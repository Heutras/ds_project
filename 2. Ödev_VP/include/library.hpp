/**
* @file 			g191210016
* @description 		Dosyadan okudugu sayilari 2 listeye atıp bu sayilari karsilastirarak yon veya dugum degistiren program
* @course 			1. Ogretim B grubu
* @assignment		1.Odev
* @date 			04.08.2021
* @author 			Alper Çelik alper.celik@ogr.sakarya.edu.tr
*/

#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include <iostream>
#include <string>
#include "node.hpp"
#include "file.hpp"

class AVLTree
{
private:
	Node *root;
	Node *AraveEkle(Node*, person*);
	Node *rightRotate(Node*); // Sağa dönüş
	Node *leftRotate(Node*); // lefta dönüş
	void Inorder(Node*);
	void Preorder(Node*);
	void Postorder(Node*);
	void SeviyeyiYazdir(Node*,int);
	int Yukseklik(Node*);
	bool DugumSil(Node*&);
	bool Ara(Node*,const int&);

public:

	AVLTree();
	bool Bosmu();
	void Ekle(person*);
	void Inorder();
	void Preorder();
	void Postorder();
	void Levelorder();
	bool Arama(const int&);
	void Temizle();
	int Yukseklik();
	~AVLTree();
};


#endif