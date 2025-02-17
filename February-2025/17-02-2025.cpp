*******************************GFG POTD*************************
*	               T.C = O(klogk)							                * 
*	               							                        * 
*	               S.C = O(k)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans;
        
        for(int i = 0; i<arr.size(); i++)
        {
            pq.push(arr[i]);
            
            if(pq.size() > k)
            {
                pq.pop();
            }
            
        }
        
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};