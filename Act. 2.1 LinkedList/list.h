#ifndef LIST_H_
#define LIST_H_

#include <sstream>
#include <cstring>
#include <string>

using namespace std;

template <class T> class List;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	
	T	value;
	Link<T> *next;

	friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
class List{
	public:
		List();
		List(const List<T>&);
		~List();
		
    void clear();
		bool empty() const;
		void addFirst(T);
		void add(T);
		T find(T);
		void update(T,T);
		T remove(int);
    T removeFirst();
		
		string toString() const;
	private:
		Link<T> *head;
		int size;
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
  clear();
}

template <class T>
void List<T>::clear() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
void List<T>::addFirst(T val) {
	Link<T> *newLink;

	newLink = new Link<T>(val);
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::add(T val) {
	Link<T> *newLink, *p;
	
	newLink = new Link<T>(val);
	if(empty()){
		addFirst(val);
		return;
	}
	
	p = head;
	while (p->next != 0) {
		p = p->next;
	}
	
	newLink->next = 0;
	p->next = newLink;
	size++;
}

template <class T>
T List<T>::find(T val) {
	int pos = 0;
	Link<T> *p;
	
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
void List<T>::update(T pos,T val) {
	Link<T> *p;
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
T List<T>::remove(int index) {
  T val;
  int pos;
	Link<T> *p, *aux;
  aux = 0;
	p = head;

  if (index == 0) {
		return removeFirst();
	}

  for (int i=0;i<size;i++) {
		
    if(i == index){
      aux->next = p->next;
	    val = p->value;
      delete p;
	    break;
    }
    aux = p;
    p = p->next;
  }
	return val;
}

template <class T>
T List<T>::removeFirst() {
	T val;
	Link<T> *p;

	p = head;

	head = p->next;
	val = p->value;

	delete p;
	size--;

	return val;
}

template <class T>
string List<T>::toString() const {
	stringstream aux;
	Link<T> *p;

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

#endif
