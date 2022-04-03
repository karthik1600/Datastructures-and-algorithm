# Arrays

- 1. `Largest no. by joining all elements of array`

```C++
#include <bits/stdc++.h>
using namespace std;
int comparefun(string x,string y){ //comaparator func
	string xy=x.append(y);
	string yx=y.append(x);
	if(xy.compare(yx)>0)
		return 1;
	else
		return 0;
}
void largest(vector<string> n)
{
	sort(n.begin(),n.end(),comparefun);
	for(int i=0;i<n.size();i++)
	{
		cout<<n[i];
	}

}
int main()
{
	int n,tn;
	vector<string> s;
	cout<<"input";
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>tn;
		s.push_back(to_string(tn));//to convert no.to string
	}
	largest(s);
}
```

---

## rotate array 90 degrees

```c++
void rotate(vector<vector<int>>& matrix) {
        int temp;
        int n=matrix.size();
        for(int i=0;i<n/2;i++)//no. of squares
        {
            for(int j=i;j<matrix.size()-i-1;j++)//till second last element in a row
            {
                temp=matrix[i][j];
                matrix[i][j]=matrix[n-j-1][i];
                matrix[n-j-1][i]=matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
                matrix[j][n-i-1]=temp;
            }
        }
    }
};
```

---

## Next Permutation

```C++
void nextPermutation(vector<int>& v) {
        if(v.size()==1)return;
        int iter=v.size()-1;
        while(iter!=0&&v[iter]<=v[iter-1])//till n2<n1
        {								  //n2,n1,...]
         iter--;
        }
        int t=iter;
        int n=v.size()-1;

        while(t<n)  //reversing n1,...]=>....,n1]
        {
            swap(v[t],v[n]);
            t++;
            n--;
        }
        if(iter==0)return;
        for(int i=iter;i<v.size();i++)   //search for ele where n2>e
        {
            if(v[iter-1]<v[i]){
                swap(v[iter-1],v[i]);
                    break;
            }
        }

    }
```

---

## to replace space with %$\*

```c++
void urlify(string str)
{
	int c=0;
	for(auto s:str)
	{
		if(s==' ')
		{
			c++;
		}
	}
	int len=str.length()+c*2-1;
	int n=str.length();
	str.resize(len,'*');
	for(int i=n-1;i>=0;i--)
	{
		if(str[i]==' ')
		{
			str[len]='#';
			str[len-1]='$';
			str[len-2]='^';
			len=len-3;
		}
		else
		str[len--]=str[i];
	}
	cout<<str;
}
```

---

# Moores voting algorith for ,ajority element

```c++
int majorityElement(int a[], int size)
{
     int maj=a[0],c=1;
    for(int i=0;i<size;i++)
    {
        if(maj==a[i]){
            c++;
        }
        else{
            c--;
            if(c==0)
            {
                maj=a[i];
                c++;

            }
        }
    }
    c=0;
    for(int i=0;i<size;i++)
    {
        if(maj==a[i])c++;
    }
    return c>size/2?maj:-1;
}
//as for maj ele c>1 till to keep it maj

//2nd approach
public int majorityElement1(int[] nums) {
    Arrays.sort(nums);
    return nums[nums.length/2];
}
```

---

## minimum window subsequence

```c++
    string minWindow(string s, string t) {
        int asciiStr[256]={0},asciiPtr[256]={0};
        for(int i=0;i<t.size();i++)
            asciiPtr[t[i]]++;
        int start=0,windowstart=-1,count=0,minlen=INT_MAX;
        for(int i=0;i<s.size();i++)
        {
            asciiStr[s[i]]++;
            if(asciiPtr[s[i]]!=0 && asciiStr[s[i]]<=asciiPtr[s[i]]) //checks if ele present in pattern and should be less than if more thaan no need to inc
            {
                 count++;
            }
            if(count==t.size())
            {
                while(asciiStr[s[start]]>asciiPtr[s[start]]||asciiPtr[s[start]]==0)
                {
                    asciiStr[s[start]]--;
                    start++;
                }
                int len_window=i-start+1;
                if(minlen>len_window)
                {
                    minlen=len_window;
                    windowstart=start;
                }
            }
        }

        return s.substr(windowstart,minlen);
    }
```

---

## `Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.`

```c++
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> cnt;
        for (int x : arr) cnt[x]++;

        for (int x : arr) {
            if (cnt[x] == 0) continue;
            if (x < 0 && x % 2 != 0) return false; // For example: arr=[-5, -2, 1, 2], x = -5, there is no x/2 pair to match
            int y = x > 0 ? x*2 : x/2;
            if (cnt[y] == 0) return false; // Don't have the corresponding `y` to match with `x` -> Return IMPOSSIBLE!
            cnt[x]--;
            cnt[y]--;
        }
        return true;
    }
```

here arr[2*i+1]=arr[x+1] where x=2i

---

## continuos subarray which contains sum equal to k

```c++
int subArraySum(int arr[], int n, int sum)
{
    int curr_sum, i, j;

    // Pick a starting point
    for (i = 0; i < n; i++) {
        curr_sum = arr[i];

        // try all subarrays starting with 'i'
        for (j = i + 1; j <= n; j++) {
            if (curr_sum == sum) {
                cout << "Sum found between indexes "
                     << i << " and " << j - 1;
                return 1;
            }
            if (curr_sum > sum || j == n)
                break;
            curr_sum = curr_sum + arr[j];
        }
    }

    cout << "No subarray found";
    return 0;
}
```

or

- Create three variables, l=0, sum = 0
- Traverse the array from start to end.
- Update the variable sum by adding current element, sum = sum + array[i]
- If the sum is greater than the given sum, update the variable sum as sum = sum – array[l], and update l as, l++.
- If the sum is equal to given sum, print the subarray and break the loop.
  for o(n)

---

## Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

