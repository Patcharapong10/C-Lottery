#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<time.h>
using namespace std;
int Menu();
void main2(string &Id,string &pass);
void main3(string &Id,string &pass);
int Read(int &monney);
int Cal(int &monney,int &Pay);
int clabonus(int &Pay,int &Bonus);
int Cal2(int &Pay,int lotterry[],int &monney,int &Bonus,int &random,int &Pay1,string &Id);
int Cal3(int lotterry[],int &random,int &Pay);
void main4(string &Id,string &pass);
int main()
{
	const int i = 1;
	string Data[i][3],Id,Pass;
	const string DataA = "DataA.txt";
	ifstream InFile;
	ofstream OutFile;
	int c;
	do {
		c = Menu();
		if(c == 1){main2(Id,Pass);}
		else if(c == 2){main3(Id,Pass);}
		else {system("cls");cout<<"Please Agian . . ."<<endl;}
	} while(c != 0);
	cout << "Exit program." << endl;
	return(0);
}
int Menu()
{
	string line(28,'=');
	int Choose;
	cout << line << endl;
	cout << "Program Account Lottery Data\n";
	cout << line << endl;
	cout << ":         Main Menu        :\n";
	cout << line << endl;
	cout << ":     0 - Exit             :\n";
	cout << ":     1 - Add-Account      :\n";
	cout << ":     2 - Login-Account    :\n";
	cout << line << endl;
	cout << "Enter choose : ";
	cin >> Choose;
	return(Choose);
}
void main2(string &Id,string &pass)
{
	ofstream Test;
	cout<<  "Enter you Id : ";
	cin>>Id;
	Test.open(Id.c_str(),ios::out|ios::app);
	cout<<  "Enter you Pass: ";
	cin>>pass;
	Test<<Id<<" "<<pass<<" ";
	cout<<"Add Id Success"<<endl;
	Test.close();
}
void main3(string &Id,string &pass)
{
	ifstream Test;
	string Id1,Id2,pass1,Pass;
	cout<<"Login ID: ";
	cin>>Id1;
	Test.open(Id1.c_str(),ios::in);
	Test>>Id>>Pass;
	if(Id1 == Id){cout<<"Enter your Pasword: ";
	cin >> pass1;
	if(pass1 == Pass){cout<<"FINISH!!!!"<<endl;main4(Id,Pass);}
	else{cout<<"WRONG!! Password"<<endl;}}
	else{cout<<"No Account ID!!"<<endl;}
	Test.close();
}
void main4(string &Id,string &pass)
{
	ifstream Test1;
	ofstream Test;
	const int M = 30;
	string line;
	int lotterry[M],a = 0,b = 0,c = 0,d = 0,e = 0,f = 0,Pay1 = 0,count = 0;
	char H;
	Test1.open(Id.c_str(),ios::in);
	Test1>>Id>>pass>>d>>Pay1>>f>>e;
	while (Test1.get(H))
	for(int i=0;i<Pay1;i++){
		Test1>>lotterry[i];}
	Test1.close();
	do{
		cout<<setfill('=')<<setw(31)<<"="<<endl;
		cout<<setfill(' ')<<setw(9)<<" "<<"Menu Lotterry"<<endl;
		cout<<setfill('=')<<setw(31)<<"="<<endl;
		cout<<setfill(' ')<<setw(3)<<" "<<"1.Enter your money"<<endl;
		cout<<setfill(' ')<<setw(3)<<" "<<"2.Enter pay your money"<<endl;
		cout<<setfill(' ')<<setw(3)<<" "<<"3.Enter you Lotter number"<<endl;
		cout<<setfill(' ')<<setw(3)<<" "<<"4.Show lottery"<<endl;
		cout<<setfill(' ')<<setw(3)<<" "<<"5.Check money"<<endl;
		cout<<setfill(' ')<<setw(3)<<" "<<"6.Exit"<<endl;
		cout<<setfill('=')<<setw(31)<<"="<<endl;
		cout<<"Enter your chioce: ";
		cin >> a;
		if(a == 1){d = Read(d); b = 0;system("cls");}
		else if(a == 2){c = Cal(d,c);e = clabonus(c,e); b = 0;system("cls");}
		else if(a == 3){
			if(c >= 10){f = Cal2(c,lotterry,d,e,f,Pay1,Id); b = 0;system("cls");}
			else if(c < 10){cout<<"Please Pay money agian :')"<<endl;}
		}
		else if(a == 4){system("cls");Cal3(lotterry,f,Pay1); b = 0;}
		else if(a == 5){system("cls");cout<<"Your have a money : "<<d<<endl; b = 0;}
		else{cout<<"Goodbye . . . ."<<endl;
		Test.open(Id.c_str(),ios_base::out);
		Test<<Id<<" "<<pass<<" "<<d<<" "<<Pay1<<" "<<f<<" "<<e<<endl;
		for(int i = 0;i < Pay1;i++)
		{
			Test<<lotterry[i]<<endl;
		}
		Test.close();
		b = 1;system("exit");
		}
	}while(b != 1);
	
}
int Read(int &monney)
{
	int a,b=0;
	do{
	cout<<"Enter your money (1000 - 5000): ";
	cin>>a;
	if(a < 1000){cout<<"Please enter more than 1000."<<endl; b = 0;}
	else if(a > 5000){cout<<"You have more money than a certain amount."<<endl; b = 0;}
	else if(a >= 1000 && a <= 5000){b = 1;}
	}while(b != 1);
	return(a);
}
int Cal(int &monney,int &Pay)
{
	int w = 0;
	do{
	cout<<"10 Bath per 1 random"<<endl;
	cout<<"If more than 100 Bath will get bonus X3"<<endl;
	cout<<"If more than 1000 Bath will receive bonus X5"<<endl;
	cout<<"Enter your pay money: ";
	cin>>Pay;
	if(Pay < 10){cout<<"Please Enter more than 10 ... "<<endl;w = 0;}
	else if(Pay > monney){cout<<"Not enough money.Please Enter agian . . .  "<<endl;w = 0;}
	else if(Pay >= 10||Pay <= monney){monney = monney - Pay;w = 1;}
	}while(w != 1);
	return(Pay); 
}
int clabonus(int &Pay,int &Bonus)
{
	if(Pay >= 100){cout<<"you have a bonus X3"<<endl; Bonus = 3;}
	else if(Pay >= 1000){cout<<"you have a bonus X5"<<endl; Bonus = 5;}
	else{Bonus = 2;}
	return(Bonus);
}
int Cal2(int &Pay,int lotterry[],int &monney,int &Bonus,int &random,int &Pay1,string &Id)
{
	ofstream Test;
	
	int B,G;
	srand(unsigned int (time(NULL)));
	Pay1 = Pay/10;
	B = rand()%100;
	cout<<"You can random is : "<<Pay / 10<<endl;
	for(int i = 0;i < Pay1;i++)
	{
		cout<<"Enter yours number is : ";
		cin>>lotterry[i];
	}
	for(int i = 0;i < Pay1;i++)
	{
		if(lotterry[i] == B){monney = (Pay*Bonus) + monney;
		cout<<"You Win you have a monney :"<<monney<<endl;}
	}
	Pay = 0;return(B);
}
int Cal3(int lotterry[],int &random,int &Pay1)
{
	
	cout<<setfill('=')<<setw(31)<<"="<<endl;
	cout<<"|"<<setfill(' ')<<setw(5)<<"Number random is "<<setfill(' ')<<setw(3)<<"|"<<setfill(' ')<<setw(5)<<random<<setfill(' ')<<setw(5)<<"|"<<endl;
	cout<<setfill('=')<<setw(31)<<"="<<endl;
	cout<<"|"<<setfill(' ')<<setw(10)<<" Your Enter lotterry "<<setfill(' ')<<setw(9)<<"|"<<endl;
	cout<<setfill('=')<<setw(31)<<"="<<endl;
	for(int i = 0;i < Pay1;i++)
	{
		cout<<"|"<<setfill(' ')<<setw(8)<<i+1<<setfill(' ')<<setw(7)<<"|"<<setfill(' ')<<setw(8)<<lotterry[i]<<setfill(' ')<<setw(7)<<"|"<<endl;
	}cout<<setfill('=')<<setw(31)<<"="<<endl;
	return(0);
}
