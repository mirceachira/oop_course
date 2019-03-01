#include <stdio.h>
/*
    a. Read sequences of positive integer numbers (reading of each sequence
ends by 0, reading of all  thesequences ends  by -1)  and  determine  the
maximum  element of  each  sequence  and  the maxim element of the global
sequence.b. Given a vector of numbers, find the longest contiguous subsequence
such that all elements are in a given interval
*/


int     readMatrix(int matrix[][100]) {
    int currentNumber, rowIndex=0, colIndex=0;

    scanf("%d", &currentNumber);
    while (currentNumber != -1) {
       matrix[rowIndex][colIndex++] = currentNumber;
       scanf("%d", &currentNumber);

       if (currentNumber == 0) {
           matrix[rowIndex][colIndex++] = currentNumber;
           rowIndex++;
           colIndex = 0;
           scanf("%d", &currentNumber);
       }
   }

   return rowIndex;
}

void     printMatrix(int len, int matrix[][100]) {
    int j=0;

    for (int i=0; i<len; i++) {
        do {
            printf("%d\t", matrix[i][j]);
        } while (matrix[i][j++] != 0);

        printf("\n");
        j = 0;
    }
}

void     printMax(int len, int matrix[][100]) {
    int rowMax, max=matrix[0][0], j=0;

    for (int i=0; i<len; i++) {
        rowMax = matrix[i][0];

        do {
            if (max < matrix[i][j])
                max = matrix[i][j];
            if (rowMax < matrix[i][j])
                rowMax = matrix[i][j];
        } while (matrix[i][j++] != 0);

        printf("Sequence %d max is %d\n", i, rowMax);
        j = 0;
    }
    printf("Array max is %d\n", max);
}

void exa() {
    int     matrix[100][100];
    int     len, j=0;

    len = readMatrix(matrix);
    printf("\nMatrix:\n");
    printMatrix(len, matrix);
    printf("\n");
    printMax(len, matrix);
}


int     readVector(int vector[]) {
    int currentNumber, index=0;

    scanf("%d", &currentNumber);
    while (currentNumber != -1) {
        vector[index++] = currentNumber;
        scanf("%d", &currentNumber);
    }

    return index;
}

void     longestSubSequence(int len, int vector[]) {
    int     intervalStart, intervalEnd;
    printf("Interval start: ");
    scanf("%d", &intervalStart);
    printf("\n");
    printf("Interval end: ");
    scanf("%d", &intervalEnd);
    printf("\n");

    int     longestStartIndex=-1, longLen=0, currentStartIndex=-1, currentLen=0, i=0;

    while (i < len) {
        if (intervalStart <= vector[i] && vector[i] <= intervalEnd) {
            currentStartIndex = i;
            currentLen = 1;

            while (intervalStart <= vector[i] && vector[i] <= intervalEnd) {
                currentLen++;
                i++;
            }
            if (currentLen > longLen) {
                longestStartIndex = currentStartIndex;
                longLen = currentLen;
            }
        }
        else
            i++;
    }

    printf("Longest subsequence in [%d, %d]:\n", intervalStart, intervalEnd);
    while (intervalStart <= vector[longestStartIndex] && vector[longestStartIndex] <= intervalEnd) {
        printf("%d\t", vector[longestStartIndex]);
        longestStartIndex++;
    }
    printf("\n");
}

void     exb() {
    int     vector[100];
    int     len;

    len = readVector(vector);
    longestSubSequence(len, vector);
}


int     main(void){
    char    option;

    printf("Choose an option (a or b): ");
    scanf("%c", &option);

    if (option == 'a')
        exa();
    else if (option == 'b')
        exb();
    else
        printf("Invalid option!");

};