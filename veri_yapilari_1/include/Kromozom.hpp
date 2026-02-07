//Kromozom.hpp başlangıç

#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP

#include "Gen.hpp"


class Kromozom {
public:
    Gen* bas;
    Gen *son;
    Kromozom* sonraki; // Diğer kromozomları bağlamak için
    Kromozom();
    ~Kromozom();
    void ekle(char veri);
    void yazdir();
    int uzunluk();
    void mutasyon(int genIdx);
    char enKucukGenBulVeYazdir();
    

};

#endif

//Kromozom.hpp bitiş
