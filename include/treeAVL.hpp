#ifndef treeAVL_hpp
#define treeAVL_hpp
#include "DogruKuyruk.hpp"
#include "DugumTree.hpp"
using namespace std;
class treeAVL
{
public:
    treeAVL();
    ~treeAVL();
    void ekle(DogruKuyruk* kuyruk);
    int yukseklik() ;
    void postOrder(); 

private:    
    void RemoveSubTree(DugumTree* ptr);
    DugumTree* ekle(DogruKuyruk* kuyruk, DugumTree* aktifDugum);
    int yukseklik(DugumTree* aktifDugum);
    void postOrder(DugumTree* aktif);
    DugumTree* solaDondur(DugumTree* buyukEbeveyn);
    DugumTree* sagaDondur(DugumTree* buyukEbeveyn);
    DugumTree* root;
};

#endif  