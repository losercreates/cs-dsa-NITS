#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX (int)1e4

void generateRandomInput(int n, int input[])
{
    for (int i = 0; i < n; i++)
        input[i] = rand() % MAX;
}

void generateSortedInput(int n, int input[])
{
    for (int i = 0; i < n; i++)
        input[i] = i;
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n){
    
    int arrcpy[n];
    for(int i=0;i<n;i++)
        arrcpy[i]=arr[i];
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arrcpy[j] < arrcpy[min_idx])
            min_idx = j;
        swap(&arrcpy[min_idx], &arrcpy[i]);
    }
}
void bubbleSort(int arr[], int n)
{
    int arrcpy[n];
    for(int i=0;i<n;i++)
        arrcpy[i]=arr[i];
   int i, j;
   for (i = 0; i < n-1; i++)     
       for (j = 0; j < n-i-1; j++)
           if (arrcpy[j] > arrcpy[j+1])
              swap(&arrcpy[j], &arrcpy[j+1]);
}
int main()
{

    srand(time(0));
    int n;
    printf("Enter size of input > ");
    scanf("%d", &n);

    int sortedinput[n];
    int randominput[n];
    generateRandomInput(n, randominput);
    generateSortedInput(n, sortedinput);

    FILE *inputFile = fopen("inputRandom.txt", "w");

    if (inputFile != NULL)
    {
        printf("Sorted Input File Generation Successfull !\n");
    }
    else
    {
        printf("Sorted Input File Generation Failed.\n");
        return -1;
    }

    fprintf(inputFile, "%d\n", n);
    for (int i = 0; i < n; i++)
        fprintf(inputFile, "%d ", randominput[i]);

    fclose(inputFile);

    FILE *inputFile2 = fopen("inputSorted.txt", "w");

    if (inputFile2 != NULL)
    {
        printf("Random Input File Generation Successfull !\n");
    }
    else
    {
        printf("Random Input File Generation Failed.\n");
        return -1;
    }

    fprintf(inputFile2, "%d\n", n);
    for (int i = 0; i < n; i++)
        fprintf(inputFile2, "%d ", sortedinput[i]);

    fclose(inputFile2);

    printf("\n\n");

    clock_t start, end;
    long int t;

    start=clock();
    selectionSort(sortedinput,n);
    end=clock();
    t=end-start;
    printf("Time required for sorting, by selection sort, a sorted array of size %d is %f\n\n", n, (double)t/(double)CLOCKS_PER_SEC);

    start=clock();
    selectionSort(randominput,n);
    end=clock();
    t=end-start;
    printf("Time required for sorting, by selection sort, an unsorted array of size %d is %f\n\n", n, (double)t/(double)CLOCKS_PER_SEC);

    start=clock();
    bubbleSort(sortedinput,n);
    end=clock();
    t=end-start;
    printf("Time required for sorting, by bubble sort, a sorted array of size %d is %f\n\n", n, (double)t/(double)CLOCKS_PER_SEC);

    start=clock();
    bubbleSort(randominput,n);
    end=clock();
    t=end-start;
    printf("Time required for sorting, by bubble sort, an unsorted array of size %d is %f\n\n", n, (double)t/(double)CLOCKS_PER_SEC);
    return 0;
}