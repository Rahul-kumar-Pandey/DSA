/*
##LFUCache(int capacity) Initializes the object with the capacity of the data structure.
##int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
##void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. 
  When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item
. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
*/
/*
IDEA:
## to get least frequent use map<frequency,dll>
## in dll it is stored in LRU manner
## map<key,Node> to retreive fast key , value
*/
