#include <stdio.h>
#include <math.h>

// defining the function
float f(float x){
    return tan(M_PI* 50/180)*x - 9.81/(2*625*pow(cos(M_PI*50/180),2))*pow(x,2)+1;
}


float gold(float xl,float xu,float err)//defining function that uses golden ratio search
{   
    float er=10;//initial value of error to start the loop
    float xopt;//this the value at which function gives maxima
    while (2>1){
    float r=(pow(5,0.5)-1)/2;//defining the value of gold ratio
    float p = (xu-xl);//the difference between lower and upper limits
    float d = r*p;
    float x1=xl+d;//defining x1 and x2
    float x2=xu-d;



    if (f(x1)>f(x2))//redefining x1 and x2 if f(x1)>f(x2)
    {
        xl=x2;
        
        xopt=x1;
        
    }

    else //redefining x1 and x2 if f(x1)<f(x2)
    {  
        xu=x1;
        xopt=x2;
    }
   
    float er=(1-r)*fabs((xu-xl)/xopt)*100;//defining the relative error
    if (er<err){
        break;
    }
}
    return (xopt);//returning the x at which maxima occurs
}

    

int main()
{
    printf("%f, and the value is %f",gold(0,60,0.1), f(gold(0,60,0.1)));//calling the function
}