/*
    2. Add Two Numbers

    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

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
        // Create a dummy node to simplify the result list creation
        ListNode dummy(0);
        ListNode* current = &dummy;
        int carry = 0; 

        // Loop until both lists are exhausted
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; 

            // Add l1's value if it's not null
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next; 
            }
            
            // Add l2's value if it's not null
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next; 
            }
            
            // Update carry and the digit for the current node
            carry = sum / 10; 
            current->next = new ListNode(sum % 10); 
            current = current->next; 
        }
        
        return dummy.next; // Return the result, skipping the dummy node
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