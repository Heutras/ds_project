/**
* @file 			g191210016
* @description 		Dosyadan okudugu sayilari 2 listeye atıp bu sayilari karsilastirarak yon veya dugum degistiren program
* @course 			1. Ogretim B grubu
* @assignment		1.Odev
* @date 			04.08.2021
* @author 			Alper Çelik alper.celik@ogr.sakarya.edu.tr
*/

#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <string>
#include "person.hpp"
#include "stack.hpp"

class Node{
	public:
        person* Person;
		Node* left;
		Node* right;
        Stack* height;
        Stack* depth;
        Node(person*, Node*, Node*, Stack*, Stack*);
        Node();
};

#endif