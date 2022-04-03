# `STACKs and QUEUEs`
stack using array
```java
public class MyStack {
   private int maxSize;
   private long[] stackArray;
   private int top;
   
   public MyStack(int s) {
      maxSize = s;
      stackArray = new long[maxSize];
      top = -1;
   }
   public void push(long j) {
      stackArray[++top] = j;
   }
   public long pop() {
      return stackArray[top--];
   }
   public long peek() {
      return stackArray[top];
   }
   public boolean isEmpty() {
      return (top == -1);
   }
   public boolean isFull() {
      return (top == maxSize - 1);
   }
   ```
   ---
   queue using array
   ```cpp
   class queue
{
    int *arr;       // array to store queue elements
    int capacity;   // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int count;      // current size of the queue
 
public:
    queue(int size = SIZE);     // constructor
    ~queue();                   // destructor
 
    void dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};
 
// Constructor to initialize a queue
queue::queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}
 
// Destructor to free memory allocated to the queue
queue::~queue() {
    delete[] arr;
}
 
// Utility function to dequeue the front element
void queue::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Removing " << arr[front] << endl;
 
    front = (front + 1) % capacity;
    count--;
}
 
// Utility function to add an item to the queue
void queue::enqueue(int item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Inserting " << item << endl;
 
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}
int queue::peek()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}
 
// Utility function to return the size of the queue
int queue::size() {
    return count;
}
 
// Utility function to check if the queue is empty or not
bool queue::isEmpty() {
    return (size() == 0);
}
 
// Utility function to check if the queue is full or not
bool queue::isFull() {
    return (size() == capacity);
}
```
---
## delete middle el of stack
![](img\deletemiddleleofstack.png)

---
# k stacks
```cpp
class newStack{ 
    int *arr;   
    int *top;   
    int *next;  
    
    int n, k; 
    int free; 
public: 
    
    newStack(int k, int n); 
  
    bool isFull(){  
        return(free == -1);  
    } 
  
    void push(int item, int sn); 
  
    int pop(int sn); 
  
    bool isEmpty(int sn){  
        return (top[sn] == -1); 
    } 
}; 
  
newStack::newStack(int k1, int n1){ 
    
    k = k1, n = n1; 
    arr = new int[n]; 
    top = new int[k]; 
    next = new int[n]; 
  
    for(int i = 0; i < k; i++) 
        top[i] = -1; 
  
    free = 0; 
    for(int i=0; i<n-1; i++) 
        next[i] = i+1; 
    next[n-1] = -1; 
} 
  
void newStack::push(int item, int sn){ 
    
    if(isFull()){ 
        cout << "\nStack Overflow\n"; 
        return; 
    } 
  
    int i = free;     
  
    free = next[i]; 
  
    next[i] = top[sn]; 
    top[sn] = i; 
  
    arr[i] = item; 
} 
  
int newStack::pop(int sn){ 
    
    if(isEmpty(sn)){ 
         cout<<"\nStack Underflow\n"; 
         return INT_MAX; 
    } 
  
    int i = top[sn]; 
  
    top[sn] = next[i];  
  
    next[i] = free; 
    free = i; 
  
    return arr[i]; 
} 
```
![](img\kstackex.png)
![](img\kstacks.jpg)

---
## Baalanced paranthesis checker
```cpp
bool isBalanced(string str){ 
    stack<char> s; 
    char x; 
  
    for(int i=0; i<str.length(); i++){ 
        if(str[i]=='('||str[i]=='['||str[i]=='{'){ 
            s.push(str[i]); 
            continue; 
        }
  
        if(s.empty()) 
           return false; 
  
        switch(str[i]){ 
            case ')': 
      
                x = s.top(); 
                s.pop(); 
                if(x=='{' || x=='[') 
                    return false; 
                break; 
      
            case '}': 
      
                x = s.top(); 
                s.pop(); 
                if(x=='(' || x=='[') 
                    return false; 
                break; 
      
            case ']': 
      
                x = s.top(); 
                s.pop(); 
                if(x =='(' || x == '{') 
                    return false; 
                break; 
        } 
    } 
  
    return (s.empty()); 
} 
```
![](img\balancedparanthesis.png)

