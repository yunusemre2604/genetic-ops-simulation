/**
* @file TumIslemler.cpp
* @description Kromozomların tek yönlü bağlı listesini yönetmek için var.
* @course 1. Öğretim C Grubu 
* @assignment 1. Ödev
* @date 16.11.2024
* @author Yunus Emre Yıldız yunus.yildiz25@ogr.sakarya.edu.tr
*/
//TumIslemler.cpp başlangıç

#include "TumIslemler.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
TumIslemler::TumIslemler(const string &dosyaAdi) : ilk(nullptr)
{
    dosyaOku(dosyaAdi);
}

TumIslemler::~TumIslemler()
{
    Kromozom *temp;
    while (ilk)
    {
        temp = ilk;
        ilk = ilk->sonraki;
        delete temp;
    }
}

void TumIslemler::dosyaOku(const string &dosyaAdi)
{
    ifstream dosya(dosyaAdi);
    string satir;
    Kromozom *sonKromozom = nullptr;
    while (getline(dosya, satir)) //dosyadan satır satır okuma yapılır.
    {
        istringstream ss(satir);
        char gen; 
        Kromozom *yeniKromozom = new Kromozom(); //her satır için yeni bir kromozom oluşturulur
        while (ss >> gen)
        {
            yeniKromozom->ekle(gen); //satırdaki kromozomlar karakter karakter(gen gen) okunur.
                                    //Satırdaki her bir karakter(gen) true döndüğü sürece yeni oluşturulan kromozom nesnesine eklenir.
        }
        if (!ilk)   //Eğer ki ilk kromozom yoksa oluşturulan kromozomun adresi ilk değişkenine atanır.
        {
            ilk = yeniKromozom;
            ilk->sonraki=nullptr;
        }   
        else  //Aksi durumda son kromozomun sonraki adresi oluşturulan yeni kromozomun adresini gösterecek şekilde ayarlama yapılır.
        {
            sonKromozom->sonraki = yeniKromozom;
            yeniKromozom->sonraki=nullptr;
        }
        sonKromozom = yeniKromozom; //artık son kromozom eklenen yeni kromozomdur.
        
    }
    
    dosya.close();
}
void TumIslemler::tumunuYazdir() //odevin dogru calisip calismadigini ogrenmek icin kullandim.
{
    int index=0;
    Kromozom *gecici = ilk;
    while (gecici)
    {
        cout << index << " : " ; gecici->yazdir();
        gecici = gecici->sonraki;
        index++;
    }
    
}

