#include <iostream>
#include <string.h>

using namespace std;

template <typename T> void binsearch( T *arr, int size, T key )
{
  setlocale( LC_ALL, "rus" );

  if( key < arr[0] || key > arr[size - 1] )
  {
    cout << "Такого элемента нет" << endl;
    return;
  }

  int highb = size - 1, lowb = 0;
  int i = ( highb + lowb ) / 2;

  while( true )
  {
    if( arr[i] < key )
    {
      lowb = i;
      i = ( highb + lowb ) / 2;
    }
    else if( arr[i] > key )
    {
      highb = i;
      i = ( highb + lowb ) / 2;
    }
    else
    {
      cout << "Найдено!" << endl;
      return;
    }

    if( highb - lowb == 1 )
    {
      cout << "Такого элемента нет" << endl;
      return;
    }
  }
}

template <> void binsearch( char **arr, int size, char *key )
{
  setlocale( LC_ALL, "rus" );

  if( strcmp( key, arr[0] ) < 0 || strcmp( key, arr[size - 1] ) > 0 )
  {
    cout << "Такого элемента нет" << endl;
    return;
  }

  int highb = size - 1, lowb = 0;
  int i = ( highb + lowb ) / 2;

  while( true )
  {
    if( strcmp( arr[i], key ) < 0 )
    {
      lowb = i;
      i = ( highb + lowb ) / 2;
    }
    else if( strcmp( arr[i], key ) > 0 )
    {
      highb = i;
      i = ( highb + lowb ) / 2;
    }
    else
    {
      cout << "Найдено!" << endl;
      return;
    }

    if( highb == lowb )
    {
      cout << "Такого элемента нет" << endl;
      return;
    }
  }
}