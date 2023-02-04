#include <stdio.h>
#include <math.h>


float f(float x){
    return 4*x - 1.8*pow(x,2) + 1.2*pow(x,3) - 0.3*pow(x,4);
}

float fdash(float x){
    return  4 - 3.6*x + 3.6*pow(x, 2) - 1.2*pow(x, 3);
}

float fddash(float x){
    return -3.6 + 7.2*x - 3.6*pow(x,2); 
}

int main(){
    double xi = 2;
    double es = 10;
    while (fabs(es)>0.01){
        double xi1 = xi - fdash(xi)/fddash(xi);
        es = (xi1 - xi)/xi * 100;
        xi = xi1;
    }
    printf("The minima we get is %f", xi);
}
