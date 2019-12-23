#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>

class book
{
   int id;
   char name[25];
   int price;
   char publisher[20];
  public:
   void getdata();
   void putdata();
   void modify();
   int getid()
   {
      return id;
   }
   int getprice()
   {
      return price;
   }
};
void book::getdata()
{
   cout<<"\n\n\tEnter Book ID: ";
   cin>>id;
   cout<<"\n\n\tEnter the name of book: ";
   gets(name);
   cout<<"\n\n\tEnter name of publisher: ";
   gets(publisher);
   cout<<"\n\n\tEnter price of book: Rs. ";
   cin>>price;
}
void book::putdata()
{
   cout<<"\n\n\tBook ID is: "<<id;
   cout<<"\n\n\tName of the book is: "<<name;
   cout<<"\n\n\tName of the publisher is: "<<publisher;
   cout<<"\n\n\tPrice of the book is: Rs. "<<price;
}
void book::modify()
{
   cout<<"\n\n\tOld Name\t"<<name;
   cout<<"\n\n\tOld Publisher\t"<<publisher;
   cout<<"\n\n\tOld Price\t"<<price;
   cout<<"\n\n\tEnter new details for book having code\t"<<id;
   cout<<"\n\n\tEnter new name\t";
   gets(name);
   cout<<"\n\n\tEnter New Publisher\t";
   gets(publisher);
   cout<<"\n\n\tEnter New Price\t";
   cin>>price;
}
void showallbooks()
{
   ifstream fio;
   fio.open("book.dat",ios::in|ios::binary);
   cout<<"\n\n\n\t\t\tList of books:-\n";
   book ob;
   while(fio.read((char*)&ob,sizeof(ob)))
   {
       ob.putdata();
   }
   fio.close();
}
void purchase()
{
    showallbooks();
    char ch;
    book ob;
    int qty;
    ifstream fin("book.dat" , ios::in|ios::binary);
    ofstream fout("temp.dat",ios::out|ios::binary);
    int id,found=0,total=0;

	cout<<"\n\tEnter id of the book you want to buy:\t ";
	found=0;
	cin>>id;
	cout<<"\n\tEnter Quantity : ";
	cin>>qty;
	while(fin.read((char*)&ob, sizeof(ob)))
	{
	   if(ob.getid()==id)
	   {
	      fout.write((char*)&ob,sizeof(ob));
	      found=1;
	      total+=ob.getprice()*qty;
	      break;
	   }
	}
	if(found==0)
	{
	   cout<<"\n\tBook is not available";
	   //return;
	}
    fout.close();
    fin.close();
    if(found==1)
    {
    clrscr();
    fin.open("temp.dat",ios::in|ios::binary);
    while(fin.read((char*)&ob,sizeof(ob)))
    {
       ob.putdata();
    }
    cout<<"\n\t\tTOTAL PRICE IS: Rs"<<total<<endl;
    }
}
void addbook()
{
   book ob,ob1;
   ob.getdata();
   int found=0;
   ofstream fio;
   fio.open("book.dat",ios::app|ios::binary);
   fio.seekp(0,ios::beg);
   ifstream fin("book.dat",ios::in|ios::binary);
   fin.seekg(0,ios::beg);
   while(fin.read((char*)&ob1,sizeof(ob1)))
   {
      if (ob1.getid()==ob.getid())
      {
	 cout<<"\nBOOK ALREADY EXISTS\n";
	 ob1.putdata();
	 found=1;
	 break;
      }
   }
   if(found==0)
   {
      fio.write((char*)&ob,sizeof(ob));
   }
   fio.close();
   showallbooks();
}
void deletebook()
{
   int idno;
   cout<<"ENTER ID OF BOOK YOU WANT TO DELETE:\t";
   cin>>idno;
   book ob1;
   ifstream fin;
   fin.open("book.dat",ios::in|ios::binary);
   ofstream fout;
   fout.open("book1.dat",ios::out|ios::binary);
   while(fin.read((char*)&ob1,sizeof(ob1)))
   {
      if(ob1.getid()!=idno)
      {
	 fout.write((char*)&ob1,sizeof(ob1));
	 cout<<"THE BOOK IS DELETED";
      }
   }
   fout.close();
   fin.close();
   remove("book.dat");
   rename("book1.dat","book.dat");
   showallbooks();
}
void modifybook()
{
   cout<<"\n\n\tENTER THE ID OF BOOK WHOSE CONTENTS NEED TO BE MODIFIED:  ";
   int idcod;
   cin>>idcod;
   book ob;
   ifstream fin;
   fstream fio("book.dat", ios::in|ios::out|ios::binary);
   while(fio.read((char*)&ob,sizeof(book)))
   {
      int size=fio.tellg()-sizeof(ob);
      if(ob.getid()==idcod)
      {
	 ob.modify();
	 fio.seekp(size,ios::beg);
	 fio.write((char*)&ob,sizeof(ob));
      }
   }
   fio.close();
   showallbooks();
}

void main()
{
   char choice;
   do
   {
      clrscr();
      cout<<"\n[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]";
      cout<<"\n\n\t\t\tBOOK  SHOP  BILLING\n";
      cout<<"\n\t\t\t\t\t\t       BY:ANUSREE and MARIA";
      cout<<"\n[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]";
      cout<<"\n\n\n\n\n\n"
      <<"\t\t\t\t   MAIN MENU\n"
      <<"================================================================================\n\n"
      <<"\t\t\t  1.ADD BOOK\n\n"
      <<"\t\t\t  2.DISPLAY LIST\n\n"
      <<"\t\t\t  3.PURCHASE BOOK\n\n"
      <<"\t\t\t  4.DELETE BOOK\n\n"
      <<"\t\t\t  5.MODIFY BOOK\n\n"
      <<"\t\t\t  6.QUIT\n\n"
      <<"\t\t\t\tEnter your choice(1-6) : ";
      choice=getch();
      switch (choice)
      {
	 case '1':clrscr();
		  addbook();
		  break;
	 case '2':clrscr();
		  showallbooks();
		  break;
	 case '3':clrscr();
		  purchase();
		  break;
	 case '4':clrscr();
		  deletebook();
		  break;
	 case '5':clrscr();
		  modifybook();
		  break;
	 case '6':clrscr();
		  cout<<"\n\n\n\t\t\tTHANKS FOR INTERACTING";
		  exit(0);
		  break;
	 default: cout<<"\n\n\nWRONG CHOICE ENTERED!!\n\n";
      }
      cout<<"\n\n\n\t    PRESS ANY KEY TO RETURN: ";
      getch();
   }while(choice!=6);
}























