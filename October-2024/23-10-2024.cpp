
*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                          * 
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int currentLevelSum = 0;

        while(!q.empty())
        {
            int size = q.size();
            int nextLevelSum = 0;

            while(size--)
            {
                pair<TreeNode*, int> p = q.front();
                q.pop();

                TreeNode* node = p.first;
                node->val = currentLevelSum - p.second;
                int siblingSum = 0;

                if(node->left)
                {
                    nextLevelSum += node->left->val;
                    siblingSum += node->left->val;
                }
                if(node->right)
                {
                    nextLevelSum += node->right->val;
                    siblingSum += node->right->val;
                }

                if(node->left)
                {
                    q.push({node->left, siblingSum});
                }
                if(node->right)
                {
                    q.push({node->right, siblingSum});
                }
            }

            currentLevelSum = nextLevelSum;
        }

        return root;
    }
};