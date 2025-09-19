/**
 * 28.Find the index of the first occurence in a string
 * Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * Done
 */

#include <iostream>
#include <string>

using std::string;

class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        int j {0};
        int occur {0};
        for(int i = 0; i < haystack.length(); i++)
        {
            if(haystack[i] == needle[0])
            {
                j = 0;
                occur = 0;
                for(int n = 0; n < needle.length(); n++)
                {
                    if(haystack[i+n] == needle[n]) 
                    {
                        if(j==0) occur = i;
                        j++;
                        if(j==needle.length()) return occur;
                    } else {
                        break;
                    }
                }
            }
            if(haystack.length() - i < needle.length()) return -1;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    int s = sol.strStr("mississippi", "issip");
    std::cout << s << "\n";
    return 0;
}

