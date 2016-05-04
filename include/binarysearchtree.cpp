#include "binarysearchtree.h"
#include <iostream>
#include <fstream>
using namespace std;
Iscluchenia::Iscluchenia(char* _err) : err(_err){}
char* Iscluchenia::what() { return err; }
Uzhe_est::Uzhe_est() : Iscluchenia("ERROR: etot element uzhe dobavlen!") {}
File_Not_Open::File_Not_Open() : Iscluchenia("ERROR: file not open!") {}
Pustoe_derevo::Pustoe_derevo() : Iscluchenia("ERROR: derevo pusto!") {}
//Element_not_found::Element_not_found() : Iscluchenia("ERROR: takogo elementa v dereve net!") {}

template <class Z>
BinarySearchTree<Z>::der::der(Z x) : D(x), l(nullptr), r(nullptr){}
template <class Z>
void BinarySearchTree<Z>::der::add(Z x){
	if (x < D){
		if (l != nullptr) l->add(x);
		if (l == nullptr) l = new der(x);
	}
	if (x>D){
		if (r != nullptr) r->add(x);
		if (r == nullptr) r = new der(x);
	}
}
template <class Z>
bool BinarySearchTree<Z>::der::search(Z x){
	if (x == D) { return true; }
	if (x > D) if (r != nullptr) return(r->search(x));
	if (x < D) if (l != nullptr) return(l->search(x));
	return false;
}
template <class Z>
bool BinarySearchTree<Z>::der::print_console(){
	if (this != nullptr){
		if (l != nullptr) l->print_console();
		cout << D << " ";
		if (r != nullptr) r->print_console();
		return true;
	}
	else return false;
}
template <class Z>
bool BinarySearchTree<Z>::der::print_file(ofstream &fout){
	if (this != nullptr){
		if (fout.is_open()){
			if (l != nullptr) l->print_file(fout);
			fout << D << " ";
			if (r != nullptr) r->print_file(fout);
		}
		return true;
	}
	return false;
}

template <class Z>
BinarySearchTree<Z>::BinarySearchTree() : root(nullptr){}
template <class Z>
bool BinarySearchTree<Z>::add(Z x){
	if (root != nullptr) if (search(x)) throw Uzhe_est();
	if (root == nullptr) { root = new der(x); return true; }
	else { root->add(x); return true; }
	return false;
}
template <class Z>
bool BinarySearchTree<Z>::search(Z x){
	if (root == nullptr) throw Pustoe_derevo();
	return(root->search(x));
}
template <class Z>
ostream & operator <<(ostream & out, BinarySearchTree<Z> & tree) {
	if (tree.root->print_console()) return out;
	else throw Pustoe_derevo();
}
template <class Z>
ifstream & operator >>(ifstream & fin, BinarySearchTree<Z> & tree) {
	if (!fin.is_open()) throw File_Not_Open();
	Z x;
	while (!fin.eof()){
		fin >> x;
		if(x!=-1)tree.add(x);
		else break;
	}
	return fin;
}
template <class Z>
ofstream & operator <<(ofstream & fout, BinarySearchTree<Z> & tree) {
	if (tree.root->print_file(fout)) return fout;
	else throw Pustoe_derevo();
}
