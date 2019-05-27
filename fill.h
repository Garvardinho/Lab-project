#include <iostream>

using namespace std;

template <class T> void fill( T *arr, int size )
{
  for( int i = 0; i < size; i++ )
  {
    cout << "arr[" << i << "] = ";
    cin >> arr[i];
    cin.ignore( 1, '\n' );
  }
}

template <> void fill( char **arr, int size )
{
  char tmp[100];
  int len;

  for( int i = 0; i < size; i++ )
  {
    cout << "arr[" << i << "] = ";
    cin.getline( tmp, 100 );
    len = strlen( tmp ) + 1;

    arr[i] = new char[len];
    strcpy( arr[i], tmp );
  }
}