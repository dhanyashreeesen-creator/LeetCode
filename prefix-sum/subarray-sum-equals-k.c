int subarraySum(int* nums, int numsSize, int k)
{
    int count = 0;

    for(int i = 0; i < numsSize; i++)
    {
        int sum = 0;

        for(int j = i; j < numsSize; j++)
        {
            sum += nums[j];

            if(sum == k)
                count++;
        }
    }

    return count;
}