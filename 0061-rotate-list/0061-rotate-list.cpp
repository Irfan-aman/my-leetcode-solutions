/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int sizeOfList(ListNode* head) {
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = sizeOfList(head);
        if (n == 0)
            return head;
        if (k>=n) k = k % n;
        if (k == 0 || head == NULL || head->next == NULL)
            return head;
        int m = n - k;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (m) {
            prev = temp;
            temp = temp->next;
            m--;
        }
        ListNode* oldHead = head;
        head = prev->next;
        prev->next = nullptr;
        prev=head;
        while (prev->next) {
            prev = prev->next;
        }
        prev->next = oldHead;
        return head;
    }
};