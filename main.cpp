#include <iostream>
#include "header.h"

using namespace std;

int main()
{
  setlocale( LC_ALL, "rus" );
  int ch1;

  do
  {
    system( "cls" );
    cout << "Выберите задание:\n1. Бинарный поиск\n2. Односвязный список\n0. Выход\nВаш выбор: ";
    cin >> ch1;

    if( ch1 == 1 )
    {
      int ch2;

      do
      {
        system( "cls" );

        int size;
        cout << "С каким типом данных вы хотите работать:\n1. Int\n2. Char\n3. Float\n4. Double\n5. Char *\n0. Выход\nВаш выбор: ";
        cin >> ch2;

        if( ch2 == 0 )
          break;

        cin.ignore( 1, '\n' );

        cout << endl <<  "Введите размер массива: ";
        cin >> size;
        cin.ignore( 1, '\n' );

        system( "cls" );

        switch( ch2 )
        {
        case 1:
          {
            int *arr = new int[size];
            int key;

            fill( arr, size );

            cout << "Введите значение для поиска: ";
            cin >> key;
            cin.ignore( 1, '\n' );

            my_sort( arr, size );
            binsearch( arr, size, key );
            delete [] arr;
            break;
          }

        case 2:
          {
            char *arr = new char[size];
            char key;

            fill( arr, size );

            cout << "Введите значение для поиска: ";
            cin >> key;
            cin.ignore( 1, '\n' );

            my_sort( arr, size );
            binsearch( arr, size, key );
            delete [] arr;
            break;
          }

        case 3:
          {
            float *arr = new float[size];
            float key;

            fill( arr, size );

            cout << "Введите значение для поиска: ";
            cin >> key;
            cin.ignore( 1, '\n' );

            my_sort( arr, size );
            binsearch( arr, size, key );
            delete [] arr;
            break;
          }

        case 4:
          {
            double *arr = new double[size];
            double key;

            fill( arr, size );

            cout << "Введите значение для поиска: ";
            cin >> key;
            cin.ignore( 1, '\n' );

            my_sort( arr, size );
            binsearch( arr, size, key );
            delete [] arr;
            break;
          }

        case 5:
          {
            char **arr = new char*[size];
            char key[100];

            fill( arr, size );

            cout << "Введите значение для поиска: ";
            cin >> key;
            cin.ignore( 1, '\n' );

            my_sort( arr, size );
            binsearch( arr, size, key );

            for( int i = 0; i < size; i++ )
              delete [] arr[i];

            delete [] arr;
            break;
          }
        }

        getchar();
      } while ( true );
    }
    else if( ch1 == 2 )
    {
      int ch2, ch3, ch4;

      do
      {
        system( "cls" );
        cout << "С каким типом данных вы хотите работать:\n1. Int\n2. Char\n3. Float\n4. Double\n5. Char *\n0. Выход\nВаш выбор: ";
        cin >> ch2;

        if( ch2 == 0 )
          break;

        cin.ignore( 1, '\n' );
        system( "cls" );

        switch( ch2 )
        {
        case 1:
          {
            list<int> l1, l2;
            int elem;

            do
            {
              system( "cls" );
              cout << "С каким списком вы хотите работать?\n1. Первый\n2. Второй\n3. Сравнить списки\n0. Выход\nВаш выбор: ";
              cin >> ch3;
              cin.ignore( 1, '\n' );  
              
              if( ch3 == 3 )
              {
                (l1 < l2) ? cout << endl << "l1 < l2" : cout << endl << "l1 >= l2";
                (l1 > l2) ? cout << endl << "l1 > l2" : cout << endl << "l1 <= l2";
                getchar();
              }
              else if( ch3 == 2 || ch3 == 1 )
              {
                system("cls");
                cout << "1. Добавить элемент\n2. Извлечь\nВаш выбор: ";
                cin >> ch4;
                cin.ignore( 1, '\n' );

                if( ch4 == 1 )
                {
                  cout << endl << "Введите значение: ";
                  cin >> elem;
                  cin.ignore( 1, '\n' );

                  (ch3 == 1) ? l1 + elem : l2 + elem;
                }
                else if( ch4 == 2 )
                  (ch3 == 1) ? l1-- : l2--;
              }
              else if( ch3 == 0 )
                break;

            } while( true );
            break;
          }

        case 2:
          {
            list<char> l1, l2;
            char elem;

            do
            {
              system( "cls" );
              cout << "С каким списком вы хотите работать?\n1. Первый\n2. Второй\n3. Сравнить списки\n0. Выход\nВаш выбор: ";
              cin >> ch3;
              cin.ignore( 1, '\n' );  
              
              if( ch3 == 3 )
              {
                (l1 < l2) ? cout << endl << "l1 < l2" : cout << endl << "l1 >= l2";
                (l1 > l2) ? cout << endl << "l1 > l2" : cout << endl << "l1 <= l2";
                getchar();
              }
              else if( ch3 == 2 || ch3 == 1 )
              {
                system("cls");
                cout << "1. Добавить элемент\n2. Извлечь\nВаш выбор: ";
                cin >> ch4;
                cin.ignore( 1, '\n' );

                if( ch4 == 1 )
                {
                  cout << endl << "Введите значение: ";
                  cin >> elem;
                  cin.ignore( 1, '\n' );

                  (ch3 == 1) ? l1 + elem : l2 + elem;
                }
                else if( ch4 == 2 )
                  (ch3 == 1) ? l1-- : l2--;
              }
              else if( ch3 == 0 )
                break;

            } while( true );
            break;
          }

        case 3:
          {
            list<float> l1, l2;
            float elem;

            do
            {
              system( "cls" );
              cout << "С каким списком вы хотите работать?\n1. Первый\n2. Второй\n3. Сравнить списки\n0. Выход\nВаш выбор: ";
              cin >> ch3;
              cin.ignore( 1, '\n' );  
              
              if( ch3 == 3 )
              {
                (l1 < l2) ? cout << endl << "l1 < l2" : cout << endl << "l1 >= l2";
                (l1 > l2) ? cout << endl << "l1 > l2" : cout << endl << "l1 <= l2";
                getchar();
              }
              else if( ch3 == 2 || ch3 == 1 )
              {
                system("cls");
                cout << "1. Добавить элемент\n2. Извлечь\nВаш выбор: ";
                cin >> ch4;
                cin.ignore( 1, '\n' );

                if( ch4 == 1 )
                {
                  cout << endl << "Введите значение: ";
                  cin >> elem;
                  cin.ignore( 1, '\n' );

                  (ch3 == 1) ? l1 + elem : l2 + elem;
                }
                else if( ch4 == 2 )
                  (ch3 == 1) ? l1-- : l2--;
              }
              else if( ch3 == 0 )
                break;

            } while( true );
            break;
          }

        case 4:
          {
            list<double> l1, l2;
            double elem;

            do
            {
              system( "cls" );
              cout << "С каким списком вы хотите работать?\n1. Первый\n2. Второй\n3. Сравнить списки\n0. Выход\nВаш выбор: ";
              cin >> ch3;
              cin.ignore( 1, '\n' );  
              
              if( ch3 == 3 )
              {
                (l1 < l2) ? cout << endl << "l1 < l2" : cout << endl << "l1 >= l2";
                (l1 > l2) ? cout << endl << "l1 > l2" : cout << endl << "l1 <= l2";
                getchar();
              }
              else if( ch3 == 2 || ch3 == 1 )
              {
                system("cls");
                cout << "1. Добавить элемент\n2. Извлечь\nВаш выбор: ";
                cin >> ch4;
                cin.ignore( 1, '\n' );

                if( ch4 == 1 )
                {
                  cout << endl << "Введите значение: ";
                  cin >> elem;
                  cin.ignore( 1, '\n' );

                  (ch3 == 1) ? l1 + elem : l2 + elem;
                }
                else if( ch4 == 2 )
                  (ch3 == 1) ? l1-- : l2--;
              }
              else if( ch3 == 0 )
                break;

            } while( true );
            break;
          }

        case 5:
          {
            list<char *> l1, l2;
            char *elem = new char[100];

            do
            {
              system( "cls" );
              cout << "С каким списком вы хотите работать?\n1. Первый\n2. Второй\n3. Сравнить списки\n0. Выход\nВаш выбор: ";
              cin >> ch3;
              cin.ignore( 1, '\n' );  
              
              if( ch3 == 3 )
              {
                (l1 < l2) ? cout << endl << "l1 < l2" : cout << endl << "l1 >= l2";
                (l1 > l2) ? cout << endl << "l1 > l2" : cout << endl << "l1 <= l2";
                getchar();
              }
              else if( ch3 == 2 || ch3 == 1 )
              {
                system("cls");
                cout << "1. Добавить элемент\n2. Извлечь\nВаш выбор: ";
                cin >> ch4;
                cin.ignore( 1, '\n' );

                if( ch4 == 1 )
                {
                  cout << endl << "Введите значение: ";
                  cin.getline( elem, 100 );

                  (ch3 == 1) ? l1 + elem : l2 + elem;
                }
                else if( ch4 == 2 )
                  (ch3 == 1) ? l1-- : l2--;
              }
              else if( ch3 == 0 )
                break;

            } while( true );

            delete [] elem;
            break;
          }
        }
      } while ( true );
    }
    else if( ch1 == 0 )
      break;

  } while ( true );
  return 0;
}