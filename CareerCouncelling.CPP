#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<iomanip.h>

void display();
void c_show(int);
char name[50],password[50];

class counselling
{
   char best_stream[50];
   char extra[50];
   char bname[50];
   long bid;
   long book_id;
   char book_name[50];
   char b_pass[50];
   char cname[40];
   double salary;
   int cid;
   char name[50];
   char password[20];
   char interest[20];
   float marks[5];
   float test_mark[3][3];
   public :
   counselling()
 {
  strcpy(best_stream,"Not Assigned");
  strcpy(extra,"Not Assigned");
  strcpy(name,"Not Assigned");
  strcpy(bname,"Not Assigned");
  strcpy(cname,"Not Assigned");
  strcpy(interest,"Not Assigned");
  strcpy(password,"Not Assigned");
  strcpy(b_pass,"Not Assigned");
  strcpy(book_name,"Not Assigned");
  bid=0;
  book_id=0;
  salary=0;
  cid=0;
 }
  int rid()
   {
    return cid;
   }
 char *get_name()
 {
  return(name);
 }
 char *get_pass()
 {
  return(password);
 }
 void assign_detail(char a[],char b[])
 {
  strcpy(name,a);
  strcpy(password,b);
 }
  void additional(int d)
 {
  if(d==1)
   strcpy(extra," Medical");
  else
   strcpy(extra," Non Medical");
 }
 void calc(int a,int b,int c,int d)
{
 if(a>b&&a>c)
 {
  test_mark[2][0]=1.5;
  test_mark[2][1]=0;
  test_mark[2][2]=0;
 }
 else if(b>a&&b>c)
 {
  test_mark[2][0]=0;
  test_mark[2][1]=1.5;
  test_mark[2][2]=0;
 }
 else if(c>a&&c>b)
 {
  test_mark[2][0]=0;
  test_mark[2][1]=0;
  test_mark[2][2]=1.5;
 }

 else if(a==b&&a==c)
  {
  if((test_mark[0][0]+test_mark[1][0])>(test_mark[0][1]+test_mark[1][1])&&
      (test_mark[0][0]+test_mark[1][0])>(test_mark[0][2]+test_mark[1][2]) )
       {
	  test_mark[2][0]=1.5;
	  test_mark[2][1]=0;
	  test_mark[2][2]=0;
       }
  else if((test_mark[0][1]+test_mark[1][1])>(test_mark[0][2]+test_mark[1][2]))
      {
	  test_mark[2][0]=0;
	  test_mark[2][1]=1.5;
	  test_mark[2][2]=0;
      }

  else
       {
	  test_mark[2][0]=0;
	  test_mark[2][1]=0;
	  test_mark[2][2]=1.5;
       }
  }
 else if(a==b)
 {
  if((test_mark[0][0]+test_mark[1][0])>(test_mark[0][1]+test_mark[1][1]))
     {
	  test_mark[2][0]=1.5;
	  test_mark[2][1]=0;
	  test_mark[2][2]=0;
   }

  else
     {
	  test_mark[2][0]=0;
	  test_mark[2][1]=1.5;
	  test_mark[2][2]=0;
     }

 }
 else if(b==c)
 {
  if((test_mark[0][1]+test_mark[1][1])>(test_mark[0][2]+test_mark[1][2]))
     {
	  test_mark[2][0]=0;
	  test_mark[2][1]=1.5;
	  test_mark[2][2]=0;
     }

  else
    {
	  test_mark[2][0]=0;
	  test_mark[2][1]=0;
	  test_mark[2][2]=1.5;
    }

 }
 else if(a==c)
 {
  if( (test_mark[0][0]+test_mark[1][0])>(test_mark[0][2]+test_mark[1][2]) )
     {
	  test_mark[2][0]=1.5;
	  test_mark[2][1]=0;
	  test_mark[2][2]=0;
   }
  else
     {
	  test_mark[2][0]=0;
	  test_mark[2][1]=0;
	  test_mark[2][2]=1.5;
     }
 }
 int x=test_mark[0][0]+test_mark[1][0]+test_mark[2][0];
  int y=test_mark[0][1]+test_mark[1][1]+test_mark[2][1];
 int z=test_mark[0][2]+test_mark[1][2]+test_mark[2][2];
 if(x>y&&x>z)
  {
   strcpy(best_stream,"Science");
   additional(d);
  }
 else if(y>z)
 {
  strcpy(best_stream,"Commerce");
  strcpy(extra," ");
 }
 else
 {
  strcpy(best_stream,"Humanities");
  strcpy(extra," ");
 }
}
 void get_interest(char a[])
 {
  if(strcmp(a,"science")==0)
  {
   test_mark[0][0]=1;
   test_mark[0][1]=0;
   test_mark[0][2]=0;
  }
  else if(strcmp(a,"commerce")==0)
  {
   test_mark[0][0]=0;
   test_mark[0][1]=1;
   test_mark[0][2]=0;
  }
  else if(strcmp(a,"humanities")==0)
  {
   test_mark[0][0]=0;
   test_mark[0][1]=0;
   test_mark[0][2]=1;
  }
}
 void get_marks()
 {
  cout<<"\n\n\t\t\tMarks in Subjects(Out of 100)...";
  cout<<"\n\n\t\t\t->English :";
  cin>>marks[0];
  cout<<"\t\t\t->Hindi   :";
  cin>>marks[1];
  cout<<"\t\t\t->Maths   :";
  cin>>marks[2];
  cout<<"\t\t\t->Science :";
  cin>>marks[3];
  cout<<"\t\t\t->SSt     :";
  cin>>marks[4];
  cout<<"\n\t\t************************************************";
  float avg=(marks[0]+marks[1]+marks[2]+marks[3]+marks[4])/5;
  cout<<"\n\n\t\t\tYour Percentage\t:"<<setprecision(4)<<avg<<" %";
  cout<<"\n\n\t\t************************************************";
  if(avg>85)
  {
   test_mark[1][0]=2;
   test_mark[1][1]=0;
   test_mark[1][2]=0;
  }
  else if(avg>75)
  {
   test_mark[1][0]=0;
   test_mark[1][1]=2;
   test_mark[1][2]=0;
  }
  else
  {
   test_mark[1][0]=0;
   test_mark[1][1]=0;
   test_mark[1][2]=2;
  }
  delay(1500);
}
  void get()
  {
   cout<<"\n\n\t\t\t\tCOUNSELLOR DETAILS \n";
   cout<<"\t\t****************************************************";
   cout<<"\n\n\t\t  Counsellor's Name         :";
   gets(cname);
   cout<<"\n\t\t  Counsellor's ID(3 Digits) :";
   cin>>cid;
   cout<<"\n\t\t  Fees (Paid by user)       :";
   cin>>salary;
  }
   void c_display()
    {
      cout<<cname<<"\t\t"<<salary;
    }
    void show()
   {
    cout<<"\t\t\t"<<cname<<"\t\t"<<cid<<"\t\t"<<salary<<"\n";
   }
   void booking_details()
  {
  display();
  cout<<"\n\t\t\tSelect a Counseller's ID :";
  cin>>book_id;
  clrscr();
  cout<<"\n\n\t\t****************************************************";
  cout<<"\n\t\t\t\tCOUNSELLOR BOOKING";
  cout<<"\n\t\t****************************************************";
  cout<<"\n\n\t\t\tYour Name for Booking     :";
  gets(book_name);
      cout<<"\t\t\tYour Bank's Name          :";
  gets(bname);
      cout<<"\t\t\tYour Bank ID (4 Digit)    :";
  cin>>bid;
      cout<<"\t\t\tBank Account Password     :";
  gets(b_pass);
}
void b_show()
{
  cout<<"  "<<book_name<<"\t"<<bname<<"\t\t"<<bid<<"\t";
  c_show(book_id);
  cout<<"\n";
}
void test_show()
{
  cout<<best_stream<<extra;
 }
};
counselling c;

void c_show(int id)
{
 counselling check;
 ifstream f("council.dat",ios::in|ios::binary);
 while(!f.eof())
 {
  f.read((char*)&check,sizeof(check));

  if(check.rid()==id)
  {
   check.c_display();
   break;
  }
 }
 f.close();
}

void book_details()
{
 int temp=0;
 clrscr();
  cout<<"\n\n*****************************************************************************";
  cout<<"\n\t\t\t\tCOUNSELLOR BOOKING";
  cout<<"\n*****************************************************************************";
  cout<<"\n  NAME\t\tBANK NAME\t\tBANK ID\tCOUNSELLOR\tFEES";
  cout<<"\n*****************************************************************************";
  cout<<"\n";
 ifstream i("booking.dat",ios::in|ios::binary);
   while(!i.eof())
   {
    i.read((char*)&c,sizeof(c));
    if(i.eof())
     break;
     if(strcmpi(name,c.get_name())==0&&
	strcmp(password,c.get_pass())==0)
     {
      c.b_show();
      temp=1;
     }
   }
   i.close();
 if(temp==0)
 {
   clrscr();
  cout<<"\n\n*****************************************************************************";
  cout<<"\n\t\t\t\tCOUNSELLOR BOOKING";
  cout<<"\n*****************************************************************************";
  cout<<"\n\n\t\t\t  No Previous Booking Present !!!";
  cout<<"\n";
 }
 else
 {
  cout<<"*****************************************************************************";
  cout<<"\n\t\t    For Any Further Details Related to Timings.";
  cout<<"\n\t\t\t        Contact No. :9810098100";
  cout<<"\n\t\t\t                     9355555501";
 }
  cout<<"\n*****************************************************************************";
  cout<<"\n\n\t\t\t";
  system("pause");
}
void booking()
{
 char ch;
 clrscr();
  cout<<"\n\n\t\t****************************************************";
  cout<<"\n\t\t\t\tCOUNSELLOR BOOKING";
  cout<<"\n\t\t****************************************************";
  c.booking_details();
  cout<<"\n\t\t\tConfirm Booking (y/n) :";
  cin>>ch;
  if(ch=='y'||ch=='Y')
  {
   cout<<"\n\t\t\t\t BOOKING DONE !!!";
   cout<<"\n\n\t\t****************************************************";
   cout<<"\n\t\t    For Any Further Details Related to Timings.";
   cout<<"\n\t\t\t        Contact No. :9810098100";
   cout<<"\n\t\t\t                     9355555501";
   cout<<"\n\t\t****************************************************";
   c.assign_detail(name,password);
   ofstream o("booking.dat",ios::app|ios::binary);
   o.write((char*)&c,sizeof(c));
   o.close();
 }
  else
  {
   cout<<"\n\t\t\t    BOOKING CANCELLED !!!";
   cout<<"\n";
  }
  delay(1200);
}
void display()
{
  clrscr();
  cout<<"\n\n\t\t****************************************************";
  cout<<"\n\t\t\t\tCOUNSELLORS DETAILS";
  cout<<"\n\t\t****************************************************";
  cout<<"\n\t\t\tName\t\tID\t\tFees";
  cout<<"\n\t\t****************************************************";
  cout<<"\n";
  ifstream i("council.dat",ios::in|ios::binary);
  i.seekg(0);
   while(!i.eof())
   {
    i.read((char*)&c,sizeof(c));
    if(i.eof())
      break;
    c.show();
   }
   i.close();
  cout<<"\t\t****************************************************";
  cout<<"\n";
}