```c++
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> map;

		map[0] = 1;//when
		int sum = 0;
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];

			if (map.find(sum - k) != map.end()) { //sum exceeds k
				count += map[sum-k];
			}
			map[sum]++;
		}

		return count;
	}
```

---

## longest substring with different characters

```c++
int longestUniqueSubsttr(string s)
{

    // Creating a set to store the last positions
    // of occurrence
    map<char, int> seen ;
    int maximum_length = 0;

    // Starting the initial point of window to index 0
    int start = 0;

    for(int end = 0; end < s.length(); end++)
    {

        // Checking if we have already seen the element or
        // not
        if (seen.find(s[end]) != seen.end())
        {

            // If we have seen the number, move the start
            // pointer to position after the last occurrence
            //if last position is before start we ignore it therefor we take max of start and last seen + 1
            start = max(start, seen[s[end]] + 1);
        }

        // Updating the last seen value of the character
        seen[s[end]] = end;
        maximum_length = max(maximum_length,
                             end - start + 1);
    }
    return maximum_length;
}
```

---

## Check if frequency of all characters can become same by one removal

```cpp
int getIdx(char ch)
{
    return (ch - 'a');
}

// Returns true if all non-zero elements
// values are same
bool allSame(int freq[], int N)
{
    int same;

    // get first non-zero element
    int i;
    for (i = 0; i < N; i++) {
        if (freq[i] > 0) {
            same = freq[i];
            break;
        }
    }

    // check equality of each element with variable same
    for (int j = i + 1; j < N; j++)
        if (freq[j] > 0 && freq[j] != same)
            return false;

    return true;
}

// Returns true if we can make all character
// frequencies same
bool possibleSameCharFreqByOneRemoval(string str)
{
    int l = str.length();

    // fill frequency array
    int freq[M] = { 0 };
    for (int i = 0; i < l; i++)
        freq[getIdx(str[i])]++;

    // if all frequencies are same, then return true
    if (allSame(freq, M))
        return true;

    /*  Try decreasing frequency of all character
        by one and then    check all equality of all
        non-zero frequencies */
    for (char c = 'a'; c <= 'z'; c++) {
        int i = getIdx(c);

        // Check character only if it occurs in str
        if (freq[i] > 0) {
            freq[i]--;

            if (allSame(freq, M))
                return true;
            freq[i]++;
        }
    }

    return false;
}
```

---

## min no of refuels

![question](img\leetcode-minnoofrefule.png)

```
        int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int ret = 0, stationId = 0, range = startFuel;
        while (range < target) {
            //to check if the station is within range
            while (stationId < stations.size() && stations[stationId][0] <= range)
            {
                pq.push(stations[stationId++][1]);
            }
            if (pq.empty()) return -1;
            range += pq.top();
            pq.pop();
            ++ret;
        }
        return ret;
    }
```

---

## k anagram

`Given two strings of lowercase alphabets and a value k, the task is to find if two strings are K-anagrams of each other or not. Two strings are called k-anagrams if following two conditions are true. Both have same number of characters. Two strings can become anagram by changing at most k characters in a string.`

```cpp
bool areKAnagrams(string str1, string str2, int k)
{
    // If both strings are not of equal
    // length then return false
    int n = str1.length();
    if (str2.length() != n)
        return false;

    int hash_str1[MAX_CHAR] = {0};

    // Store the occurrence of all characters
    // in a hash_array
    for (int i = 0; i < n ; i++)
        hash_str1[str1[i]-'a']++;

    // Store the occurrence of all characters
    // in a hash_array
    int count = 0;
    for (int i = 0; i < n ; i++)
    {
        if (hash_str1[str2[i]-'a'] > 0)
            hash_str1[str2[i]-'a']--;
        else
            count++;

        if (count > k)
            return false;
    }

    // Return true if count is less than or
    // equal to k
    return true;
}
```

---

## Given a number ‘n’, find the smallest number ‘p’ such that if we multiply all digits of ‘p’, we get ‘n’. The result ‘p’ should have minimum two digits.

```c++
void findSmallest(int n)
{
    int i, j = 0;

    // To store digits of result
    // in reverse order
    int res[MAX];

    // Case 1: If number is smaller than 10
    if (n < 10)
    {
        cout << n + 10;
        return;
    }

    // Case 2: Start with 9 and
    // try every possible digit
    for (i = 9; i > 1; i--)
    {
        // If current digit divides n, then store all
        // occurrences of current digit in res
        while (n % i == 0)
        {
            n = n / i;
            res[j] = i;
            j++;
        }
    }

    // If n could not be broken
    // in form of digits (prime factors
    // of n are greater than 9)
    if (n > 10)
    {
        cout << "Not possible";
        return;
    }

    // Print the result array in reverse order
    for (i = j - 1; i >= 0; i--)
        cout << res[i];
}
```

---

## group anagrams

![img](img\groupanagrams.png)

```cpp
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> res;
        for(auto str :strs )
        {
            string s;
            vector<int> count(26,0);
            for(int i=0;i<str.size();i++)
            {
                count[str[i]-'a']++;

            }
            for(int i=0;i<26;i++)
            {
                s=s+"#";
                s=s+to_string(count[i]);
            }
            m[s].push_back(str);
        }
        for(auto st:m)
        {
            res.push_back(st.second);
        }
            return res;
    }
```

---

## isomeric strings

![img](img\isomericstring.png)

```cpp
bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;//because when first char is replaced we will get 0 itself if we put i instead of i+1
            m2[t[i]] = i + 1;
        }
        return true;
    }
```

---

## check is ap

Given an array of n integers. The task is to check whether an arithmetic progression can be formed using all the given elements. If possible print “Yes”, else print “No”.

