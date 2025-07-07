/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.
*/
/*
BRUTE FORCE: for each i find next smaller in right and next smaller in left 
BETTER: precompute NSE and PSE for each elements(using stack)
        then use same concept for each index
        
*/
