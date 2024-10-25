
*******************************LEETCODE POTD*************************
*	               T.C = O(nlogn)							                * 
*	               							                        * 
*	               S.C = O(N)                                          * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        int n = folder.size();
        vector<string> result;
        result.push_back(folder[0]);
        
        for(int i = 1; i<n; i++)
        {
            string currentFolder = folder[i];
            string lastFolder = result.back();
            lastFolder.push_back('/');

            if(currentFolder.find(lastFolder) != 0)
            {
                result.push_back(currentFolder);
            }
        }

        return result;
    }
};