#include <stdio.h>
#include <stdlib.h>

// Define a array to store the serial number
int* originalIndexes;

// Using Select Sort to implement SJF
void SortUsingSJF(int* bt, int num) {
    int i, j, minIndex, temp;
    for (i = 0; i < num - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < num; j++) {
            if (bt[j] < bt[minIndex]) {
                minIndex = j;
            }
        }
        temp = bt[i];
        bt[i] = bt[minIndex];
        bt[minIndex] = temp;

        temp = originalIndexes[i];
        originalIndexes[i] = originalIndexes[minIndex];
        originalIndexes[minIndex] = temp;
    }
}

int main() {
    int num;
    printf("Enter number of processes: ");
    scanf("%d", &num);
    printf("\n");
    if (num <= 0 || num > 10) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    int* bt = (int*)malloc(num * sizeof(int));
    originalIndexes = (int*)malloc(num * sizeof(int));
    int* wt = (int*)malloc(num * sizeof(int));
    int* tt = (int*)malloc(num * sizeof(int));

    if (bt == NULL || originalIndexes == NULL || wt == NULL || tt == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter Burst Time for each process:\n");
    for (int i = 0; i < num; i++) {
        printf("p%d:", i + 1);
        scanf("%d", &bt[i]);
        originalIndexes[i] = i; // Initialize the original array
    }

    SortUsingSJF(bt, num);

    // Initialize average time of wt and tt
    int sum = 0;
    for (int i = 0; i < num; i++) {
        wt[i] = sum;
        tt[i] = bt[i] + wt[i];
        sum += bt[i];
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num; i++) {
        printf("p%d\t\t%d\t\t%d\t\t%d\n", originalIndexes[i] + 1, bt[i], wt[i], tt[i]);
    }
    printf("\n");

    // Calculate the average time
    double AveWt = 0;
    double AveTt = 0;
    for (int i = 0; i < num; i++) {
        AveWt += wt[i];
        AveTt += tt[i];
    }
    printf("Average Waiting Time:%f\n", AveWt / num);
    printf("Average Turnaround Time:%f\n", AveTt / num);

    // Release memory
    free(bt);
    free(originalIndexes);
    free(wt);
    free(tt);
    return 0;
}