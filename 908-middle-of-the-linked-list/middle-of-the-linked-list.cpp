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
    // int leng(ListNode* head){
    //     ListNode* temp=head;
    //     int cnt=0;
    //     while(temp!=NULL){
    //         cnt++;
    //         temp=temp->next;
    //     }
    //     return cnt;

    // }
    ListNode* middleNode(ListNode* head) {
        if(head->next==NULL) return head;
        // int n=leng(head);
        // int mid=(n/2)+1;
        ListNode* tor=head;
        ListNode* har=head;
        // int cnt=0;
        while(har!=NULL&&har->next!=NULL){
            har=har->next;
            har=har->next;
            tor=tor->next;
        }
        return tor;        
    }
};