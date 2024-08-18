class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1, 0);
        int i2, i3, i5;
        i2 = i3 = i5 = 1;
        arr[1] = 1;

        for(int i = 2; i<=n; i++)
        {
            int i2Ugly = arr[i2] * 2;
            int i3Ugly = arr[i3] * 3;
            int i5Ugly = arr[i5] * 5;

            int num = min({i2Ugly, i3Ugly, i5Ugly});

            if(i2Ugly == num)
            {
                i2++;
            }
            if(i3Ugly == num)
            {
                i3++;
            }
            if(i5Ugly == num)
            {
                i5++;
            }

            arr[i] = num;
        }

        return arr[n];
    }
};