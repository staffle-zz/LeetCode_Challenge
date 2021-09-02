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
        ListNode *cur = new ListNode(0);
        ListNode *ans = cur;
        int carry = 0;
        while(l1 || l2){
            if(l1)
                carry += l1->val , l1 = l1->next;
            if(l2)
                carry += l2->val , l2 = l2->next;
            ListNode * here = new ListNode(carry%10);
            carry /= 10;
            if(cur)
                cur->next = here;
            cur = here;
        }
        if(carry)
        {
            ListNode * here = new ListNode(carry);
            cur->next = here;
            cur = here;
        }
        ans = ans->next;
        return ans;
    }
};
