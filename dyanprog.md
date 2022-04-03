# Dynamic Programing
# fibonacci
## tabulation
```c++
fib[0]=0,fib[1]=1;
for(i=2;i<=n;i++)
fib[i]=fib[i-1]+fib[i-2];
```
## Recursive
```c++
int fibo(int n)
{
    if(n==1||n==0)
    return 1;
    return fibo(n-1)+fibo(n-2);
}
```
longest common subsequence               
```c++
void lcs(string s1,string s2)    //=>abcde,ace      =>3
{
    int l1=s1.length();
    int l2=s2.length();
    string newst;
    int table[l1+1][l2+1];
    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
            if(i==0||j==0)               
            {
                table[i][j]=0; 
                continue;
            }
            if(s1[i-1]==s2[j-1])
            {
                table[i][j]=table[i-1][j-1]+1;
                newst.push_back(s1[i-1]); 
            }
            else{
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }

            
        }
        
    }for(int i=0;i<newst.length();i++)
        cout<<newst[i];
}
int t[10][10];

int lcsrec(string s1,string s2,int i,int j)
{
    if(i==0||j==0)return 0;
    if(t[i][j]!=-1)return t[i][j];
    if(s1[i-1]==s2[j-1])                                                               
    return t[i][j]=1+lcsrec(s1,s2,i-1,j-1);
    else
    return t[i][j]=max(lcsrec(s1,s2,i-1,j),lcsrec(s1,s2,i,j-1)) ;
}
```
![](https://images.slideplayer.com/25/7702674/slides/slide_4.jpg)

---
## Longest palindromic Subsequence
same as lcs just need to rev string and do lcs on it
```C++
    int longestPalindromeSubseq(string s) {
        string revs = string(s.rbegin(),s.rend());
        int l=s.length();vector<int> v(l+1,0);
        vector<vector<int>> dp(l+1,v);
        for(int i=0;i<l+1;i++)
        {
            for(int j=0;j<l+1;j++)
            {
                if(i==0||j==0)continue;
                if(s[i-1]==revs[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[l][l];
        
    }
```

## longest repeating subsequence
same as lcs but we add i!=j when we compare 2 strings and the 2 stringss we take for lcs are the same
```c++
void lrs(string s)
{
    int l1=s.length();
    int table[l1+1][l1+1];
    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l1;j++)
        {
            if(i==0||j==0)
            {
                table[i][j]=0; 
                continue;
            }
            if(s[i-1]==s[j-1]&&i!=j)
            {
                table[i][j]=table[i-1][j-1]+1;
            }
            else{
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }

            
        }
        
    }
    
    if(table[l1][l1]>=2)cout<<"1";  repeating substring will be more than equal to 2
    else cout<<"0";
}
```
![](img\longestrepeatingsubsequence.png)

---
## longest increasing substring
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
```c++
int lengthOfLIS(vector<int>& nums) {
        int lis[nums.size()];
        for(int i=0;i<nums.size();i++)
            lis[i]=1;
        int maxlis=1;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    lis[i]=max(lis[i],lis[j]+1);
                    if(lis[i]>maxlis)maxlis=lis[i];
                }
            }
        }
        return maxlis;
    }
```
make a table of of lis of 1 for each element

| j| | |i |
|-|-|-|-|
|0|2|3|4|
|n1|n2|n3|n4|

we we compare n4>n3 then take max(nums[i],nums[j]+1)

---
# coin change - no. of ways we can makechange
recursive
```cpp
int count(int S[], int m, int n)
{
     
    // If n is 0 then there is 1 solution
    // (do not include any coin)
    if (n == 0)
        return 1;
     
    // If n is less than 0 then no
    // solution exists
    if (n < 0)
        return 0;
 
    // If there are no coins and n
    // is greater than 0, then no
    // solution exist
    if (m <= 0 && n >= 1)
        return 0;
 
    // count is sum of solutions (i)
    // including S[m-1] (ii) excluding S[m-1]
    return count(S, m - 1, n) +
           count(S, m, n - S[m - 1]);
}
```
tabular
```c++
int count( int S[], int m, int n )//m - size of array
{
    int i, j, x, y;
    int table[n + 1][m];
     
    // Fill the entries for 0
    // value case (n = 0)
    for (i = 0; i < m; i++)
        table[0][i] = 1;
 
    // Fill rest of the table entries
    // in bottom up manner
    for (i = 1; i < n + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;
 
            // Count of solutions excluding S[j]
            y = (j >= 1) ? table[i][j - 1] : 0;
 
            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m - 1];
}
```
![](img\coinchange-noofways.png)

---
# min no. of coins required
```c++
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
```
![](img\coinchange-minnoofcoins.png)
---
# Word Break
given a dictionary and a string and using dictionary we need to split string
```c++
    bool wordBreak(string s, vector<string>& wordDict) {
       if(memo.find(s)!=memo.end())
           return memo[s];
        if(s=="")return true;
        for(string str:wordDict)
        {
            if(s.substr(0,str.size())==str)
            {
                if(wordBreak(s.substr(str.size()),wordDict))
                {
                    memo[s]=true;
                    return true;
                }
            }
        }
        memo[s]=false;
        return false;
    } 
```
![](img\wordbreak.png)

---
# Palindromic Substring
you are given a string and you need to partition that string such that every substring of the partition is a palindrome. Your task is to return the minimum cuts needed for a palindrome partitioning of the given string.
```c++
bool isPalindrome(string String, int i, int j)
{
    while(i < j)
    {
      if(String[i] != String[j])
        return false; 
      i++;
      j--;
    }
    return true;
}
int minPalPartion(string String, int i, int j)
{
    if( i >= j || isPalindrome(String, i, j) )
      return 0;
    int ans = INT_MAX, count;
    for(int k = i; k < j; k++)
    {
      count = minPalPartion(String, i, k) +
        minPalPartion(String, k + 1, j) + 1;
  
      ans = min(ans, count);
    }
    return ans;
}
```
![](https://s3-lc-upload.s3.amazonaws.com/users/r0cky2h/image_1536728871.png)

---
# Egg Drop
![](img\eggdropping.png)

Recursion
```c++
int eggDrop(int n, int k)
{
    // If there are no floors,
    // then no trials needed.
    // OR if there is one floor,
    // one trial needed.
    if (k == 1 || k == 0)
        return k;
 
    // We need k trials for one
    // egg and k floors
    if (n == 1)
        return k;
 
    int min = INT_MAX, x, res;
 
    // Consider all droppings from
    // 1st floor to kth floor and
    // return the minimum of these
    // values plus 1.
    for (x = 1; x <= k; x++) {
        res = max(
            eggDrop(n - 1, x - 1),
            eggDrop(n, k - x));
        if (res < min)
            min = res;
    }
 
    return min + 1;
}
```
DP
```c++
![]()
int eggDrop(int n, int k)
{
    /* A 2D table where entry
    eggFloor[i][j] will represent
    minimum number of trials needed for
    i eggs and j floors. */
    int eggFloor[n + 1][k + 1];
    int res;
    int i, j, x;
 
    // We need one trial for one floor and 0
    // trials for 0 floors
    for (i = 1; i <= n; i++) {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }
 
    // We always need j trials for one egg
    // and j floors.
    for (j = 1; j <= k; j++)
        eggFloor[1][j] = j;
 
    // Fill rest of the entries in table using
    // optimal substructure property
    for (i = 2; i <= n; i++) {
        for (j = 2; j <= k; j++) {
            eggFloor[i][j] = INT_MAX;
            for (x = 1; x <= j; x++) {
                res = 1 + max(
                              eggFloor[i - 1][x - 1],
                              eggFloor[i][j - x]);
                if (res < eggFloor[i][j])
                    eggFloor[i][j] = res;
            }
        }
    }
 
    // eggFloor[n][k] holds the result
    return eggFloor[n][k];
}
 
```
---
# rod cutting
recursion
```c++
int rodCut(int price[], int n)
{
    // base case
    if (n == 0) {
        return 0;
    }
 
    int maxValue = INT_MIN;
 
    // one by one, partition the given rod of length `n` into two parts
    // of length (1, n-1), (2, n-2), (3, n-3), … ,(n-1, 1), (n, 0)
    // and take maximum
    for (int i = 1; i <= n; i++)
    {
        // rod of length `i` has a cost `price[i-1]`
        int cost = price[i - 1] + rodCut(price, n - i);
 
        if (cost > maxValue) {
            maxValue = cost;
        }
    }
 
    return maxValue;
}
```

dp
```c++
int rodCut(int price[], int n)
{
    // `T[i]` stores the maximum profit achieved from a rod of length `i`
    int T[n + 1];
 
    // initialize maximum profit to 0
    for (int i = 0; i <= n; i++) {
        T[i] = 0;
    }
 
    // consider a rod of length `i`
    for (int i = 1; i <= n; i++)
    {
        // divide the rod of length `i` into two rods of length `j`
        // and `i-j` each and take maximum
        for (int j = 1; j <= i; j++) {
            T[i] = max(T[i], price[j - 1] + T[i - j]);
        }
    }
 
    // `T[n]` stores the maximum profit achieved from a rod of length `n`
    return T[n];
}
```
---
# longest common substring
```c++
string LCS(string X, string Y, int m, int n)
{
    int maxlen = 0;         // stores the max length of LCS
    int endingIndex = m;    // stores the ending index of LCS in `X`
 
    // `lookup[i][j]` stores the length of LCS of substring
    // `X[0…i-1]`, `Y[0…j-1]`
    int lookup[m + 1][n + 1];
 
    // initialize all cells of the lookup table to 0
    memset(lookup, 0, sizeof(lookup));
 
    // fill the lookup table in a bottom-up manner
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // if the current character of `X` and `Y` matches
            if (X[i - 1] == Y[j - 1])
            {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
 
                // update the maximum length and ending index
                if (lookup[i][j] > maxlen)
                {
                    maxlen = lookup[i][j];
                    endingIndex = i;
                }
            }
        }
    }
 
    // return longest common substring having length `maxlen`
    return X.substr(endingIndex - maxlen, maxlen);
}
```
---
# Given an array [] of length N and an integer Sum , the task is to find the number of subsets with sum equal to Sum
```c++
int findCnt(int* arr,int required_sum, int n) 
{ 
  int tab[n+1][required_sum+1];
  for(int i=0;i<=n;i++)
  {
      tab[i][0]=1;
  }
  for(int i=1;i<=required_sum;i++)
  {
      tab[0][i]=0;
  }
  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=required_sum;j++)
      {
          if(j<arr[i-1])
          {
              tab[i][j]=tab[i-1][j];
          }
          else
          {
              tab[i][j]=tab[i-1][j]+tab[i-1][j-arr[i-1]];
          }
      }
  }
  return tab[n][required_sum];
} 
```
---
# weighted job sscheduling
```c++
int maxProfit(vector<Job> &jobs, int n)
{
  sort(jobs.begin(),jobs.end(),compare);//sort according to finish time
  vector<int> jb(n,0);
  jb[0]=jobs[0].profit;//initialise first one
  for(int i=1;i<n;i++)
  {
      
      for(int j=0;j<i;j++)
      {
          if(jobs[j].finish<=jobs[i].start)
          {
              jb[i]=max(jb[i],jobs[i].profit+jb[j]);
          }
      }
      if(jb[i]==0)jb[i]=jobs[i].profit;//if it doesnt have an non overlapping job
  }
  int maxv=jb[0];
  for(auto a:jb)
  {
      if(a>maxv)maxv=a;
  }
	return maxv;
}
```
![](img\weightedscheduling.png)

---
# interleaving 2 strings
![](img\interleavingofstring-1.png)
```c++
bool isInterleave(string s1, string s2, string s3) {
    if(s3.length() != s1.length() + s2.length())
        return false;
    
    bool table[s1.length()+1][s2.length()+1];
    
    for(int i=0; i<s1.length()+1; i++)
        for(int j=0; j< s2.length()+1; j++){
            if(i==0 && j==0)
                table[i][j] = true;
            else if(i == 0)
                table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
            else if(j == 0)
                table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
            else
                table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
        }
        
    return table[s1.length()][s2.length()];
}
```
![](img\interleavingofstring-2.png)

---
# keystroke
```c++
int findoptimal(int N)
{
    // The optimal string length is N when N is smaller than 7
    if (N <= 6)
        return N;
 
    // An array to store result of subproblems
    int screen[N];
 
    int b; // To pick a breakpoint
 
    // Initializing the optimal lengths array for uptil 6 input
    // strokes.
    int n;
    for (n = 1; n <= 6; n++)
        screen[n - 1] = n;
 
    // Solve all subproblems in bottom manner
    for (n = 7; n <= N; n++) {
        // Initialize length of optimal string for n keystrokes
        screen[n - 1] = 0;
 
        // For any keystroke n, we need to loop from n-3 keystrokes
        // back to 1 keystroke to find a breakpoint 'b' after which we
        // will have ctrl-a, ctrl-c and then only ctrl-v all the way.
        for (b = n - 3; b >= 1; b--) {
            // if the breakpoint is at b'th keystroke then
            // the optimal string would have length
            // (n-b-1)*screen[b-1];
            int curr = (n - b - 1) * screen[b - 1];
            if (curr > screen[n - 1])
                screen[n - 1] = curr;
        }
    }
 
    return screen[N - 1];
}
```
![](img\keystroke.png)
---
# Subset Partition By using Memorization Approach
```
Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is the same. 
```
```c++
bool subsetSum(int arr[], int n, int sum)
{
	// matrix[i][j] stores true if subset with sum j can be attained with
	// using items up to first i items
	bool matrix[n + 1][sum + 1];

	// if 0 items in the list and sum is non-zero
	for (int j = 1; j <= sum; j++)
		matrix[0][j] = false;

	// if sum is zero
	for (int i = 0; i <= n; i++)
		matrix[i][0] = true;

	// do for ith item
	for (int i = 1; i <= n; i++)
	{
		// consider all sum from 1 to sum
		for (int j = 1; j <= sum; j++)
		{
			// don't include ith element if j-arr[i-1] is negative
			if (arr[i - 1] > j)
				matrix[i][j] = matrix[i - 1][j];
            else
			// find subset with sum j by excluding or including the ith item
				matrix[i][j] = matrix[i - 1][j] || matrix[i - 1][j - arr[i - 1]];
		}
	}

	// return maximum value
	return matrix[n][sum];
}
```
![](img\arraypartition.png)
---
# Wildcard Matching
```c++
bool isMatch(string s, string p) {
        bool tb[s.length()+1][p.length()+1];
        int sl=s.length(),pl=p.length();
        memset(tb, false, sizeof(tb));
        tb[0][0]=true;
        for(int i=1;i<=pl;i++)
        if(p[i-1]=='*')
            tb[0][i]=tb[0][i-1];
        for(int i=1;i<=sl;i++)
        {
            for(int j=1;j<=pl;j++)
            {
                if(p[j-1]=='?'||s[i-1]==p[j-1])
                {
                    tb[i][j]=tb[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    tb[i][j]=tb[i-1][j]||tb[i][j-1];
                }
                else
                    tb[i][j]=false;
            }
        }
        return tb[sl][pl];
    }   
```
---
# maximum increasing subsequence
```c++
int maxSumIS(int arr[], int n)
{
    int i, j, max = 0;
    int msis[n];
 
    /* Initialize msis values
    for all indexes */
    for ( i = 0; i < n; i++ )
        msis[i] = arr[i];
 
    /* Compute maximum sum values
    in bottom up manner */
    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
                msis[i] = msis[j] + arr[i];
 
    /* Pick maximum of
    all msis values */
    for ( i = 0; i < n; i++ )
        if ( max < msis[i] )
            max = msis[i];
 
    return max;
}
```
---
## malware spread
![](img\malwarespread1.png)
```cpp
vector<int> par;
int find(int u)
{
    return par[u] == u ? u : par[u] = find(par[u]);
}

int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial)
{
    int n = graph.size();
    for (int i = 0; i < n; i++)
        par.push_back(i);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && graph[i][j] == 1)
                par[find(i)] = find(j); //union two set, cycle dosent matter here so we didn't check just merge two set.

    vector<int> IPC(n, 0); //infected patient count
    vector<int> POC(n, 0); //population of country

    sort(initial.begin(), initial.end());
    int ans = initial[0];
    for (int patient : initial) // set leader will store how many infected patient the have and size of set.
        IPC[find(patient)]++;
    for (int i = 0; i < n; i++)
        POC[find(i)]++;

    int maxPopulation = 0;
    for (int patient : initial) // iterate over leaders and ask them how many infected patient they have.
    {
        if (IPC[par[patient]] == 1 && POC[par[patient]] > maxPopulation)
        {
            maxPopulation = POC[par[patient]];
            ans = patient;
        }
    }

    return ans;
}
```
![](img\malwarespread2.png)

---
## climbing stairs
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
```cpp
    int climbStairs(int n) {
        vector<int> a(n+1,0);
        a[0]=1;
        for(int i=0;i<n;i++) //[as 0 1 2 3   n-1] n  0th step has 1 way
        {
            a[i+1]=a[i]+a[i+1];//taking 1 step
            if(i+2<=n) //outside limit
            a[i+2]=a[i]+a[i+2];//taking 2 steps
            
        }
        return a[n]; 
    }
```
---
## jump game
![](img\jumpg1.png)
```cpp
    int jump(vector<int>& nums) {
        int a=nums[0],b=nums[0],j=1;
        if(a==0||nums.size()==1)return 0;
        for(int i=1;i<nums.size()-1;i++)
        {
            
            a--;
            b--;
            if(b<nums[i])
            {
                b=nums[i];
            }
            if(a==0)
            {
                j++;
                a=b;
            }
        }
        return j;
    }
```
![](img\jumpg2.png)

---
## min path sum
![](img\minpathsum1.png)
```cpp
    int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0] = grid[0][0];
    for(int i=1;i<m;i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];
    for(int j=1;j<n;j++)
        dp[0][j] = dp[0][j-1] + grid[0][j];
     for(int i=1;i<m;i++)
         for(int j=1;j<n;j++)
             dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
        return dp[m-1][n-1];
    }
```
![](img\minpathsum2.png)

---
## Maximum size square sub-matrix with all 1s
![img](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Maximum-size-square-sub-matrix-with-all-1s.png)
```cpp
int  getMaxSizeSubmatrixWithAllOne(vector<vector<int>>& matrix)
{
	int rows = matrix.size();
	int cols = matrix[0].size();
/*create the same size of another 2d dp table.. */
	vector<vector<int>> dp(rows, vector<int>(cols, 0));
	int maxSize = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols ; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = matrix[i][j];
			}
			else if (matrix[i][j] == 1)
			{
				
				dp[i][j] = 1 + min({dp[i - 1][j - 1] , dp[i - 1][j] , dp[i][j - 1]});
				maxSize = max(maxSize, dp[i][j]);
			}
			else if (matrix[i][j] == '0')
				dp[i][j] = 0;
		}
	}
	return maxSize;
}
```
![](img\max1s.png)

---
## 0 1 knapsack
```cpp
int knapSack(int W, int wt[], int val[], int n)
{
 
    // Base Case
    if (n == 0 || W == 0)
        return 0;
    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
     // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            val[n - 1]+ knapSack(W - wt[n - 1],wt, val, n - 1),knapSack(W, wt, val, n - 1));
}
```
dp
```cpp
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
      vector<vector<int>> K(n + 1, vector<int>(W + 1));
 
    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
```
![](img\o1knap.png)

---
## longest increasing subsequence
```cpp
    int lengthOfLIS(vector<int>& nums) {
        const int size = nums.size();
        if (size == 0) { return 0; } 
        vector<int> dp(size, 1);
        int res = 1;
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max (res, dp[i]);
        }
        return res;
    }
```
## building bridges
```cpp
struct bridge_co_ordinates
{ 
    int north, south; 
}; 
  
// comparison function to sort bridge co ordinates
bool compare(struct bridge_co_ordinates a, struct bridge_co_ordinates b) 
{ 
    if (a.south == b.south) 
        return a.north < b.north; 
    return a.south < b.south; 
} 
  

int get_max_bridges(struct bridge_co_ordinates values[], int n) 
{ 
    int dp_array[n]; 
    for (int i=0; i<n; i++) 
        dp_array[i] = 1; 
          
    sort(values, values+n, compare); 
      
    // logic of longest increasing subsequence applied on the north coordinates 
    for (int i=1; i<n; i++) 
        for (int j=0; j<i; j++) 
            if (values[i].north >= values[j].north  
                && dp_array[i] < 1 + dp_array[j]) 
                dp_array[i] = 1 + dp_array[j]; 
          
          
    int max = dp_array[0]; 
    for (int i=1; i<n; i++) 
        if (max < dp_array[i]) 
            max = dp_array[i]; 
             
    return max;         
} 
```
![](img\buildingbridges.png)

---
## box stacking
`You are given a set of n types of rectangular 3-D boxes, where the i^th box has height h(i), width w(i) and depth d(i) (all real numbers). You want to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base. It is also allowable to use multiple instances of the same type of box. 
`
1) Generate all 3 rotations of all boxes. The size of rotation array becomes 3 times the size of the original array. For simplicity, we consider width as always smaller than or equal to depth. 
2) Sort the above generated 3n boxes in decreasing order of base area.
3) After sorting the boxes, the problem is same as LIS with following optimal substructure property. 
MSH(i) = Maximum possible Stack Height with box i at top of stack 
MSH(i) = { Max ( MSH(j) ) + height(i) } where j < i and width(j) > width(i) and depth(j) > depth(i). 
If there is no such j then MSH(i) = height(i)
4) To get overall maximum height, we return max(MSH(i)) where 0 < i < n
Following is the implementation of the above solution. 
```cpp
int compare (const void *a, const void * b)
{
    return ( (*(Box *)b).d * (*(Box *)b).w ) -
           ( (*(Box *)a).d * (*(Box *)a).w );
}
 
/* Returns the height of the tallest stack that can be
   formed with give type of boxes */
int maxStackHeight( Box arr[], int n )
{
   /* Create an array of all rotations of given boxes
      For example, for a box {1, 2, 3}, we consider three
      instances{{1, 2, 3}, {2, 1, 3}, {3, 1, 2}} */
   Box rot[3*n];
   int index = 0;
   for (int i = 0; i < n; i++)
   {
      // Copy the original box
      rot[index].h = arr[i].h;
      rot[index].d = max(arr[i].d, arr[i].w);
      rot[index].w = min(arr[i].d, arr[i].w);
      index++;
 
      // First rotation of box
      rot[index].h = arr[i].w;
      rot[index].d = max(arr[i].h, arr[i].d);
      rot[index].w = min(arr[i].h, arr[i].d);
      index++;
 
      // Second rotation of box
      rot[index].h = arr[i].d;
      rot[index].d = max(arr[i].h, arr[i].w);
      rot[index].w = min(arr[i].h, arr[i].w);
      index++;
   }
 
   // Now the number of boxes is 3n
   n = 3*n;
 
   /* Sort the array 'rot[]' in non-increasing order
      of base area */
   qsort (rot, n, sizeof(rot[0]), compare);
 
   // Uncomment following two lines to print all rotations
   // for (int i = 0; i < n; i++ )
   //    printf("%d x %d x %d\n", rot[i].h, rot[i].w, rot[i].d);
 
   /* Initialize msh values for all indexes
      msh[i] --> Maximum possible Stack Height with box i on top */
   int msh[n];
   for (int i = 0; i < n; i++ )
      msh[i] = rot[i].h;
 
   /* Compute optimized msh values in bottom up manner */
   for (int i = 1; i < n; i++ )
      for (int j = 0; j < i; j++ )
         if ( rot[i].w < rot[j].w &&
              rot[i].d < rot[j].d &&
              msh[i] < msh[j] + rot[i].h
            )
         {
              msh[i] = msh[j] + rot[i].h;
         }
 
 
   /* Pick maximum of all msh values */
   int max = -1;
   for ( int i = 0; i < n; i++ )
      if ( max < msh[i] )
         max = msh[i];
 
   return max;
}
```
---
## buy sell stock 1
![](img\buysellstock1.png)
```cpp
    int maxProfit(vector<int>& nums) {
    int minsofar=INT_MAX,maxsofar=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            minsofar=min(minsofar,nums[i]);
            maxsofar=max(maxsofar,nums[i]-minsofar);
        }
        return maxsofar;
    
    }
```
![](img\maxsubarray.png)
---
## buy sell stock 2
![](img\buysellstock2.png)
```cpp
    int maxProfit(vector<int>& prices) {
    int maxpr=0;

        for(int i=0;i<prices.size()-1;i++)
        {
            maxpr=maxpr=max(0,prices[i]-prices[i-1]);
        }
        return maxpr;
    }
```
![](img\buysellstock2-s.png)

