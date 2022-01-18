#ifndef DogruKuyruk_hpp
#define DogruKuyruk_hpp
#include<iostream>
#include<iomanip>
#include <exception>
#include "Dugum.hpp"

using namespace std;

class DogruKuyruk
{
public:
	DogruKuyruk();
	~DogruKuyruk();
	void ekle(int veri);
	void enKucukCikar();
	Dugum* enKucukOncekiDugum();
	int enKucukGetir();
	int mesafe=0;
	friend ostream& operator<<(ostream& os, DogruKuyruk& kuyruk);

private:
	Dugum* ilk;
	Dugum* son;	
};

#endif