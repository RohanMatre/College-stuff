#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getSum(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int findMaxSum(vector<int> &nums)
{
    int n = nums.size();
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        int maxVal = nums[i];
        int sum = nums[i];
        int maxSum = getSum(maxVal);

        for (int j = i + 1; j < n; j++)
        {
            maxVal = max(maxVal, nums[j]);
            maxSum = max(maxSum, getSum(nums[j]));

            if (maxSum * (j - i + 1) == sum + nums[j])
            {
                result = max(result, sum + nums[j]);
            }
        }
    }

    return result;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int output = findMaxSum(nums);
    cout << "Maximum sum with equal maximum digits: " << output << endl;

    return 0;
}
