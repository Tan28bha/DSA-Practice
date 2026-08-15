class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int k = s1.length();

        if (k > s2.length()) {
            return false;
        }

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        for (char c : s1) {
            need[c - 'a']++;
        }

        int required = 0;

        for (int i = 0; i < 26; i++) {
            if (need[i] > 0) {
                required++;
            }
        }

        int have = 0;

        for (int i = 0; i < k; i++) {

            int idx = s2[i] - 'a';

            window[idx]++;

            if (window[idx] == need[idx]) {
                have++;
            }
        }

        if (have == required) {
            return true;
        }

        for (int right = k; right < s2.length(); right++) {

            // Add right
            int r = s2[right] - 'a';

            window[r]++;

            if (window[r] == need[r]) {
                have++;
            }

            // Remove left
            int left = right - k;
            int l = s2[left] - 'a';

            if (window[l] == need[l]) {
                have--;
            }

            window[l]--;

            if (have == required) {
                return true;
            }
        }

        return false;
    }
};