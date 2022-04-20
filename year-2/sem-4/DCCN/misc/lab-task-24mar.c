#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    printf("This is Karan Taneja's code. SAP ID: 5000084399.");

    int demand[10], maxBand = 9, nDevices = 3;
    float AvgBandwidth = maxBand / nDevices, bandProvision[10];
    float excessBandwidth = 0, condition[10], count = 0;

    for (int i = 0; i < nDevices; i++)
        demand[i] = rand() % 5 + 1;

    printf("\nBandwidth limit of the channel: %d\n\n", maxBand);

    for (int i = 0; i < nDevices; i++)
        printf("Bandwidth demand for device %d: %d mbps\n", i + 1, demand[i]);

    for (int i = 0; i < nDevices; i++)
        if (demand[i] <= AvgBandwidth)
        {
            bandProvision[i] = demand[i];
            excessBandwidth += AvgBandwidth - demand[i];
            condition[i] = 1;
        }
        else
        {
            bandProvision[i] = AvgBandwidth;
            condition[i] = 0;
            count++;
        }

    printf("\nExcess Bandwidth after providing average bandwidth = %f\n\n", excessBandwidth);

    float BonusBandwidth = excessBandwidth / count;

    for (int i = 0; i < nDevices; i++)
        if (condition[i] == 0)
            bandProvision[i] += BonusBandwidth;

    for (int i = 0; i < nDevices; i++)
        if (demand[i] == bandProvision[i])
            printf("Device %d: Demand Satisfied (%f mbps provided)\n", i + 1, bandProvision[i]);
        else
            printf("Device %d: Demand Not Satisfied (%f mbps provided)\n", i + 1, bandProvision[i]);
}