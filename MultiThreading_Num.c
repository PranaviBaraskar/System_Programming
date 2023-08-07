
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          PROGRAM STATEMENT : Operation on N Number's using MultiThreading Concepts.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//----------*--------------------------*-------------------------*---------------------------*---------------------------*-----------
//
//      DESCRIPTION     :  Problem Solving on N numbers using the Concept of Multithreading
//      AUTHOR NAME     :  Pranavi Ghanshyam Baraskar
//      DATE            :  07.08.2023 
//
//----------*--------------------------*-------------------------*---------------------------*---------------------------*-----------

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef unsigned int UINT;

#define TRUE 1
#define FALSE -1

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          FUNCTION NAME   : ThreadProc_EvenOdd
//          DESCRIPTION     : Check whether the Number is Even OR Odd.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
void * ThreadProc_EvenOdd(void * ptr)
{
    UINT iNo = (int)ptr;
    UINT iRet = 0;

    if((iNo % 2) == 0)
    {
        iRet = TRUE;
    }
    else
    {
        iRet = FALSE;
    }

    pthread_exit(iRet);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          FUNCTION NAME   : ThreadProc_Prime
//          DESCRIPTION     : Check whether the Number is Prime OR Not
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void * ThreadProc_Prime(void * ptr)
{
    UINT iNo = (int)ptr;
    UINT iRet = 0;
    int iCnt = 0;

    for(iCnt = 2; iCnt < iNo; iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            break;
        }
    }

    if(iCnt == iNo)
    {
        iRet = TRUE;
    }
    else
    {
        iRet = FALSE;
    }
    pthread_exit(iRet);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          FUNCTION NAME   : ThreadProc_Perfect
//          DESCRIPTION     : Check whether the Number is Perfect OR Not.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void * ThreadProc_Perfect(void * ptr)
{
    UINT iNo = (int)ptr;
    UINT iSum = 0;
    UINT iRet = 0;
    int iCnt = 0;

    for(iCnt = 1; iCnt <= (iNo/2); iCnt++)
    {
        iSum = iSum + iCnt;
    }

    if(iNo == iSum)
    {
        iRet = TRUE;
    }
    else
    {
        iRet = FALSE;
    }
    pthread_exit(iRet);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          FUNCTION NAME   : ThreadProc_Factors
//          DESCRIPTION     : Display the Factors.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void * ThreadProc_Factors(void * ptr)
{
    UINT iNo = (int)ptr;
    int iCnt = 0;

    printf("\n---------------------------------------------------\n");

    printf("\n* Factors :  ");
    for(iCnt = 1; iCnt <= iNo; iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            printf("| %d ",iCnt);
        }
    }
    printf(" |\n");
    pthread_exit(NULL);

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          FUNCTION NAME   : ThreadProc_CountFact
//          DESCRIPTION     : Number of Factors.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void * ThreadProc_CountFact(void * ptr)
{
    UINT iNo = (int)ptr;
    int iCnt = 0;
    int iFact = 0;

    for(iCnt = 1; iCnt <= iNo; iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            iFact++;
        }
    }
    pthread_exit(iFact);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          FUNCTION NAME   : ThreadProc_AddFactors
//          DESCRIPTION     : Addition of Factors
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void * ThreadProc_AddFactors(void * ptr)
{
    UINT iNo = (int)ptr;
    int iCnt = 0;
    int iFact = 0;

    for(iCnt = 1; iCnt <= iNo; iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            iFact = iFact + iCnt;
        }
    }
    pthread_exit(iFact);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          FUNCTION NAME   : ThreadProc_DisplayFactorial
//          DESCRIPTION     : Display All Factorials
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void * ThreadProc_DisplayFactorial(void * ptr)
{
    UINT iNo = (int)ptr;
    int iCnt = 0;

    printf("\n---------------------------------------------------\n");
    printf("\n* Factorials :  ");
    for(iCnt = 1; iCnt <= iNo; iCnt++)
    {
        printf("| %d ",iCnt);
    }
    printf(" |\n");
    pthread_exit(NULL);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          FUNCTION NAME   : ThreadProc_SumFactorial
//          DESCRIPTION     : Summation of All Factorials
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void * ThreadProc_SumFactorial(void * ptr)
{
    UINT iNo = (int)ptr;
    int iCnt = 0;
    int iFact = 1;

    for(iCnt = 1; iCnt <= iNo; iCnt++)
    {
        iFact = iFact * iCnt;
    }
    pthread_exit(iFact);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          MAIN FUNCTION 
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    pthread_t TID1, TID2, TID3, TID4, TID5, TID6, TID7, TID8;
    UINT Ret = 0;
    UINT iTemp = 0;

    UINT value = 0;
    UINT Return_Value = 0;


    printf("Enter the number\n");
    scanf("%d",&value);

    iTemp = value;

//==============================================================================
//  Thread 1

    Ret = pthread_create(&TID1,NULL,ThreadProc_EvenOdd,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID1, &Return_Value);
    printf("\n---------------------------------------------------\n");
    if(Return_Value == 1)
    {
        printf("\n* Your Number is Even \n");
    }
    else
    {
        printf("\n* Your Number is Odd \n");
    }
//==============================================================================
//  Thread 2

    Ret = pthread_create(&TID2,NULL,ThreadProc_Prime,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID2, &Return_Value);

    printf("\n---------------------------------------------------\n");

    if(Return_Value == 1)
    {
        printf("\n* Your Number is Prime \n");
    }
    else
    {
        printf("\n* Your Number is Not Prime \n");
    }
    
//==============================================================================
//  Thread 3

    Ret = pthread_create(&TID3,NULL,ThreadProc_Perfect,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID3, &Return_Value);

    printf("\n---------------------------------------------------\n");

    if(Return_Value == 1)
    {
        printf("\n* Your Number is Perfect \n");
    }
    else
    {
        printf("\n* Your Number is Not Perfect \n");
    }

//==============================================================================
//  Thread 4

    Ret = pthread_create(&TID4,NULL,ThreadProc_Factors,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID4,NULL);

//==============================================================================
//  Thread 5

    Ret = pthread_create(&TID5,NULL,ThreadProc_CountFact,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID5, &Return_Value);
    
    printf("\n---------------------------------------------------\n");

    printf("\n* Number of Factors : %d\n",Return_Value);

//==============================================================================
//  Thread 6

    Ret = pthread_create(&TID6,NULL,ThreadProc_AddFactors,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID6, &Return_Value);
    
    printf("\n---------------------------------------------------\n");

    printf("\n* Addition of Factors : %d\n",Return_Value);

//==============================================================================
//  Thread 7

    Ret = pthread_create(&TID7,NULL,ThreadProc_DisplayFactorial,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID7,NULL);

//==============================================================================
//  Thread 8

    Ret = pthread_create(&TID8,NULL,ThreadProc_SumFactorial,(int*)iTemp);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
    }
    pthread_join(TID8, &Return_Value);
    
    printf("\n---------------------------------------------------\n");

    printf("\n* Addition of Factorials : %d\n",Return_Value);
    
    printf("\n---------------------------------------------------\n");


    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          END OF PROGRAM...
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
