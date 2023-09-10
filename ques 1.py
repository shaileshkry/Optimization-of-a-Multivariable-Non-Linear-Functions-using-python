from sre_constants import IN
from tkinter import Variable
from unittest import result
import numdifftools as nd
import random
import numpy as np

def fun(Variable):
    result = 0
    for i in range(1, (len(Variable) +1)):
        result = result + (i*(Variable[i-1]**2))
    return result

def grad(Variable):

    gradient_results = nd.Gradient(fun)(Variable)
    return gradient_results 

def exhaustive_search(input_variables,Variable, gradient):
    n = input_variables[1]
    a = -10
    b = 10
    h = (b-a)/n
    x1 = a
    x2 = x1 + h
    x3 = x2 + h
    Variable1 = Variable - x1*gradient
    Variable2 = Variable - x2*gradient
    Variable3 = Variable - x3*gradient
    f1= fun(Variable1)
    f2 = fun(Variable2)
    f3 = fun(Variable3)

    while(x3 <= b):
        if(f1 >= f2 and f2 <= f3):
            return x1, x3
        else:
            x1 = x2                         #Updating points
            x2 = x3
            x3 = x2 + h
            Variable3 = Variable - x3*gradient
            f1 = f2
            f2 = f3
            f3 = fun(Variable3)


def interval_halv(input_variables, Variable, gradient, lower, upper):
    error = 1/pow(10, input_variables[2])
    lo = abs(upper - lower)                  
    xm = (lower + upper)/2
    Variablen = Variable - xm*gradient
    fn = fun(Variablen)  
    while( abs(lo) >= error):
        A = lower + lo/4                  
        B = upper - lo/4
        Variable1 = Variable - A*gradient
        Variable2 = Variable - B*gradient
        f1 = fun(Variable1)
        f2 = fun(Variable2)
        
        if ( f1 < fn):
            upper = xm                     
            xm = A
            fn = f1
        elif( f2 < fn):
            lower = xm                      
            xm = B
            fn = f2
        else:
            lower = A                     
            upper = B
        
        lo = (B - A)

    return (A + B)/2                   




file1 = open('Input_file.txt', 'r')
file2=open("output.txt",'w')
lines = file1.read().splitlines()
input = []                        #create list file
for line in lines:
    if line.isdigit() == True:
        input.append(int(line))

input_variables = np.array(input)
Variable = np.random.uniform(-5.12, 5.12, size = (input[0]))
print("**************************************************************")
print("  Sum Squares Function Function ")
print("**************************************************************")
print('**************************************************************',file=file2)
print(' Sum Squares Function ',file=file2)
print('**************************************************************',file=file2)
print('The Initial values for the variables are :\n')
print('The Initial values for the variables are :',file=file2)
print(Variable, '\n')
print(Variable, '',file=file2)
print('The Initial Value of Objective Function is:')
print(fun(Variable))
m = input_variables[3]
n = input_variables[4]
eps1 = 1/(10**n)
eps2 = pow(10, -10)
gradient = grad(Variable)
k = 0  
print('iteration \t fuction value',file=file2)                                       #k= no. of iteration
while(np.linalg.norm(gradient) >= eps1):
    print(k,'\t\t',fun(Variable),file=file2)
    if k < m:
        Variable_pre = Variable
        lower, upper = exhaustive_search(input_variables, Variable, gradient)
        alpha = interval_halv(input_variables, Variable, gradient, lower, upper)
        Variable = Variable - (alpha * gradient)
        norm_value = np.linalg.norm(Variable - Variable_pre)/np.linalg.norm(Variable_pre)

        if(np.linalg.norm(np.dot(grad(Variable), grad(Variable_pre)))) <= eps2:
            break
        if norm_value <= eps1:
            break
        else:
            k = k+1                     
            gradient= grad(Variable)
    else:
        break
       

print('The no. of iteration  are :\n')
print('The no. of iteration  are :',file=file2)   
print(k,file=file2)
print(k)
print("**************************************************************")
print('The Finals values for the variables are :\n')
print('The Finals values for the variables are :',file=file2)
final_result  = np.round(Variable, 5)
print(np.absolute(final_result))
print(np.absolute(final_result),file=file2)
print('The Final Value of Objective Function is:')
print('The Final Value of Objective Function is:',file=file2)
print(np.round(fun(Variable), 5))
print(np.round(fun(Variable), 5),file=file2)
print("**************************************************************",file=file2)
file2.close()