void modify()
{
 int p,flag=0,pos=0;
 char ch1;
 cout<<"\n\n\t\t        CAREER COUNSELLING ";
 cout<<"\n\t\t****************************************************";
 cout<<"\n\n\t\t  Counsellor's ID to be Modified : ";
 cin>>p;
 fstream f("council.dat",ios::binary|ios::in|ios::out);
  f.seekg(0);
  while(!f.eof())
   {
    pos=f.tellg();
    f.read((char*)&c,sizeof(c));
    if(f.eof())
     {
      break;
     }
    else if(p==c.rid())
    {
     cout<<"\n\t\t\tName\t\tID\t\tFees";
     cout<<"\n\t\t****************************************************";
     cout<<"\n";
     c.show();
     cout<<"\t\t****************************************************";
     flag=1;
     c.get();
     f.seekp(pos);
     f.write((char*)&c,sizeof(c));
     }
   }
 f.close();
 if(flag==1)
 {
  cout<<"\n\t\t\t  Record Modified !!! ";
 }
 if(flag==0)
 {
  cout<<"\n\t\t\t No Record Present !!!";
 }
}
void del_coun()
{
 int t,flag=0;
 cout<<"\n\n\t\t        CAREER COUNSELLING ";
 cout<<"\n\t\t****************************************************";
 cout<<"\n\n\t\t   Counsellor's ID to be deleted :";
 cin>>t;
 ifstream i("council.DAT",ios::binary|ios::in);
 i.seekg(0);
 ofstream o("ABC.dat",ios::app|ios::binary);
  while(!i.eof())
   {
    i.read((char*)&c,sizeof(c));
    if(i.eof())
     {
      break;
     }
    if(t==c.rid())
    {
     char ch1;
      cout<<"\n\t\t\tName\t\tID\t\tFees";
     cout<<"\n\t\t****************************************************";
     cout<<"\n";
     c.show();
     cout<<"\n\t\t****************************************************";
     cout<<"\n\t\t\tAre you sure (y/n) :";
     cin>>ch1;
     if(ch1=='y'||ch1=='Y')
     {
      cout<<"\n\t\t\tRecord Deleted!!!";
      flag=1;
     }
     else
	o.write((char*)&c,sizeof(c));
    }
    else
	o.write((char*)&c,sizeof(c));
  }
 if(flag==0)
 {
  cout<<"\n\t\t\tNo ID Present!!!";
 }
 delay(1500);
i.close();
o.close();
remove("council.dat");
rename("ABC.dat","council.dat");
}
void insert()
{
 ofstream o("council.dat",ios::binary|ios::app);
 c.get();
 o.write((char*)&c,sizeof(c));
 o.close();
}
void test()
{
 char a;
 int m1=0,m2=0,m3=0,m4=0;
 clrscr();
 cout<<"\n\t\t                  TEST YOUR KNOWLWDGE";
 cout<<"\n        ******************************************************************";
 cout<<"\n\n\t\t 1. If you increased the radius 5 times and decreased";
 cout<<"\n\t\t      the height 5 times,What is the change in Volume";
 cout<<"\n\t\t       of cylinder ?";
 cout<<"\n\n\t\t   a) Decreased 2 times";
 cout<<"\n\t\t   b) Increased 5 times";
 cout<<"\n\t\t   c) No change";
 cout<<"\n\n\t\t  Your choice (a-c):";
 cin>>a;
 if(a=='b'||a=='B')
 ++m2;
 clrscr();
  cout<<"\n\t\t                  TEST YOUR KNOWLWDGE";
 cout<<"\n        ******************************************************************";
 cout<<"\n\n\t\t 2. Who is the composer 'Vande Mataram'? ";
 cout<<"\n\n\t\t   a) Rabindranath tagore";
 cout<<"\n\t\t   b) Bankim Chandra Chatterjee";
 cout<<"\n\t\t   c) Ravi Shankar";
 cout<<"\n\n\t\t  Your choice (a-c):";
 cin>>a;
 if(a=='b'||a=='B')
 ++m3;
 clrscr();
  cout<<"\n\t\t                  TEST YOUR KNOWLWDGE";
 cout<<"\n        ******************************************************************";
 cout<<"\n\n\t\t 3. Who discovered neutron ? ";
 cout<<"\n\n\t\t   a) J.J Thomson";
 cout<<"\n\t\t   b) Charles Darwin";
 cout<<"\n\t\t   c) James Chadwick";
 cout<<"\n\n\t\t  Your choice (a-c):";
 cin>>a;
 if(a=='c'||a=='C')
 ++m1;
 clrscr();
  cout<<"\n\t\t                  TEST YOUR KNOWLWDGE";
 cout<<"\n        ******************************************************************";
 cout<<"\n\n\t\t4. What is the power house of a cell ?";
 cout<<"\n\n\t\t  a) Neucleolus";
 cout<<"\n\t\t  b) Golgi Apparatus";
 cout<<"\n\t\t  c) Mitochondria";
 cout<<"\n\n\t\t  Your choice (a-c):";
 cin>>a;
 if(a=='c'||a=='C')
  ++m4;
 clrscr();
  cout<<"\n\t\t                  TEST YOUR KNOWLWDGE";
 cout<<"\n        ******************************************************************";
 cout<<"\n\n\t\t 5. What is Neuton's second law of Motion ?";
 cout<<"\n\n\t\t  a) Every action has an equal and opposite";
 cout<<"\n\t\t     Reaction.";
 cout<<"\n\t\t  b) Object remains at rest unless acted";
 cout<<"\n\t\t     upon by an external force. ";
 cout<<"\n\t\t  c) Acceleration of any body dependent on";
 cout<<"\n\t\t     mass of body and force acting on it.";
 cout<<"\n\n\t\t  Your choice (a-c):";
 cin>>a;
 if(a=='c'||a=='C')
 ++m1;
 clrscr();
  cout<<"\n\t\t                  TEST YOUR KNOWLWDGE";
 cout<<"\n        ******************************************************************";
 cout<<"\n\n\t\t 6. Solve the expression (x^2-8x+14)=(-2x+5) ?";
 cout<<"\n\n\t\t  a) x=3";
 cout<<"\n\t\t  b) x=1,5";
 cout<<"\n\t\t  c) x=3,-3";
 cout<<"\n\n\t\t  Your choice (a-c):";
 cin>>a;
 if(a=='a'||a=='A')
 ++m2;
 clrscr();
  cout<<"\n\t\t                  TEST YOUR KNOWLWDGE";
 cout<<"\n        ******************************************************************";
 cout<<"\n\n\t\t 7. When did Jallianwalla incident takes place ?";
 cout<<"\n\n\t\t  a) On 15 August 1919";
 cout<<"\n\t\t  b) On 13 April 1919";
 cout<<"\n\t\t  c) On 27 October 1920";
 cout<<"\n\n\t\t  Your choice (a-c):";
 cin>>a;
 if(a=='b'||a=='B')
 ++m3;
 cout<<"\n\t\t\t     TEST COMPLETED !!!";
 cout<<"\n\n\t\t\t";
 system("pause");
 c.calc(m1,m2,m3,m4);
}

