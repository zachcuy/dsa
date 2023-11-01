#include "includes.h"

int getSum(int n)
{
    int sum = 0;

    if (n == 1)
    {
        return 1;
    }
    else
    {
        sum += getSum(n - 1) + n;
    }

    return sum;
}

int main()
{
    int n = 5;

    std::cout << getSum(n) << "\n\n";

    return 0;
}