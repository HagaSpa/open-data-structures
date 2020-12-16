#include "array.cpp"
#include "utils.cpp"

template<class T>
class ArrayStack {
protected:
    array<T> a;
    int n;
    int size();
    virtual void resize();
public:
    ArrayStack();
    T get(int i);
    T set(int i, T x);
};

template<class T>
ArrayStack<T>::ArrayStack() : a(1) {
    n = 0;		
}

template<class T> inline
int ArrayStack<T>::size() {
    return n;
}

template<class T> inline
T ArrayStack<T>::get(int i) {
    return a[i];
}

template<class T> inline
T ArrayStack<T>::set(int i, T x) {
    T y = a[i];
    a[i] = x;
    return y;
}

template<class T>
void ArrayStack<T>::resize() {
    array<T> b(max(2*n, 1));
    for (int i=0; i<n; i++)
        b[i] = a[i];
    a = b;
}

// entry point
#include<iostream>
using namespace std;
int main() {
    ArrayStack<int> l;
    cout << l.get(0) << endl;
    l.set(0, 10);
    cout << l.get(0) << endl;
}