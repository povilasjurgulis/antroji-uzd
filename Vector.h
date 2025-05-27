#ifndef VECTOR_H
#define VECTOR_H

#include <ranges>
#include <iterator>
#include <utility>   // for std::move
#include <type_traits>
#include <concepts>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <limits>

template <typename T>
class Vector{
    
        size_t _size;
        size_t _capacity;
        T* _data;

        static T* allocate(std::size_t n) {
        return n ? new T[n] : nullptr;
        }
        static void deallocate(T* p) {
        delete [] p;
        }
        
        using iterator = T*;
        using const_iterator = const T*;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;
        using allocator_type = std::allocator<T>;
        std::allocator<T> alloc;

        public:

Vector(): _size(0), _capacity(0), _data(nullptr) {}; // Konstruktorius

Vector(size_t dydis) : _size(dydis), _capacity(dydis), _data(dydis ? new T[dydis] : nullptr) { // Konstruktorius su dydžiu
    for (size_t i = 0; i < _size; ++i) {
        _data[i] = T{}; // Inicializuojame elementus
    }
}

Vector(std::initializer_list<T> il)
    : _size(il.size()),
      _capacity(il.size()),
      _data(il.size() ? new T[il.size()] : nullptr)
{
    std::uninitialized_copy(il.begin(), il.end(), _data);
}

Vector(const Vector<T>& naujas): _data(naujas._capacity ? new T[naujas._capacity] : nullptr), _size(naujas._size), _capacity(naujas._capacity) // Copy constructor 
{
        for (size_t i = 0; i < _size; ++i) {
            std::construct_at(_data+i, naujas._data[i]);
        }
}

Vector(Vector<T>&& naujas) noexcept: _data(naujas._data), _size(naujas._size), _capacity(naujas._capacity) // Move constructor
{ 
        naujas._data = nullptr;
        naujas._size = 0;
        naujas._capacity = 0;
}

~Vector() { // Destruktorius
    for (size_t i = 0; i < _size; ++i)
        std::destroy_at(_data + i);  // sunaikina visus T objektus
    
    delete[] _data;
}

Vector<T>& operator=(const Vector<T>& naujas) // Copy priskyrimo operatorius
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

Vector<T>& operator=(Vector<T>&& naujas) noexcept
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

T& operator[](size_t index)
{
    return _data[index];
}

const T& operator[](size_t index) const
{
    return _data[index];
}

T& at(size_t indeksas)
{
    if(indeksas < 0 || indeksas >= _size)
        throw std::out_of_range("Vector::at(): indeksas uz ribu");
    else
        return _data[indeksas];
}

const T& at(size_t indeksas) const
{
    if(indeksas < 0 || indeksas >= _size)
        throw std::out_of_range("Vector::at(): indeksas uz ribu");
    else
        return _data[indeksas];
}

T& front()
{
    return _data[0];
}

const T& front() const
{
    return _data[0];
}

T& back()
{
    return _data[_size-1];
}

const T& back() const
{
    return _data[_size-1];
}

size_t max_size() const
{
    return std::numeric_limits<size_t>::max() / sizeof(T); // dalinti iš sizeof(T), nes tiek elementų tilptų į maksimalų baitų kiekį.
}

size_t size() const noexcept
{
    return _size;
}

size_t capacity() const noexcept
{
    return _capacity;
}

bool empty() const noexcept
{
    if(_size == 0)
        return true;
    else
        return false;
}

void reserve(size_t new_capacity)
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

void shrink_to_fit()
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

void resize(size_t new_size)
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

void push_back(const T& new_value)
{
    if(_size >= _capacity)
    {
        std::size_t new_cap = _capacity ? _capacity * 2 : 1; // rezervuojame apie 1.5 kartus daugiau
        reserve(new_cap);
    }

    _data[_size] = new_value;
    _size++;
}

void push_back(T&& new_value)
{
    if(_size == _capacity)
    {
        std::size_t new_cap = _capacity ? _capacity * 2 : 1;
        reserve(new_cap); // rezervuojame apie 1.5 kartus daugiau
    }

    _data[_size] = std::move(new_value);
    _size++;   
}

void pop_back()
{
    if (_size == 0)
        throw std::out_of_range("Vector::pop_back(): tuscias Vektorius");

    std::destroy_at(&_data[_size - 1]);   // sunaikiname paskutinį elementą
    --_size;                            // sumažiname dydį
}

void clear()
{
    for(size_t i = 0; i < _size; i++)
    {
        std::destroy_at(&_data[i]);
    }
    _size = 0;
}

void swap(Vector<T> &naujas)
{
    std::swap(this->_data, naujas._data);
    std::swap(this->_size, naujas._size);
    std::swap(this->_capacity, naujas._capacity);
}

void sort()
{
    std::sort(begin(), end());
}

void assign(size_t count, const T& value) {
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

iterator end() noexcept { return _data + _size; } // tas pats, kas &_data[_size]

const_iterator end() const { return _data + _size; } // tas pats, kas &_data[_size]

const_iterator cend() const noexcept { return _data + _size; } // tas pats, kas &_data[_size]

iterator begin() noexcept { return _data; }

const_iterator begin() const noexcept{ return _data; }

const_iterator cbegin() const noexcept { return _data; }

reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }

const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(end()); }

