## Given a non-negative integer num, return the number of steps to reduce it to zero. If the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
```cpp
//if even you take one step
    //if odd you take one step to make it even then one more step as its even
    int numberOfSteps(int num) {
        if(num==0)return 0;
        int c=0;
        while(num>0)
        {
                c=c+((num&1)==0?1:2);   
            num=num>>1;
        }
        return c-1;
    }
};
```

---
# max xor of 2 numbers in a array
```cpp
    int findMaximumXOR(vector<int>& nums) {
        int maxres=0,mask=0;
        for(int i=31;i>=0;i--){
            unordered_set<int> setforc;
            mask=mask|(1<<i); //1000000000,1100000000000,111000000000000 
            for(int num:nums){
                setforc.insert(mask&num);//we only need the part with that many 1s
            }
            int b=maxres|(1<<i); //this is best estimated result we may get in this cycle
            //eg if previosly max =1[000] in next cycle it will 11[00] for 10[00] =>101[0]
            for(int a:setforc){
                if(setforc.find(a^b)!=setforc.end()){
                    maxres=b; //a^b=c so a and c are the numbers as a^c=b == a^b=c
                }
            }
            
        }
        return maxres;
    }
};
/*
 (a&B) => a= 1001 b=1011 a&b=1001 so 11000 & 10000 =10000 so we get only the left most part which has 1
 b=maxres| 1<<i  => lets say max result in i+1th cycle =10[....] the max in ith cycle will be 101[.....]
 this above is expected so we search for a number c by xoring a and b a=are all numbers we found with mask 
 b=is the expected max in this cycle as ith bit can have either 1 or 0 
 propert : A ^ B = C  A^C=B      so we need to find max A ^ C 
 */
```
---