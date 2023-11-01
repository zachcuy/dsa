#include "includes.h"

/*
DP PROBLEM

count the number of paths from 0 to n (1 <= n <= 10^6)

constraint: can only jump 1 or 2 units to the right

example: n = 4

0 ----- 1 ------ 2 ----- 3 ----- 4

res: 5

at each point, we can move +1 or +2 spots
then we can save the amount

for 1, we can only get there in one way
for 2, we can get there in two ways

recursively, we need to know how the previous value did...

so if we are given n = 4,
we need to know how many ways to get to 3, and we need to know how many ways to get to 2, and we need to know how many ways to get to 1
*/

int countPaths(int val)
{
    int count = 0;

    // base case
    if (val <= 2)
    {
        return val;
    }

    // add to count with one step and two steps
    count += countPaths(val - 1);
    count += countPaths(val - 2);

    return count;
}

int main()
{
    std::cout << countPaths(5) << "\n\n";

    return 0;
}