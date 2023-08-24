#ifndef _MA_H_
#define _MA_H_
#include "influ.h"
#include <utility>
#include <vector>
#include <random>

struct Seed
{
    std::vector<std::pair<int, int>> coords;
    double fitness;
};

class MA
{
public:
    void FindBest();

protected:
    void Init();
    void Crossover();
    void Mutate();
    void Evaluate();
    void LocalSearch();
    void Select();

private:
    std::vector<Seed> pop_;
    std::vector<Seed> pop_offspring_;
};

inline std::pair<int, int> ProduceRandom() { return std::make_pair(rand() % kN, rand() % kM); }

#endif