class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> countMap;
        vector<string> distinct;

        // Count occurrences of each string
        for(const string& str : arr) {
            countMap[str]++;
        }
        
        // Collect strings that appear exactly once
        for(const string& str : arr) {
            if(countMap[str] == 1) {
                distinct.push_back(str);
            }
        }
        
        // Return the k-th distinct string if available
        if(k > distinct.size()) {
            return "";
        }
        
        return distinct[k - 1];
    }
};