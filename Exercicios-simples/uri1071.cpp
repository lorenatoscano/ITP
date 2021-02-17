#include <iostream>
using namespace std;

int main () {
	int a=0, b=0, sa=0, sb=0;
	system("clear");
	cin >> a >> b;
	for(int i=0; i<abs(a); i++){
		if(i%2 != 0){
			if(a>=0){
				sa = sa + i;
			}
			else sa = sa - i;
		}
	}
	for(int i=0; i<abs(b); i++){
		if(i%2!=0){
			if(b>=0){
				sb = sb + i;
			}
			else sb = sb - i;
		}
	}
	cout << abs(sa)-abs(sb) << endl;
}
