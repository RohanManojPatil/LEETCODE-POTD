
*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // If both roots are null, the trees are equivalent
        if (!root1 && !root2) return true;
        // If one is null and the other isn't, the trees aren't equivalent
        if (!root1 || !root2) return false;
        // If the values don't match, they aren't equivalent
        if (root1->val != root2->val) return false;
        
        // Check if the trees are equivalent without flip or with flip
        bool noFlip = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        bool flip = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        
        return noFlip || flip;
    }
};
