/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the 
very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max of sliding window.
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

Approach1: use map (map stores in increasing order of key) , so for each window i can find answer
Approach2: (using deque)
          1) store in decreasing in deque , so dq.front() will always given answer
          2) we will store indexes why??( 1, 3, 1, 2, 0, 5) , because dq.front()( which is index) <=i-k to remove fron deque
*/


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque <int>dq;
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for(int i=k;i<nums.size();i++){
            //special to handle remove from front
            if(!dq.empty() && dq.front()<=i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();

            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
