/*
    896. Monotonic Array
    An array is monotonic if it is either monotone increasing or monotone decreasing.

    An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

    Given an integer array nums, return true if the given array is monotonic, or false otherwise.

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        std::pair<int, int> myPair(0, 0);
        int calc {0};
        for(int i = 0; i < nums.size()-1; i++)
        {
            calc = nums[i + 1] - nums[i];
            if(calc > 0)
            {
                myPair.first = 1;
            } else if(calc < 0)
            {
                myPair.first = -1;
            } else {
                continue;
            }

            if (myPair.first == myPair.second || myPair.second == 0)
            {
                myPair.second = myPair.first;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution Sol;
    vector<int> data {1, 3, 2};
    bool result = Sol.isMonotonic(data);

    cout << result << endl;
    return 0;
}