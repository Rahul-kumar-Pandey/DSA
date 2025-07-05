/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
*/
/*
Key observation:
Suppose we have a decreasing sequence followed by a greater number
For example [5, 4, 3, 2, 1, 6] then the greater number 6 is the next greater element for all previous numbers in the sequence

We use a stack to keep a decreasing sub-sequence, whenever we see a number x greater than stack.peek() we pop all elements less 
than x and for all the popped ones, their next greater element is x
*/
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>res;
        unordered_map<int,int>mp;
        for(auto n:nums2){
            while(!st.empty() && st.top()<n){
                mp[st.top()]=n;
                st.pop();
            }
            st.push(n);
        }
        for(int n:nums1){
            if(mp[n]){
                res.push_back(mp[n]);
            }
            else res.push_back(-1);
        }
        return res;
    }
