class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string>dict(wordDict.begin(),wordDict.end());

        vector<int>dp(n+1,false);
        dp[0]=true;
        for(int i=0;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&dict.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};