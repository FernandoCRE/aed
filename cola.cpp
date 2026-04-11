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
    void print();
};

template <class T, int N>
cola<T, N>::cola() {
    nro_elementos = N;
    arr = new T[nro_elementos];
    head = nullptr;
    tail = nullptr;
}

template <class T, int N>
void cola<T, N>::print() {
    if (vacio()) {
        cout << "La cola esta vacia.\n";
        return;
    }

    // puntero temporal
    T* t = head;

    while (true) {
        cout << *t << " "; 

        // t se movera circularmente
        if (t == arr + nro_elementos - 1) 
            t = arr; // fin=inicio
        else 
            t++;     

        // t=tail=fin
        if (t == tail) break;
    }
    cout << "\n";
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

    // next posicion de head
    T* proximo_head;
    if (head == arr + nro_elementos - 1) 
        proximo_head = arr;
    else 
        proximo_head = head + 1;

    // 2. head=tail=sacamos el ultimo elemento
    // significa que acabamos de sacar el último elemento.
    if (proximo_head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = proximo_head;
    }

    return true;
}

int main() {
    cola<int> c;
    
    
    c.push(1);
    c.print();
    int x;
    c.pop(x);
    c.print();
    c.pop(x);
    c.print();
    
    return 0;
}
