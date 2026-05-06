class Solution {
public:
    int characterReplacement(string s, int k) {
        // use sliding window
        vector<int> count(26, 0);
        int left = 0;
        int max_freq = 0;
        int max_length = 0;

        for (int right = 0; right < s.length(); ++right) {
            // Update frequency of the current character
            count[s[right] - 'A']++;
            
            // Keep track of the most frequent character in the current window
            max_freq = max(max_freq, count[s[right] - 'A']);

            // Current window size is (right - left + 1)
            // If replacements needed (size - max_freq) > k, shrink window
            while ((right - left + 1) - max_freq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            // Update the result
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};
