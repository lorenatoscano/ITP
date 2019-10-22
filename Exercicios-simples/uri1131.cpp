#include <iostream>
using namespace std;

int main () {
	int check=1, vg=0, vi=0, pg=0, pi=0, em=0, i=0;
	while (check != 2) {
		cin >> pi >> pg; 
		if(pi>pg) {
			vi++;
		}
		else if (pg>pi) {
			vg++;
		}
		else {
			em++;
		}
		cout << "Novo grenal (1-sim 2-nao)" << endl;
		cin >> check;
		i++;
	}	
	cout << i << " grenais\nInter:" << vi << endl << "Gremio:" << vg << endl << "Empates:" << em << endl;
	if (vi > vg) {
		cout << "Inter venceu mais\n";
	}
	else if(vg > vi){
		cout << "Gremio venceu mais\n";
	}
}
