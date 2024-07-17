class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow=head;
        ListNode *fast=head;
        for(int i=0;i<n;i++) fast=fast->next;

        if(fast==NULL) return head->next;
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* delNode=slow->next;
        slow->next=slow->next->next;
        delete delNode;
        return head;
    }
};