#include <stdio.h>
#include <string>

#include "utils.h"
#include "domain.h"

template <typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
    this->size     = 0;
    this->capacity = capacity;
    this->elements = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
{
    this->size     = v.size;
    this->capacity = v.capacity;
    this->elements = new T[v.capacity];
    for (int i = 0; i < v.capacity; i++) {
        this->elements[i] = v.elements[i];
    }
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
    delete[] this->elements;
}

template <typename T>
DynamicVector<T>&
DynamicVector<T>::operator = (const DynamicVector<T>& v)
{
    if (this == &v)
        return *this;

    this->size     = v.size;
    this->capacity = v.capacity;

    delete[] this->elements;
    this->elements = new T[v.capacity];
    for (int i = 0; i < v.capacity; i++) {
        this->elements[i] = v.elements[i];
    }
    return *this;
}

template <typename T>
DynamicVector<T>&
operator + (DynamicVector<T>& v, const T& e)
{
    v.add(e);
    return v;
}

template <typename T>
DynamicVector<T>&
operator + (const T& e, DynamicVector<T>& v)
{
    v.add(e);
    return v;
}

template <typename T>
T&
DynamicVector<T>::operator [] (int pos)
{
    return this->elements[pos];
}

template <typename T>
void
DynamicVector<T>::add(const T& e)
{
    if (this->size == this->capacity)
        resize();
    this->elements[this->size++] = e;
}

template <typename T>
void
DynamicVector<T>::remove(int pos)
{
    while (pos < this->size) {
        this->elements[pos] = this->elements[pos + 1];
        pos++;
    }
    this->size--;
}

template <typename T>
void
DynamicVector<T>::resize(double factor)
{
    this->capacity *= static_cast<int>(factor);
    T * els = new T[this->capacity];
    for (int i = 0; i < this->size; i++)
        els[i] = this->elements[i];
    delete[] this->elements;
    this->elements = els;
}

template <typename T>
int
DynamicVector<T>::getSize() const
{
    return this->size;
}

template <typename T>
int
DynamicVector<T>::getCapacity() const
{
    return this->capacity;
}

template <typename T>
T *
DynamicVector<T>::getElements() const
{
    return this->elements;
}

template class DynamicVector<Dog>;
