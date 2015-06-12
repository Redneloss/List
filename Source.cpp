#include <iostream>
#include <string>
#include "List.cpp"  //it has to work with #include "List.h", bun for some strange reason it doesn`t

using namespace std;

int main()
{
	List<int> list1;
	list1.push_front(100);  
	list1.push_front(200);  
	list1.push_front(300);  
	list1.push_back(777);
	cout << list1.back() << endl; //777  
	list1.pop_back();
	cout << list1.back() << endl; //100  
	cout << list1.front() << endl; //300  
	list1.pop_front();
	cout << list1.front() << endl; //200

	List<int> list2;
	list2.push_back(616);  
	list2.push_front(515);  
	list2.push_front(313); 
	list2.push_back(777);

	//Извежда 313 515 616 777  
	for (List<int>::iterator it = list2.begin(); it != list2.end(); it++)  
	{  
		cout << *it << " ";
	}  
	cout << endl;

	List<string> list3;  
	list3.push_back("vidi");  
	list3.push_back("vici");
	List<string>::iterator iter = list3.begin();
	list3.insert(iter, "Veni");

	//Извежда Veni vidi vici 
	for (List<string>::iterator it = list3.begin(); it != list3.end(); it++)  
	{   
		cout << *it << " ";  
	}  
	cout << endl;

	List<string> list4;  
	list4.push_back("Divide"); 
	list4.push_back("et");  
	list4.push_back("impera");

	//Извежда Divide et impera  
	for (List<string>::iterator it = list4.begin(); it != list4.end(); it++) 
	{   
		cout << *it << " ";  
	}  
	List<string>::iterator mid = ++list4.begin();  
	list4.erase(mid);

	//Извежда Divide impera  
	for (List<string>::iterator it = list4.begin(); it != list4.end(); it++)  
	{   
		cout << *it << " "; 
	}    
	cout << endl; 

	system("pause");
	return 0;
}

