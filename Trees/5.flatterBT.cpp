/*
Given the root of a binary tree, flatten the tree into a "linked list":
//The "linked list" should be in the same order as a pre-order traversal of the binary tree.
//  1 (aise dikhega tree) 
     \
       2
         \
           3
            \
             4
*/
-------------------------------------
Approach1:
/*
1) do preorder traversal and create a new node 
2) tc(O(N)) sc:O(N)
*/
Approach2:
 TreeNode* prev=NULL;
    void solve(TreeNode* root){
        if(root==NULL) return ;

        solve(root->right);
        solve(root->left);

        root->right=prev;
        root->left=NULL;
        prev=root;
    }

Approach3:(moris), TC:O(N) sc:O(1)
  
