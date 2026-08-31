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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> list;
        if (head->next->next == NULL)
            return {-1, -1};
        int firstMinOrMax = -1;
        int ans1 = -1, ans2 = -1;
        int prev = head->val;
        int curr = head->next->val;
        ListNode* temp = head->next->next;
        int idx = 2;
        while (temp) {
            int next = temp->val;
            if ((curr < prev && curr < next) || (curr > prev && curr > next)) {
                list.push_back(idx);
            }
            temp = temp->next;
            prev = curr;
            curr = next;
            idx++;
        }
        if (list.size() > 1)
            ans1 = list[1] - list[0];
        for (int i = 2; i < list.size(); i++) {
            ans1 = min(ans1, list[i] - list[i - 1]);
        }
        if (list.size() > 1)ans2 = list[list.size() - 1] - list[0];
        return {ans1, ans2};
    }
};