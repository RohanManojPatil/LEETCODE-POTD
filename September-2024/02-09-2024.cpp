class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        long long remain = k%sum;

        for(int i = 0; i<chalk.size(); i++)
        {
            if(chalk[i] > remain)
            {
                return i;
            }

            remain -= chalk[i];
        }

        return -1;
    }
};