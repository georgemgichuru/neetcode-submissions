class Solution {
public:
    bool isPalindrome(string s) {
        // Use 2 pointers if a character is not alphanumeric ignore and move
        // to the next character
        // compare the two pointers while moving
        int left = 0;
        int right = s.length() - 1;
        while (left < right){
            // move left character forward is character is not alphanumeric
            if(!isalnum(s[right])){
                right--;
            }
            else if(!isalnum(s[left])){
                left++;
            }else{
                // Both are alphanumeric so compare them
                if(tolower(s[left]) != tolower(s[right])){
                    return false;
                }
                left++;
                right--;
            }
        }
    return true;
    }
};
