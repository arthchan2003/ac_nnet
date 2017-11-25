#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    float x[10] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    float y[10] = {0.0, 3.0, 6.0, 9.0, 12.0, 15.0, 18.0, 21.0, 24.0, 27.0};

    int i;
    int N=10;
    printf("The x,y pair\n");
    for (i=0;i< N;i++){
        printf("x:%-8.2f y:%-8.2f\n", x[i],y[i]);
    }
    printf("\n");

    float xbar, ybar, xsquarebar, xybar;
    xbar=ybar=xsquarebar=xybar=0.0;

    //Calculate various statistic, xbar, ybar, xsquarebar, xybar
    for(i=0;i< N;i++){
        xbar += x[i];
        ybar += y[i];
        xsquarebar += x[i] * x[i];
        xybar += x[i] * y[i];
    }

    xbar/=N;
    ybar/=N;
    xsquarebar/=N;
    xybar/=N;

    printf("xbar %f, ybar %f, xsquarebar %f, xybar %f\n", xbar, ybar, xsquarebar, xybar);

    //Suppose we are fitting y= a + b;
    //Then b = (xybar - xbar * ybar) /(xsquarebar - xbar^2);
    //And a is simply ybar - b * xbar.  
    //For Proof. See Regression by Bingham p.4. 

    float b = (xybar - xbar * ybar ) /(xsquarebar - xbar * xbar);
    float a = ybar - b * xbar;

    printf("a: %f b: %f\n", a,b);
    
}
