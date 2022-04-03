# reverse words of string
in 2 pass - using stack to put words then put it back
```cpp
string reverseWords(string s) {
        if(s.size() == 0) return s;
        stack<string> stack;
        string result;
        for(int i=0; i<s.size(); i++) {
            string word;
            if(s[i]==' ') continue; //skip spaces
            while(i<s.size() && s[i]!=' ' ) { //store continuous letters into word
                word += s[i]; i++;
            }
            stack.push(word); //push word to the stack
        }
        while(!stack.empty()) {
            result += stack.top(); stack.pop();
            if(!stack.empty()) result += " ";
        }
        return result;
    }
```
or 
2 pointer 1 pass
```cpp
    string reverseWords(string s) {
        int i=0,n=s.size(),l=0,r=0;
        reverse(s.begin(),s.end());
        while(i<n){
            while(i<n&&s[i]!=' '){ //if not space
            	s[r++]=s[i++];
            }
            if(l<r){
            	reverse(s.begin()+l,s.begin()+r);
            	if(r==n)break;
            	s[r++]=' ';
                l=r;
            }
        	i++; //if space
        }
        if(s[r-1]==' ')r--; //check if last character ' '
        s.resize(r);
        return s;
    }
```
![](img\reversewordsinstring.png)

---
# Longest Palindromic substr
```cpp
    string longestPalindrome(string s) {
        if(s.size()<=1)return s;
        vector<int> dp(s.size(),0);
        int maxlen=1,st=0,n=s.size();
        	for(int i=0;i<n;i++){
        		int l=i,r=i; //odd length as only one center
        		while(l>=0&&r<s.size()&&s[l]==s[r]){
        			l--;
        			r++;
        		}
        		int len=r-l-1;
        		if(len>maxlen){
                    maxlen=len;
                    st=l+1;
                }
            }
    		for(int i=0;i<n-1;i++){
    			int l=i,r=i+1;//even lengthed with 2 centers
    			while(l>=0&&r<s.size()&&s[l]==s[r]){
        			l--;
        			r++;
        		}
        		int len=r-l-1;
        		if(len>maxlen){
                    maxlen=len;
                    st=l+1;
                }
        	}
        return s.substr(st,maxlen);
    }
```
---
check for both even lengthed and odd lengthed substring
can be shortened by below code
```cpp
extendPalindrome(s, i, i);  //assume odd length, try to extend Palindrome as possible
extendPalindrome(s, i, i+1);//assumes evenlength

///////
void extendPalindrome(String s, int j, int k) {
	while (j >= 0 && k < s.size() && s[j] == s[k]) {
		j--;
		k++;
	}
	if (maxLen < k - j - 1) {
		lo = j + 1;
		maxLen = k - j - 1;
	}
}}
```
---
# Roman to integer
```cpp
    int romanToInt(string s) {
        if(s.size()==0)return 0;
        unordered_map<char,int> T ={{'I',1},
                                  {'V',5},
                                  {'X',10},
                                  {'L',50},
                                  {'C',100},
                                  {'D',500},
                                  {'M',1000}
                                 };
        int num=0;
        for(int i=0;i<s.size()-1;i++){
            if(T[s[i]]<T[s[i+1]]){   I V  I<V so minus
                num=num-T[s[i]];
            }else{
                num=num+T[s[i]];
            }
        }
        num=num+T[s[s.size()-1]];  
        return num;
    }
```
# integer to Roman
```cpp
    string intToRoman(int num) {
        vector<int> val={1000,900,500,400,100,90,50,40,10,9,5,4,1};// 1 fucks up 4 and 9 in 10th place and 100th places so that 
        //means 10 fucks up 40 and 90 100 fucks up 400 and 900
        vector<string> ch={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans="";
        for(int i=0;i<13;i++){
            while(num>=val[i]){
                ans=ans+ch[i];
                num=num-val[i];
            }
        }
        return ans;
    }
```
---
string to integer
```cpp
    int myAtoi(string s) {
        int i=0,ind=1;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='+'||s[i]=='-'){
            ind=s[i]=='+'?1:-1;
            i++;
        }
        int num=0;
        while(s[i]>='0'&&s[i]<='9'){
            if(INT_MAX/10<num || ((INT_MAX/10==num)&&(s[i]-'0'>7))){
                if(ind==1)return INT_MAX;
                else
                return INT_MIN;
            }
            num=num*10+(s[i]-'0');
            i++;
        }
        return num*ind;
    }
```
- in INT_MAX/10 >num that means if you add any more numbers it will overflow
ex: lets say hypothet 431 ->INT_MAX , num =54 `43 < 54 `if you add any digit to 54 you will get overflow
- INT_MAX/10 == num 
- +2147483647. Value of INT_MIN is -2147483648
so INT_MAX/10 == num 214748364 == 214748364 so if the digit to be added is more than 7 it will overflow

