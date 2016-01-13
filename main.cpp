#include <iostream>
#include <cstring>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Elem                             //описываем структуру элемента связного списка
{
    int data;                           //полезная информация
    Elem* next;                         //указатель элемента
};


class Elemlist                          //описываем класс списка из элементов структуры Elem
{
 private:                               //закрытая часть класса
    Elem* first;                        //указатель на первый элемент списка
    Elem* last;                         //указатель последний элемент списка
 public:                                //открытая часть класса
    Elemlist()
    {
        first = NULL;
        last = NULL;
    }
    void add(int d)                     //функция добавления нового элемента в список
    {
       Elem *newelem = new Elem;        //новый элемент списка
       newelem -> data = d;             //задаем значение data новому элементу структуры
       newelem -> next = NULL;          //зануляем значение next новому элементу структуры
       if (first == NULL)               //проверка, если список пустой - новый элемент структуры станет первым
           first = newelem;
       else  last -> next = newelem;    //если список не пустой (first !== NULL) - новый элемент структуры добавится в конец списка
       last = newelem;                  //новый элемент становится последним в списке
    }
    void delf()                         //функция удаления первого элемента из списка
    {
        Elem *deletf = first;
        if (first)                      //проверка что первый элемент существует
        {
        cout << "Udalyau: " << deletf->data<<endl;
        first = deletf->next;
        }
        else
        {
           system("cls");
           cout << "Spisok Pust!!!" << endl;
           system("pause");
        }
    }

    void vivod()                        //функция вывода списка
    {
        Elem *info = first;
        while(info)
        {
            cout << info -> data << endl;
            info = info -> next;
        }
    }
};


int main()
{
    float q;                            //переменная ввода данных в элемент списка
    Elemlist m;                         //собственно наш список
    string y = "y";                     //переменная для цикла добавления нового элемента в список
    string x = "y";                     //переменная для главного цикла интерфейса
    string z = "y";                     //переменная для условия запуска цикла удаления первого элемента списка
    string w = "y";                     //переменная для цикла удаления первого элемента списка
    while (x == "y")                    //главный цикл управления интерфейсом
    {
    while (y == "y")                    //цикл добавления нескольких новых элементов в список
    {
            //system("color A");
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hStdOut,FOREGROUND_GREEN |FOREGROUND_INTENSITY);
            cout << "\nVvedite chislovoe znachenie novogo elementa spiska: ";
            cin >> q;
            m.add(q);
            cout << "\n'y' - novoe znachenie; Any key - vivod spiska: ";
            cin >> y;
    }
    system("cls");
    cout << "\nSpisok:" << endl;
    m.vivod();
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut,FOREGROUND_RED |FOREGROUND_INTENSITY);
    cout << "\nUdalit perviy element? Y - Da, Any key - prodoljit: ";
    cin >> z;
    if (z == "y")                       // условие запуска цикла удаления первого элемента списка
    {
        while (w == "y")                //цикл удаления первого элемента списка
        {
            m.delf();
            system("cls");
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            cout << "\nSpisok:" << endl;
            SetConsoleTextAttribute(hStdOut,FOREGROUND_GREEN |FOREGROUND_INTENSITY);
            m.vivod();
            cout << endl;
            SetConsoleTextAttribute(hStdOut,FOREGROUND_RED |FOREGROUND_INTENSITY);
            cout << "Udalit noviy perviy element? Y - Da, Any key - prodoljit: ";
            cin >> w;

        }
    }
    SetConsoleTextAttribute(hStdOut,FOREGROUND_GREEN |FOREGROUND_INTENSITY);
    cout << "Dobavit novie elementy? Y - Da, Any key - exit: ";
    y = "y";                               //обновление значения переменной
    z = "y";                               //обновление значения переменной
    w = "y";                               //обновление значения переменной
    cin >> x;
    }
    cout << endl;
    system("pause");
    return 0;
}
