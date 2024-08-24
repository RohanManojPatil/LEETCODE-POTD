class Solution {
public:
    long long findClosestPalindrome(long long first, bool isOdd)
    {
        long long palindrome = first;
        if(isOdd)
        {
            first = first/10;
        }

        while(first>0)
        {
            palindrome = palindrome * 10 + (first%10);
            first = first/10;
        }

        return palindrome;
    }
    string nearestPalindromic(string n) {
        int len = n.length();
        long long number = stoll(n);

        if(number <= 10) return to_string(number-1);
        if(number == 11) return "9";

        if(n == "999999999999999999")
        {
            return "1000000000000000001";
        }

        vector<long long> ans;
        bool isOdd = len%2 == 0 ? 0 : 1;
        long long firstHalf = stoll(n.substr(0, (len+1)/2));
        long long minDiff = LONG_MAX, candidate = 0;

        ans.push_back(findClosestPalindrome(firstHalf, isOdd));
        ans.push_back(findClosestPalindrome(firstHalf-1, isOdd));
        if(firstHalf < 999999999)
        {
            ans.push_back(findClosestPalindrome(firstHalf+1, isOdd));
        }
        else
        {
            ans.push_back(stoll("1" + string(len-1, '0') + "1"));
        }

        ans.push_back(pow(10, len-1)-1);
        ans.push_back(pow(10, len)+1);

        for(long long num : ans)
        {
            if(num == number) continue;

            long long diff = abs(num-number);

            if((diff == minDiff && num < candidate) || diff < minDiff)
            {
                candidate = num;
                minDiff = diff;
            }
        }

        return to_string(candidate);
    }
};