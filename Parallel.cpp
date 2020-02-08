// Recursive C++ program to find maximum 

#include <iostream> 
#include <time.h> //or ctime
#include <stdio.h> 
#include <time.h> 
#include <thread>   
using namespace std; 


int findMaxRec(int A[], int n) 
{ 
    int start = 0, end = n-1; 
    int lowVal =10;
    int highVal = 20;
    if (n == 1) 
        return A[0]; 
    for (int i=0; i<=end;) 
    { 
        //si el elemento es mas pequeno que el rango, se pone disponible en la siguiente posicion
        if (A[i] < lowVal) 
            swap(A[i++], A[start++]);

        //si el elemento es mas largo que el rango
        else if (A[i] > highVal) 
            swap(A[i], A[end--]); 

        else
            i++; 
    }
    return max(A[n-1], findMaxRec(A, n-1));  

} 



int main() 



{ 
    srand(time(NULL)); //seed the generator
    int arr[10000];
    for(int i = 0; i < 10000; i++)
    {
        arr[i] = rand()%50000; //huge number, you can give it a range by rand() % limit
    }
    int n = sizeof(arr)/sizeof(arr[0]); 
    clock_t t; 
    t = clock(); 
    //cout <<  findMaxRec(arr, n); 
    thread th1(findMaxRec,arr, n); 
    th1.join();
    //std:: thread first (findMaxRec(arr, n));

    //std:: thread second (Particion(A, n, 10, 20));

   // first.join();                // pauses until first finishes

   // second.join();               // pauses until second finishes

    ///cout <<  findMaxRec(arr, n); 
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("\n took %f seconds to execute \n", time_taken); 
    return 0; 

    



}