    #include<stdlib.h>
    #include<stdio.h>
    #include<time.h>
    #include <pthread.h>
    #include <iostream> 
    #include <time.h> 
    using namespace std; 
    void *thread_function(void *arg)
    {
             pthread_t pt;
             pt = pthread_self();
             printf("Thread %x corrio\n", (int)pt );
             pthread_exit( NULL );
    }

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
        srand(time(0));
        srand(time(NULL)); 
        clock_t t; 
        t = clock();
        int i ,j, asize , max1,Num_Threads,ret,status;
        int a1[10000];
        asize = 10000;
        Num_Threads = 4;
        pthread_t  threads[4];
        for (i = 0 ; i < Num_Threads ; i++){
         ret=pthread_create(&threads[i], NULL, thread_function, &a1[0] );
         if (ret != 0) {
                 printf( "Error creando threads %d\n", (int)threads[i] );
         }
        }
       for (i=0; i<asize/Num_Threads && j<asize; i++,j++){
         ret=pthread_join (threads[i], (void **)&status);
         if (ret != 0) {
                 printf( "Error juntando threads %d\n", (int)threads[i] );
          } else {
           printf( "Status = %d\n", status );
           }
        }
        for (i=0; i<asize; i++)
        {
           a1[i]= rand()%9;
        }
        max1=a1[0];
      int n = sizeof(a1)/sizeof(a1[0]); 
      for  (i=1; i<asize; i++)
         cout << a1[i] << " ";
         cout << findMaxRec(a1,n);
         if (max1 < a1[i]){
         max1=a1[i];
         printf(" el maximo es %d",max1);
        }
       t = clock() - t; 
       double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
        printf("\n took %f seconds to execute \n", time_taken); 
    return 0;
    }