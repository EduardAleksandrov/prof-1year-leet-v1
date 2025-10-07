/*
    206. Reverse Linked List

    Given the head of a singly linked list, reverse the list, and return the reversed list.

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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr; 
        vector<int> vec{};
        while(head != nullptr)
        {
            vec.push_back(head->val);
            head = head->next;
        }

        ListNode* l = new ListNode(vec.back());
        ListNode* first = l;
        for(int i = vec.size()-2; i >= 0; i--)
        {
            l->next = new ListNode(vec[i]);
            l = l->next;
        }
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
    vector<int> v1 {9,8,7,6,5,4,3};

    ListNode* list1 = Sol.Create(v1);

    ListNode* res =  Sol.reverseList(list1);

    do
    {
        cout << res->val << " ";
        
    } while (res = res->next);
    
    cout << endl;

    return 0;
}