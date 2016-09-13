#include "Nodo.h"

class ListaCircular
{
public:
	Nodo* H;
	Nodo* T;	
	ListaCircular();
	ListaCircular(int Dato);
	bool ListaCircularVacia();
	void Add(int Dato);
	void AddRef(int Dato, int Ref);
	int Remove();
	void RemoveRef(int Ref);
	void VaciarListaCircular();
	Nodo* BuscarElemento(int Dato);
	void Show();
};