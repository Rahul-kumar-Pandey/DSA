/*
You are given two integer arrays a[] and b[] of equal size. A sum combination is formed by adding one element from a[] and
one from b[], using each index pair (i, j) at most once. Return the top k maximum sum combinations, sorted in non-increasing order.

Input: a[] = [1, 4, 2, 3], b[] = [2, 5, 1, 6], k = 3
Output: [10, 9, 9]
Explanation: The top 3 maximum possible sums are : 4 + 6 = 10, 3 + 6 = 9, and 4 + 5 = 9
*/
/*Approach:
  1) sort both array in dec order , now a[0]+b[0] is max sum
  2) the next potential largest sums lie at positions (i+1, j) and (i, j+1) because of sorted order
  3) exploring these candidates using a max heap and tracking visited index pairs will give answer
*/
vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        vector<int>res;
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>s;
        
        pq.push({a[0]+b[0],{0,0}});
        s.insert({0,0});
        
        while(res.size()<k){
            auto top=pq.top();
            pq.pop();
            res.push_back(top.first);
            int i=top.second.first;
            int j=top.second.second;
            if(i+1<a.size() && s.find({i+1,j})==s.end()){
                pq.push({a[i+1]+b[j],{i+1,j}});
                s.insert({i+1,j});
            }
            if(j+1<b.size() && s.find({i,j+1})==s.end()){
                pq.push({a[i]+b[j+1],{i,j+1}});
                s.insert({i,j+1});
            }
        }
        return res;
    }
