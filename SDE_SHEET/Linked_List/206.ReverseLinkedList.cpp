Recursive

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode *newHead= reverseList(head->next);

        ListNode *front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;

    }
};


Iterative...


ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;

        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }