/*
@ solution - Check the array once with a seen and not seen
we can use an unordered_set which only picks unique characters 
*/

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen = {};
        for (int num : nums){
            if (!seen.count(num)){
                seen.insert(num);
                continue;
            }else {
                return true;
            }
        }
        return false;
    }
};