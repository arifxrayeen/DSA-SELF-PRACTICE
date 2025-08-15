#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    // base case
    if (n == 0 || n == 1)
        return;
    // 1 case solve karna hai
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    // recursive call
    bubbleSort(arr, n - 1);
}
int main()
{
    int arr[5] = {5, 1, 4, 2, 8};
    bubbleSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}