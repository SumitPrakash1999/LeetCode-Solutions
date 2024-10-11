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
    ListNode* getKnode(ListNode* temp, int k){
        k--;
        while(k>0&&temp!=NULL){
            temp=temp->next;
            k--;
        }
        if(k>0) return NULL;
        else return temp;
    }
    void reverseLL(ListNode* head){
        ListNode* cur=head;
        ListNode* prev=NULL;
        while(cur){
            ListNode* nextNode=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextNode;
        }
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        while(temp){
            ListNode* kthNode=getKnode(temp,k);
            if(kthNode==NULL){
                if(prevNode) prevNode->next=temp;
                break;
            }
            ListNode* nextNode=kthNode->next;
            kthNode->next=NULL;
            reverseLL(temp);
            if(temp==head){
                head=kthNode;
            }
            else{
                prevNode->next=kthNode;                              
            }
            prevNode=temp;  
            temp=nextNode;

        }
        return head;
        
    }
};