#include <algorithm>
#include <utility>
#include <vector>

// sort with lambda
void sort_using_lambda()
{
    std::vector<std::pair<int, int>> v {{1, 2}, {1, 1}, {2, 3}, {2, 2}, {0, 8}};
    std::sort(v.begin(),
              v.end(),
              [](const std::pair<int, int>& a, const std::pair<int, int>& b)
              {
                  if (a.first != b.first)
                  {
                      return a.first < b.first;
                  }
                  return a.second < b.second;
              });
}
