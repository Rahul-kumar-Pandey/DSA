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

//Preorder Traversal
/*
1) root left right
*/
 vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int>ans;
        TreeNode * curr=root;
        stack<TreeNode*>st;
        st.push(curr);
        while(!st.empty()){
            curr=st.top();
            st.pop();
            ans.push_back(curr->val);
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
        }
        return ans;
    }
//postorder Traversal
