class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string str1 = to_string(a);
            string str2 = to_string(b);
            return str1 + str2 > str2 + str1;
        });

        string ans = "";
        
        if (nums[0] == 0) {
            return "0";
        }
        for(int i = 0; i<n; i++)
        {
            ans += to_string(nums[i]);
        }

        return ans;
    }
};