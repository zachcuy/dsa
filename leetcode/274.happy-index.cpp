#include "includes.h"

/*

Problem:
Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia:
The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

*/

/* Counting Sort

One option is to use counting sort. Counting sort works by using a separate vector to store the frequencies that each element occurs.
The frequency vector should have a size up to the maximum integer in the original vector + 1 (so indices match).

The

Given a vector (size = 11):
0 1 2 3 4 5 6 7 8 9 10

9 6 8 3 2 2 6 3 1 0 8

frequency vector (max = 9):
0 1 2 3 4 5 6 7 8 9
1 1 2 2 0 0 2 0 2 1

convert frequency vector to cumulative sum:
0 1 2 3 4 5 6 7 8 9
1 2 4 6 6 6 8 8 10 11

Then the input vector is traversed starting from the end, and the value in each cell corresponds to the cell we check in the cumsum freq vector

The value in the cumsum freq vector has 1 subtracted from it and that is the cell of the output vector that we put the value we used from the original vector
the vlaue in the cumsum freq vector is also updated


*/

void countingSort(std::vector<int> &vec)
{
    std::vector<int> freq(*std::max_element(vec.begin(), vec.end()) + 1, 0); // max value in vector + 1
    std::vector<int> out(vec.size(), 0);

    // frequencies
    for (auto &i : vec)
    {
        freq[i]++;
    }

    // cum sum
    for (int i = 1; i < freq.size(); ++i)
    {
        freq[i] += freq[i - 1];
    }

    // traverse original vector from end to beginning
    for (auto i = vec.rbegin(); i != vec.rend(); ++i)
    {
        // using the value in the original vector as the index of the frequency vector
        int freq_idx = *i;

        // the cell value corresponding to the freq_idx has 1 subtracted from it and that's the index we place the value from the original vector
        freq[freq_idx] -= 1;
        int output_idx = freq[freq_idx];

        // assign the value of the output vector with index from freq vector as the value from the original vector
        out[output_idx] = freq_idx;
    }

    // assign to vec
    std::reverse(out.begin(), out.end());
    vec = out;
}

int hIndex(std::vector<int> &vec)
{
    size_t len = vec.size();

    int H = 0;
    for (int i = 1; i < len; ++i)
    {
        if (vec[i - 1] >= i)
        {
            H = i;
        }
        else
        {
            break;
        }
    }

    return H;
}

int main()
{
    // std::vector<int> vec{9, 6, 8, 3, 2, 2, 6, 3, 1, 0, 8};
    std::vector<int> vec{3, 0, 6, 1, 5};

    countingSort(vec);
    std::cout << hIndex(vec) << "\n";

    return 0;
}