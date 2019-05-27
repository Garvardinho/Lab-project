#include <iostream>
#include <string.h>
#include "node.h"

using namespace std;

template <class T> class list
{
private:
  node<T> *head;

public:
  list();
  list( const list<T> &l );
  ~list();

  T operator-- ( int );
  void operator+ ( T );
  bool operator< ( list<T> & );
  bool operator> ( list<T> & );
};

template <class T> list<T>::list()
{
  head = nullptr;
}

template <class T> list<T>::list( const list<T> &l )
{
  node<T> *p1 = head;
  node<T> *p2 = l.head;

  while( p2 != nullptr )
  {
    p1 = new node<T>;
    p1->setval( p2->getval() );
    if( p2->getnext() != nullptr )
    {
      p1->setnext( new node<T> );
      p1 = p1->getnext();
      p2 = p2->getnext();
    }
    else
    {
      p1->setnext( nullptr );
      break;
    }
  }
}

template <class T> list<T>::~list()
{
  node<T> *ptr = head;
  node<T> *tmp;

  while( ptr != nullptr )
  {
    tmp = ptr->getnext();
    delete ptr;
    ptr = tmp;
  }
}

template <> list<char *>::~list()
{
  node<char *> *ptr = head;
  node<char *> *tmp;

  if( head != nullptr )
  {
    while( ptr != nullptr )
    {
      tmp = ptr->getnext();
      delete ptr->getval();
      delete ptr;
      ptr = tmp;
    }
  }
  
  delete head;
}
 
template <class T> T list<T>::operator-- ( int )
{
  setlocale( LC_ALL, "rus" );
  node<T> *ptr = head;
  T res;

  try
  {
    if( ptr != nullptr && ptr->getnext() != nullptr )
    {
      cout << "Извлечено: " << ptr->getval();
      res = ptr->getval();
      head = ptr->getnext();
      delete ptr;
    }
    else if(  ptr != nullptr && ptr->getnext() == nullptr )
    {
      cout << "Извлечено: " << ptr->getval();
      res = ptr->getval();
      delete head;
    }
    else
      throw "Список пуст";
  }
  catch ( char *s )
  {
    cout << s << endl;
    system( "pause" );
    return 0;
  }

  getchar();
  return res;
}

template <> char *list<char *>::operator-- ( int )
{
  setlocale( LC_ALL, "rus" );
  node<char *> *ptr = head;
  char *res;

  try
  {
    if( ptr != nullptr && ptr->getnext() != nullptr )
    {
      res = new char[strlen( ptr->getval() ) + 1];
      cout << "Извлечено: " << ptr->getval();
      strcpy( res, ptr->getval() );
      head = ptr->getnext();
      delete ptr->getval();
      delete ptr;
    }
    else if(  ptr != nullptr && ptr->getnext() == nullptr )
    {
      res = new char[strlen( ptr->getval() ) + 1];
      cout << "Извлечено: " << ptr->getval();
      strcpy( res, ptr->getval() );
      delete head->getval();
      delete head;
      head = nullptr;
    }
    else
      throw "Список пуст";
  }
  catch ( char *s )
  {
    cout << s << endl;
    system( "pause" );
    return 0;
  }

  getchar();
  return res;
}

template <class T> void list<T>::operator+ ( T val )
{
  node <T> *ptr = new node<T>;
  
  ptr->setval( val );
  ptr->setnext( head );
  head = ptr;
}

template <class T> bool list<T>::operator< ( list<T> &l )
{
  node<T> *p1 = head;
  node<T> *p2 = l.head;

  while( true )
  {
    if( p1 == nullptr && p2 != nullptr )
      return true;
    else if( p1 != nullptr && p2 == nullptr || p1 == nullptr && p2 == nullptr )
      return false;

    if( p1->getval() < p2->getval() )
      return true;
    else if( p1->getval() > p2->getval() )
      return false;

    p1 = p1->getnext();
    p2 = p2->getnext();
  }

  return false;
}

template <> bool list<char *>::operator< ( list<char *> &l )
{
  node<char *> *p1 = head;
  node<char *> *p2 = l.head;

  while( true )
  {
    if( p1 == nullptr && p2 != nullptr )
        return true;
    else if( p1 != nullptr && p2 == nullptr || p1 == nullptr && p2 == nullptr )
        return false;

    if( strcmp( p1->getval(), p2->getval() ) < 0 )
      return true;
    else if( strcmp( p1->getval(), p2->getval() ) > 0 )
      return false;

    p1 = p1->getnext();
    p2 = p2->getnext();
    
  }
  
  return false;
}

template <class T> bool list<T>::operator> ( list<T> &l )
{
  node<T> *p1 = head;
  node<T> *p2 = l.head;

  while( true )
  {
    if( p1 != nullptr && p2 == nullptr )
      return true;
    else if( p1 == nullptr && p2 != nullptr || p1 == nullptr && p2 == nullptr )
      return false;

    if( p1->getval() > p2->getval() )
      return true;
    else if( p1->getval() < p2->getval() )
      return false;

    p1 = p1->getnext();
    p2 = p2->getnext();
  }

  return false;
}

template <> bool list<char *>::operator> ( list<char *> &l )
{
  node<char *> *p1 = head;
  node<char *> *p2 = l.head;

  while( true )
  {
    if( p1 == nullptr && p2 != nullptr )
        return true;
    else if( p1 != nullptr && p2 == nullptr || p1 == nullptr && p2 == nullptr )
        return false;

    if( strcmp( p1->getval(), p2->getval() ) > 0 )
      return true;
    else if( strcmp( p1->getval(), p2->getval() ) < 0 )
      return false;

    p1 = p1->getnext();
    p2 = p2->getnext();
    
  }
  
  return false;
}