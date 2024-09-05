class Solution {
public:
    vector<int> solveEquation(int coefficient, int rhs) {
    vector<int> result(coefficient, 1);  // Initialize the array with size equal to the coefficient and elements as 1
    int sum = coefficient;               // Initially, the sum is all 1's
    int remaining = rhs - sum;           // Remaining sum to distribute

    if (rhs < coefficient || rhs > 6 * coefficient) {
        // If the rhs is smaller than coefficient or larger than 6 * coefficient, it is impossible to meet the condition
        return {};
    }

    // Distribute the remaining value by incrementing the elements
    for (int i = 0; remaining > 0 && i < coefficient; i++) {
        int increment = min(remaining, 6 - result[i]);  // Increment but do not exceed 6
        result[i] += increment;
        remaining -= increment;
    }

    return result;
}
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();       
        int sum = accumulate(rolls.begin(), rolls.end(), 0);

        int temp = mean * (n+m);

        return solveEquation(n, temp-sum);
    }
};