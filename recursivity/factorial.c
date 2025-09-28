#include <stdio.h>

int factorial(int n)
{
    if(n == 0)
        return 1;
    
    return n * factorial(n - 1);
}

int main()
{

    int number;

    printf("number: ");
    scanf("%d", &number);

    printf("factorial of %d: %d\n", number, factorial(number));

    return 0;
}
