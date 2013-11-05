#include <stdio.h>

#define LENGTH 8

#define SWAP(a,b)\
do{\
    int tmp = a;\
    a = b;\
    b = tmp;\
}while(0)

static int data[LENGTH] = {45, 95, 15, 78, 84, 51, 24, 12};

static void printData(int *pData, int count)
{
    int i;
    for (i=0; i<count; i++)
    {
        printf("data[%d] = %d\n", i, pData[i]);
    }
}

static void quickSort(int *pData, int left, int right)
{
    int pivot, i, j;

    if ( left >= right )
    {
        return ;
    }

    pivot = pData[left];

    i = left+1;
    j = right;

    while (1)
    {
        while (i <= right)
        {
            if ( pData[i] > pivot )
            {
                break;
            }
            i++;
        }

        while (j > left)
        {
            if ( pData[j] < pivot )
            {
                break;
            }
            j--;
        }

        if ( i > j ) 
        {
            break;
        }

        SWAP(pData[i], pData[j]);
    }
    
    SWAP(pData[left], pData[j]);

    quickSort(pData, left, j-1);
    quickSort(pData, j+1, right);
}

static void sortData(int *pData, int count)
{
    quickSort(pData, 0, count-1);
}

int main(void)
{
    sortData(data, LENGTH);

    printData(data, LENGTH);

    return 0;
}
