class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;

        for (char c: s) mapS[c]++;
        for (char c: t) mapT[c]++;

        return mapS == mapT;
    }
};
