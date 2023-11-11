/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (54.20%)
 * Likes:    27210
 * Dislikes: 1503
 * Total Accepted:    2.5M
 * Total Submissions: 4.6M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * You are given an integer array height of length n. There are n vertical
 * lines drawn such that the two endpoints of the i^th line are (i, 0) and (i,
 * height[i]).
 *
 * Find two lines that together with the x-axis form a container, such that the
 * container contains the most water.
 *
 * Return the maximum amount of water a container can store.
 *
 * Notice that you may not slant the container.
 *
 *
 * Example 1:
 *
 *
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array
 * [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
 * container can contain is 49.
 *
 *
 * Example 2:
 *
 *
 * Input: height = [1,1]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
 *
 *
 */

/*
use two pointers

a = 0
b = len - 1

move pointers based on which one is bigger
the bigger one stays and the smaller one moves

use a while loop to keep looping, the condition is that we haven't crossed each
other

0 1 2 3 4 5 6 7 8
1 8 6 2 5 4 8 3 7

0 1 2 3  4  5 6
1 3 2 5 25 24 5

*/
#include "includes.h"
// @lc code=start
class Solution {
 public:
  int maxArea(vector<int>& h) {
    int a = 0;
    int b = h.size() - 1;
    int max = 0;
    int tmp = 0;

    while (a <= b) {
      // calc tmp -> current area
      tmp = (b - a) * std::min(h[b], h[a]);

      // update max
      max = std::max(max, tmp);

      // check which one will improve our area more
      if (h[a] <= h[b]) {
        a++;
      } else {
        b--;
      }
    }

    return max;
  }
};
// @lc code=end

int main() {
  Solution o;

  std::vector<int> v1{1, 8, 6, 2, 5, 4, 8, 3, 7};  // 49
  std::vector<int> v2{1, 1};                       // 1
  std::vector<int> v3{1, 3, 2, 5, 25, 24, 5};      // 24

  std::cout << o.maxArea(v1) << "\n";
  std::cout << o.maxArea(v2) << "\n";
  std::cout << o.maxArea(v3) << "\n\n\n";
}