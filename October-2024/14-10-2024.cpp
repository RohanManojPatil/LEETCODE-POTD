
*******************************LEETCODE POTD*************************
*	               T.C = O(N∗Log(N))							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size();
        long long maximumScore = 0;

        for(int i = 0; i<n; i++)
        {
            pq.push(nums[i]);
        }

        while(k-- && !pq.empty())
        {
            int maximumElement = pq.top();
            pq.pop();
            maximumScore += maximumElement;
            pq.push(ceil((double)maximumElement/3));
            cout << maximumElement << " ";
        }

        return maximumScore;
    }
};