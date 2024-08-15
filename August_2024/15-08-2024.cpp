class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount = 0, tenCount = 0, twentyCount = 0;

        if(bills[0] != 5)
        {
            return false;
        }

        fiveCount++;
        for(int i = 1; i<bills.size(); i++)
        {
            if(bills[i] == 5)
            {
                fiveCount++;
            }
            else if(bills[i] == 10)
            {
                if(fiveCount >= 1)
                {
                    fiveCount--;
                    tenCount++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(tenCount >= 1 && fiveCount >= 1)
                {
                    tenCount--;
                    fiveCount--;
                }
                else if(fiveCount >= 3)
                {
                    fiveCount -= 3;
                }
                else
                {
                    return false;
                }
                twentyCount++;
            }
        }

        return true;
    }
};