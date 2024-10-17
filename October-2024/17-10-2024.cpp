
*******************************LEETCODE POTD*************************
*	               T.C = O(N*2)							                * 
*	               							                        * 
*	               S.C = O(1)                                          * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.length();
        bool swapRequired = false;

        for(int i = 0; i<n; i++)
        {
            int currentElement = str[i]-'0';
            int index = i;

            if(str[i] != '9')
            {
                for(int j = n-1; j>i; j--)
                {
                    int compareElement = str[j]-'0';
                    if(compareElement > currentElement)
                    {
                        currentElement = compareElement;
                        index = j;
                        swapRequired = true;
                    }
                }
            }

            if(swapRequired)
            {
                swap(str[i], str[index]);
                break;
            }
        }

        int target = stoi(str);

        return target;
    }
};