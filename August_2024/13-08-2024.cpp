class Solution {
public:
    set<vector<int>> ans;  // Use set to handle uniqueness
    
    void solve(int i, vector<int>& candidates, int target, vector<int> &temp, int sum) {
        if (sum > target) {
            return;  // If sum exceeds target, terminate this branch
        }
        if (sum == target) {
            ans.insert(temp);  // Insert into set to avoid duplicates
            return;
        }

        for (int j = i; j < candidates.size(); ++j) {
            // Skip duplicates by checking if the current number is the same as the previous one
            if (j > i && candidates[j] == candidates[j - 1]) continue;

            temp.push_back(candidates[j]);
            solve(j + 1, candidates, target, temp, sum + candidates[j]);  // Recurse with next index
            temp.pop_back();  // Backtrack
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
        vector<int> temp;
        solve(0, candidates, target, temp, 0);
        
        return vector<vector<int>>(ans.begin(), ans.end());  // Convert set to vector
    }
};