void TumIslemler::caprazlama(int idx1, int idx2)
{
    Kromozom *krom1 = ilk;
    Kromozom *krom2 = ilk;

    // idx1 ve idx2 ile belirtilen kromozomları bulma
    for (int i = 0; i < idx1 && krom1 != nullptr; i++)
    {
        krom1 = krom1->sonraki;
    }
    for (int i = 0; i < idx2 && krom2 != nullptr; i++)
    {
        krom2 = krom2->sonraki;
    }
    


    // Kromozomlardan herhangi biri yoksa işlem yapılmaz
    if (!krom1 || !krom2)
        return;
    

    int len1 = krom1->uzunluk();
    int len2 = krom2->uzunluk();

    int orta1 = len1 / 2; // ilk kromozomun orta noktası
    int orta2 = len2 / 2; // ikinci kromozomun orta noktası

    // Yeni kromozomları oluşturma
    Kromozom *yeniKrom1 = new Kromozom(); // ilk yeni kromozom
    Kromozom *yeniKrom2 = new Kromozom(); // ikinci yeni kromozom

    // İlk kromozomun sol kısmı
    Gen *gecici = krom1->bas;
    if (len1 % 2 == 1 || len2 % 2 == 1)
    {
        if (len1 % 2 == 1 && len2 % 2 == 0)
        {
            gecici = krom1->bas;
            for (int i = 0; i < orta1; i++)
            {
                yeniKrom1->ekle(gecici->veri); // 1.kromozomun ortasına kadar genleri ekliyor.
                gecici = gecici->sonraki;
            }
            gecici = krom2->bas;
            for (int i = 0; i < orta2; i++)
            {

                gecici = gecici->sonraki; // 2. kromozomun ortasına kadar geliyor
            }
            for (int i = orta2; i < len2; i++)
            {
                yeniKrom1->ekle(gecici->veri); // 2.kromozomun ortasından sonuna kadar genleri ekliyor.
                gecici = gecici->sonraki;
            }
            gecici = krom2->bas;
            for (int i = 0; i < orta2; i++)
            {
                yeniKrom2->ekle(gecici->veri); // 2. kromozomun ortasına kadar genleri ekliyor.
                gecici = gecici->sonraki;
            }
            gecici = krom1->bas;
            for (int i = 0; i < orta1 + 1; i++)
            {
                gecici = gecici->sonraki; // 1. kromozomun ortasına kadar geliyor.
            }
            for (int i = orta1 + 1; i < len1; i++)
            {
                yeniKrom2->ekle(gecici->veri); // 1. kromozomun ortasından sonuna kadar kromozomları ekliyor.
                gecici = gecici->sonraki;
            }
        }
        else if (len1 % 2 == 0 && len2 % 2 == 1)
        {
            gecici = krom1->bas;
            for (int i = 0; i < orta1; i++)
            {
                yeniKrom1->ekle(gecici->veri); // 1.kromozomun ortasına kadar genleri ekliyor.
                gecici = gecici->sonraki;
            }
            gecici = krom2->bas;
            for (int i = 0; i < orta2+1; i++)
            {

                gecici = gecici->sonraki; // 2. kromozomun ortasına kadar geliyor
            }
            for (int i = orta2+1; i < len2; i++)
            {
                yeniKrom1->ekle(gecici->veri); // 2.kromozomun ortasından sonuna kadar genleri ekliyor.
                gecici = gecici->sonraki;
            }
            gecici = krom2->bas;
            for (int i = 0; i < orta2; i++)
            {
                yeniKrom2->ekle(gecici->veri); // 2. kromozomun ortasına kadar genleri ekliyor.
                gecici = gecici->sonraki;
            }
            gecici = krom1->bas;
            for (int i = 0; i < orta1 ; i++)
            {
                gecici = gecici->sonraki; // 1. kromozomun ortasına kadar geliyor.
            }
            for (int i = orta1 ; i < len1; i++)
            {
                yeniKrom2->ekle(gecici->veri); // 1. kromozomun ortasından sonuna kadar kromozomları ekliyor.
                gecici = gecici->sonraki;
            }
        }
        else if (len1 % 2 == 1 && len2 % 2 == 1)
        {
            gecici = krom1->bas;
            for (int i = 0; i < orta1; i++)
            {
                yeniKrom1->ekle(gecici->veri); // 1.kromozomun ortasına kadar genleri ekliyor.
                gecici = gecici->sonraki;
            }
            gecici = krom2->bas;
            for (int i = 0; i < orta2 + 1; i++)
            {

                gecici = gecici->sonraki; // 2. kromozomun ortasına kadar geliyor
            }
            for (int i = orta2 + 1; i < len2; i++)
            {
                yeniKrom1->ekle(gecici->veri); // 2.kromozomun ortasından sonuna kadar genleri ekliyor.
                gecici = gecici->sonraki;
            }
            gecici = krom2->bas;
            for (int i = 0; i < orta2; i++)
            {
                yeniKrom2->ekle(gecici->veri); // 2. kromozomun ortasına kadar genleri ekliyor.
                gecici = gecici->sonraki;
            }
            gecici = krom1->bas;
            for (int i = 0; i < orta1 + 1; i++)
            {
                gecici = gecici->sonraki; // 1. kromozomun ortasına kadar geliyor.
            }
            for (int i = orta1 + 1; i < len1; i++)
            {
                yeniKrom2->ekle(gecici->veri); // 1. kromozomun ortasından sonuna kadar kromozomları ekliyor.
                gecici = gecici->sonraki;
            }
        }
    }
    else
    {
        for (int i = 0; i < orta1; i++)
        {
            yeniKrom1->ekle(gecici->veri); // 1.kromozomun ortasına kadar genleri ekliyor.
            gecici = gecici->sonraki;
        }

        // İkinci kromozomun sağ kısmı
        gecici = krom2->bas;
        for (int i = 0; i < orta2; i++)
        {

            gecici = gecici->sonraki; // 2. kromozomun ortasına kadar geliyor
        }
        for (int i = orta2; i < len2; i++)
        {
            yeniKrom1->ekle(gecici->veri); // 2.kromozomun ortasından sonuna kadar genleri ekliyor.
            gecici = gecici->sonraki;
        }

        // İkinci kromozomun sol kısmı
        gecici = krom2->bas;
        for (int i = 0; i < orta2; i++)
        {
            yeniKrom2->ekle(gecici->veri); // 2. kromozomun ortasına kadar genleri ekliyor.
            gecici = gecici->sonraki;
        }

        // İlk kromozomun sağ kısmı
        gecici = krom1->bas;
        for (int i = 0; i < orta1; i++)
        {
            gecici = gecici->sonraki; // 1. kromozomun ortasına kadar geliyor.
        }
        for (int i = orta1; i < len1; i++)
        {
            yeniKrom2->ekle(gecici->veri); // 1. kromozomun ortasından sonuna kadar kromozomları ekliyor.
            gecici = gecici->sonraki;
        }
    }

    // Yeni kromozomları mevcut popülasyona ekleme
    Kromozom *sonKromozom = ilk;
    while (sonKromozom->sonraki)
    {
        sonKromozom = sonKromozom->sonraki;
    }
    sonKromozom->sonraki = yeniKrom1; // yeniKrom1'i ekle
    yeniKrom1->sonraki = yeniKrom2;   // yeniKrom2'yi ekle
    yeniKrom2->sonraki=nullptr;
    
    
}

