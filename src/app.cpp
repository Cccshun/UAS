#include <iostream>
#include <ctime>
#include <chrono>
#include "ma.h"

using namespace std;

void test();
int main()
{
    srand(time(0));
    MA ma;
    auto start_time = chrono::high_resolution_clock::now();
    ma.FindBest();
    auto end_time = chrono::high_resolution_clock::now();
    printf("exection time==>%d milliseconds\n", chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));
    test();
}

void test()
{
    double sum = 0;
    int num = 10000;
    for (int n = 0; n < num; n++)
    {
        Seed seed;
        for (int i = 0; i < kSEED_SIZE; i++)
        {
            seed.coords.push_back(ProduceRandom());
        }
        sum += calInflu(seed.coords);
    }
    printf("avg: %f", sum / num);
}