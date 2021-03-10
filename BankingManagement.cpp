#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
using namespace std;
class Bank
{
public:
    int balance,acc_num,d1,m1,y1,d2,m2,y2,d,y,m;
    char fname[10],lname[10],type[3],phone[13];

    Bank()
        {
            balance=0;
            acc_num=0;
        }
    void get_data();
    void store();
    void sho_store(int);
    void sty();
    void sho_all_store();
    void Acc_Num(int);
    void AddDip(int);
    void WidthDiP(int);
    int ReferDip(int);
    int AcceptDip(int,int);
    void Nothing(int,int);
    void Update(int,int,int);
};

void Bank::Update(int a,int b,int c)
{
    d2=a;
    m2=b;
    y2=c;
    int i,j,z;
    ofstream writeM("New.txt",ios::out);
    ifstream readM("bank.txt",ios::in);
    while(!readM.eof())
    {

            readM>>fname>>lname>>d1>>m1>>y1>>type>>phone>>acc_num>>balance;
            d=d2-d1;
            m=m2-m1;
            y=y2-y1;
            if(d!=0&&m!=0)
            {
               writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<acc_num<<" "<<balance;
            }
        else if(d==0&&m==0&&y>1)
           {
               if(strcmp(type,"S")==0)
               {
                 balance=balance+500;
                 writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<acc_num<<" "<<balance;
                 i=0;
               }
              else
               {
                  writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<acc_num<<" "<<balance;
                  j=1;
               }
           }
           else
           {
             writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<acc_num<<" "<<balance;
             z=2;
           }
    }
     if(i==0)
     {
       cout<<"ALL ACCOUNT UPDATE SUCCESSFULLY!!!";
     }
     else if(j==1)
     {
       cout<<"ERROR UPDATE NOT COMPELETE!!!";
     }
     else if(j==2)
     {
       cout<<"ERROR UPDATE NOT COMPELETE!!!";
     }
     writeM.close();
     readM.close();
     remove("bank.txt");
     rename("New.txt","bank.txt");
}

void Bank::Acc_Num(int a)
{
    acc_num=a;
}

void Bank::get_data()
{

        cout<<"\n\n\n\t\t\t\t\t\t****CREAT NEW ACCOUNT*****";
        cout<<"\n\n\t\t\t\t\t\tFIRST NAME        :";
        cin.get(fname,10);
        cin.ignore();
        cout<<"\t\t\t\t\t\tLAST NAME         :";
        cin.get(lname,10);
        cin.ignore();
        cout<<"\t\t\t\t\t\tCREATION DATE     :";
        cin>>d1;
        cin.ignore();
        cin>>m1;
        cin.ignore();
        cin>>y1;
        cin.ignore();
        cout<<"\t\t\t\t\t\tENTER TYPE        :";
        cin.get(type,3);
        cin.ignore();
        cout<<"\t\t\t\t\t\tPHONE NUMBER      :";
        cin.get(phone,13);
        cin.ignore();
        cout<<"\t\t\t\t\t\tACCOUNT NUMBER    :"<<acc_num;
        cout<<"\n\t\t\t\t\t\tINITIAL BALANCE   :";
        cin>>balance;
}

void Bank::store()
{
        ofstream write;
        write.open("bank.txt",ios::app|ios::out);
        write<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<acc_num<<" "<<balance;
        write.close();

}

void Bank::sho_store(int a)
{

        ifstream read;
        read.open("bank.txt",ios::in|ios::app);
        if(!read)
        {
            cout<<"FILE NOT FOUND";
        }
    else
        while(!read.eof())
        {
            read>>fname>>lname>>d1>>m1>>y1>>type>>phone>>acc_num>>balance;
            if(a==acc_num)
            {
            cout<<"\n\n\t\t\t\t\t\tHOLDER NAME    :  "<<fname<<" "<<lname<<" ";
            cout<<"\n\t\t\t\t\t\tCREATION DATE  :  "<<d1<<"/"<<m1<<"/"<<y1;
            cout<<"\n\t\t\t\t\t\tACCOUNT TYPE   :  "<<type;
            cout<<"\n\t\t\t\t\t\tPHONE NUMBER   :  "<<phone;
            cout<<"\n\t\t\t\t\t\tACCOUNT NUM    :  "<<acc_num;
            cout<<"\n\t\t\t\t\t\tBALANCE        :  "<<balance;
            cout<<endl;
            }

      }
      read.close();
}

void Bank::sty()
{
  char a=175;
  cout<<"\n\n\t\t\t  ****ALL ACCOUNT INFORMATION****";
  cout<<"\n\n\tACCOUNT NUMBER"<<"\t"<<"HOLDER NAME"<<"\t"<<"CREATION DATE"<<"\t"<<"ACCOUNT TYPE"<<"\t"<<"BALANCE\n";
  for(int x=0;x<80;x++)
  {
      cout<<a;
  }
  cout<<endl;
}

void Bank::sho_all_store()
{
    ifstream read;
        read.open("bank.txt",ios::in|ios::app);
        if(!read)
        {
            cout<<"FILE NOT FOUND";
        }
    else
        while(!read.eof())
        {
            read>>fname>>lname>>d1>>m1>>y1>>type>>phone>>acc_num;
            read>>balance;
            cout<<"\t     "<<acc_num<<"\t\t"<<fname<<" "<<lname<<"\t   "<<d1<<"/"<<m1<<"/"<<y1<<"\t    "<<type<<"\t\t"<<balance;
            cout<<endl;
        }
        read.close();
}

void Bank::AddDip(int a)
{
    int x=0;
    ofstream writeM("New.txt",ios::out);
    ifstream readM("bank.txt",ios::in);
    while(!readM.eof())
    {
            readM>>fname>>lname>>d1>>m1>>y1>>type>>phone>>acc_num>>balance;
            if(a!=acc_num)
            {
               writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<acc_num<<" "<<balance;
            }
        else if(a==acc_num)
           {
               if(strcmp(type,"C")==0)
               {
        cout<<"\n\n\n\t\t\t\t\t\t****ADD DEPOSIT****";
        cout<<"\n\t\t\t\t\t\tYOUR BALANCE:"<<balance;
        cout<<"\n\t\t\t\t\t\tADD BALANCE:";
        cin>>x;
        balance=balance+x;
        cout<<"\n\t\t\t\t\t\tNOW BALANCE:"<<balance;
        writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<a<<" "<<balance;
           }
           else
           {
              cout<<"SORRY YOU ARE NOT ALLOW TO ADD DEPOSIT FROM SAVING ACCOUNT";
              writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<a<<" "<<balance;
           }
           }
    }
     writeM.close();
     readM.close();
     remove("bank.txt");
     rename("New.txt","bank.txt");
}

void Bank::WidthDiP(int a)
{
  int x=0;
    ofstream writeM("New.txt",ios::out);
    ifstream readM("bank.txt",ios::in);
    while(!readM.eof())
    {
            readM>>fname>>lname>>d1>>m1>>y1>>type>>phone>>acc_num>>balance;
            if(a!=acc_num)
            {
               writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<acc_num<<" "<<balance;
            }
        else if(a==acc_num)
           {
            if(strcmp(type,"C")==0)
            {
        cout<<"\n\n\n\t\t\t\t\t\t****WIDTHDRAW DEPOSIT****";
        cout<<"\n\t\t\t\t\t\tYOUR BALANCE:"<<balance;
        cout<<"\n\t\t\t\t\t\tWIDTHDROW BALANCE:";
        cin>>x;
        balance=balance-x;
        if(balance>=500)
        {
        cout<<"\n\t\t\t\t\t\tNOW BALANCE:"<<balance;
        writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<a<<" "<<balance;
        }

        else
        {
         balance=balance+x;
         cout<<"SORRY YOU DON'T HAVE ENOUGH MONEY YOU CAN WIDTHDROW <="<<balance-500<<"-TK";
         writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<a<<" "<<balance;

        }
            }
            else
           {
              cout<<"SORRY YOU ARE NOT ALLOW TO WIDTHDROW DEPOSIT FROM SAVING ACCOUNT";
              writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<a<<" "<<balance;
           }
           }
    }
     writeM.close();
     readM.close();
     remove("bank.txt");
     rename("New.txt","bank.txt");
}

int Bank::ReferDip(int a)
{
  int x=0,z=0;
    ofstream writeM("New.txt",ios::out);
    ifstream readM("bank.txt",ios::in);
    while(!readM.eof())
    {
            readM>>fname>>lname>>d1>>m1>>y1>>type>>phone>>acc_num>>balance;
            if(a!=acc_num)
            {
               writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<acc_num<<" "<<balance;
            }
        else if(a==acc_num)
           {
               if(strcmp(type,"C")==0)
               {
        cout<<"\n\n\n\t\t\t\t\t\t****WIDTHDRAW DEPOSIT****";
        cout<<"\n\t\t\t\t\t\tYOUR BALANCE:"<<balance;
        cout<<"\n\t\t\t\t\t\tWIDTHDROW BALANCE:";
        cin>>x;
        balance=balance-x;
        cout<<"\n\t\t\t\t\t\tNOW BALANCE:"<<balance;
        writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<a<<" "<<balance;
               }
               else
               {
                   cout<<"SAVING ACCOUNT DOES NOT ALLOW TO REFER DEPOSIT";
                   writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<a<<" "<<balance;
                   x=0;
               }
           }
    }
     writeM.close();
     readM.close();
     remove("bank.txt");
     rename("New.txt","bank.txt");
     return x;

}
int Bank::AcceptDip(int a,int b)
{
    int x=b,z=0;
    ofstream writeM("New.txt",ios::out);
    ifstream readM("bank.txt",ios::in);
    while(!readM.eof())
    {
            readM>>fname>>lname>>d1>>m1>>y1>>type>>phone>>acc_num>>balance;
            if(a!=acc_num)
            {
               writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<acc_num<<" "<<balance;
            }
        else if(a==acc_num)
           {
               if(strcmp(type,"C")==0)
               {
        cout<<"\n\n\n\t\t\t\t\t\t****ADD DEPOSIT****";
        cout<<"\n\t\t\t\t\t\tYOUR BALANCE:"<<balance;
        balance=balance+x-10;
        cout<<"\n\t\t\t\t\t\tNOW BALANCE:"<<balance;
        writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<a<<" "<<balance;
        z=0;

              }
              else
              {
                  cout<<"TRSNSICTION NOT COMPELET";
                   writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<acc_num<<" "<<balance;
                  z=1;
              }
           }
    }
     writeM.close();
     readM.close();
     remove("bank.txt");
     rename("New.txt","bank.txt");
     return z;

}
void Bank::Nothing(int a,int b)
{
  int x=b;
    ofstream writeM("New.txt",ios::out);
    ifstream readM("bank.txt",ios::in);
    while(!readM.eof())
    {
            readM>>fname>>lname>>d1>>m1>>y1>>type>>phone>>acc_num>>balance;
            if(a!=acc_num)
            {
               writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<acc_num<<" "<<balance;
            }
        else if(a==acc_num)
           {
        balance=balance+x;
        writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<a<<" "<<balance;
           }
    }
     writeM.close();
     readM.close();
     remove("bank.txt");
     rename("New.txt","bank.txt");
}
class AccNum:public Bank
{
public:
    int acc=0;
    AccNum()
    {
    ifstream in("accnum.txt");
    in>>acc;
    }

    ~AccNum()
    {
    ofstream out("accnum.txt");
    out<<acc;
    }
    void operator ++()
    {
        acc++;
    }
    int ret()
    {
        return acc;
    }
};

class Update:public Bank
{
public:
    void delete_acc(int);
    void Update_acc(int);
    void Modify_acc(int);
};

void Update::delete_acc(int a)
{
    int i;
    ofstream writed("New.txt",ios::out);
    ifstream readd("bank.txt",ios::in);
    while(!readd.eof())
    {
            readd>>fname>>lname>>d1>>m1>>y1>>type>>phone>>acc_num>>balance;
            if(a==acc_num)
            {
            if(a!=acc_num)
            {
               writed<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<acc_num<<" "<<balance;
               cout<<"\n\n\n\t\t\t\t\tACCOUNT NUMBER "<<a<<" IS SUCCESSFULLY DELETED!!!";
               i=0;
            }
            }
            else
            {
                cout<<"\n\n\n\t\t\t\t\tYOU ENTERED WRONG ACCOUNT NUMBER";
                i=1;
                if(i==1)
                {
                    break;
                }
            }
    }
    writed.close();
    readd.close();
    if(i==0)
    {
    remove("bank.txt");
    rename("New.txt","bank.txt");
    }
}

void Update::Modify_acc(int a)
{
    ofstream writeM("New.txt",ios::out);
    ifstream readM("bank.txt",ios::in);
    while(!readM.eof())
    {
            readM>>fname>>lname>>d1>>m1>>y1>>type>>phone>>acc_num>>balance;

            if(a!=acc_num)
            {
               writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<acc_num<<" "<<balance;
            }
        else if(a==acc_num)
        {
        cout<<"\n\n\n\t\t\t\t\t\t****MODIFY ACCOUNT****";
        cout<<"\n\n\t\t\t\t\t\tCURRENT STATUS:";
        sho_store(a);
        cout<<"\n\t\t\t\t\t\tFIRST NAME:";
        cin.get(fname,10);
        cin.ignore();
        cout<<"\n\t\t\t\t\t\tLAST NAME:";
        cin.get(lname,10);
        cin.ignore();
        cout<<"\n\t\t\t\t\t\tCREATION DATE:";
        cin>>d1;
        cin.ignore();
        cin>>m1;
        cin.ignore();
        cin>>y1;
        cin.ignore();
        cout<<"\n\t\t\t\t\t\tENTER TYPE:";
        cin.get(type,3);
        cin.ignore();
        cout<<"\n\t\t\t\t\t\tPHONE NUMBER:";
        cin.get(phone,13);
        cin.ignore();
        cout<<"\n\t\t\t\t\t\tENTER ACCOUNT NUMBER:"<<a;
        cout<<"\n\t\t\t\t\t\tENTER YOUR BALANCE:";
        cin>>balance;
        writeM<<fname<<" "<<lname<<" "<<" "<<d1<<" "<<m1<<" "<<y1<<" "<<type<<" "<<phone<<" "<<a<<" "<<balance;
        }
    }
     writeM.close();
     readM.close();
     remove("bank.txt");
     rename("New.txt","bank.txt");
}

int Menu()
{   int d;
    cout<<"\n\n\n\t\t\t\t\t  //////MAIN MENU/////";
    cout<<"\n\n\n\t\t\t\t\t  1>> CREAT A NEW ACCOUNT";
    cout<<"\n\n\t\t\t\t\t  2>> SEARCH ACCOUNT";
    cout<<"\n\n\t\t\t\t\t  3>> SHOW ALL ACCOUNT";
    cout<<"\n\n\t\t\t\t\t  4>> MODIFY ACCOUNT";
    cout<<"\n\n\t\t\t\t\t  5>> ADD DEPOSIT";
    cout<<"\n\n\t\t\t\t\t  6>> WIDTHDRAW DEPOSIT";
    cout<<"\n\n\t\t\t\t\t  7>> REFERAL DEPOSIT";
    cout<<"\n\n\t\t\t\t\t  8>> DELETE ACCOUNT";
    cout<<"\n\n\t\t\t\t\t  9>> UPDATE ACCOUNT";
    cout<<"\n\n\t\t\t\t\t  10>> EXIT";
    cout<<"\n\n\t\t\t\t\t  >> ENTER YOUR CHOICE";
    cin>>d;
    return d;
}

void Menu_func(int f)
{
    Bank b;
    Update d;
    int x,y,i,j,k,d2,m2,y2;
    system("cls");
    switch(f)
         {
            case 1:
                 {
                 system("cls");
                 cin.ignore();
                 AccNum a;
                 ++a;
                 k=a.ret();
                 b.Acc_Num(k);
                 b.get_data();
                 b.store();
                 break;
                 }
             case 2:
                 {
                 system("cls");
                 cout<<"\n\n\n\n\n\t\t\t\t\tACCOUNT NUMBER:";
                 cin>>x;
                 system("cls");
                 cout<<"\n\n\n\t\t\t\t\t\t****ACCOUNT INFORMATION****";
                 b.sho_store(x);
                 break;
                 }
             case 3:
                 {
                 system("cls");
                 cin.ignore();
                 b.sty();
                 b.sho_all_store();
                 break;
                 }
             case 4:
                 {
                  system("cls");
                  cout<<"\n\n\n\t\t\t\t\tACCOUNT NUMBER:";
                  cin>>x;
                  cin.ignore();
                  system("cls");
                  d.Modify_acc(x);
                  break;
                 }
             case 5:
                 {
                  system("cls");
                  cin.ignore();
                  cout<<"\n\n\n\n\n\t\t\t\t\tACCOUNT NUMBER:";
                  cin>>x;
                  system("cls");
                  b.AddDip(x);
                  break;
                 }
             case 6:
                 {
                  system("cls");
                  cin.ignore();
                  cout<<"\n\n\n\n\n\t\t\t\t\tACCOUNT NUMBER:";
                  cin>>x;
                  system("cls");
                  b.WidthDiP(x);
                  break;
                 }
             case 7:
                 {
                 system("cls");
                 cin.ignore();
                 cout<<"\n\n\t\t\t\t\tACCOUNT NUMBER(REFER):";
                 cin>>x;
                 i=b.ReferDip(x);
                 if(i>0)
                 {
                 cout<<"\n\n\t\t\t\t\tACCOUNT NUMBER(ACCEPT):";
                 cin>>y;
                 j=b.AcceptDip(y,i);
                 if(j==1)
                 {
                  b.Nothing(x,i);
                 }
                 }
                 break;
                 }
             case 8:
                 {
                 system("cls");
                 cin.ignore();
                 cout<<"\n\n\n\t\t\t\t\tACCOUNT NUMBER:";
                 cin>>x;
                 d.delete_acc(x);
                 break;
                 }
            case 9:
                 {
                 system("cls");
                 cin.ignore();
                 cout<<"\n\n\n\t\t\t\t\tTODAY DATE:";
                 cin>>d2;
                 cin.ignore();
                 cin>>m2;
                 cin.ignore();
                 cin>>y2;
                 b.Update(d2,m2,y2);
                 break;
                 }
            case 10:
                 {
                 exit(0);
                 }
             default:
                {
                    system("cls");
                  cout<<"\n\n\n\n\n\t\t\tYOUR ENTERED WORNG KEY PLZ EANTER AGAIN!!!";
                }
         }
}

int main()
{
 int a;
 while(1)
 {
     system("cls");
     a=Menu();
     Menu_func(a);
     getch();
 }
}
