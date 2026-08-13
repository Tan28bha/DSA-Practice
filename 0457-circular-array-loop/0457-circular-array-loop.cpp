class Solution {
public:

    int nextIndex(int i, vector<int>& nums) {

        int n = nums.size();

        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for (int start = 0; start < n; start++) {

            if (nums[start] == 0)
                continue;

            bool forward = nums[start] > 0;

            int slow = start;
            int fast = start;

            while (true) {

                // Slow
                int slowNext = nextIndex(slow, nums);

                if (nums[slow] == 0 ||
                    (nums[slow] > 0) != forward ||
                    slowNext == slow)
                    break;

                // Fast - first jump
                int fastNext = nextIndex(fast, nums);

                if (nums[fast] == 0 ||
                    (nums[fast] > 0) != forward ||
                    fastNext == fast)
                    break;

                // Fast - second jump
                int fastNextNext = nextIndex(fastNext, nums);

                if (nums[fastNext] == 0 ||
                    (nums[fastNext] > 0) != forward ||
                    fastNextNext == fastNext)
                    break;

                slow = slowNext;
                fast = fastNextNext;

                if (slow == fast)
                    return true;
            }

            // Mark the path as visited
            int current = start;

            while (nums[current] != 0 &&
                   (nums[current] > 0) == forward) {

                int next = nextIndex(current, nums);

                nums[current] = 0;

                current = next;
            }
        }

        return false;
    }
};