#pragma once

#ifndef _LIST
#define _LIST

//includes
#include <Arduino.h>
#include "Defines.h"

#define FOREACH(item, list, intname)\
for (int intname = 0; intname < list->Count; intname++)\
{\
if (list->TryGetValueAt(intname, item))


#define END_FOREACH\
}

#define LIST_PARSE_INT(charList) List<char>::ParseInt(charList);

template< typename T >
class ListItem
{
public:
  ListItem(T value)
  {
    tpValue = new T();
    (*tpValue) = value;
    pPrevious = NULL;
    pNext = NULL;
  }

  ListItem<T>* pPrevious;
  ListItem<T>* pNext;
  T* tpValue;
  
  ~ListItem()
  {
    delete tpValue;
    tpValue = NULL;
  }
};

template< typename T >
class List
{
public:
  ListItem<T>* pStart;
  ListItem<T>* pLast;
  int Count;

  List()
  {
    Count = 0;
    pStart = NULL;
    pLast = NULL;
  }

  bool TryGetItemAt(int index, ListItem<T>*& pOutput)
  {
    if (index > Count - 1) return false;

    ListItem<T>* pItem = pStart;

    for (int i = index; i > 0; i--)
    {
      pItem = pItem->pNext;
    }
    pOutput = pItem;
    return true;
  }

  bool TryGetValueAt(int index, T& pOutput)
  {
    ListItem<T>* item;
    T* t;

    if (TryGetItemAt(index, item))
    {
      t = item->tpValue;
      pOutput = *t;
      return true;
    }
    return false;
  }

  int Find(T t_value) //returns index of an item, if item does not exist, returns -1
  {
    T t;
    for (int i = 0; i < Count; i++)
    {
      if (TryGetValueAt(i, t))
      {
        if (t == t_value) return i;
      }
    }
    return -1;
  }

  void Remove(int index)
  {
    ListItem<T>* item;
    if (TryGetItemAt(index, item))
    {
      if (item->pNext != nullptr && item->pPrevious != nullptr)
      {
        item->pNext->pPrevious = item->pPrevious;
        item->pPrevious->pNext = item->pNext;
      }
      else
      {
        if (item->pNext == nullptr)
        {
          pLast = item->pPrevious;
        }
        if (item->pPrevious == nullptr)
        {
          pStart = item->pNext;
        }
      }
      item->~ListItem<T>();
      delete item;
      item = NULL;
      Count--;
    }
  }

  void Add(T value)
  {
    Count++;
    if (pStart == NULL)
    {
      pStart = new ListItem<T>(value);
      pLast = pStart;
      return;
    }
    ListItem<T>* pItem = new ListItem<T>(value);

    pLast->pNext = pItem;
    pItem->pPrevious = pLast;
    pLast = pItem;
  }

  bool operator==(List<T>* t_l)
  {
    if (Count != t_l->Count) return false;
    for (int i = 0; i < Count; i++)
    {
      T t1, t2;
      if (TryGetValueAt(i, t1))
      {
        if (t_l->TryGetValueAt(i, t2))
        {
          if (t1 != t2)
          {
            return false;
          }
        }
      }
    }
    return true;
  }

  T& operator[](int index)
  {
    T output;
    if (TryGetValueAt(index, output))
    {
      return output;
    }
    return NULL;
  }

  ~List()
  {
    ListItem<T>* item = pStart->pNext;

    for (int i = 1; i < Count - 1; i++)
    {
      item->pPrevious->~ListItem<T>();
    }
    pLast->~ListItem<T>();
  }

  static List<List<char>*>* Split(char* ca[], char splitChar)
  {
    int iStart = 0;
    List<List<char>*>* output = new List<List<char>*>();

    for (int i = 0; i < sizeof(*ca); i++)
    {
      if ((*ca[i] == splitChar) || (i == sizeof(*ca)))
      {
        List<char>* lc = new List<char>();
        for (int ii = iStart; ii < i; ii++)
        {
          lc->Add(*ca[ii]);
        }
        output->Add(lc);
        iStart = i;
      }
    }
    return output;
  }

  /*
   * Split:
   * 
   * ex: "hey,you,whatya,doing"
   * value: {h;e;y;,;y;o;u;,;w;h;a;t;y;a;,;d;o;i;n;g}
   * 
   * result : {{h;e;y};{y;o;u};{w;h;a;t;y;a};{d;o;i;n;g}}
   * 
   * step 1:
   * set starting point of new List<char> to current position (int iStart = 0)
   * 
   *  /
   * {h;e;y;,;y;o;u;,;w;h;a;t;y;a;,;d;o;i;n;g}
   * 
   * step 2:
   * look for a split char
   * 
   *  /     \
   * {h;e;y;,;y;o;u;,;w;h;a;t;y;a;,;d;o;i;n;g}
   * 
   * step 3:
   * add the chars from starting point to current position - 1 to the new List<char>
   * 
   * {h;e;y}
   *  /   \
   * {h;e;y;,;y;o;u;,;w;h;a;t;y;a;,;d;o;i;n;g}
   * 
   * step 4:
   * add the new List<char> to the output
   * 
   * {{h;e;y}}
   * 
   * step 5:
   * set the starting point to current + 1
   * 
   *          /
   * {h;e;y;,;y;o;u;,;w;h;a;t;y;a;,;d;o;i;n;g}
   */

