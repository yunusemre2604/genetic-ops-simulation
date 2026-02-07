/**
* @file Kromozom.cpp
* @description Genlerin oluşturduğu kromozomlar için oluşturuldu.Kromozomların tek yönlü bağlı listede tutulması için oluşturuldu.
* @course 1. Öğretim C Grubu 
* @assignment 1. Ödev
* @date 16.11.2024
* @author Yunus Emre Yıldız yunus.yildiz25@ogr.sakarya.edu.tr
*/
//Kromozom.cpp başlangıç

#include "Kromozom.hpp"
#include <iostream>

using namespace std;
Kromozom::Kromozom() : bas(nullptr), son(nullptr),sonraki(nullptr) {}

Kromozom::~Kromozom() {
    Gen* temp;
    while (bas) {
        temp = bas;
        bas = bas->sonraki;
        delete temp;
    }
}

void Kromozom::ekle(char veri) {
    Gen* yeniGen = new Gen(veri); // Yeni düğüm oluştur

    if (!bas) { // Liste boşsa
        bas = yeniGen; // Yeni düğüm baş olur
        bas->onceki=nullptr;
        son = yeniGen; // Yeni düğüm aynı zamanda son olur
        son->sonraki=nullptr;
    } else {
        son->sonraki = yeniGen;  // Eski son düğümün sonraki işaretçisi yeni düğümü gösterir
        yeniGen->onceki = son;   // Yeni düğümün önceki işaretçisi eski sona işaret eder
        yeniGen->sonraki=nullptr;
        son = yeniGen;           // Yeni düğüm artık son düğüm olur
    }
}

void Kromozom::yazdir() { //ödevin dogru calisip calismadıgini kontrol etmek icin kullandim
    Gen* gecici = bas;
    while (gecici) {
        cout << gecici->veri << " ";
        gecici = gecici->sonraki;
    }
    cout << endl;
    
}

int Kromozom::uzunluk() {
    int uzunluk = 0;
    Gen* gecici = bas;
    while (gecici) {
        uzunluk++;
        gecici = gecici->sonraki;
    }
    return uzunluk;
    
}
void Kromozom::mutasyon(int genIdx) {
    Gen* gecici = bas;
    int index = 0;
    while (gecici) {
        if (index == genIdx) {
            gecici->veri = 'X';  // Mutasyon işlemi
            return;
        }
        gecici = gecici->sonraki;
        index++;
    }
    
}
char Kromozom::enKucukGenBulVeYazdir() {
    if (!bas) return '0'; // Boş kromozom kontrolü

    // İlk geni başlangıç olarak kabul edelim
    char enKucukGen = bas->veri;

    // Sağdan sola doğru tarama için önce listeyi sona kadar ilerletiyoruz
    Gen* gecici = son;
    
    // Sağdan sola doğru geri tarama
    while (gecici) {
        if (gecici->veri < enKucukGen) {
            enKucukGen = gecici->veri;
        }
        gecici = gecici->onceki; // 'onceki' işaretçisiyle geriye gitme (liste çift yönlü olmalı)
        
    }
    return enKucukGen;
    
    

    
}

//Kromozom.cpp bitiş