---
## buy sell stock 3
![](img\buysellstock3.png)
```cpp
int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        int buy1    = INT_MAX;
        int profit1 = 0
        int buy2    = INT_MAX;
        int profit2 = 0
        for(int i = 0; i < prices.size(); i++){
            buy1    = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            buy2    = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }
```
We can also explain the above codes in other words. On every day, we buy the share with the price as low as we can, and sell the share with price as high as we can. For the second transaction, we integrate the profit of first transaction into the cost of the second buy, then the profit of the second sell will be the total profit of two transactions.

```cpp
int maxProfit(vector<int>& prices) {
    //It's wrong if you choose the minimum price for buy2 , but you can maximize the left money.
    //
    int buy1 = INT_MIN, sale1 = 0, buy2 = INT_MIN, sale2 = 0;
    for(int i=0; i<prices.size(); i++){                      //the more money left, the happier you will be
        buy1 = max(buy1, -prices[i]);                        //left money after buy1
        sale1 = max(sale1, prices[i] + buy1);                //left money after sale1
        buy2 = max(buy2, sale1 - prices[i]);                 //left money after buy2
        sale2 = max(sale2, prices[i] + buy2);                //left money after sale2
    }
    return sale2;
}
```
---
## buy sell stock 4
![](img\buysellstock4-1.png)
```cpp
int maxProfit(vector<int>& p, int res = 0) {
    for (int i = 1; i < p.size(); ++i) res += max(0, p[i] - p[i - 1]);
    return res;
}
int maxProfit(int k, vector<int>& prices) {
    if (k >= prices.size() / 2) return maxProfit(prices);
    vector<int> buys(k + 1, INT_MIN), sells(k + 1, 0);
    for (auto p : prices)
        for (auto i = 1; i <= k; ++i) {
        buys[i] = max(buys[i], sells[i - 1] - p);
        sells[i] = max(sells[i], buys[i] + p);  
        }
    return sells[k];
}
```
![](img\buysellstock4-2.png)