// analysis() calculates the best stream for the User.

void analysis()
{
 int ch;
 clrscr();
 cout<<"\n\n\t\t************************************************";
 cout<<"\n\t\t\t  KNOW YOUR BEST STREAM";
 cout<<"\n\t\t************************************************";
 cout<<"\n\n\t\t\tWhat's your Interest...";
 cout<<"\n\n\t\t\t1. Science";
 cout<<"\n\t\t\t2. Commerce";
 cout<<"\n\t\t\t3. Humanities";
 cout<<"\n\n\t\t************************************************";
 cout<<"\n\n\t\t\tYour Choice(1-3)\t:";
 cin>>ch;
 cout<<"\n\t\t************************************************";
 delay(1000);
 switch(ch)
 {
  case 1 :c.get_interest("science");
	  break;
  case 2 :c.get_interest("commerce");
	  break;
  case 3 :c.get_interest("humanities");
 }
 delay(1500);
 clrscr();
 cout<<"\n\n\t\t************************************************";
 cout<<"\n\t\t\t  KNOW YOUR BEST STREAM";
 cout<<"\n\t\t************************************************";
 c.get_marks();
 delay(1500);
 test();
 clrscr();
 cout<<"\n\n\t\t********************************************************";
 cout<<"\n\t\t\t\tTEST DETAILS";
 cout<<"\n\t\t********************************************************";
 cout<<"\n\n\t\t   The Best Stream For You Would be ";
 c.test_show();
 cout<<"\n\n\t\t********************************************************";
 cout<<"\n\n\t\t\t";
 system("pause");
 c.assign_detail(name,password);
 ofstream f("result.dat",ios::app|ios::binary);
 f.seekp(0);
 f.write((char*)&c,sizeof(c));
 f.close();
}
void test_details()
{
 counselling check;
 int temp=0,count=0;
 ifstream i("result.dat",ios::in|ios::binary);
  clrscr();
  cout<<"\n\n\t\t****************************************************";
 cout<<"\n\t\t\t\tTEST DETAILS";
 cout<<"\n\t\t****************************************************";
 cout<<"\n";
 i.seekg(0);
 while(!i.eof())
 {
  i.read((char*)&c,sizeof(c));
  if(i.eof())
    break;
  if(strcmpi(name,c.get_name())==0&&
     strcmp(password,c.get_pass())==0)
  {
   cout<<"\t\t  Test No. "<<++count<<" Result : ";
   c.test_show();
   cout<<"\n";
   temp=1;
  }
 }
 i.close();
 if(temp==0)
 {
  cout<<"\n\t\t\tNo Test Given Yet...";
  cout<<"\n\n";
  delay(1300);
 }
 cout<<"\t\t****************************************************";
}

