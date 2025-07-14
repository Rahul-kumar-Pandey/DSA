//Iterative inorder
/*
1) go all the way to left and push on to stack
2) when null print top of stack
3) go in right of top element
*/
vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* temp=root;
        stack<TreeNode*>st;
        vector<int>ans;
        while(!st.empty() || temp){
            while(temp){
                st.push(temp);
                temp=temp->left;
            }
            if(temp==NULL){
                temp=st.top()->right;
                ans.push_back(st.top()->val);
                st.pop();
            }
        }
        return ans;
    }
