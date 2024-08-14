class Solution {
public:
    int slidingWindow(vector<int>& nums, int distance)
    {
        int i = 0, j = 1, n = nums.size(), totalPairs = 0;

        while(j<n)
        {
            while(nums[j]-nums[i] > distance)
            {
                i++;
            }

            totalPairs += (j - i);
            j++;
        }

        return totalPairs;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int left = 0;
        int right = nums[n-1] - nums[0], ans = 0;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            int countPairs = slidingWindow(nums, mid);

            if(countPairs < k)
            {
                left = mid+1;
            }
            else
            {
                ans = mid;
                right = mid-1;
            }
        }

        return ans;
    }
};