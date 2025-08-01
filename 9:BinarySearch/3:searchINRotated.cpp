
/*
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. 
Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/
int search(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        //if mid points the target
        if (arr[mid] == k) return mid;
        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}
