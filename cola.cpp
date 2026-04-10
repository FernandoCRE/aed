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

    // Usamos un puntero temporal para no mover el 'head' original
    T* t = head;

    while (true) {
        cout << *t << " "; // Imprimimos el valor donde apunta t

        // Lógica para que el puntero 't' se mueva circularmente
        if (t == arr + nro_elementos - 1) 
            t = arr; // Si llega al final del arreglo, salta al inicio
        else 
            t++;     // Si no, avanza a la siguiente posición

        // Si después de avanzar, t alcanzó al tail, ya terminamos
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

    // 1. Calculamos cuál sería la posición SIGUIENTE del head
    T* proximo_head;
    if (head == arr + nro_elementos - 1) 
        proximo_head = arr;
    else 
        proximo_head = head + 1;

    // 2. Si el siguiente lugar del head es donde está el tail, 
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
