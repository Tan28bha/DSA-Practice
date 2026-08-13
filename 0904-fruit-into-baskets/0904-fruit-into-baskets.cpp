class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> freq;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < fruits.size(); right++) {

            // Add current fruit
            freq[fruits[right]]++;

            // More than 2 fruit types
            while (freq.size() > 2) {

                freq[fruits[left]]--;

                if (freq[fruits[left]] == 0) {
                    freq.erase(fruits[left]);
                }

                left++;
            }

            // Valid window
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};