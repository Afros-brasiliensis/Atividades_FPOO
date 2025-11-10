#include <iostream>

using namespace std;

template<typename T>

void imprime(T a, T b)
{
    cout << "Soma: " << a + b << endl;
    cout << "Subtração: " << a - b << endl;
}

template <>
void imprime<bool>(bool a, bool b)
{
    cout << "Ou logico: " << (a || b) << endl;
}

int main(){
    imprime(10, 20);
    imprime(15.8, 10.9);

    imprime(true, false);
    imprime(false, true);
    imprime(true, true);
    imprime(false, false);
    return 0;

}