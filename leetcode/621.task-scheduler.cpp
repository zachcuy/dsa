#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>

#include "solution.h"

/*
*
* You are given an array of CPU tasks,
* each represented by letters A to Z, and a cooling time, n.
*
* Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.
*
* Return the minimum number of intervals required
* to complete all tasks.
*
*
* 2 unique values
* A : 3 times
* B : 3 times
* spacing : 2
*
* A - B - idle - A - B - idle - A - B
* result = 8
*
*
*/

struct Comparator
{
    bool operator()(const std::pair<char, int>& a, const std::pair<char, int>& b)
    {
        return a.second < b.second;
    }
};

int Solution::leastInterval(std::vector<char>& tasks, int n)
{
    std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, Comparator> pq;
    std::unordered_map<char, int> freqMap;

    // Create frequency map for the elements
    for (int i = 0; i < tasks.size(); ++i) {
        freqMap[tasks[i]]++;
    }

    // populate max heap (sorted by frequency)
    for (auto& p : freqMap) {
        pq.push(p);
    }

    while (!pq.empty()) {
        auto p = pq.top();
        std::cout << p.first << " " << p.second << "\n";
        pq.pop();
    }

    return 0;
}
