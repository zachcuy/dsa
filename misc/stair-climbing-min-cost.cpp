/*

Similar to the easy climbing-stairs problem but this time, there is a vector that corresponds to each step that denotes the cost visiting a given step will cost

*/
#include "includes.h"

int calcCost(int n, std::vector<int> &v, std::vector<int> costs)
{
    if (n <= 0)
    {
        return 0;
    }
    if (v[n] > 0)
    {
        return v[n];
    }

    v[n] = costs[n] + std::min(calcCost(n - 1, v, costs), calcCost(n - 2, v, costs));

    return v[n];
}

int minPath(std::vector<int> v, std::vector<int> costs)
{
    return calcCost(v.size() - 1, v, costs);
}

int main()
{
    int n = 3; // number of stairs excluding floor
    std::vector<int> v(n + 1, 0);
    std::vector<int> costs{0, 3, 2, 4};

    std::cout << minPath(v, costs) << "\n\n";

    return 0;
}