# merging array
1st approach
```c++
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=0,j=0,k=0;
        while(i!=m&&j!=n)
        {
            if(l[i]<=nums2[j])
            {
                nums1[k]=l[i];
                i++;
                k++;
            }
             if(l[i]>r[j])
            {
                nums1[k]=r[j];
                j++;
                k++;
            }
            
        }
        while(i!=m)
        {
            nums1[k]=l[i];
            i++;
            k++;
        }
        while(j!=n)
        {
            nums1[k]=r[j];
            j++;
            k++;
        }
    }
```
---
2nd approach
```c++
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
   int i=m-1,j=n-1,k=m+n-1;
        while(i>=0&&j>=0)
        {
            if(nums1[i]>=nums2[j])
            {
                nums1[k]=nums1[i];
                k--;
                i--;
            }
            else
            {
                nums1[k]=nums2[j];
                k--;
                j--;
            }
        }
        while(j>=0)
        {
            nums1[k]=nums2[j];
            k--;
            j--;
        }
        
    } 
```
---
# Merge Sort
```c++
void merge(int arr[] , int l , int m , int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int i = 0 , j = 0, k = l;
	int left[n1] ,  right[n2];

	for ( i = 0; i < n1; i++)
		left[i] = arr[l + i];

	for ( j = 0; j < n2 ; j++)
		right[j] = arr[m + 1 + j];

	i = 0 , j = 0,k = l;

	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}

	while (i < n1)
		arr[k++] = left[i++];

	while ( j < n2)
		arr[k++] = right[j++];
}


void mergeSort(int arr[], int l , int r)
{

	if (l < r)
	{
		int mid = l + (r - l) / 2;

		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
}
```
![](img\mergesort.png)

---
# QUICK SORT
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
        int pivot = split(arr,lo,hi);
        quickSortServe(arr,lo,pivot-1);
        quickSortServe(arr,pivot+1,hi);
    }
}
```
![](img\quicksort.png)

---
# `insertion Sort`
- for evry i = `1` to `n-1`
    - key = arr[i]
    - if arr[i]<arr[j]
```cpp
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```
---
# `selection sort`
- for every i= 0 to n-2
    - find min from i to n then swap it with ith pos
```cpp
void selectionSort(vector<int>& arr) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of 
    // unsorted subarray 
    for (i = 0; i< arr.size()-1; i++) 
    { 
        
        // Find the minimum element in 
        // unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element 
        // with the first element 
        swap(arr[min_idx],arr[i]); 
    } 
} 
```
---
# `Bubble sort`
```cpp
void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(arr[j], arr[j+1]);
           swapped = true;
        }
     }
  
     // IF no two elements were swapped 
     // by inner loop, then break
     if (swapped == false)
        break;
   }
}
  
```
# FIRST AND LAST OCCURENCE OF AN ELE IN SORTED ARRAY
```cpp
int first(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
         
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}
int last(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
         
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;

        else
        {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}
 
```
![](img\FIRSTANDLASTOCCURENCE.png)

---
# find pivot of rotated sorted array
```cpp
int pivot(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[mid]>nums[right])
                left=mid+1;
            else
                right=mid;
        }
        return left;
    }
```
![](img\pivot.png)

---
# to search for ele in rotated sorted array
```cpp
    int pivot(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[mid]>nums[right])
                left=mid+1;
            else
                right=mid;
        }
        return left;
    }
    int bsearch(vector<int>& nums, int target,int low,int high)
    {
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int piv=pivot(nums);
        if(piv==0)
            return bsearch(nums,target,0,nums.size()-1);
        if(target==nums[piv])
            return piv;
        if(target>=nums[0])
        {
            return bsearch(nums,target,0,piv-1);
        }
        else
        return bsearch(nums,target,piv,nums.size()-1);
    }
```
![](img\searchinrotatedarray.png)

---
# finding min and max ele in array with minimum comparison
```cpp
struct Pair getMinMax(int arr[], int n)
{
    struct Pair minmax;    
    int i;
     
    // If there is only one element
    // then return it as min and max both
    if (n == 1)
    {
        minmax.max = arr[0];
        minmax.min = arr[0];    
        return minmax;
    }
     
    // If there are more than one elements,
    // then initialize min and max
    if (arr[0] > arr[1])
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    }
    else
    {
        minmax.max = arr[1];
        minmax.min = arr[0];
    }
     
    for(i = 2; i < n; i++)
    {
        if (arr[i] > minmax.max)    
            minmax.max = arr[i];
             
        else if (arr[i] < minmax.min)    
            minmax.min = arr[i];
    }
    return minmax;
}
```
---
# to find square root of number
```cpp
int floorSqrt(int x)
{
    // Base cases
    if (x == 0 || x == 1)
        return x;
 
    // Do Binary Search for floor(sqrt(x))
    int start = 1, end = x, ans;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (mid * mid == x)
            return mid;
        if (mid <= x / mid) {
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid - 1;
    }
    return ans;
}
``` 
---
# Searching in an array where adjacent differ by at most k
```
Input : arr[] = {20, 40, 50, 70, 70, 60}  
          k = 20
          x = 60
