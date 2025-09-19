/**
    459. Repeated Substring Pattern
    Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
    Done.
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.length() == 1) return false;

        int n = s.length();
        int len1 = n/2;
        for(long int i = 1; i<=len1; i++)
        {
            string res_sub;
            if(n % i == 0)
            {
                string sub = s.substr(0, i);
                

                int len = s.length()/sub.length();
                for(long int i = 0; i < len; i++)
                {
                    res_sub += sub;
                }
            }
            
            if (res_sub == s) return true;
        }
        
        return false;
    }
};

int main()
{
    Solution Sol;
    bool result = Sol.repeatedSubstringPattern("bb");
    cout << result << endl;
    return 0;
}