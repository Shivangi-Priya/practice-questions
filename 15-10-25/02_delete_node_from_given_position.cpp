#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode*& head, int position) {
    if (head == NULL) return;

    if (position == 1) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    ListNode* current = head;
    ListNode* prev = NULL;
    int count = 1;

    while (current != NULL && count < position) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL) return; 

    prev->next = current->next;
    delete current;
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
    head->next->next->next = new ListNode(4);

    deleteNode(head, 3); // Delete node 3 (value 3)

    printList(head); // Output: 1 -> 2 -> 4 -> NULL
    return 0;
}