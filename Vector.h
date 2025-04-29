#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector{
    private:
        int size;
        T* data;
    public:
        Vector(int size = 0); // Konstruktorius
        Vector(const Vector& other); // Copy konstruktorius
        Vector(Vector&& other) noexcept; // Move konstruktorius
        ~Vector(); // Destruktorius
        Vector& operator=(const Vector& other); // Copy priskyrimo operatorius
        Vector& operator=(Vector&& other) noexcept; // Move priskyrimo operatorius
        int& operator[](int index); // Operatorius [] (priskyrimas)
        const int& operator[](int index) const; // Operatorius [] (skaitymas)
        int GetSize() const; // Grazina vektoriaus dydi
        void SetSize(int size); // Nustato vektoriaus dydi

        void PushBack(const T& value); // Prideda elementa i vektoriu
        void PopBack(); // Istrina paskutini elementa is vektoriaus
        void Clear(); // Istrina visus elementus is vektoriaus
        void Resize(int newSize); // Pakeicia vektoriaus dydi
        void ShrinkToFit(); // Pakeicia vektoriaus dydi pagal realiai uzimama atminties dydi
        void Reserve(int newCapacity); // Rezervuoja atminties vieta vektoriui
        void Swap(Vector& other); // Pakeicia vektoriu vietomis
        void Sort(); // Surikiuoja vektoriu
        void Reverse(); // Apvercia vektoriu
};

#endif