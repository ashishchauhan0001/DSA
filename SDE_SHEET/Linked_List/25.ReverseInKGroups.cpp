class Solution {
public:
ListNode* reverseLinkedList(ListNode *head)
{

   ListNode* temp = head;  
   ListNode* prev = NULL;  

   while(temp != NULL){  
       ListNode* front = temp->next;  
       temp->next = prev;  
       prev = temp; 
       temp = front; 
   }
   return prev;  
}


ListNode* getKthListNode(ListNode* temp, int k){
    k -= 1; 
    while(temp != NULL && k > 0){
        k--; 
        temp = temp -> next; 
    }
    
    return temp; 
}

ListNode* reverseKGroup(ListNode* head, int k){
    ListNode* temp = head; 

    ListNode* prevLast = NULL; 
    
    while(temp != NULL){
        ListNode* kThListNode = getKthListNode(temp, k); 

        if(kThListNode == NULL){ // no k elements left so as it is joining
            if(prevLast){
                prevLast -> next = temp; 
            }
            
            break; 
        }
        
        ListNode* nextListNode = kThListNode -> next; // saving the breaked pointer

        kThListNode -> next = NULL; 

        reverseLinkedList(temp); 

        if(temp == head){ // if this is a first partition
            head = kThListNode;
        }else{ 
            prevLast -> next = kThListNode; // for merging the last with curr list
        }

        prevLast = temp; // after reverse the last element in the list

        temp = nextListNode; // first node in the next list
    }
    
    return head; 
}
};