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
    ListNode* moveNode(ListNode* head,int k){
        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=0;i<=k;i++){
            fast=fast->next;
        }
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
    int length(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* nextNode=NULL;
        int len=length(temp);
        k=k%len;
        if(k==0) return head;
        temp=moveNode(temp,k);
        nextNode=temp->next;
        temp->next=NULL;
        ListNode* temp1=nextNode;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=head;
        head=nextNode;
        return head;        
    }
};