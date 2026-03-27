#include <iostream>
using namespace std;

// Function to merge two sorted subarrays
void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    // Copy data to temporary arrays
    for(int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];
    int i = 0, j = 0, k = left;
    // Merge the temp arrays back into A[left..right]
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy remaining elements, if any
    while(i < n1)
    {
        A[k] = L[i];
        i++; k++;
    }
    while(j < n2)
    {
        A[k] = R[j];
        j++; k++;
    }
}
// Function to perform Merge Sort
void mergeSort(int A[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(A, left, mid);       // Sort first half
        mergeSort(A, mid + 1, right);  // Sort second half

        merge(A, left, mid, right);    // Merge sorted halves
    }
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> A[i];
    mergeSort(A, 0, n - 1);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}
