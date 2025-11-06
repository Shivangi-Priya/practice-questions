#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// --- Optimized Solution (Iteration with Carry) ---
ListNode* addTwoNumbersOptimized(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }

    return dummy.next;
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
    // 342 + 465 = 807 (Lists stored in reverse order)
    ListNode* l1 = new ListNode(2); l1->next = new ListNode(4); l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5); l2->next = new ListNode(6); l2->next->next = new ListNode(4);

    ListNode* sumList = addTwoNumbersOptimized(l1, l2);
    printList(sumList); // Output: 7 -> 0 -> 8 -> NULL
    
    return 0;
}