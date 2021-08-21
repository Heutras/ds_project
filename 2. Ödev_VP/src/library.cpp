/**
* @file 			g191210016
* @description 		Dosyadan okudugu sayilari 2 listeye atıp bu sayilari karsilastirarak yon veya dugum degistiren program
* @course 			1. Ogretim B grubu
* @assignment		1.Odev
* @date 			04.08.2021
* @author 			Alper Çelik alper.celik@ogr.sakarya.edu.tr
*/
#include "library.hpp"
#include <iostream>
#include <string>

using namespace std;

Node* AVLTree::AraveEkle(Node *alt_Dugum, person* new_person)
{
    // alt_Dugum = z, alt_Dugum->left = y, yeni = x,w
    if (alt_Dugum == NULL)
    {
        alt_Dugum = new Node(new_person, NULL, NULL, NULL, NULL);

        return alt_Dugum;
    }
    else if (new_person->height <= alt_Dugum->Person->height)
    {
        alt_Dugum->left = AraveEkle(alt_Dugum->left, new_person);

        if (Yukseklik(alt_Dugum->left) - Yukseklik(alt_Dugum->right) == 2)
        {
            if (new_person->height < alt_Dugum->left->Person->height) // sol sol
            {
                alt_Dugum = rightRotate(alt_Dugum);
            }
            else // sol sag
            {
                alt_Dugum->left = leftRotate(alt_Dugum->left);
                alt_Dugum = rightRotate(alt_Dugum);
            }
            
        }
        else if (new_person->height < alt_Dugum->Person->height)
        {
            alt_Dugum->right = AraveEkle(alt_Dugum->right, new_person);
            if (Yukseklik(alt_Dugum->right) - Yukseklik(alt_Dugum->left) == 2)
            {
                if (new_person->height >= alt_Dugum->right->Person->height) // sag sag
                {
                    alt_Dugum = leftRotate(alt_Dugum);
                }
                else // sag sol
                {
                    alt_Dugum->right = rightRotate(alt_Dugum->right);
                    alt_Dugum = leftRotate(alt_Dugum);
                }
            }
            
        }
        alt_Dugum->height->push(Yukseklik(alt_Dugum));

        return alt_Dugum;
    }
    
    /*else if (new_person->height < alt_Dugum->Person->height) // y, z'nin left çocuğu ise
    {
        alt_Dugum->left = AraveEkle(alt_Dugum->left, new_person);

        if (Yukseklik(alt_Dugum->left) - Yukseklik(alt_Dugum->right) == 2)
        {
            // left left Durumu
            if (new_person->height < alt_Dugum->left->Person->height) // x, y'nin left çocuğu ise
                alt_Dugum = rightRotate(alt_Dugum); //sağa dönüş z
            else // left Sağ Durumu
            {														  
                alt_Dugum->left = leftRotate(alt_Dugum->left); // lefta dönüş y
                alt_Dugum = rightRotate(alt_Dugum); // sağa dönüş z
            }
        }
    }
    else if (new_person->height > alt_Dugum->Person->height)
    {
        alt_Dugum->right = AraveEkle(alt_Dugum->right, new_person);

        if (Yukseklik(alt_Dugum->right) - Yukseklik(alt_Dugum->left) == 2)
        {
            // Sağ Sağ Durumu
            if (new_person->height > alt_Dugum->right->Person->height)
                alt_Dugum = leftRotate(alt_Dugum);
            else
            { // Sağ left Durumu
                alt_Dugum->right = rightRotate(alt_Dugum->right);
                alt_Dugum = leftRotate(alt_Dugum);
            }
        }
    }
    else
        ; // Aynı eleman var.
*/
    //Yüksekliği güncelle
    alt_Dugum->height->push(Yukseklik(alt_Dugum));
    return alt_Dugum;   
}

Node* AVLTree::rightRotate(Node *alt_Dugum)
{
    //swap
    Node *tmp = alt_Dugum->left;
    alt_Dugum->left = tmp->right;
    tmp->right = alt_Dugum;

    // Yükseklikleri Güncelle
    alt_Dugum->height->push(Yukseklik(alt_Dugum));
    //alt_Dugum->height->head->data = Yukseklik(alt_Dugum);
    tmp->height->push(max(Yukseklik(tmp->left), alt_Dugum->height->head->data) + 1);
    //tmp->height->head->data = max(Yukseklik(tmp->left), alt_Dugum->height->head->data) + 1; // Bir düğümün yüksekliği en yüksek çocuğunun bir fazlasıdır

    return tmp;    
}

