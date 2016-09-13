#include "ListaCircular.h"

ListaCircular::ListaCircular()
{
	this->H=NULL;
	this->T=NULL;
}

ListaCircular::ListaCircular(int Dato)
{
	Nodo * aux= new Nodo(Dato);
	this->H=aux;
	this->T=aux;
	T->setSig(H);
	H = T;
}

bool ListaCircular::ListaCircularVacia()
{
	if (this->H == NULL && this->T == NULL)
		return true;
	return false;
}

void ListaCircular::Add(int Dato)
{
	Nodo* aux = new Nodo(Dato,this->H);
	if (ListaCircularVacia())
	{
		this->T= aux;
		H = T;
		T->setSig(H);

	}
	T->setSig(aux);
	this->T = aux;
}

void ListaCircular::Show()
{
	if (!ListaCircularVacia())
	{
		Nodo* aux = this->H;
		while(aux!=T)
		{
			std::cout<<aux->getDato()<<std::endl;
			aux=aux->getSig();
		}
		std::cout<<T-> getDato()<<std::endl;
	}
	else
	{
		std::cout<<"La lista está vacía"<<std::endl;
	}

}

void ListaCircular::AddRef(int Dato, int Ref)
{
	if(ListaCircularVacia())
	{
		Add(Dato);
		std::cout<<"La lista estaba vacía, sin embargo se agregó el elemento"<<std::endl;
	}else{

		if (BuscarElemento(Ref)==NULL)
		{
			std::cout<<"No se encontró la referencia"<<std::endl;
		}else{
			Nodo* aux = BuscarElemento(Ref);
			Nodo* aux2 = new Nodo(Dato,aux->getSig());
			aux->setSig(aux2);
		}
	}
}

int ListaCircular::Remove(void)
{
	if(!ListaCircularVacia())
	{
		int Dato = H->getDato();
		
		if (H != T)
		{			
			H = H->getSig();
			T->setSig(H);
			return Dato;
		}
		else
		{

			VaciarListaCircular();
			return Dato;
		}
	}
	else
	{
		std::cout<<"La lista está vacía"<<std::endl;
		return (int)NULL;
	}	
}

void ListaCircular::RemoveRef(int Ref)
{
	if(!ListaCircularVacia())
	{

		Nodo* aux = H;
		Nodo* aux2 = NULL; 

		if (T->getDato() != Ref)
		{
			 
			while(aux != NULL && aux->getDato()!= Ref )
			{
				aux2 = aux;
				aux = aux->getSig();
			}
			aux2->setSig(aux->getSig());
			
		}
		else
		{

			while(aux != T)
			{
				aux2 = aux;
				aux = aux->getSig();
			}
			aux2->setSig(aux->getSig());
			T = aux2;
		}
	}else{
		std::cout<<"La lista está vacía"<<std::endl;

	}
}

//Si no se encuentra el elemento, regresa NULL
Nodo* ListaCircular::BuscarElemento(int Dato)
{
	if(!ListaCircularVacia())
	{
		if (T->getDato() != Dato)
		{
			Nodo* aux = H;
			T->setSig(NULL);//Para no generar un ciclo infinito
			while(aux != NULL && aux->getDato()!=Dato)
			{
				aux = aux->getSig();
			}
			T->setSig(H);//Para conservar la estructura circular
			return aux;
		}
		else
		{
			return T;
		}
	}
}

void ListaCircular::VaciarListaCircular(void)
{
	this->H = NULL;
	this->T = NULL;
}