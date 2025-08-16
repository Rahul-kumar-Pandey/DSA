 string serialize(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        string str="";
        if(root==NULL) return str;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL){
                str+="#,";
            }
            else{
                str+=to_string(node->val)+",";

                q.push(node->left);
                q.push(node->right);
            }
        }
        return str;
    }
//after serialization -> 1,2,3,#,#,4,5,#,#,#,#,
TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        stringstream s(data);
        string str;

        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            getline(s,str,',');
            if(str!="#"){
                TreeNode * newNode=new TreeNode(stoi(str));
                node->left=newNode;
                q.push(node->left);
            }

            getline(s,str,',');
            if(str!="#"){
                TreeNode* newNode=new TreeNode(stoi(str));
                node->right=newNode;
                q.push(node->right);
            }
        }

        return root;
    }
