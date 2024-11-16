
*******************************LEETCODE POTD*************************
*	               T.C = O(N*K)							                * 
*	               							                        * 
*	               S.C = O(N-K)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
    vector<int> result;

    for (int i = 0; i <= n - k; ++i) {
        bool isConsecutive = true;
        for (int j = i; j < i + k - 1; ++j) {
            if (nums[j] + 1 != nums[j + 1]) {
                isConsecutive = false;
                break;
            }
        }

        if (isConsecutive) {
            result.push_back(*max_element(nums.begin() + i, nums.begin() + i + k));
        } else {
            result.push_back(-1);
        }
    }

    return result;
    }
};