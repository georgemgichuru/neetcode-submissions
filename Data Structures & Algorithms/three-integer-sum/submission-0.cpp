class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //    Approach
        /*
        Sort nums. For each index (i) as the first element.
        use two pointers (left = i + 1) and (right = n - 1) to find
        pairs. If (nums[left] + nums[right] == -nums[i]) -> Recorded triplet
        skip duplicates for (i), (left) and (right)
        */
        vector<vector<int>> result;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(nums[i] > 0 ) break;
            // skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0){
                    result.push_back({nums[i], nums[right], nums[left]});
                    while(left < right && nums[left] == nums[left + 1])left++;
                    while(left < right && nums[right] == nums[right - 1])right--;
                    left++;
                    right--;
                }else if(sum < 0){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return result;
    }
};