Output : 5
The index of 60 is 5

```
```cpp
int search(int arr[], int n, int x, int k)
{
    // Traverse the given array starting from
    // leftmost element
    int i = 0;
    while (i < n)
    {
        // If x is found at index i
        if (arr[i] == x)
            return i;
 
        // Jump the difference between current
        // array element and x divided by k
        // We use max here to make sure that i
        // moves at-least one step ahead.
        i = i + max(1, abs(arr[i]-x)/k);
    }
    
    cout << "number is not present!";
    return -1;
}
```
---
# Find Pair Given Difference
- constant space
- sort array then one by one search diff+a[i] using binary search
```
Input:
L = 6, N = 78   L -> size N-> diff
arr[] = {5, 20, 3, 2, 5, 80}
Output: 1
Explanation: (2, 80) have difference of 78.
```
```cpp
bool findPair(int arr[], int size, int n){
   //code
   sort(arr,arr+size);
   for(int i=0;i<size;i++) {
       if(binary_search(arr+i+1,arr+size,n+arr[i])) {
           return true;
       }
   }
   return false;
}
```
- n -> diff
- size -> size of array

---
# Find four elements that sum to a given value
```

```
```cpp
void findFourElements(int arr[], int n, int X)
{
    // Store sums of all pairs
    // in a hash table
    unordered_map<int, pair<int, int> > mp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            mp[arr[i] + arr[j]] = { i, j };
 
    // Traverse through all pairs and search
    // for X - (current pair sum).
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
 
            // If X - sum is present in hash table,
            if (mp.find(X - sum) != mp.end()) {
 
                // Making sure that all elements are
                // distinct array elements and an element
                // is not considered more than once.
                pair<int, int> p = mp[X - sum];
                if (p.first != i && p.first != j
                    && p.second != i && p.second != j) {
                    cout << arr[i] << ", " << arr[j] << ", "
                         << arr[p.first] << ", "
                         << arr[p.second];
                    return;
                }
            }
        }
    }
}
```

---
#  to find all unique triplets
```cpp
int findTriplets(int nums[], int n, int sum)
{
    int i, j, k;
 
    // Vector to store all unique triplets.
    vector<triplet> triplets;
 
    // Set to store already found triplets
    // to avoid duplication.
    unordered_set<string> uniqTriplets;
 
    // Variable used to hold triplet
    // converted to string form.
    string temp;
 
    // Variable used to store current
    // triplet which is stored in vector
    // if it is unique.
    triplet newTriplet;
 
    // Sort the input array.
    sort(nums, nums + n);
 
    // Iterate over the array from the
    // start and consider it as the
    // first element.
    for (i = 0; i < n - 2; i++)
    {
        // index of the first element in
        // the remaining elements.
        j = i + 1;
 
        // index of the last element.
        k = n - 1;
 
        while (j < k) {
 
            // If sum of triplet is equal to
            // given value, then check if
            // this triplet is unique or not.
            // To check uniqueness, convert
            // triplet to string form and
            // then check if this string is
            // present in set or not. If
            // triplet is unique, then store
            // it in vector.
            if (nums[i] + nums[j] + nums[k] == sum)
            {
                temp = to_string(nums[i]) + " : "
                       + to_string(nums[j]) + " : "
                       + to_string(nums[k]);
                if (uniqTriplets.find(temp)
                    == uniqTriplets.end()) {
                    uniqTriplets.insert(temp);
                    newTriplet.first = nums[i];
                    newTriplet.second = nums[j];
                    newTriplet.third = nums[k];
                    triplets.push_back(newTriplet);
                }
 
                // Increment the first index
                // and decrement the last
                // index of remaining elements.
                j++;
                k--;
            }
 
            // If sum is greater than given
            else if (nums[i] + nums[j] + nums[k] > sum)
                k--;
 
            // If sum is less than given value
            else
                j++;
        }
    }
 
    // If no unique triplet is found, then
    // return 0.
    if (triplets.size() == 0)
        return 0;
 
    // Print all unique triplets stored in
    // vector.
    for (i = 0; i < triplets.size(); i++) {
        cout << "[" << triplets[i].first << ", "
             << triplets[i].second << ", "
             << triplets[i].third << "], ";
    }
}
```
or - technique
```cpp
int getTripletOfSum(int arr[], int n, int sum)
{
    int i, j, k;
    bool isFound=false;
    sort(arr, arr + n);
    for(i = 0; i < n - 2; i++)/////////// n-2 as 2 more left out for j and k
    {
        j = i + 1;
        k = n - 1;
        while(j < k)
        {
            if(arr[i] + arr[j] + arr[k] == sum)
            {
                cout<<"["<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<"]"<<endl;
                j++;
                k--;
                isFound=true;
            }
            else if(arr[i] + arr[j] + arr[k] > sum)
                k--;
            else
                j++;
        }
    }
    return isFound;
}
```
![](img\tripletsum.png)

---
# merge 2 arrays which are already sorted without extra space
```
Input:
N = 2, arr1[] = [10, 12]
M = 3, arr2[] = [5 18 20]
Output:
arr1[] = [5 10]
arr2[] = [12 18 20]
Explanation:
After merging two sorted arrays
we get 5 10 12 18 20.
```
```cpp
void merge(int arr1[], int arr2[], int n, int m) {
    // code here
    int i=n-1;
    int j=0;
    while(i>=0 and j<m)
    {
        if(arr1[i]>=arr2[j])
        {
            swap(arr1[i],arr2[j]);
            i--;
            j++;
        }
        else
        {
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}
```
![](img\merge2arrayszerospace.png)

---
# find number of subarrays with sum 0
```
Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].
```
```cpp
     ll findSubarray(vector<ll> arr, int n ) {
       long long sum=0;long long ans=0;
      unordered_map<long long,int>mp;
       for(int i=0;i<n;i++){
           sum+=arr[i];
          if(sum==0){
              ans++;
          }
        
          ans+=mp[sum];//no of times given sum present before
          mp[sum]++;
       }
    
       return ans;
   }
```
- when sum already there in map we have zero subarray as 
- eg: 3 ,4 ,-4 ,4  => 3 ,7 ,3 ,7 
- => we reached 3(at index=2) from 3(index=0) and reached 7(index=1) from 7(index=3) so if we have a count of particular sum we have a zero for every sum we get before it
- zero forms its own subarray so we increment once in start if first ele is zero

---
#
```cpp
bool isPossible(int arr[], int n, int m, int curr_min)
{
    int studentsRequired = 1;
    int curr_sum = 0;
 
    // iterate over all books
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > curr_min)//if there is a book with pages more than min req
            return false;
        if (curr_sum + arr[i] > curr_min)
        {
            studentsRequired++;
            curr_sum = arr[i];
            if (studentsRequired > m)
                return false;
        }
        else
            curr_sum += arr[i];
    }
    return true;
}
 
