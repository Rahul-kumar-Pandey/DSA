//Bottom view of binary tree
vector<int> bottomView(Node* root){
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            mpp[line] = node->data;
            if(node->left != NULL){
                q.push({node->left, line - 1});
            }
            if(node->right != NULL){
                q.push({node->right, line + 1});
            }
        }
        for(auto it : mpp){
            ans.push_back(it.second);
        }       
        return ans;
    }

//Top view of Binary Tree
/*
1) we can use similar method as for previous problem
2) but this will cost nlogn because of map,
3) so we will use unordered_map to reduce complexity to O(N)
*/
if (root ==  nullptr) {
        return {};
    }
    queue<pair<Node *, int>> q;
    unordered_map<int, int> mp;
    int mn = INT_MAX;
    q.push({root, 0});
    while (!q.empty()) { 
        temp = q.front().first;
        int d = q.front().second;
        mn = min(mn, d); //this will store left bound
        q.pop();
        if (mp.find(d) == mp.end()) {
            mp[d] = temp->data;
        }
        if (temp->left) {
            q.push({temp->left, d - 1});
        }
        if (temp->right) {
            q.push({temp->right, d + 1});
        }
    }
    vector<int> ans(mp.size());
    for (auto it = mp.begin(); it != mp.end(); it++) {
        ans[it->first - mn] = (it->second);        //we are shifting index 
    }
    return ans;
