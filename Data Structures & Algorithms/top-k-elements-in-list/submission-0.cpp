class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> buckets(n+1);
        unordered_map<int, int> frequency;
        for(int i : nums){
            frequency[i]++;
        }
        // use bucket sort algorithm now
        // create buckets 
        for (auto const& [value, freq]: frequency){
            buckets[freq].push_back(value);
        }
        // iterate backwards from the top buckets to find the top 
        // frequency k
        vector<int> ans;
        for(int i = n; i >= 0 && ans.size() < k; i--){
            for(int num : buckets[i]){
                ans.push_back(num);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};
