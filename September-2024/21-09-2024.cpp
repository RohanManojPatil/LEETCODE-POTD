class Solution {
public:
    vector<int> ans;
    void dfs(int x, int limit)
    {
        if(x*10 > limit)
        {
            return;
        }

        for(int i = 0; i<10; i++)
        {
            int temp = x * 10 + i;

            if(temp > limit)
            {
                return;
            }

            ans.push_back(temp);
            dfs(temp, limit);
        }
    }
    vector<int> lexicalOrder(int n) {
        
        for(int i = 1; i<10; i++)
        {
            if(i > n)
            {
                break;
            }
            ans.push_back(i);
            dfs(i, n);
        }

        return ans;
    }
};