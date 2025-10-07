/*
    445. Add Two Numbers II

    You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.
    
    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <stack>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> s1, s2;

        // Push all digits of l1 onto stack s1
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        // Push all digits of l2 onto stack s2
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* result = nullptr; // To store the result linked list
        int carry = 0;

        // While there are digits in either stack or there's a carry
        while (!s1.empty() || !s2.empty() || carry > 0) {
            int sum = carry;

            // Add the top of stack s1 if available
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            // Add the top of stack s2 if available
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            // Update carry for the next iteration
            carry = sum / 10;
            // Create a new node for the current digit and attach it to the result
            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = result; 
            result = newNode; 
        }

        return result; 
    }
    ListNode* Create(vector<int>&x)
    {
        ListNode* l = new ListNode(x[0]);
        ListNode* first = l;
        for(int i = 1; i < x.size(); i++)
        {
            
            l->next = new ListNode(x[i]);
            l = l->next;
        }
        return first;
    }
    ListNode* reverselist(ListNode* head)
    {
        ListNode* nextnode = nullptr;
        ListNode* prev = nullptr;
        while(head!= nullptr)
        {
            nextnode= head->next;
            head->next = prev;
            prev = head;
            head = nextnode;
        }
        return prev;
    }
};

int main()
{
    Solution Sol;
    vector<int> v1 {9,9,9,9,9,9,9};
    vector<int> v2 {9,9,9,9};

    ListNode* list1 = Sol.Create(v1);
    ListNode* list2 = Sol.Create(v2);

    ListNode* res =  Sol.addTwoNumbers(list1, list2);

    do
    {
        cout << res->val << " ";
        
    } while (res = res->next);
    
    cout << endl;

    return 0;
}