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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry =0;
        ListNode * res =  new ListNode(0);
        ListNode* ans = res;  
        while(l1 || l2)
        {
            int d = (l1!=nullptr?l1->val:0) + (l2!=nullptr?l2->val:0) + carry;
            ListNode *temp = new ListNode(d%10);
            res->next = temp;
            res = res->next;

            carry = d/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

            if(carry!=0){
                ListNode *temp = new ListNode(carry);
                res->next = temp;
            }

            return ans->next;


        
    }
};