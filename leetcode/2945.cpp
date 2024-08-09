#include <includes.h>

/* IN/OUT
*
* input: array of integers
* output: integer representing the longest non-decreasing array after applying ops
*
*/

/* Problem Breakdown
*
* we can use a mono stack for this problem since we want to ensure that we have an increasing array
* and a mono stack lets us know when we have the next greater element
*
* 4, 3, 2, 6
* 4 < 5 < 6
*
*/

/* Steps
*
* 1. initialize our variables:
*		a) size of our input array
*		b) vector (long long) that represents our prefix sums with a size of n+1
* 2. go through our nums array and calculate the prefix sums := sum
* 3. create our other variables
*		a) vector to keep track of our current "mono stack's value" := A (size = n+1)
*		b) vector to keep track of our difference between our prefix sum value and the sum at our "mono stack's value" := B (size = n+1)
*		c) we need a deque or queue (initialize with the first element, 0)
* 4. loop through the length of our input array
*		a) go through our queue while the queue size > 1 AND B[i] is ( greater than or equal to ) our value of B[q[1]]
*		b) assign values to our A and B vectors
*				- A[i] = A[queue.front()] + 1
*				- B[i] = sum[i] - sum[queue.front()]
*		c) loop until we get rid of all the element in our queue OR have a value for B that ( less than or equal ) to the queue's tail (queue.back()
*		d) pushing our current index to the q
* 5. return the last value in our A which is the current mono stack's value which is the index and that means that is our length (at index n)
*
*/

/* Complexities
*
* Time: O(n)
* Space: O(n)
*
*/

int findMaximumLength(std::vector<int>& nums)
{
    // 1. initialize our variables:
    // a) size of our input array
    const int n = nums.size();

    // 	b) vector (long long) that represents our prefix sums with a size of n+1 := sum
    std::vector<long long> sum(n + 1, 0);

    // 2. go through our nums array and calculate the prefix sums
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + nums[i - 1];
    }

    // 3. create our other variables
    // 	a) vector to keep track of our current "mono stack's value" := A (size = n+1)
    std::vector<long long> A(n + 1, 0);

    // 	b) vector to keep track of our difference between our prefix sum value and the sum at our "mono stack's value" := B (size = n+1)
    std::vector<long long> B(n + 1, 0);

    // 	c) we need a deque or queue (initialize with the first element, 0)
    std::deque<int> dq;
    dq.push_back(0);

    // 4. loop through the length of our input array
    for (int i = 1; i <= n; ++i)
    {
        // 	a) go through our queue while the queue size > 1 AND sum[i] is ( greater than or equal to ) our value of B[q[1]]
        while (dq.size() > 1 and sum[i] >= B[dq[1]])
        {
            dq.pop_front();
        }

        // 	b) assign values to our A and B vectors
        // 			- A[i] = A[queue.front()] + 1
        // 			- B[i] = sum[i] - sum[queue.front()]
        A[i] = A[dq.front()] + 1;
        B[i] = (sum[i] * 2) - sum[dq.front()];

        // 	c) loop until we get rid of all the element in our queue OR have a value for B that ( less than or equal ) to the queue's tail (queue.back()
        while (!dq.empty() and B[i] <= B[dq.back()])
        {
            dq.pop_back();
        }

        // 	d) pushing our current index to the q
        dq.push_back(i);
    }

    // 5. return the last value in our A which is the current mono stack's value which is the index and that means that is our length (at index n)
    return A[n];
}

int main()
{
    std::vector<int> v1 {5, 2, 2};  // 1
    std::vector<int> v2 {1, 2, 3, 4};  // 4
    std::vector<int> v3 {4, 3, 2, 6};  // 3

    dump(findMaximumLength(v1), 1);
    dump(findMaximumLength(v2), 4);
    dump(findMaximumLength(v3), 3);
}
