/*
find topological order
REMEMBER: Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v,
vertex u comes before v in the ordering.
*/
//ALGORITHM1: kahn's algo
vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>ans;
        vector<int>indeg(V,0);
        unordered_map<int,vector<int>>mp;
        
        for(auto e:edges){
            indeg[e[1]]++;
            mp[e[0]].push_back(e[1]);
        }
        queue<int>q;
        
        for(int i=0;i<V;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto nbr:mp[node]){
                indeg[nbr]--;
                if(indeg[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        return ans;
    }

//ALGORITHM2: dfs
void dfs(int node, int vis[], stack<int> &st,
	         vector<int> adj[]) {
		vis[node] = 1;
		for (auto it : adj[node]) {
			if (!vis[it]) dfs(it, vis, st, adj);
		}
		st.push(node);
	}
  vector<int> topoSort(int V, vector<int> adj[])
	{
		int vis[V] = {0};
		stack<int> st;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, vis, st, adj);
			}
		}

		vector<int> ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
