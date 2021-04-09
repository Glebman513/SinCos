#include <stdio.h>
#include <math.h>

double factorial(int n)
{
    int f, i;
    f = 1;
    for(i = 1; i <= n; i++)
    {
        f *= i;
    }
    return f;
}


double MySin(double x)
{
    double sum,an,E;  //sum - частичная сумма ряда,an - очередной член ряда,E - точность
    int n;
    n = 1;
    an = x;  //первый член ряда
    sum = an;
    E = 0.01;
    while(an > E || an < -E)
    {
        an = pow(-1, n)  * pow(x, 2 * n + 1) / factorial(2 * n + 1);
        sum += an;
        n++;
    }
    return sum;
}

double MyCos(double x)
{
    double sum,an,E;  //sum - частичная сумма ряда,an - очередной член ряда,E - точность
    int n;
    n = 1;
    an = 1;  //первый член ряда
    sum = an;
    E = 0.01;
    while(an > E || an < -E)
    {
        an = pow(-1, n)  * pow(x, 2 * n) / factorial(2 * n);
        sum += an;
        n++;
    }
    return sum;
}

int test_factorial(){
    
    if(factorial(1) == 1 && factorial(3) == 6)
    {
        printf("Factorial test is ok\n");
    }
    else
    {
        printf("Factorial test failed\n");
    }
    
}

int main()
{
    double a,si,co;
    double pi = 3.14159265358979;
    printf("Input an angle:\n");
    scanf("%lf", &a);
    test_factorial();
    a = a * pi / 180;
    //printf("angle is %lf\n", a);
    si = MySin(a);
    co = MyCos(a);
    printf("Sin is %lf\n", si);
    printf("Cos is %lf\n", co);
}
