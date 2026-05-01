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
        string encoded = "";
        for(string& i : strs){
            encoded += to_string(i.size()) + '%' + i;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '%'){
                j++;
            }
            // extract the length of the string
            int length = stoi(s.substr(i, j-i));
            i = j + 1;
            result.push_back(s.substr(i, length));
            i += length;
        }
        return result;
    }
};
