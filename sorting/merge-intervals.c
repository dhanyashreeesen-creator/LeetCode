#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;

    return x[0] - y[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {

    if (intervalsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Sort intervals by starting value
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int **result = malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = malloc(intervalsSize * sizeof(int));

    int count = 0;

    for (int i = 0; i < intervalsSize; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // No overlap
        if (count == 0 || start > result[count - 1][1]) {
            result[count] = malloc(2 * sizeof(int));
            result[count][0] = start;
            result[count][1] = end;

            (*returnColumnSizes)[count] = 2;
            count++;
        }
        // Overlap
        else {
            if (end > result[count - 1][1]) {
                result[count - 1][1] = end;
            }
        }
    }

    *returnSize = count;
    return result;
}