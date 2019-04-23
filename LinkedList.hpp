#ifndef LINKEDLIST_HPP
#define	LINKEDLIST_HPP

#include <iostream>
#include "Node.hpp"

using namespace std;

template <class T>
class LinkedList {
private:
    Node<T>* head; 
    int length;  
public:

    LinkedList();
    LinkedList(const LinkedList<T>& ll);
    LinkedList<T>& operator=(const LinkedList<T>& ll);
    ~LinkedList();

    Node<T>* getHead() const;
    Node<T>* first() const;
    Node<T>* findPrev(const T& data) const;
    Node<T>* findNode(const T& data) const;
    void insertNode(Node<T>* prev, const T& data); 
    void deleteNode(Node<T>* prevNode);
    void clear();
    size_t getLength() const;
    void print() const;
    void swap(int index1, int index2);
};

template <class T>
void LinkedList<T>::print() const {
    const Node<T>* node = first();
    while (node) {
        std::cout << node->getData();
        node = node->getNext();
    }
    cout << std::endl;
}

template <class T>
LinkedList<T>::LinkedList() {
	head = new Node<T>(); 
	length = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& ll) {
	Node<T> * tmp = ll.first();
	head = new Node<T>();
	Node<T> * tmp2 = head;
	length = 0;

	while( tmp != NULL ) {
		this->insertNode(tmp2, tmp->getData() );
		tmp = tmp-> getNext();
		tmp2 = tmp2 ->getNext();
	}
	length = ll.getLength();
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& ll) {
	
		this->~LinkedList();
		Node<T> * tmp = ll.first();
		head = new Node<T>();
		Node<T> * tmp2 = head;
		length = 0;

		while( tmp != NULL ) {
			this->insertNode(tmp2, tmp->getData() );
			tmp = tmp-> getNext();
			tmp2 = tmp2->getNext();
		}
	
	length = ll.getLength();
}

template <class T>
LinkedList<T>::~LinkedList() {
	Node<T>* tmp = head;
	Node<T>* tmp2;

	while(tmp != NULL){
		tmp2 = tmp->getNext();
		delete tmp;
		tmp = tmp2;
	}
}

template <class T>
Node<T>* LinkedList<T>::getHead() const {
	return head;
}

template <class T>
Node<T>* LinkedList<T>::first() const {
	return head->getNext();
}

template <class T>
Node<T>* LinkedList<T>::findPrev(const T& data) const {
	Node<T>* tmp = head;
	while(tmp->getNext() != NULL){
		if (tmp->getNext()->getData() == data){
			return tmp;
		}
		tmp = tmp->getNext();
	}
	return NULL;
}

template <class T>
Node<T>* LinkedList<T>::findNode(const T& data) const {
	Node<T>* tmp = head;
	while(tmp != NULL){
		if (tmp->getData() == data){
			return tmp;
		}
		tmp = tmp->getNext();
	}
	return NULL;
}

template <class T>
void LinkedList<T>::insertNode(Node<T>* prev, const T& data){
	if(prev != NULL){
		Node<T>* tmp = new Node<T>(data);
		tmp->setNext(prev->getNext());
		prev->setNext(tmp);
		length++;
	}
}

template <class T>
void LinkedList<T>::deleteNode(Node<T>* prevNode){
	if(prevNode != NULL){
		Node<T>* tmp = prevNode -> getNext();
		if (tmp != NULL){
			length--;
			if (length == 1) { prevNode->setNext(NULL); }
			else { prevNode->setNext(prevNode->getNext()->getNext()); }
			
		}
		delete tmp;
	}
}

template <class T>
void LinkedList<T>::clear(){
	/*while(length > 1) {
		deleteNode(head);
	}*/
    /*Node<T>* dummy = getHead();

    while ( dummy->getNext() ) {
        Node<T>* tmp = dummy->getNext();
        dummy->setNext(tmp->getNext());

        delete tmp;
    }*/
}

template <class T>
size_t LinkedList<T>::getLength() const{
	return length;
}

template <class T>
void LinkedList<T>::swap(int index1, int index2){
	if (index1 < length and index2 < length and index1 != index2 and index1 >= 0 and index2 >= 0) {
		Node<T>* tmp1 = head;
		Node<T>* tmp2 = head;
		T tmp3, tmp4;
		int count = 0;

		if (index1 == -1) {tmp1 = first(); }
		else {
			while(count < index1){
				tmp1 = tmp1->getNext();
				count++;
			}
			count = 0;
		}
	
		if (index2 == -1) {tmp2 = first(); }
		else {
			while(count < index2){
				tmp2 = tmp2->getNext();
				count++;
			}
		}

		tmp3 = tmp1->getNext()->getData();
		tmp4 = tmp2->getNext()->getData();

		deleteNode(tmp1);
		insertNode(tmp1,tmp4);

		deleteNode(tmp2);
		insertNode(tmp2,tmp3);
	}
}

#endif	