---
## Next greatest element
![](img\nextgreatest2.png)
```cpp
void findNGEs(int arr[],int N)
{
  cout << "The next Greater element of "<<arr[N-1] <<" is -1\n";
  
  stack<int> S;
  S.push(arr[N-1]);
  
  for(int i=N-2;i>=0;i--)
  {
    
    while(!S.empty() and arr[i] > S.top()) //If array element is greater than top element then keep i popping
    {
      S.pop();
    }  
    
    if(S.empty()) //if stack is empty means no greater element
      {
        cout<<"The next greater element of "<<arr[i]<<" is -1\n";
        
      }
    else  //if stack not empty then top element is the next greater element
      {
        cout<<"The next greater element of "<<arr[i]<<" is " << S.top()<<"\n";
      }
    S.push(arr[i]);
  }
  
}
```
![](img\nextgreatest.jpg)

---
## celebrity problem
celbrity should be known by everyone nut should not know anyone
```cpp
int FindCelebId(int a,int n)
{
    int A = 0,B = n - 1; 
    //Finding celebity
    while(A < B)
    {
        if(a[A][B])
        {
            A++;
        }
        else
        {
            B--;
        }
    }
    //Check celebrity conditions
    //If A is celebrity
    //All members should know A
    //A should not now anyone
    for (int i = 0; i < n; i++)
    {
       if ((i != A) && (a[A][i] || !a[i][A]))
       {
            return -1;
       }
    }
 
    return A;
}
```
![](img\celebrity.png)

---
## insert at bottom of stack 
- same as middle but here we go untill stack empty
```cpp
static void insert_at_bottom(char x){

    if(st.isEmpty())
        st.push(x);

    else{
        /* All items are held in Function Call Stack until we
           reach end of the stack. When the stack becomes
           empty, the st.size() becomes 0, the
           above if part is executed and the item is inserted
           at the bottom */

        char a = st.peek();
        st.pop();
        insert_at_bottom(x);

        //push all the items held in Function Call Stack
        //once the item is inserted at the bottom
        st.push(a);
    }
}
```
## reverse a stack using recursion
```cpp
char insert_at_bottom(char x)
{
 
    if(st.size() == 0)
    st.push(x);
 
    else
    {
         
        // All items are held in Function Call
        // Stack until we reach end of the stack
        // When the stack becomes empty, the
        // st.size() becomes 0, the above if
        // part is executed and the item is
        // inserted at the bottom
             
        char a = st.top();
        st.pop();
        insert_at_bottom(x);
 
        // push allthe items held in
        // Function Call Stack
        // once the item is inserted
        // at the bottom
        st.push(a);
    }
}
 
// Below is the function that
// reverses the given stack using
// insert_at_bottom()
char reverse()
{
    if(st.size()>0)
    {
         
        // Hold all items in Function
        // Call Stack until we
        // reach end of the stack
        char x = st.top();
        st.pop();
        reverse();
         
        // Insert all the items held
        // in Function Call Stack
        // one by one from the bottom
        // to top. Every item is
        // inserted at the bottom
        insert_at_bottom(x);
    }
}
```
![](img\stackreverse.png)

---
# sort a stack using recursion
```cpp
void sortedInsert(struct stack** s, int x)
{
    if (isEmpty(*s) or x > top(*s)) {
        push(s, x);
        return;
    }
    int temp = pop(s);
    sortedInsert(s, x);
    push(s, temp);
}
void sortStack(struct stack** s)
{
    if (!isEmpty(*s)) {
        int x = pop(s);
        sortStack(s);
        sortedInsert(s, x);
    }
}
```
![](img\sortstack.jpg)

---
## merge overlapping intervals
Given a set of time intervals in any order, merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals. Let the intervals be represented as pairs of integers for simplicity. 
For example, let the given set of intervals be {{1,3}, {2,4}, {5,7}, {6,8}}. The intervals {1,3} and {2,4} overlap with each other, so they should be merged and become {1, 4}. Similarly, {5, 7} and {6, 8} should be merged and become {5, 8}
```cpp
void mergeIntervals(Interval arr[], int n)
{
    // Test if the given set has at least one interval
    if (n <= 0)
        return;
 
    // Create an empty stack of intervals
    stack<Interval> s;
 
    // sort the intervals in increasing order of start time
    sort(arr, arr+n, compareInterval);
 
    // push the first interval to stack
    s.push(arr[0]);
 
    // Start from the next interval and merge if necessary
    for (int i = 1 ; i < n; i++)
    {
        // get interval from stack top
        Interval top = s.top();
 
        // if current interval is not overlapping with stack top,
        // push it to the stack
        if (top.end < arr[i].start)
            s.push(arr[i]);
 
        // Otherwise update the ending time of top if ending of current
        // interval is more
        else if (top.end < arr[i].end)
        {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }
```
![](img\mergeoverlap.png)