```cpp
bool checkIsAP(int arr[], int n)
{
    unordered_map<int, int> hm;
    int smallest = INT_MAX, second_smallest = INT_MAX;
    for (int i = 0; i < n; i++) {

        // Find the smallest and and
        // update second smallest
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        }

        // Find second smallest
        else if (arr[i] != smallest
                 && arr[i] < second_smallest)
            second_smallest = arr[i];

        // Check if the duplicate element found or not
        if (hm.find(arr[i]) == hm.end())
            hm[arr[i]]++;

        // If duplicate found then return false
        else
            return false;
    }

    // Find the difference between smallest and second
    // smallest

    int diff = second_smallest - smallest;

    // As we have used smallest and
    // second smallest,so we
    // should now only check for n-2 elements
    for (int i = 0; i < n - 1; i++) {
        if (hm.find(second_smallest) == hm.end())
            return false;
        second_smallest += diff;
    }
    return true;
}
```

---

## div by 4 pairs

Given a array if ‘n’ positive integers. Count number of pairs of integers in the array that have the sum divisible by 4.

```cpp
int count4Divisibiles(int arr[], int n)
{
    // Create a frequency array to count
    // occurrences of all remainders when
    // divided by 4
    int freq[4] = {0, 0, 0, 0};

    // Count occurrences of all remainders
    for (int i = 0; i < n; i++)
        ++freq[arr[i] % 4];

    // If both pairs are divisible by '4'
    int ans = freq[0] * (freq[0] - 1) / 2;

    // If both pairs are 2 modulo 4
    ans += freq[2] * (freq[2] - 1) / 2;

    // If one of them is equal
    // to 1 modulo 4 and the
    // other is equal to 3
    // modulo 4
    ans += freq[1] * freq[3];

    return ans;
}
```

Efficient approach is to use Hashing technique. There are only three condition that can arise whose sum is divisible by ‘4’ i.e,

If both are divisible by 4.
If one of them is equal to 1 modulo 4 and other is 3 modulo 4. For instance, (1, 3), (5, 7), (5, 11).
If both of them is equal to 2 modulo 4 i.e., (2, 2), (2, 6), (6, 10)

---

## div by k

similar to above div by 4
for second condition in above we replace with third statement below

```cpp
int countKdivPairs(int A[], int n, int K)
{
    // Create a frequency array to count
    // occurrences of all remainders when
    // divided by K
    int freq[K] = { 0 };

    // Count occurrences of all remainders
    for (int i = 0; i < n; i++)
        ++freq[A[i] % K];

    // If both pairs are divisible by 'K'
    int sum = freq[0] * (freq[0] - 1) / 2;

    // count for all i and (k-i)
    // freq pairs
    for (int i = 1; i <= K / 2 && i != (K - i); i++)//we put condition i!=k-i as we do that in third statement
        sum += freq[i] * freq[K - i];
    // If K is even
    if (K % 2 == 0)
        sum += (freq[K / 2] * (freq[K / 2] - 1) / 2);
    return sum;
}
```

---

## Given an array, A. Let x be an element in the array. x has the maximum frequency in the array. Find the smallest subsegment of the array which also has x as the maximum frequency element.

```cpp
void smallestSubsegment(int a[], int n)
{
    // To store left most occurrence of elements
    unordered_map<int, int> left;

    // To store counts of elements
    unordered_map<int, int> count;

    // To store maximum frequency
    int mx = 0;

    // To store length and starting index of
    // smallest result window
    int mn, strindex;

    for (int i = 0; i < n; i++) {

        int x = a[i];

        // First occurrence of an element,
        // store the index
        if (count[x] == 0) {
            left[x] = i;
            count[x] = 1;
        }

        // increase the frequency of elements
        else
            count[x]++;

        // Find maximum repeated element and
        // store its last occurrence and first
        // occurrence
        if (count[x] > mx) {
            mx = count[x];
            mn = i - left[x] + 1; // length of subsegment
            strindex = left[x];
        }

        // select subsegment of smallest size
        else if (count[x] == mx && i - left[x] + 1 < mn) {
            mn = i - left[x] + 1;
            strindex = left[x];
        }
    }

    // Print the subsegment with all occurrences of
    // a most frequent element
    for (int i = strindex; i < strindex + mn; i++)
        cout << a[i] << " ";
}
```

---

## Tricky sorting

![im](img\trickysorting.png)

```cpp
int lcss(int arr[],int n){
        unordered_map<int,int> mp;
        int max_count=0;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i]-1)==mp.end()){
                mp[arr[i]]++;
            }
            else{
                mp[arr[i]]=mp[arr[i]-1]+1;
                max_count=std::max(max_count,mp[arr[i]]);
            }
        }
        return max_count;
    }
    int sortingCost(int N, int arr[]){
        return N-(lcss(arr,N));
    }
```

find maximum subsequence with increasing order then subtract it with N

---

## Kth Smallest Element in a Sorted Matrix

![im](img\kthsmallestinsortedmatrix.png)

```cpp
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(n == 0)return -1;
        int low = matrix[0][0], high = matrix[n-1][n-1], ans = -1;
        while(low <= high){
            int mid = low + ((high-low)>>1);
            int count = 0;
            for(int i = 0; i < n; ++i){
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin(); // stl is very helpful
            }
            if(count < k){
                low = mid+1;
            }
            else if(count == k){ // storing the mid as the ans because this mid can be or not in the matrix
                ans = mid;
                high = mid-1;
            }
            else if(count > k) { // to understand why ans is stored this time, use this eg: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 7, the reason is due to multiple occurences of 13, count will remain 8 finally so ans = -1
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
```

upperbound returns the no. of numbers smaller than given no.

---

## brick

![im](img\brick1.png)