---
## buy sell stock with cooldown
![](img\buysellstockwc-1.png)
```cpp
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int StateC[n];
        int StateA[n];
        int stateb[n];
        StateC[0]=0;
        StateA[0]=-prices[0];
        StateB[0]=INT_MIN;
        for(int i=1;i<n;i++)
        {
            StateC[i] = max(stateb[i-1],StateC[i-1]);
            StateA[i] = max(StateC[i-1]-prices[i],StateA[i-1]);
            stateb[i] = StateA[i]+prices[i];
        }
        return max(StateC[n-1],stateb[n-1]);
    }
```
![](img\buysellstockwc-2.png)

---
## buy sell stock with trans fees
![](img\buysellstockt-1.png)
```cpp
    int maxProfit(vector<int>& prices, int fee) {
        int buy=-prices[0],sell=0;
        for(int i=1;i<prices.size();i++)
        {
            int temp=buy;
            buy=max(buy,sell-prices[i]);
            sell=max(sell,temp+prices[i]-fee);
            
        }
        return sell;
    }
```
![](img\buysellstockt-2.png)

---
## nth ugly no.
ugly no. is a multiple of either 2,3 and 5 only including 1\
`dynampro`
```cpp
unsigned getNthUglyNo(unsigned n)
{
    // To store ugly numbers
    unsigned ugly[n];
    unsigned i2 = 0, i3 = 0, i5 = 0;
    unsigned next_multiple_of_2 = 2;
    unsigned next_multiple_of_3 = 3;
    unsigned next_multiple_of_5 = 5;
    unsigned next_ugly_no = 1;
 
    ugly[0] = 1;
    for (int i = 1; i < n; i++) {
        next_ugly_no = min(
            next_multiple_of_2,
            min(next_multiple_of_3, next_multiple_of_5));
        ugly[i] = next_ugly_no;
        if (next_ugly_no == next_multiple_of_2) {
            i2 = i2 + 1;
            next_multiple_of_2 = ugly[i2] * 2;
        }
        if (next_ugly_no == next_multiple_of_3) {
            i3 = i3 + 1;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        if (next_ugly_no == next_multiple_of_5) {
            i5 = i5 + 1;
            next_multiple_of_5 = ugly[i5] * 5;
        }
    } 
   
    // End of for loop (i=1; i<n; i++)
    return next_ugly_no;
}
```
# `using set` -not pq as duplicate elements may occur
```cpp
int nthUglyNumber(int n)
{
    // Base cases...
    if (n == 1 or n == 2 or n == 3 or n == 4 or n == 5)
        return n;
 
    set<long long int> s;
    s.insert(1);
    n--;
 
    while (n) {
        auto it = s.begin();
 
        // Get the beginning element of the set
        long long int x = *it;
 
        // Deleting the ith element
        s.erase(it);
 
        // Inserting all the other options
        s.insert(x * 2);
        s.insert(x * 3);
        s.insert(x * 5);
        n--;
    }
 
    // The top of the set represents the nth ugly number
    return *s.begin();
}
```
![](img\uglynosoln-2.png)

