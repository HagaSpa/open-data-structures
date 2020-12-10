#include <cassert>

template<typename T>

class array
{
public:
    T *a;
    int length;

    // constructor
    array(int len) {
        length = len;
        a = new T[length];   
    }

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

int main() {
    array<T> a;
    a = array(6);

}
