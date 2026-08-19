class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        int n = intervals.size();

        for (int i = 1; i < n; i++) {

            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            // Overlapping
            if (end1 >= start2) {
                end1 = max(end1, end2);
            }
            // Non-overlapping
            else {
                res.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
        }

        // Push the last interval
        res.push_back({start1, end1});

        return res;
    }
};