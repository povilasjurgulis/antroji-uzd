#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector{
    
        size_t size;
        size_t capacity;
        T* data;
        
    public:

        Vector(); // Konstruktorius
        Vector(size_t size);  // Konstruktorius su dydžiu
        Vector(const Vector& other); // Copy konstruktorius
        Vector(Vector&& other) noexcept; // Move konstruktorius
        ~Vector(); // Destruktorius
        Vector& operator=(const Vector& other); // Copy priskyrimo operatorius
        Vector& operator=(Vector&& other) noexcept; // Move priskyrimo operatorius
        T& operator[](size_t index);        // prieiga be tikrinimo
        const T& operator[](size_t index) const;

        T& at(size_t index);                // prieiga su tikrinimu (gal throw)
        const T& at(size_t index) const;
        T& front();                         // pirmas elementas
        T& back();                          // paskutinis elementas
        
        // Dydžio ir talpos funkcijos:
        size_t size() const;                // grąžina dydį
        size_t capacity() const;            // grąžina talpą
        bool empty() const;                 // ar vektorius tuščias
        void reserve(size_t new_capacity);  // padidina talpą (bet nekeičia dydžio)
        void resize(size_t new_size);       // keičia dydį (gali sukurti naujus elementus)

        void push_back(const T& value); // Prideda elementa i vektoriu
        void pop_back(); // Istrina paskutini elementa is vektoriaus
        void clear(); // Istrina visus elementus is vektoriaus
        void shrink_to_fit(); // Pakeicia vektoriaus dydi pagal realiai uzimama atminties dydi
        void swap(Vector& other); // Pakeicia vektoriu vietomis
        void sort(); // Surikiuoja vektoriu
        void reverse(); // Apvercia vektoriu
};

#endif