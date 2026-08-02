class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA=0,sumB=0;
        for(int i : aliceSizes){
            sumA+=i;
        }
        for(int i : bobSizes){
            sumB+=i;
        }
        int diff=(sumA-sumB)/2;
        unordered_set<int> st(bobSizes.begin(),bobSizes.end());
        for(int a : aliceSizes){
            int b=a-diff;
            if(st.count(b)){
                return{a,b};
            }
        }
        return {};
    }
};