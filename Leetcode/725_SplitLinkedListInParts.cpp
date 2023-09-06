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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans(k, nullptr);
        ListNode* tmp = root;
        int len = 0;
        while(tmp != NULL){
            tmp = tmp->next;
            len++;
        }
        tmp = root;
        int width = len/k, rem = len%k;
        for(int i=0; i<k; i++){
            ListNode *head = tmp;
            for(int j=0; j<width + (i<rem ? 1 : 0)-1; j++){
                if(tmp != NULL){
                    tmp = tmp->next;
                }
            }
            if(tmp != NULL){
                ListNode* prev = tmp;
                tmp = tmp->next;
                prev->next = NULL;
            }
            ans[i] = head;
        }
        return ans;
    }
};
