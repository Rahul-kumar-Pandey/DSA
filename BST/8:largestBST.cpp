/*
Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).
*/
class MaxSum{
    public:
    bool bst; // current tree is bst
    int mini;  //min value in tree
    int maxi;  //max value in tree
    int maxsum; // maxsum in tree
    MaxSum(){
        bst=true;
        mini=INT_MAX;
        maxi=INT_MIN;
        maxsum=0;
    }
};
class Solution {
int ans;
public:
    MaxSum helper(TreeNode* root){
        if(root==NULL) return MaxSum(); //this, is a bst with value->(INT_MAX,INT_MIN);
        MaxSum p;
        MaxSum l=helper(root->left);
        MaxSum r =helper(root->right);

        //if sub-tree including this node is bst
        if(l.bst==true && r.bst==true && (l.maxi<root->val && root->val<r.mini)){
            p.bst=true;
            p.mini=min(l.mini,root->val);
            p.maxi=max(r.maxi,root->val);
            p.maxsum=l.maxsum+r.maxsum+root->val;
        }
        //curr tree is not a BST
        else{
            p.bst=false;
            p.maxsum=max(l.maxsum,r.maxsum);
        }
        ans=max(ans,p.maxsum);
        return p;
    }
    int maxSumBST(TreeNode* root) {
        ans=0;
        helper(root);
        return ans;
    }
};
