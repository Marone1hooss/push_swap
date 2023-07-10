#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"functions.h"
#include"stack.h"


int main(int argc, char**argv)
{
    int N;
    scanf("%d",&N);
    int* arr=(int *)malloc(N*sizeof(int));
    for (int i=0;i<N;i++) {
        int t;
        scanf("%d",&t);
        arr[i]=t;
    }
    /* simplifying the elements of the array to be in range 0 to N where N is the lenth of the array */

    
    int *simplarr=(int*)malloc(N*sizeof(int));
    simplarr= simplifyArray(arr,N);
    
    int max_bits=0;//the lenth of the biggest number if binary(the biggest number is N-1)

    while ((N-1 >> max_bits)!=0)
    {
        max_bits++;
    }

    stack sA;
    stack sB;
    char ** output=(char**)malloc(10000000*sizeof(char*));
    for (int i=0;i<10000000;i++) output[i]=(char*)malloc(3*sizeof(char));
    int c=0;
    for (int i=0;i<max_bits;i++)
    {
        sA.len=0;
        sA.size=2;
        sA.p=(int*)malloc((sA.size) * sizeof(int));
        sB.len=0;
        sB.size=2;
        sB.p=(int*)malloc((sB.size) * sizeof(int));
        for (int j=N-1;j>=0;j--)
        {
            if (((simplarr[j]>>i)&1)==1) 
            {
                add(&sA,simplarr[j]);
                output[c]="ra";
                c++;
            }
            else 
            {
                add(&sB,simplarr[j]);
                output[c]="pb";
                c++;
            }
        }
        int d=0;
        while (sA.len>0)
        {
            simplarr[d]=pop(&sA);
            d++;
        }
        
        while (sB.len>0)
        {
            simplarr[d]=pop(&sB);
            d++;
            output[c]="pa";
            c++;
        }

        free(sA.p);
        free(sB.p);
    }

    for (int i=0;i<N;i++) printf("%d ",simplarr[i]);
    printf("\n%d\n",c);
 /*     for (int i=0;i<c;i++)
    {
        printf("%s\n",output[i]);
    }   */
  
}

