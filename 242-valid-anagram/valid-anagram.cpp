class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26,0);
        if(s.size()!=t.size()){
            return false;
        }
        for(int c : s) freq[c-'a']++;
        for(int c : t) freq[c-'a']--;
        for(int x : freq){
            if(x!=0){
                return false;
            }
        }
        return true;
    }
};