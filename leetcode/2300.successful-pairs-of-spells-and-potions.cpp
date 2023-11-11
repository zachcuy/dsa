/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 *
 * https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/
 *
 * algorithms
 * Medium (41.78%)
 * Likes:    2376
 * Dislikes: 58
 * Total Accepted:    114.5K
 * Total Submissions: 273.2K
 * Testcase Example:  '[5,1,3]\n[1,2,3,4,5]\n7'
 *
 * You are given two positive integer arrays spells and potions, of length n
 * and m respectively, where spells[i] represents the strength of the i^th
 * spell and potions[j] represents the strength of the j^th potion.
 *
 * You are also given an integer success. A spell and potion pair is considered
 * successful if the product of their strengths is at least success.
 *
 * Return an integer array pairs of length n where pairs[i] is the number of
 * potions that will form a successful pair with the i^th spell.
 *
 *
 * Example 1:
 *
 *
 * Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
 * Output: [4,0,3]
 * Explanation:
 * - 0^th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
 * - 1^st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
 * - 2^nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
 * Thus, [4,0,3] is returned.
 *
 *
 * Example 2:
 *
 *
 * Input: spells = [3,1,2], potions = [8,5,8], success = 16
 * Output: [2,0,2]
 * Explanation:
 * - 0^th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
 * - 1^st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful.
 * - 2^nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful.
 * Thus, [2,0,2] is returned.
 *
 *
 *
 * Constraints:
 *
 *
 * n == spells.length
 * m == potions.length
 * 1 <= n, m <= 10^5
 * 1 <= spells[i], potions[i] <= 10^5
 * 1 <= success <= 10^10
 *
 *
 */
/*

use binary search on the potions vec to find the lowest index that works
then we can do length - (index)

potions vector needs to be sorted: o(nlogn)

*/

#include "includes.h"
// @lc code=start
class Solution {
 public:
  long long binSearch(long long spell, std::vector<int>& potions,
                      long long success) {
    int L = 0;
    int R = potions.size() - 1;
    int mid = (R + L) / 2;

    while (L < R) {
      long long tmp = potions[mid] * spell;
      if (tmp >= success) {
        R = mid - 1;
      } else {
        L = mid + 1;
      }
      mid = (R + L) / 2;
    }

    if (potions[mid] * spell >= success) {
      return potions.size() - (mid);
    }
    return potions.size() - (mid + 1);
  }
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                              long long success) {
    // sort potions
    std::sort(potions.begin(), potions.end());

    std::vector<int> out;
    for (int i = 0; i < spells.size(); ++i) {
      // binary search of potions
      out.push_back(binSearch(spells[i], potions, success));
    }

    return out;
  }
};
// @lc code=end

int main() {
  Solution o;

  std::vector<int> spells{5, 1, 3};
  std::vector<int> potions{1, 2, 3, 4, 5};
  //   std::vector<int> spells{3, 1, 2};
  //   std::vector<int> potions{8, 5, 8};

  o.successfulPairs(spells, potions, 7);
}