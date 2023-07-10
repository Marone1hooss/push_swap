#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void add(stack*list1,int k)
{
    int n=list1->len;
    int s=list1->size;
        if(n==s)
        {
            list1->size=s*2;
            int*p2=(int*)malloc(s*2*sizeof(int));
            for (int i=0;i<n;i++)
            {
                p2[i]=(list1->p)[i];
            }
            free(list1->p);
            list1->p=p2;
            (list1->len)+=1;
            (list1->p[list1->len-1])=k;
            (list1->last)=k;
            
        }
        else
        {
            (list1->len)+=1;
            (list1->p)[list1->len-1]=k;
            (list1->last)=k;


        }
    }
int pop(stack *l)
{
    l->len=l->len-1;
    int a=l->last;
    l->last=l->p[l->len-1];

    return a;
}

int top(stack *stack)
{
    return stack->last;
}