---
## super ugly no.
Super ugly numbers are positive numbers whose all prime factors are in the given prime list. Given a number n, the task is to find the nth Super Ugly number.
It may be assumed that a given set of primes is sorted. Also, the first Super Ugly number is 1 by convention. \
`dp`

```cpp
int superUgly(int n, int primes[], int k)
{
    // nextMultiple holds multiples of given primes
    vector<int> nextMultiple(primes, primes+k);
 
    // To store iterators of all primes
    int multiple_Of[k];
    memset(multiple_Of, 0, sizeof(multiple_Of));
 
    // Create a set to store super ugly numbers and
    // store first Super ugly number
    set<int> ugly;
    ugly.insert(1);
 
    // loop until there are total n Super ugly numbers
    // in set
    while (ugly.size() != n)
    {
        // Find minimum element among all current
        // multiples of given prime
        int next_ugly_no = *min_element(nextMultiple.begin(),
                                    nextMultiple.end());
 
        // insert this super ugly number in set
        ugly.insert(next_ugly_no);
 
        // loop to find current minimum is multiple
        // of which prime
        for (int j=0; j<k; j++)
        {
            if (next_ugly_no == nextMultiple[j])
            {
                // increase iterator by one for next multiple
                // of current prime
                multiple_Of[j]++;
 
                // this loop is similar to find  dp[++index[j]]
                // it -->  dp[++index[j]]
                set<int>::iterator it = ugly.begin();
                for (int i=1; i<=multiple_Of[j]; i++)
                    it++; //this is a pointer for ugly
 
                nextMultiple[j] = primes[j] * (*it);
                break;
            }
        }
    }
 
    // n'th super ugly number
    set<int>::iterator it = ugly.end();
    it--;
    return *it;
}
```


```cpp
int ugly(int a[], int size, int n){
     
    //n cannot be negative hence return -1 if n is 0 or -ve
    if(n <= 0)
        return -1;
  
    if(n == 1)
        return 1;
     
    // Declare a min heap priority queue
    priority_queue<int, vector<int>, greater<int>> pq;
     
    // Push all the array elements to priority queue
    for(int i = 0; i < size; i++){
        pq.push(a[i]);
    }
     
    // once count = n we return no
    int count = 1, no;
     
    while(count < n){
        // Get the minimum value from priority_queue
        no = pq.top();
        pq.pop();
         
        // If top of pq is no then don't increment count. This to avoid duplicate counting of same no.
        if(no != pq.top())
        {
            count++;
         
            //Push all the multiples of no. to priority_queue
            for(int i = 0; i < size; i++){
                pq.push(no * a[i]);
            //    cnt+=1;
        }
        }
    }
    // Return nth super ugly number
    return no;
}
```
same ideology as ugly no.

