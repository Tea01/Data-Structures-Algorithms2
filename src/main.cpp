
#include <iostream>
#include <string>
#include <fstream>                                               //dosyalama yapabilmek için kütüphanesi
#include <sstream>                                               // istringstream kullanmak için
#include <math.h>                                                // aritmetik işlemler yapmak için
#include "DogruKuyruk.hpp"
#include "Dugum.hpp"
#include "treeAVL.hpp"
#include "DugumTree.hpp"

using namespace std;

int main()
{      
    ifstream dosyadanOku("./doc/Noktalar.txt");                           //Noktalar dosyayı açar

    treeAVL* tree=new treeAVL();

	string satir="";

    if(dosyadanOku.is_open())                                       //Eğer dosya açıksa koşullu sağlıyor
    {
        while (getline(dosyadanOku, satir))                   		//dosyadan satır satır verileri okuyor	  
	    {        
            istringstream my_stream(satir);                         //boşluk görünceye kadar tüm verileri alır

            int x1,y1,z1;
            int x2,y2,z2;

            int originDistance=0;
            int pointsDistance =0;
 
            DogruKuyruk* kuyruk=new DogruKuyruk();      
            
            my_stream>>x1>>y1>>z1;                                                    //aynı anda 3 sayılar alıp x1 y1 ve z1 değişkenlere atıyor

            originDistance= sqrt(pow(x1,2)+pow(y1,2)+pow(z1,2));                      //x1,y1,z1 noktaların orijinden uzaklığını buluyor
 
            kuyruk->ekle(originDistance);                                             //bulunan uzaklığı kuyrukta eklenir;

            while(my_stream>>x2>>y2>>z2)                                              //ikinci noktanın x2 y2 ve z2 değerleri alır
            {   
                originDistance= sqrt(pow(x2,2)+pow(y2,2)+pow(z2,2));                  //ikinci nokta için orijinden uzaklığını bulur

                kuyruk->ekle(originDistance);                                         //bulunan uzaklığı kuyrukta eklenir;
                
                pointsDistance = sqrt(pow((x2-x1),2)+pow((y2-y1),2)+pow((z2-z1),2));  //iki nokta arasındaki uzaklığını bulunur

                kuyruk->mesafe +=pointsDistance;                                      //noktalar arasındaki mesafeyi kuyrukta atanır (int mesafe)
                
                x1=x2;                                                        
                y1=y2;
                z1=z2;    
            }  

            tree->ekle(kuyruk);                                                      //ağaçta kuyruğu atanır

	    }//satir bitti
        
   }//dosya okuma bitti
    cout<<endl;
    tree->postOrder();                            //postorder fonksiyonu çağrıyor ve ondan sonra ekrana yazdırıyor
    delete tree;                                  // ağaçın yıkıcı fonksiyonu çağrıyor ve ağaçı silenir

	if (!dosyadanOku.is_open())                             //Eğer dosya açık değilse fonksiyonu
	{
		cout << "Dosya açılamadı!" << endl;
		exit(-1);
	}
  
	dosyadanOku.close();                               //Dosyayı kapatılıyor
}
