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
class FindElements {
public:
    unordered_map<long long, bool> presence; 
    FindElements(TreeNode* root) {
        queue<TreeNode*> q;
        root->val = 0;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* node = q.front();
            presence[node->val] = 1;
            q.pop();

            if(node->left)
            {
                node->left->val = 2 * (node->val) + 1;
                q.push(node->left);
            }
            if(node->right)
            {
                node->right->val = 2 * (node->val) + 2;
                q.push(node->right);
            }
        }
    }
    
    bool find(int target) {
        if(presence.find(target) == presence.end())
        {
            return false;
        }

        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */