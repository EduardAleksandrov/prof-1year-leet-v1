/*  
    20. Valid Parentheses

    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;



class Solution {
public:
    bool isValid(string s) {
        stack<int> stack;
        int key {0};

        for(char n: s)
        {
            if(n != '(' && n != '{' && n != '[' && n != ')' && n != '}' && n != ']') continue;

            if(n == '(') {
                stack.push(1);
                continue;
            }
            
            if(n == '{') {
                stack.push(2);
                continue;
            } 
            if(n == '[') {
                stack.push(3);
                continue;
            }
            if(!stack.empty())
            {
                if((n == ')' && stack.top() == 1) || (n == '}' && stack.top() == 2) || (n == ']' && stack.top() == 3)) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                key = 1;
            }
        }
        if(stack.empty() && key != 1) return true;
        return false;
    }
};

int main()
{
    Solution Sol;
    string s {"]"};

    bool result = Sol.isValid(s);

    cout << result << endl;

    return 0;
}