// function to find minimum pages
int findPages(int arr[], int n, int m)
{
    long long sum = 0;
 
    // return -1 if no. of books is less than
    // no. of students
    if (n < m)
        return -1;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int start = 0, end = sum;
    int result = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid))
        {
              result = mid;
            end = mid - 1;
        }
 
        else
            start = mid + 1;
    }
    return result;
}
```
![](img\minallofpages.png)

---
# aggresive cows
```
Given an array of length ‘N’, where each element denotes the position of a stall. Now you have ‘N’ stalls and an integer ‘K’ which denotes the number of cows that are aggressive. To prevent the cows from hurting each other, you need to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. Return the largest minimum distance.
Eg

array: 1,2,4,8,9  &  k=3
O/P: 3
Explaination: 1st cow at stall 1 , 2nd cow at stall 4 and 3rd cow at stall 8
```
```cpp
bool isPossible(vector<int> &stalls, int minDist, int k)
{
    int cows=1;               // we already place it at the first available slot i.e stalls[0]  ( GREEDY )
    int lastCowPosition=stalls[0];
    for(int i=1;i<stalls.size();i++)
    {
        if(stalls[i]-lastCowPosition>=minDist)
        {
            cows++;
            lastCowPosition=stalls[i];
            if(cows>=k) return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int low=1,high=stalls[n-1]-stalls[0];              // just take low=0 and high = 1000000 any large number if this seems tricky
    int res;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(isPossible(stalls,mid,k))
        {
            res=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return res;
}
```
- here `isPossible` checks if we can place k cows with a min dist mid
- if cows < k -> `false`
- so `ifpossible` is true  we need to increase that min distance so move right
- if not possible that means the min distance should be decreased so that k cows can be placed in the stalls with each having a min ist so go left 

![](img\aggressivecows.png)

---
# dutch national flag
![](img\dutchnationalflag.png)

---
# array puzzle
Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].

 
```c
Input:
n = 5
nums[] = {10, 3, 5, 6, 2}
Output:
180 600 360 300 900
Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
```
```cpp
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        long long int prodth[nums.size()],revprodth[nums.size()];
        prodth[0]=1;
        for(int i=1;i<n;i++)
        prodth[i]=prodth[i-1]*nums[i-1];
        revprodth[n-1]=1;
        for(int i=n-2;i>=0;i--)
        revprodth[i]=revprodth[i+1]*nums[i+1];
        for(int i=0;i<n;i++)
        {
            nums[i]=prodth[i]*revprodth[i];
        }
        return nums;
    }
```
---
# Sort an array according to count of set bits - no. of 1s in binary
```cpp
int countBits(int a)
{
    int count = 0;
    while (a) {
        if (a & 1)
            count += 1;
        a = a >> 1;
    }
    return count;
}
 
// custom comparator of std::sort
int cmp(int a, int b)
{
    int count1 = countBits(a);
    int count2 = countBits(b);
 
    // this takes care of the stability of
    // sorting algorithm too
    if (count1 <= count2)
        return false;
    return true;
}
 
// Function to sort according to bit count using
// std::sort
void sortBySetBitCount(int arr[], int n)
{
    stable_sort(arr, arr + n, cmp);
}
```
---
# find kth smallest from a given set of ranges
```cpp
bool comp(Interval a, Interval b)
{
    return a.s < b.s;
}
int kthSmallestNum(vector<Interval> merged, int k)
{
    int n = merged.size();
    for (int j = 0; j < n; j++)
    {
        if (k <= abs(merged[j].e -
                     merged[j].s + 1))
            return (merged[j].s + k - 1);
 
        k = k - abs(merged[j].e -
                     merged[j].s + 1);
    }
 
    if (k)
        return -1;
}
 
void mergeIntervals(vector<Interval> &merged,
                 Interval arr[], int n)
{
    sort(arr, arr + n, comp);
 
    // Merging all intervals into merged
    merged.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        Interval prev = merged.back();
        Interval curr = arr[i];
        if ((curr.s <= prev.e) &&(curr.e > prev.e))
 
            merged.back().e = curr.e;
 
        else
        {
            // If starting point of next range
            // is greater than the ending point
            // of previous range then store next range
            // in merged[].
            if (curr.s > prev.e)
                merged.push_back(curr);
        }
    }
}
```
![]()

---
# kth smallest ele in 2 sorted arrays
```cpp
int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n > m) {
            return kthElement(arr2, arr1, m, n, k); 
        }
        
        int low = max(0,k-m), high = min(k,n);
        
        while(low <= high) {
            int cut1 = (low + high) >> 1; 
            int cut2 = k - cut1; 
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
            int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
            
            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            else if (l1 > r2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1; 
            }
        }
        return 1; 
    }
