#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverseListOptimized(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev; 
        prev = current;        
        current = nextNode;    
    }
    return prev;
}


ListNode* reverseListBruteForce(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* newHead = reverseListBruteForce(head->next);
    head->next->next = head;
    head->next = NULL;
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

    ListNode* reversedHead = reverseListOptimized(head); 
    printList(reversedHead); 
    
    return 0;
}