---
# Longest Common Prefix
```
Input: strs = ["dog","racecar","car"]
Output: ""
```
```cpp
public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0) return "";    
        return longestCommonPrefix(strs, 0 , strs.length - 1);
}

private String longestCommonPrefix(String[] strs, int l, int r) {
    if (l == r) { //for one ele
        return strs[l];
    }
    else {
        int mid = (l + r)/2;
        String lcpLeft =   longestCommonPrefix(strs, l , mid);
        String lcpRight =  longestCommonPrefix(strs, mid + 1,r);
        return commonPrefix(lcpLeft, lcpRight);
   }
}

String commonPrefix(String left,String right) {  //to check for 2
    int min = Math.min(left.length(), right.length());       
    for (int i = 0; i < min; i++) {
        if ( left.charAt(i) != right.charAt(i) )
            return left.substring(0, i);
    }
    return left.substring(0, min);
}
```
- divide and conquor
---
# Rabin Karp
```cpp
bool check(string st,string pat,int ind){
	for(int i=0;i<pat.size();i++){
		if(st[ind++]!=pat[i])
			return false;
	}
	return true;
}
int rabinKarp(string st,string pat,int q){
	int d=26;  // for searching d characters for 1-9 d=10
	int m=pat.size();
	int n=st.size();
	int h=1;
    for (int i = 0; i < m - 1; i++) // h =d^m-1 used to remove leftmost ele in a slide
        h = (h * d) % q; 
	int p=0,t=0;
	for(int i=0;i<m;i++){
		p=(p*d+pat[i])%q;  //  d^m-1 *c1 +d^m-2 *c2 + cm
		t=(t*d+st[i])%q;
	}

	for(int i=0;i<=n-m;i++){ //if present in last 
		if(p==t){
			if(check(st,pat,i)){ //to make sure correct maybe sometimes you get wrong and that is why we get O(m*n) then
				return i;
			}
		}
		if(i<n-m){ //unless we have reached end n-m==end+1
			t=(d*(t-h*st[i])+st[i+m])%q; //removing left most and adding right ele to slide
		if(t<0){
			//when negative to make it positive we add q as result only within q
			t=t+q;
		}
		
		}
	}
	return -1;
}
```
- q=prime number
- best case:O(n+m)
- worst case when hash value messes up n*m

---
# kmp
```cpp
//i 1->   -> m
//curlen -> tells us what is prefix len before i
//eg   a a a a b
//in   0 1 2 3 4
//lps  0 1 2 3    => in=1 1 ele is common with prefix
// in 2, 2 ele aa common with prefix
// in 3, 3 ele  aaa common from start
//so in lps we try to find the prefix common then we check ele ehich is not matching with ele after prefix
// aab[aaa]ba -string
//    [aab]a -pat 
//  here aa matches with aa b != a
// so we move pointer in patern to prefix before it
//here aa is the prefix lps[1]=1
//so we move j pointer to ind=1 
void complps(string ch,int m,vector<int>& lps){
	int curlen=0;//points to starting index
	lps[0]=0;
	int i=1;//start after initial ele
	while(i<m){
		if(ch[i]==ch[curlen]){
			curlen++;
			lps[i]=curlen;
			i++; //move i forward
		}
		else{
			if(curlen!=0){
				//length of matched prefix is more than 1 so we go check
                //eg aaaab in this if len=3 means
                //3 ele match till before i 
				curlen=lps[curlen-1];
				//we search the current at ith pos ele with ch[curlen] after change
			}else{
				lps[i]=0;
				i++;
			}
		}
}
}
int kmp(string s,string pat){
	vector<int> lps(pat.size());
	complps(pat,pat.size(),lps);
	int i=0,j=0;
	int m=pat.size(),n=s.size(),len=0;
	while(i<n&&j<m){
		if(s[i]==pat[j]){
			i++; 
			j++;
		}else{
			if(j>0){  
                //if len of string till which it matches is more than 0 before i
			j=lps[j-1];
		}else{
            //the length of string which  matches till pointer i is 0 so we move forward
			i++;
			j=0;
		}
		}
	}
	if(j==m)
		cout<<s.substr(0,i-m)<<" "<<s.substr(i-m,m)<<" "<<s.substr(i,n-i);
	else
		cout<<"-1";
}
```
---
# min number of ele added to front to make it palindrome
```cpp
void complps(string ch,vector<int>& lps){
		int curlen=0;
		int i=1;
		int n=ch.size();
		lps[0]=0;
		while(i<n){
			if(ch[i]==ch[curlen]){
				curlen++;
				lps[i]=curlen;
				i++;
			}else{
				if(curlen>0){
					curlen=lps[curlen-1];
				}
				else{
					i++;
				}
			}
		}
}
int main(){
	string s="bab";
	string rev=s;
	reverse(rev.begin(),rev.end());
	string s2=s+"$"+rev;
	cout<<s2;
	vector<int> lps(s2.size());
	complps(s2,lps);
	cout<<s.size()-lps[s2.size()-1];
}
```
- find lps of `s +'$' + rev`
- here in rev we need to check the lps
- as in the problem we need to find biggest palindrome form left to some point before right
- `[...]...r `
- the portion we nee to add is after that bracket ...r
-  `[...]..r$r..[...]`
- soo we see both brackets need to be same
- where `[...]` both are palindrome
---

