#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


int countNodesOptimized(ListNode* head) {
    int count = 0;
    ListNode* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}


int countNodesBruteForce(ListNode* head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + countNodesBruteForce(head->next);
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Node Count (Optimized): " << countNodesOptimized(head) << endl;
    cout << "Node Count (Brute Force): " << countNodesBruteForce(head) << endl;
    
    return 0;
}