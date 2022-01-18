#ifndef DugumTree_hpp
#define DugumTree_hpp
#include "Dugum.hpp"
#include "DogruKuyruk.hpp"
using namespace std;
class DugumTree
{
public:
	DugumTree(DogruKuyruk* kuyruk);
    DogruKuyruk* kuyruk;
    DugumTree* left;
    DugumTree* right;
};

#endif