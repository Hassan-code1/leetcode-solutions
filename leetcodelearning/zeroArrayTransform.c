int maxRemoval(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int numofZeros = 0;
    for(int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            numofZeros++;
        }
    }
    for(int i = 0; i < queriesSize; i++) {
        for(int j = queries[i][0]; j <= queries[i][1]; j++) {
            if (nums[j] != 0) {
                nums[j]--;
                if(nums[j] == 0) {
                    numofZeros++;
                }
            }
        }
        if(numofZeros == numsSize) {
            return queriesSize -i;
        }
    }
    return -1;
}
//chatgpt
/*#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Helper function: Check if nums can be reduced to 0 using the first keepCount queries
bool isValid(int* nums, int n, int** queries, int keepCount) {
    int* diff = (int*)calloc(n + 1, sizeof(int));
    if (!diff) return false;

    // Build difference array from the first keepCount queries
    for (int i = 0; i < keepCount; i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        diff[l]++;
        if (r + 1 < n) diff[r + 1]--;
    }

    // Build coverage array using prefix sum
    int* cover = (int*)malloc(n * sizeof(int));
    if (!cover) {
        free(diff);
        return false;
    }

    cover[0] = diff[0];
    for (int i = 1; i < n; i++) {
        cover[i] = cover[i - 1] + diff[i];
    }

    // Check if each nums[i] is covered enough
    for (int i = 0; i < n; i++) {
        if (cover[i] < nums[i]) {
            free(diff);
            free(cover);
            return false;
        }
    }

    free(diff);
    free(cover);
    return true;
}

// Main function: Return maximum number of queries that can be removed
int maxRemoval(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int low = 0, high = queriesSize, answer = -1;

    while (low <= high) {
        int mid = (low + high) / 2;  // Try removing `mid` queries
        int keepCount = queriesSize - mid;

        if (isValid(nums, numsSize, queries, keepCount)) {
            answer = mid;            // We can remove `mid` queries
            low = mid + 1;           // Try to remove more
        } else {
            high = mid - 1;          // Try to remove fewer
        }
    }

    return answer;
}
*/