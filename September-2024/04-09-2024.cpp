class Solution {
public:
    // Custom hash function for std::pair<int, int>
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& pair) const {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Maps to handle direction changes and coordinate updates
        unordered_map<char, pair<char, char>> direction = {
            {'N', {'W', 'E'}},
            {'E', {'N', 'S'}},
            {'S', {'E', 'W'}},
            {'W', {'S', 'N'}}
        };

        unordered_map<char, pair<int, int>> move = {
            {'N', {-1, 0}},
            {'E', {0, 1}},
            {'S', {1, 0}},
            {'W', {0, -1}}
        };

        // Store obstacles in a set for quick lookup
        std::unordered_set<std::pair<int, int>, pair_hash> obstaclesSet;
        for (const auto& obstacle : obstacles) {
            obstaclesSet.insert({obstacle[0], obstacle[1]});
        }

        char currentDirection = 'E';
        int row = 0, col = 0, maxDistance = 0;

        // Iterate through each command
        for (const int& command : commands) {
            if (command > 0) {
                // Move the robot command steps in the current direction
                for (int step = 0; step < command; ++step) {
                    int newRow = row + move[currentDirection].first;
                    int newCol = col + move[currentDirection].second;

                    if (obstaclesSet.find({newRow, newCol}) == obstaclesSet.end()) {
                        row = newRow;
                        col = newCol;
                    } else {
                        break;  // Stop moving if an obstacle is encountered
                    }
                }
            } else {
                // Change direction based on the command (-2 or -1)
                currentDirection = (command == -2) ? direction[currentDirection].first : direction[currentDirection].second;
            }

            // Calculate the Euclidean distance (squared)
            int distanceSquared = row * row + col * col;
            maxDistance = max(maxDistance, distanceSquared);
        }

        return maxDistance;
    }
};
