class Solution {
public:

    long long mergeSort(vector<long long>& prefix,
                        int left,
                        int right,
                        long long lower,
                        long long upper) {

        // Base case
        if (right - left <= 1) {
            return 0;
        }

        int mid = left + (right - left) / 2;

        long long count = 0;

        // Count valid pairs in left half
        count += mergeSort(prefix, left, mid, lower, upper);

        // Count valid pairs in right half
        count += mergeSort(prefix, mid, right, lower, upper);

        // Count cross-half pairs
        int low = mid;
        int high = mid;

        for (int i = left; i < mid; i++) {

            while (low < right &&
                   prefix[low] - prefix[i] < lower) {
                low++;
            }

            while (high < right &&
                   prefix[high] - prefix[i] <= upper) {
                high++;
            }

            count += high - low;
        }

        // Merge the two sorted halves
        vector<long long> temp;
        temp.reserve(right - left);

        int i = left;
        int j = mid;

        while (i < mid && j < right) {
            if (prefix[i] <= prefix[j]) {
                temp.push_back(prefix[i++]);
            } else {
                temp.push_back(prefix[j++]);
            }
        }

        while (i < mid) {
            temp.push_back(prefix[i++]);
        }

        while (j < right) {
            temp.push_back(prefix[j++]);
        }

        for (int k = 0; k < temp.size(); k++) {
            prefix[left + k] = temp[k];
        }

        return count;
    }

    int countRangeSum(vector<int>& nums,
                      int lower,
                      int upper) {

        int n = nums.size();

        vector<long long> prefix(n + 1);

        prefix[0] = 0;

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return mergeSort(
            prefix,
            0,
            n + 1,
            lower,
            upper
        );
    }
};