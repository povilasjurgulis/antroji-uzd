#include "vector.h"

template <typename T>
Vector<T>::Vector() : size(0), capacity(0), data(nullptr) {} // Konstruktorius

template <typename T>
Vector<T>::Vector(size_t size) : size(size), capacity(size), data(new T[size]) { // Konstruktorius su dydžiu
    for (size_t i = 0; i < size; ++i) {
        data[i] = 0; // Inicializuojame elementus
    }
}

template <typename T>
Vector<T>::Vector(const Vector& other): data_(new T[other.capacity_]), size_(other.size_), capacity_(other.capacity_) // Copy constructor 
{
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
}

template <typename T>
Vector<T>::Vector(Vector&& other) noexcept
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_) { // Move constructor
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
}

template <typename T>
Vector<T>::~Vector() { // Destruktorius
    delete[] data;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& newer) // Copy priskyrimo operatorius
{
    if(this != &newer)
    {
        delete[] data; // Istriname sena atminties bloka
        this->data = new T[newer.capacity]; // Sukuriame nauja atminties bloka
        this->size = newer.size;
        this->capacity = newer.capacity;
        for (size_t i = 0; i < size; ++i) {
            this->data[i] = newer.data[i];
        }
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& newer) noexcept
{
    if(this != &newer)
    {
        delete data[];
        this->data = new T[newer.capacity];
        this->size = newer.size;
        this->capacity = newer.capacity;
        for(int i = 0; i < size; i++)
        {
            this->data[i] = newer.data[i];
        }
    }
        delete newer.data [];
        newer.size = 0;
        newer.capacity = 0;
    return *this;
}

template <typename T>
T& Vector<T>::operator[](size_t index)
{
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const
{
    return data[index];
}