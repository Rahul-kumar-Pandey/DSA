Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

----------------------------------
  /*
  Intuition :use Heap
  1) use two heaps minheap,maxheap
  2) maxheap.size=minheap.size+1;
  3) <1 2 5 9> <10 21 99>  : ans=maxheap.top()
  4) <1 2 5><10 21 99>     : ans=maxheap.top()+minheap.top()/2.0;
  5) while adding one element in maxheap break the required median order like add 100 in 4th list will break order.
      then move top element to minheap to maintain order.
  */

   priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    MedianFinder() {
    }
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top()); 
        maxHeap.pop();
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
