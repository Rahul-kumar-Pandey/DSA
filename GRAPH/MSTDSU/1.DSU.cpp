//why we need a Disjoint Set data structure using the below question?
/*
Question: Given two components of an undirected graph , whether node 1 and node 5 are in the same component or not.

DFS/BFS-> O(V+E)
DSU -> constant time

##find() -> finds parent of a node
##union() -> does union of two nodes
*/
union(int a,int b){
  a=find(a);
  b=find(b);
  if(a!=b){
    if(size[a]<size[b]){
      parent[a]=b;
      size[b]+=size[a];
    }
    else{
      parent[b]=a;
      size[a]+=size[b];
    }
  }
}
find(int v){
  if(v==parent[v]) return v;
  return parent[v]=find(parent[v]); //doing path compression
}
