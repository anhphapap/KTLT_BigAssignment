#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void printMenu()
{
    system("cls");
    cout << "===============================================MENU============================================\n";
    cout << "1.NHAP DON HANG   ";
    cout << "2.TIM SAN PHAM   ";
    cout << "3.XOA SAN PHAM   ";
    cout << "4.XEM DANH SACH   ";
    cout << "5.XUAT DON HANG   ";
    cout << "6.THOAT\n";
    cout << "===============================================MENU============================================\n";
}

void printProducts()
{
    cout << "\n================PRODUCTS===============\n";
    cout << "1.IPHONE\t";
    cout << "2.MACBOOK\t";
    cout << "3.THOAT\n";
    cout << "================PRODUCTS===============\n";
}

void printModel1()
{
    cout << "\n================MODELS===============\n";
    cout << "1.SE\t";
    cout << "2.PRO\t";
    cout << " 3.PRO MAX    ";
    cout << "4.THOAT\n";
    cout << "================MODELS===============\n";
}

void chooseModel1(json j)
{
    int n;
    cout << "\nMoi chon loai IPHONE: ";
    cin >> n;
    switch (n)
    {
    case 1:
    {
        j["Mod"] = "SE";
        break;
    }
    case 2:
    {
        j["Mod"] = "PRO";
        break;
    }
    case 3:
    {
        j["Mod"] = "PRO MAX";
        break;
    }
    case 4:
    {
        exit(1);
        break;
    }
    }
    int m;
    cout << "\nNhap so luong san pham: ";
    cin >> m;
    int t;
    ifstream fi("total.txt");
    fi >> t;
    fi.close();
    t += m;
    ofstream foo("total.txt");
    foo << t;
    foo.close();
    ofstream fo("in4.json", ios::app);
    string code = "******";
    srand(time(NULL));
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string day = to_string(ltm->tm_mday) + "/" + to_string(ltm->tm_mon + 1) + "/" + to_string(ltm->tm_year + 1900);
    string time = to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
    for (int k = 0; k < m; k++)
    {
        for (int i = 0; i < 6; i++)
        {
            int x = rand() % 35 + 55;
            if (x <= 64)
            {
                x -= 55;
                string s = to_string(x);
                code[i] = s[0];
            }
            else
            {
                code[i] = char(x);
            }
        }
        j["Code"] = code;
        j["Day"] = day;
        j["Time"] = time;
        fo << j << endl;
    }
    fo.close();
    cout << endl;
    string pr = j["Prod"], mo = j["Mod"];
    cout << "DA THEM THANH CONG " << m << " " << pr << " " << mo << " VAO KHO!!\n";
    cout << "\nGo phim bat ky de quay lai MENU...";
    _getch();
}

void printModel2()
{
    cout << "\n===============MODELS=============\n";
    cout << "1.AIR\t";
    cout << "2.PRO\t";
    cout << "3.RETINA   ";
    cout << "4.THOAT\n";
    cout << "===============MODELS=============\n";
}

void chooseModel2(json j)
{
    int n;
    cout << "\nMoi chon loai MACBOOK: ";
    cin >> n;
    switch (n)
    {
    case 1:
    {
        j["Mod"] = "AIR";
        break;
    }
    case 2:
    {
        j["Mod"] = "PRO";
        break;
    }
    case 3:
    {
        j["Mod"] = "RETINA";
        break;
    }
    case 4:
    {
        exit(1);
        break;
    }
    }
    int m;
    cout << "\nNhap so luong san pham: ";
    cin >> m;
    int t;
    ifstream fi("total.txt");
    fi >> t;
    fi.close();
    t += m;
    ofstream foo("total.txt");
    foo << t;
    foo.close();
    ofstream fo("in4.json", ios::app);
    string code = "******";
    srand(time(NULL));
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string day = to_string(ltm->tm_mday) + "/" + to_string(ltm->tm_mon + 1) + "/" + to_string(ltm->tm_year + 1900);
    string time = to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
    for (int k = 0; k < m; k++)
    {
        for (int i = 0; i < 6; i++)
        {
            int x = rand() % 35 + 55;
            if (x <= 64)
            {
                x -= 55;
                string s = to_string(x);
                code[i] = s[0];
            }
            else
            {
                code[i] = char(x);
            }
        }
        j["Code"] = code;
        j["Day"] = day;
        j["Time"] = time;
        fo << j << endl;
    }
    fo.close();
    cout << endl;
    string pr = j["Prod"], mo = j["Mod"];
    cout << "DA THEM THANH CONG " << m << " " << pr << " " << mo << " VAO KHO!!\n";
    cout << "\nGo phim bat ky de quay lai MENU...";
    _getch();
}

