#include <BST.cpp>
#include <catch.hpp>
#include <fstream>
#include <iostream>
using namespace std;

SCENARIO("Add_int", "[add]") {
	BST<int> tree;
	REQUIRE(tree.add(7));
	REQUIRE(tree.add(3));
	REQUIRE(tree.add(5));
	REQUIRE(tree.search(3));
	REQUIRE(tree.search(5));
	REQUIRE(tree.search(7));
}

SCENARIO("Add_char", "[add_c]") {
	BST<char> tree;
	REQUIRE(tree.add(5));
	REQUIRE(tree.add(4));
	REQUIRE(tree.add(6));
	REQUIRE(tree.search(4));
	REQUIRE(tree.search(5));
	REQUIRE(tree.search(6));
}

SCENARIO("Add_double", "[add_d]") {
	BST<double> tree;
	REQUIRE(tree.add(7.62));
	REQUIRE(tree.add(3.14));
	REQUIRE(tree.add(5.85));
	REQUIRE(tree.search(3.14));
	REQUIRE(tree.search(5.85));
	REQUIRE(tree.search(7.62));
}

SCENARIO("Search_int", "[search_i]") {
	BST<int> tree;
	tree.add(7);
	tree.add(5);
	tree.add(1);
	tree.add(9);
	tree.add(3);
	REQUIRE(tree.search(7));
	REQUIRE(tree.search(9));
	REQUIRE(tree.search(5));
	REQUIRE(tree.search(1));
	REQUIRE(tree.search(3));
	REQUIRE(!tree.search(0));
	REQUIRE(!tree.search(8));
	REQUIRE(!tree.search(6));
	REQUIRE(!tree.search(4));
	REQUIRE(!tree.search(2));
}

SCENARIO("Search_char", "[search_c]") {
	BST<char> tree;
	tree.add(7);
	tree.add(5);
	tree.add(1);
	tree.add(9);
	tree.add(3);
	REQUIRE(tree.search(7));
	REQUIRE(tree.search(9));
	REQUIRE(tree.search(5));
	REQUIRE(tree.search(1));
	REQUIRE(tree.search(3));
	REQUIRE(!tree.search(0));
	REQUIRE(!tree.search(8));
	REQUIRE(!tree.search(6));
	REQUIRE(!tree.search(4));
	REQUIRE(!tree.search(2));
}

SCENARIO("Search_double", "[search_d]") {
	BST<double> tree;
	tree.add(7.77);
	tree.add(5.85);
	tree.add(1.29);
	tree.add(9.999);
	tree.add(3.14);
	REQUIRE(tree.search(7.77));
	REQUIRE(tree.search(9.999));
	REQUIRE(tree.search(5.85));
	REQUIRE(tree.search(1.29));
	REQUIRE(tree.search(3.14));
	REQUIRE(!tree.search(0.5));
	REQUIRE(!tree.search(8.800));
	REQUIRE(!tree.search(6.666));
	REQUIRE(!tree.search(4.13));
	REQUIRE(!tree.search(2.34));
}

SCENARIO("Read_int", "[read_i]") {
	BST<int> tree; ifstream fin("read.txt");
	fin >> tree;
	fin.close();
	REQUIRE(tree.search(7));
	REQUIRE(tree.search(9));
	REQUIRE(tree.search(5));
	REQUIRE(tree.search(1));
	REQUIRE(tree.search(3));
}

SCENARIO("Read_double", "[read_d]") {
	BST<double> tree; ifstream fin("read_double.txt");
	fin >> tree;
	fin.close();
	REQUIRE(tree.search(12.74));
	REQUIRE(tree.search(15.62));
	REQUIRE(tree.search(7.62));
	REQUIRE(tree.search(3.14));
	REQUIRE(tree.search(8.34));
	REQUIRE(tree.search(25.15));
	REQUIRE(tree.search(17.16));
}

SCENARIO("Print_int", "[print_file_i]") {
	BST<int> tree, tree_2; ofstream fout("print.txt", ios::app);
	tree.add(7);
	tree.add(3);
	tree.add(5);
	fout << tree; fout << -1;
	fout.close();
	ifstream fin("print.txt");
	fin >> tree_2;
	fin.close();
	REQUIRE(tree_2.search(7));
	REQUIRE(tree_2.search(3));
	REQUIRE(tree_2.search(5));
}

SCENARIO("Print_file_double", "[print_file_d]") {
	BST<double> tree, tree_2; ofstream fout("print_double.txt", ios::app);
	tree.add(7.77);
	tree.add(3.33);
	tree.add(5.55);
	fout << tree; fout << -1;
	fout.close();
	ifstream fin("print_double.txt");
	fin >> tree_2;
	fin.close();
	REQUIRE(tree_2.search(7.77));
	REQUIRE(tree_2.search(3.33));
	REQUIRE(tree_2.search(5.55));
}


SCENARIO("Print_console_int", "[print_console_i]") {
	BST<int> tree;
	tree.add(7);
	tree.add(3);
	tree.add(5);
	REQUIRE(cout << tree);
}

SCENARIO("Print_console_char", "[print_console_c]") {
	BST<char> tree;
	tree.add(7);
	tree.add(3);
	tree.add(5);
	REQUIRE(cout << tree);
}

SCENARIO("Print_console_double", "[print_console_d]") {
	BST<double> tree;
	tree.add(7);
	tree.add(3);
	tree.add(5);
	REQUIRE(cout << tree);
}

SCENARIO("Iscl_add", "[I_a]") {
	BST<int> tree; int G = 0;
	tree.add(1);
	try { tree.add(1); }
	catch (Already_add &e) { G++; }
	REQUIRE(G == 1);
}

SCENARIO("Iscl_not_open", "[I_no]") {
	BST<int> tree; int G = 0; ifstream fin("kek");
	try { fin >> tree; }
	catch (File_Not_Open &e) { G++; }
	REQUIRE(G == 1);
}

SCENARIO("Iscl_pust1", "[I_p1]") {
	BST<int> tree; int G = 0;
	try { cout << tree; }
	catch (Empty_tree &e) { G++; }
	REQUIRE(G == 1);
}

SCENARIO("Iscl_pust2", "[I_p2]") {
	BST<int> tree; int G = 0; ofstream fout("print_double.txt", ios::app);
	try { fout << tree; }
	catch (Empty_tree &e) { G++; }
	fout.close();
	REQUIRE(G == 1);
}
