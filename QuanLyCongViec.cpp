#include <bits/stdc++.h>
using namespace std;

// =========================== Cac struct khoi tao ============================
struct Note
{
	string Ghi_chu;
};
struct Thoi_Gian// deadline
{
	int ngay;
	int thang;
	int nam;
};
struct Cong_Viec
{
	bool Status; // trang thai
    vector <Note> Detail; // vector luu ghi chu
	char Name[1000]; // ten cong viec
	Thoi_Gian DL; // deadline
};
struct Info
{
	string name;
	int Tuoi;
	string viec_lam;
	string SDT;
	int Gioi_tinh;
	string Email;
};
// ======================= Cac bien chinh =====================================
vector <Cong_Viec> CV;
Info TT;

// =============================================================================

int ktra_Int(string nhap, string ndsai)
{
	string nd_nhap;
	int tmp;
	do
	{
		tmp = 69;
		cout << nhap;
		fflush(stdin);
		getline(cin, nd_nhap);

		for (int i = 0; i < nd_nhap.length(); i++)
		{
			// ep kieu tu 1 chu cai sang so
			// theo bang ma ASCII thi tu 0 -> 9 la 48 -> 57 neu tung phan tu k thuoc doan nay thi bao nhap lai
			if ((int)nd_nhap[i] < 48 || (int)nd_nhap[i] > 57)
			{
				tmp = 0;
				break;
			}
		}
		if (tmp == 0 || nd_nhap == "\0")
		{
			cout << ndsai << endl;
		}
	} while (tmp == 0 || nd_nhap == "\0");
	// ham c_str() bien doi tu kieu string thanh kieu du lieu mang ky tu
	// ham atoi() bien doi tu kieu mang ky tu sang so de tra ve kieu du lieu int
	int kq = atoi(nd_nhap.c_str());
	return kq; // tra ve kieu du lieu int de gan vao gia tri can nhap
}
void Mac_Dinh_TT()
{
	// ham mac dinh thong tin nguoi dung khi chua nhap thong tin
	TT.Gioi_tinh = 69;
	// 1 so bat ky mien khac 0 va 1
	TT.name = "Khach";
	TT.SDT = "Khong ro";
	TT.viec_lam = "Khong ro";
	TT.Tuoi = 0;
	TT.Email = "Khong ro";
}
bool ktra_thong_tin = true;
// neu nguoi dung chua nhap ma xem luon thong tin thi hien thi ham Mac_Dinh_TT();
void Nhap_thong_tin()
{
	if (ktra_thong_tin)
	{
		Mac_Dinh_TT();
	}
	ktra_thong_tin = false;
	// tat ham Mac_Dinh_TT trong ham Xuat_Thong_Tin
	int luachon;
	while (true)
	{
		system("cls");
		cout << "========================= MENU =========================" << endl;
		cout << "1. Ten. " << endl;
		cout << "2. Tuoi. " << endl;
		cout << "3. Cong viec hien tai. " << endl;
		cout << "4. So dien thoai. " << endl;
		cout << "5. Gioi tinh. " << endl;
		cout << "6. Email." << endl;
		cout << "0. Thoat." << endl;
		cout << "========================================================" << endl;
		luachon = ktra_Int("\n\tNhap lua chon : ", "\nKhong hop le !");
		while (luachon > 6 || luachon < 0)
		{
			luachon = ktra_Int("\n\tNhap lua chon : ", "\nKhong hop le !");
		}
		if (luachon == 1)
		{
			cout << "\nHay nhap ten cua ban : ";
			fflush(stdin);
			getline(cin, TT.name);
		}
		else if (luachon == 2)
		{
			TT.Tuoi = ktra_Int("\nHay nhap tuoi cua ban : ", "\nKhong hop le !");
			while (TT.Tuoi < 0 || TT.Tuoi > 200)
			{
				cout << "Vui long nhap so tuoi hop le ! ";
				TT.Tuoi = ktra_Int("\nHay nhap tuoi cua ban : ", "\nKhong hop le !");
			}
		}
		else if (luachon == 3)
		{
			cout << "\nHay nhap cong viec cua ban : ";
			fflush(stdin);
			getline(cin, TT.viec_lam);
		}
		else if (luachon == 4)
		{
			int tmp;
			do
			{
				tmp = 69;
				cout << "\nHay nhap so dien thoai cua ban : ";
				fflush(stdin);
				getline(cin, TT.SDT);

				for (int i = 0; i < TT.SDT.length(); i++)
				{
					if ((int)TT.SDT[i] < 48 || (int)TT.SDT[i] > 57)
					{
						tmp = 0;
						break;
					}
				}
				if (tmp == 0 || TT.SDT == "\0")
				{
					cout << "\nSo dien thoai khong hop le !" << endl;
				}
			} while (tmp == 0 || TT.SDT == "\0" || TT.SDT.length() > 11 || TT.SDT.length() < 9);
		}
		else if (luachon == 5)
		{
			TT.Gioi_tinh = ktra_Int("\nHay nhap gioi tinh cua ban (0 : Nu /1 : Nam): ", "\nKhong hop le !");
			while (TT.Gioi_tinh < 0 || TT.Gioi_tinh > 1)
			{
				TT.Gioi_tinh = ktra_Int("\nHay nhap gioi tinh cua ban (0 : Nu /1 : Nam): ", "\nKhong hop le !");
			}
		}
		else if (luachon == 6)
		{
			cout << "\nHay nhap dia chi email cua ban : ";
			fflush(stdin);
			getline(cin, TT.Email);
		}
		else
		{
			break;
		}
	}
}
void Xuat_TT()
{
	if (ktra_thong_tin)
	{
		Mac_Dinh_TT();
	}
	cout << "\n=================== Thong tin ca nhan ===================" << endl;
	cout << "Ten : " << TT.name << endl;
	if (TT.Tuoi > 0)
		cout << "Tuoi : " << TT.Tuoi << endl;
	else
		cout << "Tuoi : Khong ro " << endl;
	cout << "Cong viec : " << TT.viec_lam << endl;
	cout << "So dien thoai : " << TT.SDT << endl;
	cout << "Gioi tinh : " << (TT.Gioi_tinh == 1 ? "Nam" : (TT.Gioi_tinh == 0 ? "Nu" : "Khong ro")) << endl;
	// su dung toan tu 3 ngoi de nhap gioi tinh ru int -> string mong muon
	cout << "Email : " << TT.Email << endl;
	cout << "=========================================================" << endl;
}
bool nhuan(int y) // kiem tra 1 so co phai nam nhuan hay khong neu co thi tra ve true, khong la false;
{
	return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}
