/*
    682. Baseball Game

    You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

    You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

    An integer x.
    Record a new score of x.
    '+'.
    Record a new score that is the sum of the previous two scores.
    'D'.
    Record a new score that is the double of the previous score.
    'C'.
    Invalidate the previous score, removing it from the record.
    Return the sum of all the scores on the record after applying all the operations.

    The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.
    
    Input: ops = ["5","2","C","D","+"]
    Output: 30
    Explanation:
    "5" - Add 5 to the record, record is now [5].
    "2" - Add 2 to the record, record is now [5, 2].
    "C" - Invalidate and remove the previous score, record is now [5].
    "D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
    "+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
    The total sum is 5 + 10 + 15 = 30.

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stack;
        int result {0};
        for(long unsigned int i = 0; i < operations.size(); i++)
        {
            try
            {
                if(std::stoi(operations[i])) stack.push(std::stoi(operations[i]));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid number: " << operations[i] << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Number out of range: " << operations[i] << std::endl;
            }
            
            if(operations[i] == "+" && stack.size() >= 2)
            {
                int one = stack.top();
                stack.pop();
                int two = stack.top();
                stack.push(one);
                stack.push(one+two);
            } else if(operations[i] == "+" && stack.size() < 2)
            {
                throw;
            }
            if(operations[i] == "D" && stack.size() >= 1)
            {
                int one = stack.top();
                stack.push(one*2);
            } else if(operations[i] == "D" && stack.size() < 1)
            {
                throw;
            }
            if(operations[i] == "C" && stack.size() >= 1)
            {
                stack.pop();
            } else if(operations[i] == "C" && stack.size() < 1)
            {
                throw;
            }
        }
        while (!stack.empty()) 
        {
            int topElement = stack.top();
            result += topElement;
            stack.pop();
        }
        return result;
    }
};

int main()
{
    Solution Sol;
    vector<string> data = {"5","2","C","D","+"};
    int result = Sol.calPoints(data);
    cout << result << endl;
    return 0;
}