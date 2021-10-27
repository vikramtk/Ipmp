//Given an array A[] and a number x, check for pair in A[] with sum as x

#include<bits/stdc++.h>
using namespace std;

void pairsum(int A[],int x,int size)
{
    unordered_set<int> S;
    
    for(int i=0;i<size;i++)
    {
        if(S.find(x-A[i])==S.end())
        S.insert(A[i]);
        else
        {
            cout<<"The pair that gives sum "<<x<<" is ("<<A[i]<<","<<x-A[i]<<")";
        }
    }
}

int main()
{
    int A[]={12,3,54,6,7,9,2,3};
    int x=21;
    int n=sizeof(A)/sizeof(A[0]);
    pairsum(A,x,n);
}
