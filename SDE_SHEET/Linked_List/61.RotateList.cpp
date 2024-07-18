class Solution {
    // [1,2,3,4,5], k = 2
public:
  
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;

        ListNode* temp=head;
        int cnt=1;
        while(temp->next!=NULL){
          cnt++;
          temp=temp->next;
        }

        int length=cnt;
         k=k%length;
        if(k==0) return head;
        k=length-k;
        ListNode *lastNode=head;
        while(lastNode!=NULL && k>1){
            k--;
            lastNode=lastNode->next; 
         }// we are now on 3
         cout<<lastNode->val;
         ListNode* newHead=lastNode->next;
         lastNode->next=NULL;
         temp->next=head;
 
         return newHead;
    }
};