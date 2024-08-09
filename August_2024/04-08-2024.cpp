class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
       int temp = 0;
       const int  mod = 1e9 + 7;
       int ans[n * (n+1)/2];
       for(int i= 0, k=0; i<n; i++) 
       {
         int sum = 0;
         for(int j = i; j<n; j++)
         {
            sum += nums[j];
            ans[k++] = sum;
         }
}
         sort(ans, ans+n*(n+1)/2);

         for( int l = left-1; l< right; l++)  
         {
            temp = (temp + ans[l]) % mod;
          
         }

         return temp;
       }
    
};