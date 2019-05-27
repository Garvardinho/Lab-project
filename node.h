#include <string.h>

template <class T> class node
{
private:
  node *next;
  T value;

public:
  T getval();
  node<T> *getnext();
  void setval( T );
  void setnext( node<T> *);
};

template <class T> node<T> *node<T>::getnext()
{
  return next;
}

template <> node<char *> *node<char *>::getnext()
{
  return next;
}

template <class T> T node<T>::getval()
{
  return value;
}

template <> char *node<char *>::getval()
{
  return value;
}

template <class T> void node<T>::setnext( node<T> *p )
{
  next = p;
}

template <> void node<char *>::setnext( node<char *> *p )
{
  next = p;
}

template <class T> void node<T>::setval( T v )
{
  value = v;
}

template <> void node<char*>::setval( char *v )
{
  value = new char[strlen( v ) + 1];
  strcpy( value, v );
}