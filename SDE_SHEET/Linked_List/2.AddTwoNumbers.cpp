class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
       int carry=0;
       int sum=0;
       ListNode* head=new ListNode();
       ListNode*temp=head;
       while(l1!=NULL||l2!=NULL||carry) 
       {
           sum=carry;
           if(l1!=NULL)
           {
               sum+=l1->val;
               l1=l1->next;
           }
           if(l2!=NULL)
           {
               sum+=l2->val;
               l2=l2->next;
           }
           carry=sum/10;
           ListNode *val=new ListNode(sum%10);
           temp->next=val;
           temp=temp->next;
       }
       if(carry){
        ListNode *newNode=new ListNode(carry);
        temp->next=newNode;
       }

       return (head->next);
    }
};