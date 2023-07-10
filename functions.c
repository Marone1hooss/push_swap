#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


void intmerge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int L[n1], R[n2];
    
    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back into arr
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void intmergeSort(int * arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Sort first and second halves
        intmergeSort(arr, left, mid);
        intmergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        intmerge(arr, left, mid, right);
    }
}


int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if target is present at the middle index
        if (arr[mid] == target) {
            return mid;
        }
        
        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }
    
    // If target is not found, return -1
    return -1;
}

int * simplifyArray(int array[],int N) 
{

int *array0=(int*)malloc(N*sizeof(int));

for (int j=0;j<N;j++) array0[j]=array[j];

intmergeSort(array,0,N-1);
int* sortedarr =array;
int * simplarr=(int *)malloc(N*sizeof(int));
for (int i=0;i<N;i++)
{
    simplarr[i]=binarySearch(sortedarr,0,N-1,array0[i]);
}
return simplarr;
}

