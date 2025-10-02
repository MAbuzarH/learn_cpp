#include <stdio.h>

int mystery(int a, int b);

int main()
{
    printf("%s", "Enter two positive integers: ");
    int x = 0; // first integer
    int y = 0; // second integer
    scanf("%d%d", &x, &y);

    printf("The result is %d\n", mystery(x, y));
    return 0;
}

 int mystery(int a, int b) {
   // base case
    if (1 == b) {
       return a;
    } 
   else { // recursive step
       return a + mystery(a, b - 1);
    } 
 } 
