/**
* @file 			ödev_2
* @description 		Dosyadan okudugu sayilari 2 listeye atıp bu sayilari karsilastirarak yon veya dugum degistiren program
* @course 			1. Ogretim B grubu
* @assignment		2.Odev
* @date 			04.08.2021
* @author 			Alper Çelik alper.celik@ogr.sakarya.edu.tr g191210016
*/
#include <iostream>
#include "library.hpp"
#include <stdlib.h>
#include <fstream>
#include <cstddef>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    //File* TextFile = new File();

    //TextFile->readFile();
    
    system("pause");

    AVLTree *tree = new AVLTree();

    person *kisi = new person("Lebron", 36, 206);
    person *kisi1 = new person("Curry ", 33, 190);
    /*person *kisi2 = new person("Joel", 27,213);
    person *kisi3 = new person("Durant", 32, 208);
    person *kisi4 = new person("Griffin", 32, 207);
    person *kisi5 = new person("Thomas", 32, 175);
    person *kisi6 = new person("Spud", 58, 168);
    person *kisi7 = new person("Zion", 21, 201);
    person *kisi8 = new person("Young", 22, 185);
    tree->Ekle(kisi);
    tree->Ekle(kisi1);
    tree->Ekle(kisi2);
    tree->Ekle(kisi3);
    tree->Ekle(kisi4);
    tree->Ekle(kisi5);
    tree->Ekle(kisi6);
    tree->Ekle(kisi7);*/
    tree->Ekle(kisi);
    tree->Ekle(kisi1);

    tree->Levelorder();
    return 0;
    
}