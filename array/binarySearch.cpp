#include <iostream>
using namespace std;

int binarySearch(int arr[],int n,int key)
{
    
    int start = 0;
    int end = n - 1;

    while (start<=end)
    {
        int middle = (start + end) / 2;
        if (arr[middle] == key)
        {
            return middle;
        }
        else if (arr[middle] < key)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }
    return -1;
}

int main()
{

    int arr[] = {12, 14, 16, 18, 34, 37, 47, 58, 78, 91, 101, 134, 157};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<binarySearch(arr,n,92);

    return 0;
}