//sort the items and then check if they are there if they are there we append them
// @brief: Proposed solution 
// hash_map = {abc : {"bca", "cba"};
//            ghb : {"hbg", "ghb"}
// }
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        for (string i: strs){
            string x = i;
            sort(x.begin(), x.end());
            hashmap[x].push_back(i);
        }
        vector<vector<string>> answer;// will carry our answer
        for(auto& d: hashmap){
            answer.push_back(d.second);
        }
    return answer;
    }
};
