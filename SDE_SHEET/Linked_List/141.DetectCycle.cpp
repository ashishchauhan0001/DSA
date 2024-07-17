class Solution {
public:
// Brute force-> Using Map put the nodes into the map if u found any node which is already present in the map then bingo you got ur answer...
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL&&fast->next!=NULL){
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast) return true;
        }
        return false;
    }
};