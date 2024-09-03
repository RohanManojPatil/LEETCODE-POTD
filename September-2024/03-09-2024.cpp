class Solution {
public:
    int sumOfDigits(int temp)
    {
       int sum = 0;

        while(temp != 0)
        {
            int rem = temp%10;
            temp= temp/10;
            sum += rem;
        }

        return sum;
    }
    int getLucky(string s, int k) {
        string ans = "";
        int result = 0;

        for(int i = 0; i<s.length(); i++)
        {
            char ch = s[i];
            int num = ch-'a'+1;

            if(num < 10)
            {
                result += num;
            }
            else
            {
                result += sumOfDigits(num);
            }
        }

        k = k-1;
        while(k--)
        {
            result = sumOfDigits(result);
        }

        return result;
    }
};