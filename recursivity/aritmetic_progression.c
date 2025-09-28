#include <stdio.h>

/*
The aritmetic progresson is defined by:
An = An-1 + d; An: is the term in the position n, and "d" is the incrementation

This program gives the term of the n-position, based on the base "base" (is the number of the beggining), the number of the term "n" and the incrementation "d"
*/

int aritmetic_progression(int a1, int n, int d)
{
    if(n == 1)
        return a1;
    else
        return d + aritmetic_progression(a1, n - 1, d);
}

int main()
{

    int option, base, position, incrementation, term, i, limit, number_terms;

    do
    {
        printf("\nOptions:\n");
        printf("1) Get the n-term\n");
        printf("2) Get the first n-terms\n");
        printf("3) Get the sum of the firts n-termns\n");
        printf("4) Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Base: ");
            scanf("%d", &base);

            printf("Position: ");
            scanf("%d", &position);

            printf("Incrementation: ");
            scanf("%d", &incrementation);

            term = aritmetic_progression(base, position, incrementation);
            printf("The term in the position %d is: %d", position, term);
            break;

        case 2:
            printf("Limit of terms: ");
            scanf("%d", &limit);

            for(i = 1; i <= limit; i++)
            {
                if(i == limit)
                    printf("%d\n", aritmetic_progression(base, i, incrementation));
                else
                    printf("%d, ", aritmetic_progression(base, i, incrementation));
            }

            break;

        case 3:
            int sum = 0, j;
            
            printf("Number of terms: ");
            scanf("%d", &number_terms);

            for(j = 1; j <= number_terms; j++)
            {
                sum += aritmetic_progression(base, j, incrementation);
            }

            printf("The sum of the firsts %d terms is: %d\n", j, sum);
            
            break;

        default:
            printf("Option out of the parameters (1 - 4)\n");
            break;
        }
    }while(option != 4);

    return 0;
}
