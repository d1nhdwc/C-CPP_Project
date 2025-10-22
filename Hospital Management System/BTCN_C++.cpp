#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <map>
#include <windows.h>
#include <limits>
using namespace std;

string red = "\033[31m";
string green = "\033[32m";
string lgreen = "\033[38;5;120m";
string yellow = "\033[33m";
string blue = "\033[34m";
string magenta = "\033[35m";
string cyan = "\033[36m";
string bold = "\033[1m";
string reset = "\033[0m";

void Menu() {
    system("cls");
    cout << "#=============================================================================#\n";
    cout << bold << green << "  _   _                 _ _        _   __  __                             \n";
    cout << " | | | | ___  ___ _ __ (_) |_ __ _| | |  \\/  | __ _ _ __   __ _  __ _  ___ _ __ \n";
    cout << " | |_| |/ _ \\/ __| '_ \\| | __/ _` | | | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '__|\n";
    cout << " |  _  | (_) \\__ \\ |_) | | || (_| | | | |  | | (_| | | | | (_| | (_| |  __/ | \n";
    cout << " |_| |_|\\___/|___/ .__/|_|\\__\\__,_|_| |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_|\n";
    cout << "                 |_|                                            |___/   \n" << reset;
    cout << "#=============================================================================#\n";
    cout << bold << blue << "                        + Hospital Management System +\n" << reset;
    cout << "|-----------------------------------------------------------------------------|\n";
    cout << yellow << "  1) Patient\n" << reset;
    cout << cyan << "  2) Doctor\n" << reset;
    cout << lgreen << "  3) Statics\n" << reset;
    cout << red << "  0) Exit\n" << reset;
    cout << "|--------------------------------------------|\n";
}

void init_Patient() {
    cout << "#=============================#\n";
    cout << bold << yellow << "   ___       __  _          __" << endl;
    cout << "  / _ \\___ _/ /_(_)__ ___  / /_" << endl;
    cout << " / ___/ _ `/ __/ / -_) _ \\/ __/" << endl;
    cout << "/_/   \\_,_/\\__/_/\\__/_//_/\\__/ " << reset << endl;
    cout << "#=============================#\n";
}

void end_Patient() {
    cout << " 1) Them benh nhan\n";
    cout << " 2) Danh sach benh nhan\n";
    cout << " 3) Tim kiem benh nhan bang ID\n";
    cout << " 4) Xoa benh nhan bang ID\n";
    cout << " 5) Cap nhat thong tin benh nhan\n";
    cout << red << " 0) Back to menu\n" << reset;
    cout << "|---------------------------|\n";
}

void init_Doctor() {
    cout << "#===========================#\n";
    cout << bold << cyan << "   ___           __\n";
    cout << "  / _ \\___  ____/ /____  ____\n";
    cout << " / // / _ \\/ __/ __/ _ \\/ __/\n";
    cout << "/____/\\___/\\__/\\__/\\___/_/ \n" << reset;
    cout << "#===========================#\n";
}

void end_Doctor() {
    cout << " 1) Them bac si\n";
    cout << " 2) Danh sach bac si\n";
    cout << " 3) Tim kiem bac si bang ID\n";
    cout << " 4) Xoa bac si bang ID\n";
    cout << " 5) Cap nhat thong tin bac si\n";
    cout << red << " 0) Back to menu\n" << reset;
    cout << "|---------------------------|\n";
}

void init_TK() {
    cout << "#====================================#\n";
    cout << bold << lgreen << "   ______       __  _     __  _\n";
    cout << "  / __/ /____ _/ /_(_)__ / /_(_)_______\n";
    cout << " _\\ \\/ __/ _ `/ __/ (_-</ __/ / __(_-<\n";
    cout << "/___/\\__/\\_,_/\\__/_/___/\\__/_/\\__/___/\n" << reset;
    cout << "#====================================#\n";
}

void end_TK() {
    cout << " 1) Thong ke tong quan benh nhan\n";
    cout << " 2) Liet ke benh nhan dang dieu tri\n";
    cout << " 3) Liet ke benh nhan da ra vien\n";
    cout << " 4) Liet ke benh nhan theo loai benh\n";
    cout << " 5) Thong ke tong quan bac si\n";
    cout << " 6) Liet ke bac si theo chuyen khoa\n";
    cout << red << " 0) Back to menu\n" << reset;
    cout << "|------------------------------------|\n";
}

