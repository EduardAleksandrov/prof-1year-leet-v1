/*
    283. Move Zeroes
    Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
    Note that you must do this in-place without making a copy of the array.
    Done.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        if(nums.size() == 1) return;
        for(int i = size-1; i >= 0 ; i--)
        {
            if(nums[i] == 0)
            {
                nums.erase(nums.begin()+i);
                nums.push_back(0);
            }
        }
    }
};

int main()
{
    std::vector<int> s {0, 1, 0, 3, 12};

    Solution Sol;
    Sol.moveZeroes(s);
    for(int i = 0; i < s.size(); i++)
        cout << s[i] << endl;

    return 0;
}