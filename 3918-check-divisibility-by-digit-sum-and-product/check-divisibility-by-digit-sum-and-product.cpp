class Solution {
public:
    bool checkDivisibility(int n) {
        int x=n;
        int sum=0 , pro=1;
        while(x>0){
            int dig = x%10;
            sum+=dig;
            pro*=dig;
            x/=10;
        }
        return n%(sum+pro)==0;        
    }
};