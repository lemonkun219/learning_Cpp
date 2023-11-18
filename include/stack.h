#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename T>
class stack
{
public:
	//获取下一个元素的位置
	stack():_next(NULL)
	{
		size = 0;
		vector<T>* landing = new vector<T>();
	}
	stack(int& _size = 2)
	{
		//用户确切值判断
		if (_size < 2)
		{
			_size = 2;
			cout << "您输入的值不合理，已自动为您调整至2" << endl;
		}

		//初始化设置
		size = _size;
		vector<T>* landing = new vector<T>(_size);
		_next = landing->begin()++;

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
	}

	//三个检查错误程序
	bool full()
	{
		if (size != landing->max_size())
			return true;
		return else;
	}
	bool empty()
	{
		if(size = 0)
			return true;
		return false;
	}
	bool check_size()
	{
		if (size = landing->size())
			return true;
		return false;
	}

	//关于下一个位置的两个函数
	vector<T>::iterator get_next()const
	{
		if(_next == NULL)
			cerr<<"已经到了最后一个元素！";
		if (empty())
			cerr << "请检查是否存在元素！";
			return _next;
	}
	bool reset_next()const
	{
		if(empty())
			cerr<<"这是一个空的栈！";

		auto it = _next++;
		if (it = NULL)
		{
			cout<<"注意！已经到了最后一个元素"<<endl;
			return false;
		}
		
		_next = it;
		return true;
	}

	bool pop()
	{
		if (empty())
			return false;

		size--;
		landing->pop_back();
		reset_next();
		return check_size();
	}
	bool peek();

	int push(T e);

	T top();
	int get_size()
	{
		return size();
	}

	bool find();
	int count;


private:
	mutable vector<T>::iterator _next;
	int size;
	vector<T>* landing;
};
