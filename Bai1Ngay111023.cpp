#include<bits/stdc++.h>
using namespace std;
class nguoi
{
	protected:
		string ht;
		string ns;
		string dc;
	public:
		nguoi()
		{
			ht=" ";
			ns=" ";
			dc=" ";
		}
		nguoi(string name,string birth,string address)
		{
			name=ht;
			birth=ns;
			address=dc;
		}
		void nhap();
};
void nguoi::nhap()
{
	cout<<"\nNhap ho ten khach hang:";
	cin.ignore();
	getline(cin,ht);
	cout<<"Ngay sinh:";
	cin>>ns;
	cout<<"Dia chi:";
    cin.ignore();
	getline(cin,dc);
}
class khachhang : public nguoi
{
	private:
		string mkh;
		int chisotruoc,chisosau;
		double tien;
	public:
		void nhap();
		void xuat();
		void timkiem(string ht1);
	    double tinhtien();
	    int bactieuthu();
};
void khachhang::nhap()
{
	nguoi::nhap();
	cout<<"Ma khach hang:";
	cin>>mkh;
	cout<<"Chi so truoc, chi so sau:";
	cin>>chisotruoc>>chisosau;
}
void khachhang::xuat()
{
	cout<<"\n"<<setw(5)<<right<<ht<<" "<<setw(5)<<right<<ns<<" "<<setw(5)<<right<<dc<<" "<<setw(5)<<right<<mkh<<" "<<setw(5)<<right<<chisotruoc<<" "<<setw(5)<<right<<chisosau<<" "<<setw(5)<<right<<bactieuthu();
}
void khachhang::timkiem(string ht1)
{
	if(ht1==ht)
	{
		cout<<"\n"<<setw(5)<<right<<mkh<<" "<<setw(5)<<right<<chisosau-chisotruoc<<" "<<setw(5)<<right<<tinhtien();
	}
}
double khachhang::tinhtien()
{
	int sodien;
	tien=0;
	sodien=chisosau-chisotruoc;
	if(sodien<=50)
	{
		tien=sodien*1678;
	}
	if(sodien>50 && sodien<=100)
	{
		tien=50*1678+(sodien-50)*1734;
	}
	if(sodien>100 && sodien<=200)
	{
		tien=50*1678+50*1734+(sodien-100)*2014;
	}
	if(sodien>200 && sodien<=300)
	{
		tien=50*1678+50*1734+100*2014+(sodien-200)*2536;
	}
	if(sodien>300)
	{
		tien=50*1678+50*1734+100*2014+200*2536+(sodien-300)*2834;
	}
	return tien;
}
int khachhang::bactieuthu()
{
	int sodien;
	sodien=chisosau-chisotruoc;
	if(sodien<=50)
	{
		return 1;
	}
	if(sodien>50 && sodien<=100)
	{
	    return 2;
	}
	if(sodien>100 && sodien<=200)
	{
		return 3;
	}
	if(sodien>200 && sodien<=300)
	{
		return 4;
	}
	if(sodien>300)
	{
	    return 5;
	}
}
class sokhachhang{
	private:
		int n;
		khachhang *a;
	public:
		void nhap()
		{
			cout<<"So khach hang:";
			cin>>n;
			a=new khachhang[n+1];
			for (int i=0;i<n;i++)
			{
				cout<<"NHAP THONG TIN";
				a[i].nhap();
				a[i].bactieuthu();
			}
		}
		void xuat()
		{
			for (int i=0;i<n;i++)
			{
				cout<<"\nKhach hang can tim kiem:";
				a[i].xuat();
			}
		}
		void timkiem()
		{
			string hoten1;
			cin.ignore();
			cout<<"\nNhap ho ten can tim kiem:";
			getline(cin,hoten1);
			cout<<"\n"<<setw(10)<<right<<"Ma Khach Hang"<<setw(10)<<right<<"So Dien"<<setw(10)<<right<<"So Tien";
            for (int i=0;i<n;i++)
            {
            	a[i].timkiem(hoten1);
			}
        }
        void thongke()
        {
        	int b;
        	cout<<"\nNhap bac tieu thu muon thong ke:";
        	cin>>b;
        	cout<<"THONG KE KHACH HANG THEO BAC TIEU THU DIEN";
        	cout<<"\n"<<setw(5)<<right<<"Ho Ten"<<setw(5)<<right<<"Ngay Sinh"<<setw(5)<<right<<"Dia Chi"<<setw(5)<<right<<"Ma Khach Hang"<<setw(5)<<right<<"Chi So Truoc"<<setw(5)<<right<<"Chi So Sau"<<setw(5)<<right<<"Bac Tieu Thu";
        	for (int i=0;i<n;i++)
        	{
        		if(a[i].bactieuthu()==b)
        		{
        			a[i].xuat();
				}
			}
		}
};
int main()
{
	sokhachhang a;
	a.nhap();
    a.xuat();
    a.timkiem();
    a.thongke();
}
