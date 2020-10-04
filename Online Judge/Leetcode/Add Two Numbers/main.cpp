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
    ListNode* addTwoNumbers(ListNode* p, ListNode* q) {
        ListNode* root = new ListNode(0);
        ListNode* curr = root;
        int carry = 0;
        while(p != nullptr or q != nullptr){
            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if(p != nullptr) p = p->next;
            if(q != nullptr) q = q->next;
        }
        if(carry > 0){
            curr->next = new ListNode(carry);
        }
        return root->next;
    }
};