void chooseProducts(json &j)
{
    int n;
    cout << "\nMoi chon san pham: ";
    cin >> n;
    switch (n)
    {
    case 1:
    {
        j["Prod"] = "IPHONE";
        printModel1();
        chooseModel1(j);
        break;
    }
    case 2:
    {
        j["Prod"] = "MACBOOK";
        printModel2();
        chooseModel2(j);
        break;
    }
    case 3:
    {
        exit(1);
        break;
    }
    }
}

void update()
{
    int n;
    json j;
    ifstream fii("total.txt");
    fii >> n;
    fii.close();
    ifstream fi("kho.json");
    ofstream fo("in4.json");
    for (int i = 0; i < n; i++)
    {
        fi >> j;
        fo << j << endl;
    }
    fi.close();
    fo.close();
}

void outputEdit(json temp)
{
    ifstream ft("total.txt");
    json j;
    int n;
    ft >> n;
    ft.close();
    ifstream fi("in4.json");
    int counter = 0;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string s = "Edit\\" + to_string(ltm->tm_mday) + "-" + to_string(ltm->tm_mon + 1) + "-" + to_string(ltm->tm_year - 100) + "_" + to_string(ltm->tm_hour) + "-" + to_string(ltm->tm_min) + "-" + to_string(ltm->tm_sec) + ".txt";
    const char *ofile = s.c_str();
    ofstream fo(s);
    fo << "\t\t\t  DANH SACH SAN PHAM\n\n";
    fo << setfill('-') << "+" << setw(5) << "+" << setw(15) << "+" << setw(15) << "+" << setw(12) << "+" << setw(13) << "+" << setw(12) << "+" << endl;
    fo << setfill(' ') << "|" << setw(5) << "|" << left << setw(14) << "Product" << "|" << setw(14) << "Model" << "|" << right << setw(11) << "Code" << "|" << setw(12) << "Day" << "|" << setw(11) << "Time" << "|" << endl;
    fo << setfill('-') << "+" << right << setw(5) << "+" << setw(15) << "+" << setw(15) << "+" << setw(12) << "+" << setw(13) << "+" << setw(12) << "+" << endl;
    for (int k = 1; k <= n; k++)
    {
        fi >> j;
        counter++;
        string pro = j["Prod"], mod = j["Mod"], code = j["Code"], day = j["Day"], time = j["Time"];
        fo << setfill(' ') << "|" << left << setw(4) << counter << "|" << setw(14) << pro << "|" << setw(14) << mod << "|" << right << setw(11) << code << "|" << setw(12) << day << "|" << setw(11) << time << "|" << endl;
        fo << setfill('-') << "+" << right << setw(5) << "+" << setw(15) << "+" << setw(15) << "+" << setw(12) << "+" << setw(13) << "+" << setw(12) << "+" << endl;
    }
    // cout<<"\nDon hang da duoc xuat ra file "<<"\""<<s<<"\" !!!\n";
    fo << setfill(' ');
    fo << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec;
    fo << setw(58) << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
    fo << "\n***DA XOA SAN PHAM***\n\n";
    fo << "Ten san pham: " << string(temp["Prod"]) << endl;
    fo << "Loai san pham: " << string(temp["Mod"]) << endl;
    fo << "Ma san pham: " << string(temp["Code"]) << endl;
    fo << "Ngay nhap: " << string(temp["Day"]) << endl;
    fo << "Thoi gian: " << string(temp["Time"]) << endl;
    fo << "\n***DA XOA SAN PHAM***\n\n";
    fo.close();
    fi.close();
}

