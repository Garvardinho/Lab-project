#include <string.h>

template <class T> void my_sort( T *arr, int size )
{
  int j = 0;
  T tmp;

  for( int i = 0; i < size; i++ )
  {
    j = i;

    for( int k = i; k < size; k++ )
      if( arr[j] > arr[k] )
        j = k;

    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }
}

template <> void my_sort ( char **arr, int size )
{
  int j = 0;
  char *tmp = new char[1024];

  for( int i = 0; i < size; i++ )
  {
    j = i;

    for( int k = i + 1; k < size; k++ )
    {
      if( strcmp( arr[j], arr[k] ) > 0 )
        j = k;
    }

    if( strcmp( arr[i], arr[j] ) != 0 )
    {
      strcpy( tmp, arr[i] );
      delete[] arr[i];
      arr[i] = new char[strlen( arr[j] ) + 1];

      strcpy( arr[i], arr[j] );
      delete[] arr[j];
      arr[j] = new char[strlen( tmp ) + 1];

      strcpy( arr[j], tmp );
    }

  }
}