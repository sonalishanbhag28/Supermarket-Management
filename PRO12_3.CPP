#include<iomanip.h>
#include<string.h>
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>
#include<graphics.h>
#include<ctype.h>
int ser;
float total=0;
int x=0,y=0,z=0;
int length(int num)
{
	int c=0,d;
	while(num>0)
	{
		c++;
		num=num/10;
	}
	return c;
}
class catesh
{

	char name[50];
	float price;
	public:
	int qty;
	int sno;
	void read()
	{
		cout<<"Enter Product Name: ";
		gets(name);
		cout<<"Enter Price: ";
		cin>>price;
		cout<<"Enter Quantity: ";
		cin>>qty;

	}
	void display()
	{
		x=x+2;
		gotoxy(2,4+x);
		cout<<sno;
		gotoxy(22,4+x);
		cout<<name;
		gotoxy(42,4+x);
		cout<<price;
		gotoxy(58,4+x);
		cout<<qty;
		cout<<endl;

	}
	int retsno()
	{
		return sno;
	}
	char *retname()
	{
		return name;
	}
	int retqty()
	{
		return qty;
	}
	int retprice()
	{
		return price;
	}
};
struct bill
{
	char name[100];
	int s,p,q,np;
	void display1()
	{
		y=y+2;
		np=p*q;
		gotoxy(2,4+y);
		cout<<name;
		gotoxy(22,4+y);
		cout<<p;
		gotoxy(38,4+y);
		cout<<q;
		gotoxy(56,4+y);
		cout<<np;
		cout<<endl;

	}
	void display2()
	{
	np=p*q;
	z=z+2;
	gotoxy(4,7+z);
	cout<<name;
	gotoxy(25,7+z);
	cout<<p;
	gotoxy(45,7+z);
	cout<<q;
	gotoxy(64,7+z);
	cout<<np;
	}
	void calc()
	{
		y=0;
		total=total+(p*q);
		gotoxy(69,17);
		cout<<"\nSub Total   Rs. "<<total;
		cout<<"\nCGST        Rs. "<<0.0125*total;
		cout<<"\nSGST        Rs. "<<0.0125*total;
		cout<<"\nAmount      Rs. "<<(0.025*total)+total;
	}

}obj;