void deleteProd()
{
    int n;
    ifstream fi("total.txt");
    fi >> n;
    fi.close();
    if(n!=0)
    {
        bool check = false;
        string s;
        cout << "\nMoi nhap MA SAN PHAM can xoa: ";
        cin >> s;
        ifstream fii("in4.json");
        ofstream fo("kho.json");
        json j, temp;
        for (int i = 0; i < n; i++)
        {
            fii >> j;
            if (j["Code"] == s)
            {
                check = true;
                temp = j;
            }
            else
                fo << j << endl;
        }
        fo.close();
        fii.close();
        if (check == true)
        {
            cout << "\nDA XOA THANH CONG SAN PHAM CO MA \"" << s << "\"!!\n";
            n--;
            ofstream foo("total.txt");
            foo << n;
            foo.close();
            update();
            outputEdit(temp);
        }
        else
        {
            cout << "\nKHONG TIM THAY SAN PHAM CO MA \"" << s << "\" TRONG KHO!!\n";
        }
    }
    else
    {
        system("cls");
        cout << "\nDANH SACH KHO HIEN DANG TRONG !! VUI LONG NHAP THEM DON HANG DE SU DUNG TINH NANG!!\n";
    }
    cout << "\nGo phim bat ky de quay lai MENU...";
    _getch();
}

void findProd()
{
    int n;
    ifstream fi("total.txt");
    fi >> n;
    fi.close();
    if(n!=0)
    {
        bool check = false;
        string s;
        cout << "\nMoi nhap MA SAN PHAM can tim: ";
        cin >> s;
        ifstream fii("in4.json");
        json j, temp;
        for (int i = 0; i < n; i++)
        {
            fii >> j;
            if (j["Code"] == s)
            {
                check = true;
                temp = j;
            }
        }
        fii.close();
        if (check == true)
        {
            cout << "\nDA TIM THAY SAN PHAM!!\n\n";
            cout << "Ten san pham: " << string(temp["Prod"]) << endl;
            cout << "Loai san pham: " << string(temp["Mod"]) << endl;
            cout << "Ma san pham: " << string(temp["Code"]) << endl;
            cout << "Ngay nhap: " << string(temp["Day"]) << endl;
            cout << "Thoi gian: " << string(temp["Time"]) << endl;
        }
        else
        {
            cout << "\nKHONG TIM THAY SAN PHAM CO MA \"" << s << "\" TRONG KHO!!\n";
        }
    }
    else
    {
        system("cls");
        cout << "\nDANH SACH KHO HIEN DANG TRONG !! VUI LONG NHAP THEM DON HANG DE SU DUNG TINH NANG!!\n";
    }
    cout << "\nGo phim bat ky de quay lai MENU...";
    _getch();
}

