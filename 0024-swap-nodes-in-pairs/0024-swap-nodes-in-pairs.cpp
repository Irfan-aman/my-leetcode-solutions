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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* prev = NULL;
        ListNode* first = head;
        ListNode* sec = head->next;
        head = sec;
        while (sec) {
            ListNode* third = sec->next;
            sec->next = first;
            first->next = third;
            if (prev)
                prev->next = sec;
            prev = first;
            first = third;
            if (third && third->next)
                sec = third->next;
            else
                break;
        }
        return head;
    }
};