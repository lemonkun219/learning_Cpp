#pragma once
#include<iostream>
#include<list>

using namespace std;

template<typename T> class Queue
{
private:
	list<T> List;
public:
	void enqueue(T const& e) { List.push_back(e); }
	void dequeue() { List.remove_if(List.front()); }
	T& front() { return List.front(); }
};
