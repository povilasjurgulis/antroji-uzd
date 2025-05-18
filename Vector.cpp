#include "vector.h"

template <typename T>
Vector<T>::Vector(): size(0), capacity(0), data(new T[capacity]) {}; // Konstruktorius

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
    for (size_t i = 0; i < size; ++i)
        std::destroy_at(data + i);  // sunaikina visus T objektus
    
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
        delete []data;
        this->data = new T[naujas.capacity];
        this->size = naujas.size;
        this->capacity = naujas.capacity;
        for(int i = 0; i < size; i++)
        {
            this->data[i] = naujas.data[i];
        }
    }
        delete []naujas.data;
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

template <typename T>
size_t Vector<T>::max_size() const
{
    return std::numeric_limits<size_t>::max() / sizeof(T); // dalinti iš sizeof(T), nes tiek elementų tilptų į maksimalų baitų kiekį.
}

template <typename T>
size_t Vector<T>::size() const
{
    return size;
}

template <typename T>
size_t Vector<T>::capacity() const
{
    return capacity;
}

template <typename T>
bool Vector<T>::empty() const
{
    if(size == 0)
        return true;
    else
        return false;
}

template <typename T>
void Vector<T>::reserve(size_t new_capacity)
{
    if(new_capacity > max_size())
        throw std::length_error("Vector reserve() per didelis");
    else if(new_capacity > capacity)
    {
        T* new_data = new T[new_capacity];
        for(size_t i=0; i<size; i++)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
}

template <typename T>
void Vector<T>::shrink_to_fit()
{
    if(capacity = size)
        return;

    T* new_data = new T[size];
    for(int i = 0; i < size; i++)
    {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = size;
}

template <typename T>
void Vector<T>::resize(size_t new_size)
{
    if(new_size == size)
    {
        return;
    }

    else if(new_size > size)
    {
        T* new_data = new T[new_size];
        for (size_t i = 0; i < size; ++i)          // kopijuojam senus
        {
            new_data[i] = data[i];
        }
        for (size_t i = size; i < new_size; ++i)   // nauji default
        {
            new_data[i] = T{};
        }
        delete[] data;
        data = new_data;
        size = new_size;
        if(capacity <= new_size)
        {
            capacity = new_size + new_size/2 // padidiname capacity iki (arba lygiai) new_size*1.5 
        }
    }

    else if(new_size < size)
    {
        for (size_t i = new_size; i < size; ++i)
        {
            std::destroy_at(data + i);
            size = new_size;
        }
    }
}

template <typename T>
void Vector<T>::push_back(const T& new_value)
{
    if(size == capacity)
    {
        reserve(size + size/2)
    }

    data[size] = new_value;
    size++;
}

template <typename T>
void Vector<T>::push_back(T&& new_value)
{
    if(size == capacity)
    {
        reserve(size + size/2) // rezervuojame apie 1.5 kartus daugiau
    }

    data[size] = std::move(new_value);
    size++;   
}

template <typename T>
void Vector<T>::pop_back()
{
    if (size == 0)
        throw std::out_of_range("Vector::pop_back(): tuscias Vektorius");

    std::destroy_at(&data[size - 1]);   // sunaikiname paskutinį elementą
    --size;                            // sumažiname dydį
}

template <typename T>
void Vector<T>::clear()
{
    for(size_t i = 0; i < size; i++)
    {
        std::destroy_at(&data[i]);
    }
    size = 0;
}

template <typename T>
void Vector<T>::swap(Vector &naujas)
{
    swap(this->data, other.data);
    swap(this->size, other.size);
    swap(this->capacity, other.capacity);
}

template <typename T>
void Vector<T>::sort()
{
    std::sort(data);
}