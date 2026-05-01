class Solution {
public:
// we can tryins using an efficient way of figuring out where a certain#
// string starts and this can be done by ensuring that each satrt of
// each word starts with a special character and the length of the string
// 1. The length of the string
// 2. The special character 
// 3. after the special character we take all the characters of
//    lets say n elements are in the string
    string encode(vector<string>& strs) {
        // First we place the characters of strs into encoded
        string encoded = "";
        for(string& i : strs){
            // here we are adding the length of the string
            // the special character and the characters themselves
            encoded += to_string(i.size()) + '%' + i;
        }
        // return the encoded character
        return encoded;
    }

    vector<string> decode(string s) {
        // here we have the vector string result for the final answer
        vector<string> result;
        int i = 0;
        // remember s is our encoded string
        // so if i is less than the length of our encoded string
        while(i < s.size()){
            int j = i;
            // while the current character is not our special char
            // move to the next character until we find it
            while(s[j] != '%'){
                j++;
            }
            // extract the length of the string after getting the
            // special character
            // j-i because the special character comes after the length
            int length = stoi(s.substr(i, j-i));
            // we do i = j + 1 to take us to the string
            i = j + 1;
            // so now we add all the characters from the start of the string to end
            result.push_back(s.substr(i, length));
            // and then we move to the next string for decoding
            i += length;
        }
        return result;
    }
};
