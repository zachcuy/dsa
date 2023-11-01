#include "includes.h"

int memo(uint8_t n, std::vector<int> &v)
{
    if (n <= 2)
    {
        return n;
    }

    if (v[n] > 0)
    {
        return v[n];
    }

    v[n] = memo(n - 1, v) + memo(n - 2, v);

    return v[n];
}

int countPaths(uint8_t n)
{
    std::vector<int> v(n + 1, 0);

    return memo(n, v);
}

int main()
{
    std::cout << countPaths(5) << "\n\n";

    return 0;
}