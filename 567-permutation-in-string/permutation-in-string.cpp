class Solution {
public:
    bool checkInclusion(string s1, string s2){
        int n1=s1.size(),n2=s2.size();
        vector<int> need(26,0) , window(26,0);
        for(char ch : s1) need[ch-'a']++;
        for(int right=0;right<n2;right++){
            window[s2[right]-'a']++;
            if(right>=n1){
                window[s2[right-n1]-'a']--;
            }
            if(right>=n1-1&& window==need) return true;
        }
        return false;
    }
};