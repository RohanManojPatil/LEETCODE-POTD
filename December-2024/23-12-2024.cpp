*******************************LEETCODE POTD*************************
*	               T.C = O(nlogn)							                * 
*	               							                        * 
*	               S.C = O(n)                                           * 
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
    int cycleSort(vector<int>& temp) {
    int n = temp.size();
    vector<int> sortedTemp = temp; 
    sort(sortedTemp.begin(), sortedTemp.end()); // Sorted version of the array
    unordered_map<int, int> indexMap;

    // Map values to their sorted positions
    for (int i = 0; i < n; i++) {
        indexMap[sortedTemp[i]] = i;
    }

    vector<bool> visited(n, false);
    int swapCount = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || indexMap[temp[i]] == i) {
            continue; // Skip already visited or correctly placed elements
        }

        int cycleLength = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            j = indexMap[temp[j]];
            cycleLength++;
        }

        if (cycleLength > 1) {
            swapCount += (cycleLength - 1); // Swaps required = cycle length - 1
        }
    }

    return swapCount;
}

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int numOperations = 0;

        while(!q.empty())
        {
            vector<int> levelElements;
            int size = q.size();
    
            while(size--)
            {
                TreeNode* currNode = q.front();
                q.pop();
                if(currNode->left)
                {
                    q.push(currNode->left);
                    levelElements.push_back(currNode->left->val);
                }
                if(currNode->right)
                {
                    q.push(currNode->right);
                    levelElements.push_back(currNode->right->val);
                }
            }

            if(levelElements.size() > 0)
            {
                numOperations += cycleSort(levelElements);
            }
        }

        return numOperations;
    }
};