---
##  max valid substring
Given a string consisting of opening and closing parenthesis, find the length of the longest valid parenthesis substring. \
ex: (())(  -  4    )(())()  - 6

```cpp
	int n = str.length();
	// Create a stack and push -1 as
	// initial index to it.
	stack<int> stk;
	stk.push(-1);
	int result = 0;

	// Traverse all characters of given string
	for (int i = 0; i < n; i++)
	{
		// If opening bracket, push index of it
		if (str[i] == '(')
			stk.push(i);
		// If closing bracket, i.e.,str[i] = ')'
		else
		{
			// Pop the previous opening
			// bracket's index
			stk.pop();
			// Check if this length formed with base of
			// current valid substring is more than max
			// so far
			if (!stk.empty())
				result = max(result, i - stk.top());
			// If stack is empty. push current index as
			// base for next valid substring (if any)
			else
				stk.push(i);
		}
	}

```
![](img\maxvalsubs.png)

---
## check redundancy
Given a string of balanced expression, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. Print ‘Yes’ if redundant, else ‘No’.
```
Input: 
((a+b))
(a+(b)/c)
(a+b*(c-d))
Output: 
Yes
Yes
No
```
```cpp
bool checkRedundancy(string A) {
    stack<char> st;
    for(char ch : A)
    {
        if(ch == ')')
        {
            int cnt = 0;
            while(!st.empty() and st.top() != '(')
            {
                cnt++;
                st.pop();
            }
            st.pop();
            if(cnt < 2) return 1;
        }
        else st.push(ch);
    }
 
    return 0;
}
```
![](img\redundancycheck.png)

---
LRU cache
```cpp
class LRUCache {
    // store keys of cache
    list<int> dq;
 
    // store references of key in cache
    unordered_map<int, list<int>::iterator> ma;
    int csize; // maximum capacity of cache
 
public:
    LRUCache(int);
    void refer(int);
    void display();
};
 
// Declare the size
LRUCache::LRUCache(int n)
{
    csize = n;
}
 
// Refers key x with in the LRU cache
void LRUCache::refer(int x)
{
    // not present in cache
    if (ma.find(x) == ma.end()) {
        // cache is full
        if (dq.size() == csize) {
            // delete least recently used element
            int last = dq.back();
 
            // Pops the last element
            dq.pop_back();
 
            // Erase the last
            ma.erase(last);
        }
    }
 
    // present in cache
    else
        dq.erase(ma[x]);
 
    // update reference
    dq.push_front(x);
    ma[x] = dq.begin();
}
 
// Function to display contents of cache
void LRUCache::display()
{
 
    // Iterate in the deque and print
    // all the elements in it
    for (auto it = dq.begin(); it != dq.end();
         it++)
        cout << (*it) << " ";
 
    cout << endl;
}
```
- if item present already then erase it from dequeue
and add it to front and update its position
- if item not present and queue is not full then just add it to front and pos=start of dequeue
- if item not present and queue is full then remove fromm back of queue and insert element to front  of queue

---
# reversing Queue
- either do recusion after poping then insert popped element to queue after recursive call
- use stack

