/**
* @file                         B191210555
* @description                  .txt dosyadan verileri okuyup, ilk olarak iki nokta arasındaki uzaklığını bulup sonra her satır için noktalar arasındaki toplam uzaklığını bulup kuyruğa tutuyoruz. Sonra her noktanın orijinden uzaklığını bulup kuyrukta bağlı liste kullanarak tutuyoruz. Sonra toplam uzaklığını kullanarak her satırı AVL ağaçta post order kullanarak düzenliyoruz ve ekrana ağaçtan, orijinden uzaklığını çıkartıyoruz. 
* @course                       1. Öğretim C Grubu
* @assignment                   2. Ödev
* @date                         26/12/2021
* @author                       Tea Shkurti | E-posta: tea.shkurti@ogr.sakarya.edu.tr
*/

#include "Dugum.hpp"

Dugum::Dugum(int veri)
{
    this->veri = veri;
    sonraki=0;                //düğüm kimseyi göstermiyor. pointer=0
}