class Doctor {
private:
    static int nextIDd;
    int ID;
    string name, gender; int age;
    string speci, number, work;
public:
    Doctor() { ID = nextIDd++; }
    void setName(const string& n) { name = n; }
    void setGender(const string& g) { gender = g; }
    void setAge(int a) { age = a; }
    void setSpeci(const string& s) { speci = s; }
    void setNumber(const string& n) { number = n; }
    void setWork(const string& w) { work = w; }
    string getName() const { return name; }
    string getGender() const { return gender; }
    int getAge() const { return age; }
    string getSpeci() const { return speci; }
    string getNumber() const { return number; }
    string getWork() const { return work; }
    void Add();
    void Show();
    string getID() const {
        string se;
        stringstream out;
        out << "BS" << setfill('0') << setw(4) << ID;
        se = out.str();
        return se;
    }
    string toString() const {
        stringstream ss;
        ss << getID() << "|" << name << "|" << gender << "|" << age << "|" << speci << "|" << number << "|" << work;
        return ss.str();
    }

    static Doctor fromString(const string& line) {
        Doctor d;
        stringstream ss(line);
        string token;
        vector<string> parts;
        while (getline(ss, token, '|')) parts.push_back(token);
        if (parts.size() == 7) {
            // parts[0] is like "BS0001" -> lấy phần số
            string idStr = parts[0];
            if (idStr.size() > 2 && idStr.substr(0, 2) == "BS") {
                try {
                    d.ID = stoi(idStr.substr(2));
                }
                catch (...) {
                    d.ID = nextIDd++;
                }
            }
            else {
                d.ID = nextIDd++;
            }
            d.name = parts[1];
            d.gender = parts[2];
            d.age = stoi(parts[3]);
            d.speci = parts[4];
            d.number = parts[5];
            d.work = parts[6];
            if (nextIDd <= d.ID) nextIDd = d.ID + 1;
        }
        return d;
    }

};

class Patient {
private:
    static int nextIDp;
    int ID;
    string name, gender; int age;
    string address, inDay, outDay, disaster;
    string doctorID;
public:
    Patient() {
        ID = nextIDp++;
        doctorID = "-1";
    }
    void Add(const vector<Doctor> &doctors);
    void Show(const vector<Doctor> &doctors) const;
    void setName(const string& n) { name = n; }
    void setGender(const string& g) { gender = g; }
    void setAge(int a) { age = a; }
    void setAddress(const string& a) { address = a; }
    void setInDay(const string& d) { inDay = d; }
    void setOutDay(const string& d) { outDay = d; }
    void setDisaster(const string& d) { disaster = d; }
    string getName() const { return name; }
    string getGender() const { return gender; }
    int getAge() const { return age; }
    string getAddress() const { return address; }
    string getInDay() const { return inDay; }
    string getOutDay() const { return outDay; }
    string getDisaster() const { return disaster; }
    string getID() const{
        string se;
        stringstream out;
        out << "BN" << setfill('0') << setw(4) << ID;
        se = out.str();
        return se;
    }
    string toString() const {
        stringstream ss;
        ss << getID() << "|" << name << "|" << gender << "|" << age << "|" << address << "|" << inDay << "|" << outDay << "|" << disaster << "|" << doctorID;
        return ss.str();
    }
    static Patient fromString(const string& line) {
        Patient p;
        stringstream ss(line);
        string token;
        vector<string> parts;
        while (getline(ss, token, '|')) parts.push_back(token);
        if (parts.size() >= 9) {
            string idStr = parts[0];
            if (idStr.size() > 2 && idStr.substr(0, 2) == "BN") {
                try {
                    p.ID = stoi(idStr.substr(2));
                }
                catch (...) {
                    p.ID = nextIDp++;
                }
            }
            else {
                p.ID = nextIDp++;
            }
            p.name = parts[1];
            p.gender = parts[2];
            p.age = stoi(parts[3]);
            p.address = parts[4];
            p.inDay = parts[5];
            p.outDay = parts[6];
            p.disaster = parts[7];
            p.doctorID = parts[8];
            if (nextIDp <= p.ID) nextIDp = p.ID + 1;
        }
        return p;
    }
};

