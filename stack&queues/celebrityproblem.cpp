/*
A celebrity is a person who is known to all but does not know anyone at a party
A square matrix mat[][] (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 
it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist,
return -1.

Input: mat[][] = [[1, 1, 0], [0, 1, 0], [0, 1, 1]]
Output: 1
*/

//optimal Approach
int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        int top=0,bottom=n-1;
        while(top<bottom){
            //top knows bottom so top can't be a celebs
            if(mat[top][bottom]==1){
                top++;
            }
              //bottom knows top so bottom can't be a celebs
            else if(mat[bottom][top]==1){
                bottom--;
            }
              //no body knows , (so both can be answer)
            else{
                //neighter top , nor bottom knows each other so it can't be answer
                top++;
                bottom--;
            }
        }
        if(top==bottom){
          //just checking if top is a valid answer 
          //means top does'nt know anyone but every body knows top
            for(int i=0;i<n;i++){
                if(i==top) continue;
                if(mat[top][i]==0 and mat[i][top]==1)
                {
                    
                }else return -1;
            }
            return top;
        }
        return -1;
    }
