#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // If jth element is greater than 'j + 1' th element, swap them
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    vector<int> arr;
    int n;

    // Taking user input for the array size
    cout << "Enter the size of the array: ";
    cin >> n;

    // Taking user input for the array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    // Before sorting
    cout << "Array before sorting: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    bubbleSort(arr, n);

    // After sorting
    cout << "Array after sorting: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
