class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        
        int maxSum = INT_MIN, curMax = 0;
        int minSum = INT_MAX, curMin = 0;
        
        for (int num : nums) {
            totalSum += num;
            
            // Kadane (max)
            curMax = max(num, curMax + num);
            maxSum = max(maxSum, curMax);
            
            // Reverse Kadane (min)
            curMin = min(num, curMin + num);
            minSum = min(minSum, curMin);
        }
        
        // Edge case: all elements negative
        if (maxSum < 0) return maxSum;
        
        return max(maxSum, totalSum - minSum);
    }
};