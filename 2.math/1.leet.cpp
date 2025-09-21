/*  
    2. Add Two Numbers
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


//Definition for singly-linked list.
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
        ListNode* l = new ListNode(0);
        ListNode* first = l;
        int add{0};
        int count{0};
        do
        {
            int l11{0};
            if(l1) l11 = l1->val;
            int l12{0};
            if(l2) l12 = l2->val;

            l->val = (l11 + l12 + add) % 10;
            if((l11 + l12 + add) >= 10) add = 1;
            else add = 0;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            if(l1 || l2 || add == 1) 
            {
                l->next = new ListNode();
                l = l->next;
                continue;
            }
            break;
        } while (true);

        return first;
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