// us_menu() displays the user menu for Stream selection test
// 		and Counsellor Booking.

void us_menu()
{
 int tell;
 char ch;
 do
 {
 clrscr();
 cout<<"\n\n\t\t************************************************";
 cout<<"\n\t\t\t\tUSER MENU";
 cout<<"\n\t\t************************************************";
 cout<<"\n\n\t\t\t1. Know Your Perfect Stream";
 cout<<"\n\t\t\t2. Book a Counsellor";
 cout<<"\n\t\t\t3. View Previous Test Details";
 cout<<"\n\t\t\t4. View Previous Booking Details";
 cout<<"\n\t\t\t5. Exit";
 cout<<"\n\n\t\t************************************************";
 cout<<"\n\n\t\t\tYour Choice (1-5) :";
 cin>>tell;
 cout<<"\n\t\t************************************************";
 delay(500);
 delay(1000);
 switch(tell)
 {
  case 1 :analysis();
	  break;
  case 2 :booking();
	  break;
  case 3 :test_details();
	  break;
  case 4 :book_details();
	  break;
  case 5 :clrscr();
	  cout<<"\n\n\t\t************************************************";
	  cout<<"\n\t\t\t\tCAREER COUNSELLING";
	  cout<<"\n\t\t************************************************";
	  cout<<"\n\n\t\t\t     Thanks For Using!!!";
	  cout<<"\n\n\t\t************************************************";
	  delay(3000);
	  exit(0);
  default:cout<<"\n\n\t\t\tWrong Choice!!!";
	  cout<<"\n";
 }
 cout<<"\n\t\t\tGo to User Menu(y/n) :";
 cin>>ch;

 }while(ch=='y'||ch=='Y');
}