bool ktra_thoi_gian(Thoi_Gian &DL)
{
	if (DL.ngay > 31 || DL.ngay < 1 || DL.thang > 12 || DL.thang < 1 || DL.nam < 2000 || DL.nam > 2100)
	{
		// neu ngay, thang, nam khong nam trong khoang hop le thi tra ve false
		return false;
	}
	else if (DL.ngay == 30 && DL.thang == 2)
	{
		// neu la thang 2 va ngay la 30 -> false
		return false;
	}
	else if (DL.ngay == 29 && DL.thang == 2 && !nhuan(DL.nam))
	{
		// neu ngay la 29, thang 2, nam khong nhuan -> false
		return false;
	}
	else if (DL.ngay == 31 && (DL.thang == 2 || DL.thang == 4 || DL.thang == 6 || DL.thang == 9 || DL.thang == 11))
	{
		// ngay 31 cua nhung thang 2 4 6 9 11 -> false
		return false;
	}
	return true;
	// con lai true
}
void Mac_Dinh_Time(Cong_Viec &temp)
{
	// ham dung de mac dinh thoi gian deadline la ngay nhap neu nguoi dung khong dat deadline cho cong viec
	time_t hientai = time(0);
	tm *ltm = localtime(&hientai);
	temp.DL.ngay = (ltm->tm_mday);
	temp.DL.nam = (1900 + ltm->tm_year);
	temp.DL.thang = (1 + ltm->tm_mon);
}
void Nhap_Time(Thoi_Gian &DL)
{
	DL.ngay = ktra_Int("\nNhap ngay : ", "\nHay nhap ngay hop le !");
	DL.thang = ktra_Int("\nNhap thang : ", "\nHay nhap thang hop le !");
	DL.nam = ktra_Int("\nNhap nam : ", "\nHay nhap nam hop le !");

	while (!ktra_thoi_gian(DL))
	{
		cout << "Ngay thang nam khong hop le." << endl;
		cout << "Moi nhap lai !" << endl;
		DL.ngay = ktra_Int("\nNhap ngay : ", "\nHay nhap ngay hop le !");
		DL.thang = ktra_Int("\nNhap thang : ", "\nHay nhap thang hop le !");
		DL.nam = ktra_Int("\nNhap nam : ", "\nHay nhap nam hop le !");
	}
}
void Nhap_Lai_VT(int &vt)
{
	// ham dung de kiem tra phan tu nhap co vuot qua so phan tu vector hay khong ?
	while (vt > CV.size())
	{
		vt = ktra_Int("\nNhap STT cong viec hop le : ", "\nKhong hop le !");
	}
}
void Xuat_Dau_Bang()
{
	cout << "+--------------------------------------------------------------------------------+\n";
	cout << "| STT |               Ten Cong Viec                    | Trang Thai |  Deadline  |\n";
	cout << "+--------------------------------------------------------------------------------+\n";
}
void Data_Bang(Cong_Viec tmp, int STT)
{
	// dung ham setw() de can chinh do rong cua du lieu thi xuat ra man hinh
	cout << "| " << setw(3) << left << STT << " | "
		 << setw(46) << left << tmp.Name << " | "
		 << setw(10) << left << (tmp.Status ? "Da xong" : "Chua xong") << " | "
		 // su dung toan tu 3 ngoi de gan trang thai
		 << (((tmp.DL.ngay > 9 && tmp.DL.thang > 9) || (tmp.DL.ngay < 9 && tmp.DL.thang > 9)) ? setw(2) : setw(3))
		 << right << tmp.DL.ngay << "/" << tmp.DL.thang << "/" << tmp.DL.nam << " | " << endl;

	cout << "+--------------------------------------------------------------------------------+" << endl;
}
void Xuat_Cong_Viec()
{
	if (CV.size() > 0)
	{
		Xuat_Dau_Bang();
		for (int i = 0; i < CV.size(); i++)
		{
			// dung vong lap de chay cac du lieu cong viec trong bang voi STT tang dan
			Data_Bang(CV[i], i + 1);
		}
	}
	else
	{
		cout << "\nCan co it nhat 1 cong viec de xem !" << endl;
	}
}
void Them_Ghi_Chu(Cong_Viec &temp)
{
	Note tmp; // tao 1 struct Note tam thoi de luu du lieu nhap vao tu ban phim

	cout << "\nNhap ghi chu cho cong viec : ";
	fflush(stdin);
	getline(cin, tmp.Ghi_chu);

	temp.Detail.push_back(tmp);
	// day Struct Note vao cuoi vector Detail trong 1 struct Cong_Viec
}
void Xuat_Dau_Ghi_Chu()
{
	cout << "+----------------------------------------------------------------------------------+" << endl;
	cout << "| STT |                              Noi dung ghi chu                              |" << endl;
	cout << "+----------------------------------------------------------------------------------+" << endl;
}
void Ghi_Chu_Dai(Cong_Viec temp, int STT)
{
	cout << "\nGhi chu " << STT << " : " << temp.Detail[STT - 1].Ghi_chu << endl;
}
void Data_Ghi_Chu(Cong_Viec temp, int STT)
{
	cout << "| " << setw(3) << left << STT << " | "
		 << setw(74) << left << temp.Detail[STT - 1].Ghi_chu << " | " << endl;
	// hien thi du lieu cua 1 phan tu trong vector Detail cua 1 struct Cong_Viec
	cout << "+----------------------------------------------------------------------------------+" << endl;
}
int Xem_Ghi_Chu()
{
	Xuat_Cong_Viec(); // hien thi bang cong viec de nguoi dung de kiem soat
	if (CV.size() < 1)
	{
		return 0;
	}
	int vt;
	vt = ktra_Int("\nNhap STT cong viec muon xem ghi chu : ", "\nKhong hop le !");
	Nhap_Lai_VT(vt);
	bool check = false;

	if (CV[vt - 1].Detail.size() < 1)
	{
		cout << "\nCong viec nay khong co ghi chu !" << endl;
		return 0;
	}
	for (int i = 0; i < CV[vt - 1].Detail.size(); i++)
	{
		if (CV[vt - 1].Detail[i].Ghi_chu.length() > 70)
		{
			check = true;
		}
	}
	if (check)
	{
		cout << "\nVi noi dung ghi chu qua 70 ky tu nen se khong the xuat dang bang !" << endl;
		cout << "\nNoi dung ghi chu cua cong viec. " << endl;
		for (int i = 0; i < CV[vt - 1].Detail.size(); i++)
		{
			Ghi_Chu_Dai(CV[vt - 1], i + 1);
		}
	}
	else
	{
		Xuat_Dau_Ghi_Chu();
		for (int i = 0; i < CV[vt - 1].Detail.size(); i++)
		{
			Data_Ghi_Chu(CV[vt - 1], i + 1);
		}
	}
	// dung vong lap de hien thi het cac phan tu trong Detail cua 1 struct CV da chon
}
int Sua_Ghi_Chu()
{
	Xuat_Cong_Viec(); // hien thi bang cong viec de nguoi dung de kiem soat
	int vt;
	vt = ktra_Int("\nNhap STT cong viec muon thay the ghi chu : ", "\nKhong hop le !");
	Nhap_Lai_VT(vt);

	if (CV[vt - 1].Detail.size() < 1)
	{
		cout << "\nCong viec nay khong co ghi chu !" << endl;
		return 0;
	}

	Xuat_Dau_Ghi_Chu();
	for (int i = 0; i < CV[vt - 1].Detail.size(); i++)
	{
		Data_Ghi_Chu(CV[vt - 1], i + 1);
	}
	// xem cong viec va ghi chu
	int tmp;
	tmp = ktra_Int("\nNhap STT ghi chu muon thay : ", "Khong hop le !");
	while (tmp > CV[vt - 1].Detail.size())
	{
		tmp = ktra_Int("\nNhap STT ghi chu muon thay the : ", "Khong hop le !");
	}

	// tao 1 string moi de viet moi
	string s;
	cout << "\nNhap noi dung ghi chu moi : ";
	fflush(stdin);
	getline(cin, s);
	// gan noi dung vua nhap vao ghi chu can thay the
	CV[vt - 1].Detail[tmp - 1].Ghi_chu = s;

	// xem ghi chu vua sua
	Xuat_Dau_Ghi_Chu();
	for (int i = 0; i < CV[vt - 1].Detail.size(); i++)
	{
		Data_Ghi_Chu(CV[vt - 1], i + 1);
	}
}
int Xoa_Ghi_Chu()
{
	// tuong tu ham Sua_Ghi_Chu
	Xuat_Cong_Viec();
	int vt;
	vt = ktra_Int("\nNhap STT cong viec muon xoa ghi chu : ", "\nKhong hop le !");
	Nhap_Lai_VT(vt);

	if (CV[vt - 1].Detail.size() < 1)
	{
		cout << "\nCong viec nay khong co ghi chu !" << endl;
		return 0;
	}

	Xuat_Dau_Ghi_Chu();
	for (int i = 0; i < CV[vt - 1].Detail.size(); i++)
	{
		Data_Ghi_Chu(CV[vt - 1], i + 1);
	}
	// xem cong viec va ghi chu
	int tmp;
	tmp = ktra_Int("\nNhap STT ghi chu muon xoa : ", "Khong hop le !");
	while (tmp > CV[vt - 1].Detail.size())
	{
		tmp = ktra_Int("\nNhap STT ghi chu muon xoa : ", "Khong hop le !");
	}
	CV[vt - 1].Detail.erase(CV[vt - 1].Detail.begin() + tmp - 1);

	// xem ghi chu
	Xuat_Dau_Ghi_Chu();
	for (int i = 0; i < CV[vt - 1].Detail.size(); i++)
	{
		Data_Ghi_Chu(CV[vt - 1], i + 1);
	}
}

