/*
given a m*n grid containing o's and x's 
Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: the reason is surrounded by x's and it's not on boundary

TASK-> if o's are surrounded by x's then replace it with x
*/
---------------------------------------------------------------------
/*
ALGORITHM: dfs from each boundary o's and mark connected o's as visited
           once done , see if current cell is 'o' and not visited then it is a surrounded region;
*/
