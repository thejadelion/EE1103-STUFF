#include <stdio.h>
#include <math.h>

// This is the function oracle
float f(float x){
    return 4*x - 1.8*pow(x,2) + 1.2*pow(x,3) - 0.3*pow(x,4);
}


int main(){
    // We define the starting points x0, x1, x2
    double x0 = 1.75, x1 = 2, x2 = 2.5;
    // x3 is the predicted maximum value
    double x3 = 1.25;

    double temp = 1;
    printf("The value isn't %f\n", fabs((x3 - x2)/x3));
    int ct = 4;
    do
    {   
        double temp = x3;
        x3 = (f(x0)*(pow(x1, 2)-pow(x2, 2))+f(x1)*(pow(x2, 2)-pow(x0, 2))+f(x2)*(pow(x0, 2)-pow(x1, 2)))/(2*(f(x0)*(x1-x2)+f(x1)*(x2-x0)+f(x2)*(x0-x1)));
        printf("%f\n", x3);
        if (f(x3)>f(x1)){
            if (x3>x1){
                x0 = x1;
                x1 = x3;
            }
            else{
                x2 = x1;
                x1 = x3;
            }
        }
        else{
            if (x3>x1){
                x2 = x3;
            }
            else{
                x0 = x3;
            }
        }
        ct -= 1;
    } while (ct>0);
    
    printf("The value of the extrema is %f", x3);
 }