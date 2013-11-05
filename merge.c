#include <stdio.h>
#include <stdlib.h>

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

static void merge(int *pLeftArray, int leftCount, int* pRightArray, int rightCount, int* pMergeArray)
{
    int leftIdx=0, rightIdx=0, mergeIdx=0;

    while ( (leftIdx < leftCount) && (rightIdx < rightCount) )
    {
        if ( pLeftArray[leftIdx] < pRightArray[rightIdx] )
        {
            pMergeArray[mergeIdx] = pLeftArray[leftIdx];
            leftIdx++;
        }
        else
        {
            pMergeArray[mergeIdx] = pRightArray[rightIdx];
            rightIdx++;
        }

        mergeIdx++;
    }

    if ( leftIdx < leftCount )
    {
        while (leftIdx < leftCount)
        {
            pMergeArray[mergeIdx] = pLeftArray[leftIdx];
            mergeIdx++;
            leftIdx++;
        }
    }
    else
    {
        while (rightIdx < rightCount)
        {
            pMergeArray[mergeIdx] = pRightArray[rightIdx];
            mergeIdx++;
            rightIdx++;
        }
    }
}

static void sortData(int *pData, int count)
{
    // merge sort
    
    if ( count > 1 )
    {
        int i, left, right;
        int *pLeftArray;
        int *pRightArray;
    
        left = count / 2;
        right = count - left; 

        pLeftArray = malloc( left * sizeof(int) );
        pRightArray = malloc( right * sizeof(int) );

        for (i=0; i<left; i++)
        {
            pLeftArray[i] = pData[i];
        }

        for (i=0; i<right; i++)
        {
            pRightArray[i] = pData[left+i];
        }

        sortData(pLeftArray, left);
        sortData(pRightArray, right);
        merge(pLeftArray, left, pRightArray, right, pData);

        free(pLeftArray);
        free(pRightArray);
    }
}

int main(void)
{
    sortData(data, LENGTH);

    printData(data, LENGTH);

    return 0;
}
