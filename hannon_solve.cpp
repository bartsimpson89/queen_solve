#include<iostream>
using namespace std;
int hannon(int num,string a,string b,string c)
{
	if (num == 1)
	{
		cout<<a<<"->"<<c<<endl;
		return 0;
	}
	hannon(num-1,a,c,b);
	cout<<a<<"->"<<c<<endl;
	hannon(num-1,b,a,c);
}
        
int main()
{
	cout<<"hannon_solve"<<endl;
	hannon(3,"A","B","C");
	return 0;
}
