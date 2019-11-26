#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Write your code below
void initPrimes(bool prime[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i == 1)
        {
            prime[i] = false;
        }
        else
        {
            prime[i] = true;
        }
    }
}

void sievePrimes(bool prime[], int n)
{
    int count = 2;
    while (count <= n)
    {
        if (prime[count] == true)
        {
            for (int i = count + count; i <= n; i += count)
            {
                prime[i] = false;
            }
        }
        count++;
    }
}
#define MAX 10001
void printPrimes(bool prime[], int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    bool prime[n + 1];
    initPrimes(prime, n);
    sievePrimes(prime, n);
    printPrimes(prime, n);
}

void printPrimes(bool prime[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (prime[i] == true)
        {
            printf("%d\n", i);
        }
    }
}
