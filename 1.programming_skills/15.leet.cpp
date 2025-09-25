/*
    1041. Robot Bounded In Circle

    On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:

    The north direction is the positive direction of the y-axis.
    The south direction is the negative direction of the y-axis.
    The east direction is the positive direction of the x-axis.
    The west direction is the negative direction of the x-axis.
    The robot can receive one of three instructions:

    "G": go straight 1 unit.
    "L": turn 90 degrees to the left (i.e., anti-clockwise direction).
    "R": turn 90 degrees to the right (i.e., clockwise direction).
    The robot performs the instructions given in order, and repeats them forever.

    Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int d{1};
        std::pair<int, int> myPair(0, 0);
        for(auto& s: instructions)
        {
            if(s == 'L' && d == 1) 
            {
                d = -1;
                continue;
            }
            if(s == 'L' && d == -1) 
            {
                d = -2;
                continue;
            }
            if(s == 'L' && d == -2) 
            {
                d = -3;
                continue;
            }
            if(s == 'L' && d == -3) 
            {
                d = 1;
                continue;
            }

            if(s == 'R' && d == 1) 
            {
                d = -3;
                continue;
            }
            if(s == 'R' && d == -3) 
            {
                d = -2;
                continue;
            }
            if(s == 'R' && d == -2) 
            {
                d = -1;
                continue;
            }
            if(s == 'R' && d == -1) 
            {
                d = 1;
                continue;
            }

            if(s == 'G' && d == 1)
            {
                myPair.first += 0;
                myPair.second += 1;
                continue;
            }
            if(s == 'G' && d == -1)
            {
                myPair.first += -1;
                myPair.second += 0;
                continue;
            }
            if(s == 'G' && d == -2)
            {
                myPair.first += 0;
                myPair.second += -1;
                continue;
            }
            if(s == 'G' && d == -3)
            {
                myPair.first += 1;
                myPair.second += 0;
                continue;
            }
        }
        return (myPair.first == 0 && myPair.second == 0) || d != 1;
    }
};

int main()
{
    Solution Sol;
    string data = "GGLLGG";
    bool result = Sol.isRobotBounded(data);
    cout << result << endl;
    return 0;
}