#pragma once
#include"BinNode.h"
#include"stack.h"

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
    BinNodePosi(T) BinTree<T>::insertlc(BinNodePosi(T), T const& e);
    BinNodePosi(T) BinTree<T>::insertrc(BinNodePosi(T), T const& e);
    BinNodePosi(T) attachlc(BinNodePosi(T) x, BinTree<T>*& t);
    BinNodePosi(T) attachrc(BinNodePosi(T) x, BinTree<T>*& t);
    int remove(BinNodePosi(T) x);
    BinTree<T>* putup(BinNodePosi(T) x);
    
    template<typename VST>
    void travLevel(VST& visit){if(_root) _root->travLevel(visit);}
    template<tepename VST>
    void travin(VST& visit){if(_root) _root->travIn(visit);}
    template<tepename VST>
    void travPost(VST& visit){if(_root) _root->travPost(visit);}

    bool operator==(BinNodePosi(T) const& bn)
    {return _root && bn.root() && (_root == bn.root());}
};

template<typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x)
{return x->height = 1 + max(x->lc->height, x->rc->height);}

template<typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x)
{
    while(x)
    {
       updateHeight(x);
       if(x->parent == updateHeight(x->parent))
       {
            return;
       } 
       x = x->parent;
        
    }
    return;
}

template<typename T>
BinNodePosi(T) BinTree<T>::insertroot(T const& e)
{
    _size = 1;
    return _root = new BinNode<T>(e);
}

template<typename T>
BinNodePosi(T) BinTree<T>::insertlc(BinNodePosi(T) x, T const& e)
{
   _size++;
   return x->lc == new BinNodePosi(T) (e); 
}

template<typename T>
BinNodePosi(T) BinTree<T>::insertrc(BinNodePosi(T) x, T const& e)
{
    _size++;
    return x->rc == new BinNodePosi(T) (e);
}

template<typename T>
BinNodePosi(T) BinTree<T>::attachlc(BinNodePosi(T) x, BinTree<T>*& t)
{
    delete x->lc;
    if(x->lc = t->_root)
        x->lc->parent = x;
    _size += t->size;
    updateheightAbove(x);
    t->_root = NULL;
    t->size = 0;
    release(t);
    t == NULL;
    return x;
}

template<typename T>
BinNodePosi(T) BinTree<T>::attachrc(BinNodePosi(T) x, BinTree<T>*& t)
{
    delete x->rc;
    if(x->rc = t->_root)
        x->rc->parent = x;
    x->_size += t->_size;
    t->_root = NULL;
    t->_size = 0;
    release(t);
    t == NULL;
    return x;
}

template<typename T>
int BinTree<T>::remove(BinNodePosi(T) x)
{
    BinNodePosi(T) temp;
    BinNodePosi(T) mani;
    temp = x;
    while(x->Haschild())
    {
        while(temp->Haschild())
        {
            if(temp->HasLchild())
            {
                temp = temp->lc;
                continue;
            }
            if(temp->HasRchild())
                temp = temp->rc;
        }
        mani = temp;
        temp = temp->parent;
        delete mani;
        this->_size--;
    }
    temp = x->parent;
    delete x;
    updateHeightAbove(temp);
    temp = NULL;
}

void size_c(int s){s++;}
template<typename T>
BinTree<T>* BinTree<T>::putup(BinNodePosi(T) x)
{
    BinNodePosi(T) temp = x->Ischild_cut();
    updateHeightAbove(T);
    temp = NULL;
    BinTree<T>* t = new BinTree<T>;
    t->_root = x;
    t->_size = x->travIn(&size_c);
    
    return t;
}