```cpp
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall)
    {
        unordered_map<int, int> edge_frequency;     //HashMap to store the number of common edges among the rows

        int max_frequency = 0;         //Variable to store the frequency of most occuring edge

        for(int row=0; row<wall.size(); row++)        //Iterating through each row
        {
            int edge_postion = 0;       //Variable to store different edge postion

            for(int brick_no=0; brick_no< wall[row].size() -1; brick_no++)    //Iterating through each brick inside a row
            {
                int current_brick_length = wall[row][brick_no];  //Length of the current brick

                edge_postion = edge_postion + current_brick_length ;  //Next Edge Position = Previous Edge Position + Current Brick's Length

                edge_frequency[edge_postion]++;  //Incrementing the Frequency of just calculated Edge Postion

                max_frequency = max(edge_frequency[edge_postion],max_frequency);  //Comparing the "Frequency of just calculated Edge Postion" with "Max Frequency seen till now" & storing whichever is greater.
            }
        }
        return wall.size() - max_frequency; // returning (Number of Bricks Crossed by Line) i.e. (Number of Rows in Wall - Frequency of Most Occuring Edge)
    }
};
```

intiution

![im](img\brick2.png)

---

## array pair divisibility by k

Given an array of integers arr of even length n and an integer k.

We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

Return True If you can find a way to do that or False otherwise.

```cpp
    bool canArrange(vector<int>& arr, int k) {
        if(arr.size()&1) return false;
        unordered_map<int,int>m;
        for(auto x:arr) m[(x%k + k)%k]++;          //store the count of remainders in a map.
        for(auto x:arr)
        {
            int rem=(x%k + k)%k;
            if(rem==0)                         //if the remainder for an element is 0 then the count of numbers that give this remainder must be even.
            {
                if(m[rem] & 1) return false;            //if count of numbers that give this remainder is odd all pairs can't be made hence return false.
            }
            else if(m[rem] != m[k - rem]) return false;    //if the remainder rem and k-rem do not have the same count then pairs can not be made
        }
        return true;
    }
};
```

---

## fraction to recurring decimal

![im](img\recurdec.png)

```cpp
 string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) {
            return "0";
        }
        string ans;
        if (numerator > 0 ^ denominator > 0) {
            ans += '-';
        }
        long n = labs(numerator), d = labs(denominator), r = n % d;
        ans += to_string(n / d);
        if (!r) {
            return ans;
        }
        ans += '.';
        unordered_map<long, int> rs;
        while (r) {
            if (rs.find(r) != rs.end()) {
                ans.insert(rs[r], "(");
                ans += ')';
                break;
            }
            rs[r] = ans.size();
            r *= 10;
            ans += to_string(r / d);
            r %= d;
        }
        return ans;
    }
```

---

## Insert Delete GetRandom O(1)

![i](<img\insdel-o(1).png>)

```cpp
class RandomizedSet {
    vector<int> numberList;
    unordered_map<int, int> hashTable;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hashTable.find(val) != hashTable.end())
        {
            return false;
        }
        hashTable[val] = numberList.size();
        numberList.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hashTable.find(val) == hashTable.end())
        {
            return false;
        }
        swap(numberList[hashTable[val]], numberList[numberList.size() - 1]);
        numberList.pop_back();
        hashTable[numberList[hashTable[val]]] = hashTable[val];
        hashTable.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return numberList[rand() % numberList.size()];
    }
};
```

---

## incomplete array

Given an array A containing N integers.Find out how many elements should be added such that all elements between the maximum and minimum of the array is present in the array.

```cpp
    int countElements(int n, int arr[]) {
        if(n==1)
        return 0;
        unordered_set<int> S;
        int max=arr[0];
        int min=arr[0];
        S.insert(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i]>max)
            max=arr[i];

            if(arr[i]<min)
            min=arr[i];

            S.insert(arr[i]);
        }
        if(max==min)
        return 0;
        return max-min-1-S.size()+2;  //-2 is for excluding max min
    }
};
```

---

## long press

![im](img\keyboardmash.png)

```cpp
    bool isLongPressedName(string name, string typed) {

        int i=0, j=0;
        while(i<name.size())
        {
            if(name[i]==typed[j])
            {
                j++;
                i++;
            }
            else
            {
                if((j-1>=0&&typed[j]!=typed[j-1])||j==0)
                {
                    return 0;
                }
                j++;
            }
        }

        /*
		For the Test cases like:
		"alex"
        "alexxp"
		*/

        while(j<typed.size())
        {
            if(typed[j]!=typed[j-1])
                return 0;
            j++;
        }
        return 1;
    }
```

---

Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

For example,
Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
Output: [-2,0,3,5,3]
![im](img\range.png)

---

## next greatest no.

![im](img\nextgreatestno.png)

```cpp
int nextGreaterElement(int n) {
    string s = to_string(n);
    int i = s.size() - 2;
    // start from right
    // find the number x which is smaller than the next one
    for(; i >= 0; i--){
        if(s[i] < s[i + 1]) break;
    }
    // if it doesn't exist, return -1
    if(i < 0) return -1;
    // find the number x' in the right side which is just greater than x
    for(int j = s.size() - 1; j > i; j--){
        if(s[j] > s[i]){
            swap(s[i], s[j]);
            break;
        }
    }
    // reverse right side to make it in increasing order
    reverse(s.begin() + i + 1, s.end());
    long res = stol(s);
    return res > INT_MAX? -1 : res;
}
```

---

## maximum subarray sum

`dp`

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, smax = INT_MIN;
        for (int num : nums) {
            sum += num;
            smax = max(smax, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return smax;
    }
};
```

`div and conq`

```cpp
  int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
private:
    int maxSubArray(vector<int>& nums, int l, int r) {
        if (l > r) {
            return INT_MIN;
        }
        int m = l + (r - l) / 2, ml = 0, mr = 0;
        int lmax = maxSubArray(nums, l, m - 1);
        int rmax = maxSubArray(nums, m + 1, r);
        for (int i = m - 1, sum = 0; i >= l; i--) {
            sum += nums[i];
            ml = max(sum, ml);
        }
        for (int i = m + 1, sum = 0; i <= r; i++) {
            sum += nums[i];
            mr = max(sum, mr);
        }
        return max(max(lmax, rmax), ml + mr + nums[m]);
    }
