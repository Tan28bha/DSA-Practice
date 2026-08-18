class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        vector<int> freq(k, 0);

        // Prefix sum 0 has remainder 0
        freq[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int x : nums) {

            prefixSum += x;

            int remainder = prefixSum % k;

            // Handle negative remainder
            if (remainder < 0) {
                remainder += k;
            }

            // Previous prefix sums with same remainder
            count += freq[remainder];

            // Store current remainder
            freq[remainder]++;
        }

        return count;
    }
};