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
    // shell sort
    int i, j, gap, temp;
    
    for (gap = count/2 ; gap >0; gap /= 2)
    {
        printf("gap = %d\n", gap);
        for (i=gap; i<count; i++)
        {
            temp = pData[i];
            for (j=i; j>0; j=j-gap)
            {
                if ( pData[j-gap] > temp )
                {
                    pData[j] = pData[j-gap];
                }
                else 
                {
                    break;
                }
            }
            pData[j] = temp;
        }

        printData(data, LENGTH);
        printf("\n");
    }
        
}

int main(void)
{
    sortData(data, LENGTH);

    printData(data, LENGTH);

    return 0;
}
