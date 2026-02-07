//TumIslemler.hpp başlangıç

#ifndef TumIslemler_HPP
#define TumIslemler_HPP

#include "Kromozom.hpp"
#include <string>
using namespace std;
class TumIslemler {
private:
    Kromozom* ilk; // İlk kromozomun başlangıç noktası
    void dosyaOku(const string& dosyaAdi);
public:
    TumIslemler(const string& dosyaAdi);
    ~TumIslemler();
    void tumunuYazdir();
    void caprazlama(int idx1, int idx2);
    void dosyaGuncelle(const string& dosyaAdi);
    void mutasyon(int idx, int genIdx);
    void otomatikIslemler(const string& dosyaAdi);
    
    void enKucukGenYazdir2();
};

#endif
//TumIslemler.hpp bitiş