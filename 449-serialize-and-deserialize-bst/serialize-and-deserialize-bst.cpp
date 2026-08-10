/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preorder(TreeNode* root,string &s){
        if(!root) return;
        s +=to_string(root->val)+" ";
        preorder(root->left,s);
        preorder(root->right,s);
    }
    TreeNode* build(vector<int>&nums,int &i ,int lower,int upper){
        if(i==nums.size()||nums[i]<lower||nums[i]>upper) return nullptr;
        int val=nums[i++];
        TreeNode* root=new TreeNode(val);
        root->left=build(nums,i,lower,val);
        root->right=build(nums,i,val,upper);
        return root;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preorder(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int>nums;
        stringstream ss(data);
        int x ;
        while(ss>>x){
            nums.push_back(x);
        }
        int i=0;
        return build(nums,i,INT_MIN,INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;