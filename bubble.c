#include <stdio.h>

#define LENGTH 8

#define SWAP(a, b)\
do{\
	a ^= b;\
	b ^= a;\
	a ^= b;\
}while(0)

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
    // bubble sort
    int i, j;

    for (i=0; i<count-1; i++)
    {
        for (j=0; j<(count-i-1); j++)
        {
            if ( pData[j] > pData[j+1] )
            {
                SWAP( pData[j], pData[j+1]);
            }
        }
    }
}

int main(void)
{
	sortData(data, LENGTH);

    printData(data, LENGTH);

    return 0;
}
