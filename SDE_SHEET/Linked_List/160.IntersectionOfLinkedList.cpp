class Solution {
public:
// Brute force --> put one list's node in the map and check other list's node occurences
// Using lengh--->find the larger-smaller length and move the larger LL diff times and then iterative both the list and check

// optimal is below
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* slow=headA;
        ListNode* fast=headB;
        while(slow!=fast){
          slow=slow->next;
          fast=fast->next;
          if(slow==fast) return slow;
          if(slow==NULL) slow=headB;
          if(fast==NULL) fast=headA;
        }

        return slow;
    }
};