void output()
{
    system("cls");
    ifstream ft("total.txt");
    json j;
    int n;
    ft >> n;
    ft.close();
    if (n != 0)
    {
        ifstream fi("in4.json");
        int counter = 0;
        time_t now = time(0);
        tm *ltm = localtime(&now);
        string s = "Bill\\" + to_string(ltm->tm_mday) + "-" + to_string(ltm->tm_mon + 1) + "-" + to_string(ltm->tm_year - 100) + "_" + to_string(ltm->tm_hour) + "-" + to_string(ltm->tm_min) + "-" + to_string(ltm->tm_sec) + ".txt";
        const char *ofile = s.c_str();
        ofstream fo(s);
        fo << "\t\t\t  DANH SACH SAN PHAM\n\n";
        fo << setfill('-') << "+" << setw(5) << "+" << setw(15) << "+" << setw(15) << "+" << setw(12) << "+" << setw(13) << "+" << setw(12) << "+" << endl;
        fo << setfill(' ') << "|" << setw(5) << "|" << left << setw(14) << "Product" << "|" << setw(14) << "Model" << "|" << right << setw(11) << "Code" << "|" << setw(12) << "Day" << "|" << setw(11) << "Time" << "|" << endl;
        fo << setfill('-') << "+" << right << setw(5) << "+" << setw(15) << "+" << setw(15) << "+" << setw(12) << "+" << setw(13) << "+" << setw(12) << "+" << endl;
        for (int k = 1; k <= n; k++)
        {
            fi >> j;
            counter++;
            string pro = j["Prod"], mod = j["Mod"], code = j["Code"], day = j["Day"], time = j["Time"];
            fo << setfill(' ') << "|" << left << setw(4) << counter << "|" << setw(14) << pro << "|" << setw(14) << mod << "|" << right << setw(11) << code << "|" << setw(12) << day << "|" << setw(11) << time << "|" << endl;
            fo << setfill('-') << "+" << right << setw(5) << "+" << setw(15) << "+" << setw(15) << "+" << setw(12) << "+" << setw(13) << "+" << setw(12) << "+" << endl;
        }
        cout << "\nDon hang da duoc xuat ra file "
             << "\"" << s << "\" !!!\n";
        fo << setfill(' ');
        fo << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec;
        fo << setw(58) << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
        fo.close();
        fi.close();
        ofstream fii("in4.json");
        ofstream ftt("total.txt");
        ftt << 0;
        fii << "";
        fii.close();
        ftt.close();
    }
    else
    {
        cout << "\nDANH SACH KHO HIEN DANG TRONG !! VUI LONG NHAP THEM DON HANG DE SU DUNG TINH NANG!!\n";
    }
    cout << "\nGo phim bat ky de quay lai MENU...";
    _getch();
}

void printList()
{
    system("cls");
    ifstream ft("total.txt");
    int n;
    ft >> n;
    if (n != 0)
    {
        ifstream fi("in4.json");
        json j;
        int counter = 0;
        cout << "\t\t\t  DANH SACH SAN PHAM\n\n";
        cout << setfill('-') << "+" << setw(5) << "+" << setw(15) << "+" << setw(15) << "+" << setw(12) << "+" << setw(13) << "+" << setw(12) << "+" << endl;
        cout << setfill(' ') << "|" << setw(5) << "|" << left << setw(14) << "Product" << "|" << setw(14) << "Model" << "|" << right << setw(11) << "Code" << "|" << setw(12) << "Day" << "|" << setw(11) << "Time" << "|" << endl;
        cout << setfill('-') << "+" << right << setw(5) << "+" << setw(15) << "+" << setw(15) << "+" << setw(12) << "+" << setw(13) << "+" << setw(12) << "+" << endl;
        for (int k = 1; k <= n; k++)
        {
            fi >> j;
            counter++;
            string pro = j["Prod"], mod = j["Mod"], code = j["Code"], day = j["Day"], time = j["Time"];
            cout << setfill(' ') << "|" << left << setw(4) << counter << "|" << setw(14) << pro << "|" << setw(14) << mod << "|" << right << setw(11) << code << "|" << setw(12) << day << "|" << setw(11) << time << "|" << endl;
            cout << setfill('-') << "+" << right << setw(5) << "+" << setw(15) << "+" << setw(15) << "+" << setw(12) << "+" << setw(13) << "+" << setw(12) << "+" << endl;
        }
        fi.close();
    }
    else
    {
        cout << "\nDANH SACH KHO HIEN DANG TRONG !! VUI LONG NHAP THEM DON HANG DE SU DUNG TINH NANG!!\n";
    }
    ft.close();
    cout << "\nGo phim bat ky de quay lai MENU...";
    _getch();
}

void chooseMenu()
{
    int n;
    cout << "\nMoi chon Menu: ";
    cin >> n;
    switch (n)
    {
    case 1:
    {
        json j;
        printProducts();
        chooseProducts(j);
        break;
    }
    case 2:
    {
        findProd();
        break;
    }
    case 3:
    {
        deleteProd();
        break;
    }
    case 4:
    {
        printList();
        break;
    }
    case 5:
    {
        output();
        break;
    }
    case 6:
    {
        exit(1);
        break;
    }
    }
}

int main()
{
    while (1)
    {
        printMenu();
        chooseMenu();
    }
    return 0;
}