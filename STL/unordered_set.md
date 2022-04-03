```c++
unordered_set <string> stringSet ;
stringSet.insert("fast") ;
 
string key = "slow" ;
 
//  find returns end iterator if key is not found,
//  else it returns iterator to that key
 if (stringSet.find(key) == stringSet.end())//not found