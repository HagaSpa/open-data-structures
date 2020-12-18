#include<iostream>
using namespace std;

#include "array.cpp"
// #include "utils.cpp"

template<class T>
class ArrayQueue {
protected:
	array<T> a;
	int j;
	int n;
	void resize();
public:
	ArrayQueue();
	virtual bool add(T x);
	virtual T remove();
    T print();
};

template<class T>
ArrayQueue<T>::ArrayQueue() : a(1) {
	n = 0;
	j = 0;
}

template<class T>
void ArrayQueue<T>::resize() {
	array<T> b(max(2*n, 1));
	for (int k = 0; k < n; k++)
		b[k] = a[(j+k)%a.length];
	a = b;
	j = 0;
}

template<class T>
bool ArrayQueue<T>::add(T x) {
	if (n + 1 > a.length) resize();
	a[(j+n) % a.length] = x;
	n++;
	return true;
}

template<class T>
T ArrayQueue<T>::remove() {
	T x = a[j];
	j = (j + 1) % a.length;
	n--;
	if (a.length >= 3*n) resize();
	return x;
}

// for debug.
template<class T> inline
T ArrayQueue<T>::print() {
    for (int i=0; i<n; i++) {
        cout << a[i] << endl;
    } 
}

// entry point
int main() {
    ArrayQueue<string> l;
    
    l.add("a");
    l.add("b");
    l.add("c");

    l.add("d");

    l.print();

}