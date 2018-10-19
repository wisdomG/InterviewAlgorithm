#include <iostream>

template<typename T>
class shared_ptr {
private:
    T *ptr;
    int *cnt;
public:
    shared_ptr(T *p) {
        ptr = p;
        cnt = new int(1);
    }
    shared_ptr(const shared_ptr<T> &other) {
        ptr = other.ptr;
        ++(*other.cnt);
        cnt = other.cnt;
    }
    shared_ptr<T>& operator=(const shared_ptr<T> &other) {
        if (other == *this) return *this;
        if (ptr != nullptr && --(*cnt) == 0) {
            delete ptr;
            delete cnt;
        }
        ptr = other.ptr;
        ++(*other.cnt);
        cnt = other.cnt;
        return *this;
    }
    ~shared_ptr() {
        if (--(*cnt) == 0) {
            delete ptr;
            delete cnt;
        }
    }
};

int main()
{
    return 0;
}