// ad_log() displays an Admin menu for any alteration in Counsellor's Records.

void ad_log()
{
  char ch='y',name[100],password[40];
  int choice1;
  clrscr();
  cout<<"\n\n\t\t************************************************";
  cout<<"\n\t\t\t\tADMIN LOGIN";
  cout<<"\n\t\t************************************************";
  cout<<"\n\n\t\t\tEnter Username :";
  gets(name);
  cout<<"\n\t\t\tEnter Password :";
  gets(password);
  if(strcmpi(name,"khushal")==0&&strcmp(password,"myproject")==0)
 {
 cout<<"\n\t\t************************************************";
 cout<<"\n\t\t\t Successfully Signed in !!!";
 cout<<"\n\n\t\t\t";
 system("pause");
 do
 {
  clrscr();
  cout<<"\n\n\t\t************************************************";
  cout<<"\n\t\t\t\tADMIN LOGIN";
  cout<<"\n\t\t************************************************";
  cout<<"\n\n\t\t\t1. Add a Counsellor";
  cout<<"\n\t\t\t2. Delete a Counsellor";
  cout<<"\n\t\t\t3. Modify a Counsellor";
  cout<<"\n\t\t\t4. Display Counsellors";
  cout<<"\n\t\t\t5. Exit";
  cout<<"\n\n\t\t************************************************";
  cout<<"\n\n\t\t\tYour choice (1-5) :";
  cin>>choice1;
  cout<<"\n\t\t************************************************";
  delay(1000);
  switch(choice1)
  {
   case 1 :clrscr();
	   insert();
	   break;
   case 2 :clrscr();
	   del_coun();
	   break;
   case 3 :clrscr();
	   modify();
	   break;
   case 4 :clrscr();
	   display();
	   break;
   case 5 :clrscr();
	   cout<<"\n\n\t\t************************************************";
	   cout<<"\n\t\t\t\tCAREER COUNSELLING";
	   cout<<"\n\t\t************************************************";
	   cout<<"\n\n\t\t\t     Thanks For Using!!!";
	   cout<<"\n\n\t\t************************************************";
	   delay(4000);
	   exit(0);
   default :cout<<"\n\n\t\t\tWrong Choice!!!";
	   cout<<"\n";
  }
  cout<<"\n\t\t\tGo to Admin Menu (y/n) :";
  cin>>ch;
  }while(ch=='y'||ch=='Y');
 }
 else
 {
  cout<<"\n\t\t************************************************";
  cout<<"\n\t\t\t     Wrong Details!!!";
  cout<<"\n";
  delay(1200);
 }
}

