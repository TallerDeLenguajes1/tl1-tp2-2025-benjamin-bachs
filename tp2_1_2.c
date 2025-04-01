// codigo a completar
#define N 20
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i;
    double vt[N];
    for (i = 0; i < N; i++)
    {
        *(vt+i)=1+rand()%100;
        printf("%f   ", *(vt+i));
    }
    return 0;
}
