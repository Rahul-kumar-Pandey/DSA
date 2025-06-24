/*
Given a row-wise sorted matrix where the number of rows and columns is always odd, find the median of the matrix.
Input: mat = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
Output: 5
*/
/* Optimal Approcah:(Binary Search)
  1)lo=min(mat),hi=max(mat) , then find mid . 
  2)for mid how many elements are smaller than it and store answer;
  Time Complexity: O(n log m * log(maxVal – minVal))
  Auxiliary Space: O(1)
*/
int upperBound(vector<int> &arr, int x, int n) {
    int lo=0,hi=arr.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]<=x){
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return lo;
}

int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += upperBound(matrix[i], x, n);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;

    //point low and high to right elements:
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}
