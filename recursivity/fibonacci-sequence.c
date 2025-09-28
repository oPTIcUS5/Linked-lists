#include <stdio.h>

int fibonacci(int n)
{
    if(n == 0)
        return 0;

    if(n == 1)
        return 1;
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n, i, fib_term;

    printf("number of terms: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        fib_term = fibonacci(i);

        if (i == n - 1)
        {
            printf("%d\n", fib_term);
        }
        else
        {
            printf("%d, ", fib_term);
        }
    }
}
