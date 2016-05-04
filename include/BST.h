#ifndef BST_h
#define BST_h
#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class BST;

template <class T>
ostream & operator<<(ostream & out, BST<T> &tree);

template <class T>
ofstream & operator<<(ofstream & fout, BST<T> &tree);

template <class T>
ifstream & operator >> (ifstream & fin, BST<T> &tree);
class Exceptions {
	char* err;
public:
	Exceptions(char* _err);
	char* what();
};

class Uzhe_est : public Exceptions {
public:
	Uzhe_est();
};

class File_Not_Open : public Exceptions {
public:
	File_Not_Open();
};

class Empty_tree : public Exceptions {
public:
	Empty_tree();
};


template <class T>
class BST {
public:
	BST();
	bool add(T x);
	bool search(T x);
	friend ostream & operator<< <>(ostream &out, BST<T> &tree);
	friend ofstream & operator<< <>(ofstream &fout, BST<T> &tree);
	friend ifstream & operator>> <>(ifstream &fin, BST<T> &tree);
private:
	class Node;
	Node* root;
};

template <class T>
class BST<T>::Node {
public:
	Node(T x);
	void add(T x);
	bool search(T x);
	bool print_console();
	bool print_file(ofstream &fout);
private:
	T k;
	Node *l;
	Node *r;
};
