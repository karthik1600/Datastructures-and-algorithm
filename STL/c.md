for unsigned
```c
unsigned int myvariable = 4294967294;
 printf("%u",myvariable);

```
scanf
```c
scanf("%d", &b);
//%f for float* and %lf for double*.
```
> In general, it is best to use scanf as shown here -- to read a single value from the keyboard. Use multiple calls to scanf to read multiple values. In any real program, you will use the gets or fgets functions instead to read text a line at a time. Then you will "parse" the line to read its values. The reason that you do that is so you can detect errors in the input and handle them as you see fit.

---
# get char and putchar
putchar() function is a file handling function in C programming language which is used to write a character on standard output/screen. getchar() function is used to get/read a character from keyboard input. Please find below the description and syntax for above file handling function.
```c
#include <stdio.h>
#include <ctype.h>
int main()
{
   char c;
   printf("Enter some character. Enter $ to exit...\n");
   while (c != '$');
   {
      c = getchar();
      printf("\n Entered character is: ");
      putchar(c);
      printf("\n")
   } 
   return 0;
}
```
```
Enter some character. Enter $ to exit…
A
Entered character is: A
B
Entered character is: B
$
Entered character is: $
```
---
# scan input in desired format
```
scanf("%d:%d",&nusm1,&nums2);
```
```
5:4
```
nums1=5,nums2=4

---