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