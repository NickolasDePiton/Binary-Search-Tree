#include <iostream>
#include <fstream>
using namespace std;

class BinarySearchTree{
public:
	BinarySearchTree() :root(nullptr){}
	bool add(int x){
		if (root == nullptr) { root = new der(x); return true; }
		else { root->add(x); return true; }
		return false;
	}
	bool search(int x){ return(root->search(x)); }
	bool read_file(char* a){
		ifstream fin; int x;
		fin.open(a);
		if (fin.is_open()){
			while (!fin.eof()){
				fin >> x;
				this->add(x);
			}
			fin.close();
			return true;
		}
		return false;
	}
	void print_file(char* b){
		root->print_file(b);
	}
	void print_console(){
		root->print_console();
	}
private:
	class der{
	public:
		der(int x) :D(x), l(nullptr), r(nullptr){}
		void add(int x){
			if (x < D){ 
				if (l != nullptr) l->add(x);
				if (l == nullptr) l = new der(x); 
			}
			if (x>D){
				if (r != nullptr) r->add(x);
				if (r == nullptr) r = new der(x);
			}
		}
		bool search(int x){
			if (x == D) return true;
			if (x < D){ if (l != nullptr) l->search(x); else return false; }
			if (x > D){ if (r != nullptr) r->search(x); else return false; }
			}
		void print_console(){
			if (l != nullptr) l->print_console();  
			cout << D << " ";
			if (r != nullptr) r->print_console();  
		}
		void print_file(char *b){
			ofstream fout;
			fout.open(b, ios::app);
			if (fout.is_open()){
				if (l != nullptr) l->print_file(b);
				fout << D << " "; fout.close();
				if (r != nullptr) r->print_file(b);
			}
			fout.close();
		}
	private:
		int D;
		der *l;
		der *r;
	};
	der* root;
};



int main(){
	BinarySearchTree tree; int J;
	cout << "add-1, search-2, read_f-3, print_f-4, print_c-5, exit-0\n";
	do{
		cout << "J="; cin >> J;
		if (J == 1){
			int x;
			cout << "x="; cin >> x;
			if(tree.add(x))cout<<"done\n";
		}
		if (J == 2){
			int x;
			cout << "x="; cin >> x;
			if (tree.search(x)) cout << "founded\n"; else cout << "not founded\n";
		}
		if (J == 3){
			char a[20];
			cout << "name of file: "; cin >> a;
			if (tree.read_file(a)) cout << "done\n";
		}
		if (J == 4){
			char b[20];
			cout << "name of file: "; cin >> b;
			tree.print_file(b);
		}
		if (J == 5){
			tree.print_console(); cout << endl;
		}
	} while (J);
	system("pause");
}
