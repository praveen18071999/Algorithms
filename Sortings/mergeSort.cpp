#include<iostream>
using namespace std;
void mergeSort(vector<int> v,int n,int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergeSort(v,n,l,mid);
        mergeSort(v,n,mid+1,r);
        cout<<l<<" "<<mid<<" "<<r<<"\n";
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    mergeSort(a,n,0,n);
}