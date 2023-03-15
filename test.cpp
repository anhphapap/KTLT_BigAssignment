#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<conio.h>
#include<ctime>
#include<nlohmann/json.hpp>

using json=nlohmann::json;
using namespace std;

void printDelete()
{
    cout << "BAN CO MUON XOA SAN PHAM NAY KHONG?\n";
    cout << "1.XOA SAN PHAM\n";
    cout << "2.QUAY LAI MENU\n";
}

void chooseDelete()
{
    printDelete();
    int n;
    cout<<"Moi chon: ";
    cin>>n;
    switch(n)
    {
        case 1:
        {
            //cout << "\nDA XOA THANH CONG SAN PHAM CO MA \"" << s << "\"!!\n";
            n--;
            ofstream foo("total.txt");
            foo << n;
            foo.close();
            // update();
            // outputEdit(temp);
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            exit(1);
            break;
        }
    }
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

void printList()
{
    system("cls");
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string day = to_string(ltm->tm_mday)+"/"+to_string(ltm->tm_mon+1)+"/"+to_string(ltm->tm_year+1900);
    string time = to_string(ltm->tm_hour) +":"+ to_string(ltm->tm_min) +":"+to_string(ltm->tm_sec);
    ifstream ft("total.txt");
    int n;
    ft>>n;
    if(n!=0)
    {
        ifstream fi("in4.json");
        json j;
        int counter=0;
        cout<<"\t    DANH SACH SAN PHAM\n\n";
        cout << setfill('-') << "+" << setw(5) << "+" << setw(15) << "+" << setw(15) << "+" << setw(12) << "+" << setw(13) << "+" << setw(12) << "+" << endl;
        cout << setfill(' ') << "|" << setw(5) << "|" << left << setw(14) << "Product" << "|" << setw(14) << "Model" << "|" << right <<setw(11) <<"Code"<<"|"<<setw(12)<<"Day"<<"|"<<setw(11)<<"Time"<<"|"<<endl;
        cout << setfill('-') << "+" << right << setw(5) << "+" << setw(15) << "+" << setw(15) << "+" << setw(12) << "+" << setw(13) << "+" << setw(12) << "+" << endl;
        for(int k=1;k<=n;k++)
        {
            fi>>j;
            counter++;
            string pro=j["Prod"], mod=j["Mod"], code=j["Code"];
            cout << setfill(' ') << "|" << left << setw(4) << counter << "|"<<setw(14) << pro << "|" << setw(14) << mod << "|" << right <<setw(11) <<code<<"|"<<setw(12)<<day<<"|"<<setw(11)<<time<<"|"<<endl;
                    cout << setfill('-') << "+" << right << setw(5) << "+" << setw(15) << "+" << setw(15) << "+" << setw(12) << "+" << setw(13) << "+" << setw(12) << "+" << endl;
        }
        fi.close();
    }
    else
    {
        cout<<"DANH SACH KHO HIEN DANG TRONG !! VUI LONG NHAP THEM DON HANG !!\n";
    }
    ft.close();
    // cout << "\nGo phim bat ky de quay lai MENU...";
	// _getch();
}

int main()
{
    // printList();
    // time_t now = time(0);
    // tm *ltm = localtime(&now);
    // string day = to_string(ltm->tm_mday)+"/"+to_string(ltm->tm_mon+1)+"/"+to_string(ltm->tm_year+1900);
    // string time = to_string(ltm->tm_hour) +":"+ to_string(ltm->tm_min) +":"+to_string(ltm->tm_sec);
    // cout<<day<<endl<<time;
    printDelete();
    return 0;
}