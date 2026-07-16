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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=l1->val + l2->val;
        int carry=sum/10; sum =sum % 10;
        ListNode* head=new ListNode(sum);
        ListNode* temp=head;
        l1=l1->next; l2=l2->next;
        while(l1 && l2){
            int currSum=l1->val + l2->val +carry;
            carry=currSum/10;
            currSum = currSum% 10;
            ListNode* newNode=new ListNode(currSum);
            temp->next=newNode;
            temp=newNode;
            l1=l1->next; l2=l2->next;
        }
        while(l1){
            int currSum=l1->val + carry;
            carry=currSum/10;
            currSum = currSum% 10;
            ListNode* newNode=new ListNode(currSum);
            temp->next=newNode;
            temp=newNode;
            l1=l1->next;
        }
        while(l2){
            int currSum= l2->val +carry;
            carry=currSum/10;
            currSum = currSum% 10;
            ListNode* newNode=new ListNode(currSum);
            temp->next=newNode;
            temp=newNode;
            l2=l2->next;
        }
        if(carry){
            ListNode* newNode=new ListNode(carry);
            temp->next=newNode;
        }
        return head;
    }
};