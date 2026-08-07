class Solution {
public:
    string longestPalindrome(string s){
        if(s.empty()) return "";
        string t="^";
        for(char c : s){
            t+="#";
            t+=c;
        }
        t+="#$";
        int n=t.size();
        vector<int> p(n,0);
        int center=0;
        int right=0;
        int maxlen=0;
        int maxcenter=0;
        for(int i=1;i<n-1;i++){
            int mirror=2*center-i;
            if(i<right){
                p[i]=min(right-i,p[mirror]);
            }
            while(t[i+(1+p[i])]==t[i-(1+p[i])]){
                p[i]++;
            }
            if(i+p[i]>right){
                center=i;
                right=i+p[i];
            }
            if(p[i]>maxlen){
                maxlen=p[i];
                maxcenter=i;
            }
        }
        int start=(maxcenter - maxlen)/2;
        return s.substr(start,maxlen);
    }
};