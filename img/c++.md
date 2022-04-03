# cpp
---
# setprecisions
```cpp
// 4 digits after the decimal point  
    printf("%0.4f", num); 
//or
number=0.123242;
cout<<fixed<<setprecision(4)<<number;
```
---
# Taking String input with space in C
```cpp
    char str[100];
    scanf("%[^\n]s",str); 
    printf("%s",str);
    // or 
    char input[100];
    cin.getline(input,sizeof(input));
```
- [ ] is the scanset character. ^\n tells to take input until newline doesn’t get encountered. Here we used ^ (XOR -Operator ) which gives true until both characters are different. Once the character is equal to New-line (‘\n’)

---