void Them_Cong_Viec_Moi()
{
	// tao 1 struct Cong_Viec de nhap du lieu
	Cong_Viec temp;
	Mac_Dinh_Time(temp);
	cout << "\nNhap ten cong viec (toi da 40 ky tu) : ";
	fflush(stdin);
	gets(temp.Name);

	while (strlen(temp.Name) > 40)
	{
		cout << "\nTen cong viec khong duoc qua 40 ky tu !" << endl;
		cout << "Moi nhap lai !" << endl;
		cout << "\nNhap ten cong viec : ";
		fflush(stdin);
		gets(temp.Name);
	}

	int luachon;
	while (true)
	{
		system("cls");
		cout << "========================= MENU =========================" << endl;
		cout << "1. Nhap deadline cho cong viec." << endl;
		cout << "2. Nhap ghi chu cho cong viec." << endl;
		cout << "0. Thoat." << endl;
		cout << "========================================================" << endl;
		luachon = ktra_Int("\n\tNhap lua chon : ", "\nKhong hop le !");
		while (luachon > 2 || luachon < 0)
		{
			luachon = ktra_Int("\n\tNhap lua chon : ", "\nKhong hop le !");
		}
		if (luachon == 1)
		{
			Nhap_Time(temp.DL);
		}
		else if (luachon == 2)
		{
			Them_Ghi_Chu(temp);
		}
		else
		{
			break;
		}
	}

	temp.Status = false; // gan trang thai cong viec = false -> chua xong
	CV.push_back(temp);	 // day struct Cong_Viec vao cuoi vector
}
void Sap_Xep_CV()
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "========================= MENU =========================" << endl;
		cout << "1. Sap xep theo ten cong viec." << endl;
		cout << "2. Sap xep theo Deadline." << endl;
		cout << "3. Sap xep theo tien do cong viec." << endl;
		cout << "4. Thay doi tung cong viec tuy y." << endl;
		cout << "0. Thoat." << endl;
		cout << "========================================================" << endl;
		luachon = ktra_Int("\n\t Nhap lua chon : ", "Khong hop le !");
		while (luachon > 4 || luachon < 0)
		{
			luachon = ktra_Int("\n\t Nhap lua chon : ", "Khong hop le !");
		}
		if (luachon == 1)
		{
			for (int i = 0; i < CV.size() - 1; i++)
			{
				for (int j = i + 1; j < CV.size(); j++)
				{
					if (strcmp(CV[i].Name, CV[j].Name) > 0)
					{
						swap(CV[i], CV[j]);
					}
				}
			}
			// ham sap xep neu so sanh lan luot chu cai cua CV[i] ( theo bang chu cai) ma lon hon cua V[j] thi doi cho chung do nhau
			// ( ham strcmp() tra ve gia tri > 0 neu dieu kien tren dung, = 0 neu cung 1 chuoi va < 0, neu dk sai)
			cout << "Da sap xep xong" << endl;
			Xuat_Cong_Viec();
			system("pause");
		}
		else if (luachon == 2)
		{
			for (int i = 0; i < CV.size() - 1; i++)
			{
				for (int j = i + 1; j < CV.size(); j++)
				{
					// ham so sanh ngay thang am cua CV[i] va CV[j] neu cai nao nho hon thi len truoc
					if (CV[i].DL.nam > CV[j].DL.nam)
					{
						swap(CV[i], CV[j]);
					}
					else if (CV[i].DL.nam == CV[j].DL.nam)
					{
						if (CV[i].DL.thang > CV[j].DL.thang)
						{
							swap(CV[i], CV[j]);
						}
						else if (CV[i].DL.thang == CV[j].DL.thang)
						{
							if (CV[i].DL.ngay > CV[j].DL.ngay)
							{
								swap(CV[i], CV[j]);
							}
						}
					}
				}
			}
			cout << "Da sap xep xong" << endl;
			Xuat_Cong_Viec();
			system("pause");
		}
		else if (luachon == 3)
		{
			stack<Cong_Viec> tmp;
			// tao 1 stack Cong_Viec de luu tam du lieu Cong_Viec chua xong
			for (int i = 0; i < CV.size(); i++)
			{
				if (CV[i].Status) //  xong thi Status = true
				{
					tmp.push(CV[i]);		  // day pt co Trang thai da xong vao stack
					CV.erase(CV.begin() + i); // xoa phan t day khoi vector
				}
			}
			while (!tmp.empty()) // chay cho dne khi ham rong
			{
				CV.push_back(tmp.top()); // day phan tu trong stack vao vector
				tmp.pop();				 // xoa pt day vao di
			}
			cout << "Da sap xep xong" << endl;
			Xuat_Cong_Viec();
			system("pause");
		}
		else if (luachon == 4)
		{
			Xuat_Cong_Viec();
			int vt1;
			vt1 = ktra_Int("\nChon STT cong viec muon thay doi vi tri : ", "\nKhong hop le !");
			Nhap_Lai_VT(vt1);
			int vt2;
			vt2 = ktra_Int("\nNhap STT cong viec muon doi : ", "\nKhong hop le !");
			Nhap_Lai_VT(vt2);
			
			CV.insert(CV.begin() + vt2 - 1, CV[vt1 - 1]); // ham chen phan tu co san ham vector
			CV.erase(CV.begin() + vt1); // ham xoa phan tu cu

			cout << "\nDa xong viec thay doi vi tri cong viec ! " << endl;
			Xuat_Cong_Viec();
			system("pause");
		}
		else
		{
			break;
		}
	}
}

