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
    bool isPalindrome(ListNode* head) { 
        ListNode* a1 = head;
        ListNode* a2 = head;
        while(a1->next&&a1->next->next){
            a2=a2->next;
            a1=a1->next->next;
        }       
        ListNode* prev=NULL;
        ListNode* curr= a2->next;
        while(curr){
            ListNode* temp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        while(prev!=NULL){
            if(head->val != prev->val) {
                return false;
            }
            head = head->next;
            prev=prev->next ;
        }
        return true ;
        
    }
};