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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while(head != NULL){
            while(head != NULL && st.find(head -> val) != st.end()){
                head = head -> next;
            }
            if(head == NULL)continue;
            p -> next = head;
            p = p -> next;
            head = head -> next;
        }
        return dummy -> next;
    }
};