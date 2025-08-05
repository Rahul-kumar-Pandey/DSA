/*
 return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
*/
void solve(TreeNode* root,int k,int &cnt,int &ans){
        if(root==NULL) return ;

        solve(root->left,k,cnt,ans);
        cnt++;
        if(cnt==k) ans=root->val;
        solve(root->right,k,cnt,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1,cnt=0;
        solve(root,k,cnt,ans);
        return ans;
    }