Node* AVLTree::leftRotate(Node *alt_Dugum)
{
    //swap
    Node *tmp = alt_Dugum->right;
    alt_Dugum->right = tmp->left;
    tmp->left = alt_Dugum;

    // Yükseklikleri Güncelle
    alt_Dugum->height->push(Yukseklik(alt_Dugum));
    //alt_Dugum->height->head->data = Yukseklik(alt_Dugum);
    tmp->height->push(max(Yukseklik(tmp->right), alt_Dugum->height->head->data) + 1);
    //tmp->height->head->data = max(Yukseklik(tmp->right), alt_Dugum->height->head->data) + 1;

    return tmp;
}

void AVLTree::Inorder(Node *alt_Dugum)
{
    if (alt_Dugum != NULL)
    {
        Inorder(alt_Dugum->left);
        cout << alt_Dugum->Person->height << " ";
        Inorder(alt_Dugum->right);
    }    
}

void AVLTree::Preorder(Node *alt_Dugum)
{
    if (alt_Dugum != NULL)
    {
        cout << alt_Dugum->Person->height << " ";
        Preorder(alt_Dugum->left);
        Preorder(alt_Dugum->right);
    }
}

void AVLTree::Postorder(Node *alt_Dugum)
{
    if (alt_Dugum != NULL)
    {
        Postorder(alt_Dugum->left);
        Postorder(alt_Dugum->right);
        cout << alt_Dugum->Person->height << " "<<alt_Dugum->height << "\t" <<alt_Dugum->depth;
    }
}

void AVLTree::SeviyeyiYazdir(Node *alt_Dugum, int seviye)
{
    if (alt_Dugum == NULL)
        return;
    if (seviye == 0)
        cout << alt_Dugum->Person->name << " " << alt_Dugum->Person->age << " " << alt_Dugum->Person->height;
    else
    {
        SeviyeyiYazdir(alt_Dugum->left, seviye - 1);
        SeviyeyiYazdir(alt_Dugum->right, seviye - 1);
    }
}

int AVLTree::Yukseklik(Node *alt_Dugum)
{
    if (alt_Dugum == NULL)
        return -1; // Ortada düğüm yoksa yükseklik anlamsızdır. Kodun çalışması adına -1 verilmektedir.
    return 1 + max(Yukseklik(alt_Dugum->left), Yukseklik(alt_Dugum->right));
}

bool AVLTree::DugumSil(Node *&alt_Dugum)
{
    Node *silinecekDugum = alt_Dugum;

    if (alt_Dugum->right == NULL)
        alt_Dugum = alt_Dugum->left;
    else if (alt_Dugum->left == NULL)
        alt_Dugum = alt_Dugum->right;
    else
    {
        silinecekDugum = alt_Dugum->left;
        Node *ebeveynDugum = alt_Dugum;
        while (silinecekDugum->right != NULL)
        {
            ebeveynDugum = silinecekDugum;
            silinecekDugum = silinecekDugum->right;
        }
        alt_Dugum->Person->height = silinecekDugum->Person->height;
        if (ebeveynDugum == alt_Dugum)
            alt_Dugum->left = silinecekDugum->left;
        else
            ebeveynDugum->right = silinecekDugum->left;
    }
    delete silinecekDugum;
    return true;
}

bool AVLTree::Ara(Node *alt_Dugum, const int &aranan)
{
    if (alt_Dugum == NULL)
        return false;
    if (alt_Dugum->Person->height == aranan)
        return true;
    if (aranan < alt_Dugum->Person->height)
        return Ara(alt_Dugum->left, aranan);
    if (aranan > alt_Dugum->Person->height)
        return Ara(alt_Dugum->right, aranan);
}

AVLTree::AVLTree()
{
    root = NULL;
}

bool AVLTree::Bosmu()
{
    return root == NULL;
}

void AVLTree::Ekle(person* new_person)
{
    root = AraveEkle(root, new_person);
}

void AVLTree::Inorder()
{
    Inorder(root);
}

void AVLTree::Preorder()
{
    Preorder(root);
}

void AVLTree::Postorder()
{
    Postorder(root);
}

void AVLTree::Levelorder()
{
    int h = Yukseklik();
    for (int level = 0; level <= h; level++)
        SeviyeyiYazdir(root, level);
}

bool AVLTree::Arama(const int &aranan)
{
    return Ara(root, aranan);
}

void AVLTree::Temizle()
{
    while (!Bosmu())
        DugumSil(root);
}

int AVLTree::Yukseklik()
{
    return Yukseklik(root);
}

AVLTree::~AVLTree()
{
    Temizle();
}
