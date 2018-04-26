#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    int rndNumber = rand();
    cout << rndNumber << endl;

    //int const *p; // int ist konstant, also Ziel des Zeigers
    //int *const p; // Zeiger ist konstant

    struct Datum
    {
        int tag;
        int monat;
        int jahr;
    };
    Datum d;
    d.tag = 1;
    d.monat = 4;
    d.jahr = 2018;
    union Zeug
    {
        char x[8];
        char y[8];
        char z[8];
        char a[8];
    };
    Zeug p;
    for(int i = 0; i < 8; i++)
    {
        // p.x[i] = (char)('A' + i);
        // p.x[i] = char('A' + i);
        p.x[i] = static_cast<char>('A' + i);
        // reinterpret_cast
        // p.y[i] = reinterpret_cast<char>('A' + i);
        // dynamic_cast
        // p.z[i] = dynamic_cast<char>('A' + i);
        // const_cast
        // p.a[i] = const_cast<char>('A' + i);
    }
    cout << p.x << endl;
    cout << p.y << endl;
    cout << p.z << endl;
    cout << p.a << endl;

    return 0;
}