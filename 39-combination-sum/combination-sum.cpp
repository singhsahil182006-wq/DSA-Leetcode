class Solution {
public:
    void solve(int idx,int target ,vector<int>&candidates,vector<int>&current ,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(current);
            return ;
        }
        if(idx==candidates.size()||target<0){
            return ;
        }
        if(candidates[idx]<=target){
            current.push_back(candidates[idx]);
            solve(idx,target-candidates[idx],candidates,current,ans);
            current.pop_back();
        }
        solve(idx+1,target,candidates,current ,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>current;
        solve(0,target,candidates,current,ans);
        return ans;
    }
};