/*
 your task is to find the greatest value node of the BST which is smaller than or equal to x.
*/
int floor(Node* root, int x) {
        if(root==NULL) return -1;
        
        int ans=-1;
        while(root){
            if(root->data==x){
                ans=root->data;
                break;
            }
            if(x<root->data){
                root=root->left;
            }
            else{
                ans=root->data;
                root=root->right;
            }
        }
        return ans;
    }
/*
for ceil thoda ulti kr do 
## ceil means immediately  greater than or equal to target.
*/