---
## wild card matching
![](img\wildcardpattern-1.png)
```cpp
bool strmatch(char str[], char pattern[], int n, int m)
{
    // empty pattern can only match with
    // empty string
    if (m == 0)
        return (n == 0);
 
    // lookup table for storing results of
    // subproblems
    bool lookup[n + 1][m + 1];
 
    // initialize lookup table to false
    memset(lookup, false, sizeof(lookup));
 
    // empty pattern can match with empty string
    lookup[0][0] = true;
 
    // Only '*' can match with empty string
    for (int j = 1; j <= m; j++)
        if (pattern[j - 1] == '*')
            lookup[0][j] = lookup[0][j - 1];
 
    // fill the table in bottom-up fashion
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // Two cases if we see a '*'
            // a) We ignore ‘*’ character and move
            //    to next  character in the pattern,
            //     i.e., ‘*’ indicates an empty sequence.
            // b) '*' character matches with ith
            //     character in input
            if (pattern[j - 1] == '*')
                lookup[i][j]
                    = lookup[i][j - 1] || lookup[i - 1][j];
 
            // Current characters are considered as
            // matching in two cases
            // (a) current character of pattern is '?'
            // (b) characters actually match
            else if (pattern[j - 1] == '?'
                     || str[i - 1] == pattern[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1];
 
            // If characters don't match
            else
                lookup[i][j] = false;
        }
    }
 
    return lookup[n][m];
}
```
![](img\wildcardpattern.png)

---
## regular expression
![](img\regularexpression-1.png)
```cpp
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        
        f[0][0] = true;
        for (int i = 1; i <= m; i++)
            f[i][0] = false;
        // p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
        for (int j = 1; j <= n; j++)
            f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];
        
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] != '*')
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                else
                    // p[0] cannot be '*' so no need to check "j > 1" here
                    f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];
        
        return f[m][n];
    }
```
![](img\regularexpression.png)

