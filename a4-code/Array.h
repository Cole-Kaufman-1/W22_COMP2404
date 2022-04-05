
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>
class Array {

	template <class V>
	friend ostream& operator<<(ostream&, const Array<V>&);

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		void add(const T&);
		int getSize() const;
		bool isFull() const;
		T& operator[](int) const;
	
	private:
		int size;
		T* elements;
	
};

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}

template <class T>
Array<T>::~Array(){
	delete [] elements;
}

template <class T>
void Array<T>::add(const T& t){
	if (size >= MAX_ARR)   return;
  	elements[size++] = t;
}

template <class T>
int Array<T>::getSize() const{
	return size;
}

template <class T>
bool Array<T>::isFull() const{
	return size >= MAX_ARR;
}

template <class V>
ostream& operator<<(ostream& out, const Array<V>& arr){
	int i = 0;
	while(i < arr.size){
		out<<arr.elements[i]<<endl;
		i++;
	}
	return out;
}

template <class T>
T& Array<T>::operator[](int index) const{
	if (index < 0 || index > size - 1){
		cerr<<"Invalid index exiting program"<<endl;
		exit(1);
	}
	return elements[index];
}

#endif