class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
// use prefix and suffix arrays
// the result of each index i is given by prefix[i] * suffix[i]
    vector<int> output(nums.size(), 1);
    // calculate the prefix
    // store all the products of elements to the left of i in output[i]
    int prefix = 1;
    for (int i = 0;i < nums.size(); i++){
        output[i] = prefix;
        prefix *= nums[i];
    }
    // do the same but now for the suffix
    int suffix = 1;
    for (int i = (nums.size()-1); i >= 0;i--){
        output[i] *= suffix;
        suffix *= nums[i];
    }
    return output;
    }
};
