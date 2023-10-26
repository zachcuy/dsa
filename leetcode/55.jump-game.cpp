#include "includes.h"
struct Node
{
    int loc;
    int val;
    std::vector<int> neighbors;

    friend std::ostream &operator<<(std::ostream &output, const Node &N)
    {
        output << "loc: " << N.loc << ", val: " << N.val << ", neighbors: ";

        output << "[ ";
        for (auto &i : N.neighbors)
        {
            output << i << " ";
        }
        output << "]\n";
        return output;
    }
};

class Solution
{
public:
    bool canJump(std::vector<int> &nums)
    {
        std::unordered_map<int, Node> m;

        for (int i = 0; i < nums.size(); ++i)
        {
            Node tmp;
            tmp.loc = i;
            tmp.val = nums[i];
            for (int j = 0; j < tmp.val; ++j)
            {
                if (i + j + 1 < nums.size())
                {
                    tmp.neighbors.push_back(i + j + 1);
                }
            }

            m[i] = tmp;
        }

        for (auto &i : m)
        {
            std::cout << i.first << ":: " << i.second << "\n";
        }
        return 0;
    }
};

int main()
{

    Solution obj;
    std::vector<int> in{2, 3, 1, 1, 4};
    for (auto &i : in)
    {
        std::cout << i << " ";
    }
    std::cout << "\n\n";
    obj.canJump(in);

    return 0;
}