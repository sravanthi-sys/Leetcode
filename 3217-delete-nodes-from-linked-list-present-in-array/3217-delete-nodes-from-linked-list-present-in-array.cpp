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
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        ListNode* p=head;
        ListNode* q=head;
        bool first=true;
        while(p && q->next){
            if(first && s.find(head->val) != s.end() ){
            head=head->next;
            q=p->next;
            p=p->next;
            
            }
            else if(s.find(p->val)!= s.end()){
                q->next=p->next;
                
                p=p->next;
                first=false;
            }
            else{
                q=p;
                p=p->next;
            }
        }
        return head;
    }
};