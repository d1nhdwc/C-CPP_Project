#include <iostream>
#include <math.h>
using namespace std;

/* LUU Y
- 1 nam = 365 ngay
- 1 thang = 30 ngay
- 1 tuan = 7 ngay 
*/

int main(){
	int ng, tu, t, n;
	cout << "Nhap so ngay: ";
	cin >> ng;
	n = ng%365;
	t = ng%30;
	tu = ng%7;
	if ( ng<7 && ng >0 ){ //So ngay
		cout << ng <<" ngay"<< endl;
	} 
	else if ( ng>=7 && ng<30 ){ //So tuan
		if ( tu==0 ){
			cout << ng/7 <<" tuan\n";
		}else{
			cout << ng/7 << " tuan " << tu << " ngay" << endl;
		}
	}
	else if ( ng>=30 && ng<365 ){ //So thang
		if ( t == 0 ){
			cout << ng/30 << " thang\n" ;
		}else if( t<7){
			cout << ng/30 << " thang " << t << " ngay" << endl;
		}else if( t%7==0 ){
			cout << ng/30 << " thang " << t/7 << " tuan\n";
		}else{
			cout << ng/30 << " thang " << t/7 << " tuan " << t%7 << " ngay" << endl;
		}
	}
	else{
		if ( ng<= 0 ){
			cout <<"So ngay khong hop le\n";
		}else{
			if ( n==0 ){
				cout << ng/365 <<" nam\n";
			}
			else if( n<7 ){
				cout << ng/365 <<" nam "<<n<<" ngay\n";
			}
			else if( n>=7 && n<30 ){
				if ( n%7==0 ){
					cout << ng/365 <<" nam "<<n/7<<" tuan\n";
				}else{
					cout << ng/365 << " nam " << n/7 << " tuan " << n%7 << " ngay" << endl;
				}
			}
			else if ( n>=30 && n<365 ){ 
				if ( n%30==0 ){
					cout << ng/365 << " nam " << n/30 << " thang\n" ;
				}else if( n%30<7 ){
					cout << ng/365 << " nam " << n/30 << " thang " << n%30 << " ngay\n";
				}else if( (n%30)%7==0 ){
					cout << ng/365 << " nam " << n/30 << " thang " << (n%30)/7 << " tuan\n";
				}else{
					cout << ng/365 << " nam " << n/30 << " thang " << (n%30)/7 << " tuan " << (n%30)%7 << " ngay\n";
				}
			}
		}
	}	
	return 0;
}








