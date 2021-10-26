//Explore vectors-begin(),end() and similar, erase(),clear(),size(),push_back(), pop_back(), 
//insert(), passing vectors as arguments to functions, initiliazing vectors

#include<iostream>
#include<vector>
using namespace std;

void func(vector<int> &vect)
{
   vect.push_back(200);
}

int main()
{
	vector<int> vect{1,2,3};            // Initialisation of Vectors
	
	for (auto i = vect.begin(); i != vect.end(); i++)  //begin().end()
        cout << *i << " ";  //outpiuts 1 2 3
        
    cout<<"\nSize is "<<vect.size()<<endl;   //size() = 3
    
    if(vect.empty())  //vector not empty
    cout<<"Vector is empty"<<endl;
    else
    cout<<"Vector is not empty"<<endl;
    
    vect.push_back(4);  //push-back() inserts 4 at last - 1 2 3 4
    cout<<vect.back()<<endl;
    vect.push_back(5);  // 1 2 3 4 5
    cout<<vect.back()<<endl;
    
    vect.pop_back();  //deletes 5
    cout<<vect.back()<<endl; //4
	
	vect.clear();  //cleares all elements
	cout<<"Size is "<<vect.size()<<endl;  //0
	
	for (int i = 1; i <= 10; i++)
        vect.push_back(i);
        
    cout<<"At 5:"<<vect.at(5)<<endl;
    vect.erase(vect.begin()+5);         //erase
    cout<<"After erase at 5:"<<vect.at(5)<<endl;
    
    vect.insert(vect.begin()+1,100);
    cout<<vect.at(1)<<endl;
   
    func(vect);  //passing vector as argument
    cout<<vect.back();  //200
}
