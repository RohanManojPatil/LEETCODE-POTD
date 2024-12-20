*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        stack<int> st;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                TreeNode *currentNode = q.front();
                q.pop();

                if(currentNode->left)
                {
                    q.push(currentNode->left);
                    q.push(currentNode->right);
                }

                if(level%2 != 0)
                {
                    currentNode->val = st.top();
                    st.pop();
                }
                else
                {
                    if(currentNode->left)
                    {
                        st.push(currentNode->left->val);
                        st.push(currentNode->right->val);
                    }
                }
            }

            level++;
        }

        return root;
    }
};