void TumIslemler::dosyaGuncelle(const string &dosyaAdi) //ödevin dogru calisip calismadıgini kontrol etmek icin kullandim
{
    ofstream dosya(dosyaAdi);
    Kromozom *gecici = ilk;
    while (gecici)
    {
        Gen *gen = gecici->bas;
        while (gen)
        {
            dosya << gen->veri << " ";
            gen = gen->sonraki;
        }
        dosya << endl;
        gecici = gecici->sonraki;
    }
    
    dosya.close();
}
void TumIslemler::mutasyon(int idx, int genIdx) {
    Kromozom* gecici = ilk;
    for (int i = 0; i < idx && gecici != nullptr; i++) {
        gecici = gecici->sonraki;
    }
    
    
    if (gecici) {
         
        gecici->mutasyon(genIdx);
    }
    
    
}
void TumIslemler::otomatikIslemler(const string& dosyaAdi) {
    ifstream dosya(dosyaAdi);
    string satir;
    
    while (getline(dosya, satir)) {
        istringstream ss(satir);
        char islem;
        int idx1, idx2;
        
        ss >> islem >> idx1 >> idx2; // Dosyadan işlemi ve indeksleri al
        
        if (islem == 'C') {  // Çaprazlama işlemi
            caprazlama(idx1, idx2);  // Çaprazlama işlemini uygula
        } else if (islem == 'M') {  // Mutasyon işlemi
            mutasyon(idx1, idx2);  // Mutasyon işlemini uygula
        }
        
    }
    dosya.close();
    
    
    cout << "Islem tamamlandi" <<endl <<endl; 
}

void TumIslemler::enKucukGenYazdir2(){
    Kromozom *gecici = ilk;
    int index = 0;
    while(gecici){
        cout<<gecici->enKucukGenBulVeYazdir() <<" ";
        gecici=gecici->sonraki;
        index++;
    } cout <<endl;
    
    
}



//TumIslemler.cpp bitiş