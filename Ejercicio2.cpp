/******************************************************************************
Domain decomposition 
: 
Divide 
data into pieces
–
Determine how to associate computations with the data
–
Focuses on the largest and most frequently accessed data structure
•
Functional 
decomposition 
: 
Divide 
computation into pieces
–
Determine how to associate data with the computations
•
Independent 
tasks : 
subdivide computation into tasks 
that do 
not 
depend on each other (
embarrassingly parallel 
)
•
Array parallelism : 
simultaneous operations on entries 
of vectors
, 
matrices, or other arrays
•
Divide
-
and
-
conquer :
recursively divide problem 
into tree
-
like 
hierarchy 
of 
subproblems
•
Pipelining :
break 
problem into sequence of stages 
for  each 
of 
sequence of 
objects
Please post examples for each on piazza.






Anotaciones

*******************************************************************************/

#include <iostream> 
using namespace std; 
  

int findMaxRec(int A[], int n) 
{ 

    if (n == 1) 
        return A[0]; 
    return max(A[n-1], findMaxRec(A, n-1)); 
} 

void Particion(int arr[], int n, 
                int lowVal, int highVal) 
{ 
    //inicializa las posiciones disponibles para un pequeno rango y largo rango de elementos
    int start = 0, end = n-1; 
  
    // Agarra los elementos desde la izquierda
    for (int i=0; i<=end;) 
    { 
    
        //si el elemento es mas pequeno que el rango, se pone disponible en la siguiente posicion
        if (arr[i] < lowVal) 
            swap(arr[i++], arr[start++]); 
  
        //si el elemento es mas largo que el rango
        else if (arr[i] > highVal) 
            swap(arr[i], arr[end--]); 
  
        else
            i++; 
    } 
} 
  

int main() 
{ 
    int A[] = {1, 4, 45, 6, -50, 10, 2}; 
    int n = sizeof(A)/sizeof(A[0]); 
    Particion(A, n, 10, 20);
    for (int i=0; i<n; i++)
        cout << A[i] << " ";
    cout <<  findMaxRec(A, n); 
    return 0; 
} 