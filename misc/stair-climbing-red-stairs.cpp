/*

Similar to the easy climbing-stairs problem but this time, there is a vector of stairs that denote the values that we cannot go to

*/
#include "includes.h"

int memo(uint8_t n, std::vector<int> &v)
{
    if (n <= 1)
    {
        return n;
    }

    if (v[n] > -1)
    {
        return v[n];
    }

    v[n] = memo(n - 1, v) + memo(n - 2, v) + memo(n - 3, v);

    return v[n];
}

int countPaths(uint8_t n, std::vector<int> k)
{
    std::vector<int> v(n + 1, -1);

    for (auto &i : k)
    {
        v[i] = 0;
    }

    return memo(n, v);
}

int main()
{
    std::cout << countPaths(7, {1, 3, 4}) << "\n\n";

    return 0;
}