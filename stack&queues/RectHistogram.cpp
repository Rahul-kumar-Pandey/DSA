/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.
*/
/*
BRUTE FORCE: for each i find next smaller in right and next smaller in left 
BETTER: precompute NSE and PSE for each elements(using stack)
        then use same concept for each index
        ans=height[i]*(nse[i]-pse[i]-1)

OPTIMAL:
        1) we will traverse from 0 to n-1
        2) store elements in stack monotically increasing
        3) whenever some i : st.top()>height[i] => for st.top() i is nse and element before stack top is pse . woohhaaa
        Test case:3,2,10,11,5,10,6,3
*/
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==1) return heights[0];
        
        int ans=0;
        stack<int>st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int x=st.top();
                int nse=i;
                int pse=-1;
                st.pop();
                if(!st.empty()){
                    pse=st.top();
                }
                ans=max(ans,heights[x]*(nse-pse-1));
            }
            st.push(i);
        }
        //when height array is increasing 2,4,6,9 then .
        while(!st.empty()){
                int x=st.top();
                int nse=heights.size();
                int pse=-1;
                st.pop();
                if(!st.empty()){
                    pse=st.top();
                }
                ans=max(ans,heights[x]*(nse-pse-1));
        }
        return ans;
    }
