#include <stdio.h>

#define LENGTH 8

static int data[LENGTH] = {95, 45, 15, 78, 84, 51, 24, 12};

static void printData(int *pData, int count)
{
    int i;
    for (i=0; i<count; i++)
    {
        printf("data[%d] = %d\n", i, pData[i]);
    }
}

static void sortData(int *pData, int count)
{
    // insert sort
    int i, j, temp;

    for (i=1; i<count; i++)
    {
        temp = pData[i];
        for (j=i; j>0; j-- )
        {
            if ( pData[j-1] > temp )
            {
                pData[j] = pData[j-1];
            }
            else
            {
                break;
            }
        }
        pData[j] = temp;
    }
}

int main(void)
{
    sortData(data, LENGTH);

    printData(data, LENGTH);

    return 0;
}
