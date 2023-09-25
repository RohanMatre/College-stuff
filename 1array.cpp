// Arrays - Input, Output, Upadate
#include <iostream>
using namespace std;

int main()
{
    int marks[100] = {-1};
    int n;
    cout << "Enter the no. of students : ";
    cin >> n;

    // Assign a Value
    // marks[0]=-1;
    // Input
    for (int i = 1; i < n; i++)
    {
        cin >> marks[i];
        marks[i] = marks[i] * 2;
    }

    // Upadate the Marks

    // Output
    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << ",";
    }
    cout << endl;
    return 0;
}