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
    int findGCD(int a, int b)
    {
        if(b == 0)
        {
            return a;
        }

        return findGCD(b, a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
         ListNode* prev = head, *curr = head->next;
         
         if(curr == NULL)
         {
            return prev;
         }
         while(curr != NULL)
         {
             
             int gcd = findGCD(prev->val, curr->val);
            
             ListNode* gcdNode = new ListNode(gcd);
             
             prev->next = gcdNode;
             gcdNode->next = curr;
             
             prev = curr;
             curr = curr->next;
         }
        
        return head;
    }
};