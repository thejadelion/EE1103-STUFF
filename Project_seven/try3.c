#include <stdio.h>
#include <math.h>

float f(float x)
{
    return(4*x-1.8*pow(x,2)+1.2*pow(x,3)-0.3*pow(x,4));
}


float gold(float xl,float xu,float err)
{   printf("%f %f\n",xl,xu);
    float er=10;
    float xopt = 3;
    float r=2/3;

while (er>err){
    float p = (xu-xl);
    float d = r*p;
    float x1=xl+d;
    float x2=xu-d;
    if (f(x1)<f(x2))
    {
        xu=x1;
        printf("22222222222222222");
        xopt=x2;
        printf("%f %f %f \n",xl,xu,xopt);
    }
    else 
    {   
        xl=x2;
        printf("33333333333333333333");
        xopt=x1;
        printf("%f %f %f \n",xl,xu,xopt);
    }
    printf("%f %f %f \n",xl,xu,xopt);
    float er=(1-r)*fabs((xu-xl)/xopt)*100;
    if (er<err){break;}}

    return (xopt);
}
    

int main()
{
    printf("%f",gold(-2,6,1));
}