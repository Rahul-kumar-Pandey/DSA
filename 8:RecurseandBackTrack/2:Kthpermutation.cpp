/*
Input: n = 4, k = 9
Output: "2314"
*/
//Approach1: generate all permuation(using recursion) and sort the array . now return the k-1 th vector as answer.

//Approach2: Mathematical
            /*
              //step1: 1,{2,3,4} ----> total 6 permutation(0th to 5th )
                       2.{1,3,4} ----> ""                 (6th - 11th)
                       3,{1,2,4} ----> ""                 (12th - 17th)
                       4,{1,2,3} ----> ""                 (18th - 23th)
              //step2: solve for smaller problem:
            */
string getPermutation(int n, int k) {
      int fact = 1;
      vector < int > numbers;
      for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
      }
      numbers.push_back(n);
      string ans = "";
      k = k - 1;
      while (true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0) {
          break;
        }

        k = k % fact;
        fact = fact / numbers.size();
      }
      return ans;
    }