int Patient::nextIDp = 1;

void Patient::Add(const vector<Doctor>& doctors) {
    system("cls");
    init_Patient();
    cin.ignore();
    cout << cyan << "-- Moi ban nhap benh nhan: --\n" << reset;
    cout << "[+] Nhap ten benh nhan: "; getline(cin, name);
    cout << "[+] Nhap gioi tinh: "; cin >> gender;
    cout << "[+] Nhap tuoi: "; cin >> age;
    cin.ignore();
    cout << "[+] Nhap dia chi thuong tru: "; getline(cin, address);
    cout << "[+] Nhap ngay vao vien: "; cin >> inDay;
    cout << "[+] Nhap ngay ra vien (Neu chua ra vien nhap 'N/A'): "; cin >> outDay;
    cin.ignore();
    cout << "[+] Ten benh ly chan doan: "; getline(cin, disaster);
    if (doctors.empty()) {
        cout << yellow << "=> Hien chua co bac si nao trong he thong, khong the gan bac si phu trach!\n" << reset;
        doctorID = "-1";
    }
    else {
        cout << cyan << "\nDanh sach bac si hien co:\n" << reset;
        for (const auto& doc : doctors) {
            cout << "[" << setw(4) << setfill('0') << doc.getID() << "] "
                << doc.getName() << " - " << doc.getSpeci() << endl;
        }
        cout << "\nNhap ID bac si phu trach: ";
        string id; cin >> id;
        bool found = false;
        for (auto& doc : doctors) {
            if (doc.getID() == id) {
                doctorID = id;
                found = true;
                cout << green << "=> Da gan bac si " << doc.getName() << " phu trach benh nhan.\n" << reset;
                break;
            }
        }
        if (!found) {
            cout << red << "=> ID khong ton tai! Benh nhan chua co bac si phu trach.\n" << reset;
            doctorID = "-1";
        }
    }
    cout << cyan << "-----------------------------\n" << reset;
    end_Patient();
}

void Patient::Show(const vector<Doctor>& doctors) const {
    cout << "[BN" << setfill('0') << setw(4) << ID << "] " << name << endl;
    cout << "- Gioi tinh: " << gender << "     - Tuoi: " << age << endl;
    cout << "- Dia chi thuong tru: " << address << endl;
    cout << "- Ngay vao vien: " << inDay << endl;
    cout << "- Ngay ra vien: " << outDay << endl;
    cout << "- Benh ly chan doan: " << disaster << endl;
    if (doctorID != "-1") {
        auto it = find_if(doctors.begin(), doctors.end(),
            [&](const Doctor& d) { return d.getID() == doctorID; });
        if (it != doctors.end()) {
            cout << "- Bac si phu trach: " << it->getName()
                << " (" << it->getSpeci() << ")\n";
        }
        else {
            cout << "- Bac si phu trach: [Khong ton tai trong danh sach]\n";
        }
    }
    else {
        cout << "- Bac si phu trach: [Chua phan cong]\n";
    }
    cout << endl;
}

void searchP( vector <Patient> &p, vector <Doctor> &d) {
    system("cls");
    init_Patient();
    cout << cyan << "-- Tim kiem benh nhan --\n" << reset;
    string searchID;
    cout << green << "[+] Nhap ID can tim: " << reset;
    cin >> searchID;
    cout << endl;
    bool found = false;
    for (auto& x : p) {
        if (x.getID() == searchID) {
            x.Show(d);
            found = true;
            break;
        }
    }
    if (!found) cout << "=> Khong tim thay benh nhan voi ID nay!" << endl;
    cout << cyan << "-----------------------------\n" << reset;
    end_Patient();
}

