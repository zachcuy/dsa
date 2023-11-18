#include "includes.h"

/*

at each value, we have the choice to include and exclude a value

*/

void generate(vector<int>& v, vector<vector<int>>& res, vector<int>& tmp, int index)
{
    // push to res
    if (index >= v.size())
    {
        res.push_back(tmp);
        return;
    }

    tmp.push_back(v[index]);
    generate(v, res, tmp, index + 1);

    tmp.pop_back();
    generate(v, res, tmp, index + 1);
}

vector<vector<int>> combinations(vector<int>& v)
{
    vector<vector<int>> res;
    vector<int> tmp;

    generate(v, res, tmp, 0);

    vecPrint2D(res);
    return res;
}

int main(int argc, char const* argv[])
{
    vector<int> v1{1, 2, 3};

    combinations(v1);

    return 0;
}
