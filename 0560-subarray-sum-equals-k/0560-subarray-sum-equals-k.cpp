class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();

        int sum=0;
        unordered_map<int,int> freq;
        int result=0;
        freq[0]=1;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            int guess =sum-k;
            int f =freq[guess];
            result+=f ;
            freq[sum]++;
        }
        return result;

        
    }
};