/*

original
[1 2 3]
[4 5 6]
[7 8 9]

output
[7 4 1]
[8 5 2]
[9 6 3]

output indices
[2, 0][1, 0][0, 0]
[2, 1][1, 1][0, 1]
[2, 2][1, 2][0, 2]

As we fill up, we want the first row to always have the same col value, with descending row val
if n is the dimensions of length and width, then the indices to use are
    [n-j-1, i]

[2, 0] => [0, 0] and [0, 0] => [0, 2] and [0, 2] => [2, 2] and [2, 2] => [2, 0]
[2, 1] => [1, 0] and [1, 0] => [0, 1] and [0, 1] => [1, 2] and [1, 2] => [2, 1]

n = 3
i = 0
total operations per block is always 4 because it's a square matrix

[0, 0] => [0, 2] => [2, 2] => [2, 0] => [0, 0]

[1 2 3 4 5]
[11 22 33 44 55]
[111 222 333 444 555]
[1111 2222 3333 4444 5555]
[11111 22222 33333 44444 55555]

ori
[0, 0][0, 1][0, 2]
[1, 0][1, 1][1, 2]
[2, 0][2, 1][2, 2]

out
[2, 0][1, 0][0, 0]
[2, 1][1, 1][0, 1]
[2, 2][1, 2][0, 2]

single-num index
[0 1 2]
[3 4 5]
[6 7 8]

[0 1 2] [3 4 5] [6 7 8]
[6 3 0] [7 4 1] [8 5 2]

indices (row, col)
[0, 0][0, 1][0, 2]
[1, 0][1, 1][1, 2]
[2, 0][2, 1][2, 2]

first row becomes last column
second row becomes middle column
third row becomes first

doing this with O(1) additional memory means we can use a separate 2d array (for the output)

*/

/*

ori
[0, 0][0, 1][0, 2][0, 3][0, 4]
[1, 0][1, 1][1, 2][1, 3][1, 4]
[2, 0][2, 1][2, 2][2, 3][2, 4]
[3, 0][3, 1][3, 2][3, 3][3, 4]
[4, 0][4, 1][4, 2][4, 3][4, 4]

out
[4, 0][3, 0][2, 0][1, 0][0, 0]
[4, 1][3, 1][2, 1][1, 1][0, 1]
[4, 2][3, 2][2, 2][1, 2][0, 2]
[4, 3][3, 3][2, 3][1, 3][0, 3]
[4, 4][3, 4][2, 4][1, 4][0, 4]


I can use a nested for loop that fills in each row by accessing the original array

time complexity = O(n^2)

*/

vector<vector<int>> solution(vector<vector<int>> a) {
    std::vector<std::vector<int>> out;
    
    // square matrix
    const int DIM = a.size();
    
    for (int i = 0; i < DIM; ++i) {
        std::vector<int> tmp;
        for (int j = DIM - 1; j >= 0; --j) {
            // get values from original array (for a 5x5, it'd be 5 values)
            tmp.push_back(a[j, i]);
        }
        // add tmp to output matrix
        out.push_back(tmp);
    }

    return out;
}
