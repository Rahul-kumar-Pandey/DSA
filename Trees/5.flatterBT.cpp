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
  /*
  1)as linked list order should be of preorder traversal of binary tree
  2) root->(leftsubtree)->(rightsubtree)
  */
     curr=root;
     while(curr!=null){
          if(curr->left!=NULL){
               prev=curr->left;
               //find rightmost node of root's left
               while(prev->right){
                    prev=prev->right;
               }
               prev->right=curr->right;
               curr->right=curr->left;
          }
          curr=curr->right;
     }