```

---

## rotate array

![](img\rotatearray.png)

```cpp
void leftRotate(int arr[], int d, int n)
{
    if (d == 0)
        return;
    // in case the rotating factor is
    // greater than array length
    d = d % n;

    reverseArray(arr, 0, d - 1);
    reverseArray(arr, d, n - 1);
    reverseArray(arr, 0, n - 1);
}
```

---

## remove duplicates in sorted array

```cpp
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                count++;
            }
            else
            {
                nums[i-count]=nums[i];
            }
        }
        return nums.size()-count;
    }
```

---

## deck of cards

![](img\deckofcards.png)

```cpp
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        int res = 0;
        for (int i : deck) count[i]++;
        for (auto i : count) res = __gcd(i.second, res);
        return res > 1;
    }
```

---

## merge k sorted array

Given K sorted arrays arranged in the form of a matrix of size K\*K. The task is to merge them into one sorted array.

```cpp
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int> v;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                v.push_back(arr[i][j]);
            }
        }
        sort(v.begin(),v.end());
        return v;
        //code here
    }
```

---

# Rearrange characters in a string such that no two adjacent are same

![](img\rearrangechar.png)

```cpp
void rearrangeString(string str)
{
    int n = str.length();

    // Store frequencies of all characters in string
    int count[MAX_CHAR] = { 0 };
    for (int i = 0; i < n; i++)
        count[str[i] - 'a']++;

    // Insert all characters with their frequencies
    // into a priority_queue
    priority_queue<Key> pq;
    for (char c = 'a'; c <= 'z'; c++) {
          int val = c - 'a';
        if (count[val]) {
            pq.push(Key{ count[val], c });
        }
    }

    // 'str' that will store resultant value
    str = "";

    // work as the previous visited element
    // initial previous element be. ( '#' and
    // it's frequency '-1' )
    Key prev{ -1, '#' };

    // traverse queue
    while (!pq.empty()) {
        // pop top element from queue and add it
        // to string.
        Key k = pq.top();
        pq.pop();
        str = str + k.ch;

        // IF frequency of previous character is less
        // than zero that means it is useless, we
        // need not to push it
        if (prev.freq > 0)
            pq.push(prev);

        // make current character as the previous 'char'
        // decrease frequency by 'one'
        (k.freq)--;
        prev = k;
    }

    // If length of the resultant string and original
    // string is not same then string is not valid
    if (n != str.length())
        cout << " Not valid String " << endl;

    else // valid string
        cout << str << endl;
}
```

---

## longest consecutive sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

- eg
  Input: nums = [100,4,200,1,3,2]
  Output: 4
  Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

```cpp
int longestConsecutive(vector<int> &num) {
        unordered_set<int> record(num.begin(),num.end());
        int res = 0;
        for(int n : num){
            if(record.find(n)!=record.end()){
                int count=1; //as only n itself is of length 1
                int prev=n-1,next=n+1;
                record.erase(n);
                while(record.find(prev)!=record.end()){
                    count++;  //as prev present increase count
                    record.erase(prev);
                    prev--; //decrease prev to check if prev present or not
                }
                while(record.find(next)!=record.end()){
                    count++;  //as prev present increase count
                    record.erase(next);
                    next++;
                }
                res=max(count,res);
                
            }
        }
        return res;
    }
```

![](img\longestconsecutivesequevence.png)

---

## longest contiguous subarray

![](img\longestcontiguoussubarray.png)
Input: arr[] = {10, 12, 11};
Output: Length of the longest contiguous subarray is 3

Input: arr[] = {10, 12, 12, 10, 10, 11, 10};
Output: Length of the longest contiguous subarray is 2

```cpp
int findLength(int arr[], int n)
{
	int max_len = 1; // Initialize result

	// One by one fix the starting points
	for (int i=0; i<n-1; i++)
	{
		// Create an empty hash set and
		// add i'th element to it.
		set<int> myset;
		myset.insert(arr[i]);

		// Initialize max and min in
		// current subarray
		int mn = arr[i], mx = arr[i];

		// One by one fix ending points
		for (int j=i+1; j<n; j++)
		{
			// If current element is already
			// in hash set, then this subarray
			// cannot contain contiguous elements
			if (myset.find(arr[j]) != myset.end())
				break;

			// Else add current element to hash
			// set and update min, max if required.
			myset.insert(arr[j]);
			mn = min(mn, arr[j]);
			mx = max(mx, arr[j]);

			// We have already checked for
			// duplicates, now check for other
			// property and update max_len
			// if needed
			if (mx - mn == j - i)
				max_len = max(max_len, mx - mn + 1);
		}
	}
	return max_len; // Return result
}
```

---

# min number of swaps to make array sorted

This can be easily done by visualizing the problem as a graph. We will have n nodes and an edge directed from node i to node j if the element at i’th index must be present at j’th index in the sorted array.

The graph will now contain many non-intersecting cycles. Now a cycle with 2 nodes will only require 1 swap to reach the correct ordering, similarly a cycle with 3 nodes will only require 2 swap to do so.

```cpp
int minimumSwaps(int a[], int n){
    vector<bool> vis(n, false);

	int res = 0;
	pair<int, int> arr[n];
	for (int i = 0; i < n; i++) {
		arr[i].first = a[i];
		arr[i].second = i;
	}

	sort(arr, arr + n); // sort by first


	for (int i = 0; i < n; i++)
	{
		if (vis[i])
			continue;

		int cycle_len = 0;
		int j = i;
		while (vis[j]==false)
		{
			vis[j] = true;
			j = arr[j].second;
			cycle_len++;
		}

		if (cycle_len > 0)
		{   //if in cycle there are n swap then there will be n-1 swap required
			res =res+ (cycle_len - 1);
		}
	}
	return res;

}
```

![](img\minnumberofswaps.png)

---

# find kth smallest ele

- if in quicksort the partition `pos == k` return that

```cpp
int split(int arr[],int lo,int hi)
{
    int i = lo-1;
    int pivot = hi;
    for(int j=lo;j<pivot;j++)
    {
        if(arr[j] < arr[pivot])
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[pivot]);
    return i+1;
}
void quickSortServe(int arr[],int lo,int hi)
{
    if(lo < hi)
    {
        int pos = split(arr,lo,hi);////////////////
        if(pos==k-1)
        return arr[k];
        if(pos>k-1)                // |   k   |pos|  |
        return quickSortServe(arr,lo,pivot-1);
        else if(pos<k-1)           //  |....|pos|...K....|
        return quickSortServe(arr,pivot+1,hi);
    }
}
```

other methods

- use minheap or maxheap

---

# Union and intersection of 2 arrays

```
1) Use two index variables i and j, initial values i = 0, j = 0
2) If arr1[i] is smaller than arr2[j] then increment i.
3) If arr1[i] is greater than arr2[j] then increment j.
4) If both are same then print any of them and increment both i and j.
```

---

# rotate clpckwise array once

```cpp
Given an array, cyclically rotate the array clockwise by one.

