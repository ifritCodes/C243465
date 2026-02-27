#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int A[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    int item;
    cout<<"Enter element to search: ";
    cin>>item;
    int pos=-1;
    for(int i=0;i<n;i++)
    {
        if(A[i]==item)
        {
            pos=i;
            break;
        }
    }
    if(pos!=-1)
    {
        cout<<"Element found at position "<<pos + 1;
    }
    else
    {
        cout<<"Element not found";
    }
    return 0;
}
