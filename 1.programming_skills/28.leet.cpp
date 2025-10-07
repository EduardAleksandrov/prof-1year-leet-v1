/*
    21. Merge Two Sorted Lists

    You are given the heads of two sorted linked lists list1 and list2.

    Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

    Return the head of the merged linked list.
    
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to help simplify the merging process
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1; 
                list1 = list1->next; 
            } else {
                current->next = list2; 
                list2 = list2->next; 
            }
            current = current->next; // Move the current pointer forward
        }
        
        // At least one of l1 or l2 can still have nodes
        if (list1 != nullptr) {
            current->next = list1; 
        } else {
            current->next = list2; 
        }
        
        return dummy.next;
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

    ListNode* res =  Sol.mergeTwoLists(list1, list2);

    do
    {
        cout << res->val << " ";
        
    } while (res = res->next);
    
    cout << endl;

    return 0;
}