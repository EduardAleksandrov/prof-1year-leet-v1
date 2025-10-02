/*
    1523. Count Odd Numbers in an Interval Range

    Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        int count{0};
        for(int i = low; i <= high; i++)
        {
            if(i % 2 == 1) count++;
        }
        return count;
    }
    int countOdds2(int low, int high) {
        if(high % 2 != 0 || low % 2 != 0) return (high - low) / 2 + 1;
        else return (high - low) / 2;
    }
};

int main()
{
    Solution Sol;
    int low {3}, hight {7};
    int result = Sol.countOdds(low, hight);

    cout << result << endl;

    return 0;
}