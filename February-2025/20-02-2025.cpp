*******************************LEETCODE POTD*************************
*	               T.C = O(2^N)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int n;
    unordered_set<string> st;
    string ans = "";
    void solve(int index, vector<string>& nums, string temp)
    {
        if(index >= n)
        {
            if(st.find(temp) == st.end())
            {
                ans = temp;
            }

            return;
        }

        temp.push_back('0');
        solve(index+1, nums, temp);
        temp.pop_back();

        temp.push_back('1');
        solve(index+1, nums, temp);
        temp.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums[0].length();
        string temp = "";
        for(int i = 0; i<nums.size(); i++)
        {
            st.insert(nums[i]);
        }

        solve(0, nums, temp);

        return ans;
    }
};