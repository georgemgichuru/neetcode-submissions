class Solution {
public:
        string minWindow(string s, string t) {
            if (s.empty() || t.empty()) return "";

            // Frequency map for characters in t
            vector<int> target_map(128, 0);
            for (char c : t) target_map[c]++;

            int left = 0, right = 0;
            int required = t.length();
            int min_len = INT_MAX;
            int start_idx = 0;

            while (right < s.length()) {
                // If current char is needed, decrease required count
                if (target_map[s[right]] > 0) {
                    required--;
                }
                // Decrease frequency in map (can go negative for extra chars)
                target_map[s[right]]--;
                right++;

                // When window is valid
                while (required == 0) {
                    // Update minimum window
                    if (right - left < min_len) {
                        min_len = right - left;
                        start_idx = left;
                    }

                    // Try to shrink from left
                    target_map[s[left]]++;
                    // If the char we just removed was essential, increase required
                    if (target_map[s[left]] > 0) {
                        required++;
                    }
                    left++;
                }
            }

            return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
        }
};
