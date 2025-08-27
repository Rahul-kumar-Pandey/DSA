/*
used to find shortest path from each node to other node
cycle ke liye v kaam krta hai
*/
// we can also use priorityQueue(minheap) but that is a bit costly
//TC:O( E log(V) )
 vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int,vector<pair<int,int>>>graph;
        
        for(auto e:edges){
            graph[e[0]].push_back({e[1],e[2]});
        }
        set<pair<int,int>> st; 
        st.insert({0,src});
        vector<int>ans(V,INT_MAX);
        ans[src]=0;
        while(!st.empty()){
            auto it = *(st.begin()); 
            int node = it.second; 
            st.erase(it);
            
            for(auto v:graph[node]){
                int nbr=v.first;
                int wt=v.second;
                if(ans[node]+wt<ans[nbr]){
                    ans[nbr]=ans[node]+wt;
                    st.insert({ans[nbr],nbr});
                }
            }
        }
        return ans;
    }
