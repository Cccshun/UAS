#include "ma.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

void MA::Init()
{
    pop_.resize(kPOP_SIZE);
    for (int i = 0; i < kPOP_SIZE; i++)
    {
        for (int j = 0; j < kSEED_SIZE; j++)
        {
            pop_[i].coords.push_back(ProduceRandom());
        }
    }
}

void MA::Crossover()
{
    pop_offspring_.insert(pop_offspring_.end(), pop_.begin(), pop_.end());
    random_device rd;
    shuffle(pop_offspring_.begin(), pop_offspring_.end(), mt19937(rd()));

    for (int i = 0; i < kPOP_SIZE; i += 2)
    {
        for (int j = 0; j < kSEED_SIZE; j++)
        {
            if ((double)rand() / RAND_MAX < kCROSSOVER)
            {
                auto tmp = pop_offspring_[i].coords[j];
                pop_offspring_[i].coords[j] = pop_offspring_[i + 1].coords[j];
                pop_offspring_[i + 1].coords[j] = tmp;
            }
        }
    }
}

void MA::Mutate()
{
    for (int i = 0; i < kPOP_SIZE; i++)
    {
        if ((double)rand() / RAND_MAX < kMUTATE)
        {
            int pos = rand() % kSEED_SIZE;
            pop_offspring_[i].coords[pos] = ProduceRandom();
        }
    }
}

void MA::Evaluate()
{
    for (int i = 0; i < kPOP_SIZE; i++)
    {
        for (int j = 0; j < kSEED_SIZE; j++)
        {
            pop_[i].fitness = calInflu(pop_[i].coords);
            pop_offspring_[i].fitness = calInflu(pop_offspring_[i].coords);
        }
    }
}

void MA::LocalSearch()
{
    for (int i = 0; i < kPOP_SIZE; i++)
    {
        if ((double)rand() / RAND_MAX < kLOCAL_SEARCH)
        {
            for (int j = 0; j < kSEED_SIZE; j++)
            {
                auto tmpSeed = pop_offspring_[i];
                auto maxSeed = pop_offspring_[i];
                int x = pop_offspring_[i].coords[j].first;
                int y = pop_offspring_[i].coords[j].second;
                for (int row = max(0, x - 1); row < min(kN, x + 1); row++)
                {
                    for (int col = max(0, y - 1); col < min(kM, y + 1); col++)
                    {
                        tmpSeed.coords[j].first = row;
                        tmpSeed.coords[j].second = col;
                        tmpSeed.fitness = calInflu(tmpSeed.coords);
                        if (tmpSeed.fitness > maxSeed.fitness)
                        {
                            maxSeed.coords[j].first = row;
                            maxSeed.coords[j].second = col;
                            maxSeed.fitness = tmpSeed.fitness;
                        }
                    }
                }
                pop_offspring_[i] = maxSeed;
            }
        }
    }
}

void MA::Select()
{
    pop_offspring_.insert(pop_offspring_.end(), pop_.begin(), pop_.end());
    sort(pop_offspring_.begin(), pop_offspring_.end(), [](const Seed &seed1, const Seed &seed2)
         { return seed1.fitness > seed2.fitness; });
    pop_.clear();
    pop_.insert(pop_.end(), pop_offspring_.begin(), pop_offspring_.begin() + kPOP_SIZE);
    pop_offspring_.clear();
}

void MA::FindBest() {
    Init();
    int gen = 0;
    while (gen++ < kMAX_GENS) {
        Crossover();
        Mutate();
        Evaluate();
        LocalSearch();
        Select();
        printf("%d-", gen);
        for (const auto& coord: pop_[0].coords) {
            printf("(%d,%d), ", coord.first, coord.second);
        }
        printf("%f\n", pop_[0].fitness);
    }
}

