#include "includes.h"
// @lc code=start
class Solution
{
   public:
    bool divisorGame(int n)
    {
        return n % 2 ? false : true;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution obj;

    dump(obj.divisorGame(2));
    dump(obj.divisorGame(3));
    dump(obj.divisorGame(4));
    dump(obj.divisorGame(5));
    return 0;
}