reverse_iterator rend() noexcept { return reverse_iterator(begin()); }

const_reverse_iterator rend() const noexcept { return const_reverse_iterator(begin()); }

const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(end()); }

const_reverse_iterator crend() const noexcept { return const_reverse_iterator(begin()); }

iterator insert(const_iterator pos, const T& value)
{
    const std::size_t idx = static_cast<std::size_t>(pos - begin());
    if (pos < begin() || pos > end()) {
    throw std::out_of_range("insert position is invalid");
    }
     if (_size == _capacity)
        reserve(_capacity ? _capacity * 2 : 1);

    for(size_t i = _size; i > idx; i--) 
    {
        std::construct_at(&_data[i], std::move(_data[i-1]));
        std::destroy_at(&_data[i-1]);
    }

    std::construct_at(_data + idx, value);
    ++_size;
    return _data + idx; // reikia iteratoriaus
}

iterator insert( const_iterator pos, T&& value )
{
    const std::size_t idx = static_cast<std::size_t>(pos - begin());
    if (pos < begin() || pos > end()) {
    throw std::out_of_range("insert position is invalid");
    }
     if (_size == _capacity)
        reserve(_capacity ? _capacity * 2 : 1);

    for(size_t i = _size; i > idx; i--) 
    {
        std::construct_at(&_data[i], std::move(_data[i-1]));
        std::destroy_at(&_data[i-1]);
    }

    std::construct_at(_data + idx, std::move(value));
    ++_size;
    return _data + idx;
}

T* data() noexcept
{
    return _data; // Pirmo _data elemento adresas
} 

const T* data() const
{
    return _data; // Pirmo _data elemento adresas
} 

template <typename... Args>
iterator emplace(const_iterator pos, Args&&... args)
{
    std::size_t idx = static_cast<std::size_t>(pos - begin());

    if (_size == _capacity)
        reserve(_capacity ? (_capacity * 3) / 2 : 1);

    /* pastumiame elementus vietos užleidimui */
    for (std::size_t i = _size; i-- > idx; ) {
        std::construct_at(_data + i + 1, std::move(_data[i]));
        std::destroy_at  (_data + i);
    }

    /* sukonstruojame elementą vietoje */
    std::construct_at(_data + idx, std::forward<Args>(args)...);

    ++_size;
    return _data + idx;
}

template <typename... Args>
void emplace_back( Args&&... args )
{
    if(_capacity == _size)
         reserve(_capacity ? _capacity * 2 : 1);
    
    std::construct_at(&_data[_size], std::forward<Args>(args)...);

    ++_size;
}

template <typename InputIt>
iterator insert_range(const_iterator pos, InputIt first, InputIt last)
{
    std::size_t idx   = static_cast<std::size_t>(pos - begin());  // fiksuojame dar galiojantį
    std::size_t count = std::distance(first, last);
    if (count == 0) return _data + idx;                           // nieko įterpti

    if (_size + count > _capacity)                                // galimas _data perkėlimas!
        reserve(_capacity ? (_capacity * 3) / 2 : count);         // 1.5×, bent count

    /* 1) pastumiame senus elementus į dešinę (nuo galo, kad nepersirašytų) */
    for (std::size_t i = _size; i-- > idx; ) {
        std::construct_at(_data + i + count, std::move(_data[i]));
        std::destroy_at  (_data + i);
    }

    /* 2) įterpiame naujus */
    for (std::size_t i = 0; i < count; ++i, ++first) {
        std::construct_at(_data + idx + i, *first);
    }

    _size += count;
    return _data + idx;
}

template <typename R>
constexpr void assign_range(R&& rg)
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

allocator_type get_allocator() const
{
    return alloc;
}

template <typename R>
constexpr void append_range(R&& rg)
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

friend bool operator== (const Vector<T>& a, const Vector<T>& b)
{
    if (a._size != b._size) 
        return false;
    for (size_t i = 0; i < a._size; ++i) {
            if (!(a._data[i] == b._data[i])) return false;
        }
        return true;
}

friend bool operator!=(const Vector<T>& a, const Vector<T>& b) {
    return !(a == b);
}

iterator erase(const_iterator pos)
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

iterator erase(const_iterator first, const_iterator last)
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

template <class U>
friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vec);
};

template <class U>
std::ostream& operator<<(std::ostream& os, const Vector<U>& vec)
{
    for (const auto& el : vec) os << el;
    return os;
}
#endif