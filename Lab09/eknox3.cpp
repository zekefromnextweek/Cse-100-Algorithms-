#include <iostream> 
#include <vector> 
#include <climits>//found this on c++ references
using namespace std; 
void MatrixChainOrder(int *p, int n); 
int main(){
        int  z = 0;
        cin >> z;
        int p[z+1];
        for(int i = 0; i <= z;i++) {
                cin >> p[i];
        }
        MatrixChainOrder(p, z);
}
void PrintOptimalParens(vector< vector<int> > &s, int i, int j) {
        if(i == j) {
                cout << "A" << (i-1);
        } else {
                cout << "(";
                PrintOptimalParens(s,i,s[i][j]);
                PrintOptimalParens(s,s[i][j]+1,j);
                cout << ")";
        }
}
void MatrixChainOrder(int * p, int n) {
	int i;
	int j;
	int k;
	int length;
	int q;
	int m[n+1][n+1];
	vector <vector<int> > v;
	v.resize(n+1, vector<int>(n+1,0));
	for(i = 1; i <= n; i++){
		m[i][i] = 0;
	}
	for(length = 2; length <= n; length++) {
		for(i = 1; i <= n - length +1; i++) {
			j = i + length -1;
			m[i][j] = INT_MAX;
			for(k = i; k <= j - 1; k++) {
				q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
				if(q < m[i][j]) {
					m[i][j] = q;
					v[i][j] = k;
				}
			}
		}
	}
	cout << m[1][n] <<endl;
	PrintOptimalParens(v,1,n);
	cout<<endl;
}
