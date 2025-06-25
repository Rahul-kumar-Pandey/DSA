/*
Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
*/
//INTITUTION: exactly same as Median wala 
int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n1=a.size(),n2=b.size();
        if(n1>n2) return kthElement(b,a,k);
        k--;
        int lo=max(0,(k-n2)),hi=min(n1,k);  //Yha catch hai bas (isko dekho)
        while(lo<=hi){
            int mid1=(lo+hi)/2;
            int mid2=(k-mid1);
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            
            if(mid1-1>=0) l1=a[mid1-1];
            if(mid2-1>=0) l2=b[mid2-1];
            if (mid1 < n1) r1 = a[mid1];
            if (mid2 < n2) r2 = b[mid2];
            
            if(l1<=r2 and l2<=r1){
                return min(r1,r2);
            }
            else if(l1>r2) hi=mid1-1;
            else if(l2>r1) lo=mid1+1;
        }
        return 0;
    }
