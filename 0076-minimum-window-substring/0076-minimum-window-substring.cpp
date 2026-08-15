class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> count(128, 0);

        // Store required frequencies
        for (char c : t) {
            count[c]++;
        }

        int missing = t.length();

        int left = 0;

        int start = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < s.length(); right++) {

            char c = s[right];

            // If c was still required
            if (count[c] > 0) {
                missing--;
            }

            // Add c to the window
            count[c]--;

            // Window is valid
            while (missing == 0) {

                // Update minimum
                int len = right - left + 1;

                if (len < minLen) {
                    minLen = len;
                    start = left;
                }

                // Remove left character
                char leftChar = s[left];

                count[leftChar]++;

                // If it became positive,
                // we are missing this character again
                if (count[leftChar] > 0) {
                    missing++;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};