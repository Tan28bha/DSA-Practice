class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add current character
            int index = s[right] - 'A';
            freq[index]++;

            // Maximum frequency seen in the window
            maxFreq = max(maxFreq, freq[index]);

            // Number of characters we need to replace
            // to make the whole window the same
            while ((right - left + 1) - maxFreq > k) {

                freq[s[left] - 'A']--;
                left++;
            }

            // Current window is valid
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};