---
# revese first k ele of queue
```cpp
void reverseQueueFirstKElements(
    int k, queue<int>& Queue)
{
    if (Queue.empty() == true
        || k > Queue.size())
        return;
    if (k <= 0)
        return;
 
    stack<int> Stack;
 
    /* Push the first K elements
       into a Stack*/
    for (int i = 0; i < k; i++) {
        Stack.push(Queue.front());
        Queue.pop();
    }
 
    /* Enqueue the contents of stack
       at the back of the queue*/
    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
 
    /* Remove the remaining elements and
       enqueue them at the end of the Queue*/
    for (int i = 0; i < Queue.size() - k; i++) {
        Queue.push(Queue.front());
        Queue.pop();
    }
```
---
## inter leave first and second half of stack
```
Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

Only a stack can be used as an auxiliary space.
Input :  1 2 3 4
Output : 1 3 2 4

Input : 11 12 13 14 15 16 17 18 19 20
Output : 11 16 12 17 13 18 14 19 15 20
```
```cpp
void interLeaveQueue(queue<int>& q)
{
    // To check the even number of elements
    if (q.size() % 2 != 0)
        cout << "Input even number of integers." << endl;
  
    // Initialize an empty stack of int type
    stack<int> s;
    int halfSize = q.size() / 2;
  
    // Push first half elements into the stack
    // queue:16 17 18 19 20, stack: 15(T) 14 13 12 11
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }
  
    // enqueue back the stack elements
    // queue: 16 17 18 19 20 15 14 13 12 11
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
  
    // dequeue the first half elements of queue
    // and enqueue them back
    // queue: 15 14 13 12 11 16 17 18 19 20
    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }
  
    // Again push the first half elements into the stack
    // queue: 16 17 18 19 20, stack: 11(T) 12 13 14 15
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }
  
    // interleave the elements of queue and stack
    // queue: 11 16 12 17 13 18 14 19 15 20
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}
```
![](img\interleavestack.png)

---
## Circular Tour
```
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.
```
```
Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
```
```cpp
int printTour(petrolPump arr[], int n)
{
    int start;
 
    for (int i = 0; i < n; i++) {
        // Identify the first petrol pump from where we
        // might get a full circular tour
        if (arr[i].petrol >= arr[i].distance) {
            start = i;
            break;
        }
    }
 
    // To store the excess petrol
    int curr_petrol = 0;
 
    int i;
 
    for (i = start; i < n;) {
 
        curr_petrol += (arr[i].petrol - arr[i].distance);
 
        // If at any point remaining petrol is less than 0,
        // it means that we cannot start our journey from
        // current start
        if (curr_petrol < 0) {
 
            // We move to the next petrol pump
            i++;
 
            // We try to identify the next petrol pump from
            // where we might get a full circular tour
            for (; i < n; i++) {
                if (arr[i].petrol >= arr[i].distance) {
 
                    start = i;
 
                    // Reset rem_petrol
                    curr_petrol = 0;
 
                    break;
                }
            }
        }
 
        else {
            // Move to the next petrolpump if curr_petrol is
            // >= 0
            i++;
        }
    }
 
    // If remaining petrol is less than 0 while we reach the
    // first petrol pump, it means no circular tour is
    // possible
    if (curr_petrol < 0) {
        return -1;
    }
 
    for (int j = 0; j < start; j++) {
 
        curr_petrol += (arr[j].petrol - arr[j].distance);
 
        // If remaining petrol is less than 0 at any point
        // before we reach initial start, it means no
        // circular tour is possible
        if (curr_petrol < 0) {
            return -1;
        }
    }
 
    // If we have successfully reached intial_start, it
    // means can get a circular tour from final_start, hence
    // return it
    return start;
}
```
![](img\circulartour.png)

---
# Minimum time required to rot all oranges
```
Given a matrix of dimension m*n where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:  

0: Empty cell
1: Cells have fresh oranges
2: Cells have rotten oranges
```

