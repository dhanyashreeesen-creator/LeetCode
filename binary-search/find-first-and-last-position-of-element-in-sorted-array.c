int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int low, high, mid;
    int first = -1;
    int last = -1;

    *returnSize = 2;

    // Find first occurrence
    low = 0;
    high = numsSize - 1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    // Find last occurrence
    low = 0;
    high = numsSize - 1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    int* result = malloc(2 * sizeof(int));

    result[0] = first;
    result[1] = last;

    return result;
}