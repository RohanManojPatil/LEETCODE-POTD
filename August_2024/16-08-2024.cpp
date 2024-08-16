class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        pair<int, int> firstMini = {INT_MAX, -1}, firstMaxi = {INT_MIN, -1};
        pair<int, int> secondMini = {INT_MAX, -1}, secondMaxi = {INT_MIN, -1};

        for(int i = 0; i<arrays.size(); i++)
        {
            int j = arrays[i].size()-1;
            int mini = arrays[i][0];
            int maxi = arrays[i][j];

            if(firstMini.first > mini)
            {
                firstMini = {mini, i};
            }
            if(firstMaxi.first < maxi)
            {
                firstMaxi = {maxi, i};
            }
        }

        if(firstMini.second != firstMaxi.second)
        {
            return abs(firstMaxi.first - firstMini.first);
        }
        else
        {

            for(int i = 0; i<arrays.size(); i++)
            {
                int j = arrays[i].size()-1;
                int mini = arrays[i][0];
                int maxi = arrays[i][j];

                if(secondMini.first > mini && i != firstMini.second)
                {
                    secondMini = {mini, i};
                }
                if(secondMaxi.first < maxi && i != firstMaxi.second)
                {
                    secondMaxi = {maxi, i};
                }
            }

            return max(abs(firstMaxi.first - secondMini.first), abs(secondMaxi.first - firstMini.first));
        }
    }
};