```
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
```
top down
```cpp
    int climbStairs(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        if(n==2)return 2;
        if(mp[n]!=0)return mp[n];
        return mp[n]=climbStairs(n-1)+climbStairs(n-2);
    }
```
- we know you can climb stair 1 in 1 way and 2 in 2 ways (2,(1,1))

---
# bottom up
```cpp
public int climbStairs(int n) {
    // base cases
    if(n <= 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;
    
    int one_step_before = 2;
    int two_steps_before = 1;
    int all_ways = 0;
    
    for(int i=2; i<n; i++){
    	all_ways = one_step_before + two_steps_before;
    	two_steps_before = one_step_before;
        one_step_before = all_ways;
    }
    return all_ways;
}
```
