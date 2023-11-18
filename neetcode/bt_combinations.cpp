#include "includes.h"

void generate(int index, vector<vector<int>>& res, vector<int>& tmp, int n, int k)
{
    if (tmp.size() == k)
    {
        res.push_back(tmp);
        return;
    }
    if (index > n)
    {
        return;
    }

    for (size_t i = index; i < n + 1; i++)
    {
        // include
        tmp.push_back(i);
        generate(i + 1, res, tmp, n, k);

        tmp.pop_back();
    }
}

vector<vector<int>> combinations(int n, int k)
{
    // data vars
    vector<vector<int>> res;
    vector<int> tmp;

    // create the subsets
    generate(1, res, tmp, n, k);

    vecPrint2D(res);
    return res;
}

int main(int argc, char const* argv[])
{
    combinations(5, 2);
    return 0;
}
