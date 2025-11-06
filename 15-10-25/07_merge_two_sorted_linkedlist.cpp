#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// --- Optimized Solution (Iterative with Dummy Node) ---
ListNode* mergeTwoListsOptimized(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;

    return dummy.next;
}

// --- Brute-Force/Alternative Solution (Recursive) ---
ListNode* mergeTwoListsBruteForce(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    if (l1->val < l2->val) {
        l1->next = mergeTwoListsBruteForce(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoListsBruteForce(l1, l2->next);
        return l2;
    }
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
    ListNode* l1 = new ListNode(1); l1->next = new ListNode(3); l1->next->next = new ListNode(5);
    ListNode* l2 = new ListNode(2); l2->next = new ListNode(4); l2->next->next = new ListNode(6);

    ListNode* merged = mergeTwoListsOptimized(l1, l2);
    printList(merged); // Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    
    return 0;
}