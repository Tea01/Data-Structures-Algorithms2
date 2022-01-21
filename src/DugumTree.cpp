

#include "DugumTree.hpp"
#include <exception>

using namespace std;

DugumTree::DugumTree(DogruKuyruk* kuyruk)        // Ağaçaların düğümelerde içinde kuyruğun adresi tutulmaktadır
{
    this->kuyruk = kuyruk;
    left=right=0;
}
