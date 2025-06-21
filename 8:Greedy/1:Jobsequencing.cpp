/*
You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, 
and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.
*/
/*
Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
*/
public:
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
pair < int, int > JobScheduling(Job arr[], int n) {
  //1. sort according to profit in dec order
      sort(arr, arr + n, comparison);
      int maxi = arr[0].dead;
      for (int i = 1; i < n; i++) {
         maxi = max(maxi, arr[i].dead);
      }
  //2. maximum deadline ke size ka array bnao 
      int slot[maxi + 1];
      for (int i = 0; i <= maxi; i++)
         slot[i] = -1;
      int countJobs = 0, jobProfit = 0;
      for (int i = 0; i < n; i++) {
        //3. try to delay to place job till deadline (deadline ---------> day 1 tak aao)
         for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               countJobs++;
               jobProfit += arr[i].profit;
               break;
            }
         }
      }
      return make_pair(countJobs, jobProfit);
   }

// NOTE: tc(O(n*d)) +O(nlong(N))
// can be optimized inner loop using DSU
