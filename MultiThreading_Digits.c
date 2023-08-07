#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef unsigned int UINT;

#define TRUE 1
#define FALSE -1

void * ThreadProc_CountEven(void * ptr)
{
    UINT iNo = (int)ptr;
    UINT iDigit = 0;
    UINT iCnt = 0;

    while(iNo != 0)
    {
        iDigit = iNo % 10;
        if((iDigit % 2) == 0)   
        {
            iCnt++;
        }
        iNo = iNo / 10;
    }
    pthread_exit(iCnt);
}

void * ThreadProc_CountOdd(void * ptr)
{
    UINT iNo = (int)ptr;
    UINT iDigit = 0;
    UINT iCnt = 0;

    while(iNo != 0)
    {
        iDigit = iNo % 10;
        if((iDigit % 2) != 0)   
        {
            iCnt++;
        }
        iNo = iNo / 10;
    }
    pthread_exit(iCnt);
}

void * ThreadProc_CountDigits(void * ptr)
{
    UINT iNo = (int)ptr;
    UINT iDigit = 0;
    UINT iCnt = 0;

    while(iNo != 0)
    {
        iDigit = iNo % 10;
        iCnt++;
        iNo = iNo / 10;
    }
    pthread_exit(iCnt);
}

void * ThreadProc_CheckNum(void * ptr)
{
    UINT iNo = (int)ptr;
    UINT iDigit = 0;
    UINT iCnt = 0;
    UINT iRet = 0;
    UINT value = 0;

    printf("\nEnter the number that you want to check\n");
    scanf("%d",&value);

    while(iNo != 0)
    {
        iDigit = iNo % 10;
        if(value == iDigit)
        {
            iRet = TRUE;
        }
        iNo = iNo / 10;
    }
    pthread_exit(iRet);
}

void * ThreadProc_FreqNum(void * ptr)
{
    UINT iNo = (int)ptr;
    UINT iDigit = 0;
    UINT iCnt = 0;
    UINT iRet = 0;
    UINT value = 0;

    printf("\nEnter the number that you want to Count Frequency\n");
    scanf("%d",&value);

    while(iNo != 0)
    {
        iDigit = iNo % 10;
        if(value == iDigit)
        {
            iRet++;
        }
        iNo = iNo / 10;
    }
    pthread_exit(iRet);
}

void * ThreadProc_SmallDigits(void * ptr)
{
    UINT iNo = (int)ptr;
    UINT iDigit = 0;
    UINT iMin = 9;

    while(iNo != 0)
    {
        iDigit = iNo % 10;
        if(iMin > iDigit)
        {
            iMin = iDigit;
            if(iMin == 0)
            {
                break;
            }
        }
        iNo = iNo / 10;
    }
    pthread_exit(iMin);
}

void * ThreadProc_LargeDigits(void * ptr)
{
    UINT iNo = (int)ptr;
    UINT iDigit = 0;
    UINT iMax = 0;

    while(iNo != 0)
    {
        iDigit = iNo % 10;
        if(iMax < iDigit)
        {
            iMax = iDigit;
            if(iMax == 9)
            {
                break;
            }
        }
        iNo = iNo / 10;
    }
    pthread_exit(iMax);
}

void * ThreadProc_Reverse(void * ptr)
{
    UINT iNo = (int)ptr;
    UINT iDigit = 0;
    UINT iReverse = 0;

    while(iNo != 0)
    {
        iDigit = iNo % 10;
        iReverse = (iReverse * 10) + iDigit;
        iNo = iNo / 10;
    }
    pthread_exit(iReverse);
}

void * ThreadProc_Pallindrome(void * ptr)
{
    UINT iNo = (int)ptr;
    UINT iDigit = 0;
    UINT iTemp = iNo;
    UINT iReverse = 0;
    UINT iRet = 0;

    while(iTemp != 0)
    {
        iDigit = iTemp % 10;
        iReverse = (iReverse * 10) + iDigit;
        iTemp = iTemp / 10;
    }
    if(iReverse == iNo)
    {
        iRet = TRUE;
    }
    else
    {
        iRet = FALSE;
    }

    pthread_exit(iRet);
}

