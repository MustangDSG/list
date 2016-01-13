#include <iostream>
#include <cstring>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Elem                             //��������� ��������� �������� �������� ������
{
    int data;                           //�������� ����������
    Elem* next;                         //��������� ��������
};


class Elemlist                          //��������� ����� ������ �� ��������� ��������� Elem
{
 private:                               //�������� ����� ������
    Elem* first;                        //��������� �� ������ ������� ������
    Elem* last;                         //��������� ��������� ������� ������
 public:                                //�������� ����� ������
    Elemlist()
    {
        first = NULL;
        last = NULL;
    }
    void add(int d)                     //������� ���������� ������ �������� � ������
    {
       Elem *newelem = new Elem;        //����� ������� ������
       newelem -> data = d;             //������ �������� data ������ �������� ���������
       newelem -> next = NULL;          //�������� �������� next ������ �������� ���������
       if (first == NULL)               //��������, ���� ������ ������ - ����� ������� ��������� ������ ������
           first = newelem;
       else  last -> next = newelem;    //���� ������ �� ������ (first !== NULL) - ����� ������� ��������� ��������� � ����� ������
       last = newelem;                  //����� ������� ���������� ��������� � ������
    }
    void delf()                         //������� �������� ������� �������� �� ������
    {
        Elem *deletf = first;
        if (first)                      //�������� ��� ������ ������� ����������
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

    void vivod()                        //������� ������ ������
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
    float q;                            //���������� ����� ������ � ������� ������
    Elemlist m;                         //���������� ��� ������
    string y = "y";                     //���������� ��� ����� ���������� ������ �������� � ������
    string x = "y";                     //���������� ��� �������� ����� ����������
    string z = "y";                     //���������� ��� ������� ������� ����� �������� ������� �������� ������
    string w = "y";                     //���������� ��� ����� �������� ������� �������� ������
    while (x == "y")                    //������� ���� ���������� �����������
    {
    while (y == "y")                    //���� ���������� ���������� ����� ��������� � ������
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
    if (z == "y")                       // ������� ������� ����� �������� ������� �������� ������
    {
        while (w == "y")                //���� �������� ������� �������� ������
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
    y = "y";                               //���������� �������� ����������
    z = "y";                               //���������� �������� ����������
    w = "y";                               //���������� �������� ����������
    cin >> x;
    }
    cout << endl;
    system("pause");
    return 0;
}
