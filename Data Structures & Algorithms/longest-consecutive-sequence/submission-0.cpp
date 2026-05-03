class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // step 1: Put everything into a hash set for O(1) lookups
        // This also handles duplicates automatically
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;
        for(int num : numSet){
            // step 2: Check if 'num' is the start of a sequence
            // We only start counting if (num - 1) doesn't exist
            if(numSet.find(num - 1) == numSet.end()){
                int currentNum = num;
                int currentStreak = 1;

                // step 3 : keep checking for n + 1
                while (numSet.find(currentNum + 1) != numSet.end()){
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        
        }
        return longestStreak;
    }

};
