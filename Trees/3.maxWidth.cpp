/*
Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
LINK: https://leetcode.com/problems/maximum-width-of-binary-tree/description/

EG:                1
                  /  \
                3     2
               /       \
              5          9
              max width is on level 3 with {5 ,null,null,9} =4

Approach: assign indices on each nodes 
                    1(1)
                  /  \
                3(2)  2(3)
               /       \
              5(4)      9(7)
          then calculate ans=last-first+1
*/
 queue<pair<TreeNode*,long long>>q;
        if(root==NULL) return 0;
        q.push({root,1});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            int first=0,last=0;
            long long minid=q.front().second;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                long long id=q.front().second;
                id=id-minid;
                if(i==0){
                    first=q.front().second;
                }
                if(i==size-1){
                    last=q.front().second;
                }
                q.pop();
                if(node->left) q.push({node->left,2*id+1});
                if(node->right) q.push({node->right,2*id+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
