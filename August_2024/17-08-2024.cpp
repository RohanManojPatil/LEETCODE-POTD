class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points[0].size(), n = points.size();
        vector<long long> prev(m), curr(m), left(m, 0), right(m, 0);

        // Initialize the first row
        for(int i = 0; i < m; i++) {
            prev[i] = points[0][i];
        }

        // Iterate through all rows starting from the second row
        for(int i = 1; i < n; i++) {
            left[0] = prev[0];
            right[m-1] = prev[m-1];

            // Calculate left max array
            for(int j = 1; j < m; j++) {
                left[j] = max(left[j-1] - 1, prev[j]);
            }

            // Calculate right max array
            for(int j = m - 2; j >= 0; j--) {
                right[j] = max(right[j + 1] - 1, prev[j]);
            }

            // Calculate the current row based on left and right max values
            for(int k = 0; k < m; k++) {
                curr[k] = points[i][k] + max(left[k], right[k]);
            }

            // Move to the next row
            prev = curr;
        }

        // Return the maximum points in the last row
        return *max_element(prev.begin(), prev.end());
    }
};
