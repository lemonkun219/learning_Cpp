#include<iostream>
#include<vector>
#include"/workspaces/learning_Cpp/include/quenue.h"
#include"/workspaces/learning_Cpp/include/stack.h"
#include"/workspaces/learning_Cpp/include/BinNode.h"

using namespace std;

int main()
{
	stack<int> s();
	stack<int> st(3);
	BinNode<int> b;
	BinNode<int> bi(3);
	if(st.find(2))
		cout<<"找到了！"<<endl;
	else
		cout<<"没找到"<<endl;

	return 0;
}