```
![](img\kelefrom2sort-1.png)
![](img\kelefrom2sort-2.png)

---
# median of 2 sorted arrays
```cpp
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size(); 
        int low = 0, high = n1;
        
        while(low <= high) {
            int cut1 = (low+high) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1; 
            
        
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1]; 
            
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2]; 
            
            
            if(left1 <= right2 && left2 <= right1) {
                if( (n1 + n2) % 2 == 0 ) 
                    return (max(left1, left2) + min(right1, right2)) / 2.0; 
                else 
                    return max(left1, left2); 
            }
            else if(left1 > right2) {
                high = cut1 - 1; 
            }
            else {
                low = cut1 + 1; 
            }
        }
        return 0.0; 
    }
```
- same as the one with kth smallest but here `k=(n1+n2+1)/2` =>middle ele
- if odd == n1+n2 its max(left1, left2) =>
- if even == n1+n2 its `(max(left1, left2) + min(right1, right2))` one from before partition and one after partition

---
# find the no. of ele greater than x in a sorted array
```cpp
int countSmallerThanMid(vector<int> &arr, int x) {
    int l = 0, h = arr.size() - 1; 
    while(l <= h) {
        int md = (l + h) >> 1; 
        if(arr[md] <= x) { //ele less than x so move right
            l = md + 1;
        }
        else {  //ele greater than x
            h = md - 1;
        }
    }
    return l; 
}
```
![](img\bsnoofelgreater.png)

---
# median of a matrix which is sorted in every row
```cpp
// number of ele lesser than than mid in each row
int countSmallerThanMid(vector<int> &row, int mid) {
    int l = 0, h = row.size() - 1; 
    while(l <= h) {
        int md = (l + h) >> 1; 
        if(row[md] <= mid) {
            l = md + 1;
        }
        else {
            h = md - 1;
        }
    }
    return l; 
}
int Solution::findMedian(vector<vector<int> > &A) {
    int low = INT_MIN;
    int high = INT_MAX; 
    int n = A.size();
    int m = A[0].size(); 
    while(low <= high) {
        int mid = (low + high) >> 1; 
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            cnt += countSmallerThanMid(A[i], mid); 
        }
        
        if(cnt <= (n * m) / 2) low = mid + 1; 
        else high = mid - 1; 
    }
    return low; 
}
```
![](img\medianofsortedmatrix.png)

---