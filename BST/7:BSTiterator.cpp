/*
implement BST iterator over inorder traversal of BST
BSTIterator(TreeNode root)->init BST Iterator
boolean hasNext()-> return true if it has next
int next()-> print next and move to next
*/
//Approach:
## we are considering inorder Traversal so ,
## push all element in left => top will be next () 
## after processing top , we need to push top->right;

class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* top=st.top();
        st.pop();
        pushAll(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    void pushAll(TreeNode* root){
        TreeNode* node=root;
        while(node){
            st.push(node);
            node=node->left;
        }
    }
};
