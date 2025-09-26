/*
    54. Spiral Matrix

    Given an m x n matrix, return all elements of the matrix in spiral order.

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res {};
        int left = 0, right = matrix.back().size() - 1, top = 0, bottom = matrix.size() - 1;
        int num = 1;

        while (left <= right && top <= bottom) 
        {
            // Fill the top row
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }
            top++;

            // Fill the right column
            for (int i = top; i <= bottom; ++i) {
                res.push_back(matrix[i][right]);
            }
            right--;

            // Fill the bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Fill the left column
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};

int main()
{
    Solution Sol;
    vector<vector<int>> data = {{1,5,3},{7,3,4},{3,5,2}};
    vector<int> result = Sol.spiralOrder(data);

    for(auto& x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}