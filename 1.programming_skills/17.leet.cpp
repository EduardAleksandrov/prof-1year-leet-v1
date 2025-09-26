/*
    1572. Matrix Diagonal Sum

    Given a square matrix mat, return the sum of the matrix diagonals.

    Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum{0};
        for(int n = 0; n < mat.size(); n++)
        {
            sum += mat[n][n];
            sum += mat[n][mat.size()-1-n];
        }

        if(mat.size() % 2 != 0) sum-= mat[mat.size()/2][mat.size()/2];

        return sum;
    }
};

int main()
{
    Solution Sol;
    vector<vector<int>> data = {{1,5,3},{7,3,4},{3,5,2}};
    int result = Sol.diagonalSum(data);
    cout << result << endl;
    return 0;
}