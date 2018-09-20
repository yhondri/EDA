#include "TreeMap.h"
#include "AvlTreeMap.h"
#include "HashMap.h"

using namespace std;

template<class K,class V>
void listAlphabetically(TreeMap<K,V>& map, ostream& out){
	typename TreeMap<K,V>::ConstIterator it = map.cbegin();
	out << "{";
	if (it != map.cend()){
		out << "(" << it.key() << "," << it.value() << ")";
		it.next();
	}
	while (it != map.cend()){
		out << ",(" << it.key() << "," << it.value() << ")";
		it.next();
	}
	out << "}\n";
}

template<class K,class V>
void listAlphabetically(HashMap<K,V>& map, ostream& out){
	typename HashMap<K,V>::ConstIterator it = map.cbegin();
	out << "{";
	if (it != map.cend()){
		out << "(" << it.key() << "," << it.value() << ")";
		it.next();
	}
	while (it != map.cend()){
		out << ",(" << it.key() << "," << it.value() << ")";
		it.next();
	}
	out << "}\n";
}


void testTreeMap(){
	char op;
	char c; int n;
	TreeMap<char,int> map;
	do{
		cout << "Choose option ((i)nsert, (g)et, (r)emove, (l)ist alphabetically, (e)xit) " << endl;
		cin >> op;
		if (op == 'i'){
			cin >> c; cin >> n;
			map.insert(c,n);
		} else if (op == 'g'){
			cin >> c;
			try {
				n = map.at(c);
				cout << n << endl;
			} catch (EClaveErronea& e){
				cout << "Key " << c << " not found" << endl;
			}
		} else if (op == 'r') {
			cin >> c;
			map.erase(c);
		} else if (op == 'l') {
			listAlphabetically(map,cout);
		}
	} while (op != 'e');
	cout << "Program finished" << endl;
}

void testAVLTreeMap(){
	char op;
	char c; int n;
	AvlTreeMap<char,int> map;
	do{
		cout << "Choose option ((i)nsert, (g)et, (r)emove, (p)rint, (e)xit) " << endl;
		cin >> op;
		if (op == 'i'){
			cin >> c; cin >> n;
			map.insert(c,n);
		} else if (op == 'g'){
			cin >> c;
			try {
				n = map.at(c);
				cout << n << endl;
			} catch (EClaveErronea& e){
				cout << "Key " << c << " not found" << endl;
			}
		} else if (op == 'r') {
			cin >> c;
			map.erase(c);
		} else if (op == 'p') {
			map.print(cout);
		}
	} while (op != 'e');
	cout << "Program finished" << endl;
}

void testHashMap(){
	char op;
	char c; int n;
	HashMap<char,int> map;
	do{
		cout << "Choose option ((i)nsert, (g)et, (r)emove, (l)ist alphabetically, (e)xit) " << endl;
		cin >> op;
		if (op == 'i'){
			cin >> c; cin >> n;
			map.insert(c,n);
		} else if (op == 'g'){
			cin >> c;
			try {
				n = map.at(c);
				cout << n << endl;
			} catch (EClaveErronea& e){
				cout << "Key " << c << " not found" << endl;
			}
		} else if (op == 'r') {
			cin >> c;
			map.erase(c);
		} else if (op == 'l') {
			listAlphabetically(map,cout);
		}
	} while (op != 'e');
	cout << "Program finished" << endl;
}

int main(){
	testTreeMap();
	//testAVLTreeMap();
	//testHashMap();
	return 0;
}
