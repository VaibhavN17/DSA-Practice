#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;          // move by 1
            fast = fast->next->next;    // move by 2
            if (slow == fast) return true; // cycle found
        }
        return false; // reached null → no cycle
    }
};

int main() {
    Solution sol;

    // Create a linked list: 1 -> 2 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    // Introduce a cycle: node 3 points back to node 2
    head->next->next->next = head->next;

    if (sol.hasCycle(head)) {
        std::cout << "Cycle detected" << std::endl;
    } else {
        std::cout << "No cycle detected" << std::endl;
    }

    return 0;
}