---
## count all palindromic subsequences
```cpp
cp[i][j] => no. of palind subseq between i and j 
int countPS(string str)
{
    int N = str.length();
 
    // create a 2D array to store the count of palindromic
    // subsequence
    int cps[N + 1][N + 1];
    memset(cps, 0, sizeof(cps));
 
    // palindromic subsequence of length 1
    for (int i = 0; i < N; i++)
        cps[i][i] = 1;           //individuls character are palindrome by itself
 
    // check subsequence of length L is palindrome or not
    for (int L = 2; L <= N; L++) {
        for (int i = 0; i <= N-L; i++) {
            int k = L + i - 1;
            if (str[i] == str[k])
                cps[i][k]
                    = cps[i][k - 1] + cps[i + 1][k] + 1;
            else
                cps[i][k] = cps[i][k - 1] + cps[i + 1][k]
                            - cps[i + 1][k - 1];
        }
    }
 
    // return total palindromic subsequence
    return cps[0][N - 1];
}
```
memorization
```cpp
int n, dp[1000][1000];
string str = "abcb";
 
// Function return the total
// palindromic subsequence
int countPS(int i, int j)
{
 
    if (i > j)
        return 0;
 
    if (dp[i][j] != -1)
        return dp[i][j];
 
    if (i == j)
        return dp[i][j] = 1;
 
    else if (str[i] == str[j])
        return dp[i][j]
               = countPS(i + 1, j) +
                countPS(i, j - 1) + 1;
 
    else
        return dp[i][j] = countPS(i + 1, j) +
                          countPS(i, j - 1) -
                          countPS(i + 1, j - 1);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    n = str.size();
    cout << "Total palindromic subsequence are : "
         << countPS(0, n - 1) << endl;
    return 0;
}
```
![](https://media.geeksforgeeks.org/wp-content/uploads/20190804162927/00011.jpg)
 
---
# Max sum with no 2 adjacent element
```cpp
int FindMaxSum(int arr[], int n)
    {
        int dp[n];
        dp[0] = arr[0];
        if(n == 1)
        return dp[0];
        dp[1] = max(arr[0], arr[1]);
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
```
![](img\maxnonadjsum.png)

---
# Max sum with no 3 continuous element
```cpp
int maxSumWO3Consec(int n)
{
    if(sum[n]!=-1)
    return sum[n];
     
    //Base cases (process first three elements)
     
    if(n==0)
    return sum[n] = 0;
     
    if(n==1)
    return sum[n] = arr[0];
     
    if(n==2)
    return sum[n] = arr[1]+arr[0];
     
    // Process rest of the elements
    // We have three cases
    return sum[n] = max(max(maxSumWO3Consec(n-1),
                    maxSumWO3Consec(n-2) + arr[n]),
                    arr[n] + arr[n-1] + maxSumWO3Consec(n-3);
     
     
}
```
![](img\no3seladjsum.png)

---
# Count number of binary strings without consecutive 1’s
```cpp
int fibo(int n)
{
    if(n==1||n==0)
    return 1;
    return fibo(n-1)+fibo(n-2);
}
```
- fibo - 0 1 1 2 3
- so its the (n+2)th fibonacci no \
    n = 1, count = 2  = fib(3)  // 0   1        \
    n = 2, count = 3  = fib(4)    // 01 10 00 \
    n = 3, count = 5  = fib(5) \
    n = 4, count = 8  = fib(6) \
    n = 5, count = 13 = fib(7) 
---

## longest common subsequence of 3 strings
recursive
```cpp
int lcsOf3( string X, string Y, string Z, int m,
                               int n, int o)
{
    int L[m+1][n+1][o+1];
 
    /* Following steps build L[m+1][n+1][o+1] in
       bottom up fashion. Note that L[i][j][k]
       contains length of LCS of X[0..i-1] and
       Y[0..j-1]  and Z[0.....k-1]*/
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            for (int k=0; k<=o; k++)
            {
                if (i == 0 || j == 0||k==0)
                    L[i][j][k] = 0;
 
                else if (X[i-1] == Y[j-1] && X[i-1]==Z[k-1])
                    L[i][j][k] = L[i-1][j-1][k-1] + 1;
 
                else
                    L[i][j][k] = max(max(L[i-1][j][k],
                                         L[i][j-1][k]),
                                     L[i][j][k-1]);
            }
        }
    }
 
    /* L[m][n][o] contains length of LCS for
      X[0..n-1] and Y[0..m-1] and Z[0..o-1]*/
    return L[m][n][o];
}
```
tabular
```cpp
int lcsOf3( string X, string Y, string Z, int m,
                               int n, int o)
{
    int L[m+1][n+1][o+1];
 
    /* Following steps build L[m+1][n+1][o+1] in
       bottom up fashion. Note that L[i][j][k]
       contains length of LCS of X[0..i-1] and
       Y[0..j-1]  and Z[0.....k-1]*/
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            for (int k=0; k<=o; k++)
            {
                if (i == 0 || j == 0||k==0)
                    L[i][j][k] = 0;
 
                else if (X[i-1] == Y[j-1] && X[i-1]==Z[k-1])
                    L[i][j][k] = L[i-1][j-1][k-1] + 1;
 
                else
                    L[i][j][k] = max(max(L[i-1][j][k],
                                         L[i][j-1][k]),
                                     L[i][j][k-1]);
            }
        }
    }
 
    /* L[m][n][o] contains length of LCS for
      X[0..n-1] and Y[0..m-1] and Z[0..o-1]*/
    return L[m][n][o];
}
```

---
## Edit Distance
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:
- Insert a character
- Delete a character
- Replace a character
```c++
    int minDistance(string word1, string word2) {
       int l1=word1.length();
        int l2=word2.length();
        int table[l1+1][l2+1];
        table[0][0]=0;
        for(int i=1;i<l1+1;i++)table[i][0]=i;
        for(int i=1;i<l2+1;i++)table[0][i]=i;
        for(int i=1;i<l1+1;i++)
        {
            for(int j=1;j<l2+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    table[i][j]=table[i-1][j-1];
                }
                else
                {
                    table[i][j]=1+min(table[i-1][j-1],min(table[i-1][j],table[i][j-1]));//min of delete replace and insert
                }
            }
        }
        return table[l1][l2];
    }
```
memo
```cpp
int editDist(string str1, string str2, int m, int n)
{
    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0)
        return n;
 
    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0)
        return m;
 
    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if (str1[m - 1] == str2[n - 1])
        return editDist(str1, str2, m - 1, n - 1);
 
    // If last characters are not same, consider all three
    // operations on last character of first string,
    // recursively compute minimum cost for all three
    // operations and take minimum of three values.
    return 1
           + min(editDist(str1, str2, m, n - 1), // Insert
                 editDist(str1, str2, m - 1, n), // Remove
                 editDist(str1, str2, m - 1,
                          n - 1) // Replace
             );
}
```
![](img\editdistance.png)

---
## frog jump
![](img\frogjump-1.png)
```cpp
    bool canCross(vector<int>& stones) {
        int N = stones.size();
        vector<vector<bool>> dp(N,vector<bool>(N+1,false));
        dp[0][1] = true;
        
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                int diff = stones[i] - stones[j];
                if(diff < 0 || diff > N || !dp[j][diff]) continue;
                dp[i][diff] = true;
                if(diff - 1 >= 0) dp[i][diff - 1] = true;
                if(diff + 1 <= N) dp[i][diff + 1] = true;
                if(i == N - 1) return true;
            }
        }

        return false;
    }
```
![](img\frogjump-2.png)

---
# Optimal Strategy for a Game | DP-31
Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against an opponent by alternating turns. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin. Determine the maximum possible amount of money we can definitely win if we move first.
Note: `The opponent is as clever as the user.`
```cpp
int optimalStrategyOfGame(
    int* arr, int n)
{
    // Create a table to store
    // solutions of subproblems
    int table[n][n];
 
    // Fill table using above
    // recursive formula. Note
    // that the table is filled
    // in diagonal fashion (similar
    // to http:// goo.gl/PQqoS),
    // from diagonal elements to
    // table[0][n-1] which is the result.
    for (int gap = 0; gap < n; ++gap) {
        for (int i = 0, j = gap; j < n; ++i, ++j) {
            // Here x is value of F(i+2, j),
            // y is F(i+1, j-1) and
            // z is F(i, j-2) in above recursive
            // formula
            int x = ((i + 2) <= j)
                        ? table[i + 2][j]
                        : 0;
            int y = ((i + 1) <= (j - 1))
                        ? table[i + 1][j - 1]
                        : 0;
            int z = (i <= (j - 2))
                        ? table[i][j - 2]
                        : 0;
 
            table[i][j] = max(
                arr[i] + min(x, y),
                arr[j] + min(y, z));
        }
    }
 
    return table[0][n - 1];
}
```
![](img\optimumgamechoice.png)

---
## temple offering
![](img\templeoffering.png)
```cpp
int offerings(int n, int arr[]){
        int of[n]={0};
        of[0]=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
                of[i]=of[i-1]+1;
            else
                of[i]=1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>arr[i+1]&&of[i]<=of[i+1])
                of[i]=of[i+1]+1;
        }
        int sum=0;
        for(int i=0;i<n;i++)
            sum=sum+of[i];
        return sum;
    }
```
![](img\templeoffering2.png)
![](img\billboard.png)
---
## highway billboard problem
```cpp
int maxRevenue(int m, int x[], int revenue[], int n,
                                              int t)
{
    // Array to store maximum revenue at each miles.
    int maxRev[m+1];
    memset(maxRev, 0, sizeof(maxRev));
 
    // actual minimum distance between 2 billboards.
    int nxtbb = 0;
    for (int i = 1; i <= m; i++)
    {
        // check if all billboards are already placed.
        if (nxtbb < n)
        {
            // check if we have billboard for that particular
            // mile. If not, copy the previous maximum revenue.
            if (x[nxtbb] != i)
                maxRev[i] = maxRev[i-1];
 
            // we do have billboard for this mile.
            else
            {
                // We have 2 options, we either take current
                // or we ignore current billboard.
 
                // If current position is less than or equal to
                // t, then we can have only one billboard.
                if (i <= t)
                    maxRev[i] = max(maxRev[i-1], revenue[nxtbb]);
 
                // Else we may have to remove previously placed
                // billboard
                else
                    maxRev[i] = max(maxRev[i-t-1]+revenue[nxtbb],
                                                  maxRev[i-1]);
 
                nxtbb++;
            }
        }
        else
            maxRev[i] = maxRev[i - 1];
    }
 
    return maxRev[m];
}
```
![](img\billoard-1.png)

---
## Number of subsequences of the form a^i b^j c^k
i,j,k>=1
```cpp
int countSubsequences(string s)
{
    int aCount = 0;
    int bCount = 0;
    int cCount = 0;
    for (unsigned int i = 0; i < s.size(); i++) {
        if (s[i] == 'a')
            aCount = (1 + 2 * aCount);
        else if (s[i] == 'b')
            bCount = (aCount + 2 * bCount);
        else if (s[i] == 'c')
            cCount = (bCount + 2 * cCount);
    }
 
    return cCount;
}
```
![](img\aibjck.png)

---
## filling cup
![](img\fillingcup1.png)
```cpp
float findWater(int i, int j, float X)
{
    // A row number i has maximum i columns. So input
    // column number must be less than i
    if (j > i)
    {
        printf("Incorrect Inputn");
        exit(0);
    }
 
    // There will be i*(i+1)/2 glasses till ith row
    // (including ith row)
    float glass[i * (i + 1) / 2];
 
    // Initialize all glasses as empty
    memset(glass, 0, sizeof(glass));
 
    // Put all water in first glass
    int index = 0;
    glass[index] = X;
 
    // Now let the water flow to the downward glasses
    // till the row number is less than or/ equal to i (given row)
    // correction : X can be zero for side glasses as they have lower rate to fill
    for (int row = 1; row <= i ; ++row)
    {
        // Fill glasses in a given row. Number of
        // columns in a row is equal to row number
        for (int col = 1; col <= row; ++col, ++index)
        {
            // Get the water from current glass
            X = glass[index];
 
            // Keep the amount less than or equal to
            // capacity in current glass
            glass[index] = (X >= 1.0f) ? 1.0f : X;
 
            // Get the remaining amount
            X = (X >= 1.0f) ? (X - 1) : 0.0f;
 
            // Distribute the remaining amount to
            // the down two glasses
            glass[index + row] += X / 2;
            glass[index + row + 1] += X / 2;
        }
    }
 
    // The index of jth glass in ith row will
    // be i*(i-1)/2 + j - 1
    return glass[i*(i-1)/2 + j - 1];
}
```
![](img\fillingcup.png)

---
# Largest sum subarray with at-least k numbers
```cpp
int maxSumWithK(int a[], int n, int k)
{
    // maxSum[i] is going to store maximum sum
    // till index i such that a[i] is part of the
    // sum.
    int maxSum[n];
    maxSum[0] = a[0];
 
    // We use Kadane's algorithm to fill maxSum[]
    // Below code is taken from method 3 of
    int curr_max = a[0];
    for (int i = 1; i < n; i++)
    {
        curr_max = max(a[i], curr_max+a[i]);
        maxSum[i] = curr_max;
    }
 
    // Sum of first k elements
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += a[i];
 
    // Use the concept of sliding window
    int result = sum;
    for (int i = k; i < n; i++)
    {
        sum = sum + a[i] - a[i-k];
        result = max(result, sum);
        result = max(result, sum + maxSum[i-k]);
    }
    return result;
}
```
![](img\largestksubarr.png)

---
##
```cpp
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        vi f(n+2 , 0);
        vector<pair<int ,int>> pre(n+2) ,suf(n+2);

        for( int i=1 ;i<=n ;i++ ) f[i] = f[i-1] + nums[i-1];

        for(int i=k ;i<=n ;i++){
            pre[i] = pre[i-1];
            if( pre[i].first < ( f[i] - f[i-k] ) ){
                pre[i].first = ( f[i] - f[i-k] );
                pre[i].second = i-k+1;
            }
        }

        for(int i=n-k+1 ;i>=1 ;i--){
            suf[i] = suf[i+1];
            if( suf[i].first <= ( f[i+k-1] - f[i-1] ) ){        // <= due to lexicographically minimum
                suf[i].first = ( f[i+k-1] - f[i-1] );
                suf[i].second = i;
            }
        }

        int cur=0;
        vi ans = {-1,-1,-1};
        for( int i=k+1 ;i<=n-2*k+1 ;i++ ){                        // all valid starting index of middle subarray
            int sm = pre[i-1].first + suf[i+k].first + ( f[i+k-1] - f[i-1] );
            if( cur < sm ){
                cur = sm;   
                ans = { pre[i-1].second-1 ,i-1 ,suf[i+k].second-1 };
            }
        }
        return ans;
    }
```
![](img\maxsumof3nonoverlappingarray.png)

---
## Remove minimum elements from either side such that 2*min becomes more than max
```cpp
int minRemovals(int arr[], int l, int h)
{
    if (l >= h) return 0;
    int mn = min(arr, l, h); //returns min between l and h
    int mx = max(arr, l, h);
    if (2*mn > mx)
       return 0;
    return min(minRemovals(arr, l+1, h),
               minRemovals(arr, l, h-1)) + 1;
}
```
tabular
```cpp
int minRemovalsDP(int arr[], int n)
{
    // Create a table to store solutions of subproblems
    int table[n][n], gap, i, j, mn, mx;
    // from diagonal elements to table[0][n-1] which is the result.
    for (gap = 0; gap < n; ++gap)
    {
        for (i = 0, j = gap; j < n; ++i, ++j)
        {
            mn = min(arr, i, j);
            mx = max(arr, i, j);
            table[i][j] = (2*mn > mx)? 0: min(table[i][j-1]+1,
                                              table[i+1][j]+1);
        }
    }
    return table[0][n-1];
}
```
![](img\noofremovals2minmax.png)

---
# scramble string
![](img\scrambledstring1.png)
```cpp
    unordered_map <string, int> m;
    bool solve (string a, string b)
    {
        if (a.size() != b.size()) return false;
        if (a == b) return true;
        if (a.size() == 0 || b.size() == 0) return false;

    `if (m.find(a + " " + b) != m.end()) return m[a + " " + b]; `
	`// this step is very fast instead of` 
	`//if (m[a + " " + b] ) return m[a + " " + b]`

        
        int n = a.size();
        
        for (int i = 1; i < n; i++)
        {
            if (solve (a.substr (0, i), b.substr (n-i, i)) && solve (a.substr (i, n - i), b.substr (0, n - i)))
                return m[a + " " + b] = true; // instead of flag directly return true
            if (solve (a.substr (0, i), b.substr (0, i)) && solve (a.substr (i, n - i), b.substr (i, n - i)))
                return m[a + " " + b] = true; // instead of flag directly return true
            
        }
        return m[a + " " + b] = false;
        
    }
    bool isScramble(string a, string b) {
        
        if (a.size() != b.size()) return false;
        if (a == b) return true;
        
		// check if both the string contains the same characters or not 
        int cnt[26] = {0};
        for (int i = 0; i < a.size(); i++)
        {
            cnt[a[i] - 'a'] ++;
            cnt[b[i] - 'a'] --;
        }
        
        for (auto & i : cnt) if (i != 0) return false;
        
        return solve (a, b);
         
    }
