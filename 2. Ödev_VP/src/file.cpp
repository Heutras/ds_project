/*
*
* @file 			File.cpp
* @description 		Program, önceden hazırlanmış veri.txt dosyasını okuyup, okunan sayılarla AVL ağaçları oluşturarak listeler üzerinde istenilen işlemleri yapar ve AVL ağaçlarının son halini ekranana yazdırır.
* @course 			Veri Yapıları 2.Öğretim C Grubu
* @assignment		Veri Yapıları 2.Ödev
* @date 			22 ‎Aralık ‎2020 ‎Salı, ‏‎19:54:20
* @author 			Emirhan Şensoy - emirhan.sensoy@ogr.sakarya.edu.tr
*
*/

#include "File.hpp"
#include "library.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

void File::readFile()
{
    AVLTree *tree = new AVLTree();
    char Separator = '#'; // okunacak sayıyı bölecek ayraç tanımlandı.
    string Content; 
    string Temp;
	ifstream file("Kisiler.txt");

    if (!file) // dosya bulunamadıysa ekrana yazdıran fonksiyon.
    {
        cout << "Dosya Bulunamadi !!";
    }
	if (file.is_open())
    {
		int n = 0;
		
		while (getline(file, Content))
		{
			person *cur_person = new person();

			string Separator = "#";

			size_t position = 0;
			
			while ((position = Content.find(Separator)) != string::npos)
			{
				Temp = Content.substr(0, position);
				if (n == 0)
				{
					cur_person->name = Temp;
					//BURADA ISIMLE ILE ILIGLI ISLEMLER
					n++;
					//cout << cur_person->name << "\t";									
				}
				else
				{
					cur_person->age = stoi(Temp);
					//BURADA YAŞ İLE İLGİLİ İŞLEMLER
					n=0;
     				//cout << cur_person->age << "\t";
				}
				Content.erase(0, position + Separator.length());
			}
			cur_person->height = stoi(Content);
			//cout <<cur_person->name << "\t" << cur_person->age << "\t" << cur_person->height << endl;
			//cout << " basarili bir sekilde kisiyi okudun kardesim"<<endl;
			//tree->Ekle(cur_person);
			//tree->Levelorder();
			//cout << endl;
		}
	}
	//tree->Levelorder();

	file.close();
}