void serial()
{
	ifstream fin;
	fin.open("serial.txt",ios::in);
	fin>>ser;
	fin.close();
}
int searchfile(int number)
{
	ifstream fin;
	int found=0,q;
	catesh cat;
	fin.open("catesh.dat",ios::binary);
	while(!fin.eof())
	{
		fin.read((char*)&cat,sizeof(cat));
		if(cat.retsno()==number)
		{       int s;
			float p;
			char *k;
			s=cat.retsno();
			q=cat.retqty();
			p=cat.retprice();
			k=cat.retname();
			cout<<"Record found."<<endl;
			gotoxy(1,5);
			cout<<"Product No.";
			gotoxy(22,5);
			cout<<"Product Name";
			gotoxy(42,5);
			cout<<"Price";
			gotoxy(58,5);
			cout<<"Quantity";
			gotoxy(1,7);
			cout<<s;
			gotoxy(22,7);
			cout<<k;
			gotoxy(42,7);
			cout<<p;
			gotoxy(58,7);
			cout<<q;
			getch();
			found=1;
			return(q);
		}
	}
	if(found==0)
	{cout<<"Record not found.";
	return -1;
	}
	fin.close();
	cout<<"\n";
	system("pause");
	return 0;


}
int namesearchfile(char search[100])
{
	ifstream fin;
	int found=0,i,j,q;
	catesh cat;
	char *result;
	fin.open("catesh.dat",ios::binary);
	while(fin.read((char*)&cat,sizeof(cat)))
	{
		result=cat.retname();
		if(strcmp(result,search)==0)
		{       int s;
			float p;
			found=1;
			char *karen;
			s=cat.retsno();
			q=cat.retqty();
			p=cat.retprice();
			karen=cat.retname();
			cout<<"Record found."<<endl;
			gotoxy(1,5);
			cout<<"Product No.";
			gotoxy(22,5);
			cout<<"Product Name";
			gotoxy(42,5);
			cout<<"Price";
			gotoxy(58,5);
			cout<<"Quantity";
			gotoxy(1,7);
			cout<<s;
			gotoxy(22,7);
			cout<<karen;
			gotoxy(42,7);
			cout<<p;
			gotoxy(58,7);
			cout<<q;
			getch();
			return(p);
		}
	}
	if(found==0)
	{
	cout<<"Record not found.";
	return(0);
	}
   cout<<"\n";
   system("pause");
   return(0);

}
void modifyfile()
{
	fstream fin;

	fin.open("catesh.dat",ios::binary|ios::in|ios::out);

	int found=0;
	catesh cat;
	int numbe,poss;
	cout<<"Enter Product Number of the item you wish to modify\n";
	cin>>numbe;

	while(!fin.eof())
	{
		fin.read((char*)&cat,sizeof(cat));
		poss=fin.tellg()-sizeof(cat);
		if(cat.retsno()==numbe)
		{       cout<<"Record Found.\n";
			int s,q;
			float p;
			found=1;
			char *karen;
			s=cat.retsno();
			q=cat.retqty();
			p=cat.retprice();
			karen=cat.retname();
			gotoxy(1,7);
			cout<<"Product No.";
			gotoxy(22,7);
			cout<<"Product Name";
			gotoxy(42,7);
			cout<<"Price";
			gotoxy(58,7);
			cout<<"Quantity";
			gotoxy(1,9);
			cout<<s;
			gotoxy(22,9);
			cout<<karen;
			gotoxy(42,9);
			cout<<p;
			gotoxy(58,9);
			cout<<q;
			char an,an1;
			cout<<"\n\nIs this the one you want to modify?(Y/N)\n";
			cin>>an;
			clrscr();
			if(an=='N'||an=='n')
			{
				cout<<"Sorry, try again.\n";
				getch();
				break;
			}
			else if(an=='Y'||an=='y')
			{
				cout<<"\nEnter new details for Product Number "<<cat.retsno()<<" :\n\n";
				cat.read();
				fin.seekp(poss);
				fin.write((char*)&cat,sizeof(cat));
				cout<<"Successfully Modified.\n";
				break;
			}
			else
			{	cout<<"Invalid.\n";
				getch();
				break;
			}
		}
	}
	if(found==0)
	{
	cout<<"Record does not exist.\n";
	}
	cout<<"\n";
	system("pause");
	fin.close();
}
void writefile()
{
	catesh cat;
	cat.read();
	cat.sno=ser;
	ofstream fout;
	fout.open("catesh.dat",ios::binary|ios::app);
	fout.write((char*)&cat,sizeof(cat));
	ser++;
	fout.close();

}
void readfile()
{
	catesh cat;
	ifstream fin("catesh.dat",ios::binary);
	gotoxy(2,4);
	cout<<"Product No.";
	gotoxy(22,4);
	cout<<"Product Name";
	gotoxy(42,4);
	cout<<"Price";
	gotoxy(58,4);
	cout<<"Quantity";
	while(fin.read((char*)&cat,sizeof(cat)))
	cat.display();
	cout<<endl;
	fin.close();
}
void deletefile(int s)
{
	catesh cat;
	int flag1=0;
	ifstream fin("catesh.dat",ios::binary);
	ofstream fout("catemp.dat",ios::binary);
	while(fin.read((char*)&cat,sizeof(cat)))
	{
		if(cat.retsno()!=s)
		fout.write((char*)&cat,sizeof(cat));
		else
		flag1=1;
	}
	if(flag1==0)
	cout<<"Not Found.\n";
	else
	cout<<"Record Deleted.\n";
	fin.close();
	fout.close();
	remove("catesh.dat");
	rename("catemp.dat","catesh.dat");
	cout<<"\n";
	system("pause");
}
void order(int num)
{       x=0;
	int q,qt;
	clrscr();
	q=searchfile(num);
	if(q==-1)
		getch();
	else if(q==0)
	{
	cout<<"\n\nSorry, Product out of Stock.\n";
	system("pause");
	}
	else
	{
		cout<<"\n\nEnter Quantity: ";
		cin>>qt;
		if(qt>q)
		{
			cout<<"\nSorry, Limited Stock only.\n";
			system("pause");
		}
		else if(qt<=q)
		{
		int poss;
		catesh cat;
		ofstream fout;
		fstream fin("catesh.dat",ios::binary|ios::in|ios::out);
		fout.open("bill.dat",ios::binary|ios::app|ios::out);
		while(!fin.eof())
		{
			fin.read((char*)&cat,sizeof(cat));
			poss=fin.tellg()-sizeof(cat);
			if(cat.retsno()==num)
			{
				int quan=cat.retqty();
				quan-=qt;
				cat.qty=quan;
				fin.seekp(poss);
				fin.write((char*)&cat,sizeof(cat));
				obj.p=cat.retprice();
				obj.q=qt;
				strcpy(obj.name,cat.retname());
				fout.write((char*)&obj,sizeof(obj));
				cout<<"Order Successful.\n";
				system("pause");
				x=0;
				break;


			}
		}

	}


}
}
void billing()
{
	clrscr();
	z=0;

	cout<<"\t\t\t\tCATESH SUPERMARKET\n\n";
	cout<<"\t\t\t\t    INVOICE\n";
	cout<<"\t\t\t________________________________";
	bill obj;
	ifstream fin("bill.dat",ios::binary);
	gotoxy(4,6);
	cout<<"Product Name";
	gotoxy(25,6);
	cout<<"Price";
	gotoxy(45,6);
	cout<<"Quantity";
	gotoxy(64,6);
	cout<<"Net Price";
	while(fin.read((char*)&obj,sizeof(obj)))
	{	obj.display2();
		obj.calc();
	}
	fin.close();
	total=0;
	z=0;
	cout<<endl;
	system("pause");
}