Examples:

Input:  arr[] = {1, 2, 3, 4, 5}
Output: arr[] = {5, 1, 2, 3, 4}
    //store x=arr[n-1]
    //for n-1 to 1  arr[i]=arr[i-1]  a[0] =x
```

---

# minimize diff of height

```cpp
        int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int diff=arr[n-1]-arr[0];
        int minh=arr[0];
        int maxh=arr[n-1];
        for(int i=1;i<n;i++)  //0...x,y....n-1  i=y i-1=x
        {
            if(arr[i]>=k){ //so that y doesnt become negative
            minh=min(arr[i]-k,arr[0]+k);
            maxh=max(arr[i-1]+k,arr[n-1]-k);
            diff=min(diff,maxh-minh);
        }

        }
        return diff;
    }
```

![](img\minhdiff.png)

---

# find duplicate number

```
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
```

o(n) space use hash set
for o(1) use fast slow below 0(n) time
other method is binary search where we find number and check how many numbers are smaller than it in array => O(nlogn)

```cpp
    int findDuplicate(vector<int>& nums) {
        int fast=nums[0];
        int slow=nums[0];
        do{
            fast=nums[nums[fast]];
            slow=nums[slow];
        }while(slow!=fast);
        fast=nums[0];
        while(fast!=slow)
        {
            fast=nums[fast];
            slow=nums[slow];
        }
        return slow;
    }
```

![](img\findduplic.png)
![](img\findduplic-2.png)

---

# inversion count - the

```
Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum.
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
```

```
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5
has three inversions (2, 1), (4, 1), (4, 3).
```

```cpp
long long int merge(long long arr[],int left,long long int mid,long long int right,long long temp[]){
    long long int i=left;
    long long int j=mid+1;
    long int k=left;
    long long int inv=0;
    while(i<=mid&&j<=right){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{

            temp[k++]=arr[j++];inv=inv+mid-i+1;
        }

    }
            while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=right){
            temp[k++]=arr[j++];
        }

        for(int i=left;i<=right;i++){
            arr[i]=temp[i];
        }
    return inv;
}
long long int mergesort(long long arr[],int left,int right,long long temp[]){
    if(left==right)return 0;
    long long int mid=(left+right)/2;
    long long int inv=0;
    inv=inv+mergesort(arr,left,mid,temp)
    +mergesort(arr,mid+1,right,temp)
    +merge(arr,left,mid,right,temp);
    return inv;
}
long long int inversionCount(long long arr[], long long N)
{
    long long temp[N];
    return mergesort(arr,0,N-1,temp);
}
```

![](img\inversioncount.png)

---

# next permutation

`Strategy`

```
Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
Find the largest index l > k such that nums[k] < nums[l].
Swap nums[k] and nums[l].
Reverse the sub-array nums[k + 1:].
```

```md
Input: nums = [1,2,4,3,2] => 1 `2 < 4` 3 2= 1 4 2 [3,2]=>1 4 2 2 3
Output: [1,3,2]
```

```cpp
void nextPermutation(vector<int>& nums) {
    	int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            }
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
```

---

# Merge intervals

```
Sort by start value. (Changed the pass in value, not nice.)
Scan one interval at a time, keep a current interval and compare with next interval
If next interval is disconnected from the current interval (next start is larger than current end), add current interval to return, the next interval becomes current one.
Otherwise the two ranges overlap or at least connected, update the current interval's end point with the largest of the current interval's end and next interval's end.
When finished scaning, remember to put the last current interval into return value.
Runtime: O(n*log(n)) sort, O(n) linear scan.
```

```cpp
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> inter;
        sort(intervals.begin(),intervals.end());
        vector<int> cur=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(cur[1]<intervals[i][0]){    //is disconnected interval start > curr end
                inter.push_back(cur);
                cur=intervals[i];
            }
            else cur[1]=max(cur[1],intervals[i][1]);
        }
        inter.push_back(cur);
        return inter;
    }
```

---

# rearrange positive and negative numbers in O(n) time and O(1) space alternatively

```cpp
int partition(int A[], int n)
{
    int j = 0;
    int pivot = 0;    // consider 0 as a pivot
    // each time we find a negative number, `j` is incremented,
    // and a negative element would be placed before the pivot
    for (int i = 0; i < n; i++)
    {
        if (A[i] < pivot)
        {
            swap(A[i], A[j]);
            j++;
        }
    }

    // `j` holds the index of the first positive element
    return j;
}
int rearrange(int A[], int size)
{
    // partition a given array such that all positive elements move
    // to the end of the array
    int p = partition(A, size);

    // swap alternate negative elements from the next available positive
    // element till the end of the array is reached, or all negative or
    // positive elements are exhausted.

    for (int n = 0; (p < size && n < p); p++, n += 2) {
        swap(A[n], A[p]);
    }
}
```

- we find a pivot right of which is all negative
- condition to take note of n < p -as we from p all are +ve and p < size of array we dont want to go outside array
- we swap every alternate -ve number with a +ve number n+=2 and p++

---

# Factorial of a large number

```cpp
void multiplyx(int x, int ans[], int &size)
{
    int carry = 0;
    for (int i=0; i<size; i++)
    {
        int product = ans[i] * x + carry;  ///  eg prod=678
        ans[i] = product % 10;   //ans[i] = 8
        carry  = product/10;     //carry=67
    }

    while (carry) //if any carry left   //68  =>extra ele =>[........8 ,6]
    {
        ans[size] = carry%10;
        carry = carry/10;
        size++; //as we use an extra space we increase size
    }
}

