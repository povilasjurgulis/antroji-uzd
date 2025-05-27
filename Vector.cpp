#include "Vector.h"

template <typename T>
Vector<T>::Vector(): _size(0), _capacity(0), _data(nullptr) {}; // Konstruktorius

template <typename T>
Vector<T>::Vector(size_t dydis) : _size(dydis), _capacity(dydis), _data(dydis ? new T[dydis] : nullptr) { // Konstruktorius su dydžiu
    for (size_t i = 0; i < _size; ++i) {
        _data[i] = T{}; // Inicializuojame elementus
    }
}

template <typename T>
Vector<T>::Vector(const Vector& naujas): _data(naujas._capacity ? new T[naujas._capacity] : nullptr), _size(naujas._size), _capacity(naujas._capacity) // Copy constructor 
{
        for (size_t i = 0; i < _size; ++i) {
            std::construct_at(_data+i, naujas._data[i]);
        }
}

template <typename T>
Vector<T>::Vector(Vector&& naujas) noexcept: _data(naujas._data), _size(naujas._size), _capacity(naujas._capacity) // Move constructor
{ 
        naujas._data = nullptr;
        naujas._size = 0;
        naujas._capacity = 0;
}

template <typename T>
Vector<T>::~Vector() { // Destruktorius
    for (size_t i = 0; i < _size; ++i)
        std::destroy_at(_data + i);  // sunaikina visus T objektus
    
    delete[] _data;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& naujas) // Copy priskyrimo operatorius
{
    if (this == &naujas)
        return *this;

    T* new_data = new T[naujas._capacity];
    try {
        for (size_t i = 0; i < naujas._size; ++i)
            new_data[i] = naujas._data[i];        
    } catch (...) {
        delete[] new_data;
        throw;
    }

    delete[] _data; // Istriname sena atminties bloka
    _data = new_data; // Sukuriame nauja atminties bloka
    _size = naujas._size;
    _capacity = naujas._capacity;
    return *this;

}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& naujas) noexcept
{
    if(this == &naujas)
        return *this;
    
    //Jeigu this != &naujas
    clear();
    delete[] _data;

    _data = naujas._data;
    _size = naujas._size;
    _capacity = naujas._capacity;

    naujas._data = nullptr;
    naujas._size = 0;
    naujas._capacity = 0;
    
    return *this;
}

