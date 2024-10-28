
*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                          * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> presence;
        int longestStreak = -1;
        for(int i = 0; i<n; i++)
        {
            int currentElement = nums[i];
            int root = static_cast<int>(sqrt(currentElement));

            if(presence.find(root) != presence.end() && root*root != currentElement)
            {
                presence[currentElement] = 1;
            }
            else
            {
                presence[currentElement] = 1 + presence[root];
            }

            longestStreak = max(longestStreak, presence[currentElement]);
        }

        if(longestStreak == 1)
        {
            return -1;
        }
        else
        {
            return longestStreak;
        }


    }
};