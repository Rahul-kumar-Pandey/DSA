/*check if a tree is valid BST*/
bool helper(TreeNode *root,long left,long right){
        if(root==NULL) return true;
        if(left>=root->val or root->val>=right){
            return false;
        }
        return helper(root->left,left,root->val) and helper(root->right,root->val,right);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN, LONG_MAX);
    }
