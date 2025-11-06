#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// --- Optimized Solution (Connect End to Head) ---
ListNode* rotateRightOptimized(ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) return head;

    ListNode* tail = head;
    int length = 1;
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    // Connect the tail to the head (circular list)
    tail->next = head;

    // Find the new head position (length - k % length)
    int stepsToNewHead = length - (k % length);
    
    // Traverse to the node *before* the new head
    ListNode* newTail = head;
    for (int i = 0; i < stepsToNewHead - 1; ++i) {
        newTail = newTail->next;
    }

    // New head is the node after the new tail
    ListNode* newHead = newTail->next;
    
    // Break the ring
    newTail->next = NULL;

    return newHead;
}


void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    int k = 2;

    ListNode* rotated = rotateRightOptimized(head, k);
    printList(rotated);
    
    return 0;
}