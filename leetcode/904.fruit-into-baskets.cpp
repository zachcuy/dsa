/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 *
 * https://leetcode.com/problems/fruit-into-baskets/description/
 *
 * algorithms
 * Medium (43.78%)
 * Likes:    4375
 * Dislikes: 307
 * Total Accepted:    369.8K
 * Total Submissions: 843.9K
 * Testcase Example:  '[1,2,1]'
 *
 * You are visiting a farm that has a single row of fruit trees arranged from
 * left to right. The trees are represented by an integer array fruits where
 * fruits[i] is the type of fruit the i^th tree produces.
 *
 * You want to collect as much fruit as possible. However, the owner has some
 * strict rules that you must follow:
 *
 *
 * You only have two baskets, and each basket can only hold a single type of
 * fruit. There is no limit on the amount of fruit each basket can hold.
 * Starting from any tree of your choice, you must pick exactly one fruit from
 * every tree (including the start tree) while moving to the right. The picked
 * fruits must fit in one of your baskets.
 * Once you reach a tree with fruit that cannot fit in your baskets, you must
 * stop.
 *
 *
 * Given the integer array fruits, return the maximum number of fruits you can
 * pick.
 *
 *
 * Example 1:
 *
 *
 * Input: fruits = [1,2,1]
 * Output: 3
 * Explanation: We can pick from all 3 trees.
 *
 *
 * Example 2:
 *
 *
 * Input: fruits = [0,1,2,2]
 * Output: 3
 * Explanation: We can pick from trees [1,2,2].
 * If we had started at the first tree, we would only pick from trees [0,1].
 *
 *
 * Example 3:
 *
 *
 * Input: fruits = [1,2,3,2,2]
 * Output: 4
 * Explanation: We can pick from trees [2,3,2,2].
 * If we had started at the first tree, we would only pick from trees
 * [1,2].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= fruits.length <= 10^5
 * 0 <= fruits[i] < fruits.length
 *
 *
 */

/*

two pointer???

*/
#include "includes.h"
// @lc code=start
class Solution
{
   public:
    // AC: sliding window approach
    int totalFruit(vector<int>& fruits)
    {
        unordered_set<int> types;

        int r = 0;
        int l = 0;
        int maxCount = 0;
        int count = 0;
        while (r < fruits.size())
        {
            if (!types.count(fruits[r]))
            {
                types.insert(fruits[r]);
            }
            if (types.size() > 2)  // reached max baskets and encountered third type of fruit
            {
                maxCount = max(maxCount, count);
                r = l;
                count = 0;
                types.clear();
            }
            else
            {
                count++;
                if (fruits[r] != fruits[l])
                {
                    l = r;
                }
                r++;
            }
        }

        return max(maxCount, count);
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution obj;

    vector<int> v1{1, 2, 1};
    vector<int> v2{0, 1, 2, 2};
    vector<int> v3{1, 2, 3, 2, 2};
    vector<int> v4{1, 0, 3, 4, 3};
    vector<int> v5{3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    vector<int> v6{0, 1, 6, 6, 4, 4, 6};

    dump(obj.totalFruit(v1));  // 3
    dump(obj.totalFruit(v2));  // 3
    dump(obj.totalFruit(v3));  // 4
    dump(obj.totalFruit(v4));  // 3
    dump(obj.totalFruit(v5));  // 5
    dump(obj.totalFruit(v6));  // 5
    return 0;
}