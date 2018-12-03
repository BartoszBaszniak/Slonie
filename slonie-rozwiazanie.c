#include <stdio.h>
#include <stdlib.h>


long long int min(long long int a,long long int b)
{
    if(a>=b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int w[1000000];           // weight
int p[1000000];           // position
int dp[1000000];          //destination position
int minA=100000000;
int r;
int permut[100000];
int x[10000000];
int main()
{

    long long int pier,dru;
    long long int wynik=0;
    int N;
    int i;

    FILE*plik;
    plik=fopen("slo0.in","r");          //file path
    fscanf(plik,"%d",&N);
    for(i=0;i<N;i++)
        {
            fscanf(plik,"%d",&w[i]);
        }
    for(i=0;i<N;i++)
        {
            fscanf(plik,"%d",&p[i]);
        }
    for(i=0;i<N;i++)
        {
            fscanf(plik,"%d",&dp[i]);
        }
    fclose(plik);

    for(i=0;i<N;i++)
        {
            minA=min(w[i],minA);       // minimal weight of all
        }
    for(i=0;i<N;i++)
        {
            r=dp[i];
            permut[r]=p[i]; //permutation of the set
        }
    for(int y=0;y<N;y++)
        {
            if(x[y]!=(dp[y]))
                {
                    int C=0;
                    int minC=100000000;
                    long long int suma =0;
                    i=y;
                    for (;;)
                        {
                            suma=suma+w[i];
                            minC=min(minC,w[i]);   //minimal weight of cycle
                            i=permut[i+1]-1;
                            x[i]=dp[i];
                            ++C;
                            if(i==y)
                                {
                                    break;
                                }

                        }
                    pier=suma + (C-2)*minC;        //method 1
                    dru=suma+minC+(1+C)*minA;      //method 2
                    wynik =wynik + min(pier, dru);

                }
        }

printf("%lli\n",wynik);

return 0;
}
