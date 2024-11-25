*******************************LEETCODE POTD*************************
*	               T.C = O(n*m!)							                * 
*	               							                        * 
*	               S.C = O(n*m!)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int, vector<int>> mp;
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {1, 3, 5};
        mp[5] = {2, 4};

        queue<string> q;
        string target = "123450";
        string curr = "";
        int level = 0;
        unordered_set<string> visited;

        for(int i = 0; i<2; i++)
        {
            for(int j = 0; j<3; j++)
            {
                curr += to_string(board[i][j]);
            }
        }

        q.push(curr);

        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                string state = q.front();
                q.pop();

                if(visited.find(state) == visited.end())
                {
                    visited.insert(state);
                    if(state == target)
                    {
                        return level;
                    }

                    int zeroPosition = state.find('0');

                    for(auto pos : mp[zeroPosition])
                    {
                        string temp = state;
                        swap(temp[pos], temp[zeroPosition]);
                        q.push(temp);
                    }
                }
            }

            level++;
        }

        return -1;
    }
};