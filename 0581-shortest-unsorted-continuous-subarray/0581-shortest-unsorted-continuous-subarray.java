class Solution {
    public int findUnsortedSubarray(int[] nums) {

        int n = nums.length;

        int left = -1;
        int right = -1;

        // Find right boundary
        int maxSeen = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {

            if (nums[i] < maxSeen) {
                right = i;
            } else {
                maxSeen = nums[i];
            }
        }

        // Find left boundary
        int minSeen = Integer.MAX_VALUE;

        for (int i = n - 1; i >= 0; i--) {

            if (nums[i] > minSeen) {
                left = i;
            } else {
                minSeen = nums[i];
            }
        }

        // Already sorted
        if (right == -1) {
            return 0;
        }

        return right - left + 1;
    }
}