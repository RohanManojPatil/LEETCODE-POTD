
*******************************LEETCODE POTD*************************
*	               T.C = O(nlogn)							                * 
*	               							                        * 
*	               S.C = O(n)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int freeChairNumber = 0;  // Start chair numbering from 0
        set<pair<int, pair<int, int>>> st;
        int n = times.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        set<int> freeSlots;

        // Insert all times into a set sorted by start time
        for (int i = 0; i < n; i++) {
            int startTime = times[i][0];
            int endTime = times[i][1];
            st.insert({startTime, {endTime, i}});
        }

        // Process each friend's entry
        for (auto entry : st) {
            int startTime = entry.first;
            int endTime = entry.second.first;
            int friendNumber = entry.second.second;

            // Free up chairs whose end time is before or at the current start time
            while (!pq.empty() && pq.top().first <= startTime) {
                freeSlots.insert(pq.top().second.second);  // Insert chair into free slots
                pq.pop();  // Pop the element from the priority queue
            }

            // Assign a chair to the current friend
            int currentChairNumber;
            if (freeSlots.empty()) {
                currentChairNumber = freeChairNumber++;  // No free slots, use a new chair
            } else {
                currentChairNumber = *(freeSlots.begin());  // Take the lowest free slot
                freeSlots.erase(freeSlots.begin());  // Remove the assigned chair from free slots
            }

            // Add this friend's end time and chair number to the priority queue
            pq.push({endTime, {startTime, currentChairNumber}});

            // If this is the target friend, return the chair number
            if (friendNumber == targetFriend) {
                return currentChairNumber;
            }
        }

        return -1;  // This line should never be reached if input is valid
    }
};
