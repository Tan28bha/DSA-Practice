class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left = 0;
        int zeros = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Add current element
            if (nums[right] == 0)
                zeros++;

            // Too many zeros
            while (zeros > k) {

                if (nums[left] == 0)
                    zeros--;

                left++;
            }

            // Valid window
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};