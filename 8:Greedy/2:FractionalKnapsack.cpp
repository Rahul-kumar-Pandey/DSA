/*
Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20.
so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 
*/


 bool static comparison(pair<int,int> a, pair<int,int> b) {
         return ((double)a.first/(double)a.second > (double)b.first/(double)b.second);
      }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<int,int>>vp;
        for(int i=0;i<val.size();i++){
            vp.push_back({val[i],wt[i]});
        }
      //1. sort on the basis of val/weight in dec order
        sort(vp.begin(),vp.end(),comparison);
        double ans=0.0;
        int i=0;

      //2. consume capacity
        while(capacity>0 && i<val.size()){
            auto e=vp[i];
            if(e.second<=capacity){
                ans+=e.first;
                capacity-=e.second;
            }
            else{
                ans+=((double)e.first/(double)e.second)*(double)capacity;
                capacity=0;
            }
            i++;
        }
        return ans;
    }
