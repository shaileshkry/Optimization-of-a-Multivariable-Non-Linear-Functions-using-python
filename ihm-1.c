#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>

double interval_halving_method(double a,double b);
double objective_function(double x);
    int main()
{

    double a ,b;
    printf("Enter the lower limit of x=",a);
    scanf("%lf",&a);
    printf("Enter the upper limit of x=",b);
    scanf("%lf",&b);
    interval_halving_method(a,b);
}
    double objective_function(double x)
{

    return (-pow((2*x - 5), 4) - pow((x*x - 1), 3));          //objective Functions
    //return( -(8 + pow(x,3) -2*x -2*exp(x)));                  //objective Functions
    //return (-4*x*sin(x));                                     //Objective Functions
    //return (2*pow((x-3), 2) + exp(0.5*x*x));                  //objective Functions
    //return (x*x - 10*exp(0.1*x));                             //objective Functions
    //return  (-(20*sin(x) - 15*x*x) );                         //Objective Functions

}
double interval_halving_method(double a,double b)

{
 double x1,x2,xm,fm,f1,f2,L,e,error,func_eval,i;
 FILE *fptr;
printf("\n**********************************\n");
printf("Interval halving method\n");
L=(b-a);       //step 1
error = pow(10,-3);
printf("\n**********************************\n");
func_eval=0;
i=0;
fptr=fopen("Output.txt","w");
fprintf(fptr,"Output in tabulur form\n");
fprintf(fptr,"SI\tx1\tx2\txm\tf1\tf2\tfm\n");
while(L>0.001)
{
x1=(a+L/4);    //step 2
f1=objective_function(x1);
printf("The value of f(x1) %lf\n",f1);
x2=(b-L/4);
f2=objective_function(x2);
printf("The value of f(x2) %lf\n",f2);
xm=(a+b)/2;
fm=objective_function(xm);
fprintf(fptr,"%.1lf\t%0.2lf\t%0.2lf\t%0.2lf\t%0.2lf\t%0.2lf\t%0.2lf\n",i,x1,x2,xm,f1,f2,fm);
func_eval=func_eval+2;
if(f1<fm)              //step 3
{
    b=xm;
    xm=x1;
}
else if(f2<fm)     //step 4
        {
    a=xm;
    xm=x2;
        }
else
    {
        a=x1;
        b=x2;
    }
        L=(b-a);           //step 5
        i++;
        printf("L    %lf\n",L);
}
printf("\n");
       printf("Total no of function Evaluation=%lf",func_eval);

       printf("\n");
      printf("Total no. of iteration=%lf\n",i);
       printf("\n");
       printf("Minima lies between:(%lf %lf)",a,b);
       fprintf(fptr,"\nThe minimum point lies between (%lf,%lf)",a,b);
	fprintf(fptr,"\ntotal number of function evaluations: %lf",func_eval);

    return(0);
}

