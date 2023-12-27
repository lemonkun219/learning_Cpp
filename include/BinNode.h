#pragma once
#define BinNodePosi(T) BinNode<T>*   		//同ListNode一样的替代方法，并且使用指针可以使传输效率大幅度提高
#define stature(p)((p) ? (p) -> height : -1)//我们约定了空树的深度为-1所以说这行代码是防止出现问题而定义的
typedef enum { RB_RED, RB_BLACK } RBColor;  //红黑树
#include"quenue.h"

using namespace std;

template<typename T> struct BinNode
{
	T data;
	BinNodePosi(T) parent; BinNodePosi(T) lc; BinNodePosi(T) rc;
	int height;
	int npl;		//左式堆，相比一般的堆多了npl结构，即到单孩子或叶节点的最短距离，最关键的功能是合并，其合并可以说相当简单;
	RBColor color;	//红黑树

	BinNode():parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RBColor){}
	BinNode(T d, BinNodePosi(T) p = NULL, BinNodePosi(T) l = NULL, BinNodePosi(T) r = NULL, int h = 0, int n = 1, RBColor c = RB_RED)
	:data(d), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c){}	//这样构造的理由是可以自由的输入想要定义的变量，不想定义的变量全部交给初始化就可以了
//使用成员逐一初始化列表的方式进行构建，使template可以适用于任何类型

	int size()
	{
		int sum = 1;
		if (lc)
			sum += lc->size();
		if (rc)
			sum += rc->size();

		return sum;
	}	//可以好好想想这个递推关系
	int islrc() { return this->parent->lc == this ? 0 : 1; }
	BinNodePosi(T) insertAsLc(T const& l)
	{
		this->lc = new BinNode(l, this);
		this->height++;

		return this->lc;
	}
	BinNodePosi(T) insertAsRc(T const& r)
	{
		this->rc = new BinNode(r, this);
		this->height++;
		return this->rc;
	}
	BinNodePosi(T) succ()	//直接后继是指中序遍历中的下一个遍历对象,中序遍历一个向上一个向下，所以可以这样分情况讨论
	{
		//先看看他有没有右子树
		if (rc)
		{
			BinNodePosi(T) x = this->rc;	//new创建对象需要手动地进行释放，所以没啥事不要用new来创建对象
			while (x->lc)
				x = x->lc;
			return x;
		}
		else	//好好想想这个else
		{
			BinNodePosi(T) x = this;
			while (x->islrc())
			{
				x = x->parent;
			}
			x = x->parent;
			return x;
		}
	}	//对于大的模型要进行抽象，讲类型分类，不要只想着单个循环，将每种情况的下一步骤总结起来再加以完善修理就可以得到规律；

	template<typename VST> void travLevel(VST& visit)
	{
		Queue<BinNodePosi(T)> q;
		q.push(this);
		while (!q.empty())
		{
			BinNodePosi(T) x = q.front();
			q.dequeue();
			visit(x->data);
			if (x->rc)
				q.enqueue(x->rc);
			if (x->lc)
				q.enqueue(x->lc);
		}
	}
	template<typename VST> void travPre(VST& visit)
	{
		stack<BinNodePosi(T)> s;
		BinNodePosi(T) x = this;
		while (x)
		{
			visit(x->data);
			if (x->lc)
			{
				x = x->lc;
				s.push(x->rc);
			}
			else
			{
				x = s.top();
				s.pop();
			}
		}
	}
	template<typename VST> void travIn(VST& visit)
	{
		BinNodePosi(T) x = this;
		while (x)
		{
			visit(x->data);
			if (x->rc)
			{
				x = x->rc;
				while (x->lc)
					x = x->lc;
			}
			else
				x = x->succ();
		}
	}
	template<typename VST> void travPost(VST& visit)
	{
		stack<BinNodePosi(T)> s;
		BinNodePosi(T) x = this;
		if (x)
			s.push(x);
		while (!s.empty())
		{
			if (s.top() != x->parent);
			{
				while (x = s.top())
				{
					if (x->lc)
					{
						s.push(x->rc);
						s.push(x->lc);
					}
					else
						s.push(x->rc);
				}
				s.pop();
			}
			x = s.top();
			s.pop();
			visit(x->data);

		}
	}


	bool operator< (BinNode const& bn) { return data < bn.data; }
	bool operator== (BinNode const& bn) { return data == bn.data; }

//BinNode状态判断
	int IsRoot(BinNode const& bn)
	{
		if(bn.parent == NULL)
			return 1;
		else
			return 0;
	}
	int IsLchild(BinNode const& bn)
	{
		if(!bn.parent == NULL)
			return 0;
		else if(bn.parent->lc == bn)
			return 1;
	}
	int IsRchild(BinNode const& bn)
	{
		if(!bn.parent == NULL)
			return 0;
		else if(bn.parent->rc == bn)
			return 1;
	}
	bool Ischild_cut()
	{
		if(this->IsRoot())
			return flase;
		if(this->parent->lc == this)
		{
			this->parent->lc = NULL;
			return true;
		}	
		if(this->parent->rc == this)
		{
			this->parent->rc = NULL;
			return true;
		}
	}
	int Hasparent(){return IsRoot(this);}
	int HasLchild(){return lc;}	
	int HasRchild(){return rc;}
	int Haschild(){return lc || rc;}
	int HasBothchild(){return lc && rc;}
	int IsLeaf(){return this->Haschild;}	
	int sib(){return IsLchild ? parent->rc : parent->lc;}
	BinNodePosi(T) fromparent(){return parent;}
	int uncle(){return this->parent->IsLchild() ? parent->parent->rc : parent->parent->lc;}
	

};




//template<typename T, typename VST>//先序遍历递归版算法示例
//void B_travPre_re(BinNodePosi(T) x, VST& visit)
//{
//    if (!x) return;
//    visit(x->data);
//    B_travPre_re(x->lc);
//    B_travPre_re(x->rc);
//}

//template<typename T, typename VST>//中序遍历递归版演示
//void B_travIn_re(BinNodePosi(T) x, VST& visit)
//{
//    if (!x) return;
//    B_travIn_re(x->lc, visit);
//    visit(x->data);
//    B_travIn_re(x->rc, visit);
//}

//template<typename T, typename VST>//后序遍历递归版演示
//void B_travPost_re(BinNodePosi(T) x, VST& visit)
//{
//    if (!x) return;
//    B_travPost_re(x->lc, visit);
//    B_travPost_re(x->rc, visit);
//    visit(x->data);
//}