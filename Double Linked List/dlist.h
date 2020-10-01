#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>
#include <cstring>

using namespace std;

template <class T> class DList;

template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T	    value;
	DLink<T> *previous;
	DLink<T> *next;

	friend class DList<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}

template <class T>
class DList {
  public:
    DList();
    DList(const DList<T>&);
    ~DList();

    void clear();
    bool empty() const;
    void addFirst(T);
    void add(T);
    T find(T) const;
    void update(T,T);
    T remove(int);
    T removeFirst();

    string toStringForward() const;
    string toStringBackward() const;
  private:
    DLink<T> *head;
    DLink<T> *tail;
    int size;
};

template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

template <class T>
DList<T>::~DList() {
	clear();
}

template <class T>
void DList<T>::clear() {
	DLink<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	size = 0;
}

template <class T>
bool DList<T>::empty() const {
	return (head == 0 && tail == 0);
}

template <class T>
void DList<T>::addFirst(T val) {
	DLink<T> *newLink;
	newLink = new DLink<T>(val);

	if (empty()) {
		head = newLink;
		tail = newLink;
	} else {
		newLink->next = head;
		head->previous = newLink;
		head = newLink;
	}
	size++;
}

template <class T>
void DList<T>::add(T val) {
	DLink<T> *newLink;
	newLink = new DLink<T>(val);

	if (empty()) {
		head = newLink;
		tail = newLink;
	} else {
		tail->next = newLink;
		newLink->previous = tail;
		tail = newLink;
	}
	size++;
}

template <class T>
T DList<T>::find(T val) const{
	int pos = 0;
	DLink<T> *p;
	
	p = head;
	while(p != 0){
		if (p->value == val) {
			return pos;
		}
		p = p->next;
		pos++;
	}
	return -1;
}

template <class T>
void DList<T>::update(T pos,T val) {
	DLink<T> *p;
  int cont = 0;
	
	p = head;
	while (p != 0){
		if (cont == pos){
			p->value = val;
		}
		p = p->next;
		cont++;
	}
}

template <class T>
T DList<T>::remove(int index) {
	int pos;
	T val;
	DLink<T> *p;
  p = head;
	pos = 0;

	if (index == 0) {
		return removeFirst();
	}

  for (int i=0;i<size;i++) {

    if(i == index){
      p->previous->next = p->next;
      if (p->next != 0) {
        p->next->previous = p->previous;
      }
	    val = p->value;
      delete p;
	    break;
    }
    p = p->next;
  }
	size--;
	return val;
}

template <class T>
T DList<T>::removeFirst() {
	T val;
	DLink<T> *p;

	p = head;
	val = p->value;

	if (head == tail) {
		head = 0;
		tail = 0;
	} else {
		head = p->next;
		p->next->previous = 0;
	}
	delete p;
	size--;

	return val;
}

template <class T>
string DList<T>::toStringForward() const {
		stringstream aux;
		DLink<T> *p;
		p = head;
		aux << "[";
		while (p != 0) {
			aux << p->value;
			if (p->next != 0) {
				aux << ", ";
			}
			p = p->next;
		}
		aux << "]";
		return aux.str();
	}
  
template <class T>
string DList<T>::toStringBackward() const {
	stringstream aux;
	DLink<T> *p;
	p = tail;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->previous != 0) {
			aux << ", ";
		}
		p = p->previous;
	}
	aux << "]";
	return aux.str();
}

#endif