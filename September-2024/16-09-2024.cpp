class Solution {
public:
    static bool cmp(string time1, string time2)
    {
        int hour1 = stoi(time1.substr(0, 2));
        int hour2 = stoi(time2.substr(0, 2));

        if(hour1 != hour2)
        {
            return hour1 < hour2;
        }
        else
        {
            int min1 = stoi(time1.substr(3, 2));
            int min2 = stoi(time2.substr(3, 2));

            return min1 < min2;
        }
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end(), cmp);
        int ans = INT_MAX;
        int n = timePoints.size();

        for(int i = 0; i<n-1; i++)
        {
            string time1 = timePoints[i];
            string time2 = timePoints[i+1];

            int hour1 = stoi(time1.substr(0, 2));
            int hour2 = stoi(time2.substr(0, 2));
            int min1 = stoi(time1.substr(3, 2));
            int min2 = stoi(time2.substr(3, 2));

            int minute = (hour2-hour1) * 60;

            if(min1 < min2)
            {
                //add minutes
                minute += min2 - min1;
            }
            else
            {
                //subtract minutes
                minute -= min1 - min2;
            }

            ans = min(ans, minute);
        }

        string time1 = timePoints[n-1];
        string time2 = timePoints[0];
        int min1 = stoi(time1.substr(3, 2));
        int min2 = stoi(time2.substr(3, 2));

        int temp1 = 24 - stoi(time1.substr(0, 2));
        temp1 += (stoi(time2.substr(0, 2)) - 1 ) + 1;

        int minutes = temp1 * 60;
        if(min1 < min2)
        {
                //add minutes
                minutes += min2 - min1;
        }
        else
        {
                //subtract minutes
                minutes -= min1 - min2;
        }


        return min(ans, minutes);
    }
};