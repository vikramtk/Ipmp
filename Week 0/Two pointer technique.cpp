//Given an array A[] and a number x, check for pair in A[] with sum as x

#include<bits/stdc++.h>
using namespace std;

void pairsum(int A[],int x,int n)
{
    int *l,*r;
    sort(A,A+n);
    l=A;
    r=A+n;
    while(*l<*r){
        if((*l + *r) == x)
        {
            cout<<"The pair adding up to "<<x<<" is ("<<*l<<","<<*r<<")\n";
            return;
        }
        else if((*l + *r) > x)
        r--;
        else
        l++;
    }
    cout<<"No pair adds upto "<<x;
}

int main()
{
    int A[]={12,3,54,6,7,9,2,3};
    int x=11;
    int n=sizeof(A)/sizeof(A[0]);
    pairsum(A,x,n);
}
