> Problem Statement: Given a number of stairs. Starting from the 0th stair we need to climb to the “Nth” stair. At a time we can climb either one or two steps. We need to return the total number of distinct ways to reach from 0th to Nth stair.
> ![](https://lh4.googleusercontent.com/qYp5CdHJ0Wqq_Bct5RhB5oKKXUBOdnoe-Ya6fjh3vqVIQbzsnrSLE7QjlMkm2IDhHuIjNKlLfhVavT4AJkRWoaREJSvcCQZ_Tx0rtYmuiJXFaz9Wg3m-OXcycwsfSQnBjWsskSep)

```cpp
  dp[0]= 1;
  dp[1]= 1;

  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
```

optimization

```cpp
  int prev2 = 1;
  int prev = 1;

  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
```

---

> Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.

![](https://lh3.googleusercontent.com/_w5IvcsYohG_kLM-vSZddLFe5AbrSM40J5oC8UZ63fbkmxLhwVHqeKUqKDNXdEv_MnQSlVoAfZxontqdBqCmV_wHq4AssTQu9f8v1LO8M_xpiFCaILeruL-THce3stMY3GmnQaeN)

```cpp
int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
    if(ind>1)
        jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);

    return dp[ind]=min(jumpOne, jumpTwo);
}

```

space optimized

```cpp
  prev=0,prev2=0;
  for(int i=1;i<n;i++){

      int jumpTwo = INT_MAX;
      int jumpOne= prev + abs(height[i]-height[i-1]);
      if(i>1)
        jumpTwo = prev2 + abs(height[i]-height[i-2]);

      int cur_i=min(jumpOne, jumpTwo);
      prev2=prev;
      prev=cur_i;

  }
```

---

> This is a follow-up question to “Frog Jump” discussed in the previous article. In the previous question, the frog was allowed to jump either one or two steps at a time. In this question, the frog is allowed to jump up to ‘K’ steps at a time. If K=4, the frog can jump 1,2,3, or 4 steps at every index.
> ![](https://lh5.googleusercontent.com/kx9o7SlWA4RwXuHtnFTcSOsKmWGWFWAl_u-k_gJ1CDEPHQtttzDWVGcN_YCDemZeCIzcZQ3Hlxb8ns3IwDr8pb_3Yb6r2t8GznIyQISmjsPW9mlL2JIs3znJ7b4QkgP-Hvqal1WH)

```cpp
int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];

    int mmSteps = INT_MAX;

    for(int j=1;j<=k;j++){
        if(ind-j>=0){
      int jump = solveUtil(ind-j, height, dp, k)+ abs(height[ind]- height[ind-j]);
            mmSteps= min(jump, mmSteps);
        }
    }
    return dp[ind]= mmSteps;

}
```

tabulation

```cpp
int solveUtil(int n, vector<int>& height, vector<int>& dp, int k){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;

        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                mmSteps= min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}
```

---

> sum of no adjacent element in the array
> optimized

```cpp
int solve(int n, vector<int>& arr){
    int prev = arr[0];
    int prev2 =0;

    for(int i=1; i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;

        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;

    }
    return prev;
}
```

> `A thief needs to rob money in a street. The houses in the street are arranged in a circular manner. Therefore the first and the last house are adjacent to each other. The security system in the street is such that if adjacent houses are robbed, the police will get notified. Given an array of integers “Arr” which represents money at each house, we need to return the maximum amount of money that the thief can rob without alerting the police.`

```cpp
long long int solve(vector<int>& arr){
    int n = arr.size();
    long long int prev = arr[0];
    long long int prev2 =0;

    for(int i=1; i<n; i++){
        long long int pick = arr[i];
        if(i>1)
            pick += prev2;
        int long long nonPick = 0 + prev;

        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;

    }
    return prev;
}

long long int robStreet(int n, vector<int> &arr){
    vector<int> arr1;
    vector<int> arr2;

    for(int i=0; i<n; i++){

        if(i!=0) arr1.push_back(arr[i]);
        if(i!=n-1) arr2.push_back(arr[i]);
    }

    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);

    return max(ans1,ans2);
}


int main() {

  vector<int> arr{1,5,1,2,6};
  int n=arr.size();
  cout<<robStreet(n,arr);
}
```

---

> `A Ninja has an ‘N’ Day training schedule. He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. There are merit points associated with performing an activity each day. The same activity can’t be performed on two consecutive days. We need to find the maximum merit points the ninja can attain in N Days. We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of specific activity on that particular day. Our task is to calculate the maximum number of merit points that the ninja can earn.`

![](https://lh3.googleusercontent.com/fGhKc0zD0hrkqCd-4jAGVuIiJgqFvyk1dSLmTiwWwTXmRmG_LoqpiaOwk1puC3jgVB_HZx3p0v0Ovq66QWwKhaYanSBF8yI09GLZwm-aumvQT8LPuSSvlDerGoN0uz2MyNhX8I67)
![](https://lh3.googleusercontent.com/r8sm6cCBI_19bCk_Lj74zjkTHAwlHY39TZvjY_ac6-MmOQSkD26aVBRlVryky_417c16Dnms5M0q1ywBqTzP6sQalUvv_H9LS_bziYoXJfYcAaCzKHvoAvD4NHyub8uog11tQCoO)
![](https://lh6.googleusercontent.com/D99rKrCmR8yGELFs-PuEMYnHTtjCctCBqeVGvNE6ZLHjPPAg44aqUlsxUGlUMCx70qmJrthbaSQM1Gom-DwtcQ9Bzd37mwrf83GuOxUZcX-aabv8ttPYbTJDpXWOuiyY-98h_i5H)
Recursive soln

```cpp
int f(int day, int last, vector<vector<int>> &points,vector<vector<int>> &dp) {

  if (dp[day][last] != -1) return dp[day][last];

  if (day == 0) {
    int maxi = 0;
    for (int i = 0; i <= 2; i++) {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }
    return dp[day][last] = maxi;
  }

  int maxi = 0;
  for (int i = 0; i <= 2; i++) {
    if (i != last) {
      int activity = points[day][i] + f(day - 1, i, points, dp);
      maxi = max(maxi, activity);
    }

  }

  return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < vector < int > > dp(n, vector < int > (4, -1));
  return f(n - 1, 3, points, dp);
}
```

## `Tabular`

```cpp
int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < vector < int > > dp(n, vector < int > (4, 0));

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          int activity = points[day][task] + dp[day - 1][task];
          dp[day][last] = max(dp[day][last], activity);
        }
      }
    }

  }

  return dp[n - 1][3];
}

```

---

> `Given two values M and N, which represent a matrix[M][N]. We need to find the total unique paths from the top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]).At any cell we are allowed to move in only two directions:- bottom and right.`

```cpp
int countWaysUtil(int m, int n, vector<vector<int> > &dp) {
  for(int i=0; i<m ;i++){
      for(int j=0; j<n; j++){

          //base condition
          if(i==0 && j==0){
              dp[i][j]=1;
              continue;
          }
          int up=0;
          int left = 0;
          if(i>0)
            up = dp[i-1][j];
          if(j>0)
            left = dp[i][j-1];
          dp[i][j] = up+left;
      }
  }
```

space optimization as we are using only 2 rows

```cpp
int countWays(int m, int n){

    vector<int> prev(n,0);
    for(int i=0; i<m; i++){
        vector<int> temp(n,0); //////////
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                temp[j]=1;
                continue;
            }

            int up=0;
            int left =0;

            if(i>0)
                up = prev[j];
            if(j>0)
                left = temp[j-1];

            temp[j] = up + left;
        }
        prev = temp;
    }

    return prev[n-1];
}
```

---

> `same question as above with obstacles`

```cpp
int mazeObstacles(int n, int m, vector<vector<int> > &maze){

    vector<int> prev(m,0);
    for(int i=0; i<n; i++){
        vector<int> temp(m,0);
        for(int j=0; j<m; j++){
            if(i>0 && j>0 && maze[i][j]==-1){
                temp[j]=0;
                continue;
            }
            if(i==0 && j==0){
                temp[j]=1;
                continue;
            }

            int up=0;
            int left =0;

            if(i>0)
                up = prev[j];
            if(j>0)
                left = temp[j-1];

            temp[j] = up + left;
        }
        prev = temp;
    }

    return prev[n-1];


}

```

---

> `We are given an “N*M” matrix of integers. We need to find a path from the top-left corner to the bottom-right corner of the matrix, such that there is a minimum cost past that we select.At every cell, we can move in only two directions: right and bottom. The cost of a path is given as the sum of values of cells of the given matrix.`
> tabulation

```cpp
int minSumPath(int n, int m, vector<vector<int> > &matrix){
    vector<vector<int> > dp(n,vector<int>(m,0));
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) dp[i][j] = matrix[i][j];
            else{

                int up = matrix[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;

                int left = matrix[i][j];
                if(j>0) left+=dp[i][j-1];
                else left += 1e9;

                dp[i][j] = min(up,left);
            }
        }
    }

    return dp[n-1][m-1];

}

```

space optimization

```cpp
int minSumPath(int n, int m, vector<vector<int> > &matrix){
      vector<int> prev(m,0);
    for(int i=0; i<n ; i++){
        vector<int> temp(m,0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0) temp[j] = matrix[i][j];
            else{

                int up = matrix[i][j];
                if(i>0) up += prev[j];
                else up += 1e9;

                int left = matrix[i][j];
                if(j>0) left+=temp[j-1];
                else left += 1e9;

                temp[j] = min(up,left);
            }
        }
        prev=temp;
    }

    return prev[m-1];

}
```

---

> `We are given an ‘N*M’ matrix. We need to find the maximum path sum from any cell of the first row to any cell of the last row.`

```cpp
int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix,
vector<vector<int> > &dp){

    // Base Conditions
    if(j<0 || j>=m)
        return -1e9;
    if(i==0)
        return matrix[0][j];

    if(dp[i][j]!=-1) return dp[i][j];

    int up = matrix[i][j] + getMaxUtil(i-1,j,m,matrix,dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i-1,j-1,m,matrix,dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i-1,j+1,m,matrix,dp);

    return dp[i][j]= max(up,max(leftDiagonal,rightDiagonal));

}

int getMaxPathSum(vector<vector<int> > &matrix){

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n,vector<int>(m,-1));

    int maxi = INT_MIN;

    for(int j=0; j<m;j++){
        int ans = getMaxUtil(n-1,j,m,matrix,dp);
        maxi = max(maxi,ans);
    }

    return maxi;
}
```

tabulation

```cpp
int getMaxPathSum(vector<vector<int> > &matrix){

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n,vector<int>(m,0));

    // Initializing first row - base condition
    for(int j=0; j<m; j++){
        dp[0][j] = matrix[0][j];
    }

    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){

            int up = matrix[i][j] + dp[i-1][j];

            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += dp[i-1][j-1];
            else leftDiagonal += -1e9;

            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += dp[i-1][j+1];
            else rightDiagonal += -1e9;

            dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));

        }
    }

    int maxi = INT_MIN;

    for(int j=0; j<m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }

    return maxi;
}
```

- can further be space optimized

---

# 3D DP

> `We are given an ‘N*M’ matrix. Every cell of the matrix has some chocolates on it, mat[i][j] gives us the number of chocolates. We have two friends ‘Alice’ and ‘Bob’. initially, Alice is standing on the cell(0,0) and Bob is standing on the cell(0, M-1). Both of them can move only to the cells below them in these three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).When Alica and Bob visit a cell, they take all the chocolates from that cell with them. It can happen that they visit the same cell, in that case, the chocolates need to be considered only once.They cannot go out of the boundary of the given matrix, we need to return the maximum number of chocolates that Bob and Alice can together collect.`

[Explanation](https://takeuforward.org/data-structure/3-d-dp-ninja-and-his-friends-dp-13/)

## `ALGO`

![](https://lh4.googleusercontent.com/7aYfjlF_ObESYKWa2Qp8L2qyNvS6gFM5dZTjp8qcxzj-MJNdDsj_zcdTW_j3ZxjvyAogREQw2JTeFaMbklFglu3i4eaj5Ars-p7ddbdKHPtkjNsK2N2U01R_dOlknRblMttKluQS)

```cpp
int maxChocoUtil(int i, int j1, int j2, int n, int m, vector < vector < int >>
& grid, vector < vector < vector < int >>> & dp) {
  if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    return -1e9;

  if (i == n - 1) {
    if (j1 == j2)
      return grid[i][j1];
    else
      return grid[i][j1] + grid[i][j2];
  }

  if (dp[i][j1][j2] != -1)
    return dp[i][j1][j2];

  int maxi = INT_MIN;
  for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
      int ans;
      if (j1 == j2)
        ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
      else
        ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n,
        m, grid, dp);
      maxi = max(maxi, ans);
    }
  }
  return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int n, int m, vector < vector < int >> & grid) {

  vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, vector < int
  > (m, -1)));

  return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
}
```

Tabulation

```cpp
int maximumChocolates(int n, int m, vector < vector < int >> & grid) {
  // Write your code here.
  vector < vector < vector < int >>> dp(n, vector < vector < int >> (m,
  vector < int > (m, 0)));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        dp[n - 1][j1][j2] = grid[n - 1][j1];
      else
        dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += dp[i + 1][j1 + di][j2 + dj];

            maxi = max(ans, maxi);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }

  return dp[0][0][m - 1];

}
```

---

# `subset sum`

```cpp
int Solution::solve(vector<int> &arr, int k) {
    int n=arr.size();
     vector < vector < bool >> dp(n + 1, vector < bool > (k + 1,false));

    // If required price = 0, answer always true.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
           bool not_take = dp[i - 1][j];
           bool take=false;
            if (arr[i - 1] <= j) {
                t =dp[i - 1][j - arr[i - 1]];
            }
            dp[i][j]=take|not_take;
        }
    }

    return dp[n][k];
}
```

---

# `equal subset sum`

```cpp
bool canPartition(vector<int> &arr, int n)
{
    int sum=0;
	for(int a:arr)sum+=a;
    if(sum%2==1)return false;
    sum=sum/2;
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    for(int i=0;i<=n;i++)dp[i][0]=true;
    for(int i=1;i<=n;i++){
        for(int target=1;target<=sum;target++){
            bool not_take=dp[i-1][target];
            bool take=false;
            if(arr[i-1]<=target){
                take=dp[i-1][target-arr[i-1]];
            }
            dp[i][target]=take|not_take;
        }
    }
    return dp[n][sum];
}
```

---

# `Partition a set into two subsets such that the difference of subset sums is minimum.`

```cpp
int minSubsetSumDifference(vector<int>& arr, int n)
{
     // take total sum as k
     int sum=0;
     for(int a:arr)sum+=a;
     int k=sum;
     vector < vector < bool >> dp(n + 1, vector < bool > (k + 1,false));

    // If required price = 0, answer always true.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
           bool not_take = dp[i - 1][j];
           bool take=false;
            if (arr[i - 1] <= j) {
                take = dp[i - 1][j - arr[i - 1]];
            }
            dp[i][j]=take|not_take;
        }
    }
    int minSum=sum+1;
    //check what  all numbers are possible too formed using subset
    for(int i=0;i<=sum;i++){
        if(dp[n][i]==true){
            int other =sum-i;
            int diff = abs(i-other);
            minSum=min(minSum,diff);
        }
    }
    return minSum;
}
```

---

# no. of subset to get sum k

- `memo`

```cpp
int solve(vector<int> &arr, int i, int target ,vector<vector<int>>& dp){
    if(target==0)return 1; ///// imp //// line 1
    if(i==0){//line 2
        if(arr[0]==target)return 1; ///imp////as we only 2 choices here
        else return 0;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    int not_take=solve(arr,i-1,target,dp);
    int take=0;
    if(arr[i]<=target){
        take=solve(arr,i-1,target-arr[i],dp);
    }
    return dp[i][target]=take+not_take;
}
int findWays(vector<int> &arr, int k)
{
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return solve(arr,n-1,k,dp);
}
```

`bottom up approach tabulation`

```cpp
int findWays(vector<int> &arr, int k)
{
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    for(int i=0;i<n;i++)dp[i][0]=1; //line 1
    if(arr[0]<=k)dp[0][arr[0]]=1; //line 2 as some numbers may be greater than k
    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            // copy everything formm memo code and change solve to dp
            int not_take=dp[i-1][target];
            int take=0;
            if(arr[i]<=target){
                take=dp[i-1][target-arr[i]];
            }
            dp[i][target]=take+not_take;
        }
    }
    return dp[n-1][k];
}
```

- to deal with sitations where there are 0s in the array

```cpp
int mod=(int)(1e9+7);
int solve(vector<int> &arr, int i, int target ,vector<vector<int>>& dp){
//     if(target==0)return 1; //line 1 not needed as there is a probability of 0 being present in the ret of array
    if(i==0){
        if(target==0&&arr[0]==0)return 2; // as we can both inc and exclude it to give ans
        if(arr[0]==target)return 1; //line 2
        if(target==0)return 1; // as there is a posiblity of subset being equal to target and adding 0 to it doesnt change target
        else return 0;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    int not_take=solve(arr,i-1,target,dp);
    int take=0;
    if(arr[i]<=target){
        take=solve(arr,i-1,target-arr[i],dp);
    }
    return dp[i][target]=(take+not_take);
}
```

`Tabulation`

```cpp
   vector<vector<int>> dp(n,vector<int>(target+1,0));
    if(arr[0]==0)dp[0][0]=2;
    else dp[0][0]=1;
    if(arr[0]!=0&&target>=arr[0]){
        dp[0][arr[0]]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            int not_take=dp[i-1][j];
            int take=0;
            if(arr[i]<=j){
                take=dp[i-1][j-arr[i]];
            }
            dp[i][j]=take+not_take;
        }
    }
    return dp[n-1][target];
```

---

# `0/1 knapsach`

```cpp
int solve(int ind,int currWeight,vector<int> weight, vector<int> value,vector<vector<int>>& dp){
    if(ind==0){ //as any weight greater than currWeight not possible
        if(weight[0]<=currWeight)return value[0];
        else return 0;
    }
    if(dp[ind][currWeight]!=-1)return dp[ind][currWeight];
    int not_take = 0 + solve(ind-1,currWeight,weight,value,dp);
    int take = INT_MIN;
    if(currWeight>=weight[ind])take = value[ind] + solve(ind-1,currWeight-weight[ind],weight,value,dp);
    return dp[ind][currWeight] = max(take,not_take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return solve(n-1,maxWeight,weight,value,dp);
}

```

`tabulation`

```cpp
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    for(int i=weight[0];i<=maxWeight;i++)dp[0][i]=value[0]; //line 1 as every weight from weight[0] to max is robbabable
    for(int ind=1;ind<n;ind++){
        for(int currWeight=1;currWeight<=maxWeight;currWeight++){
            int not_take = 0 + dp[ind-1][currWeight];
            int take = INT_MIN;
            if(currWeight>=weight[ind])take = value[ind] + dp[ind-1][currWeight-weight[ind]];
            dp[ind][currWeight] = max(take,not_take);
          }
    }
	return dp[n-1][maxWeight];
```

---

# min number of coins to reach a value

```cpp
int solve(int ind,int currSum,vector<int> num,vector<vector<int>>& dp){
    if(ind==0){
        if(currSum%num[0]==0)return currSum/num[0]; //to check if therem value can be made by first coin or this branch wrong
        else return 1e9;
    }
    if(dp[ind][currSum]!=-1)return dp[ind][currSum];
    int not_take = 0 +solve(ind-1,currSum,num,dp);
    int take=INT_MAX;
    if(currSum>=num[ind]){
        take=1+solve(ind,currSum-num[ind],num,dp); // no ind-1 as we can use the coin again
    }
    return dp[ind][currSum] = min(take,not_take);
}
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,-1));
    int ans = solve(n-1,x,num,dp);
    if(ans>=1e9)return -1;
    return ans;
}
```

```cpp
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,0));
    for(int i=0;i<=x;i++){
        if(i%num[0]==0)
        dp[0][i]=i/num[0];
        else dp[0][i]=1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int currSum=1;currSum<=x;currSum++){
                int not_take = 0 +dp[ind-1][currSum];
                int take=INT_MAX;
                if(currSum>=num[ind]){
                    take=1+dp[ind][currSum-num[ind]];
                }
                dp[ind][currSum] = min(take,not_take);
        }
    }
    int ans=dp[n-1][x];
    if(ans>=1e9)return -1;
    return ans;
```

- can optimize the above by using prev[] and curr[] for dp then doing
- `prev=curr` after one outer loop iteration

---

# target sum

```
You are given an array ‘ARR’ of ‘N’ integers and a target number, ‘TARGET’. Your task is to build an expression out of an array by adding one of the symbols '+' and '-' before each integer in an array, and then by concatenating all the integers, you want to achieve a target. You have to return the number of ways the target can be achieved.
```

```
You are given the array ‘ARR’ = [1, 1, 1, 1, 1], ‘TARGET’ = 3. The number of ways this target can be achieved is:
1. -1 + 1 + 1 + 1 + 1 = 3
2. +1 - 1 + 1 + 1 + 1 = 3
3. +1 + 1 - 1 + 1 + 1 = 3
4. +1 + 1 + 1 - 1 + 1 = 3
5. +1 + 1 + 1 + 1 - 1 = 3
These are the 5 ways to make. Hence the answer is 5.
```

```cpp
int targetSum(int n, int target, vector<int>& arr) {
    int t=0;
    for(int a:arr)t+=a;
    // nothing but s1-s2=target   total-target /2 => s2
    int find=t-target;
    if(find<0 || find%2 ==1)return false;
    find=find/2;
    vector<vector<int>> dp(n,vector<int>(find+1,0));
    if(arr[0]==0)
        dp[0][0]=2; //both inc and exc
    else dp[0][0]=1; //omly exc
    if(arr[0]!=0&&arr[0]<=find)dp[0][arr[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=find;j++){
            int not_take=dp[i-1][j];
            int take=0;
            if(arr[i]<=j)
                take=dp[i-1][j-arr[i]];
            dp[i][j]=take+not_take;
        }
    }
    return dp[n-1][find];
}

```

---

# no of ways we can reach a value given simem coins which can be used infinitely

```cpp
long f(int ind,int curr,int* coins,vector<vector<long>>& dp){
    if(ind==0){
        if(curr%coins[0]==0)return 1;// to check if we reach the remainng amout
        else return 0;
    }
    if(dp[ind][curr]!=-1)return dp[ind][curr];
    long not_take=f(ind-1,curr,coins,dp);
    long take=0;
    if(coins[ind]<=curr)take=f(ind,curr-coins[ind],coins,dp);// dont change int
    return dp[ind][curr]=take+not_take;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,-1));

    return f(n-1,value,denominations,dp);
}
```

---

# Unbounded knapsack

```cpp
//base case
if(ind==0){
  int value=((int)(currwt/weight[0])*profit[0])
  // eg currwt =13 and wt[0]=4 we cann use 4 wts totaling 12 and profit = profit[0]*3
  return value;
}
```

```cpp
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    for(int i=1;i<=w;i++){ // base case of recursion
        dp[0][i]=((int)(i/weight[0]))*profit[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int currwt=1;currwt<=w;currwt++){
            int not_take=dp[ind-1][currwt];
            int take=0;
            if(weight[ind]<=currwt)
                take=profit[ind]+dp[ind][currwt-weight[ind]];//dont change
            dp[ind][currwt]=max(take,not_take);
        }
    }
    return dp[n-1][w];
}
```

# `Rod Cutting problem`

```cpp
int solve(int ind,int currSize,vector<int> price,vector<vector<int>>& dp){
    if(ind==0){
        return price[0]*currSize; //there will currSize rods then
    }
    if(dp[ind][currSize]!=-1)return dp[ind][currSize];
    int not_take=0 + solve(ind-1,currSize,price,dp);
    int take=INT_MIN;
    int rodLen=ind+1;
    if(rodLen<=currSize)
        take=price[ind]+solve(ind,currSize-rodLen,price,dp);
    return dp[ind][currSize]=max(take,not_take);

}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return solve(n-1,n,price,dp);

}
```

tab

```cpp
    vector<vector<int>> dp(n,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)dp[0][i]=price[0]*i;
    for(int ind=1;ind<n;ind++){
        for(int currSize=1;currSize<=n;currSize++){
            int not_take=0 + dp[ind-1][currSize];
            int take=INT_MIN;
            int rodLen=ind+1;
            if(rodLen<=currSize)
                take=price[ind]+dp[ind][currSize-rodLen];
            dp[ind][currSize]=max(take,not_take);
        }
    }
    return dp[n-1][n];
```

---

# longest common subsequence

```cpp
    int solve(int ind1,int ind2,string s1,string s2,vector<vector<int>>& dp){
        if(ind1<0||ind2<0)return 0; // as neg iind not poss // line
        int ans;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2]){
            ans=1+solve(ind1-1,ind2-1,s1,s2,dp);
        }else{
            int ignore1 = 0+ solve(ind1-1,ind2,s1,s2,dp);//ignore letter of s1
            int ignore2 = 0 + solve(ind1,ind2-1,s1,s2,dp);//ignore letter of s2
            ans=max(ignore1,ignore2);
        }
        return dp[ind1][ind2]=ans;

    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return solve(text1.size()-1,text2.size()-1,text1,text2,dp);
    }
```

Tabulation

```cpp
      vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
      // we move one index left because we need to handle line1
      for(int i=0;i<=text1.size();i++)dp[i][0]=0; //line1
      for(int j=0;j<=text2.size();j++)dp[0][j]=0;//line1
      for(int ind1=1;ind1<=text1.size();ind1++){
          for(int ind2=1;ind2<=text2.size();ind2++){
              int ans;
              if(text1[ind1-1]==text2[ind2-1]){
                  ans=1+dp[ind1-1][ind2-1];
              }else{
                  int ignore1 = 0+ dp[ind1-1][ind2];
                  int ignore2 = 0 + dp[ind1][ind2-1];
                  ans=max(ignore1,ignore2);
              }
              dp[ind1][ind2]=ans;
          }
      }
      return dp[text1.size()][text2.size()];
```

## Printing LCS

```cpp
        int i=text1.size(),j=text2.size();
        string ans;
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                ans=text1[i-1]+ans;
                i--;
                j--;
            }else{
                if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }else{
                    j--;
                }
            }
        }
        cout<<ans;
```

---

## Longest common substring

- same as `Longest Common Subsequence` just chnage the part as shown below

```cpp
if(text1[ind1-1]==text2[ind2-1]){
    ans=1+dp[ind1-1][ind2-1];
}else{
  ans=0;
}
dp[ind1][ind2]=ans;
```

## Longest Palindromic Substring( L P S)

- same as `Longest Common Subsequence` just keep s1=orignal and s2 = reversed original

## Minimum insertions to make string palindrome

- find `L P S` and then `string.size() - L P S;`

## Minimum number of insertions and deletions to maake A into B

- number of del = size of A - LCS
- number of ins = size of B - LCS

```cpp
int canYouMake(string &str, string &ptr)
{
    int LCS = LongestCommonSubsequence(str,ptr);
    int number_of_del = str.size() - LCS;
    int number_of_ins = ptr.size() - LCS;
    return number_of_del + number_of_ins;
}
```

## shortest Common supersequence

```cpp
    string lcsString(string text1,string text2,vector<vector<int>> dp){ // to create longest common subseq string using LCS table
        int i=text1.size(),j=text2.size();
        string ans;
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                ans=text1[i-1]+ans;
                i--;
                j--;
            }else{
                if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }else{
                    j--;
                }
            }
        }
        cout<<ans<<endl;
        return ans;
    }
    string lcs(string text1,string text2){ // to gwt lcs table
      vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
      // we move one index left because we need to handle line1
      for(int i=0;i<=text1.size();i++)dp[i][0]=0; //line1
      for(int j=0;j<=text2.size();j++)dp[0][j]=0;//line1
      for(int ind1=1;ind1<=text1.size();ind1++){
          for(int ind2=1;ind2<=text2.size();ind2++){
              int ans;
              if(text1[ind1-1]==text2[ind2-1]){
                  ans=1+dp[ind1-1][ind2-1];
              }else{
                  int ignore1 = 0+ dp[ind1-1][ind2];
                  int ignore2 = 0 + dp[ind1][ind2-1];
                  ans=max(ignore1,ignore2);
              }
              dp[ind1][ind2]=ans;
          }
      }
      return lcsString(text1,text2,dp);

    }
    string shortestCommonSupersequence(string str1, string str2) {
        int a,b;
        string lcsubsequence = lcs(str1,str2);
        int i=str1.size()-1,j=str2.size()-1;
        int len=lcsubsequence.size()-1;
        string ans="";
        while(len>=0){ // for all leters of LCS
            while(lcsubsequence[len]!=str1[i]){ //as all letters till first occurence of LCS letter
                ans=str1[i]+ans;
                i--;
            }
            while(lcsubsequence[len]!=str2[j]){ //as all letters are needed till first occurence of lcs letter
                ans=str2[j]+ans; // need to add any letter before the occurence of lcs letter
                j--;
            }

            ans=lcsubsequence[len]+ans; //including the lcs letter in ans as this is pos it has to be added
            len--;
            i--;
            j--;
        }
        while(i>=0){ //addinng remaining letters left
            ans=str1[i]+ans;
            i--;
        }
        while(j>=0){ //adding remaining letters left
            ans=str2[j]+ans;
            j--;
        }
        return ans;

    }

```

---

# total number of subsequences -- important phases of dp on strings

![](img\distinctsubs.png)

## `first step : Recursion + Memo`

```cpp
    double solve(int ind1,int ind2,string s,string t,vector<vector<double>> &dp){
        //base case
        if(ind2<0)return 1;//as we used up all char of t
        if(ind1<0)return 0; // as we have character in t but all char in s used up
        if(dp[ind1][ind2]!=-1.0)return dp[ind1][ind2];
        int ans = 0;
        if(s[ind1]==t[ind2]){
            double not_use_t = solve(ind1-1,ind2,s,t,dp);  // use char from t
            double use_t = solve(ind1-1,ind2-1,s,t,dp); //not use
            ans = not_use_t + use_t;
        }else{
            //move right to find some other char
            ans = solve(ind1-1,ind2,s,t,dp);
        }
        return dp[ind1][ind2]=ans;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<double>> dp(n,vector<double>(m,-1.0));
        return (int)solve(n-1,m-1,s,t,dp);
    }
```

## `second step : Tabulation` - convert recursion to tabulation

```cpp
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=1; //we
        for(int i=1;i<=m;i++)dp[0][i]=0; // when we have more than equal to 1 t remaining
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                int ans = 0;
                if(s[ind1-1]==t[ind2-1]){
                    double not_use_t = dp[ind1-1][ind2];  // use char from t
                    double use_t = dp[ind1-1][ind2-1]; //not use
                    ans = not_use_t + use_t;
                }else{
                    //move right to find some other char
                    ans = dp[ind1-1][ind2];
                }
                dp[ind1][ind2]=ans;
            }
        }
        return (int)dp[n][m];
    }
```

## `third step : 2d to 1d space optimization`

```cpp
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        // vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        vector<double> prev(m+1,0),curr(m+1,0);
        // for(int i=0;i<=n;i++)dp[i][0]=1; //we
        // for(int i=1;i<=m;i++)dp[0][i]=0; // when we have more than equal to 1 t remaining
        prev[0]=1,curr[0]=1;
        for(int i=1;i<=m;i++)prev[i]=0;
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                int ans = 0;
                if(s[ind1-1]==t[ind2-1]){
                    double not_use_t = prev[ind2];  // use char from t
                    double use_t = prev[ind2-1]; //not use
                    ans = not_use_t + use_t;
                }else{
                    //move right to find some other char
                    ans = prev[ind2];
                }
                curr[ind2]=ans;
            }
            prev=curr;
        }
        return (unsigned int)prev[m];
    }
```

## `fourth step : optimizing the 1d space further`

```cpp
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        // vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        vector<double> prev(m+1,0);
        // for(int i=0;i<=n;i++)dp[i][0]=1; //we
        // for(int i=1;i<=m;i++)dp[0][i]=0; // when we have more than equal to 1 t remaining
        prev[0]=1;
        for(int i=1;i<=m;i++)prev[i]=0;
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=m;ind2>0;ind2--){
                int ans = 0;
                if(s[ind1-1]==t[ind2-1]){
                    double not_use_t = prev[ind2];  // use char from t
                    double use_t = prev[ind2-1]; //not use
                    ans = not_use_t + use_t;
                }else{
                    //move right to find some other char
                    ans = prev[ind2];
                }
                prev[ind2]=ans;
            }
        }
        return (unsigned int)prev[m];
    }
```

---

# Edit distance

```cpp
    int solve(int ind1,int ind2,string s1,string s2, vector<vector<int>>& dp){
        if(ind1<0)return ind2+1; // insert all other characters from s2
        if(ind2<0)return ind1+1; //delete all other characters from s1
        int ans=0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2]){
            ans = solve(ind1-1,ind2-1,s1,s2,dp);
        }else{
            int insert = 1 + solve(ind1,ind2-1,s1,s2,dp);
            int deletech = 1 + solve(ind1-1,ind2,s1,s2,dp);
            int replace = 1 + solve(ind1-1,ind2-1,s1,s2,dp);
            ans=min({insert,deletech,replace});
        }
        return dp[ind1][ind2]=ans;

    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
       return solve(n-1,m-1,word1,word2,dp);
    }
```

# Wildcard Matching

```cpp
    int solve(int ind1,int ind2,string s, string p,vector<vector<int>>& dp){
        if(ind2<0&&ind1<0)return 1;
        if(ind2<0)return 0;//pattern got exhausted but other string has things left
        if(ind1<0){
            for(int i=0;i<=ind2;i++){ //as if everything it has is * it is equivalent to empty string
                if(p[i]!='*')return 0;
            }
            return 1;
        }
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        int ans=0;
        if(s[ind1]==p[ind2]){
            ans=solve(ind1-1,ind2-1,s,p,dp);
        }
        else if(p[ind2]=='?'){
            ans=solve(ind1-1,ind2-1,s,p,dp);
        }else if(p[ind2]=='*'){
            int choice1=solve(ind1,ind2-1,s,p,dp);//ignoring the *
            int choice2=solve(ind1-1,ind2,s,p,dp);// replacing char of t with *
            ans=choice1|choice2;
        }else{
            ans=0;
        }

        return dp[ind1][ind2]=ans;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m= p.size();
        vector<vector<int>> dp(s.size() + 1, vector(p.size() + 1, -1));
        return solve(n-1,m-1,s,p,dp);

    }
```

---

# buy and sell stock 1

```cpp
    int maxProfit(vector<int>& nums) {
        int minsf=nums[0],maxPr=0; // buying and selling on same day
        for(int i=1;i<nums.size();i++){
            int cost =nums[i]-minsf;
            maxPr=max(cost,maxPr);
            minsf=min(nums[i],minsf);
        }
    return maxPr;
    }
```

## `buy and sell stock 2`

```cpp
    int solve(int ind,int canBuy,vector<int>& prices,vector<vector<int>> &dp){
        //base case
        if(ind==prices.size())return 0;
        int ans;
        if(dp[ind][canBuy]!=-1)return dp[ind][canBuy];
        if(canBuy){ //has to buy now not sell
            int buy = -prices[ind] + solve(ind+1,0,prices,dp);//set it to cant buy anymore
            int notBuy = 0 + solve(ind+1,1,prices,dp); //just deciding to not buy now
            ans = max(buy,notBuy);
        }else{
            int sell = prices[ind] + solve(ind+1,1,prices,dp); //set it to can buy
            int notSell = 0 + solve(ind+1,0,prices,dp); // try selling in future not now
            ans=max(sell,notSell);
        }
        return dp[ind][canBuy]=ans;

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
```

`Tabulation`

```cpp
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=0;i<=1;i++)dp[n][i]=0; //base case
        for(int ind=n-1;ind>=0;ind--){
            for(int canBuy=1;canBuy>=0;canBuy--){
                int ans;
                if(canBuy){ //has to buy now not sell
                    int buy = -prices[ind] + dp[ind+1][0];//set it to cant buy anymore
                    int notBuy = 0 + dp[ind+1][1]; //just deciding to not buy now
                    ans = max(buy,notBuy);
                }else{
                    int sell = prices[ind] + dp[ind+1][1]; //set it to can buy
                    int notSell = 0 + dp[ind+1][0]; // try selling in future not now
                    ans=max(sell,notSell);
                }
                dp[ind][canBuy]=ans;
            }
        }
        return dp[0][1];
    }
```

# space optimization

```cpp
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        vector<int> ahead(2,0),curr(2,0);
        // for(int i=0;i<=1;i++)dp[n][i]=0; //base case
        ahead[0]=ahead[1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int canBuy=1;canBuy>=0;canBuy--){
                int ans;
                if(canBuy){ //has to buy now not sell
                    int buy = -prices[ind] + ahead[0];//set it to cant buy anymore
                    int notBuy = 0 + ahead[1]; //just deciding to not buy now
                    ans = max(buy,notBuy);
                }else{
                    int sell = prices[ind] + ahead[1]; //set it to can buy
                    int notSell = 0 + ahead[0]; // try selling in future not now
                    ans=max(sell,notSell);
                }
                curr[canBuy]=ans;
            }
            ahead=curr;
        }
        return ahead[1];
    }
```

---

# stock with cooldown of one day after sell

```cpp
    int solve(int ind,int canBuy,vector<int>& prices,vector<vector<int>> &dp){
        //base case
        if(ind>=prices.size())return 0;
        if(dp[ind][canBuy]!=-1)return dp[ind][canBuy];
        int ans;
        if(canBuy){
            int buy = -prices[ind]+solve(ind+1,0,prices,dp);
            int notBuy = 0 + solve(ind+1,1,prices,dp);
            ans=max(buy,notBuy);
        }else{
            int sell = prices[ind]+solve(ind+2,1,prices,dp);
            int notSell = 0 + solve(ind+1,0,prices,dp);
            ans=max(sell,notSell);
        }
        return dp[ind][canBuy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
```
