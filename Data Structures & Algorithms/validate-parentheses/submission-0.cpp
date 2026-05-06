class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // Map closing brackets to their corresponding opening brackets
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            // If it's a closing bracket
            if (bracketMap.find(c) != bracketMap.end()) {
                // Check if stack is empty or top doesn't match
                if (st.empty() || st.top() != bracketMap[c]) {
                    return false;
                }
                st.pop();
            } else {
                // It's an opening bracket, push to stack
                st.push(c);
            }
        }

        // Valid if no unmatched opening brackets remain
        return st.empty();
    }
};
