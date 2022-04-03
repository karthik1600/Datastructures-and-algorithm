## NQueens
```c++
    vector<vector<string>> strv;
  void solve(vector<string>& ind,int row,vector<int>& col,vector<int>& ld,vector<int>& rd,vector<vector<string>>& ans,int n)
    {
        if(row>=n){
            ans.push_back(ind);
            return;
        }
        for(int i=0;i<n;i++){
            if(col[i]==0&&rd[row+i]==0&&ld[row-i+n-1]==0){
                ld[row-i+n-1]=1;
                rd[row+i]=1;
                col[i]=1;
                ind[row][i]='Q';
                solve(ind,row+1,col,ld,rd,ans,n);
                ind[row][i]='.';
                col[i]=0;
                ld[row-i+n-1]=0;
                rd[row+i]=0;
            }
        }
        
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col(n,0),ld(2*n,0),rd(2*n,0);
        vector<vector<string>> ans;
        string s="";
        for(int i=0;i<n;i++)s.push_back('.');
        vector<string> ind(n,s);
        solve(ind,0,col,ld,rd,ans,n);
        return ans;
    }
```
implementation of branch and bound theory

---
# combination sum 1
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The `same number may be chosen from candidates an unlimited number of times`. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
```
```cpp
void helper(vector<int>& candidates, int& target,vector<int>& ar,vector<vector<int>>& ans,int st){
	if(target==0){ //if target reached
		ans.push_back(ar);
		return;
	}
	for(int i=st;i<candidates.size();i++){
		if(target>=candidates[i]){
            //including ele
				ar.push_back(candidates[i]);
				target=target-candidates[i];
				helper(candidates,target,ar,ans,i);
            //excluding ele
				target=target+candidates[i];
				ar.pop_back();
		}
		else{
			return;
		}
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> ans;
    vector<int> ar;
   	helper(candidates,target,ar,ans,0);
    return ans;
}
```
![](img\combsum.png)

---
# combnation sum2
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

`Each number in candidates may only be used once in the combination.`

Note:` The solution set must not contain duplicate combinations.`
```
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],[1,2,5],[1,7], 
[2,6]
]
```
`here we ignore one 1 in recursion or we get [1,2,7] and [1,7] again`
```cpp
void helper(vector<int>& candidates, int& target,vector<int>& ar,vector<vector<int>>& ans,int st){
	if(target==0){ 
		ans.push_back(ar);
		return;
	}
	for(int i=st;i<candidates.size();i++){
        
		if(target>=candidates[i]){
                //check for duplicate if i>st then prev ele is excluded and this ele is duplicate and will produce duplicate
                if(i>st&&candidates[i]==candidates[i-1])continue;
				ar.push_back(candidates[i]);
				target=target-candidates[i];
				helper(candidates,target,ar,ans,i+1);
				target=target+candidates[i];
				ar.pop_back();
		}
		else{
			return;
		}
	}
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> ans;
    vector<int> ar;
   	helper(candidates,target,ar,ans,0);
    return ans;
}
```
![](img\combsum2.png)

---
# palindrome partiotion

```
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
```
```cpp
    bool isPalindrome(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(string s,vector<vector<string>> &ans,vector<string> &ind,int index){
        if(index==s.size()){
            ans.push_back(ind);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                ind.push_back(s.substr(index,i-index+1));
                helper(s,ans,ind,i+1);
                ind.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> ind;
        vector<vector<string>> ans;
        helper(s,ans,ind,0);
        return ans;
    }
```
![](img\palindromepart.png)

---
# sudoku solve
```cpp
bool check(vector<vector<char>> &board, int i, int j, char val)
{
    int row = i - i%3, column = j - j%3;
    for(int x=0; x<9; x++) if(board[x][j] == val) return false;//check that row
    for(int y=0; y<9; y++) if(board[i][y] == val) return false;//check that column
    for(int x=0; x<3; x++)
    for(int y=0; y<3; y++)
        if(board[row+x][column+y] == val) return false;//check the cube
    return true;
}
    bool solve(vector<vector<char>>& board,int row,int col){
        if(row==9)return true;
        if(col==9)return solve(board,row+1,0); //if you last col of row so go to next row 
        if(board[row][col]!='.')return solve(board,row,col+1);//if already filled so checck next column
        for(char c='1';c<='9';c++){
            if(check(board,row,col,c)){
                board[row][col]=c;
                if(solve(board,row,col+1))return true;//check next ele
                board[row][col]='.';
            }
    }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
       solve(board,0,0);
    }
```
- we can make hashed row and col and cube as it takes constant space with 9 ele max
```cpp
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int d = board[r][c];
                    row[r][d] = 1; col[c][d] = 1; cube[r/3][c/3][d] = 1;
                }
            }
        }
