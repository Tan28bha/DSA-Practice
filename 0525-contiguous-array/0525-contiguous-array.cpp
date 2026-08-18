class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> firstIndex;

        // Prefix sum 0 before array starts
        firstIndex[0] = -1;

        int prefixSum = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {

            // 0 -> -1, 1 -> +1
            prefixSum += (nums[i] == 0 ? -1 : 1);

            if (firstIndex.count(prefixSum)) {

                // Same prefix sum => sum between them is 0
                ans = max(ans, i - firstIndex[prefixSum]);

            } else {

                // Keep earliest occurrence
                firstIndex[prefixSum] = i;
            }
        }

        return ans;
    }
};