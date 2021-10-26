//Explore sets - header file, iterators(begin() ,end()) and size(), insert(), erase(), clear(), 
//find(), lower_bound() and upper_bound()

#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main()
{
	set<int> s1;

	for(int i=1;i<=5;i++)
	s1.insert(i);          //insert()

	set<int>::iterator itr;
	cout << "The set s1 is : \n";
	for (itr = s1.begin(); itr != s1.end(); itr++)   //begin(),end()
		cout << *itr<<" ";
	cout << endl;
 
    cout<<"Size is "<<s1.size()<<endl;   //size()

	auto pos=s1.find(3);  //find()
	cout<<*pos<<endl;       //3
	
	auto pos2=s1.find(30);
	cout<<*pos2<<endl;       //5 final element as pos = end()

    s1.erase(3);   //erase()
    
    for (itr = s1.begin(); itr != s1.end(); itr++)   
		cout << *itr<<" ";
	
	cout << "s1.lower_bound(4) : \n"<< *s1.lower_bound(4)<< endl;
    cout << "s1.upper_bound(4) : \n"<< *s1.upper_bound(4)<< endl;

	s1.clear();    //clear()
	cout<<"\nSize is "<<s1.size()<<endl;

    return 0;
}
