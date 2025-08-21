//try to color with two colors
bool dfs(vector<vector<int>>& graph,int node,vector<int>& vis,vector<int>&colors,int col){
        colors[node]=col;
        vis[node]=1;
        for(int nbr:graph[node]){
            if(colors[nbr]==-1 && dfs(graph,nbr,vis,colors,!col)==false) return false;
            else if(colors[nbr]==col) return false; 
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colors(n,-1);
        vector<int>vis(n,0);

        for(int i=0;i<n;i++){
            if(colors[i]==-1 && !dfs(graph,i,vis,colors,0)) return false;
        }
        return true;
    }
