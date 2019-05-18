#ifndef UTILS
#define UTILS

template <typename T>
class DynamicVector {
private:
    T * elements;
    int size;
    int capacity;
    void
    resize(double factor = 2);
public:
    DynamicVector(int capacity = 100);

    DynamicVector(const DynamicVector& v);

    ~DynamicVector();

    DynamicVector&
    operator = (const DynamicVector& v);

    T&
    operator [] (int pos);

    void
    add(const T& e);
    void
    remove(int pos);

    int
    getSize() const;
    int
    getCapacity() const;
    T *
    getElements() const;
};

#endif // ifndef UTILS
