class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) {
            return {};  // Return an empty matrix if conversion isn't possible
        }
        
        vector<vector<int>> mat(m, vector<int>(n, 0));
        
        for (int i = 0; i < original.size(); ++i) {
            int row = i / n;
            int col = i % n;
            mat[row][col] = original[i];
        }
        
        return mat;
    }
};