void Tim_Kiem() // Tim kiem cong viec theo ten
{
	cout << "\nNhap ten cong viec can tim : ";
	fflush(stdin);
	char tukhoa[1000];
	gets(tukhoa);

	int dem = 0;
	for (int i = 0; i < CV.size(); i++)
	{
		if (strstr(CV[i].Name, tukhoa) != NULL)
		{
			// hien dau bang
			if (dem == 0)
			{
				Xuat_Dau_Bang();
			}
			// hien du lieu bang
			Data_Bang(CV[i], i + 1);
			dem++;
		}
	}

	if (dem > 0)
	{
		cout << "\nTim thay " << dem << " cong viec phu hop." << endl;
	}
	else
	{
		cout << "\nKhong tim thay cong viec phu hop!" << endl;
	}
}
void Menu_Cong_Viec()
{
	if (CV.size() > 0)
	{
		int luachon;
		while (true)
		{
			system("cls");
			if (CV.size() < 1)
			{
				cout << "\nKhong co cong viec de quan ly." << endl;
				cout << "Vui long nhap cong viec !" << endl;
				system("pause");
				break;
			}
			cout << "========================= MENU =========================" << endl;
			cout << "\n\tA. Cong Viec :" << endl
				 << endl;
			cout << "1. Cap nhap deadline cho cong viec da co." << endl;
			cout << "2. Cap nhat trang thai cong viec." << endl;
			cout << "3. Sap xep cong viec." << endl;
			cout << "4. Thay doi ten cong viec." << endl;
			cout << "5. Tim kiem cong viec." << endl;
			cout << "6. Xoa cong viec." << endl;
			cout << "\n\tB. Ghi Chu :" << endl
				 << endl;
			cout << "7. Sua ghi chu." << endl;
			cout << "8. Them ghi chu cong viec da co." << endl;
			cout << "9. Xoa ghi chu." << endl;
			cout << "0. Thoat." << endl;
			cout << "========================================================" << endl;
			luachon = ktra_Int("\n\t Nhap lua chon : ", "\nKhong hop le !");
			while (luachon > 9 || luachon < 0)
			{
				luachon = ktra_Int("\n\t Nhap lua chon : ", "\nKhong hop le !");
			}
			if (luachon == 1)
			{
				Xuat_Cong_Viec();
				int vt;
				vt = ktra_Int("\nNhap cong viec muon sua deadline : ", "\nKhong hop le !");
				Nhap_Lai_VT(vt);
				Nhap_Time(CV[vt - 1].DL); // nhap lai thoi gian phan tu da chon
				Xuat_Cong_Viec();
				system("pause");
			}
			else if (luachon == 2)
			{
				Xuat_Cong_Viec();
				int vt;
				vt = ktra_Int("\nNhap cong viec da hoan thanh : ", "\nKhong hop le !");
				Nhap_Lai_VT(vt);
				CV[vt - 1].Status = true; // cap nhat Status cua phan tu = true -> da xong
				cout << "\nDa cap nhap xong trang thai !" << endl;
				Xuat_Cong_Viec();
				system("pause");
			}
			else if (luachon == 3)
			{
				Sap_Xep_CV();
			}
			else if (luachon == 4)
			{
				Xuat_Cong_Viec();
				int vt;
				vt = ktra_Int("\nNhap STT cong viec muon doi ten : ", "\nKhong hop le !");
				Nhap_Lai_VT(vt);
				cout << "\nNhap ten moi cho cong viec : ";
				fflush(stdin);
				gets(CV[vt - 1].Name); // viet lai ten cho phan tu da chon
				cout << "\nCap nhat ten thanh cong !" << endl;
				Xuat_Cong_Viec();
				system("pause");
			}
			else if (luachon == 5)
			{
				Tim_Kiem();
				system("pause");
			}
			else if (luachon == 6)
			{
				Xuat_Cong_Viec();
				int vt;
				vt = ktra_Int("\nNhap cong viec can xoa : ", "\nKhong hop le !");
				Nhap_Lai_VT(vt);
				CV.erase(CV.begin() + vt - 1); // xoa phan tu da chon trong vector
				cout << "\nDa xoa thanh cong !" << endl;
				Xuat_Cong_Viec();
				system("pause");
			}
			else if (luachon == 7)
			{
				Sua_Ghi_Chu();
				system("pause");
			}
			else if (luachon == 8)
			{
				Xuat_Cong_Viec();
				int vt;
				vt = ktra_Int("\nNhap cong viec muon them ghi chu : ", "\nKhong hop le !");
				Nhap_Lai_VT(vt);
				Them_Ghi_Chu(CV[vt - 1]);
			}
			else if (luachon == 9)
			{
				Xoa_Ghi_Chu();
				system("pause");
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		cout << "\nPhai co it nhat 1 cong viec de quan ly !" << endl;
		system("pause");
	}
}
void Ghi_file()
{
	if (ktra_thong_tin)
	{
		Mac_Dinh_TT();
	}

	if (CV.size() > 0)
	{
		fstream fp;							// khai bao ham nhap du lieu
		fp.open("data.txt", ios_base::out); // chon file ghi du lieu, va lenh ghi
		if (fp.fail() == true)				// ham kiem tra xem file co duoc mo khong
		{
			cout << "\nLoi khong the mo file ...";
		}
		else
		{
			fp << "Thong tin nguoi dung : " << endl;
			fp << "Ten : " << TT.name << endl;
			fp << "Tuoi : " << TT.Tuoi << endl;
			fp << "Cong viec : " << TT.viec_lam << endl;
			fp << "So dien thoai : " << TT.SDT << endl;
			fp << "Gioi tinh : " << (TT.Gioi_tinh == 1 ? "Nam" : (TT.Gioi_tinh == 0 ? "Nu" : "Khong ro")) << endl;
			fp << "Email : " << TT.Email << endl;
			for (int i = 0; i < CV.size(); i++) // vong lap luu file
			{
				fp << "\nTen cong viec : " << CV[i].Name << endl;
				fp << "Trang thai : " << (CV[i].Status ? "Da xong" : "Chua xong") << endl;
				fp << "Deadline : " << CV[i].DL.ngay << "/" << CV[i].DL.thang << "/" << CV[i].DL.nam << endl;
				fp << "Ghi chu cua cong viec : " << endl;
				for (int j = 0; j < CV[i].Detail.size(); j++)
				{
					fp << j + 1 << ". " << CV[i].Detail[j].Ghi_chu << endl;
				}
			}
			cout << "\nGhi file thanh cong !" << endl;
		}
		fp.close(); // dong file
	}
	else
	{
		cout << "\nChua co du lieu ghi file." << endl;
		cout << "\nVui long nhap cong viec !" << endl;
	}
}

int main ()
{
    int luachon;
	while (true)
	{
		system("cls");
        cout << "========================= MENU =========================" << endl;
		cout << "1. Nhap thong tin." << endl;
		cout << "2. Xem thong tin." << endl;
		cout << "3. Nhap cong viec moi." << endl;
		cout << "4. Xem cong viec." << endl;
        cout << "5. Quan ly cong viec." << endl;
        cout << "6. Xem ghi chu cong viec." << endl;
		cout << "7. Ghi file txt." << endl;
		cout << "0. Thoat." << endl;
        cout << "========================================================" << endl;
		luachon = ktra_Int("\n\tNhap lua chon : ","\nKhong hop le !");
		
		while (luachon > 7 || luachon < 0)
		{
			luachon = ktra_Int("\n\tNhap lua chon : ","\nKhong hop le !");
		}
		
		if (luachon == 1)
		{
			Nhap_thong_tin();
		}
		else if (luachon == 2)
		{
			Xuat_TT();
            system("pause");
		}
		else if (luachon == 3)
		{
			Them_Cong_Viec_Moi();
		}
		else if (luachon == 4)
		{
			Xuat_Cong_Viec();
            system("pause");
		}
        else if (luachon == 5)
        {
            Menu_Cong_Viec();
        }
        else if (luachon == 6)
        {
            Xem_Ghi_Chu ();
            system("pause");
        }
		else if (luachon == 7)
		{
			Ghi_file();
			system("pause");
		}
		else
        {
			cout << "\n======================= Tam biet =======================" << endl;
			break;
        }
	}
    return 0;
}
