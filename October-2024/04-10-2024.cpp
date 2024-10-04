
*******************************LEETCODE POTD*************************
*	               T.C = O(n)							                * 
*	               							                        * 
*	               S.C = O(1)                                          * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int i = 0, j = n-1;
        long long sum = 0;
        int equalSkill = skill[i] + skill[j];

        while(i<j)
        {
            if(skill[i]+skill[j] != equalSkill)
            {
                return -1;
            }
            else
            {
                sum += (skill[i] * skill[j]);
            }

            i++;
            j--;
        }

        return sum;
    }
};