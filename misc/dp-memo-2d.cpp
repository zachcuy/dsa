#include "includes.h"

int memo(int r, int c, int ROWS, int COLS, std::vector<std::vector<int>> &vec)
{
    if (r == ROWS or c == COLS)
    {
        return 0;
    }
    if (vec[r][c] > 0)
    {
        return vec[r][c];
    }
    if (r == ROWS - 1 and c == COLS - 1)
    {
        return 1;
    }

    // remember the value
    vec[r][c] = (memo(r + 1, c, ROWS, COLS, vec)) + (memo(r, c + 1, ROWS, COLS, vec));

    return vec[r][c];
}

int main()
{
    std::vector<std::vector<int>> v(4, std::vector<int>(4, 0));

    for (auto &i : v)
    {
        for (auto &e : i)
        {
            std::cout << e << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n\n";

    std::cout << memo(0, 0, 4, 4, v) << "\n\n";

    return 0;
}