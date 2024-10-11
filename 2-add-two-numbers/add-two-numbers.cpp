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
    int length(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    void insertatend(ListNode* head, int val){
        ListNode* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        ListNode* newNode=new ListNode(val);
        temp->next=newNode;
        return;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1=length(l1);
        int n2=length(l2);
        ListNode* temp=l1;
        ListNode* temp1=l2;
        int carry=0;
        if(n1>n2){
            while(temp1!=NULL){
            temp->val=temp->val+temp1->val+carry;
            carry=0;
            if(temp->val>=10){
                temp->val-=10;
                carry=1;
            }
            temp=temp->next;
            temp1=temp1->next;
            }
            while(temp!=NULL){
                temp->val+=carry;
                carry=0;
                if(temp->val>=10){
                temp->val-=10;
                carry=1;
                }
                temp=temp->next;
            }
            if(carry==1){
                insertatend(l1,carry);
            }
            return l1;

        }
        else{
            while(temp!=NULL){
            temp1->val=temp->val+temp1->val+carry;
            carry=0;
            if(temp1->val>=10){
                temp1->val-=10;
                carry=1;
            }
            temp=temp->next;
            temp1=temp1->next;
            }
            while(temp1!=NULL){
                temp1->val+=carry;
                carry=0;
                if(temp1->val>=10){
                temp1->val-=10;
                carry=1;
                }
                temp1=temp1->next;
            }
            if(carry==1){
                insertatend(l2,carry);
            }
            return l2;
        }

        return NULL;        
        
        
    }
};