/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        priority_queue<int,vector<int>,greater<>> pq;
        ListNode* curr = list1;
        while(curr)
        {
            pq.push(curr->val);
            curr = curr->next;
        }
        curr = list2;
        while(curr)
        {
            pq.push(curr->val);
            curr = curr->next;
        }

        ListNode* temp = new ListNode(0);
        ListNode* res = temp;
        while(!pq.empty())
        {
            temp->next = new ListNode(pq.top());
            pq.pop();
            temp= temp->next;
        }

        return res->next;


    }
};