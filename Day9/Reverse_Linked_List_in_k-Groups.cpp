#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public: 
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while (curr != NULL && count != k) {
            curr = curr->next;
            count++;
        }
        if (count == k) {
            curr = reverseKGroup(curr, k);
            while (count-- > 0) {
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
            }
            head = curr;
        }
        return head;
    }
};
int main(){
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;
    ListNode* newHead = sol.reverseKGroup(head, k);
    while (newHead != NULL) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    return 0;
}