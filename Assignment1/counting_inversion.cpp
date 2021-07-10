#include <bits/stdc++.h>
using namespace std;
 
int Merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;
    int inversionCount = 0;
 
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        }
        else {
            aux[k++] = arr[j++];
            inversionCount += (mid - i + 1);         }
    }
     while (i <= mid) {
        aux[k++] = arr[i++];
    }
 
     for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
 
    return inversionCount;
}
 
int MergeSort(int arr[], int aux[], int low, int high)
{
    if (high == low) {        
        return 0;
    }
 
    int mid = (low + ((high - low) >> 1));
    int inversionCount = 0;

    inversionCount += MergeSort(arr, aux, low, mid);
 
    inversionCount += MergeSort(arr, aux, mid + 1, high);
 
    inversionCount += Merge(arr, aux, low, mid, high);
 
    return inversionCount;
}
 
int main()
{
    int arr[] = { 1, 9, 6, 4, 5 };
 
    int N = sizeof(arr)/sizeof(arr[0]);
 
    int aux[N];
    for (int i = 0; i < N; i++) {
        aux[i] = arr[i];
    }
 
    cout<<"The inversion count is "<< MergeSort(arr, aux, 0, N - 1);

}