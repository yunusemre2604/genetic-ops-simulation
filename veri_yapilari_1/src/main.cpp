/**
* @file main.cpp
* @description main dosyası 
* @course 1. Öğretim C Grubu 
* @assignment 1. Ödev
* @date 16.11.2024
* @author Yunus Emre Yıldız yunus.yildiz25@ogr.sakarya.edu.tr
*/
//main.cpp başlangıç
#include "TumIslemler.hpp"
#include <iostream>

#include <locale>
using namespace std;
int main() {
     setlocale(LC_ALL, "Turkish"); // Türkçe karakter desteği
    TumIslemler dna("Dna.txt");
    
    
    int secim;
    do {
        cout << "1 - Caprazlama\n2 - Mutasyon \n3 - Otomatik Islemler\n4 - Ekrana Yaz \n5 - Cikis\n";
        cout << "Seciminiz: ";
        cin >> secim;
        if (secim == 1) {
            int idx1, idx2;
            
            cout << "ilk kromozom satir numarasini girin: ";
            cin >> idx1;
            cout << "ikinci kromozom satir numarasini girin: ";
            cin >> idx2;
            dna.caprazlama(idx1, idx2);
            
            
        } else if (secim == 2) {
            int kroidx, genidx;
            
            cout << "Mutasyon gecirilecek kromozom satir numarasini giriniz: ";
            cin >> kroidx;
            cout << "Mutasyon gecirilecek gen indisini giriniz: "; 
            cin >> genidx;
            dna.mutasyon(kroidx, genidx);
            
            

        }else if (secim == 3) {
            string dosyaAdi = "Islemler.txt";
            dna.otomatikIslemler(dosyaAdi);  // Otomatik işlemleri çalıştır
            
            
            
        }else if (secim == 4) {
            dna.enKucukGenYazdir2();
            
        }
        
        
        
    } while (secim != 5);
    
    
    return 0;
}

//main.cpp bitiş
