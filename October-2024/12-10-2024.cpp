
*******************************GFG POTD******************************
*	               T.C = O(n)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
         int max=-1;
         
        for(int i=1;i<arr.size();i++){
            if(max<arr[i]+arr[i-1]) max=arr[i]+arr[i-1];
        }
        return max;
    }
};