void factorial(int n)
{
    int ans[MAX];
    ans[0] = 1; //only one block used
    int size = 1;
    for (int x=2; x<=n; x++)
        multiplyx(x, ans, size);
    for (int i=size-1; i>=0; i--)
        cout << ans[i];
}
```

![](img\factorialofbigno.png)

---

# max product subarray

```cpp
    int maxProduct(vector<int>& nums) {
        int prod=1,maxp=INT_MIN;
        for(int i=0;i<nums.size();i++){
            prod*=nums[i];
            maxp=maxp>prod?maxp:prod;
            if(prod==0)prod=1;
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            prod*=nums[i];
            maxp=maxp>prod?maxp:prod;
            if(prod==0)prod=1;
        }
        return maxp;
    }
```
- Simplest case. Consider this array `[1,2,3,-4,5,6]`. We can think of `-4` as dividing the array into 2 halves, `[1,2,3]` and `[5,6]`. The forward traversal yields the max as 6, while the reverse traversal yields 30.
- Say the array has even number of negative numbers eg. `[1,2,-3,-4,5,6]`. `Both forward and reverse traversals yield the same result`, so it doesnt matter.
- Say the array has `multiple odd number of negative integers. eg. [1,2,-3,-4,-5, 6]`. We can think of the "last" negative number in each traversal breaks the array to 2 halves. In this case , the max array `in forward traversal is the maximum of ([1,2,-3,-4] and [6])` which is 24. In `the reverse`, the split is `delimited by -3`. So the max subarrray is the maximum of `([6,-5,-4] and [2])`
- Hence, in the end, its all about the presence of odd or even number of negative integers. In case of even, the product is always positive. In case of odd, the max product is limited by the last negative integer in each traversal.

![](img\maxprodsub.png)
```cpp
    int maxProduct(vector<int>& a) {
        int minhere=1,maxhere=1,res=INT_MIN;
        for(auto n:a){
            if(n<0)  //when number negative
                swap(minhere,maxhere); //make maxhere as minhere
            maxhere=max(maxhere*n,n);
            minhere=min(minhere*n,n);
            res=max(maxhere,res);
        }
        return res;
    }
```
![](img\maxprodsub-2.png)

---
# print all ele that occur more than n/k times
```cpp
void morethanNbyK(int arr[], int n, int k)
{
    int x = n / k; //  n/k 
      
      // unordered_map initialization
    unordered_map<int, int> freq;
  
    for(int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    
      // Traversing the map
    for(auto i : freq)
    {
          
        // Checking if value of a key-value pair
        // is greater than x (where x=n/k)
        if (i.second > x)
        {
              
            // Print the key of whose value
            // is greater than x
            cout << i.first << endl;
        }
    }
}
```
---
# check if array subset of another array
```
Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. It may be assumed that elements in both array are distinct.``
```
```cpp
string isSubset(int a1[], int a2[], int n, int m) {
    set<int> s;
    for(int i=0; i<n; i++){
        s.insert(a1[i]);
    }
    for(int j=0; j<m; j++){
        if(s.find(a2[j]) == s.end()) return "No";
    }
    return "Yes";
}
```
---
# 3 sum
```cpp
bool find3Numbers(int A[], int arr_size, int sum)
{
    int l, r;
    sort(A, A + arr_size);
    for (int i = 0; i < arr_size - 2; i++) {
        l = i + 1;
        r = arr_size - 1; // index of the last element
        while (l < r) {
            if (A[i] + A[l] + A[r] == sum) {
                printf("Triplet is %d, %d, %d", A[i],
                       A[l], A[r]);
                return true;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }
    return false;
}
```
---
# trapping rainwater
```cpp
    int trap(vector<int>& height) {
            int maxleft=0,maxright=0,total=0;
            int left=0,right=height.size()-1;
            while(left<right){
                //choose the smaller bounding value  as
                if(height[left]<=height[right]){
                    //if height is more than maxleft it cannot contribute so make it maxleft and go left
                    if(height[left]>=maxleft){
                        maxleft=height[left];
                        left++;
                    }else{
                        //else it contributes to the totaal
                        total=total+maxleft-height[left];
                        left++;
                    }
                }else{
                    //if higher height then you cant contribute
                    if(height[right]>=maxright){
                        maxright=height[right];
                        right--;
                    }else{
                        //else contributes
                        total=total+maxright-height[right];
                        right--;
                    }
                }
            }
        return total;
    }
```
other method - find left max and rightmax

```cpp
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);
            leftMax[0] = height[0];rightMax[n-1]=height[n-1];
        for (int i = 1; i < n; ++i) 
            leftMax[i] = max(height[i], leftMax[i-1]);
        for (int i = n-2; i >= 0; --i) 
            rightMax[i] = max(height[i], rightMax[i+1]);
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int waterLevel = min(leftMax[i], rightMax[i]);
            ans += waterLevel - height[i];
        }
        return ans;
    }
```
![](https://assets.leetcode.com/users/images/defee20d-dca9-4244-8817-2f158efecc55_1627750629.6494076.png)

---
# Chocolate distribution
```
Given an array of n integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 

