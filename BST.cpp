#include <iostream>
#include <fstream>
using namespace std;

class BST {
public:
	BST() :parent(nullptr) {}
	bool add(int x) { // Добавление элемента
		if (parent == nullptr) { parent = new Tree(x); return true; }
		else { parent->add(x); return true; }
		return false;
	}
	bool search(int x) { return(parent->search(x)); } // Поиск
	bool read_file(char* a) { // Чтение из файла
		ifstream fin; int x;
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
	class Tree {
	public:
		Tree(int x) :k(x), l(nullptr), r(nullptr) {}
		void add(int x) { // Добавление элемента
			if (x < k) { // Если нововведенный элемент x меньше чем элемент k из семечка дерева, уходим влево
				if (l != nullptr) l->add(x); // Вставляем элемент на свободный участок
				if (l == nullptr) l = new Tree(x); // Выделяем память левому подзвену
			}
			if (x > k) { // Иначе идем вправо
				if (r != nullptr) r->add(x);
				if (r == nullptr) r = new Tree(x);
			}
		}
			bool search(int x){ // Поиск элемента
			if (x == k) return true;
			if (x < k){ if (l != nullptr) l->search(x); else return false; } // Идем в левую сторону и ищем элемент
			if (x > k){ if (r != nullptr) r->search(x); else return false; } // Идем в правую
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
		int k;
		Tree *l;
		Tree *r;
	};
	Tree* parent;
};
