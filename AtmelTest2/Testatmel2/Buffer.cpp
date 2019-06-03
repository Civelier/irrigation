/* 
* Buffer.cpp
*
* Created: 5/30/2019 3:52:35 PM
* Author: civel
*/


#include "Buffer.h"

// default constructor
template < typename T >
Buffer<T>::Buffer(int t_count)
{
	for (int i = 1; i < t_count; i++)
	{
		Add(new ListItem<T>(NULL));
	}
} //Buffer

template < typename T >
void Buffer<T>::RemoveAll()
{
	ListItem<T>* pTemp;
	while (m_selected != nullptr)
	{
		pTemp = m_selected->pNext;
		m_selected->~ListItem();
		delete m_selected;
		m_selected = pTemp;
	}
	iCount = 0;
}

template < typename T >
void Buffer<T>::Previous()
{
	m_selected = m_selected->pPrevious == nullptr ? m_selected : m_selected->pPrevious;
}

template < typename T >
T Buffer<T>::GetPrevious()
{
	Previous();
	return (*m_selected->tpValue);
}

template < typename T >
void Buffer<T>::Next()
{
	DebugWriteLine("Next", 2);
	m_selected = m_selected->pNext == nullptr ? m_selected : m_selected->pNext;
	DebugWriteLine("Next finished", 2);
}

template < typename T >
T Buffer<T>::GetNext()
{
	Next();
	return (*m_selected->tpValue);
}

template < typename T >
void Buffer<T>::SetNext(T t_value)
{
	if (iValues != 0) Next();
	if (m_selected->tpValue == nullptr) 
	{
		iValues++;
		DebugWrite("Values = ", 2);
		DebugWriteLine(iValues, 2);
	}
	delete m_selected->tpValue;
	m_selected->tpValue = new T(t_value);
}

template < typename T >
void Buffer<T>::Add(T t_value)
{
	Add(new ListItem<T>(t_value));
}

template < typename T >
void Buffer<T>::Add(ListItem<T>* t_item)
{
	if (m_selected == nullptr) 
	{
		m_first = t_item;
		m_selected = t_item;
		m_selected->pNext = m_selected;
		m_selected->pPrevious = m_selected;
	}
	else
	{
		m_selected->pNext = t_item;
		t_item->pPrevious = m_selected;
		m_first->pPrevious = t_item;
		t_item->pNext = m_first;
		m_selected = t_item;
	}
	iCount++;
}

template < typename T >
void Buffer<T>::Erase()
{
	for (int i = 0; i < iCount; i++)
	{
		Next();
		delete m_selected->tpValue;
	}
	iValues = 0;
}

// default destructor
template < typename T >
Buffer<T>::~Buffer()
{
	RemoveAll();
} //~Buffer