```
![](img\scrambledstring.png)

---
## keypad
![](img\keypad-0.png)
```cpp
int getCount(char keypad[][3], int n)
{
    if(keypad == NULL || n <= 0)
        return 0;
    if(n == 1)
        return 10;
 
    // left, up, right, down move from current location
    int row[] = {0, 0, -1, 0, 1};
    int col[] = {0, -1, 0, 1, 0};
 
    // taking n+1 for simplicity - count[i][j] will store
    // number count starting with digit i and length j
    int count[10][n+1];
    int i=0, j=0, k=0, move=0, ro=0, co=0, num = 0;
    int nextNum=0, totalCount = 0;
 
    // count numbers starting with digit i and of lengths 0 and 1
    for (i=0; i<=9; i++)
    {
        count[i][0] = 0;
        count[i][1] = 1;
    }
 
    // Bottom up - Get number count of length 2, 3, 4, ... , n
    for (k=2; k<=n; k++)
    {
        for (i=0; i<4; i++)  // Loop on keypad row
        {
            for (j=0; j<3; j++)   // Loop on keypad column
            {
                // Process for 0 to 9 digits
                if (keypad[i][j] != '*' && keypad[i][j] != '#')
                {
                    // Here we are counting the numbers starting with
                    // digit keypad[i][j] and of length k keypad[i][j]
                    // will become 1st digit, and we need to look for
                    // (k-1) more digits
                    num = keypad[i][j] - '0';
                    count[num][k] = 0;
 
                    // move left, up, right, down from current location
                    // and if new location is valid, then get number
                    // count of length (k-1) from that new digit and
                    // add in count we found so far
                    for (move=0; move<5; move++)
                    {
                        ro = i + row[move];
                        co = j + col[move];
                        if (ro >= 0 && ro <= 3 && co >=0 && co <= 2 &&
                           keypad[ro][co] != '*' && keypad[ro][co] != '#')
                        {
                            nextNum = keypad[ro][co] - '0';
                            count[num][k] += count[nextNum][k-1];
                        }
                    }
                }
            }
        }
    }
    totalCount = 0;
    for (i=0; i<=9; i++)
        totalCount += count[i][n];
    return totalCount;
}
```
![](img\keypad-1.png)

---
## matrix multiplication
![](img\matrixmultiplication.png)

---
## Given a string, find out if the string is K-Palindrome or not. A k-palindrome string transforms into a palindrome on removing at most k characters from it.
```cpp
int isKPalDP(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m + 1][n + 1];
 
    // Fill dp[][] in bottom up manner
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            if (i == 0)
                dp[i][j] = j; // Min. operations = j
 
            
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i
 
            // If last characters are same, ignore last character
            // and recur for remaining string
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
 
            // If last character are different, remove it
            // and find minimum
            else
             dp[i][j] = 1 + min(dp[i - 1][j], // Remove from str1
                             dp[i][j - 1]); // Remove from str2
        }
    }
 
    return dp[m][n];
}
```

![](img\kpalindrome.png)

---
## maximize th cut segment
Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.
```cpp
    int dp[10005];
    public:
    int func(int n, int x, int y, int z)
    {
       if(n==0)
        return 0;
       if(dp[n] != -1)
        return dp[n];
       int x1=INT_MIN,y1=INT_MIN,z1=INT_MIN;
       if(n>=x)
        x1 = func(n-x, x,y,z);
       if(n>=y)
        y1 = func(n-y, x,y,z);
       if(n>=z)
         z1 = func(n-z, x,y,z);
         
         dp[n] = 1+max(x1, max(y1,z1));
       return dp[n];
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(dp, -1, sizeof(dp));
        int a = func(n, x, y, z);
        if(a<0)
        return 0;
        
        return a;   
    }
```
![](img\maximisecutseg.png)

---
## Maximum sum increasing subsequence
```cpp
int maxSumIS(int arr[], int n)  
	{  
	    int dp[n];
	    for(int i=0;i<n;i++)
	    dp[i]=arr[i];
	    int ans=dp[0];
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(arr[i]>arr[j])
	            {
	                dp[i]=max(dp[i],arr[i]+dp[j]);
	                ans=max(dp[i],ans);
	            }
	        }
	    }
	    return ans;
	} 
```
![](img\maximumsumofincsubse.png)

---

## friend pairing problem
Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
```cpp
int dp[1000];
 
