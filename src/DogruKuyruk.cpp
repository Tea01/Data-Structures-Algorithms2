
#include "DogruKuyruk.hpp"
#include <exception>

using namespace std;

DogruKuyruk::DogruKuyruk()                                   //Kuyruğun kurucu fonksiyonu
{
	ilk=son=0;
}
DogruKuyruk::~DogruKuyruk()                                  //Kuyruğun yıkıcı fonksiyonu
{
	while(ilk!=0)
	{
		Dugum* gec= ilk;
		ilk=ilk->sonraki;
		delete gec;
	}
}
void DogruKuyruk::ekle(int veri)                            //kuyrukta veriler ekliyor
{
	if(ilk==0)
	{
		ilk=new Dugum(veri);
		son= ilk;
	}
	else
	{
		Dugum* yeni = new Dugum(veri);
		son->sonraki=yeni;
		son=yeni;
	}
}
Dugum* DogruKuyruk:: enKucukOncekiDugum()                  //Listede en küçük önceki düğümeyi dödürüyor
{
	if(ilk==0)	return 0;

	Dugum* gec = ilk;
	Dugum* onceki=0;
	int enKucuk = gec->veri;
		
	while(gec->sonraki!=0)
	{
		if(gec->sonraki->veri < enKucuk)
		{
			enKucuk = gec->sonraki->veri;
			onceki = gec;
		}
		gec= gec->sonraki;
	}
	return onceki;
}
void DogruKuyruk::enKucukCikar()                                    //Listede en küçük düğümeyi çıkartıyor
{
	Dugum* onceki = enKucukOncekiDugum();
	if(onceki)
	{
		if(onceki->sonraki==son)
			son=onceki;
		Dugum* sil = onceki->sonraki;
		onceki->sonraki= sil->sonraki;
		delete sil;			
	}
	else
	{
		if(ilk==0)
			return;
		Dugum* sil= ilk;
		ilk=ilk->sonraki;
		delete sil;
	}
}
int DogruKuyruk::enKucukGetir()                                   //Listeden en küçük düğümeyi getiriyor
{
	Dugum* onceki = enKucukOncekiDugum();
	
	if(onceki)
		return onceki->sonraki->veri;
	if(ilk!=0)
		return ilk->veri;
	throw std::out_of_range("Kuyruk Bos");
}
ostream& operator<<(ostream& os, DogruKuyruk& kuyruk)              //Listede bulunan verileri yazdırıyor
{
	int enKucuk=-1;

	while (true)
	{
		enKucuk=kuyruk.enKucukGetir();
		os<<enKucuk<<"  ";
		kuyruk.enKucukCikar();
		if(kuyruk.ilk==0)
		break;
	}
	cout << endl;

	os << endl;
	return os;
}