  static List<List<char>*>* Split(List<char>* t_text, char t_splitChar)
  {
    int iStart = 0;
    List<List<char>*>* output = new List<List<char>*>();
    char c1, c2;

    for (int i = 0; i < t_text->Count; i++)
    {
      if (t_text->TryGetValueAt(i, c1)) //Getting c1
      {
        
        if ((c1 == t_splitChar) || (i == t_text->Count - 1)) //Checking if the char is a split char or if the for reached the last item of the list
        {
          List<char>* lc = new List<char>();
          
          for (int ii = iStart; ii < i; ii++) //Getting c2
          {
            if (t_text->TryGetValueAt(ii, c2)) //Getting c1
            {
              lc->Add(c2);
            }
            
          }
          if (i == t_text->Count - 1)
          {
            if (t_text->TryGetValueAt(i, c2)) //Getting c1
            {
              lc->Add(c2);
            }
          }
          output->Add(lc);
          iStart = i + 1;
        }
        
      }
    }
    return output;
  }

  /*
  static List<char>* FromCharArray(char* ca[])
  {
    List<char>* output = new List<char>();
    for(int i = 0; i < sizeof(*ca); i++)
    {
      output->Add(*ca[i]);
    }
    return output;
  }*/

  static List<char>* FromString(String* s)
  {
    List<char>* output = new List<char>();
    for(int i = 0; i < s->length(); i++)
    {
      output->Add(s->charAt(i));
    }
    return output;
  }

  static void Print(List<char>* lc, bool toDebug = false)
  {
    char c;
    for (int i = 0; i < lc->Count; i++)
    {
      if (lc->TryGetValueAt(i, c))
      {
        if (toDebug)
        {
          DebugWrite(c, 1);
        }
        else 
        {
          Serial.print(c);
        }
      }
    }
  }

  static void Print(List<List<char>*>* llc, bool toDebug = false)
  {
    
    List<char>* lc;
    for (int i = 0; i < llc->Count; i++)
    {
      if (i != 0) 
      {
        if (toDebug) DebugWrite(',', 1);
        else Serial.print(',');
      }
      if (llc->TryGetValueAt(i, lc))
      {
        Print(lc, toDebug);
      }
    }
  }

  static int ToInt(List<char>* t_value) //works between 0 and 99
  {
    char c;
    bool bsign = false;
    int result = 0;
    int d = t_value->Count - 1;
        
    for (int i = 0; i < t_value->Count; i++, d--)
    {
      if (t_value->TryGetValueAt(d, c))
      {
        //Serial.println("char");
        //Serial.println(c);
        //Serial.println("pow");
        int p = int((pow(10,i) * m_ParseInt(c)));
        //Serial.println(p);
        result += p;
        /*
        if ((i == 0) && (c == '-'))
        {
          bsign = true;
          Serial.println("signed");
        }
        else
        {
          
          Serial.println("char");
          Serial.println(c);
          //Serial.println("EXP");
          //Serial.println((float)(t_value->Count - 1 - bsign - i));
          //Serial.println("pow");
          //Serial.println((int)(pow(10.0f,(float)(t_value->Count - 1 - bsign - i))));
          int surplus = 0;
          if (t_value->Count - 1 - bsign - i >= 2) surplus = t_value->Count - 2 - bsign - i;
          int n = (m_ParseInt(c) * (int)(pow(10.0f,(float)(t_value->Count - 1 - bsign - i))));
          Serial.println("n * pow");
          Serial.println(n * (int)(pow(10.0f,(float)(t_value->Count - 1 - bsign - i))));
          //Serial.println("n");
          //Serial.println(n);
          
          result += n;
        }*/
      }
    }
    return result;
  }


  private:
  
  static int m_ParseInt(char t_c)
  {
    switch (t_c)
    {
      case '0':
      return 0;
      case '1':
      return 1;
      case '2':
      return 2;
      case '3':
      return 3;
      case '4':
      return 4;
      case '5':
      return 5;
      case '6':
      return 6;
      case '7':
      return 7;
      case '8':
      return 8;
      case '9':
      return 9;
    }
    return -1;
  }
};

#endif

