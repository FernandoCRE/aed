#include <iostream>
using namespace std;

template <class T, int N = 10>
struct cola {
    int nro_elementos;   
    T* arr;
    T* head;
    T* tail;

    cola();
    ~cola();

    bool vacio();
    bool lleno();
    bool push(T valor);
    bool pop(T& valor);
};

template <class T, int N>
cola<T, N>::cola() {
    nro_elementos = N;
    arr = new T[nro_elementos];
    head = nullptr;
    tail = nullptr;
}

template <class T, int N>
cola<T, N>::~cola() {
    delete[] arr;
}

template <class T, int N>
bool cola<T, N>::vacio() {
    return head == nullptr && tail == nullptr;
}

template <class T, int N>
bool cola<T, N>::lleno() {
    if (vacio()) return false;
    return head == tail;
}

template <class T, int N>
bool cola<T, N>::push(T valor) {
    if (lleno()) return false;

    if (vacio()) {
        head = arr;
        tail = arr;
        *tail = valor;

        if (tail == arr + nro_elementos - 1)
            tail = arr;
        else
            tail++;

        return true;
    }

    *tail = valor;

    if (tail == arr + nro_elementos - 1)
        tail = arr;
    else
        tail++;

    return true;
}

template <class T, int N>
bool cola<T, N>::pop(T& valor) {
    if (vacio()) return false;

    valor = *head;

    // si solo hay un elemento
    if ((head == tail - 1) || (head == arr + nro_elementos - 1 && tail == arr)) {
        head = nullptr;
        tail = nullptr;
        return true;
    }

    // pila circular
    if (head == arr + nro_elementos - 1)
        head = arr;
    else
        head++;

    return true;
}

int main() {
    cola<int> c;

    c.push(1);
    c.push(2);
    c.push(3);
    c.push(4);

    int x;

    c.pop(x); cout << "es: " << x << endl;
    c.pop(x); cout << "es: " << x << endl;

    c.push(13);
    c.push(20);

    c.pop(x); cout << "es: " << x << endl;
    c.pop(x); cout << "es: " << x << endl;
    c.pop(x); cout << "es: " << x << endl;
    c.pop(x); cout << "es: " << x << endl;

    
    
    return 0;
}