//Explore Pair

#include<iostream>
#include<utility>
using namespace std;

int main()
{
    pair<int, char> p1;
 
    p1.first = 100;
    p1.second = 'a';
    
    pair<int, char>p2 = make_pair(100,'b');  //another way of initialising
    
    if(p1<p2)
    cout<<"P1 is smaller"<<endl;   //compares second since first is same

    cout<<"Pair 1 : ("<<p1.first<<","<<p1.second<<")\n";
    cout<<"Pair 2 : ("<<p2.first<<","<<p2.second<<")\n";  
    
    p1.swap(p2);
    cout<<"After swapping\n";
    cout<<"Pair 1 : ("<<p1.first<<","<<p1.second<<")\n";
    cout<<"Pair 2 : ("<<p2.first<<","<<p2.second<<")\n";
    return 0;
}
