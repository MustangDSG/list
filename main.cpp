#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Elem                             //описываем структуру элемента связного списка
{
    string data;                        //полезная информация
    Elem* next;                         //указатель на следующий элемента
    Elem* prev;                         //указатель на предыдущий элемент
};

class Elemlist                          //описываем класс списка из элементов структуры Elem
{
private:                                //закрытая часть класса
    int counter;                        //счетчик элементот
    Elem* first;                        //указатель на первый элемент списка
    Elem* last;                         //указатель последний элемент списка
public:                                 //открытая часть класса
    Elemlist()
    {
        counter = 0;
        first = NULL;
        last = NULL;
    }
    void add(string d)                   //функция добавления нового элемента в список
    {
        Elem *newelem = new Elem;        //выделение памяти для нового элемента
        newelem -> data = d;             //задаем значение data новому элементу структуры
        newelem -> next = NULL;          //зануляем значение указателя на следующий элемент
        counter++;                       //увеличиваем значение счетчика элементов
        if (first == NULL)               //проверка, если список пустой - новый элемент структуры станет первым и одновременно последним, предыдущий станет NULL
        {
            first = newelem;
            newelem -> prev = NULL;
            last=first;
        }
        else
        {
            newelem -> prev = last;      //указатель на предыдущий элемент, для нового элемента предыдущим будет последний добавленный
            last -> next = newelem;      //указатель на следующий за последним существующим элементом т.е. тот, что добавляем сейчас
            last = newelem;              //новый элемент становится последним в списке
        }
    }

    void del(int v)                     //метод удаления произвольного элемента
    {
        if ( counter == 0 )             //если элементов в списке 0, то вывести сообщение о пустом списке
        {
            cout << "The list is empty, delete nothing ...\n";
            system("pause");
        }
        else if ( ( v > counter ) || ( v < 0 ) ) //если введеный номер удаляемого элемента больше чем вообще элементов или отрицательный, то отбой
        {
            cerr << "This item does not exist\n";
            system("pause");
        }
        else if ( ( v == 1 ) and ( first -> next ) ) //если удаляется первый элемент, но в списке больше 1 элемента
        {
            Elem *delelem = first;
            first = first -> next;
            first -> prev = NULL;
            delete delelem;
            counter--;
            ofstream result;
            result.open("result.txt", ios::out);
            result.close();
        }
        else if ( (v == 1) and ( first == last ) ) //если удаляется первый и единственный элемент
        {
            first -> next = NULL;
            first -> prev=NULL;
            first = NULL;
            last = NULL;
            delete first;
            counter--;
            ofstream result;
            result.open("result.txt", ios::out);
            result.close();
        }
        else if ( (v == counter) )                 //если удаляется последний элемент
        {
            Elem *delelem = last;
            last = last -> prev;
            last -> next = NULL;
            delete delelem;
            counter--;
            ofstream result;
            result.open("result.txt", ios::out);
            result.close();
        }
        else                                       //удаление элемента из середины списка
        {
            Elem *delelem = first;
            Elem *delelem2;
            for (int i=0;i<v-1;i++) delelem = delelem -> next;
            delelem2 = delelem;
            delelem2 -> prev -> next = delelem -> next; //указываем, что следующий элемент для того, что стоит перед удаляемым это элемент, который стоит после удаляемого
            delelem2 -> next -> prev = delelem -> prev; //указываем, что предыдущий эелемент для того, что стоит после удаляемого это элемент, который стоит перед удаляемым
            delete delelem;
            counter--;
            ofstream result;
            result.open("result.txt", ios::out);
            result.close();
        }
    }

    void vivod()                        //функция вывода списка от начала к концу
    {
        ofstream result;
        result.open("result.txt", ios::app);
        result << "---------------List from beginning to end:" << endl;
        result.close();
        Elem *info = first;
        while(info)
        {
            ofstream result;
            result.open("result.txt", ios::app);
            cout << info -> data << endl;
            result << info -> data << endl;
            result.close();
            info = info -> next;
        }
    }

    void vivod2()                        //функция вывода списка от конца к началу
    {
        ofstream result;
        result.open("result.txt", ios::app);
        result << "---------------List from back to front:" << endl;
        result.close();
        Elem *info2 = last;
        while(info2)
        {
            ofstream result;
            result.open("result.txt", ios::app);
            cout << info2 -> data << endl;
            result << info2 -> data << endl;
            result.close();
            info2 = info2 -> prev;
        }
    }
};

int main()
{
    ofstream result;
    result.open("result.txt", ios::out);
    result.close();
    string q;                           //переменная ввода данных в элемент списка
    int g;                              //переменная номера удаляемого элемента
    Elemlist m;                         //собственно наш список
    string y = "y";                     //переменная для цикла добавления нового элемента в список
    string x = "y";                     //переменная для главного цикла интерфейса
    string z = "y";                     //переменная для условия запуска цикла удаления первого элемента списка
    string w = "y";                     //переменная для цикла удаления первого элемента списка

    while (x == "y")                    //главный цикл управления интерфейсом
    {
        while (y == "y")                //цикл добавления нескольких новых элементов в список
        {
            cout << "\nEnter value for the new list item: ";
            cin >> q;
            m.add(q);
            cout << "\nType 'y' to enter a new item; type 'any value' to list: ";
            cin >> y;
        }
        system("cls");
        cout << "\nList from beginning to end:" << endl;
        m.vivod();
        cout << "\nList from back to front:" << endl;
        m.vivod2();
        //result<<123;
        cout << "\nDo you want to remove any item, y/n -? :";
        cin >> z;
        if ( z == "y" )
        {
            while ( w == "y")
            {
                cout << "\nEnter the number of deleted: ";
                cin >> g;
                m.del(g);
                system("cls");
                cout << "\nList from beginning to end:" << endl;
                m.vivod();
                cout << "\nList from back to front:" << endl;
                m.vivod2();
                cout << "\nDo you want to remove any item, y/n -? :";
                cin >> w;
            }
        }
        cout << "Add new items? 'y' - add; 'any value' - exit: ";
        y = "y";                        //обновление значения переменной
        z = "y";                        //обновление значения переменной
        w = "y";                        //обновление значения переменной
        cin >> x;
    }
    cout << endl;
    system("pause");
    return 0;
}
