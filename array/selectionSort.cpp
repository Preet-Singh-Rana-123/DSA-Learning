#include <iostream>
using namespace std;

int main()
{

    int arr[] = {16, 37, 89, 12, 45, 56, 27, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        int index = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[index] > arr[j])
            {
                index =j;
            }
            swap(arr[index],arr[i]);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}