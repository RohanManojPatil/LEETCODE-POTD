class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, bool> mp;
        int ans = 0;

        for(auto ch : allowed)
        {
            mp[ch] = 1;
        }

        for(int i = 0; i<words.size(); i++)
        {
            bool flag = true;
            for(int j = 0; j<words[i].size(); j++)
            {
                if(mp[words[i][j]] == 0)
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                ans++;
            }
        }

        return ans;
    }
};