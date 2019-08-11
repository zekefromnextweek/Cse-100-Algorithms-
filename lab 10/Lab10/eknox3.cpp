#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char arr[] = {'A','B','C','D','E','F'};
string a = "",b = "",c = "",d = "",e = "",f="";
struct MinHeap{
	char data;
	size_t q;
	MinHeap *left, *right; //left and right children
	MinHeap(char data, unsigned q){

		left = right = NULL;
		this->data = data;
		this->q = q;

	}
};

struct compare{

	bool operator()(MinHeap* l, MinHeap* r){
		return (l->q > r->q);
	}

};

void print(struct MinHeap* root, string str){

	if(root == NULL)
		return;
	if(root->data != '$'){
		if(root->data == 'A'){
			a += "A:" + str;
		}
		else if(root->data == 'B'){
			b += "B:" + str;
		}
		else if(root->data =='C'){
			c += "C:" + str;
		}
		else if(root->data =='D'){
			d += "D:" + str;
		}
		else if(root->data =='E'){
			e += "E:" + str;
		}
		else if(root->data =='F'){
			f += "F:" + str;
		}
	}
	else {
	print(root->left, str + "0");
	print(root->right, str + "1");
	}
}

void Huffman(char data[], int freq[]){

	struct MinHeap *left, *right, *top;
	priority_queue<MinHeap*, vector<MinHeap*>, compare> H;
	for(int i = 0; i < 6; i++){
		H.push(new MinHeap(data[i], freq[i]));
	}
	while(H.size() != 1){
		left = H.top();
		H.pop();
		right = H.top();
		H.pop();
		top = new MinHeap('$', left->q + right ->q);
		top->left = left;
		top->right = right;
		H.push(top);
	}
	print(H.top(), "");
}

int main(){

	int q[6]; 
	int input;
	for(int i = 0; i < 6; i++){
		cin >> input;
		q[i] = input;
	}
	Huffman(arr ,q);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;
}