template <typename T>
T& Vector<T>::operator[](size_t index)
{
    return _data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const
{
    return _data[index];
}

template <typename T>
T& Vector<T>::at(size_t indeksas)
{
    if(indeksas < 0 || indeksas >= _size)
        throw std::out_of_range("Vector::at(): indeksas uz ribu");
    else
        return _data[indeksas];
}

template <typename T>
const T& Vector<T>::at(size_t indeksas) const
{
    if(indeksas < 0 || indeksas >= _size)
        throw std::out_of_range("Vector::at(): indeksas uz ribu");
    else
        return _data[indeksas];
}

template <typename T>
T& Vector<T>::front()
{
    return _data[0];
}

template <typename T>
const T& Vector<T>::front() const
{
    return _data[0];
}

template <typename T>
T& Vector<T>::back()
{
    return _data[_size-1];
}

template <typename T>
const T& Vector<T>::back() const
{
    return _data[_size-1];
}

template <typename T>
size_t Vector<T>::max_size() const
{
    return std::numeric_limits<size_t>::max() / sizeof(T); // dalinti iš sizeof(T), nes tiek elementų tilptų į maksimalų baitų kiekį.
}

template <typename T>
size_t Vector<T>::size() const noexcept
{
    return _size;
}

template <typename T>
size_t Vector<T>::capacity() const noexcept
{
    return _capacity;
}

template <typename T>
bool Vector<T>::empty() const noexcept
{
    if(_size == 0)
        return true;
    else
        return false;
}

template <typename T>
void Vector<T>::reserve(size_t new_capacity)
{
    if(new_capacity > max_size())
        throw std::length_error("Vector reserve() per didelis");
    else if(new_capacity > _capacity)
    {
        T* new_data = new T[new_capacity];
        for(size_t i=0; i<_size; i++)
        {
            new_data[i] = std::move(_data[i]);
        }
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }
}

template <typename T>
void Vector<T>::shrink_to_fit()
{
    if (_size == 0) 
    { 
        delete[] _data; _data=nullptr; _capacity=0; return; 
    }

    if(_capacity == _size)
        return;

    T* new__data = new T[_size];
    for(size_t i = 0; i < _size; i++)
    {
        new__data[i] = std::move(_data[i]);
    }
    delete[] _data;
    _data = new__data;
    _capacity = _size;
}

template <typename T>
void Vector<T>::resize(size_t new_size)
{
    if (new_size == _size) return;

    if (new_size < _size)
    {
        for (size_t i = new_size; i < _size; ++i)
            std::destroy_at(_data + i);

        _size = new_size;
        return;
    }

    if (new_size <= _capacity)
    {
        for (size_t i = _size; i < new_size; ++i)
            std::construct_at(_data + i);         

        _size = new_size;
        return;
    }

    reserve(new_size);          // reserve() pasirūpins _capacity & kopijavimu

    for (size_t i = _size; i < new_size; ++i)
        std::construct_at(_data + i);

    _size = new_size;
}

template <typename T>
void Vector<T>::push_back(const T& new_value)
{
    if(_size == _capacity)
    {
        std::size_t new_cap = _capacity ? _capacity * 3 / 2 : 1; // rezervuojame apie 1.5 kartus daugiau
        reserve(new_cap);
    }

    _data[_size] = new_value;
    _size++;
}

template <typename T>
void Vector<T>::push_back(T&& new_value)
{
    if(_size == _capacity)
    {
        std::size_t new_cap = _capacity ? _capacity * 3 / 2 : 1;
        reserve(new_cap); // rezervuojame apie 1.5 kartus daugiau
    }

    _data[_size] = std::move(new_value);
    _size++;   
}

template <typename T>
void Vector<T>::pop_back()
{
    if (_size == 0)
        throw std::out_of_range("Vector::pop_back(): tuscias Vektorius");

    std::destroy_at(&_data[_size - 1]);   // sunaikiname paskutinį elementą
    --_size;                            // sumažiname dydį
}

template <typename T>
void Vector<T>::clear()
{
    for(size_t i = 0; i < _size; i++)
    {
        std::destroy_at(&_data[i]);
    }
    _size = 0;
}

template <typename T>
void Vector<T>::swap(Vector &naujas)
{
    std::swap(this->_data, naujas._data);
    std::swap(this->_size, naujas._size);
    std::swap(this->_capacity, naujas._capacity);
}

template <typename T>
void Vector<T>::sort()
{
    std::sort(begin(), end());
}

template <typename T>
void Vector<T>::assign(size_t count, const T& value) {
    if (count > _capacity)
        reserve(count);

    // sunaikinam senus objektus
    for (size_t i = 0; i < _size; ++i)
        std::destroy_at(_data + i);

    // konstruojam naujus
    for (size_t i = 0; i < count; ++i)
        std::construct_at(_data + i, value);

    _size = count;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end() noexcept { return _data + _size; } // tas pats, kas &_data[_size]

template <typename T>
typename Vector<T>::const_iterator Vector<T>::end() const { return _data + _size; } // tas pats, kas &_data[_size]

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const noexcept { return _data + _size; } // tas pats, kas &_data[_size]

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() noexcept { return _data; }

template <typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const { return _data; }

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const noexcept { return _data; }

template <typename T>
typename Vector<T>::reverse_iterator Vector<T>::rbegin() noexcept { return reverse_iterator(end()); }

template <typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::rbegin() const noexcept { return const_reverse_iterator(end()); }

template <typename T>
typename Vector<T>::reverse_iterator Vector<T>::rend() noexcept { return reverse_iterator(begin()); }

template <typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::rend() const noexcept { return const_reverse_iterator(begin()); }

template <typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crbegin() const noexcept { return const_reverse_iterator(end()); }

template <typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crend() const noexcept { return const_reverse_iterator(begin()); }

template <typename T>
typename Vector<T>::iterator Vector<T>::insert(const_iterator pos, const T& value)
{
    if (pos < begin() || pos > end()) {
    throw std::out_of_range("insert position is invalid");
    }
     if (_size == _capacity)
        reserve(_capacity ? _capacity * 3 / 2 : 1);

    for(size_t i = _size; i > pos - _data; i--) // pos - _data yra tas pats, kas pos - begin()
    {
        std::construct_at(&_data[i], std::move(_data[i-1]));
        std::destroy_at(&_data[i-1]);
    }

    std::construct_at(&_data[pos-_data], value);
    ++_size;
    return _data + (pos - _data); // reikia iteratoriaus
}

template <typename T>
typename Vector<T>::iterator Vector<T>::insert( const_iterator pos, T&& value )
{
    if (pos < begin() || pos > end()) {
    throw std::out_of_range("insert position is invalid");
    }
     if (_size == _capacity)
        reserve(_capacity ? _capacity * 3 / 2 : 1);

    for(size_t i = _size; i > pos - _data; i--) // pos - _data yra tas pats, kas pos - begin()
    {
        std::construct_at(&_data[i], std::move(_data[i-1]));
        std::destroy_at(&_data[i-1]);
    }

    std::construct_at(&_data[pos-_data], std::move(value));
    ++_size;
    return _data + (pos - _data);
}

template <typename T>
T* Vector<T>::data() noexcept
{
    return _data; // Pirmo _data elemento adresas
} 

template <typename T>
const T* Vector<T>::data() const
{
    return _data; // Pirmo _data elemento adresas
} 

template <typename T>
template <typename... Args>
typename Vector<T>::iterator 
Vector<T>::emplace(const_iterator pos, Args&&... args)
{
    if (pos < begin() || pos > end())
        throw std::out_of_range("emplace position is invalid");
    
     if (_size == _capacity)
         reserve(_capacity ? _capacity * 3 / 2 : 1);
    
    for (size_t i = _size; i > pos - _data; --i) {
        std::construct_at(&_data[i], std::move(_data[i - 1]));
        std::destroy_at(&_data[i - 1]);
    }

    std::construct_at(&_data[pos - _data], std::forward<Args>(args)...); // forward perduoda argumentus tiksliai taip, kaip jie buvo gauti

    ++_size;
    return _data + (pos - _data);
}

template <typename T>
template<typename... Args>
void Vector<T>::emplace_back( Args&&... args )
{
    if(_capacity == _size)
         reserve(_capacity ? _capacity * 3 / 2 : 1);
    
    std::construct_at(&_data[_size], std::forward<Args>(args)...);

    ++_size;
}

template <typename T>
template <typename InputIteratorius>
typename Vector<T>::iterator Vector<T>::insert_range(const_iterator pos, InputIteratorius first, InputIteratorius last) 
{
    size_t count = std::distance(first, last);

    if (_size + count > _capacity)
         reserve(_capacity ? _capacity * 3 / 2 : 1);

    // Slenkam buvusius elementus į dešinę
    for (size_t i = _size; i > pos - _data; --i) // Jeigu pos==5, tai pos - _data == 4, nes _data yra rodyklė į pirmą elementą
    {
        std::construct_at(&_data[i - 1 + count], std::move(_data[i - 1]));
        std::destroy_at(&_data[i - 1]);
    }

    // Įterpiam naujus elementus
    for (size_t i = 0; i < count; ++i, ++first) {
        std::construct_at(&_data[pos - _data + i], *first);
    }

    _size += count;
    return _data + (pos - _data);
}

template <typename T>
template <typename R>
constexpr void Vector<T>::assign_range(R&& rg)
{
    static_assert(std::ranges::input_range<R>, "R must be an input range");
    static_assert(std::constructible_from<T, std::ranges::range_reference_t<R>>, "T must be constructible from range reference type");

    size_t count = std::ranges::distance(rg);
    if (count > _capacity)
        reserve(count + count / 2);
     
    auto it = std::ranges::begin(rg);
    for(size_t i=0; i < count; i++, it++)
    {
        std::destroy_at(&_data[i]);
        std::construct_at(&_data[i], *it);
    }

    if(count<_size)
        for(size_t i = count; i < _size; i++)
        {
            std::destroy_at(&_data[i]);
        }

    _size = count;
}

template <typename T>
Vector<T>::allocator_type Vector<T>::get_allocator() const
{
    return alloc;
}

template <typename T>
template <typename R>
constexpr void Vector<T>::append_range(R&& rg)
{
    static_assert(std::ranges::input_range<R>, "R must be an input range");
    static_assert(std::constructible_from<T, std::ranges::range_reference_t<R>>, "T must be constructible from range reference type");

    const size_t count = std::ranges::distance(rg);

    if (_size + count > _capacity)
        reserve(_size + count + count / 2);

    auto it = std::ranges::begin(rg);
    for (size_t i = 0; i < count; ++i, ++it)
    {
        std::construct_at(&_data[_size + i], std::forward<decltype(*it)>(*it));
    }

    _size += count;
}

template <typename T>
bool operator== (const Vector<T>& a, const Vector<T>& b)
{
    if (a._size != b._size) 
        return false;
    for (size_t i = 0; i < a._size; ++i) {
            if (!(a._data[i] == b._data[i])) return false;
        }
        return true;
}

template <typename T>
bool operator!=(const Vector<T>& a, const Vector<T>& b) {
    return !(a == b);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::erase(const_iterator pos)
{
    size_t index = pos - begin();
    if (pos < begin() || pos >= end()) {
    throw std::out_of_range("erase position is invalid");
    }
    
    for (size_t i = index + 1; i < _size; ++i) 
    {
        _data[i-1] = std::move(_data[i]);
    }

    std::destroy_at(&_data[_size - 1]); // sunaikiname paskutinį elementą
    _size--;

    return _data + (pos - _data);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::erase(const_iterator first, const_iterator last)
{
    if (first < begin() || first > end() || last  < begin() || last  > end() || last  < first)
    {
        throw std::out_of_range("Vector::erase(range) invalid range");
    }

    // Apskaičiuojam, kiek elementų triname
    size_t idx   = first - begin();
    size_t count = last  - first;  // gali būti 0

    for (size_t i = idx + count; i < _size; ++i) {
        _data[i - count] = std::move(_data[i]);
    }

    for (size_t i = _size - count; i < _size; ++i) {
        std::destroy_at(_data + i);
    }

    _size -= count;

    return _data + idx;
}