Each student gets one packet.
The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.
```
```cpp
int findMinDiff(int arr[], int n, int m)
{
    // if there are no chocolates or number
    // of students is 0
    if (m == 0 || n == 0)
        return 0;
 
    // Sort the given packets
    sort(arr, arr + n);
 
    // Number of students cannot be more than
    // number of packets
    if (n < m)
        return -1;
    int min_diff = INT_MAX;
        for (int i = 0; i + m - 1 < n; i++) {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}
```
![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20190620132657/Chocolate-Distribution-Problem.png)

---
# smallest subarray with sum > k 
```cpp
int findSmallestSubarrayLen(int arr[], int n, int k)
{
    // stores the current window sum
    int windowSum = 0;
 
    // stores the result
    int len = INT_MAX;
 
    // stores the window's starting index
    int left = 0;
 
    // maintain a sliding window `[left…right]`
    for (int right = 0; right < n; right++)
    {
        // include the current element in the window
        windowSum += arr[right];
 
        // the window becomes unstable if its sum becomes more than `k`
        while (windowSum > k && left <= right)
        {
            // update the result if the current window's length is less than the
            // minimum found so far
            len = min(len, right - left + 1);
 
            // remove elements from the window's left side till the window
            // becomes stable again
            windowSum -= arr[left];
            left++;
        }
    }
 
    // invalid input
    if (len == INT_MAX) {
        return 0;
    }
 
    // return result
    return len;
}
```
![](img\smallestsubarrgreterk.png)

---
## arrange all ele greater than y to right and less then x to left ...[x....y].... and the three sets can be arranged in any manner 
```cpp
    void threeWayPartition(vector<int>& a,int x, int y)
    {
        int curr=0;
        int n=a.size(),left=0,right;
        right=n-1;
            while(curr<=right){
                if(a[curr]<x){
                    swap(a[left],a[curr]);
                    left++;
                    curr++;
                }
                else if(a[curr]>y){
                    swap(a[right],a[curr]);
                    right--;
                }
                else curr++;
            }
    }
```
- dutch national flag

---
# Minimum swaps and K together 
```
Given an array arr of n positive integers and a number k. One can apply a swap operation on the array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.
```
```cpp
    int minSwap(int a[], int n, int k) {
        int c=0;
        for(int i=0;i<n;i++){//count number of ele less than or equal to k
            if(a[i]<=k)count++;
        }
        int numbers_less_than_equal_to_k=0,mins=c;
        for(int i=0;i<c;i++){ 
            //count number of ele less than or equal to k in first window
            if(a[i]<=k)numbers_less_than_equal_to_k++;
        }
        mins=c-numbers_less_than_equal_to_k;
        int j=(0+c-1);// start=0 count 3 j=0+3-1=2=> [0 1 2]
        for(int i=0;j<n-1;i++){
            // check how many ele are less than or equal to k in each window and find min
            if(a[i]<=k){  //removing ith ele
                numbers_less_than_equal_to_k--;
            }
            if(a[++j]<=k){//adding next ele of sliding window
                numbers_less_than_equal_to_k++;
            }
            mins=min(c-numbers_less_than_equal_to_k,mins);
        }
        return mins;
    }
```
```cpp
[1, 12, 10, 3, 14, 10, 5]
number of elements <= k (k=8) ===> 3 (1,3,5)
so we want these 3 elements together, let us check all windows of size 3 that has least elements > 8
Lets start sliding window,
[[1, 12, 10], 3, 14, 10, 5] --- 2 elements>8 (12,10)
[1, [12, 10, 3], 14, 10, 5] --- 2 elements>8 (12,10)
[1, 12, [10, 3, 14], 10, 5] --- 2 elements>8 (10,14)
[1, 12, 10, [3, 14, 10], 5] --- 2 elements>8 (14,10)
[1, 12, 10, 3, [14, 10, 5]] --- 2 elements>8 (14,10)
A = [1, 12, 10, 3, 14, 10, 5]
After swapping  12 and 3, A => [1, 3, 10, 12, 14, 10, 5].
After swapping  the first occurrence of 10 and 5, A => [1, 3, 5, 12, 14, 10, 10].
Now, all elements less than or equal to 8 are together.
So, the answer is 2.
```
- here they are to grouped together in any window so we need to find the window where we need to swap less

---
# number of minnimum swaps required to make an array palindrome
```cpp
/**
     * Algorithm:
     *     1. First check the given string is a jumbled/shuffled palindrome or not.
     *     2. Next have two pointers p1 at 0 and p2 at s.length - 1 and start iterating.
     *     3. If chars at both the pointers are same then just shrink the window (increase the p1 and decrease the p2).
     *     4. or Else
     *          a. find the matching pair and swap the char to p2 index (increase swap count while swapping) and finally shrink the window.
     *          b. if not found just swap once with adjacent index and increase the swap count (do not shrink the window here)
     *     5. Print the Swap Count
     *
     * Time Complexity: O(n) to find Palindrome + [ O(n) for two pointer iteration * O(n) for checking and swapping ] so => O(n^2)
     * Space Complexity: O(n)
     *
     */
```
```cpp
int minswapspal(string a,int n){
    int l,r,ts=0,mid;
    l=0;r=n-1,mid;
    while(l<r){
        if(a[l]==a[r]){
            l++;
            r--;//closing that window
        }else {
            mid=r;
            while(mid>l&&a[l]!=a[mid]){
                mid--;
            }
            if(mid==l){ 
            //if that ele is the one with odd freq eg acbba c has odd frequency here is l=1 so a[l]=c
            //so it is swapped with next char to make it abcba and left is pointing at b now
                swap(a[l],a[l+1]);
                ts++; //we dont change are window pointer as we check for the ele swapped
            }else{  
                //found charcter in window 
                //swap it adjacently till you reach r
                for(int i=mid;i<r;i++){
                    swap(a[i],a[i+1]);
                    ts++;
                }
                r--; //closing that window
                l++;
            }
        }
    }
    return ts;
}
```
