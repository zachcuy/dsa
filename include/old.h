#include <limits>
#include <vector>

#include "includes.h"

inline std::vector<int> nodesBetweenCriticalPoints(ListNode* head)
{
    // tracking our result
    int minDistance = std::numeric_limits<int>::max();
    int maxDistance = 0;

    // tracking our positions
    int prev     = 0;
    int lastCrit = 0;
    int count    = 0;

    while (head->next)
    {
        // get current val
        int cur = head->val;

        // check if we are at a critical point
        if (prev != 0
            and ((prev < cur and head->next->val < cur)
                 or (prev > cur and head->next->val > cur)))
        {
            dump("crit point", count, cur);
            if (lastCrit != 0)
            {
                // update min distance -> check if distance between count and last crit is smaller than minDistance
                minDistance = std::min(minDistance, count - lastCrit);

                // update max distance -> add distance between count and last crit
                maxDistance += count - lastCrit;
            }

            // save current crit point as last crit point encountered
            lastCrit = count;
        }

        // add to node count
        count++;

        // save current val and move to next node
        prev = head->val;
        head = head->next;
    }

    // check if we ever find a minimum distance
    if (!maxDistance)
    {
        return {-1, -1};
    }
    return {minDistance, maxDistance};
}

inline int minimumEffort(vector<vector<int>>& tasks)
{
    int ans         = 0;
    int energy_left = 0;

    // sort in descending order for the differences
    sort(tasks.begin(),
         tasks.end(),
         [&](const vector<int>& a, const vector<int>& b)
         { return (a[1] - a[0]) > (b[1] - b[0]); });

    for (vector<int> i : tasks)
    {
        const int actual  = i[0];
        const int minimum = i[1];

        if (energy_left < minimum)
        {
            // energy we have is smaller than our needed energy to start task (in other words, we don't have enough energy to actually start this)

            // we add the difference between the minimum and energy remaining to our ans
            ans += minimum - energy_left;

            // also we need to update our remaining energy so that it's the difference for the task
            energy_left = minimum - actual;
        }
        else
        {
            // since we have enough energy for this one, we can just do it and update our remaining energy
            energy_left -= actual;
        }
    }

    return ans;
}