// us_sign() helps in User sign up.

void us_sign()
{
  cout<<"\n\n\t\t************************************************";
  cout<<"\n\t\t\t\tUSER SIGN UP";
  cout<<"\n\t\t************************************************";
  cout<<"\n\n\t\t\tEnter your Username :";
  gets(name);
  cout<<"\n\t\t\tEnter your Password :";
  gets(password);
  cout<<"\n\t\t************************************************";
  int found=0;
  ifstream  ii("details.dat",ios::in|ios::binary);
  while(!ii.eof())
  {
   ii.read((char*)&c,sizeof(c));
   if(strcmpi(name,c.get_name())==0)
   {
    found=1;
    cout<<"\n\t\t\tSame Username Already exists !!!";
    cout<<"\n\t\t\tPlease Try Another Username !!!";
    cout<<"\n\t\t************************************************";
    break;
   }
  }
  ii.close();
  if(found==0)
  {
   c.assign_detail(name,password);
   ofstream  of("details.dat",ios::app|ios::binary);
   of.write((char*)&c,sizeof(c));
   cout<<"\n\n\t\t\t    ID Successflly Created!!";
   cout<<"\n\t\t\tRemember Your Username & Password!";
   cout<<"\n\n\t\t************************************************";
   of.close();
  }
  delay(1000);
}

// us_log() helps in User Log in.

void us_log()
{
  int temp=0;
  ifstream f("details.dat",ios::in|ios::binary);
  cout<<"\n\n\t\t************************************************";
  cout<<"\n\t\t\t\tUSER LOG IN";
  cout<<"\n\t\t************************************************";
  cout<<"\n\n\t\t\t     Username  :";
  gets(name);
  cout<<"\n\t\t\t     Password  :";
  gets(password);
  cout<<"\n\t\t************************************************";
  f.seekg(0);
  while(!f.eof())
  {
   f.read((char*)&c,sizeof(c));
   if(f.eof())
    break;
   if(strcmpi(name,c.get_name())==0&&
       strcmp(password,c.get_pass())==0)
    {
     cout<<"\n\n\t\t\tSuccessfully Signed in !!";
     delay(1000);
     cout<<"\n\n\t\t\t";
     system("pause");
     us_menu();
     temp=1;
     break;
    }
  }
  f.close();
  if(temp==0)
   {
    cout<<"\n\t\t\t   No Such User Exists !!";
    cout<<"\n\t\t\tYour Details May be incorrect!!";
    cout<<"\n";
    delay(1500);
   }
}

