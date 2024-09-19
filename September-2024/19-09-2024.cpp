class Solution {
public:
    vector<int> solve(string str) {
        vector<int> result;

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '+' || str[i] == '-' || str[i] == '*') {
                // Split the string into two parts: left and right
                vector<int> left = solve(str.substr(0, i));
                vector<int> right = solve(str.substr(i + 1));

                // Combine results from left and right
                for (int l : left) {
                    for (int r : right) {
                        if (str[i] == '+') {
                            result.push_back(l + r);
                        } else if (str[i] == '-') {
                            result.push_back(l - r);
                        } else if (str[i] == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }

        // If no operators were found, the result is just the integer
        if (result.empty()) {
            result.push_back(stoi(str));  // Convert string to integer
        }

        return result;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};
