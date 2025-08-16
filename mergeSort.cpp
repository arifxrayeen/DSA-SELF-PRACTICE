#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    // low...mid
    // mid+1...high
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // remaining elements of part 1
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    // copy array into original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void mergeSort(vector<int> &arr, int low, int high)
{
    // base case rukna kab hai means if array has one element that means low == high
    if (low == high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    vector<int> nums = {5, 2, 9, 1, 5, 6};
    mergeSort(nums, 0, nums.size() - 1);
    for (int num : nums)
    {
        cout << num << " ";
    }
    return 0;
}