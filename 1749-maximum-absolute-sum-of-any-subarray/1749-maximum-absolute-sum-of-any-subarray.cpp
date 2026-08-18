class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int maxEnding = 0;
        int minEnding = 0;
        int ans = 0;

        for (int x : nums) {

            maxEnding = max(x, maxEnding + x);
            minEnding = min(x, minEnding + x);

            ans = max({
                ans,
                maxEnding,
                -minEnding
            });
        }

        return ans;
    }
};