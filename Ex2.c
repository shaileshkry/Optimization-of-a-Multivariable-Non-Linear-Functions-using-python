#include<stdio.h>
# include <stdlib.h>
# include <math.h>
#include <string.h>
double exhaustive_search();
double objective_function();
int main()
{
 double a,b;
 printf("Exhaustive Search Method\n");
 printf("enter a=lower limit of x \n b=upper limit of x\n");
 scanf("%lf %lf",&a,&b);
 exhaustive_search(a,b);

}
double objective_function(double x)
{

	return(-(8+x*x*x-2*x-2*exp(x)));
}


double exhaustive_search(double a,double b)
{
	int n,i,fun_ev;
	double delta,x1,x2,x3,f1,f2,f3;
	FILE *fptr;
	printf("enter number of intermediate points n\n");
	scanf("%d",&n);

	/*step 1*/
	delta=(b-a)/n;
	x1=a;
	x2=x1+delta;
	x3=x2+delta;
	fun_ev=0;
	f1=objective_function(x1);
	f2=objective_function(x2);
	f3=objective_function(x3);
	i=1;
	fun_ev=fun_ev+3;
	fptr=fopen("Output in Tablular form","w");
	fprintf(fptr,"SI\tx1\tx2\tx3\tf(x1)\tf(x2)\tf(x3)\n");
	do
	{
		fprintf(fptr,"%d\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t\n",i,x1,x2,x3,f1,f2,f3);
	if(f1>=f2)
	{

	if(f2<=f3)
	{
	}
	}
    x1=x2;
	x2=x3;
	x3=x2+delta;
	f1=f2;
	f2=f3;
	f3=objective_function(x3);
	fun_ev++;
	i=i+1;
	}
	while(x3<b);
	printf("\nThe maxima lies between (%lf %lf)\n",x1,x3);
	printf("\nTotal no of function evaluation is %d\n",fun_ev);
	printf("\nTotal no of iteration is %d\n",i);
	fprintf(fptr,"\nThe maxima lies between (%lf,%lf)",x1,x3);
	fprintf(fptr,"\nTotal number of function evaluations is %d",fun_ev);

	fclose(fptr);
	return 0;
}
