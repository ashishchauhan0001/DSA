Node * makeLL(vector<int> &arr){
    Node* dummy=new Node(-1);
    Node *curr=dummy;
    for(int i=0;i<arr.size();i++){
        Node *newNode=new Node(arr[i]);
        curr->bottom=newNode;
        curr=curr->bottom;
    }
    
    return dummy->bottom;
}    
    
Node *flatten(Node *head) {
    // Your code here
  vector<int> arr;

    // Traverse through the linked list
    while (head != nullptr) {
        // Traverse through the child
        // nodes of each head node
        Node* t2 = head;
        while (t2 != nullptr) {
            // Store each node's data in the array
            arr.push_back(t2->data);
            // Move to the next child node
            t2 = t2->bottom;
        }
        // Move to the next head node
        head = head->next;
    }
    sort(arr.begin(),arr.end());
    
    Node *root=makeLL(arr);
    
    return  root;
}


// Optimal will be done merge sort like algo... will upload soon