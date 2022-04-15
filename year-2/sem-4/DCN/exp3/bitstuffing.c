#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX_SIZE 100

void MergeArr(int a[], int n1, int b[], int n2, int product[])
{
	int i, j, k, n3;
	j = k = 0;
	n3 = n1 + n2;
	for (i = 0; i < n3;)
	{
		if (j < n1 && k < n2)
		{
			if (a[j] < b[k])
			{
				product[i] = a[j];
				j++;
			}
			else
			{
				product[i] = b[k];
				k++;
			}
			i++;
		}
		else if (j == n1)
		{
			while (i < n3)
			{
				product[i] = b[k];
				k++;
				i++;
			}
		}
		else
		{
			while (i < n3)
			{
				product[i] = a[j];
				j++;
				i++;
			}
		}
	}
}

int main()
{
	printf("Karan Taneja's code, SAP - 500084399.\n");
	printf("Bit stuffing taking the flag pattern as {1, 1, 1, 0, 0, 0}\n\n");

	int flag[] = {1, 1, 1, 0, 0, 0};
	int flagSize = sizeof(flag) / sizeof(int);

	int dataStream[MAX_SIZE];

	int dataStreamSize;
	printf("Enter size of the bit stream: ");
	scanf("%d", &dataStreamSize);

	printf("Enter data bit stream: ");
	for (int i = 0; i < dataStreamSize; i++)
	{
		scanf("%d", &dataStream[i]);
	}

	int resultSize = 2 * flagSize + dataStreamSize;
	int resultStream[MAX_SIZE];

	int tempArray[MAX_SIZE];
	MergeArr(flag, flagSize, dataStream, dataStreamSize, tempArray);
	MergeArr(tempArray, flagSize + dataStreamSize, flag, flagSize, resultStream);

	printf("Result array:\n");
	for (int i = 0; i < resultSize; i++)
	{
		printf("%d ", resultStream[i]);
	}
}