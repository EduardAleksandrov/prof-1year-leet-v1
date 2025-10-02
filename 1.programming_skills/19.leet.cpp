/*
    73. Set Matrix Zeroes

    Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

    You must do it in place.

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeros_coord{};
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0) zeros_coord.push_back(pair<int, int>(i,j));
            }
        }
        for(auto n: zeros_coord)
        {
            int one = n.first;
            int two = n.second;
            for(int i = 0; i < matrix[0].size(); i++)
            {
                matrix[one][i] = 0;
            }
            for(int i = 0; i < matrix.size(); i++)
            {
                matrix[i][two] = 0;
            }
        }
    }
};

int main()
{
    Solution Sol;
    vector<vector<int>> data = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Sol.setZeroes(data);

    for(auto& x : data)
    {
        for(auto& y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}