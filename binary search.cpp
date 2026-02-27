#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int A[n];
    cout<<"Enter sorted elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    int item;
    cout<<"Enter element to search: ";
    cin>>item;
    int low=0,high=n-1,mid;
    int pos=-1;
    while(low<=high)
    {
        mid=(low+high)/2;
     if(A[mid]==item)
        {
            pos=mid;
            break;
        }
        else if(A[mid]<item)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(pos!=-1)
    {
        cout<<"Element found at position "<<pos+1;
    }
    else
    {
        cout<<"Element not found";
    }
    return 0;
}
