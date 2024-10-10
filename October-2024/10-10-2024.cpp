
*******************************LEETCODE POTD*************************
*	               T.C = O(n)							                * 
*	               							                        * 
*	               S.C = O(n)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        int maxWidth = 0;

        for(int i = 0; i<n; i++)
        {
            if(st.empty() || nums[i]<nums[st.top()])
            {
                st.push(i);
            }
        }

        for(int j = n-1; j>=0; j--)
        {
            while(!st.empty() && nums[st.top()] <= nums[j])
            {
                maxWidth = max(maxWidth, j-st.top());
                st.pop();
            }
        }

        return maxWidth;
    }
};