void cart()
{
	bill obj;
	clrscr();
	cout<<"CART\n";
	ifstream fin("bill.dat",ios::binary);
	gotoxy(2,4);
	cout<<"Product Name";
	gotoxy(22,4);
	cout<<"Price";
	gotoxy(38,4);
	cout<<"Quantity";
	gotoxy(56,4);
	cout<<"Net Price";
	while(fin.read((char*)&obj,sizeof(obj)))
	obj.display1();
	cout<<endl;
	fin.close();
}


void main()
{
serial();
clrscr();
label1:  x=0,y=0;
	 clrscr();


	cout<<"\n\n\t\t\t     CATESH SUPERMARKET\n\n\n\t\t\t         MAIN MENU\n\n\n\t\t\t     1. Administrator\n\t\t\t     2. Customer\n\t\t\t     3. Exit\n\n\t\t\t     Enter choice: ";
	char m;
	cin>>m;
	clrscr();
	switch(m)
	{
	case '1':
	cout<<"WELCOME, ADMIN!\n";
	cout<<"Enter password to continue:\n";
	char xyz[50];
	cin>>xyz;
	if(strcmp(xyz,"catesh")!=0)
	break;
	label2:	y=0; clrscr();

	cout<<"\n\n\t\t\t         ADMINISTRATOR\n\n\n\t\t\t     1. Add Products\n\t\t\t     2. Inventory\n\t\t\t     3. Modify Products\n\t\t\t     4. Search for a Product\n\t\t\t     5. Delete Products\n\t\t\t     6. Go back to Main Menu\n\t\t\t     7. Exit\n\n\t\t\t     Enter choice: ";
	int s; char ch;
	cin>>ch;
	switch(ch)
	{       catesh cat;
		case '1':
		clrscr();
		cout<<"ADD PRODUCT\n";
		cout<<"Enter details as specified:\n";
		writefile();
		getch();
		break;

		case '2':
		clrscr();
		cout<<"INVENTORY\n";
		x=0;
		readfile();
		getch();
		break;

		case '3':
		clrscr();
		cout<<"MODIFY\n\n";
		modifyfile();
		break;

		case '4':
		clrscr();
		cout<<"SEARCH\n\na)Search by Product Number\n\nb)Search by Product Name\nEnter your choice:";
		char fish;
		cin>>fish;
		int numb;
		char search[100];
		if(fish=='a')
		{
		clrscr();
		cout<<"SEARCH BY PRODUCT NUMBER\n\n";
		cout<<"Enter Product Number:";
		cin>>numb;
		searchfile(numb);
		}
		else if(fish=='b')
		{ clrscr();
		  cout<<"SEARCH BY PRODUCT NAME\n\n";
		  cout<<"Enter Product Name(Case Sensitive):";
		  gets(search);
		  namesearchfile(search);
		}
		else
			cout<<"Invalid.\n";
		getch();
		goto label2;

		case '5':
		clrscr();
		char ans1;
		cout<<"DELETE\n\na)Individual Record\n\nb)All Records\n\nEnter your choice:";
		cin>>ans1;
		clrscr();
		if(ans1=='a')
		{
		clrscr();
		cout<<"DELETING INDIVIDUAL RECORD\n\n";
		cout<<"Enter Product No.: ";
		cin>>s;
		deletefile(s);
		}
		else if(ans1=='b')
		{
		clrscr();
		char abc;
		cout<<"DELETE ALL RECORDS\n\n";
		cout<<"Are you sure you'd like to proceed?(Y/N)\n";
		cin>>abc;
		if(abc=='Y'||abc=='y')
		{
		remove("catesh.dat");

		cout<<"\nRecords deleted.\nEnter any key to continue.";
		}
		else if(abc=='N'||abc=='n')
		goto label2;

		}
		else
			cout<<"Invalid.\n";
		getch();
		break;

		case '6':
		clrscr();
		cout<<"Go back to Main Menu?(Y/N)\n";
		char xyz;
		cin>>xyz;
		if(xyz=='Y'||xyz=='y')
		goto label1;
		else if(xyz=='N'||xyz=='n')
		goto label2;
		else
		{
		cout<<"Invalid.\n";
		getch();
		goto label2;
		}

		case '7':
		ofstream fout;
		fout.open("serial.txt",ios::out);
		fout<<ser;
		fout.close();
		exit(0);
		break;

		default:
		cout<<"Invalid.\n";
	}
	goto label2;
	case '2':
		clrscr();
		char name[100];
		cout<<"Enter your name: ";
		gets(name);
		name[0]=toupper(name[0]);
		cout<<"Welcome, "<<name<<"!\n";
		system("pause");
	label3:	y=0;
		clrscr();

		cout<<"\n\n\t\t\t         CUSTOMER\n\n\n\t\t\t     1. Place an Order\n\t\t\t     2. View Cart\n\t\t\t     3. Clear Cart\n\t\t\t     4. Checkout\n\t\t\t     5. Go back to Menu\n\t\t\t     6. Exit\n\n\t\t\t\tEnter choice: ";
		gotoxy(63,2);
		cout<<"Customer: "<<name;
		gotoxy(46,13);
		int choice;
		cin>>choice;
		clrscr();
		switch(choice)
		{
		case 1:
		ifstream fin("catesh.dat",ios::binary);
		if(!fin)
		{
		clrscr();
		cout<<"No products currently available. Sorry for the inconvenience.\n\n";
		system("pause");
		goto label1;
		}
		cout<<"PLACE AN ORDER\n";
		cout<<"\nLoading Inventory... Please wait.\n";
		delay(500);
		system("pause");
		x=0;
		clrscr();
		cout<<"PLACE AN ORDER\n";
		readfile();
		cout<<"\nWould you like to place an order?(Y/N)\n";
		char answer;
		cin>>answer;
		if(answer=='Y'||answer=='y')
		{       cout<<"\nEnter Product Number:\n";
			int num,k;
			cin>>num;
			order(num);
			goto label3;
		}
		else if(answer=='N'||answer=='n')
			goto label3;
		else
		{
			cout<<"Invalid.\n";
			system("pause");
			goto label3;
		}


		case 2:
		clrscr();
		cout<<"CART\n";
		cout<<"Loading Cart... Please wait.\n";
		system("pause");
		clrscr();
		cart();

		getch();
		goto label3;

		case 3:
		cout<<"All items currently in your cart will be cleared.\nAre you sure you'd like to proceed?(Y/N)\n";
		char ans;
		cin>>ans;
		if(ans=='Y'||ans=='y')
		{
		remove("bill.dat");
		cout<<"\n\nCart Successfully Cleared.\n";
		}
		else if(ans=='N'||ans=='n')
		system("pause");
		else
		cout<<"Invalid.\n";
		getch();
		goto label3;

		case 4:
		cart();

		ifstream finny("bill.dat",ios::binary);
		if(!finny)
		{
		clrscr();
		cout<<"Your cart seems to be empty. Please add items before checking out.\n\n";
		system("pause");
		goto label3;
		}
		cout<<"\n\nProceed to Checkout?(Y/N)\n";
		char answer1;
		cin>>answer1;
		if(answer1=='Y'||answer1=='y')
		{
			clrscr();
			cout<<"Generating bill, please wait...\n";
			delay(1000);
			system("pause");
			clrscr();
			billing();
			getch();
			clrscr();

			cout<<"Please confirm payment.\n";
			delay(250);
			cout<<"Payment sucessful\n";
			system("pause");


				clrscr();
				cout<<"Please wait, generating invoice...\n";
				system("pause");
		       label4:	billing();

				clrscr();
				cout<<"Thank you for shopping with us!\n";
				getche();
				cout<<"1. View Invoice Again\n2. Continue Shopping\n3. Main Menu\n4. Exit\nEnter choice:\n";
				int la;
				cin>>la;
				if(la==1)
				goto label4;
				else if(la==2)
				{remove("bill.dat");
				goto label3;
				}
				else if(la==3)
				{remove("bill.dat");
				goto label1;
				}
				else if(la==4)
			       {	ofstream fout;
		fout.open("serial.txt",ios::out);
		fout<<ser;
		fout.close();remove("bill.dat");
				exit(0);
				}


		}
		else if(answer1=='N'||answer1=='n')
		goto label3;
		else cout<<"Invalid";
		goto label3;

		case 5:
		cout<<"Go back to Main Menu?(Y/N)\n";
		char xyz;
		cin>>xyz;
		if(xyz=='Y'||xyz=='y')
		goto label1;
		else if(xyz=='N'||xyz=='n')
		goto label3;
		else
		{
		cout<<"Invalid.\n";
		getch();
		goto label3;
		}


		case 6:
		ofstream fout;
		fout.open("serial.txt",ios::out);
		fout<<ser;
		fout.close();
		exit(0);
		break;

		default :
		clrscr();
		cout<<"Invalid.\n";
		getch();
		goto label3;


	 }

	case '3':
	ofstream fout;
	fout.open("serial.txt",ios::out);
	fout<<ser;
	fout.close();
	exit(0);
	break;
	default:
	cout<<"Invalid";
	getch();
	clrscr();
	}
	goto label1;

}