// Returns count of ways n people
// can remain single or paired up.
int countFriendsPairings(int n)
{
    if (dp[n] != -1)
        return dp[n];
 
    if (n > 2)
        return dp[n] = countFriendsPairings(n - 1) + (n - 1) * countFriendsPairings(n - 2);
    else
        return dp[n] = n;
}
```
dp table
```cpp
int countFriendsPairings(int n)
{
    int dp[n + 1];
 
    // Filling dp[] in bottom-up manner using
    // recursive formula explained above.
    for (int i = 0; i <= n; i++) {
        if (i <= 2)
            dp[i] = i;
        else
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
 
    return dp[n];
}
//or
int countFriendsPairings(int n)
{
    int a = 1, b = 2, c = 0;
    if (n <= 2) {
        return n;
    }
    for (int i = 3; i <= n; i++) {
        c = b + (i - 1) * a;
        a = b;
        b = c;
    }
    return c;
}
```
![](img\friendpairing.png)

---
## catalan number
```cpp
unsigned long int catalan(unsigned int n)
{
    // Base case
    if (n <= 1)
        return 1;
 
    // catalan(n) is sum of
    // catalan(i)*catalan(n-i-1)
    unsigned long int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i)
            * catalan(n - i - 1);
 
    return res;
}
```
![](img\catalan.png)

---
## gold minor
```cpp
    for (int col=n-1; col>=0; col--)
    {
        for (int row=0; row<m; row++)
        {
            // Gold collected on going to the cell on the right(->)
            int right = (col==n-1)? 0: goldTable[row][col+1];
 
            // Gold collected on going to the cell to right up (/)
            int right_up = (row==0 || col==n-1)? 0:
                            goldTable[row-1][col+1];
 
            // Gold collected on going to the cell to right down (\)
            int right_down = (row==m-1 || col==n-1)? 0:
                             goldTable[row+1][col+1];
 
            // Max gold collected from taking either of the
            // above 3 paths
            goldTable[row][col] = gold[row][col] +
                              max(right, max(right_up, right_down));
                                                     
        }
    }
 
    // The max amount of gold collected will be the max
    // value in first column of all rows
    int res = goldTable[0][0];
    for (int i=1; i<m; i++)
        res = max(res, goldTable[i][0]);
    return res;
}
```
![](img\goldminer.png)

---
## painting fence

```cpp
int main(){
    int numWays(int n, int k) {

        if (n == 0) return 0;

        if (n == 1) return k;

        int diff = k * (k - 1), same = k;

        for (int i = 2; i < n; i++) {

            int temp = (diff + same) * (k - 1);

            same = diff;

            diff = temp;

        }

         

        return diff + same;

    }
```
![](img\paintingfence.png)

---
##
```cpp
bool comp(struct val a, struct val b)
{
    return a.second<b.second;
}
int maxChainLen(struct val p[],int n)
{
//Your code here
    sort(p, p+n,comp); //sort according to finish time or second
    int c=1;
    int l=p[0].first, r= p[0].second;
    
    for(int i=1; i<n; i++)
    {
        if(r< p[i].first)
        {
            c++;
            r= p[i].second;
        }
        
    }
    return c;
}
```

---
## max chain length
same as weighted scheduling can use longest inc subsequence
```cpp
bool comp(struct val a, struct val b)
{
    return a.second<b.second;
}
int maxChainLen(struct val p[],int n)
{
//Your code here
    sort(p, p+n,comp);
    int c=1;
    int l=p[0].first, r= p[0].second;
    
    for(int i=1; i<n; i++)
    {
        if(r< p[i].first)
        {
            c++;
            r= p[i].second;
        }
        
    }
    return c;
}
//or use algorithm given below 
```
![](img\maxchainpair.png)

---
## number of product subsequence where prodcut <k
```cpp
    static int[][] dp;

    static int process(int[] arr, int n, int k, int product){

        if(n == 0) 
            return 0;

        if(product > k){ 
            return 0;
        }

        if(dp[n][product] != -1) // dp check
            return dp[n][product];

        int inc = product * arr[n-1]; 
        int exc = product; 

        int count = 0;

        if(inc < k){ 
            count++;
        }

        count += process(arr, n-1, k, inc) + process(arr, n-1, k, exc);

        dp[n][product] = count;

        return dp[n][product];
    }

    static int find(int[] arr, int n, int k){
        dp = new int[n+1][k+1];

        for(int i = 0;i <= n;i++){
            for(int j = 0; j <= k;j++){
                dp[i][j] = -1;
            }
        }

        int product = 1;
        return process(arr, n, k, product);
    } 
```
```cpp
int productSubSeqCount(vector<int> &arr, int k)
{
    int n = arr.size();
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
    
            // number of subsequence using j-1 terms before jth term
            dp[i][j] = dp[i][j - 1];
   
            // if arr[j-1] > i it will surely make product greater
            // thus it won't contribute then
            if (i/arr[j - 1]>0) // as i>a[j-1] as eg if i=3 a[j-1]=5 3 cannot be constructed with 5 as its element 
 
                // number of subsequence using 1 to j-1 terms
                // and j-th term
                dp[i][j] += dp[i/arr[j-1]][j-1] + 1;
        }
    }
    return dp[k][n];
}
```
![](img\prouctlessksubsequence.png)

---
## Minimum removals from array to make max – min <= K
 ```cpp
 int countRemovals(int a[], int i, int j, int k)
{
    // base case when all elements are removed
    if (i >= j)
        return 0;
 
    // if condition is satisfied, no more
    // removals are required
    else if ((a[j] - a[i]) <= k)
        return 0;
 
    // if the state has already been visited
    else if (dp[i][j] != -1)
        return dp[i][j];
 
    // when Amax-Amin>d
    else if ((a[j] - a[i]) > k) {
 
        // minimum is taken of the removal
        // of minimum element or removal
        // of the maximum element
        dp[i][j] = 1 + min(countRemovals(a, i + 1, j, k),
                           countRemovals(a, i, j - 1, k));
    }
    return dp[i][j];
}
```
 - sort array
 - remove either from left or right 
 - if(func(i+1,j)||func(i,j-1))
 
 or
 ```cpp
 int findInd(int key, int i,
            int n, int k, int arr[])
{
    int start, end, mid, ind = -1;
     
    // Initialising start to i + 1
    start = i + 1;
     
    // Initialising end to n - 1
    end = n - 1;
     
    // Binary search implementation
    // to find the rightmost element
    // that satisfy the condition
    while (start < end)
    {
        mid = start + (end - start) / 2;
         
        // Check if the condition satisfies
        if (arr[mid] - key <= k)
        {  
             
            // Store the position
            ind = mid;
             
            // Make start = mid + 1
            start = mid + 1;
        }
        else
        {
            // Make end = mid
            end = mid;
        }
    }
     
    // Return the rightmost position
    return ind;
}
 
// Function to calculate
// minimum number of elements
// to be removed
int removals(int arr[], int n, int k)
{
    int i, j, ans = n - 1;
     
    // Sort the given array
    sort(arr, arr + n);
     
    // Iterate from 0 to n-1
    for (i = 0; i < n; i++)
    {
         
        // Find j such that
        // arr[j] - arr[i] <= k
        j = findInd(arr[i], i, n, k, arr);
         
        // If there exist such j
        // that satisfies the condition
        if (j != -1)
        {
            // Number of elements
            // to be removed for this
            // particular case is
            // (j - i + 1)
            ans = min(ans, n - (j - i + 1));
        }
    }
     
    // Return answer
    return ans;
}
```
![](img\mindelebinarysearch.png)

---
# Maximum sum of pairs with specific difference
```cpp
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    // Sort input array in ascending order.
    sort(arr, arr+N);
 
    // dp[i] denotes the maximum disjoint pair sum
    // we can achieve using first i elements
    int dp[N];
 
    //  if no element then dp value will be 0
    dp[0] = 0;
 
    for (int i = 1; i < N; i++)
    {
        // first give previous value to dp[i] i.e.
        // no pairing with (i-1)th element
        dp[i] = dp[i-1];
 
        // if current and previous element can form a pair
        if (arr[i] - arr[i-1] < K)
        {
            // update dp[i] by choosing maximum between
            // pairing and not pairing
            if (i >= 2)
                dp[i] = max(dp[i], dp[i-2] + arr[i] + arr[i-1]);
            else
                dp[i] = max(dp[i], arr[i] + arr[i-1]);
        }
    }
 
    //  last index will have the result
    return dp[N - 1];
}
```
or 
```cpp
int maxSumPair(int arr[], int N, int k)
{
    int maxSum = 0;
 
    // Sort elements to ensure every i and i-1 is closest
    // possible pair
    sort(arr, arr + N);
 
    // To get maximum possible sum,
    // iterate from largest to
    // smallest, giving larger
    // numbers priority over smaller
    // numbers.
    for (int i = N - 1; i > 0; --i)
    {
        // Case I: Diff of arr[i] and arr[i-1]
        //  is less then K,add to maxSum      
        // Case II: Diff between arr[i] and arr[i-1] is not
        // less then K, move to next i since with
        // sorting we know, arr[i]-arr[i-1] <
        // rr[i]-arr[i-2] and so on.
        if (arr[i] - arr[i - 1] < k)
        {
            // Assuming only positive numbers.
            maxSum += arr[i];
            maxSum += arr[i - 1];
 
            // When a match is found skip this pair
            --i;
        }
    }
 
    return maxSum;
}
``` 
![](img\maxdiffkdisjoint.png)

---


