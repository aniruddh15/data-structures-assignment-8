#include <list>
#include <iostream>
#include <stdlib.h>
#include "bintree.h"

using namespace main_savitch_10;
template <class T>
std::list<T>* createList(){
	std::list<int> *list1=new std::list<int>;
	
	list1->push_back(1);
	list1->push_back(2);
	list1->push_back(3);
	list1->push_back(4);
	list1->push_back(5);
	return list1;
	
}
template <class T>
binary_tree_node<T>* create_bst(std::list<T> *list_ptr,size_t size){
	// binary_tree_node<T> *parent=new binary_tree_node<T>(list_ptr->front());
	if(size<=0){
		return NULL;
	}
	binary_tree_node<T> *left;
	binary_tree_node<T> *parent;
	binary_tree_node<T> *right;
	left=create_bst(list_ptr,(size/2));
	parent=new binary_tree_node<T>(list_ptr->front());
	list_ptr->pop_front();
	parent->set_left(left);
	right=create_bst(list_ptr,(size-size/2)-1);//study
	parent->set_right(right);
	return parent;

	// binary_tree_node<T> *left;
	// binary_tree_node<T> *right;

//	list_ptr->pop_back();
	//left=new binary_tree_node<T>(list_ptr->back());
	//parent->set_left(left);
	
	
}
template <class T>
void Fprint(const std::list<T>* list){
	typename std::list<T>::const_iterator iter;
	for(iter=list->begin();iter != list->end();++iter){
		std::cout<<*iter<<" ";
		
	}
	std::cout<<std::endl;
}
int main(){
std::list<int> *list_ptr=createList<int>();
std::cout<<list_ptr->size()<<std::endl;
Fprint(list_ptr);
binary_tree_node<int> *bbst=create_bst<int>(list_ptr,list_ptr->size());
//std::cout<<bbst->data()<<std::endl;
print(bbst,4);
return 0;
};