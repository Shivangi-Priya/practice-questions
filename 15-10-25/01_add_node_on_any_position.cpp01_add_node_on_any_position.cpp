#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insertNode(ListNode*& head, int data, int position) {
    ListNode* newNode = new ListNode(data);

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    ListNode* current = head;
    int count = 1;

    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) return; // Position out of bounds

    newNode->next = current->next;
    current->next = newNode;
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
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    
    insertNode(head, 15, 2); // Insert 15 at position 2
    insertNode(head, 5, 1);  // Insert 5 at position 1 (head)
    
    printList(head); // Output: 5 -> 10 -> 15 -> 20 -> NULL
    return 0;
}
