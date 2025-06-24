/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

edge case: [1,1,2] 
*/
/*
The pairs which are on the left of the single element, will have the first element in an even position and the second element at an odd position. 
All the pairs which are on the right side of the single element will have the first position at an odd position and the second element at an even position.
Use this fact to decide whether to go to the left side of the array or the right side.
*/

//code:
int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1,n=nums.size();
        int ans=0;
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-2]!=nums[n-1]) return nums[n-1]; //to handle [1,1,2]
        while(l<=r){
            int mid=(l+r)/2;
            if(mid-1>=0 and mid+1<n and nums[mid-1]!=nums[mid] and nums[mid+1]!=nums[mid]) return nums[mid];
            if(mid%2==0){
                if(mid+1<n and nums[mid]==nums[mid+1]) l=mid+1;
                else if(mid-1>=0 and nums[mid]==nums[mid-1]) r=mid-1;
            }
            else{
                if(mid-1>=0 and nums[mid]==nums[mid-1]) l=mid+1;
                else if(mid+1<n and nums[mid]==nums[mid+1]) r=mid-1;
            }
        }
        return ans;
    }
