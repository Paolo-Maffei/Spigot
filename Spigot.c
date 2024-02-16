#include <stdio.h>

#define PRECISION 65536
#define LEN ((PRECISION*10)/3)+1

int i;
int j;
int k;
int q;
int x;
int n;
int d;
int a[LEN];
char *s;

int main()
{
    x = 0;
    n = 0;
    d = 0;

    // initialize array with all 2's
    i=0;
    while(i<LEN)
    {
        a[i] = 2;
        i=i+1;
    }

    // repeat calculation loop 'PRECISION' times
    j=1;
    while(j<=PRECISION)
    {
        q = 0;

        // calculate q
        i=LEN;
        while(i>0)
        {
            x = 10 * a[i-1] + q * i;
            a[i-1] = x % (2 * i - 1);
            q = x / (2 * i - 1);
            i=i-1;
        }

        a[0] = q % 10;
        q = q / 10;

        // print different digits based on q value

        // if q is 9, increment counter
        if (q == 9)
        {
            n = n + 1;
        }
        // if q is 10 (overflow case), write 9 then digit + 1
        else
            if (q == 10)
            {
                putchar(d + '1');

                k=0;
                while(k<n)
                {
                    putchar('0');
                    k=k+1;
                }

                d = 0;
                n = 0;
            }
            else
            {
                // if q is not 9 or 10, print d
                putchar(d+'0');

                // advance digit to next q
                d = q;

                // handle nine
                if (n != 0)
                {
                    k=0;
                    while(k<n)
                    {
                        putchar('9');
                        k=k+1;
                    }
                    n = 0;
                }
            }
        j=j+1;
    }

    // add the final digit
    putchar(d+'0');
}
