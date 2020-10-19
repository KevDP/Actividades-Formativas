#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <class T>
class Heap {

private:
	T *data;
	unsigned int tamaño;    // uint impide que se utilicen datos negativos
	unsigned int count;
	unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;
	void heapify(unsigned int);
	void swap(unsigned int, unsigned int);

public:
	Heap(unsigned int);
	void push(T);
	T pop();
  T top();
  bool empty() const;
  int size() const;  //Ya no es necesario que sea uint, dado que usa count, quien ya posee ese atributo

	string toString() const;
};

template <class T>
Heap<T>::Heap(unsigned int tam){
	tamaño = tam;
	data = new T[tam];
	count = 1;            // Contador y primer dato a tomar será desde 1
}

template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return (pos) / 2;
}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
	return ((2 * pos));
}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
	return ((2 * pos) + 1);
}

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}
template <class T>
void Heap<T>::heapify(unsigned int pos) {
	unsigned int le = left(pos);
	unsigned int ri = right(pos);
	unsigned int min = pos;
	if (le <= count && data[le] < data[min]) {
		min = le;
	}
	if (ri <= count && data[ri] < data[min]) {
		min = ri;
	}
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}

template <class T>
void Heap<T>::push(T val){    // Ingresar un dato a la fila priorizada
	unsigned int pos;
	pos = count;
	count++;

	while (pos > 1 && val < data[parent(pos)]){
		data[pos] = data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;
}

template <class T>
T Heap<T>::pop(){       // Sacar un dato de la fila priorizada
	T aux = data[1];
	data[1] = data[--count];
	heapify(1);
	return aux;
}

template <class T>
T Heap<T>::top(){       // Regresar el primer dato de la fila priorizada
  T aux = data[1];
  return aux;
}

template <class T>
bool Heap<T>::empty() const {   // ¿Está vacía?
	return (count == 1);
}

template <class T>
int Heap<T>::size() const {     // ¿Cuántos datos tiene?
	return count - 1;
}

template <class T>
string Heap<T>::toString() const {
	stringstream aux;
	aux << "[";	for (unsigned int i = 1; i < count; i++) {
		if (i != 1) {
			aux << " ";
		} aux << data[i];
	} aux << "]";
	return aux.str();
}
#endif
	