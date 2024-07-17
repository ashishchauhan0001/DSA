class Solution {
public:
   // brute force--> Use Stack to store the elements and traverse to stack and LL simultaneously for checking it
   // better--> make a new linked list and reverse it and check by traversing
   // optimal--> break the linked list from the middle and reverse it and check it 
   
   ListNode *rev(ListNode *head) {
    ListNode *curr = head;
    ListNode *next = NULL;
    ListNode *prev = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(ListNode *head) {
    if (!head || !head->next) return true;  // Handle edge cases
    
    ListNode *slow = head;
    ListNode *fast = head;

    // Find the middle of the linked list
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Reverse the second half of the list
    ListNode *newHead = rev(slow);

    // Compare the first and the second half
    while (newHead != NULL) {
        if (newHead->val != head->val) return false;
        newHead = newHead->next;
        head = head->next;
    }

    return true;
}
};