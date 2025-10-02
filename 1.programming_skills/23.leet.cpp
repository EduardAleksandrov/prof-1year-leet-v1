/*
    
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int sum = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++)
        {
            for(int j = i+1; j < size; j++)
            {
                for(int k = j+1; k < size; k++)
                {
                    int one = nums[i];
                    int two = nums[j];
                    int three = nums[k];
                    if( (one + two > three) && (one + three > two) && (two + three > one) && (one+two+three > sum)) sum = one+two+three;
                }
            }
        }
        return sum;
    }
    int largestPerimeter2(std::vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the array
        int size = nums.size();
        
        // Check triplets from the end of the sorted array
        for (int i = size - 1; i >= 2; i--) {
            // Check if nums[i-2], nums[i-1], nums[i] can form a triangle
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
                return nums[i - 2] + nums[i - 1] + nums[i]; // Return the perimeter
            }
        }
        
        return 0; // If no valid triangle is found
    }
};

int main()
{
    Solution Sol;
    vector<int> bills {5,5,5,10,5,5,10,20,20,20};
    int result = Sol.largestPerimeter(bills);

    cout << result << endl;

    return 0;
}