// main_window() displays the Main menu.

void main_window()
{
 int choice; char cont;
 system("cls");
 textcolor(RED);
  cout<<"\n\n\n\t";
  cputs("        ****   ***   ****   ****  ****  ****   ");cout<<"\n\t";
  delay(300);
  cputs("       *      *   *  *  *   *     *     *  *   ");cout<<"\n\t";
  delay(300);
  cputs("       *      *****  ***    ****  ****  ***    ");cout<<"\n\t";
  delay(300);
  cputs("       *      *   *  *  *   *     *     *  *    ");cout<<"\n\t";
  delay(300);
  cputs("        ****  *   *  *   *  ****  ****  *   *  ");cout<<"\n\n";
  delay(700);
  cputs("      ****  ***  *   *  *   *  *****  ****  *   *    *  *   *   **** ");
  cout<<"\n";delay(300);
  cputs("     *     *   * *   *  **  *  *      *     *   *    *  **  *  *     ");
  cout<<"\n";delay(300);
  cputs("     *     *   * *   *  * * *  *****  ****  *   *    *  * * *  *  ** ");
  cout<<"\n";delay(300);
  cputs("     *     *   * *   *  *  **      *  *     *   *    *  *  **  *   * ");
  cout<<"\n";delay(300);
  cputs("      ****  ***  *****  *   *  *****  ****  *** ***  *  *   *   ***  ");
  delay(1000);
  cout<<"\n\n\t\t\t\t";
  textcolor(BLUE);
  cputs("MADE BY :-");
  delay(600);
  textcolor(CYAN);
  cputs(" Khushal Rastogi");
 delay(2500);

 do
 {
 system("cls");
 textcolor(WHITE);
 cout<<"\n\n\t\t************************************************";
 cout<<"\n\t\t\t\tCAREER COUNSELLING";
 cout<<"\n\t\t************************************************";
 cout<<"\n\n\t\t\t1. Admin Login";
 cout<<"\n\t\t\t2. User Sign up";
 cout<<"\n\t\t\t3. User Login";
 cout<<"\n\t\t\t4. Exit";
 cout<<"\n\n\t\t************************************************";
 cout<<"\n\n\t\t\tYour Choice (1-4) :";
 cin>>choice;
 cout<<"\n\t\t************************************************";
 delay(1500);
   switch(choice)
 {
  case 1 :clrscr();
	  ad_log();
	  break;
  case 2 :clrscr();
	  us_sign();
	  break;
  case 3 :clrscr();
	  us_log();
	  break;
  case 4 :clrscr();
	  cout<<"\n\n\t\t************************************************";
	  cout<<"\n\t\t\t\tCAREER COUNSELLING";
	  cout<<"\n\t\t************************************************";
	  cout<<"\n\n\t\t\t     Thanks For Using!!!";
	  cout<<"\n\n\t\t************************************************";
	  delay(2500);
	  exit(0);
  default :cout<<"\n\n\t\t\tWrong Choice!!!";
	   cout<<"\n";
  }
  cout<<"\n\t\t\tGo to Main Menu (y/n)  :";
  cin>>cont;
  }while(cont=='y'||cont=='Y');
  clrscr();
  cout<<"\n\n\t\t************************************************";
  cout<<"\n\t\t\t\tCAREER COUNSELLING";
  cout<<"\n\t\t************************************************";
  cout<<"\n\n\t\t\t     Thanks For Using!!!";
  cout<<"\n\n\t\t************************************************";
  delay(2500);
}
void main()
{
 main_window();
}
