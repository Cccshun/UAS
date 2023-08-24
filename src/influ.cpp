#include "influ.h"
#include <cmath>
#include <unordered_set>

using namespace std;

double calInflu(vector<pair<int, int>> coords)
{

    unordered_set<pair<int, int>, PairHash, PairEqual> s;
    for (auto coord : coords)
    {
        int x = coord.first;
        int y = coord.second;
        for (int row = max(0, x - kACTIVEDRANGE); row < min(kN, x + kACTIVEDRANGE); row++)
        {
            for (int col = max(0, y - kACTIVEDRANGE); col < min(kM, y + kACTIVEDRANGE); col++)
            {
                if ((pow((row - x), 2) + pow((col - y), 2)) <= pow(kACTIVEDRANGE, 2))
                {
                    s.insert(make_pair(row, col));
                }
            }
        }
    }
    return s.size();
}
