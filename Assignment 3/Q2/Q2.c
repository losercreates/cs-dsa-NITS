#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX (int)1e4

void averagecase(int n, int input[])
{
    for (int i = 0; i < n; i++)
        input[i] = rand() % MAX;
}

void bestcase(int n, int input[])
{
    for (int i = 0; i < n; i++)
        input[i] = i;
}

void worstcase(int n, int input[])
{
    for (int i = 0; i < n; i++)
        input[i] = n-1-i;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main(){
    srand(time(0));
    int n;
    printf("Enter size of input > ");
    scanf("%d", &n);

    int bestcaseinput[n];
    int averagecaseinput[n];
    int worstcaseinput[n];

    bestcase(n,bestcaseinput);
    worstcase(n,worstcaseinput);
    averagecase(n,averagecaseinput);

    FILE *inputFile = fopen("inputbestcase.txt", "w");
    fprintf(inputFile, "%d\n", n);
    for (int i = 0; i < n; i++)
        fprintf(inputFile, "%d ", bestcaseinput[i]);
    fclose(inputFile);

    FILE *inputFile2 = fopen("inputaveragecase.txt", "w");
    fprintf(inputFile2, "%d\n", n);
    for (int i = 0; i < n; i++)
        fprintf(inputFile2, "%d ", averagecaseinput[i]);
    fclose(inputFile2);

    FILE *inputFile3 = fopen("inputworstcase.txt", "w");
    fprintf(inputFile3, "%d\n", n);
    for (int i = 0; i < n; i++)
        fprintf(inputFile3, "%d ", worstcaseinput[i]);
    fclose(inputFile3);

    printf("\nAll input files generated\n\n");

    clock_t start, end;
    long int t;

    start=clock();
    insertionSort(bestcaseinput,n);
    end=clock();
    t=end-start;
    printf("Time required for sorting, by insertion sort, for the best case %d is %f\n\n", n, (double)t/(double)CLOCKS_PER_SEC);

    start=clock();
    insertionSort(averagecaseinput,n);
    end=clock();
    t=end-start;
    printf("Time required for sorting, by insertion sort, for the average case %d is %f\n\n", n, (double)t/(double)CLOCKS_PER_SEC);

    start=clock();
    insertionSort(worstcaseinput,n);
    end=clock();
    t=end-start;
    printf("Time required for sorting, by insertion sort, for the worst case %d is %f\n\n", n, (double)t/(double)CLOCKS_PER_SEC);

    return 0;
}