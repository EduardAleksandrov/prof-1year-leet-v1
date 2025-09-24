/*
    740. Delete and Earn
    You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

    Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
    Return the maximum number of points you can earn by applying the above operation some number of times.

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        std::map<int, int> s;
        int x{0}, count{0};
        int result {0};
        while(!nums.empty())
        {
            count = 0;
            x = 0;
            s.clear();
            for(auto& n: nums)
            {
                s[n]++;
                if(s[n]*n > x){
                    x = s[n]*n;
                    count = n;
                } 
            }
            result += count;
            
            // Find the first occurrence of 'value_to_delete'
            auto it = std::find(nums.begin(), nums.end(), count);
            // If the element is found (iterator is not nums.end())
            if (it != nums.end()) {
                nums.erase(it); // Erase the element at the found position
            }
            // nums.erase(std::remove(nums.begin(), nums.end(), count+1), nums.end());
            nums.erase(std::remove(nums.begin(), nums.end(), count-1), nums.end());

            for(int n: nums)
            {
                cout << n << " ";
            }
            cout << endl;
            
        }
        return result;
    }

    int deleteAndEarn2(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Step 1: Count frequencies of each number
        unordered_map<int, int> frequency;
        int max_num = 0;
        for (int num : nums) {
            frequency[num]++;
            max_num = max(max_num, num);
        }

        // Step 2: Create a dp array
        vector<int> dp(max_num + 1, 0);

        // Step 3: Base cases
        dp[0] = 0; // No points for 0
        dp[1] = frequency[1] * 1; // Points for 1

        // Step 4: Fill the dp array
        for (int i = 2; i <= max_num; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + i * frequency[i]);
        }

        // Step 5: Return the maximum points
        return dp[max_num];
    }
    int deleteAndEarnRecurs(unordered_map<int, int>& frequency, int max_num, vector<int>& dp) {

        if(dp[max_num != 0]) return dp[max_num]; // Мемоизация
        if(max_num == 0) return 0; // No points for 0
        if(max_num == 1) return frequency[1] * 1; // Points for 1

        return dp[max_num] = max(deleteAndEarnRecurs(frequency,max_num - 1, dp), deleteAndEarnRecurs(frequency,max_num - 2, dp) + max_num * frequency[max_num]);
    }
};

int main()
{
    Solution Sol;
    vector<int> data = {8,3,4,7,6,6,9,2,5,8,2,4,9,5,9,1,5,7,1,4};
    vector<int> data1 = {1,2,5,9};

    int result = Sol.deleteAndEarn2(data);
    cout << result << endl;


    // Recursion
    unordered_map<int, int> frequency;
    int max_num = 0;
    for (int num : data) {
        frequency[num]++;
        max_num = max(max_num, num);
    }
        // Create a dp array
    vector<int> dp(max_num + 1, 0);

    int result_rec = Sol.deleteAndEarnRecurs(frequency, max_num, dp);
    cout << result_rec << endl;


    return 0;
}