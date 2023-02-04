#include <stdio.h>
#include <math.h>

float f(float x){
    return tan(M_PI* 50/180)*x - 9.81/(2*625*pow(cos(M_PI*50/180),2))*pow(x,2)+1;
}


float gold(float xl,float xu,float err)
{   printf("%f %f\n",xl,xu);
    float er=10;
    float xopt = 3;
    float r=(pow(5,0.5)-1)/2;

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
    printf("%f",gold(0,60,1));
}