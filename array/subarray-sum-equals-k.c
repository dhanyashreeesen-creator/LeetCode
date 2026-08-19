int subarraySum(int* nums, int numsSize, int k)
{
    int capacity = 1;

    while (capacity < 2 * numsSize + 1)
        capacity *= 2;

    long long keys[capacity];
    int freq[capacity];

    for (int i = 0; i < capacity; i++)
    {
        keys[i] = 0;
        freq[i] = 0;
    }

    int count = 0;
    long long sum = 0;

    // Prefix sum 0 has occurred once
    int pos = 0;
    keys[pos] = 0;
    freq[pos] = 1;

    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];

        long long needed = sum - k;

        // Search for (sum - k)
        unsigned long long h = (unsigned long long)needed;
        int index = h & (capacity - 1);

        while (freq[index] != 0)
        {
            if (keys[index] == needed)
            {
                count += freq[index];
                break;
            }

            index = (index + 1) & (capacity - 1);
        }

        // Insert/update current prefix sum
        h = (unsigned long long)sum;
        index = h & (capacity - 1);

        while (freq[index] != 0 && keys[index] != sum)
        {
            index = (index + 1) & (capacity - 1);
        }

        if (freq[index] == 0)
        {
            keys[index] = sum;
            freq[index] = 1;
        }
        else
        {
            freq[index]++;
        }
    }

    return count;
}