void deleteP(vector <Patient> &p, vector <Doctor> &d) {
    system("cls");
    init_Patient();
    cout << cyan << "-- Xoa benh nhan --\n" << reset;
    string delID;
    cout << green << "[+] Nhap ID benh nhan can xoa: " << reset; cin >> delID;
    bool found = false;
    for (auto i = p.begin(); i != p.end(); i++) {
        if (i->getID() == delID) {
            cout << "\n==> Da tim thay benh nhan voi ID: [" << delID << "]" << endl << green << "[+] Thong tin:\n" << reset;
            i->Show(d);
            char confirm;
            cout << red << "Ban co chac muon xoa (y/n)? " << reset;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                p.erase(i);
                cout << "Xoa thanh cong!\n";
                cout << cyan << "-----------------------------\n" << reset;
                end_Patient();
            }
            else {
                cout << "=> Huy thao tac xoa.\n";
                cout << cyan << "-----------------------------\n" << reset;
                end_Patient();
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "=> Khong tim thay benh nhan voi ID nay!" << endl;
        cout << cyan << "-----------------------------\n" << reset;
        end_Patient();
    }
}

void updateP(vector <Patient> &p, vector <Doctor> &d) {
    system("cls");
    init_Patient();
    cout << cyan << "-- Cap nhat thong tin benh nhan --\n" << reset;
    string upID;
    cout << green << "[+] Nhap ID benh nhan can cap nhat: " << reset; cin >> upID;
    bool found = false;
    for (auto& x : p) {
        if (x.getID() == upID) {
            cout << "\n==> Da tim thay benh nhan voi ID: [" << upID << "]" << endl;
            x.Show(d);
            found = true;
            int choice;
            cin.ignore();
            do {
                cout << yellow << "Ban muon cap nhat gi?\n" << reset;
                cout << " 1) Ten\n";
                cout << " 2) Gioi tinh\n";
                cout << " 3) Tuoi\n";
                cout << " 4) Dia chi\n";
                cout << " 5) Ngay vao vien\n";
                cout << " 6) Ngay ra vien\n";
                cout << " 7) Benh ly\n";
                cout << red << " 0) Thoat cap nhat\n" << reset;
                cout << magenta << "> Your Choice: " << reset;
                cin >> choice;
                cin.ignore();
                switch (choice) {
                    case 1: { string n; cout << "Nhap ten moi: "; getline(cin, n); x.setName(n); break; }
                    case 2: { string g; cout << "Nhap gioi tinh moi: "; cin >> g; x.setGender(g); break; }
                    case 3: { int a; cout << "Nhap tuoi moi: "; cin >> a; x.setAge(a); break; }
                    case 4: { string a; cout << "Nhap dia chi moi: "; getline(cin, a); x.setAddress(a); break; }
                    case 5: { string d; cout << "Nhap ngay vao vien moi: "; cin >> d; x.setInDay(d); break; }
                    case 6: { string d; cout << "Nhap ngay ra vien moi: "; cin >> d; x.setOutDay(d); break; }
                    case 7: { string d; cout << "Nhap benh ly moi: "; getline(cin, d); x.setDisaster(d); break; }
                }
                cout << endl;
            } while (choice != 0);
            system("cls");
            init_Patient();
            cout << green << "Cap nhat thanh cong!\n" << reset;
            break;
        }
    }
    if (!found) {
        cout << red << "=> Khong tim thay benh nhan voi ID nay!\n" << reset;
    }
    cout << cyan << "-----------------------------\n" << reset;
    end_Patient();
}

void saveP(const vector <Patient> &p) {
    ofstream fout("patients.txt");
    for (auto& x : p) {
        fout << x.toString() << "\n";
    }
    fout.close();
}

void loadP(vector <Patient> &p) {
    ifstream fin("patients.txt");
    string line;
    while (getline(fin, line)) {
        if (!line.empty()) p.push_back(Patient::fromString(line));
    }
    fin.close();
}

int Doctor::nextIDd = 1;

void Doctor::Add() {
    system("cls");
    init_Doctor();
    cin.ignore();
    cout << yellow << "-- Moi ban nhap bac si: --\n" << reset;
    cout << "[+] Nhap ten bac si: "; getline(cin, name);
    cout << "[+] Nhap gioi tinh: "; cin >> gender;
    cout << "[+] Nhap so nam kinh nghiem: "; cin >> age;
    cin.ignore();
    cout << "[+] Nhap Khoa: "; getline(cin, speci);
    cout << "[+] Nhap so dien thoai: "; getline(cin, number);
    cout << "[+] Nhap ngay lam viec: "; getline(cin, work);
    cout << yellow << "-----------------------------\n" << reset;
    end_Doctor();
}

void Doctor::Show() {
    cout << "[BS" << setfill('0') << setw(4) << ID << "] " << name << endl;
    cout << "- Gioi tinh: " << gender << endl;
    cout << "- Kinh nghiem: " << age << " nam" << endl;
    cout << "- Khoa: " << speci << endl;
    cout << "- SDT lien he: " << number << endl;
    cout << "- Ngay lam viec: " << work << endl;
    cout << endl;
}

void searchD(vector <Doctor> &d) {
    system("cls");
    init_Doctor();
    cout << yellow << "-- Tim kiem bac si --\n" << reset;
    string searchID;
    cout << green << "[+] Nhap ID can tim: " << reset;
    cin >> searchID;
    cout << endl;
    bool found = false;
    for (auto& x : d) {
        if (x.getID() == searchID) {
            x.Show();
            found = true;
            break;
        }
    }
    if (!found) cout << "=> Khong tim thay bac si voi ID nay!" << endl;
    cout << yellow << "-----------------------------\n" << reset;
    end_Doctor();
}

void deleteD(vector <Doctor> &p) {
    system("cls");
    init_Doctor();
    cout << yellow << "-- Xoa bac si --\n" << reset;
    string delID;
    cout << green << "[+] Nhap ID bac si can xoa: " << reset; cin >> delID;
    bool found = false;
    for (auto i = p.begin(); i != p.end(); i++) {
        if (i->getID() == delID) {
            cout << "\n==> Da tim thay bac si voi ID: [" << setfill('0') << setw(4) << delID << "]" << endl << green << "[+] Thong tin:\n" << reset;
            i->Show();
            char confirm;
            cout << red << "Ban co chac muon xoa (y/n)? " << reset;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                p.erase(i);
                cout << "Xoa thanh cong!\n";
                cout << yellow << "-----------------------------\n" << reset;
                end_Doctor();
            }
            else {
                cout << "=> Huy thao tac xoa.\n";
                cout << yellow << "-----------------------------\n" << reset;
                end_Doctor();
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "=> Khong tim thay bac si voi ID nay!" << endl;
        cout << yellow << "-----------------------------\n" << reset;
        end_Doctor();
    }
}

void updateD(vector <Doctor> &d) {
    system("cls");
    init_Doctor();
    cout << yellow << "-- Cap nhat thong tin bac si --\n" << reset;
    string upID;
    cout << green << "[+] Nhap ID bac si can cap nhat: " << reset; cin >> upID;
    bool found = false;
    for (auto& x : d) {
        if (x.getID() == upID) {
            cout << "\n==> Da tim thay bac si voi ID: [" << upID << "]" << endl;
            x.Show();
            found = true;
            int choice;
            cin.ignore();
            do {
                cout << yellow << "Ban muon cap nhat gi?\n" << reset;
                cout << " 1) Ten\n";
                cout << " 2) Gioi tinh\n";
                cout << " 3) So nam kinh nghiem\n";
                cout << " 4) Khoa\n";
                cout << " 5) So dien thoai\n";
                cout << " 6) Thoi gian lam viec\n";
                cout << red << " 0) Thoat cap nhat\n" << reset;
                cout << magenta << "> Your Choice: " << reset;
                cin >> choice;
                cin.ignore();
                switch (choice) {
                case 1: { string n; cout << "Nhap ten moi: "; getline(cin, n); x.setName(n); break; }
                case 2: { string g; cout << "Nhap gioi tinh moi: "; cin >> g; x.setGender(g); break; }
                case 3: { int a; cout << "Nhap tuoi moi: "; cin >> a; x.setAge(a); break; }
                case 4: { string s; cout << "Nhap Khoa moi: "; getline(cin, s); x.setSpeci(s); break; }
                case 5: { string n; cout << "Nhap So dien thoai moi: "; cin >> n; x.setNumber(n); break; }
                case 6: { string w; cout << "Nhap thoi gian lam viec moi: "; getline(cin, w); x.setWork(w); break; }
                }
                cout << endl;
            } while (choice != 0);
            system("cls");
            init_Doctor();
            cout << green << "Cap nhat thanh cong!\n" << reset;
            break;
        }
    }
    if (!found) {
        cout << red << "=> Khong tim thay bac si voi ID nay!\n" << reset;
    }
    cout << yellow << "-----------------------------\n" << reset;
    end_Doctor();
}

void saveD(const vector <Doctor> &d) {
    ofstream fout("doctors.txt");
    for (auto& x : d) {
        fout << x.toString() << "\n";
    }
    fout.close();
}

void loadD(vector <Doctor> &d) {
    ifstream fin("doctors.txt");
    string line;
    while (getline(fin, line)) {
        if (!line.empty()) d.push_back(Doctor::fromString(line));
    }
    fin.close();
}

void thongKeP( vector<Patient>& p) {
    system("cls");
    init_TK();
    cout << cyan << "---- THONG KE BENH NHAN ----\n" << reset;
    cout << "Tong so benh nhan: " << p.size() << "\n";
    int dangDieuTri = 0, daRaVien = 0;
    map<string, int> thongKeBenh;
    for (auto& x : p) {
        if (x.getOutDay() == "N/A" || x.getOutDay() == "" || x.getOutDay() == "-")
            dangDieuTri++;
        else
            daRaVien++;
        thongKeBenh[x.getDisaster()]++;
    }
    cout << "Dang dieu tri: " << dangDieuTri << "\n";
    cout << "Da ra vien: " << daRaVien << "\n";
    cout << "\nThong ke theo loai benh:\n";
    for (auto& kv : thongKeBenh) {
        cout << " - " << kv.first << ": " << kv.second << "\n";
    }
    cout << cyan << "--------------------------\n" << reset;
    end_TK();
}

void thongKeD( vector<Doctor>& d) {
    system("cls");
    init_TK();
    cout << yellow << "----- THONG KE BAC SI -----\n" << reset;
    cout << "Tong so bac si: " << d.size() << "\n";
    map<string, int> thongKeCK;
    for (auto& x : d) {
        thongKeCK[x.getSpeci()]++;
    }
    cout << "\nThong ke theo chuyen khoa:\n";
    for (auto& kv : thongKeCK) {
        cout << " - " << kv.first << ": " << kv.second << "\n";
    }
    cout << yellow << "---------------------------\n" << reset;
    end_TK();
}

void lietKeDieuTri(const vector<Patient>& p, const vector<Doctor> &d) {
    system("cls");
    init_TK();
    cout << cyan << "--- Danh sach benh nhan dang dieu tri ---\n" << reset;
    for (auto x : p) {
        if (x.getOutDay() == "N/A") {
            x.Show(d);
        }
    }
    cout << cyan << "---------------------------\n" << reset;
    end_TK();
}

void lietKeRaVien(const vector<Patient>& p, const vector<Doctor>& d) {
    system("cls");
    init_TK();
    cout << cyan << "--- Danh sach benh nhan da ra vien ---\n" << reset;
    for (auto x : p) {
        if (!(x.getOutDay() == "N/A" || x.getOutDay() == "" || x.getOutDay() == "-")) {
            x.Show(d);
        }
    }
    cout << cyan << "---------------------------\n" << reset;
    end_TK();
}

void lietKeTheoBenh(const vector<Patient>& p, const vector<Doctor>& d) {
    system("cls");
    init_TK();
    if (p.empty()) {
        cout << "=> Chua co benh nhan nao!\n";
        return;
    }
    map<string, vector<Patient>> groups;
    for (auto& x : p) {
        groups[x.getDisaster()].push_back(x);
    }
    for (auto& g : groups) {
        cout << cyan << "\n=== Benh ly: " << g.first << " ===\n" << reset;
        for (auto& p : g.second) {
            p.Show(d);
        }
    }
    cout << cyan << "---------------------------\n" << reset;
    end_TK();
}

void lietKeTheoKhoa(const vector<Doctor>& d) {
    system("cls");
    init_TK();
    if (d.empty()) {
        cout << "=> Chua co bac si nao!\n";
        return;
    }
    map<string, vector<Doctor>> groups;
    for (auto& x : d) {
        groups[x.getSpeci()].push_back(x);
    }
    for (auto& g : groups) {
        cout << yellow << "\n=== Chuyen khoa: " << g.first << " ===\n" << reset;
        for (auto& x : g.second) {
            x.Show();
        }
    }
    cout << yellow << "---------------------------\n" << reset;
    end_TK();
}

void menu_Patient(vector <Patient> &p, vector <Doctor>& d) {
    system("cls");
    int f;
    init_Patient();
    end_Patient();
    do {
        cout << magenta << "> Your Choice: " << reset;
        cin >> f;
        if (f == 1) {
            Patient i;
            i.Add(d);
            p.push_back(i);
        }
        else if (f == 2) {
            system("cls");
            init_Patient();
            cout << cyan << "-- Danh sach tat ca cac benh nhan --\n" << reset;
            if (!p.size()) {
                cout << "=> Hien khong co benh nhan nao ton tai!\n";
                cout << cyan << "-----------------------------\n" << reset;
                end_Patient();
                continue;
            }
            for (auto& x : p) x.Show(d);
            cout << cyan << "-----------------------------\n" << reset;
            end_Patient();
        }
        else if (f == 3){
            searchP(p, d);
        }
        else if (f == 4) {
            deleteP(p, d);
        }
        else if (f == 5) {
            updateP(p, d);
        }
    } while (f != 0);
    Menu();
}

void menu_Doctor(vector <Doctor> &d) {
    system("cls");
    int f;
    init_Doctor();
    end_Doctor();
    do {
        cout << magenta << "> Your Choice: " << reset;
        cin >> f;
        if (f == 1) {
            Doctor i;
            i.Add();
            d.push_back(i);
        }
        else if (f == 2) {
            system("cls");
            init_Doctor();
            cout << yellow << "-- Danh sach tat ca cac bac si --\n" << reset;
            if (!d.size()) {
                cout << "=> Hien khong co bac si nao ton tai!\n";
                cout << yellow << "-----------------------------\n" << reset;
                end_Doctor();
                continue;
            }
            for (auto& x : d) x.Show();
            cout << yellow << "-----------------------------\n" << reset;
            end_Doctor();
        }
        else if (f == 3) {
            searchD(d);
        }
        else if (f == 4) {
            deleteD(d);
        }
        else if (f == 5) {
            updateD(d);
        }
    } while (f != 0);
    Menu();
}

void menu_TK(vector <Patient>& p, vector <Doctor>& d) {
    system("cls");
    int f;
    init_TK();
    end_TK();
    do {
        cout << magenta << "> Your Choice: " << reset;
        cin >> f;
        if (f == 1) {
            thongKeP(p);
        }
        else if (f == 2) {
           lietKeDieuTri(p, d);
        }
        else if (f == 3) {
          lietKeRaVien(p, d);
        }
        else if (f == 4) {
           lietKeTheoBenh(p, d);
        }
        else if (f == 5) {
            thongKeD(d);
        }
        else if (f == 6) {
            lietKeTheoKhoa(d);
        }
    } while (f != 0);
    Menu();
}

int main() {
    vector <Patient> p;
    vector <Doctor> d;
    loadP(p);
    loadD(d);
    int function;
    Menu();
    do {
        cout << magenta << "> Your Choice: " << reset;
        cin >> function;
        switch (function) {
            case(1):
                menu_Patient(p, d);
                break;
            case(2):
                menu_Doctor(d);
                break;
            case(3):
                menu_TK(p, d);
                break;
            case(0):
                cout << green << "Dang luu du lieu..." << reset << endl;
                Sleep(3000);
                saveP(p);
                saveD(d);
                cout << yellow << "Tam biet!\n" << reset;
                break;
            default:
                cout << red << "Lua chon khong hop le!\n" << reset;
        }
    } while (function != 0);
    return 0;   
}