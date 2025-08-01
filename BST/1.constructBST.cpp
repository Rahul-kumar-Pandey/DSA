/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Approach1: without height balanced -----> make tree from array attach new node to the right of previous node (right skewed) BST 
Approach2:1) i,j,mid
          2) make node from mid
          3) node->left=solve(i,mid-1)
          4) node->right=solve(mid+1,j);
          5) return node;
*/
TreeNode* solve(vector<int>&nums,int i,int j){
        if(i>j) return NULL;
        int mid=(i+j)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=solve(nums,i,mid-1);
        node->right=solve(nums,mid+1,j);
        return node;
    }
---------------------------------------------------------------------------------------------------
  /*
  you have given preorder traversal of BST , construct a BST from it
  Approach1: get inorder traversal by sorting preorder
             now, from inorder and preorder we can construct BST.

  Approach2:  ***for root range is INT_MIN to INT_MAX;
              *** for left node range is INT_MIN to root.val-1
              *** for right node range is root.val+1,INT_MAX 
  */
  TreeNode *helper(vector<int>&preorder,int &pindex,int start,int end){
        //base case
        if(pindex>=preorder.size() or start>end) return NULL;
        //if range is not valid
        int val=preorder[pindex];
        if(val<start or val>end) return NULL;
        
        //build node of current element
        TreeNode *root=new TreeNode(val);
        pindex++;
        //set left
        root->left=helper(preorder,pindex,start,val-1);
        
        //set right
        root->right=helper(preorder,pindex,val+1,end);
        
        return root;
    }
  