```cpp
int Solution::solve(string A) {
    int count = 0;
    while(A.size() > 1) {
        if(is_palindrome(A)) {
            return count;
        }
        A.pop_back(); //take one ele out if not palindrome
        count++;
    }
    
    return count;
}
```
O(n^2) soln

---
# for minimum number of insertions to make it a palindrome 
- find longest palindromic subsequence
- n - ans of above  
- as all other ele not in that subsequence so we add it
---
# version control
```
Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
```
```cpp
    int compareVersion(string version1, string version2) {
        int i=0,j=0,v1,v2;
        while(i<version1.size()||j<version2.size()){//the reason for or
            //as some have lesser revisions than other so its revision will be zero  for those
            v1=0,v2=0;
        while(i<version1.size()&&version1[i]!='.'){//go till you meet '.'
            v1=v1*10+(version1[i]-'0');
            i++;
        }
        while(j<version2.size()&&version2[j]!='.'){
            v2=v2*10+(version2[j]-'0');
            j++;
        }
            if(v1<v2)return -1;
            if(v1>v2)return 1;
            
            //unless you are not in last position and have more revisions to go
            if(i!=version1.size())i++; 
            if(j!=version2.size())j++;
    }
        return 0;
    }
``` 
---
# [valid number](https://leetcode.com/problems/valid-number/)
```java
public boolean isNumber(String s) {
    s = s.trim();
    
    boolean pointSeen = false;
    boolean eSeen = false;
    boolean numberSeen = false;
    boolean numberAfterE = true;
    for(int i=0; i<s.length(); i++) {
        if('0' <= s.charAt(i) && s.charAt(i) <= '9') {
            numberSeen = true;
            numberAfterE = true;
        } else if(s.charAt(i) == '.') {
            if(eSeen || pointSeen) {
                return false;
            }
            pointSeen = true;
        } else if(s.charAt(i) == 'e') {
            if(eSeen || !numberSeen) {
                return false;
            }
            numberAfterE = false;
            eSeen = true;
        } else if(s.charAt(i) == '-' || s.charAt(i) == '+') {
            if(i != 0 && s.charAt(i-1) != 'e') {
                return false;
            }
        } else {
            return false;
        }
    }
    
    return numberSeen && numberAfterE;
}
```
```
If we see [0-9] we reset the number flags.
We can only see . if we didn't see e or ..
We can only see e if we didn't see e but we did see a number. We reset numberAfterE flag.
We can only see + and - in the beginning and after an e
any other character break the validation.
At the and it is only valid if there was at least 1 number and if we did see an e then a number after it as well.

So basically the number should match this regular expression:

[-+]?(([0-9]+(.[0-9]*)?)|.[0-9]+)(e[-+]?[0-9]+)?
```
---
# urlify
change all spaces to %20
```cpp
void urlify(string s,int truelen){
    int c = 0;
    for(int i=0;i<truelen;i++){
        if(s[i]==' ')
            c++;
    }
    int len = truelen + c * 2;
    for (int i = truelen - 1;i++){
        if(s[i]==' '){
            s[len] = '0';
            s[len - 1] = '2';
            s[len - 2] = '%';
            len = len - 3;
        }else{
            s[len] = s[i];
            len--;
        }
    }
}
```
---