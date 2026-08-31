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
        int first=-1,last=-1,mn=1e9;
        int i=0;
        while(head->next->next!=nullptr){
            int a=head->val;
            int b=head->next->val;
            int c=head->next->next->val;

            if((b>a && b>c) || (b<a && b<c)){
                if(first==-1){
                    first=i;
                    last=i;
                }
                else{
                    mn=min(mn,i-last);
                    last=i;
                }
            }
            i++;
            head=head->next;
        }
        if(first==last) return {-1,-1};

        return {mn,last-first};

    }
};