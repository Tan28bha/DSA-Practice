class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        long long total = 0;

        int n = prices.size();
        int m = discounts.size();

        int k = min(n, m);

        // Work with numerator to avoid floating-point errors
        for (int i = 0; i < k; i++) {
            total += 1LL * prices[i] * (100 - discounts[i]);
        }

        // Remaining items receive no discount
        for (int i = k; i < n; i++) {
            total += 1LL * prices[i] * 100;
        }

        return total / 100.0;
    }
};