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
//postorder Traversal(using 2 stack)
/*
1) take 2 stacks s1 and s2
2) s1.push(root)
3) in each iteration 
        a) take out top from s1 and push in s2
        b) push left then right in s1
4) at last s2 will contain postorder traversal.
*/


//postorder Traversal( using 1 stack)
while(curr!=null or !st.empty()){
        if(curr){
                st.push(curr);
                curr=curr->left;
        }
        else{
                temp=st.top()->right;
                if(temp==NULL){
                        temp=st.top();
                        st.pop();
                        cout<<temp->data<<endl; //print
                        //this handles right skewed tree
                        while(!st.empty() && temp==st.top()->right){ 
                                temp=st.top();
                                st.pop();
                                cout<<temp->data<<endl; //print 
                        }
                }
                else curr=temp;
        }
}