```cpp
int rotOranges(int arr[][C])
{
    // Create a queue of cells  // ele : x,y
    queue<ele> Q;
    ele temp;
    int ans = 0;
 
    // Store all the cells having rotten orange in first time frame
    for (int i=0; i<R; i++)
    {
       for (int j=0; j<C; j++)
       {
            if (arr[i][j] == 2)
            {
                temp.x = i;
                temp.y = j;
                Q.push(temp);
            }
        }
    }
 
    // Delimiter
    temp.x = -1;
    temp.y = -1;
    Q.push(temp);
 
    // Process the grid while there are rotten oranges in the Queue
    while (!Q.empty())
    {
        //flag placed so that if infected in this cycle we can increment once then stop
        bool flag = false;
        while (!isdelim(Q.front())) //checkif q.front.x,y=-1
        {
            temp = Q.front();
            if (isvalid(temp.x+1, temp.y) && arr[temp.x+1][temp.y] == 1)
            {
                // if this is the first orange to get rotten, increase
                // count and set the flag.
                if (!flag) ans++, flag = true;
 
                // Make the orange rotten
                arr[temp.x+1][temp.y] = 2;
 
                // push the adjacent orange to Queue
                temp.x++;
                Q.push(temp);
 
                temp.x--; // Move back to current cell
            }
 
            if (isvalid(temp.x-1, temp.y) && arr[temp.x-1][temp.y] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x-1][temp.y] = 2;
                temp.x--;
                Q.push(temp); // push this cell to Queue
                temp.x++;
            }
 
            // Check top adjacent cell that if it can be rotten
            if (isvalid(temp.x, temp.y+1) && arr[temp.x][temp.y+1] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x][temp.y+1] = 2;
                temp.y++;
                Q.push(temp); // Push this cell to Queue
                temp.y--;
            }
 
            // Check bottom adjacent cell if it can be rotten
            if (isvalid(temp.x, temp.y-1) && arr[temp.x][temp.y-1] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x][temp.y-1] = 2;
                temp.y--;
                Q.push(temp); // push this cell to Queue
            }
 
            Q.pop();
        }
 
        // Pop the delimiter
        Q.pop();
 
        // If oranges were rotten in current frame than separate the
        // rotten oranges using delimiter for the next frame for processing.
        if (!Q.empty()) {
            temp.x = -1;
            temp.y = -1;
            Q.push(temp);
        }
    }
 
    // Return -1 if all arranges could not rot, otherwise return ans.
    return (checkall(arr))? -1: ans;
}
```
![](img\rottenoranges.png)

---
# distance of nearest cell having 1
```
Given a binary grid. Find the distance of nearest 1 in the grid for each cell.
The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column number of the nearest cell having value 1.
```
```
Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
```
```cpp
    bool issafe(int i,int j,const vector<vector<int>> &grid,const vector<vector<int>> &ans){
        if(i<grid.size() && j<grid[0].size() && i>=0 && j>=0 && grid[i][j]==0){
            return true;
        }
        return false;
    }
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	   	vector<vector<int>> ans;
	   	for(int i=0;i<grid.size();i++){
	   	    vector<int> v;
	   	    v.assign(grid[0].size(),INT_MAX);
	   	    ans.push_back(v);
	   	}
	   	queue<pair<int,int>> q;
	   	for(int i=0;i<grid.size();i++){
	   	    for(int j=0;j<grid[i].size();j++){
	   	        if(grid[i][j]==1){
	   	            q.push({i,j});
	   	            ans[i][j] = 0;
	   	        }
	   	    }
	   	}
	   	while(!q.empty()){
	   	    int i = q.front().first;
	   	    int j = q.front().second;
	   	    q.pop();
	   	    if(issafe(i+1,j,grid,ans) && ans[i+1][j] > ans[i][j]+1){
	   	        q.push({i+1,j});
	   	        ans[i+1][j] = ans[i][j]+1;
	   	    }
	   	    if(issafe(i-1,j,grid,ans)&& ans[i-1][j] > ans[i][j]+1){
	   	        q.push({i-1,j});
	   	        ans[i-1][j] = ans[i][j]+1;
	   	    }
	   	    if(issafe(i,j+1,grid,ans)&& ans[i][j+1] > ans[i][j]+1){
	   	        q.push({i,j+1});
	   	        ans[i][j+1] = ans[i][j]+1;
	   	    }
	   	    if(issafe(i,j-1,grid,ans)&& ans[i][j-1] > ans[i][j]+1){
	   	        q.push({i,j-1});
	   	        ans[i][j-1] = ans[i][j]+1;
	   	    }
	   	}
	   	return ans;
	}
};
```
![](img\mindistacefromone.png)

---
## first neg in window
```
Given an array and a positive integer k, find the first negative integer for each window(contiguous subarray) of size k. If a window does not contain a negative integer, then print 0 for that window.
```
```cpp
	int firstNegativeIndex = 0;
	int firstNegativeElement;
	
	
	for(int i = k - 1; i < n; i++)
	{
	
		// skip out of window and positive elements
		while((firstNegativeIndex < i ) &&
			(firstNegativeIndex <= i - k ||
			arr[firstNegativeIndex] > 0))
		{
			firstNegativeIndex ++;
		}
		
		// check if a negative element is found, otherwise use 0
		if(arr[firstNegativeIndex] < 0)
		{
			firstNegativeElement = arr[firstNegativeIndex];
		}
		else
		{
			firstNegativeElement = 0;
		}
		cout<<firstNegativeElement << " ";
	}
	
}
```
![](img\firstnegwind.png)

