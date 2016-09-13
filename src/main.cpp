#include "ListaCircular.h"

int main()
{
	ListaCircular lc = ListaCircular();
	lc.AddRef(3,6);
	lc.AddRef(8,5);
	lc.Add(4);
	lc.Add(5);
	lc.Add(6);
	lc.Add(7);
	//lc.Remove();
	lc.RemoveRef(7);
	lc.RemoveRef(6);
	lc.RemoveRef(4);
	lc.Remove();
	lc.Remove();
	lc.Remove();
	lc.Remove();
	lc.Show();
	std::cout<<"Hello World"<<std::endl;
	return 0;
}