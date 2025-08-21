#include <iostream>
using namespace std;

struct Date{
    int day, month;
};

struct Student{
    string name;
    Date ngaythiTC, ngaythiXS, ngaythiGT, ngaythiKTCT, ngaythiKTS, ngaythiVL1, ngaythiT1;
    int Thechat; int XSTK;
    int GT2; int KTCT;
    int KTS; int VL1TN;
    int THCS2;
};
Student list[101]; int n;

void input(){
    for (int i = 0; i < n; i++){
        cout << "\nNhap ten Sinh vien " << i+1 << ": ";
        cin >> list[i].name;
        cout << "\nNhap ngay thi mon The Chat: " ;
        cin >> list[i].ngaythiTC.day >> list[i].ngaythiTC.month;
        cout << "\nNhap ca thi mon The chat: ";
        cin >> list[i].Thechat;

        cout << "\nNhap ngay thi mon XSTK: " ;
        cin >> list[i].ngaythiXS.day >> list[i].ngaythiXS.month;
        cout << "\nNhap ca thi mon XSTK: ";
        cin >> list[i].XSTK;

		cout << "\nNhap ngay thi mon GT2: " ;
        cin >> list[i].ngaythiGT.day >> list[i].ngaythiGT.month;
        cout << "\nNhap ca thi mon GT2: ";
        cin >> list[i].GT2;

		cout << "\nNhap ngay thi mon KTCT: " ;
        cin >> list[i].ngaythiKTCT.day >> list[i].ngaythiKTCT.month;
        cout << "\nNhap ca thi mon KTCT: ";
        cin >> list[i].KTCT;

		cout << "\nNhap ngay thi mon Ki thuat so: ";
		cin >> list[i].ngaythiKTS.day >> list[i].ngaythiKTS.month;
		cout << "\nNhap ca thi mon KTS: ";
		cin >> list[i].KTS;

		cout << "\nNhap ngay thi mon Vat ly 1: " ;
        cin >> list[i].ngaythiVL1.day >> list[i].ngaythiVL1.month;
        cout << "\nNhap ca thi mon Vat ly 1: ";
        cin >> list[i].VL1TN;

		cout << "\nNhap ngay thi mon Tin hoc co so 2: " ;
        cin >> list[i].ngaythiT1.day >> list[i].ngaythiT1.month;
        cout << "\nNhap ca thi mon Tin hoc co so 2: ";
        cin >> list[i].THCS2;
    }
}

void output(){
	for (int i = 0; i < n;i ++){
		cout << "Sinh vien " << list[i].name << endl << endl;
		cout << "Mon The Chat:\n";
		cout << "Ngay " << list[i].ngaythiTC.day << " " << list[i].ngaythiTC.month << " 2025 thi ca " << list[i].Thechat << endl;
		cout << "Mon Xac suat thong ke:\n";
		cout << "Ngay " << list[i].ngaythiXS.day << " " << list[i].ngaythiXS.month << " 2025 thi ca " << list[i].XSTK << endl;
		cout << "Mon Giai tich 2:\n";
		cout << "Ngay " << list[i].ngaythiGT.day << " " << list[i].ngaythiGT.month << " 2025 thi ca " << list[i].GT2 << endl;
		cout << "Mon Kinh te chinh tri:\n";
		cout << "Ngay " << list[i].ngaythiKTCT.day << " " << list[i].ngaythiKTCT.month << " 2025 thi ca " << list[i].KTCT << endl;
		cout << "Mon Ki thuat so:\n";
		cout << "Ngay " << list[i].ngaythiKTS.day << " " << list[i].ngaythiKTS.month << " 2025 thi ca " << list[i].KTS << endl;
		cout << "Mon Vat ly 1:\n";
		cout << "Ngay " << list[i].ngaythiVL1.day << " " << list[i].ngaythiVL1.month << " 2025 thi ca " << list[i].VL1TN << endl;
		cout << "Mon Tin hoc co so 2:\n";
		cout << "Ngay " << list[i].ngaythiT1.day << " " << list[i].ngaythiT1.month << " 2025 thi ca " << list[i].THCS2 << endl;
		cout << "----------------\n";
	}
}

