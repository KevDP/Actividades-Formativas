/*Datos del Alumno
Nombre: Kevin Joan Delgado Pérez
Matrícula: A01706328*/
#ifndef SORTS_H_
#define SORTS_H_

#include <list>
#include <vector>

template <class T>
class Sorts{

  private:

    void swap(std::vector<T>&, int, int);
    void copyArray(std::vector<T>&, std::vector<T>&, int, int);
    void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
    void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);

  public:
    std::vector<T> ordenaSeleccion(std::vector<T>&);
    std::vector<T> ordenaBurbuja(std::vector<T>&);
    std::vector<T> ordenaMerge(std::vector<T>&);
    int busqSecuencial(std::vector<T>&, int);
    int busqBinaria(std::vector<T>&, int);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &prueba, int i, int j) {
	T aux = prueba[i];
	prueba[i] = prueba[j];
	prueba[j] = aux;
}

template <class T>
std::vector<T> Sorts<T>::ordenaSeleccion(std::vector<T> &prueba) {
	int pos;

	for (int i = prueba.size() - 1; i > 0; i--) {
		pos = 0;
		for (int j = 1; j <= i; j++) {
			if (prueba[j] > prueba[pos]) {
				pos = j;
			}
		}

		if (pos != i) {
			swap(prueba, i, pos);
		}
	}
	return prueba;
}

template <class T>
std::vector<T> Sorts<T>::ordenaBurbuja(std::vector<T> &prueba) {

	for (int i = prueba.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (prueba[j] > prueba[j + 1]) {
				swap(prueba, j, j + 1);
			}
		}
	}
	return prueba;
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid &&j <= high) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}

template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	int mid;

	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}


template <class T>
std::vector<T> Sorts<T>::ordenaMerge(std::vector<T> &prueba) {
	std::vector<T> tmp(prueba.size());
	mergeSplit(prueba, tmp, 0, prueba.size() - 1);
	return prueba;
}



template <class T>
int Sorts<T>::busqSecuencial(std::vector<T> &prueba, int val){
  for(int i = 0;i < prueba.size();i++){
    if (val == prueba[i]) {
      return i;
    }
  }
  return -1;
}


template <class T>
int Sorts<T>::busqBinaria(std::vector<T> &prueba, int val) {
	int mid;
	int low = 0;
	int high = prueba.size() - 1;

	while (low < high) {
		mid = (high + low) / 2;
		if (val == prueba[mid]) {
			return mid;
		} else if (val < prueba[mid]) {
			high = mid - 1;
		} else if (val > prueba[mid]) {
			low = mid + 1;
		}
	}
	return low;
}

#endif 