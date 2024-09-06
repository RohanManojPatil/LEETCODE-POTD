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
        unordered_map<int, int> mp;
        for(int i = 0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        ListNode* temp = head, *head1 = NULL;
        ListNode* curr = new ListNode(-1);

        while(temp != NULL)
        {
            if(mp.find(temp->val) == mp.end())
            {
                ListNode* newNode = new ListNode(temp->val);
                curr->next = newNode;
                curr = newNode;

                if(head1 == NULL)
                {
                    head1 = curr;
                }
            }

            temp = temp->next;
        }

        return head1;
    }
};