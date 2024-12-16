*******************************LEETCODE POTD*************************
*	               T.C = O(nlogn)							                * 
*	               							                        * 
*	               S.C = O(n)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        
        // Custom comparator: compare by value first, then by index
        auto comparator = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first)
                return a.second > b.second; // if values are the same, compare by index
            return a.first > b.first; // otherwise, compare by value
        };

        // Min-heap with the custom comparator
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq(comparator);
        vector<int> ans(n, 0);

        // Insert elements with their indices
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        // Replace the smallest element `k` times
        while (k--) {
            pair<int, int> top = pq.top();
            pq.pop();

            int replace = top.first * multiplier;
            pq.push({replace, top.second});
        }

        // Store the final state of the elements based on the index
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            int index = top.second, num = top.first;
            
            ans[index] = num;
        }

        return ans;
    }
};
