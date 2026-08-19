class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        // Prefix sum
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> dq;

        int ans = n + 1;

        for (int j = 0; j <= n; j++) {

            // 1. Check whether we have a valid subarray
            while (!dq.empty() &&
                   prefix[j] - prefix[dq.front()] >= k) {

                ans = min(ans, j - dq.front());
                dq.pop_front();
            }

            // 2. Remove useless prefix sums
            while (!dq.empty() &&
                   prefix[dq.back()] >= prefix[j]) {

                dq.pop_back();
            }

            // 3. Add current prefix index
            dq.push_back(j);
        }

        return ans == n + 1 ? -1 : ans;
    }
};