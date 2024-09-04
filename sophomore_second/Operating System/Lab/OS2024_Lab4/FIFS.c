#include<stdio.h>
#include<stdlib.h>

int main1()
{	
	int num;
	printf("Plz enter total number of processes(more than 0 and less than 10:");
	scanf("%d", &num);
	printf("\n");
	if (num < 0 || num > 10) {
		printf("Invalid number of processes.\n");
		return 1; // Invalid input!!!!Out!!
	}
	// dynamically malloc memory for processes
	int* bt = (int*)malloc(num * sizeof(int));

	// Check whether malloc() successfully
	if (bt == NULL) {
		printf("Memory allocation failed.\n");
		return 1; // If fail,then exit the program and print the reason for the failure
	}


	printf("Plz enter Process Burst Time\n");
	for (int i = 0; i < num; i++)
	{
		printf("P[%d]:", i+1);
		scanf("%d", &bt[i]);
	}
	// initialize Waiting Time array
	int* wt = (int*)malloc(num * sizeof(int));
	int sum = 0;
	wt[0] = 0;
	for (int i = 1; i < num; i++)
	{
		sum += bt[i-1];
		wt[i] = sum;
	}
	printf("\n");
	// initialize Turnaround Time array
	int* tt = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++)
	{	
		tt[i] = bt[i] + wt[i];
	}


	printf("Process\t\tBurst Time\tWaiting time\tTurnaround Time\n");
	for (int i = 0; i < num; i++)
	{
		printf("P[%d]\t\t%d\t\t%d\t\t%d", i+1, bt[i], wt[i], tt[i]);
		printf("\n");
	}
	printf("\n");
	// Calculate Average Waiting Time
	int AveWt = 0;
	int time1 = 0;
	for (int i = 0; i < num; i++)
	{
		time1 += wt[i];
		AveWt = time1;
	}
	printf("Average Waiting Time:%d\n", AveWt/num);
	// Calculate Average Turnaround Time
	int AveTt = 0;
	int time2 = 0;
	for (int i = 0; i < num; i++)
	{
		time2 += tt[i];
		AveTt = time2;
	}
	printf("Average Turnaround Time:%d", AveTt/num);
	// Release the memory
	free(bt);
	free(wt);
	free(tt);
	return 0;
}