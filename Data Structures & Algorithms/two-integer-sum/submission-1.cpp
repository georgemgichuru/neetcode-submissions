class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // so we can try using a hashmap such that we loop through
        // once subtracting the items we check if they exist in the 
        // hashmap
        unordered_map<int, int> mapx;
        int res;
        for (int i=0;i<sizeof(nums);i++){
            res = (target - nums[i]);
            if(mapx.count(res)){
                return {mapx[res], i};
            }
            mapx[nums[i]] = i;
        }
        return {};
    }
};
