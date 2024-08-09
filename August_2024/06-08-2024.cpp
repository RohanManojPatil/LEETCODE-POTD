class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26, 0);
        int ans = 0, count = 1;

        for(int i = 0; i<word.length(); i++)
        {
            char ch = word[i];
            mp[ch-'a']++;
        }

        sort(mp.begin(), mp.end(), greater<int>());
        
        for(int i = 0; i<26; i++)
        {
            ans = ans + mp[i] * count;

            if((i+1)%8 == 0 && i != 0)
            {
                count++;
            }
        }

        return ans;
    }
};