---
# max min sum window
```
Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.
```
```cpp
int SumOfKsubArray(int arr[] , int n , int k)
{
    int sum = 0;  // Initialize result
    deque< int > S(k), G(k);
 
    // Process first window of size K
    int i = 0;
    for (i = 0; i < k; i++)
    {
        // Remove all previous greater elements
        // that are useless.
        while ( (!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); // Remove from rear
 
        // Remove all previous smaller that are elements
        // are useless.
        while ( (!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back(); // Remove from rear
 
        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }
 
    // Process rest of the Array elements
    for (  ; i < n; i++ )
    {
        // Element at the front of the deque 'G' & 'S'
        // is the largest and smallest
        // element of previous window respectively
        sum += arr[S.front()] + arr[G.front()];
 
        // Remove all elements which are out of this
        // window
        while ( !S.empty() && S.front() <= i - k)
            S.pop_front();
        while ( !G.empty() && G.front() <= i - k)
            G.pop_front();
 
        // remove all previous greater element that are
        // useless
        while ( (!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); // Remove from rear
 
        // remove all previous smaller that are elements
        // are useless
        while ( (!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back();
        G.push_back(i);
        S.push_back(i);
    }
 
    // Sum of minimum and maximum element of last window
    sum += arr[S.front()] + arr[G.front()];
 
    return sum;
}
```
![](img\maxminsumwindows.png)

---
## Minimum sum of squares of character counts in a given string after removing k characters
```
Input :  str = abccc, K = 1
Output :  6
We remove c to get the value as 1^2 + 1^2 + 2^2
```
```cpp
int minStringValue(string str, int k)
{
    int l = str.length(); // find length of string
 
    // if K is greater than length of string
    // so reduced string will become 0
    if (k >= l)
        return 0;
 
    // Else find Frequency of each character and
    // store in an array
    int frequency[MAX_CHAR] = { 0 };
    for (int i = 0; i < l; i++)
        frequency[str[i] - 'a']++;
 
    // Push each char frequency into a priority_queue
    priority_queue<int> q;
    for (int i = 0; i < MAX_CHAR; i++)
        q.push(frequency[i]);
 
    // Removal of K characters
    while (k--) {
        // Get top element in priority_queue,
        // remove it. Decrement by 1 and again
        // push into priority_queue
        int temp = q.top();
        q.pop();
        temp = temp - 1;
        q.push(temp);
    }
 
    // After removal of K characters find sum
    // of squares of string Value
    int result = 0; // Initialize result
    while (!q.empty()) {
        int temp = q.top();
        result += temp * temp;
        q.pop();
    }
 
    return result;
}
```
- make any array of freq of each character
- then put it in a priority queue
- k times take the top ele of pq then decrement it and put it back as for 4,2,2 it become 3,2,2 and again it becomes 2,2,2
- then take sum of everything in pq

---
# next smallest
```cpp
void findNGEs(int arr[],int N)
{
  cout << "The next Greater element of "<<arr[N-1] <<" is -1\n";
  
  stack<int> S;
  S.push(arr[N-1]);
  
  for(int i=N-2;i>=0;i--)
  {
    
    while(!S.empty() and arr[i] <= S.top()) //If array element is greater than top element then keep i popping
    {
      S.pop();
    }  
    
    if(S.empty()) //if stack is empty means no smallest element
      {
        cout<<"The next greater element of "<<arr[i]<<" is -1\n";
        
      }
    else  //if stack not empty then top element is the next smallest element
      {
        cout<<"The next greater element of "<<arr[i]<<" is " << S.top()<<"\n";
      }
    S.push(arr[i]);
  }
```
![](img\nextsmallest.png)

---
# first non repeating char in a string
```cpp
		string FirstNonRepeating(string A){
		    int freq[26]={0};
		    queue<char> q;
		    string s="";
		    for(int i=0;i<A.size();i++)
		    {
		        freq[A[i]-'a']++;
		        while(!q.empty()&&freq[q.front()-'a']>1){
		            q.pop();
		        }
		        
		        if(freq[A[i]-'a']==1)
		        q.push(A[i]);
		        if(!q.empty())
		           s=s+q.front();
		        else
		           s=s+"#";
		      
		    }
            return s;
		    
		}
```