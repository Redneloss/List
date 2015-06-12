#ifndef LIST
#define LIST

#include <iostream>
using namespace std;

template<typename T>
class List
{
public:
	struct Node
	{
		Node(T);
		T m_data;
		Node* m_pNext;
		Node* m_pPrev;
	};
	List();
	~List();
	void push_front(const T&);
	void push_back(const T&);
	void pop_front();
	void pop_back();
	T& front();
	T& back();
	class iterator
	{
	public:
		iterator(Node*&);
		T& operator*();
		iterator& operator++();
		iterator operator++(int);
		bool operator != (const iterator&);
		Node* m_ptr;
	};
	iterator begin();
	iterator end();
	void insert(iterator, const T&);
	void erase(iterator);
	void clear();
	bool empty();

private:
	int m_size;
	Node* m_pHead;
	Node* m_pTail;
};
#endif LIST
