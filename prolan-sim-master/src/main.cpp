#include <iostream>
#include <string>
#include <vector>

#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"

using namespace std;

vector<mahasiswa> recMhs;
vector<dosen> recDosen;
vector<tendik> recTendik;


void panggilMhs (int i)
{
	cout << "Nama            : " << recMhs[i].getNama() << endl;
	cout << "Tanggal lahir   : " << recMhs[i].getTglLahir() << "/"<< recMhs[i].getBulanLahir() << "/" << recMhs[i].getTahunLahir() << endl;
	cout << "NRP             : " << recMhs[i].getNrp() << endl;
	cout << "Departemen      : " << recMhs[i].getDepartemen() << endl;
	cout << "Tahun Masuk     : " << recMhs[i].getTahunmasuk() << endl;
	cout << "Semester        : " << recMhs[i].getSemester() << endl;
	cout << "SKS Terlampaui  : " << recMhs[i].getSKSLulus() << endl << endl;
}


int main()
{
	
	int menu_terpilih;
	string username,password;
	string user= "admin",pw="admin";

	while(1)
	{
		cout << "Username  : ";
		cin >> username;
		cout << endl << "password  : ";
		cin >> password;

		if(username==user && password == pw)
		{
			break;
		}
		system("cls");
		cout << "Wrong Username or Wrong Password, Please Try Again." << endl << endl;
	}


	while(1) 
	{
		cout << "Selamat datang di Universitas X" << endl << endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " mahasiswa" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " mahasiswa" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
		cout << "  4. Tampilkan semua Mahasiswa" << endl;
		cout << "  5. Tampilkan semua Dosen" << endl;
		cout << "  6. Tampilkan semua Tenaga Kependidikan" << endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;
		cin.ignore();

		switch (menu_terpilih) 
		{
			case 1://mahasiswa
			{
				string nama,nrp,departemen;
				int dd,mm,yy,tahunmasuk,id,skslulus,semesterke,Edit;
				float ips;
				cout << "Masukkan Nama  :" << endl;
				getline(cin,nama);
				cout << "Masukkan NRP  :" << endl;
				cin >> nrp;
				cout << "Masukkan tanggal Lahir  :" << endl;
				cin >> dd;
				cout << "Masukkan Bulan Lahir  :" << endl;
				cin >> mm;
				cout << "Masukkan Tahun Lahir  :" << endl;
				cin >> yy;
				cout << "Masukkan Tahun Masuk  :" << endl;
				cin >> tahunmasuk;
				cin.ignore();
				cout << "Masukkan Departemen  :" << endl;
				getline(cin,departemen);
				cout << "SKS yang telah terlampaui  :" << endl;
				cin >> skslulus;
				cout << "Semester  :" << endl;
				cin >> semesterke;

				mahasiswa dataMhs(id,nama,dd,mm,yy,nrp,departemen,tahunmasuk,skslulus,semesterke,ips);
				recMhs.push_back(dataMhs);
			}
				break;
			case 2://dosen
				{
					string nama,npp,departemen,pendidikan;
					int id,dd,mm,yy;
					id = 0;
					cout << "Masukkan Nama  :" << endl;
					getline(cin,nama);
					cout << "Masukkan Tanggal Lahir  :" << endl;
					cin >> dd;
					cout << "Masukkan Bulan Lahir  :" << endl;
					cin >> mm;
					cout << "Masukkan Tahun Lahir  :" << endl;
					cin >> yy;
					cout << "Masukkan Npp  :" << endl;
					cin >> npp;
					cin.ignore();
					cout << "Masukkan Departemen  :" << endl;
					getline(cin,departemen);
					cout << "Masukkan Pendidikan  :" << endl;
					getline(cin,pendidikan);
					dosen dataDsn(id,nama,dd,mm,yy,npp,departemen,pendidikan);
					recDosen.push_back(dataDsn);
				}
				break;
			case 3://tendik
			{
				string nama,npp,unit;
				int id,dd,mm,yy;
				float ips;
				cout << "Masukkan Nama  :"<< endl;
				getline(cin,nama);
				cout << "Masukkan Npp  :" << endl;
				cin >> npp;
				cin.ignore();
				cout << "Masukkan Unit  :" << endl;
				getline(cin,unit);
				cout << "Masukkan Tanggal Lahir  :" << endl;
				cin >> dd;
				cout << "Masukkan Bulan Lahir  :" << endl;
				cin >> mm;
				cout << "Masukkan Tahun Lahir  :" << endl;
				cin >> yy;
				cout << "Masukkan IPS  :" << endl;
				
				tendik dataTd(id,nama,dd,mm,yy,npp,unit);
				recTendik.push_back(dataTd);//memasukkan data yg sudah di input ke dalam vector
			}
				break;
			case 4://output data mahasiswa
			{
				int p,pilih_menu1;
				for(long unsigned i=0;i<recMhs.size();i++)
				{//output semua data mahasiswa yang disimpan di dalam vector recMhs
					cout << " =================================================================" << endl;
					cout << "Nama            : " << recMhs[i].getNama() << endl;
					cout << "Departemen      : " << recMhs[i].getDepartemen() << endl;
					cout << " =================================================================" << endl;
					
				}

				cout << "pilih mahasiswa" << endl;
				cin >> p;
				system("@clear||cls");
				 panggilMhs(p-1);
				 cout << "Silahkan pilih menu  :" << endl;
				 cout << "1.setting IPS" << endl;
				 cout << "2.Edit data Mahasiswa" << endl;
				 cout << "0.Kembali ke menu utama" << endl;
				 cin >> pilih_menu1;

				switch (pilih_menu1)
				{
					case 1:
						{
							float addips;
							//cout << "Masukkan banyak semester  :" << endl;
							//cin >> semesterset;
							for(long i = 0;i<recMhs[p-1].getSemester();i++)
							{
							cout << "Masukkan IPS  :" << endl;
							cin >> addips;
							recMhs[p-1].setIPS(i, addips);
							}
							cout << recMhs[p-1].getIPS(recMhs[p-1].getSemester()) << endl;
						}
					break;
					
					case 2:
					{
						cout << "========================" << endl;
						cout << "Data Editor" << endl;
						cout << "========================" << endl;

						string nama,nrp,departemen;
						int dd,mm,yy,tahunmasuk,id,skslulus,semesterke,Edit;
						float ips;
						cout << "Masukkan Nama  :" << endl;
						cin.ignore();
						getline(cin,nama);
						cout << "Masukkan NRP  :" << endl;
						cin >> nrp;
						cout << "Masukkan tanggal Lahir  :" << endl;
						cin >> dd;
						cout << "Masukkan Bulan Lahir  :" << endl;
						cin >> mm;
						cout << "Masukkan Tahun Lahir  :" << endl;
						cin >> yy;
						cout << "Masukkan Tahun Masuk  :" << endl;
						cin >> tahunmasuk;
						cin.ignore();
						cout << "Masukkan Departemen  :" << endl;
						getline(cin,departemen);
						cout << "SKS yang telah terlampaui  :" << endl;
						cin >> skslulus;
						cout << "Semester  :" << endl;
						cin >> semesterke;

						recMhs[p-1].setNama(nama);
						recMhs[p-1].setNrp(nrp);
						recMhs[p-1].setTglLahir(dd,mm,yy);
						recMhs[p-1].setTahunmasuk(tahunmasuk);
						recMhs[p-1].setDepartemen(departemen);
						recMhs[p-1].setSKSLulus(skslulus);
						recMhs[p-1].setSemester(semesterke);
					}
					break;

					case 3:
					{
						return main();
					}
				}
				
			}	
			case 5://output data dosen
			{
				for(long unsigned i=0;i<recDosen.size();i++)
				{
					cout << "Nama           : " << recDosen[i].getNama() << endl;
					cout << "Tanggal Lahir  : " << recDosen[i].getTglLahir() << "/"<< recDosen[i].getBulanLahir() << "/" << recDosen[i].getTahunLahir() << endl;
					cout << "NPP            : " << recDosen[i].getNpp() << endl;
					cout << "Departemen     : " << recDosen[i].getDepartemen() << endl;
					cout << "Pendidikan     : " << recDosen[i].getPendidikan() << endl << endl;
				}
			}
				
			case 6://output data tendik
			{
				for(long unsigned i=0;i<recTendik.size();i++)
				{
					cout << "Nama           : " << recTendik[i].getNama() << endl;
					cout << "Tanggal Lahir  : " << recTendik[i].getTglLahir() << "/"<< recTendik[i].getBulanLahir() << "/" << recTendik[i].getTahunLahir() << endl;
					cout << "NPP            : " << recTendik[i].getNPP() << endl;
					cout << "Unit           : " << recTendik[i].getUnit() << endl << endl;
				}
			}
				break;
			//default:
				//break;
		}
	}

	
	return 0;

}
