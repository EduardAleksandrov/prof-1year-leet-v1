/*
    1232. Check If It Is a Straight Line

    You are given an array coordinates, coordinates[i] = [x, y], where [x, y]
    represents the coordinate of a point. Check if these points make a straight line in the XY plane.

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        for(int i = 2; i < coordinates.size(); i++)
        {
            double x = coordinates[i][0];
            double y = coordinates[i][1];
            if((coordinates[1][0] - coordinates[0][0]) == 0 && (x - coordinates[0][0]) != 0) return false;
            else if ((coordinates[1][0] - coordinates[0][0]) == 0 && (x - coordinates[0][0]) == 0) continue;

            if((coordinates[1][1] - coordinates[0][1]) == 0 && (y -coordinates[0][1]) != 0) return false;
            else if((coordinates[1][1] - coordinates[0][1]) == 0 && (y -coordinates[0][1]) == 0) continue;

            if((x - coordinates[0][0])/(coordinates[1][0] - coordinates[0][0]) != (y - coordinates[0][1])/(coordinates[1][1] - coordinates[0][1])) return false;
        }
        return true;
    }
};

int main()
{
    Solution Sol;
    vector<vector<int>> line {{2,4},{2,5},{2,8}};
    bool result = Sol.checkStraightLine(line);

    cout << result << endl;

    return 0;
}