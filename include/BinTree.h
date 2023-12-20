#pragma once
#include"BinNode.h"

template<typename T>
class BinTree
{
protected:
    int _size; BinNodePosi(T) _root;
    virtual int updateHeight(BinNodePosi(T) x);
    void updateHeightAbove(BinNodePosi(T) x);
public:
    virtual BinTree() : _size(0), _root(NULL){}
    virtual ~BinTree(){if(0 < _size) remove(_root);}
    int size() const{return _size;}
    bool empty(){return !_root;}
    BinNodePosi(T) root()const {return _root;}
    BinNodePosi(T) insertroot(T const& e);
    BinNodePosi(T) insertlc(T const& e);
    BinNodePosi(T) insertrc(T const& e);
    BinNodePosi(T) attachlc(BinNodePosi(T) x, BinTree<T>* t);
    BinNodePosi(T) attachrc(BinNodePosi(T) x, BinTree<T>* t);
    int remove(BinNodePosi(T) x);
    BinTree<T>* putup(BinNodePosi(T));
    
    template<typename VST>
    void travLevel(VST& visit){if(_root) _root->travLevel(visit);}
    template<tepename VST>
    void travin(VST& visit){if(_root) _root->travIn(visit);}
    template<tepename VST>
    void travPost(VST& visit){if(_root) _root->travPost(visit);}

    bool operator==(BinNodePosi(T) const& bn)
    {return _root && bn.root() && (_root == bn.root());}
}

template<typename T>
int BinTree::updateHeight(BinNodePosi(T) x)
{return x->height = 1 + max(x->lc->height, x->rc->height);}

template<typename T>
void BinTree::updateHeightAbove(BinNodePosi(T) x)
{
    while(x->parent)
    {
        x = x->parent;
        updateheight(x);
    }
}