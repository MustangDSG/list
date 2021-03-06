#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>
#include <stdlib.h>
//ignore this string, it`s some test...
using namespace std;

ofstream result;

int cls()  //crossplatform clear screen
{
    int r;
#ifdef windows
    r = system("cls");
#else
    r = system("clear");
#endif
    return r;
}

int greeting()
{
    cout << "Welcome!" << endl;
    cout << "(c) 2016 Vaspull - All rights reserved." << endl;
#ifdef windows
    cout << "The program is compiled for use in Windows-like system.\n" << endl;
#else
    cout << "The program is compiled for use in Linux-like system.\n" << endl;
#endif
    return(0);
}

class Elemlist                          //We describe a class list of the elements of the structure Elem
{
private:
    struct Elem                         //Describe the structure of a linked list
    {
        string data;                    //The information includes a list item
        Elem* next;                     //Pointer to the next element
        Elem* prev;                     //A pointer to the previous element
    };
    int counter;                        //Counter items
    Elem* first;                        //Pointer to the first element of the list
    Elem* last;                         //Pointer to the last item in the list
public:
    Elemlist()
    {
        counter = 0;
        first = NULL;
        last = NULL;
    }
    void add(string d)                   //A method of adding a new item to the list
    {
        Elem *newelem = new Elem;        //Memory allocation for the new element
        newelem -> data = d;             //We set the value of data to the new structure element
        newelem -> next = NULL;          //Assigning a pointer to the next element to NULL
        counter++;                       //Increase the value of the counter elements
        if ( first == NULL )             //Checking if the list is empty - a new element of the structure will be the first and last at the same time, the previous will be NULL
        {
            first = newelem;
            newelem -> prev = NULL;
            last=first;
        }
        else
        {
            newelem -> prev = last;      //A pointer to the previous element, for the new element will be the previous recently added
            last -> next = newelem;      //A pointer to the next element appearing after the last existing element that is the one that is now adding
            last = newelem;              //A new element becomes the last in the list
        }
    }

    void del(int v)                     //Removal of any element
    {
        if ( counter == 0 )             //If the list is empty, then display a message indicating an empty list
        {
            cout << "<-------The list is empty, delete nothing...------->\n";
            cout << "Press ENTER to continue" << endl;
            cin.get();
        }
        else if ( ( v > counter ) || ( v < 1 ) ) //If the number is more than the element to remove all items in the list or negative, then an error message
        {
            cerr << "<-------This item does not exist, try again------->\n";
            cout << "Press ENTER to continue" << endl;
            cin.get();
        }
        else if ( ( v == 1 ) and ( first -> next ) ) //If the first element is removed, but the list of more than 1 item
        {
            Elem *delelem = first;
            first = first -> next;
            first -> prev = NULL;
            delete delelem;
            counter--;
            result.open("result.txt", ios::out);
            result.close();
        }
        else if ( ( v == 1 ) and ( first == last ) ) //If you delete the first and only item
        {
            first -> next = NULL;
            first -> prev=NULL;
            first = NULL;
            last = NULL;
            delete first;
            counter--;
            result.open("result.txt", ios::out);
            result.close();
        }
        else if ( (v == counter) )                 //If you delete the last item
        {
            Elem *delelem = last;
            last = last -> prev;
            last -> next = NULL;
            delete delelem;
            counter--;
            result.open("result.txt", ios::out);
            result.close();
        }
        else                                       //Remove item from the middle of the list
        {
            Elem *delelem = first;
            Elem *delelem2;
            for ( int i = 1 ; i < v ; i++ ) delelem = delelem -> next;
            delelem2 = delelem;
            delelem2 -> prev -> next = delelem -> next; //Indicates that the next item to the fact that it is facing a removable element which is removed after
            delelem2 -> next -> prev = delelem -> prev; //Point out that the previous element for what is to be removed after an element that stands in front of removable
            delete delelem;
            counter--;
            result.open("result.txt", ios::out);
            result.close();
        }
    }

    void vivod()                        //Output Method numbered list
    {
        time_t seconds = time(NULL);
        tm* timeinfo = localtime(&seconds);
        result.open("result.txt", ios::out);
        result.close();
        int counter2 = 1;
        result.open("result.txt", ios::app);
        result << "---------------List from beginning to end:  "<< asctime(timeinfo) << endl;
        result.close();
        Elem *info = first;
        Elem *info2 = last;
        cout << "\nList from beginning to end:  " << asctime(timeinfo) << endl;
        while( info )
        {
            result.open("result.txt", ios::app);
            cout << counter2 << ". " <<info -> data << endl;
            result << counter2 << ". " <<info -> data << endl;
            result.close();
            info = info -> next;
            if ( info )
            {
                counter2++;
            }
        }
        result.open("result.txt", ios::app);
        result << "\n---------------List from back to front:" << endl;
        result << "\n";
        result.close();
        cout << "\nList from back to front:" << endl;
        while( info2 )
        {
            result.open("result.txt", ios::app);
            cout << counter2 << ". " << info2 -> data << endl;
            result << counter2 << ". " << info2 -> data << endl;
            result.close();
            info2 = info2 -> prev;
            if ( info2 )
            {
                counter2--;
            }
        }
    }
};

