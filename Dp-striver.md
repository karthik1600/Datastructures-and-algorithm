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
