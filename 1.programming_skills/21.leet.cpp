/*
    1491. Average Salary Excluding the Minimum and Maximum Salary

    You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

    Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.
    
    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int min {salary[0]};
        int max {salary[0]};
        for(auto& x: salary)
        {
            if(x < min) min = x;
            if(x > max) max = x;
        }
        double sum{0};
        for(auto& x: salary)
        {
            if(x != min && x != max) sum += x;
        }
        return sum/(salary.size() - 2);
    }
};

int main()
{
    Solution Sol;
    vector<int> salary {4000,3000,1000,2000};
    double result = Sol.average(salary);

    cout << result << endl;

    return 0;
}