#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// --- Optimized Solution (Iterative) ---
bool searchNodeOptimized(ListNode* head, int target) {
    ListNode* current = head;
    while (current != NULL) {
        if (current->val == target) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// --- Brute-Force/Alternative Solution (Recursive) ---
bool searchNodeBruteForce(ListNode* head, int target) {
    if (head == NULL) {
        return false;
    }
    if (head->val == target) {
        return true;
    }
    return searchNodeBruteForce(head->next, target);
}

int main() {
    ListNode* head = new ListNode(5);
    head->next = new ListNode(10);
    head->next->next = new ListNode(15);

    int target1 = 10;
    cout << "Search for " << target1 << " (Optimized): " << (searchNodeOptimized(head, target1) ? "Found" : "Not Found") << endl; 

    int target2 = 25;
    cout << "Search for " << target2 << " (Brute Force): " << (searchNodeBruteForce(head, target2) ? "Found" : "Not Found") << endl; 
    
    return 0;
}