void * ThreadProc_Average(void * ptr)
{
    UINT iNo = (int)ptr;
    UINT iDigit = 0;
    UINT iCnt = 0;
    UINT iSum = 0;
    float iRet = 0.0f;

    while(iNo != 0)
    {
        iDigit = iNo % 10;
        iSum = iSum + iDigit;
        iCnt++;
        iNo = iNo / 10;
    }
    iRet = (float)(iSum / iCnt);

    printf("\n---------------------------------------------------\n");
    printf("\n* Average of  Number : %f\n",iRet);
    printf("\n---------------------------------------------------\n");

    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1, TID2, TID3, TID4, TID5, TID6, TID7, TID8, TID9, TID10;
    UINT Ret = 0;
    UINT iTemp = 0;

    UINT value = 0;
    UINT Return_Value = 0;
    float FReturn_Value = 0.0f;

    printf("Enter the number\n");
    scanf("%d",&value);

    iTemp = value;

//==============================================================================
//  Thread 1

    Ret = pthread_create(&TID1,NULL,ThreadProc_CountEven,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID1, &Return_Value);
    printf("---------------------------------------------------\n");
    printf("\n* Even Count from Number : %d\n\n",Return_Value);

//==============================================================================
//  Thread 2

    Ret = pthread_create(&TID2,NULL,ThreadProc_CountOdd,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID2, &Return_Value);
    printf("\n---------------------------------------------------\n");
    printf("\n* Odd Count from Number : %d\n",Return_Value);
    
//==============================================================================
//  Thread 3

    Ret = pthread_create(&TID3,NULL,ThreadProc_CountDigits,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID3, &Return_Value);
    printf("\n---------------------------------------------------\n");
    printf("\n* Total Count Digits from Number : %d\n",Return_Value);
    printf("\n---------------------------------------------------\n");

//==============================================================================
//  Thread 4

    Ret = pthread_create(&TID4,NULL,ThreadProc_CheckNum,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID4,&Return_Value);
    
    if(Return_Value == TRUE)
    {
        printf("Given Number is Present\n");
    }
    else
    {
        printf("Given Number is not Present\n");
    }
    printf("\n---------------------------------------------------\n");

//==============================================================================
//  Thread 5

    Ret = pthread_create(&TID5,NULL,ThreadProc_FreqNum,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID5, &Return_Value);
    
    printf("* Number of Digits present : %d\n",Return_Value);

//==============================================================================
//  Thread 6

    Ret = pthread_create(&TID6,NULL,ThreadProc_SmallDigits,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID6, &Return_Value);
    
    printf("\n---------------------------------------------------\n");
    printf("\n* Smallest Digit in number : %d\n",Return_Value);

//==============================================================================
//  Thread 7

    Ret = pthread_create(&TID7,NULL,ThreadProc_LargeDigits,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID7,&Return_Value);

    printf("\n---------------------------------------------------\n");
    printf("\n* Largest Digit in number : %d\n",Return_Value);

//==============================================================================
//  Thread 8

    Ret = pthread_create(&TID8,NULL,ThreadProc_Reverse,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID8, &Return_Value);
    
    printf("\n---------------------------------------------------\n");
    printf("\n* Reverse Number : %d\n",Return_Value);

//==============================================================================
//  Thread 9

    Ret = pthread_create(&TID9,NULL,ThreadProc_Pallindrome,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID9, &Return_Value);
    
    printf("\n---------------------------------------------------\n");
    if(Return_Value == 1)
    {
        printf("\n* Number is Pallindrome \n",Return_Value);
    }
    else
    {
        printf("\n* Number is not Pallindrome \n",Return_Value);
    }

//==============================================================================
//  Thread 10

    Ret = pthread_create(&TID10,NULL,ThreadProc_Average,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID10,NULL);

    return 0;
}
