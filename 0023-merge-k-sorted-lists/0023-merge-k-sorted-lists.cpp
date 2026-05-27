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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        priority_queue<int,vector<int>,greater<int>> pq;
        ListNode* head = NULL; 
        for(int i =0; i<lists.size(); i++){
            if(lists[i] != NULL){
                if(head == NULL) head = lists[i];
                ListNode* temp = lists[i];
                while(temp->next != NULL){
                    pq.push(temp->val);
                    temp = temp->next;
                }
                pq.push(temp->val);
                if(i < lists.size()-1){
                    int k = i+1;
                    while(k < lists.size() && lists[k] == NULL) k++;
                    if(k < lists.size()) temp->next = lists[k];
                } 
            }
        }
        ListNode* temp = head;
        while(temp != NULL){
            temp->val = pq.top();
            pq.pop();
            temp = temp->next;
        }
        return head;
    }
};