````
then we can change check to 
```cpp
    bool check(vector<vector<char>>& board, int r, int c, char val)
    {
        if(row[r][val] == 1) return false;
        if(col[c][val] == 1) return false;
        if(cube[r/3][c/3][val] == 1) return false;
        return true;
    }

```
```cpp
    int row[9][256], col[9][256], cube[3][3][256];
    bool check(vector<vector<char>>& board, int r, int c, char val)
    {
        if(row[r][val] == 1) return false;/////////////
        if(col[c][val] == 1) return false;////////////
        if(cube[r/3][c/3][val] == 1) return false;//////////
        return true;
    }
    bool solve(vector<vector<char>>& board,int i,int j){
        if(i==9)return true;
        if(j==9)return solve(board,i+1,0);
        if(board[i][j]!='.')return solve(board,i,j+1);
        for(char c='1';c<='9';c++){
            if(check(board,i,j,c)){
                board[i][j]=c;
                ////////////////////////////
                row[i][c] = 1; col[j][c] = 1; cube[i/3][j/3][c] = 1;
                if(solve(board,i,j+1))return true;
                board[i][j] = '.';
                ////////////////////////////
                row[i][c] = 0; col[j][c] = 0; cube[i/3][j/3][c] = 0;
            }
    }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(cube,0,sizeof(col));
        for (int r = 0; r < 9; r++) {////////////////////////////
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int d = board[r][c];
                    row[r][d] = 1; col[c][d] = 1; cube[r/3][c/3][d] = 1;
                }
            }
        }
       solve(board,0,0);
    }
```
---
# get kth permuatation
```
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
```
```cpp
    string getPermutation(int n, int k) {
        int factorial[n+1];
        string ans="";
        factorial[0]=1;
        vector<string> nums;
        for(int i=1;i<=n;i++){
            string c=to_string(i);
            nums.push_back(c);
        }
        for(int i=1;i<=n;i++){
            factorial[i]=factorial[i-1]*i;
        }
        for(int i=1;i<=n;i++){
            int index=k/factorial[n-i];
            if(k%factorial[n-i]==0){ 
                // as that ele is the last ele in prev permutation 6th in permuation of 4 [ ele [permutation of 3]] 3!=6
                //so each digit starts a permuation of size 6 so if 6 index=1 but index=0 for first digit
                index--;
            }
            ans=ans+nums[index];
            nums.erase(nums.begin()+index);
            k=k-index*factorial[n-i]; //eg 15/6=2 this is permuation with ele starting with 3 k=15-2*f(n-i-1) =15-2*6=3rd largest in that 
        }
        return ans;
    }
```
[](https://leetcode.com/problems/permutation-sequence/discuss/696595/C%2B%2B-or-Very-Easy-and-Detailed-Explanation-(Idea-%2B-code))
using back tracking
```cpp
bool helper(vector<string> nums,vector<int>& vis,int& n,string& ans,int& k){
    if(n==0){
        k--;
        if(k==0)
            return true;//when you reach kth you go back 
        else 
            return false;
    }
    for(int i=0;i<nums.size();i++){
        if(!vis[i]){
            ans=ans+nums[i];
            n--;
            vis[i]=1;
            if(helper(nums,vis,n,ans,k))return true;//check if helper gives kth ele
            n++;
            vis[i]=0;
            ans.pop_back();
        }
    }
    return false;
}
string getPermutation(int n, int k) {
    vector<string> nums;
    for(int i=0;i<n;i++){
        string c=to_string(i+1);
        nums.push_back(c);
    }
    vector<int> vis(n,0);
    string ans="";
    helper(nums,vis,n,ans,k);
    return ans;
}
```
---
# m colororing
```cpp
bool isSafe(bool graph[101][101],int V,vector<int> col,int node,int color){
	for(int i=0;i<V;i++){
        //i not node
        //has an edge to node so g[node][i]==1
        //check if some node connected to the the curr node has that color already then its false and that color not possible 
		if(i!=node&&graph[node][i]&&col[i]==color)return false;
	}
	return true;
}
bool solve(bool graph[101][101], int m, int V,vector<int>& col,int node)
{
	if(node==V){
		return true;
	}
	for(int i=1;i<=m;i++){
		if(isSafe(graph,V,col,node,i)){//check if any connected node has that given color
			col[node]=i;//colors the node
			if(solve(graph,m,V,col,node+1))return true;//checks if it is possible to m color the graph with curr noe as i
			col[node]=0;//if not possible recur
		}
	}
	return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> col(V,0);
    return solve(graph,m,V,col,0);
}
```
![](https://apprize.best/science/algorithms/algorithms.files/image614.jpg)

---
# Rat in a maze 
```cpp
/*
1) if either x or y -ve
2) if either x or y above n
3) if already visited before
4) if you dont have any path here as m[x][y]=0
*/
    bool isSafe(vector<vector<int>> m,int n,int x,int y,vector<vector<int>> vis){
        if(x<0||x>n-1||y<0||y>n-1||vis[x][y]==1||m[x][y]==0){
            return false;
        }
        return true;
    }
    void helper(vector<vector<int>> &m,int n,int x,int y,string& path,vector<vector<int>>& vis,vector<string>& ans){
        if(x==n-1&&y==n-1){ //check if you have reached destinatcion
            ans.push_back(path);
            return;
        }
        if(isSafe(m,n,x+1,y,vis)){
            vis[x+1][y]=1;
            path=path+"D";
            helper(m,n,x+1,y,path,vis,ans);
            path.pop_back();
            vis[x+1][y]=0;
        }
        if(isSafe(m,n,x,y-1,vis)){
            vis[x][y-1]=1;
            path=path+"L";
            helper(m,n,x,y-1,path,vis,ans);
            path.pop_back();
            vis[x][y-1]=0;
        }
        if(isSafe(m,n,x,y+1,vis)){
            vis[x][y+1]=1;
            path=path+"R";
            helper(m,n,x,y+1,path,vis,ans);
            path.pop_back();
            vis[x][y+1]=0;
        }
        if(isSafe(m,n,x-1,y,vis)){
            vis[x-1][y]=1;
            path=path+"U";
            helper(m,n,x-1,y,path,vis,ans);
            path.pop_back();
            vis[x-1][y]=0;
        }



    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<string> ans;
        string path="";
        //check if initial position and ending position safe
        if(!isSafe(m,n,0,0,vis)||!isSafe(m,n,n-1,n-1,vis))return ans;
        vis[0][0]=1;
        helper(m,n,0,0,path,vis,ans);
        return ans;
    }
```
---