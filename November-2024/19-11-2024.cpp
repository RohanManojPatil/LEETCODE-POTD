
*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(K)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    long long max(long long a, long long b)
    {
        if(a<b)
        {
            return b;
        }
        else
        {
            return a;
        }
    }
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_set<int> st;
        long long currentSum = 0;
        unordered_map<int, int> mp;
        int n = nums.size(); 

        for(int i = 0; i<k; i++)
        {
            int element = nums[i];
            st.insert(element);
            currentSum += element;
            mp[element]++;
        }

        if(st.size() == k)
        {
            ans = max(ans, currentSum);
        }

        for(int j = k; j<n; j++)
        {
            int incomingElement = nums[j];

            int outgoingElement = nums[j-k];

            currentSum -= outgoingElement;
            if(mp[outgoingElement] == 1)
            {
                st.erase(st.find(outgoingElement));
            }

            mp[outgoingElement]--;

            currentSum += incomingElement;
            st.insert(incomingElement);
            mp[incomingElement]++;

            if(st.size() == k)
            {
                ans = max(ans, currentSum);
            }
        }

        return ans;
    }
};