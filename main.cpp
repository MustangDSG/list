#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

struct Elem                             //описываем структуру элемента связного списка
{
    int data;                           //полезная информация
    Elem* next;                         //указатель на следующий элемента
    Elem* prev;                         //указатель на предыдущий элемент
};


class Elemlist                          //описываем класс списка из элементов структуры Elem
{
 private:                               //закрытая часть класса
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
    void add(int d)                     //функция добавления нового элемента в список
    {
       Elem *newelem = new Elem;        //выделение памяти для нового элемента
       newelem -> data = d;             //задаем значение data новому элементу структуры
       newelem -> next = NULL;          //зануляем значение указателя на следующий элемент
       counter++;                       //увеличиваем значение счетчика элементов
       if (first == NULL)               //проверка, если список пустой - новый элемент структуры станет первым и одновременно последним, предыдущий станет NULL
       {
            first = newelem;
            newelem->prev=NULL;
            last=first;
       }
       else
       {
           newelem->prev=last;          //указатель на предыдущий элемент, для нового элемента предыдущим будет последний добавленный
           last -> next = newelem;      //указатель на следующий за последним существующим элементом т.е. тот, что добавляем сейчас
           last = newelem;              //новый элемент становится последним в списке
       }
    }
    void delf()                         //функция удаления первого элемента из списка
    {
        Elem *deletf = first;
        if (first)                      //проверка что первый элемент существует
        {
        first = deletf->next;
        first->prev=NULL;
        counter--;
        delete deletf;
        }
        else
        {
           system("cls");
           std::wcout<<L"Список пустой, удалять нечего!!!" << endl;
           system("pause");
        }
    }


    void del(int v)                     //метод удаления произвольного элемента
{
    if ((v==1) and (first->next) and (counter != 0))
    {
        Elem *delelem=first;
        first=first->next;
        first->prev=NULL;
        delete delelem;
        counter--;
        system("pause");
     }
    else if ((v==1) and (first==last) and (counter != 0))
    {
        first->next=NULL;
        first=NULL;
        delete first;
        counter--;
        system("pause");
    }
    else if ((v==counter) and (counter != 0))
    {
        Elem *delelem=last;
        last=last->prev;
        last->next=NULL;
        delete delelem;
        counter--;
        system("pause");
    }
    else if (counter=0)
    {
        std::wcout<<L"Список пустой, удалять нечего!!!";
        system("pause");
    }
    Elem *delelem=first,*delelem2;
    for (int i=0;i<v-1;i++) delelem=delelem->next;
    delelem2=delelem;
    delelem2->prev->next=delelem->next; //указываем, что следующий элемент для того, что стоит перед удаляемым это элемент, который стоит после удаляемого
    delelem2->next->prev=delelem->prev; //указываем, что предыдущий эелемент для того, что стоит после удаляемого это элемент, который стоит перед удаляемым
    delete delelem;
    counter--;
    system("pause");
}

    void vivod()                        //функция вывода списка от начала к концу
    {
        Elem *info = first;
        while(info)
        {
            cout << info -> data << endl;
            info = info -> next;
        }
    }

    void vivod2()                        //функция вывода списка от конца к началу
    {
        Elem *info2 = last;
        while(info2)
        {
            cout << info2 -> data << endl;
            info2 = info2 -> prev;
        }
    }
};


int main()
{
    setlocale(LC_CTYPE,"");
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
            std::wcout<<L"\nВведите числовое значение для нового элемента списка: ";
            cin >> q;
            m.add(q);
            std::wcout<<L"\nВведите 'y' для вода нового элемента; введите 'любое значение' для вывода списка: ";
            cin >> y;
    }
    system("cls");
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut,FOREGROUND_BLUE |FOREGROUND_INTENSITY);
    std::wcout<<L"\nСписок от начала к концу:" << endl;
    SetConsoleTextAttribute(hStdOut,FOREGROUND_GREEN |FOREGROUND_INTENSITY);
    m.vivod();
    SetConsoleTextAttribute(hStdOut,FOREGROUND_BLUE |FOREGROUND_INTENSITY);
    std::wcout<<L"\nСписок от конца к началу:" << endl;
    SetConsoleTextAttribute(hStdOut,FOREGROUND_GREEN |FOREGROUND_INTENSITY);
    m.vivod2();
    SetConsoleTextAttribute(hStdOut,FOREGROUND_RED |FOREGROUND_INTENSITY);
    std::wcout<<L"\nУдалить первый элемент? y - удалить | 'любое значение' - продолжить: ";
    cin >> z;
    if (z == "y")                       // условие запуска цикла удаления первого элемента списка
    {
        while (w == "y")                //цикл удаления первого элемента списка
        {
            m.delf();
            system("cls");
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hStdOut,FOREGROUND_BLUE |FOREGROUND_INTENSITY);
            std::wcout<<L"\nСписок:" << endl;
            SetConsoleTextAttribute(hStdOut,FOREGROUND_GREEN |FOREGROUND_INTENSITY);
            m.vivod();
            SetConsoleTextAttribute(hStdOut,FOREGROUND_BLUE |FOREGROUND_INTENSITY);
            std::wcout<<L"\nСписок от конца к началу:" << endl;
            SetConsoleTextAttribute(hStdOut,FOREGROUND_GREEN |FOREGROUND_INTENSITY);
            m.vivod2();
            cout << endl;
            SetConsoleTextAttribute(hStdOut,FOREGROUND_RED |FOREGROUND_INTENSITY);
            std::wcout<<L"Удалить новый первый элемент? 'y' - удалить, 'любое значение' - продолжить: ";
            cin >> w;

        }
    }
    SetConsoleTextAttribute(hStdOut,FOREGROUND_GREEN |FOREGROUND_INTENSITY);
    std::wcout<<L"Добавить новые элементы? 'y' - добавить, 'любое значение' - выход: ";
    y = "y";                               //обновление значения переменной
    z = "y";                               //обновление значения переменной
    w = "y";                               //обновление значения переменной
    cin >> x;
    }
    cout << endl;
    system("pause");
    return 0;
}
