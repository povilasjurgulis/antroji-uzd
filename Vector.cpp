#include "vector.h"

template <typename T>
Vector<T>::Vector(): size(0), capacity(0), data(new T[size]) {}; // Konstruktorius

template <typename T>
Vector<T>::Vector(size_t dydis) : size(dydis), capacity(dydis), data(new T[dydis]) { // Konstruktorius su dydžiu
    for (size_t i = 0; i < size; ++i) {
        data[i] = 0; // Inicializuojame elementus
    }
}

template <typename T>
Vector<T>::Vector(const Vector& naujas): data_(new T[naujas.capacity_]), size_(naujas.size_), capacity_(naujas.capacity_) // Copy constructor 
{
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = naujas.data_[i];
        }
}

template <typename T>
Vector<T>::Vector(Vector&& naujas) noexcept: data_(naujas.data_), size_(naujas.size_), capacity_(naujas.capacity_) // Move constructor
{ 
        naujas.data_ = nullptr;
        naujas.size_ = 0;
        naujas.capacity_ = 0;
}

template <typename T>
Vector<T>::~Vector() { // Destruktorius
    delete[] data;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& naujas) // Copy priskyrimo operatorius
{
    if(this != &naujas)
    {
        delete[] data; // Istriname sena atminties bloka
        this->data = new T[naujas.capacity]; // Sukuriame nauja atminties bloka
        this->size = naujas.size;
        this->capacity = naujas.capacity;
        for (size_t i = 0; i < size; ++i) {
            this->data[i] = naujas.data[i];
        }
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& naujas) noexcept
{
    if(this != &naujas)
    {
        delete data[];
        this->data = new T[naujas.capacity];
        this->size = naujas.size;
        this->capacity = naujas.capacity;
        for(int i = 0; i < size; i++)
        {
            this->data[i] = naujas.data[i];
        }
    }
        delete naujas.data [];
        naujas.size = 0;
        naujas.capacity = 0;
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

template <typename T>
T& Vector<T>::at(size_t indeksas)
{
    if(indeksas >= size || indeksas < 0)
        throw std::out_of_range;
    else
        return data[indeksas];
}

template <typename T>
const T& Vector<T>::at(size_t indeksas) const
{
    if(indeksas >= size || indeksas < 0)
        throw std::out_of_range;
    else
        return data[indeksas];
}

template <typename T>
T& Vector<T>::front()
{
    return data[0];
}

template <typename T>
const T& Vector<T>::front() const
{
    return data[0];
}

template <typename T>
T& Vector<T>::back()
{
    return data[size-1];
}

template <typename T>
const T& Vector<T>::back() const
{
    return data[size-1];
}