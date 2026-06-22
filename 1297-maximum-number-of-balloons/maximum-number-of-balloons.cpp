class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int,int>mp;
        for(int n : text){
            mp[n]++;
        }
        mp['l']/=2;
        mp['o']/=2;
        return min({mp['b'],mp['a'],mp['l'],mp['o'],mp['n']});
    }
};