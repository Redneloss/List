#include "List.h"

template<typename T>
List<T>::Node::Node(T data)
{
	m_data = data;
	m_pNext = m_pPrev = nullptr;
}

template<typename T>
List<T>::List()
{
	m_size = 0;
	m_pHead = m_pTail = nullptr;
}

template<typename T>
List<T>::~List()
{
	if (!empty())
	{
		Node* i = m_pHead;
		while (true)
		{
			i = i->m_pNext;
			if (i != nullptr)
			{
				delete i->m_pPrev;
				i->m_pPrev = nullptr;
			}
			else
			{
				delete m_pTail;
				m_pTail = m_pHead = nullptr;
				break;
			}
		}
		m_size = 0;
	}
}

template<typename T>
void List<T>::push_front(const T& value)
{
	if (m_pHead == nullptr)
	{
		m_pHead = new Node(value);
		m_pTail = m_pHead;
	}
	else
	{
		Node* temp = new Node(value);
		temp->m_pNext = m_pHead;
		m_pHead->m_pPrev = temp;
		m_pHead = temp;
	}
	m_size++;
}

template<typename T>
void List<T>::push_back(const T& value)
{
	if (m_pHead == nullptr)
	{
		m_pHead = new Node(value);
		m_pTail = m_pHead;
	}
	else
	{
		Node* temp = new Node(value);
		m_pTail->m_pNext = temp;
		temp->m_pPrev = m_pTail;
		m_pTail = temp;
	}
	m_size++;
}

template<typename T>
void List<T>::pop_front()
{
	if (!this->empty())
	{
		m_pHead = m_pHead->m_pNext;
		m_pHead->m_pPrev = nullptr;
		m_size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	if (!this->empty())
	{
		m_pTail = m_pTail->m_pPrev;
		m_pTail->m_pNext = nullptr;
		m_size--;
	}
}

template<typename T>
T& List<T>::front()
{
	return m_pHead->m_data;
}

template<typename T>
T& List<T>::back()
{
	return m_pTail->m_data;
}

template<typename T>
List<T>::iterator::iterator(Node*& ptr) : m_ptr(ptr)
{
}

template<typename T>
T& List<T>::iterator::operator*()
{
	return m_ptr->m_data;
}

template<typename T>
typename List<T>::iterator& List<T>::iterator::operator++()
{
	m_ptr = m_ptr->m_pNext;
	return *this;
}

template<typename T>
typename List<T>::iterator List<T>::iterator::operator++(int)
{
	iterator temp = *this;
	m_ptr = m_ptr->m_pNext;
	return temp;
}

template<typename T>
bool List<T>::iterator::operator != (const iterator& it)
{
	return m_ptr != it.m_ptr;
}

template<typename T>
typename List<T>::iterator List<T>::begin()
{
	iterator it(m_pHead);
	return it;
}

template<typename T>
typename List<T>::iterator List<T>::end()
{
	iterator it(m_pTail->m_pNext);
	return it;
}

template<typename T>
void List<T>::insert(iterator it, const T& value)
{
	Node* temp = new Node(value);

	if (empty())
	{
		m_pHead = m_pTail = temp;
		temp->m_pNext = temp->m_pPrev = nullptr;
	}
	else
	{
		if (it.m_ptr == nullptr)
		{
			temp->m_pNext = nullptr;

			m_pTail->m_pNext = temp;
			temp->m_pPrev = m_pTail;

			m_pTail = temp;
		}
		else
		{
			if (it.m_ptr->m_pPrev == nullptr)
			{
				temp->m_pPrev = nullptr;
				m_pHead = temp;
			}
			else
			{
				it.m_ptr->m_pPrev->m_pNext = temp;
				temp->m_pPrev = it.m_ptr->m_pPrev;
			}

			temp->m_pNext = it.m_ptr;
			it.m_ptr->m_pPrev = temp;
		}
	}

	m_size++;
}

template<typename T>
void List<T>::erase(iterator it)
{
	if (it.m_ptr != nullptr)
	{
		if (it.m_ptr->m_pPrev == nullptr && it.m_ptr->m_pNext == nullptr)
		{
			m_pHead = m_pTail = nullptr;
		}

		if (it.m_ptr->m_pPrev == nullptr && it.m_ptr->m_pNext != nullptr)
		{
			it.m_ptr->m_pNext->m_pPrev = nullptr;
			m_pHead = it.m_ptr->m_pNext;
		}

		if (it.m_ptr->m_pPrev != nullptr && it.m_ptr->m_pNext == nullptr)
		{
			it.m_ptr->m_pPrev->m_pNext = nullptr;
			m_pTail = it.m_ptr->m_pPrev;
		}

		if (it.m_ptr->m_pPrev != nullptr && it.m_ptr->m_pNext != nullptr)
		{
			it.m_ptr->m_pPrev->m_pNext = it.m_ptr->m_pNext;
			it.m_ptr->m_pNext->m_pPrev = it.m_ptr->m_pPrev;
		}

		m_size--;
		delete it.m_ptr;
	}
	else
	{
		cerr << "Erasing failed!" << endl;
	}
}

template<typename T>
void List<T>::clear()
{
	this->~List();
}

template<typename T>
bool List<T>::empty()
{
	return !m_size;
}

