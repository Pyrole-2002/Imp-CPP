#include <bits/stdc++.h>
using namespace std;

/*
Sieve of Eratostheneses works in the following way:
    1. First put p=2 as its the first prime number.
    2. Mark all numbers (n) such that n%p==0 and n>=(n*n).
    3. Move to the next unmarked number (p=3) and repeat step-2.
    4. Move to the next unmarked number (p=5) and repeat step-2.
    5. Similarly keep on moving to the next unmarked numbers.
    6. Every value that p takes is a prime number.
*/

vector<long long> primes;


void Sieve(long long num)
{
    /*
    Sieve function finds and stores all the primes (p) such that p<=num.
    */

    bool numbers[num + 1];
    for (long long i = 0; i < num+1; i++)
    {
        numbers[i] = true;
    }

    numbers[0] = false;
    numbers[1] = false;

    for (long long i = 0; i*i <= num; i++)
    {
        /*
        Since we start marking numbers after i*i till num,
        i*i has to be less or equal to num.
        */
        if (numbers[i] == true)
        {
            /*
            Marking all multiples of i from i*i till num.
            */
            for (long long j = i*i; j <= num; j += i)
            {
                numbers[j] = false;
            }
        }
    }
    for (long long i = 0; i < num+1; i++)
    {
        if (numbers[i] == true)
        {
            primes.push_back(i);
        }
    }
}


/*
In order to find the total number of factors of a number (num), there exists a theorem:
The number of primes = (1+a1)*(1+a2)*(1+a3).....*(1+an),
Where a1, a2, a3....., an are the counts of the distinct prime factors of num.
*/

long long Factors(long long num)
{
    long long nfact = 1;
    long long quotient = num;
    Sieve(num);
    for (long long i = 0; i < (long long) primes.size(); i++)
    {
        long long a = 0;
        while ((quotient % primes[i] == 0)&&(quotient != 1))
        {
            quotient /= primes[i];
            a++;
        }
        nfact *= (a+1);
    }

    return nfact;
}

int main()
{
    long long a;
    cin >> a;
    cout << Factors(a) << endl;

    return 0;
}
