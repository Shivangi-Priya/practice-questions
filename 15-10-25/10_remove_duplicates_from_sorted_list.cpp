#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// --- Optimized Solution (Single Pass) ---
ListNode* deleteDuplicatesOptimized(ListNode* head) {
    ListNode* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            ListNode* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate; // Free memory of the duplicate node
        } else {
            current = current->next;
        }
    }
    return head;
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
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    ListNode* uniqueList = deleteDuplicatesOptimized(head);
    printList(uniqueList); 
    
    return 0;
}