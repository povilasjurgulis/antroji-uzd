#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector{
    
        size_t size;
        size_t capacity;
        T* data;
        
    public:

        Vector(); // Konstruktorius
        Vector(size_t dydis);  // Konstruktorius su dydžiu
        Vector(const Vector& naujas); // Copy konstruktorius
        Vector(Vector&& naujas) noexcept; // Move konstruktorius
        ~Vector(); // Destruktorius
        Vector& operator=(const Vector& naujas); // Copy priskyrimo operatorius
        Vector& operator=(Vector&& naujas) noexcept; // Move priskyrimo operatorius
        T& operator[](size_t index);        // prieiga be tikrinimo
        const T& operator[](size_t index) const;

        T& at(size_t indeksas);                // prieiga su tikrinimu
        const T& at(size_t indeksas) const;
        T& front();                         // pirmas elementas
        const T& front() const;
        T& back();                          // paskutinis elementas
        const T& back() const;
        
        size_t max_size() const;
        size_t size() const;                // grąžina dydį
        size_t capacity() const;            // grąžina talpą
        bool empty() const;                 // ar vektorius tuščias
        void reserve(size_t new_capacity);  // padidina talpą (bet nekeičia dydžio)
        void sort(); // Surikiuoja vektoriu 
        void swap(Vector& naujas); // Pakeicia vektoriu vietomis
        void resize(size_t new_size);       // keičia dydį (gali sukurti naujus elementus)
        void push_back(const T& new_value); // Prideda elementa i vektoriu
        void push_back(T&& new_value); // Prideda elementa i vektoriu su std::move
        void pop_back(); // Istrina paskutini elementa is vektoriaus
        void clear(); // Istrina visus elementus is vektoriaus
        void shrink_to_fit() // Pakeicia vektoriaus dydi pagal realiai uzimama atminties dydi
        // Kokios dar yra std::vector funkcijos, kurias reikia implementuoti? Atsakymas: 
        // std::vector::assign, std::vector::insert, std::vector::erase, std::vector::emplace, std::vector::emplace_back
        // std::vector::emplace_front

};

#endif