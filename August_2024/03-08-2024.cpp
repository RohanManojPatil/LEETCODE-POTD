class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp1, mp2;
        for(int i=0; i<target.size(); i++)
        {
            mp1[arr[i]]++;
            mp2[target[i]]++;

        }
        for(auto &[num, count] : mp1)
        {
           if(mp2.find(num) != mp2.end())
           {
             if(count != mp2[num])
             {
                      return false;
             }
           }
           else
           {
            return false;
           }
        }


        return true;
    }
};