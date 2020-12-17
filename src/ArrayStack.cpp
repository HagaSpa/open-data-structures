#include "array.cpp"
#include "utils.cpp"

template<class T>
class ArrayStack {
protected:
    array<T> a;
    int n;
    virtual void resize();
public:
    ArrayStack();
    T get(int i);
    T set(int i, T x);
    int size();
    virtual void add(int i, T x);
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

// insert.
template<class T>
void ArrayStack<T>::add(int i, T x) {
    if (n+1 > a.length) resize();
    for (int j=n; j>i; j--) {
        a[j] = a[j-1];
    }
    a[i] = x;
    n++;
}

// entry point_
#include<iostream>
using namespace std;
int main() {
    ArrayStack<int> l;
    
    l.set(0, 1);    
    l.add(0, 2);
    l.add(1, 3);

    for (int i=0; i<l.size(); i++) {
        cout << l.get(i) << endl;
    }
}