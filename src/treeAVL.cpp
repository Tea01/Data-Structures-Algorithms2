/**
* @file                         B191210555
* @description                  .txt dosyadan verileri okuyup, ilk olarak iki nokta arasındaki uzaklığını bulup sonra her satır için noktalar arasındaki toplam uzaklığını bulup kuyruğa tutuyoruz. Sonra her noktanın orijinden uzaklığını bulup kuyrukta bağlı liste kullanarak tutuyoruz. Sonra toplam uzaklığını kullanarak her satırı AVL ağaçta post order kullanarak düzenliyoruz ve ekrana ağaçtan, orijinden uzaklığını çıkartıyoruz. 
* @course                       1. Öğretim C Grubu
* @assignment                   2. Ödev
* @date                         26/12/2021
* @author                       Tea Shkurti | E-posta: tea.shkurti@ogr.sakarya.edu.tr
*/

#include "treeAVL.hpp"
#include "DogruKuyruk.hpp"
#include "DugumTree.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

//ağaçın kurucu fonksiyonu
treeAVL::treeAVL()                               
{
    root= 0;
}

//ağaçın yıkıcı fonksiyonu
treeAVL::~treeAVL()                             
{
  RemoveSubTree(root);                           
}
//ağaçta girip tüm düğümeleri siliyor
void treeAVL::RemoveSubTree(DugumTree* root)         
{
    if (root!=NULL)
    {
        if(root->left!=NULL)
        {
            RemoveSubTree(root->left);
        }
        if(root->right=NULL)
        {
            RemoveSubTree(root->right);
        }
        delete root;
    }
}

//ağaçta kuyruk ekliyor
void treeAVL::ekle(DogruKuyruk* kuyruk)
{
    root = ekle(kuyruk,root);
}
//ağacın düğümünde kuyruk hangi düğüm için çağırıldığı eklemektedir
DugumTree* treeAVL::ekle(DogruKuyruk* kuyruk, DugumTree* aktifDugum) 
{
    if(aktifDugum==0)
        return new DugumTree(kuyruk);

	else if(aktifDugum->kuyruk->mesafe <= kuyruk->mesafe)
    {
        aktifDugum->right=ekle(kuyruk,aktifDugum->right);

        if(yukseklik(aktifDugum->right)-yukseklik(aktifDugum->left)>1)
        {   
            if(kuyruk->mesafe>aktifDugum->right->kuyruk->mesafe)
                aktifDugum = solaDondur(aktifDugum);                
            else
            {
                aktifDugum->right = sagaDondur(aktifDugum->right);
                aktifDugum =solaDondur(aktifDugum);
            }
        }
    }
    else if(aktifDugum->kuyruk->mesafe > kuyruk->mesafe)
    {
        aktifDugum->left = ekle(kuyruk,aktifDugum->left);

        if(yukseklik(aktifDugum->left)-yukseklik(aktifDugum->right)>1)
        {
            if(kuyruk->mesafe<aktifDugum->left->kuyruk->mesafe)
                aktifDugum = sagaDondur(aktifDugum);
            else
            {
                aktifDugum->left = solaDondur(aktifDugum->left);
                aktifDugum =sagaDondur(aktifDugum);
            }
        }
    }
    return aktifDugum;
}

//ağaçın yüksekliği hesaplanmaktadır
int treeAVL::yukseklik() 
{
	return yukseklik(root);
}
//ağaçın yüksekliği hesaplanmaktadır
int treeAVL::yukseklik(DugumTree* aktifDugum) 
{
	if(aktifDugum)
    {
        return 1+max(yukseklik(aktifDugum->left), yukseklik(aktifDugum->right));
    }
    return -1;
}

//post order dolaşımını yapıyor
void treeAVL::postOrder() 
{
	postOrder(root);
}
//post order dolaşımını yapıyor
void treeAVL::postOrder(DugumTree* aktif) 
{
	if(aktif)
    {
        postOrder(aktif->left);
        postOrder(aktif->right);
        cout<<*aktif->kuyruk<<" ";
    }	
}

//eğer sağa tarafında bozulma varsa solaDondur fonsksiyonu çağrıyoruz
DugumTree* treeAVL::solaDondur(DugumTree* buyukEbeveyn) 
{
	DugumTree* sagCocuk = buyukEbeveyn->right;
    buyukEbeveyn->right = sagCocuk->left;
    sagCocuk->left = buyukEbeveyn;
    return sagCocuk;
}

//eğer sol tarafında bozulma varsa sagaDondur fonsksiyonu çağrıyoruz
DugumTree* treeAVL::sagaDondur(DugumTree* buyukEbeveyn) 
{
	DugumTree* solCocuk = buyukEbeveyn->left;
    buyukEbeveyn->left = solCocuk->right;
    solCocuk->right = buyukEbeveyn;
    return solCocuk;
}