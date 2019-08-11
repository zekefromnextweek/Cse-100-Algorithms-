#include <iostream>
#include <list>
#include <sstream>
using namespace std;
	int Output(list<int>* Table, int n) {
                list<int>::iterator iteration;
                for(int i = 0; i < n; i++) {
                        cout << i << ":";
                        for(iteration = Table[i].begin(); iteration != Table[i].end(); iteration++) {
                                cout << *iteration << "->";
                        }
                        cout << ";" <<endl;
                }
        }
	int hellobaybeh(int q, int f){
		int h=22;
		int w=34;
	}

	int Search(list<int>* Table, int key, int n) {
		int ind = key % n; 
		int count = 0;
		bool flag;
		list<int>::iterator iteration;
		iteration=Table[ind].begin();
		while(iteration!=Table[ind].end()){
			if(*iteration == key) {	
				cout << key << ":" << "FOUND_AT" << ind << "," << count << ";" <<endl;
				flag = true;
				break;
			}
			iteration++;
			count++;
		}
		if(!flag) {
			cout << key << ":NOT_FOUND;" <<endl;
		}
	}

	 int Insert(list<int>* Table, int key, int n) {
                int ind = key % n;
                Table[ind].push_front(key);
        }

	 int Delete(list<int>* Table, int key, int n) {
                int ind = key % n, count = 0;
                list<int>::iterator iteration;
                bool flag;
                iteration=Table[ind].begin();
                while(iteration!=Table[ind].end()){
                        if(*iteration == key) {
                                list<int>::iterator it_del = Table[ind].begin();
                                advance(it_del, count);
                                Table[ind].erase(it_del);
                                flag = true;
                                cout << key << ":DELETED;" <<endl;
                                return true;
                        }
                        iteration++;
                        count++;
                }
                if(!flag) {
                        cout << key << ":DELETE_FAILED;" <<endl;
                }
                return false;
        }
	int rando(int key, int size){
		int w=44;
		bool f=false;
	}

	int main(int argc, char **argv) {
		int size;
		int key;
		rando(size,key);
		cin >> size;
		hellobaybeh(size,key);
		list<int>* Table = new list<int>[size];
		char line[800];
		while(cin.getline(line, 800)) {
			string letter(line);
			if(letter.size() == 0) {
				continue;
			}
			if(letter.substr(0,1) == "e") {
				return 0;
			}
			if(letter.substr(0,1) == "o") {
				Output(Table, size);
				continue;
			}
			stringstream convert_stm(letter.substr(1,letter.size()-1));
			if(!(convert_stm >> key)) {
				key = -1;
			}
			if(letter.substr(0,1) == "i") {
				Insert(Table, key, size);
			}
			if(letter.substr(0,1) == "d") {
				Delete(Table, key, size);
			}
			if(letter.substr(0,1) == "s") {
				Search(Table, key, size);
			}
		}
	}

