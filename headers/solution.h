#ifndef INCLUDE_HEADERS_SOLUTION_H_
#define INCLUDE_HEADERS_SOLUTION_H_

#include <vector>

class Solution
{
public:
    Solution()                           = default;
    Solution(Solution&&)                 = default;
    Solution(const Solution&)            = default;
    Solution& operator=(Solution&&)      = default;
    Solution& operator=(const Solution&) = default;
    ~Solution()                          = default;

public:
    int leastInterval(std::vector<char>& tasks, int n);

private:
};

#endif  // INCLUDE_HEADERS_SOLUTION_H_
