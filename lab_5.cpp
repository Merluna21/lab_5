// lab_5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

class Cyl {
private:
    int height;
    int radius;
    double volume;
public:
    Cyl() {
        height = 0;
        radius = 0;
        volume = 0;
    }

    Cyl(int r, int h) {
        radius = r;
        height = h;
        volume = 0;
    }

    Cyl(int r, int h, double vol) {
        radius = r;
        height = h;
        volume = vol;
    }

    double Volume(Cyl a) {
        volume = 3.14 * radius * radius * height;
        return volume;
    }
    void SetR() {
        cout << "Введіть радіус: " << endl;
        cin >> radius;
    }

    void SetH() {
        cout << "Введіть висоту: " << endl;
        cin >> height;
    }

    int GetR() {
        return radius;
    }

    int GetH() {
        return height;
    }

    ~Cyl() {};

    friend ostream& operator << (ostream& out, Cyl& a);

    Cyl operator + (Cyl& o)
    {
        if (radius > o.radius) {
            Cyl f(radius, 0, volume + o.volume);
            return f;
        }
        else {
            Cyl k(o.radius, 0, volume + o.volume);
            return k;
        }
    }

    Cyl operator ++()
    {
        radius++;
        height++;
        volume = Volume(*this);
        return *this;
    }

    Cyl operator ++(int notused)
    {
        Cyl t = *this;
        radius++;
        height++;
        volume = Volume(*this);
        return t;
    }

};

ostream& operator << (ostream& out, Cyl& a) {
    if (a.height == 0)
        out << "\tРадіус = " << a.radius << "\tОбм'єм = " << a.volume << "\n\tВисота = 'Не уточнюється'" << endl;
    else
        out << "\tРадіус = " << a.radius << "\tВисота = " << a.height << "\tОбм'єм " << a.volume << endl;
    return out;
};

int main()
{
    SetConsoleOutputCP(1251);
    Cyl a(5, 6), b(5, 4);
    /*Cyl a,b;
    a.SetH();
    a.SetR();
    b.SetH();
    b.SetR();
    a.Volume(a);
    b.Volume(b);*/
    
    Cyl c = a + b;
    cout << "\nС = a + b" << "\nТоді параметри С:" << endl << c << endl;
    
    a = b++;
    cout << "\t\ta = b++" << endl;
    cout << "Параметри a: " << a << endl << "Параметри b: " << b << endl;

    a = ++b;
    cout << "\t\ta = ++b" << endl;
    cout << "Параметри a: " << a << endl << "Параметри b: " << b << endl;
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
