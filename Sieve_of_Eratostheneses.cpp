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
        i*i as to be less or equal to num.
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


int main()
{
    long long a;
    cin >> a;
    Sieve(a);
    for (long long i = 0; i < (int) primes.size(); i++)
    {
        cout << primes[i] << endl;
    }

    return 0;
}
