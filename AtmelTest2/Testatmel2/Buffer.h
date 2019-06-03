/* 
* Buffer.h
*
* Created: 5/30/2019 3:52:35 PM
* Author: civel
*/


#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "List.h"

template< typename T >
class Buffer
{
//variables
public:
	int iCount, iValues;
protected:
private:
	int m_index;
	ListItem<T> *m_selected, *m_first;

//functions
public:
	Buffer(int t_count);
	
	void Previous();
	T GetPrevious();
	
	void Next();
	void SetNext(T t_value);
	T GetNext();
	
	void Add(T t_value);
	void Erase();
	
	~Buffer();
protected:
private:
	void Add(ListItem<T>* t_item);
	void RemoveAll();

}; //Buffer

template class Buffer<int>;
template class Buffer<float>;

#endif //__BUFFER_H__
