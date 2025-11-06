#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* findMiddleOptimized(ListNode* head) {
    if (head == NULL) return NULL;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* findMiddleBruteForce(ListNode* head) {
    if (head == NULL) return NULL;

    int count = 0;
    ListNode* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    int middleIndex = count / 2;
    current = head;
    for (int i = 0; i < middleIndex; ++i) {
        current = current->next;
    }
    return current;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* mid = findMiddleOptimized(head);
    cout << "Middle Node Value (Optimized): " << mid->val << endl; // Output: 3
    
    return 0;
}