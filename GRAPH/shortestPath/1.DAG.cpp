/*
1. use topo sort in dfs
2. start with a source node
3. go all the neighbours ( we know neighbours will come after curr node so gonna give shortest path always).
4. can not be used for cyclic 
*/

void topoSort(int node,unordered_map<int,vector<pair<int,int>>>&mp,vector<int>&vis,stack<int>&st){
        vis[node]=1;
        
        for(auto it:mp[node]){
            if(!vis[it.first]){
                topoSort(it.first, mp, vis, st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<int>dist(V,1e9);
        vector<int>vis(V,0);
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto e:edges){
            mp[e[0]].push_back({e[1],e[2]});
        }
        stack<int>st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
              topoSort(i, mp, vis, st);
            }
         }
         dist[0]=0;
         while(!st.empty()){
             int node=st.top();
             //cout<<node<<" ";
             st.pop();
             for(auto it:mp[node]){
                 int v=it.first;
                 int w=it.second;
                 dist[v]=min(dist[v],dist[node]+w);
             }
             //cout<<endl;
         }
         for(int i=0;i<V;i++){
             if(dist[i]==1e9) dist[i]=-1;
         }
        return dist;
    }
