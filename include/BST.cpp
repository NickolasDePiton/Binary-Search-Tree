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
ostream & operator <<(ostream & out, BST<T> & tree) {
	if (tree.parent->print_console()) return out;
	else throw Empty_tree();
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
ofstream & operator <<(ofstream & fout, BST<T> & tree) {
	if (tree.parent->print_file(fout)) return fout;
	else throw Empty_tree();
}







/*template <class T>
class BST {
public:
	BST() :parent(nullptr) {}
	bool add(T x) { // Добавление элемента
		if (parent == nullptr) { parent = new Node(x); return true; }
		else { parent->add(x); return true; }
		return false;
	}
	bool search(T x) { return(parent->search(x)); } // Поиск
	bool read_file(char* a) { // Чтение из файла
		ifstream fin; T x;
		fin.open(a);
		if (fin.is_open()) {
			while (!fin.eof()) {
				fin >> x;
				this->add(x);
			}
			fin.close();
			return true;
		}
		return false;
	}
	void print_file(char* b) {
		parent->print_file(b);
	}
	void print_console() {
		parent->print_console();
	}
private:
	class Node {
	public:
		Node(T x) :k(x), l(nullptr), r(nullptr) {}
		void add(T x) { // Добавление элемента
			if (x < k) { // Если нововведенный элемент x меньше чем элемент k из семечка дерева, уходим влево
				if (l != nullptr) l->add(x); // Вставляем элемент на свободный участок
				if (l == nullptr) l = new Node(x); // Выделяем память левому подзвену
			}
			if (x > k) { // Иначе идем вправо
				if (r != nullptr) r->add(x);
				if (r == nullptr) r = new Node(x);
			}
		}
			bool search(T x){ // Поиск элемента
			if (x == k) {return true;}
			if (x > k){ if (r != nullptr) return(r->search(x)); // Идем в правую сторону и ищем элемент
			if (x < k){ if (l != nullptr) return(l->search(x)); // Идем в левую сторону
			return false;
			}
		void print_console() {
			if (l != nullptr) l->print_console();
			cout << k << " ";
			if (r != nullptr) r->print_console();
		}
		void print_file(char *b) {
			ofstream fout;
			fout.open(b, ios::app);
			if (fout.is_open()) {
				if (l != nullptr) l->print_file(b);
				fout << k << " "; fout.close();
				if (r != nullptr) r->print_file(b);
			}
			fout.close();
		}
	private:
		T k;
		Node *l;
		Node *r;
	};
	Node* parent;
};
