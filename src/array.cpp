#include <cassert>
#include <stdlib.h>

template<typename T>

class array
{
public:
    T *a;
    int length;

    // constructor
    array(int len);

    // index access
    T& operator[](int i) {
        assert(i >= 0 && i < length);
        return a[i];
    }

    // substitution
    array<T>& operator=(array<T> &b) {
        if (a != NULL) delete[] a;
        a = b.a;
        b.a = NULL;
        length = b.length;
        return *this;
    }
};

template<class T>
array<T>::array(int len) {
	length = len;
	a = new T[length];
}