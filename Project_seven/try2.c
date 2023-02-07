#include <stdio.h>
#include <math.h>


//We define the functin oracle
float f(float x){
    return 4*x - 1.8*pow(x,2) + 1.2*pow(x,3) - 0.3*pow(x,4);
}

//We define the function's derivative oracle
float fdash(float x){
    return  4 - 3.6*x + 3.6*pow(x, 2) - 1.2*pow(x, 3);
}

//We define the function's double derivative oracle
float fddash(float x){
    return -3.6 + 7.2*x - 3.6*pow(x,2); 
}

int main(){
    double xi = 2; // We define the initial guess 
    double es = 10; // We define the initial error percentage as 1000%
    // We write a while loop which runs till the error reaches 1%
    while (fabs(es)>0.01){
        double xi1 = xi - fdash(xi)/fddash(xi); // We define the new value calculated in the next iteration
        es = (xi1 - xi)/xi * 100; // We calculate the error percentage
        xi = xi1; // We then update the value of xi
    }
    printf("The minima we get is %f", xi); // We output the answer we get.
}