void search1(int a){
	cout << "- Ca " << a << ":\n";
	int found = 0;
	for (int i = 0; i < n; i++){
		if (list[i].Thechat == a){
			cout << "--" << list[i].name << " (" << list[i].ngaythiTC.day << "/" << list[i].ngaythiTC.month << "/2025)\n";
			found = 1;
		}
	}
	if (!found) cout << "Not Found!\n";
}

void searchTC(){
	cout << "Mon the chat 2:\n";
	search1(1);
	search1(2);
	search1(3);
	search1(4);
}

void search3(int a){
	cout << "- Ca " << a << ":\n";
	int found = 0;
	for (int i = 0; i < n; i++){
		if (list[i].XSTK == a){
			cout << "--" << list[i].name << " (" << list[i].ngaythiXS.day << "/" << list[i].ngaythiXS.month << "/2025)\n";
			found = 1;
		}
	}
	if (!found) cout << "Not Found!\n";
}

void searchXS(){
	cout << "Mon Xac suat  thong ke:\n";
	search3(1);
	search3(2);
	search3(3);
	search3(4);
}

void search2(int a){
	cout << "- Ca " << a << ":\n";
	int found = 0;
	for (int i = 0; i < n; i++){
		if (list[i].GT2 == a){
			cout << "--" << list[i].name << " (" << list[i].ngaythiGT.day << "/" << list[i].ngaythiGT.month << "/2025)\n";
			found = 1;
		}
	}
	if (!found) cout << "Not Found!\n";
}

void searchGT(){
	cout << "Mon Giai tich 2:\n";
	search2(1);
	search2(2);
	search2(3);
	search2(4);
}

void search4(int a){
	cout << "- Ca " << a << ":\n";
	int found = 0;
	for (int i = 0; i < n; i++){
		if (list[i].KTCT == a){
			cout << "--" << list[i].name << " (" << list[i].ngaythiKTCT.day << "/" << list[i].ngaythiKTCT.month << "/2025)\n";
			found = 1;
		}
	}
	if (!found) cout << "Not Found!\n";
}

void searchKTCT(){
	cout << "Mon Kinh te chinh tri:\n";
	search4(1);
	search4(2);
	search4(3);
	search4(4);
}

void search5(int a){
	cout << "- Ca " << a << ":\n";
	int found = 0;
	for (int i = 0; i < n; i++){
		if (list[i].KTS == a){
			cout << "--" << list[i].name << " (" << list[i].ngaythiKTS.day << "/" << list[i].ngaythiKTS.month << "/2025)\n";
			found = 1;
		}
	}
	if (!found) cout << "Not Found!\n";
}

void searchKTS(){
	cout << "Mon Ky thuat so:\n";
	search5(1);
	search5(2);
	search5(3);
	search5(4);
}

void search6(int a){
	cout << "- Ca " << a << ":\n";
	int found = 0;
	for (int i = 0; i < n; i++){
		if (list[i].VL1TN == a){
			cout << "--" << list[i].name << " (" << list[i].ngaythiVL1.day << "/" << list[i].ngaythiVL1.month << "/2025)\n";
			found = 1;
		}
	}
	if (!found) cout << "Not Found!\n";
}

void searchVL(){
	cout << "Mon Vat ly 1 va thi nghiem:\n";
	search6(1);
	search6(2);
	search6(3);
	search6(4);
}

void search7(int a){
	cout << "- Ca " << a << ":\n";
	int found = 0;
	for (int i = 0; i < n; i++){
		if (list[i].THCS2 == a){
			cout << "--" << list[i].name << " (" << list[i].ngaythiT1.day << "/" << list[i].ngaythiT1.month << "/2025)\n";
			found = 1;
		}
	}
	if (!found) cout << "Not Found!\n";
}

void searchTHCS(){
	cout << "Mon Tin hoc co so 2:\n";
	search7(1);
	search7(2);
	search7(3);
	search7(4);
}

int main(){
    cout << "Nhap so luong sinh vien: ";
    cin >> n; cout << endl;
    input();
	cout << "\n";
	cout << "================================\n";
	 output();
	cout << "================================\n";
	searchTC();
	searchXS();
	searchGT();
	searchKTCT();
	searchKTS();
	searchVL();
	searchTHCS();
	return 0;
}