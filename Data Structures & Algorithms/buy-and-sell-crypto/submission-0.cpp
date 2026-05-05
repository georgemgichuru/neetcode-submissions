class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Here we use the sliding window technique
        int left = 0; // buy
        int right = 1; // sell
        int max_p = 0;
        while(right < prices.size()){
            // is this a profitable transaction ?
            if (prices[left] < prices[right]){
                int profit = prices[right] - prices[left];
                max_p = max(max_p, profit);
            }else{
                // we found a lower buying point
                left = right;
            }
            right++;
        }
        return max_p;
    }
};