int char_analisys()
{
    cls();
    greeting();
    string char_analisys;
    char A[2000] = "";
    for ( int i = 0 ; i < 2000 ; i++ ) A[i] = 0;
    cout << "Enter a string for analysis:" << endl;
    cout << ">";
    getline(cin, char_analisys);
    strcpy( A , char_analisys.c_str() );
    int d = 0;
    int j = 0;
    char b;
    int o = 0;
    char e[100] = "";
    for ( int i = 0 ; i < 100 ; i++ ) e[i] = 0;
    int counter = 0;
    int p = 0;
    while( A[d] ) d++; //Поиск длины анализируемой строки
    cout << "\nSource string -  " << A << endl;
    cout << "The initial line of " << d << " characters." << "\n" << endl;
    for ( int c = 0 ; c < d ; c++ ) //главный цикл анализа строки, выполняется равное количеству символов в строке раз
    {
        int k = 1;
        int t = 0;
        p = 0;
        b = A[c];
        while( e[j] ) j++; //поиск длины дополнительного массива, в который будут складоваться символы используемые в анализируемой строке (каждый символ 1 раз)
        for ( int i = 0; i < d; i++) //цикл для подсчета количества раз использования каждого символа в строке, а также запись в дополнительный массив символов используемых в анализируемой строке (каждый символ 1 раз)
        {
            if ( b == A[i] )
            {
                counter++;
            }
            if  ( ( p <= j ) && ( k != 0 ) )
            {
                if ( b == e[p] )
                {
                    t = 0;
                    k = 0;
                }
                else
                {
                    t = 1;
                    k = 1;
                }
            }
            p++;
        }
        if ( t == 1 )
        {
            cout << b << "  " << counter << endl;
            e[o] = b;
            o++;
        }
        counter = 0;
    }
    cout << "\nThe End." << endl;
    return(0);
}

int list()
{
    cls();
    greeting();
    string q;                           //Variable input data item in the list
    int g;                              //Variable numbers removed element
    Elemlist m;                         //Our list
    string y = "y";                     //Variable cycle for adding a new item to the list
    string x = "y";                     //Variable for the main loop interface
    string z = "y";                     //Variable trigger conditions for removal cycle of the first element of the list
    string w = "y";                     //Variable cycle for removing the any item in the list
    while (x == "y")                    //The main loop control interface
    {
        while (y == "y")                //Cycle adding several new items to the list
        {
            cout << "\nEnter value for the new list item: ";
            getline ( cin ,q );
            m.add(q);
            cout << "\nType 'y' to enter a new item; type 'any value' to list: ";
            getline ( cin , y );
        }
        cls();
        m.vivod();
        cout << "\nDo you want to remove any item, y/n -? :";
        getline ( cin , z );
        if ( z == "y" )
        {
            while ( w == "y")
            {
                char ch = 'q';
                string str;
re: cout << "\nEnter the number of deleted: ";
                getline ( cin , str );
                int strlength = str.length();
                for ( int t = 0 ; t < strlength; t++ )
                {
                    ch = str.c_str()[t];
                }
                if ( !isdigit(ch) )
                {
                    cerr << "Invalid value, try again\n";
                    goto re;
                }
                g = atoi( str.c_str() );
                m.del(g);
                cls();
                m.vivod();
                cout << "\nDo you want to remove any item, y/n -? :";
                getline (cin , w );
            }
        }
        cout << "Add new items? 'y' - add; 'any value' - exit: ";
        y = "y";                        //Updating the value of the variable
        z = "y";                        //Updating the value of the variable
        w = "y";                        //Updating the value of the variable
        getline ( cin , x );
    }
    cout << endl;
    return (0);
}

int main()
{
re: cls();
    greeting();
    cout << "Choose\n";
    cout << "1. Char analysis programm\n";
    cout << "2. List programm\n";
    cout << "3. Exit\n";
    cout << "Selection: ";

    char ch = 'q';
    string str;
    int g;
    getline ( cin , str );
    int strlength = str.length();
    for ( int t = 0 ; t < strlength; t++ )
    {
        ch = str.c_str()[t];
    }
    if ( !isdigit(ch) )
    {
        cerr << "Invalid value, press Enter to try again\n";
        cin.get();
        goto re;
    }
    g = atoi( str.c_str() );

    switch ( g )
    {
    case 1:
        char_analisys();
        break;
    case 2:
        list();
        break;
    case 3:
        cout << "\nThe End." << endl;
        return(0);
    default:
        cerr << "Invalid value, press Enter to try again\n";
        cin.get();
        goto re;
    }
    return(0);
}
