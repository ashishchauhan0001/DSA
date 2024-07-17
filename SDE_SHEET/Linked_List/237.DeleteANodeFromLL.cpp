class Solution {
public:
// as it is a random node we can delete it directly.
// so we need to traverse one value i L.L
    void deleteNode(ListNode* node) {
        if(node==NULL||node->next==NULL) return ;
        ListNode* temp=node->next;
        node->val=temp->val;
        node->next=temp->next;
        delete temp;
        return ;
    }
};