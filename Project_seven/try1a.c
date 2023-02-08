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
    double temp = 1; //temp is a variable that stores intermediate information
    int ct = 4; //We initialise the counter variable
    do
    {   
        double temp = x3; //temp holds the old value of x3
        //We find the new value of x3 using the formula for the extremum of the parabola
        x3 = (f(x0)*(pow(x1, 2)-pow(x2, 2))+f(x1)*(pow(x2, 2)-pow(x0, 2))+f(x2)*(pow(x0, 2)-pow(x1, 2)))/(2*(f(x0)*(x1-x2)+f(x1)*(x2-x0)+f(x2)*(x0-x1)));
        printf("%f\n", x3); //We output this to keep track of the progress the program makes

        // We reassign as per the secant method.
        x0=x1; 
        x1=x2; 
        x2=x3;
        
        ct -= 1; //We decrease the value of counter by 1
    } while (ct>0); //We use a do-while loop so we give the condition accordingly for the loop to run 4 times.
    
    printf("The value of the extrema is %f", x3);//Finally, we output the result to the user.
 }