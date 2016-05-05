#include "BST.h"
#include <iostream>
#include <fstream>
using namespace std;
Exceptions::Exceptions(char* _err) : err(_err){}
char* Exceptions::what() { return err; }
Busy::Busy() : Exceptions("ERROR: Already added") {}
File_Not_Open::File_Not_Open() : Exceptions("ERROR: file not open!") {}
Empty_tree::Empty_tree() : Exceptions("ERROR: Tree is empty!") {}

template <class T>
BST<T>::Node::Node(T x) : k(x), l(nullptr), r(nullptr) {}
template <class T>
void BST<T>::Node::add(T x) {
	if (x < k) {
		if (l != nullptr) l->add(x);
		if (l == nullptr) l = new Node(x);
	}
	if (x>k) {
		if (r != nullptr) r->add(x);
		if (r == nullptr) r = new Node(x);
	}
}
template <class T>
bool BST<T>::Node::search(T x) {
	if (x == k) { return true; }
	if (x > k) if (r != nullptr) return(r->search(x));
	if (x < k) if (l != nullptr) return(l->search(x));
	return false;
}
template <class T>
bool BST<T>::Node::print_file(ofstream &fout) {
	if (this != nullptr) {
		if (fout.is_open()) {
			if (l != nullptr) l->print_file(fout);
			fout << k << " ";
			if (r != nullptr) r->print_file(fout);
		}
		return true;
	}
	return false;
}
bool BST<T>::Node::print_console() {
	if (this != nullptr) {
		if (l != nullptr) l->print_console();
		cout << k << " ";
		if (r != nullptr) r->print_console();
		return true;
	}
	else return false;
}

template <class T>
BST<T>::BST() : parent(nullptr) {}
template <class T>
bool BST<T>::add(T x) {
	if (parent != nullptr) if (search(x)) throw UThe_est();
	if (parent == nullptr) { parent = new Node(x); return true; }
	else { parent->add(x); return true; }
	return false;
}
template <class T>
bool BST<T>::search(T x) {
	if (parent == nullptr) throw Empty_tree();
	return(parent->search(x));
}
template <class T>
ifstream & operator >>(ifstream & fin, BST<T> & tree) {
	if (!fin.is_open()) throw File_Not_Open();
	T x;
	while (!fin.eof()) {
		fin >> x;
		if (x != -1)tree.add(x);
		else break;
	}
	return fin;
}
template <class T>
ostream & operator <<(ostream & out, BST<T> & tree) {
	if (tree.parent->print_console()) return out;
	else throw Empty_tree();
}
template <class T>
ofstream & operator <<(ofstream & fout, BST<T> & tree) {
	if (tree.parent->print_file(fout)) return fout;
	else throw Empty_tree();
}
