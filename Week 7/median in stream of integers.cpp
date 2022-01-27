#include<bits/stdc++.h>
#include "heap.h"
#include "maxheap.h"
using namespace std;

int main()
{
    int x,median;
    minheap min(100);
    maxheap max(100);
    while(1)
    {
        cout<<'\t'<<min.heapsize<<max.heapsize<<endl;
        cin>>x;
        if(min.heapsize==0 && max.heapsize==0){
        median=x;
        min.insert(x);
        }
   
        else if(min.heapsize==1 && max.heapsize==0){
            if(x>median){
                max.insert(min.extractmin());
            min.insert(x);
            }
            else
            max.insert(x);
        median=(median+x)/2;
        }
        
       /* else if(min.heapsize==0 && max.heapsize==1){
            if(x<median)
            min.insert(x);
            else{
            min.insert(max.extractmax());
            max.insert(x);}
        median=(median+x)/2;
        } */
        
        else
        {
            if(min.heapsize==max.heapsize)
            {
                if(min.peek()>x)
                {
                max.insert(x);
                median=max.peek();
                }
                else
                {
                    min.insert(x);
                    median=min.peek();
                }
            }
            else
            {
                if(min.peek()>x)
                {
                max.insert(x);
                median=max.peek();
                }
                else
                {
                    min.insert(x);
                    median=min.peek();
                }
                
                if(min.heapsize>max.heapsize){
                max.insert(min.extractmin());
                median=(min.peek()+max.peek())/2;}
                else if(max.heapsize>min.heapsize){
                min.insert(max.extractmax());
                median=(min.peek()+max.peek())/2;}
                else
                median=(min.peek()+max.peek())/2;
            }
        }
        cout<<median<<endl;
    }
    return 0;
}
