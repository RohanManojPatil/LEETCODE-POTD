
*******************************LEETCODE POTD*************************
*	               T.C = O(N * log(k))							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            long long currentlevelsum = 0;
            level++;

            while(size--)
            {
                TreeNode* node = q.front();
                q.pop();
                currentlevelsum += node->val;

                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }

            pq.push(currentlevelsum);

            while(pq.size()>k)
            {
                pq.pop();
            }
        }

        if(level<k)
        {
            return -1;
        }
        return pq.top();
    }
};