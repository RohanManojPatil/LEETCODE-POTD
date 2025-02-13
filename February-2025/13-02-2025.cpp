*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
typedef long long ll;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        int ans = 0;

        for(int i = 0; i<nums.size(); i++)
        {
            pq.push(nums[i]);
        }

        while(!pq.empty())
        {
            ll x = pq.top();
            pq.pop();

            if(x >= k)
            {
                return ans;
            }
            
            ll y = pq.top();
            pq.pop();

            ll mini = min(x, y);
            ll maxi = max(x, y);

            ll temp = mini * 2 + maxi;

            pq.push(temp);
            ans++;
        }

        return ans;
    }
};