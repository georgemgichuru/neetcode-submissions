class Solution {
public:
int lengthOfLongestSubstring(string s) {
        // Use an unordered_set to track characters in the current window
        std::unordered_set<char> charSet;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            // If the character is already in the set, it's a duplicate
            // Move the left pointer to shrink the window until the duplicate is removed
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            
            // Add the current character and update the maximum length
            charSet.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
