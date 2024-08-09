class Solution {
public:
    int stoi(char ch)
    {
        return ch-'0';
    }
    int countSeniors(vector<string>& details) {
        int ans = 0;

        for(int i = 0; i<details.size(); i++)
        {
            int digit1 = stoi(details[i][11]);
            int digit2 = stoi(details[i][12]);

            if((digit1>=6 && digit2>=0) && (digit1+digit2 != 6))
            {
                ans++;
            }
        }

        return ans;
    }
};