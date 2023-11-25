#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename T>
class stack
{
public:

	//两个构造函数
	//获取下一个元素的位置
	stack()
	{
		size = 0;
		landing = new vector<T>();
		_next = landing->begin();
	}
	stack(int _size = 2)
	{
		//用户确切值判断
		if (_size < 2)
		{
			_size = 2;
			cout << "您输入的值不合理，已自动为您调整至2" << endl;
		}

		//初始化设置
		size = _size;
		landing = new vector<T>(_size);
		_next = landing->begin() + 1;

		//初始化数据设置
		int temp = size;
		int i = 0;
		while (temp--)
		{
			T in;
			i++;
			cout << "请输入第" << i << "个数据数据" << endl;
			cin>>in;

			while(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout<<"请输入一个正确的数值：";
				cin>>in;
			}
			(*landing)[i] = in;
		}
	}

	//两个重置函数
	bool reset()
	{
		delete[] landing;
		landing = new vector<T>();
		_next = landing->begin();
		if(landing)
			return true;
		return false;
	}

	bool reset(int& _size = 2)
	{
		//用户确切值判断
		if (_size < 2)
		{
			_size = 2;
			cout << "您输入的值不合理，已自动为您调整至2" << endl;
		}

		//初始化设置
		size = _size;
		landing = new vector<T>(_size);
		_next = landing->begin() + 1;

		//初始化数据设置
		int temp = size;
		while (temp--)
		{
			T in;
			int i = 0;
			i++;
			cout << "请输入第" << i << "个数据数据" << endl;
			landing->push_back(cin >> in);
		}
		if(landing && _next)
			return true;
		return false;
	}

	//一个析构函数
	~stack()
	{
		if(landing)
			delete landing;	//delete[]用来释放连续空间，delete用来释放单个空间
							//但是对于vector, list, map这种高级线性结构而言，并不需要用delete[]来释放，在你delete完以后就会自动调用其内置的析构函数完成释放
	}

	//三个检查错误程序
	bool full()
	{
		if (size == landing->max_size())
			return true;
		return false;
	}
	bool empty()
	{
		if(size == 0)
			return true;
		return false;
	}
	bool check_size()
	{
		if (size == landing->size())
			return true;
		return false;
	}

	//关于下一个位置的两个函数
	typename vector<T>::iterator get_next()const
	{
		if(_next == landing.end() + 1)
		{
			cout<<"已经到了最后一个元素！已自动返回函数本身";
			return landing->end();
		}
		if (empty())
			cerr << "请检查是否存在元素！";
		return _next;
	}
	bool reset_next()const
	{
		if(empty())
			cerr<<"这是一个空的栈！";

		auto it = _next;
		if (it == landing->end() + 1)
		{
			cout<<"注意！已经到了最后一个元素"<<endl;
			return false;
		}
		
		_next = it;
		return true;
	}

	//两个删除类函数
	bool pop()
	{
		if (empty())
			return false;

		size--;
		landing->pop_back();
		return check_size();
	}
	bool peek(T& top)
	{
		if(empty())
			return false;
		top = landing->front();
		size--;
		landing->pop_back();
		return check_size();
	}

	typename vector<T>::iterator push(T e)
	{
		if(full())
		{
			cout<<"这个栈已经满了"<<endl;
			cerr<<"winning!";
		}
		size++;
		landing->push_back(e);
		bool test = check_size();
		
		return landing->end();
	}

	//两个查看类函数
	T top()
	{
		if(empty())
		{
			cout<<"这个栈是一个空栈！"<<endl;
			cerr<<"winning";
		}

		return landing->front();
	}
	int get_size()
	{
		return size;
	}

	//几个功能类函数
	bool find(T e)
	{
		if(empty())
		{
			cout<<"这个栈是一个空栈！"<<endl;
			cerr<<"winning";
		}

		for(auto const& it:*landing)
		{
			if(it == e)
				return true;
		}
		
		return false;
	}
	int count(T e)
	{
		if(!find(e))
			cout<<"没有这个元素"<<endl;
		
		int i = 0;
		for(auto const& it:landing)
		{
			if(it == e)
				i++;
		}
		
		return i;
	}
	void display()
	{
		cout<<"下往上打印，最后一个为顶层"<<endl;
		for(auto const& e:landing)//不晓得会不会出错
		{
			cout<<e<<" ";
		}
	}


private:
	mutable typename vector<T>::iterator _next;
	int size;
	vector<T>* landing;
};
