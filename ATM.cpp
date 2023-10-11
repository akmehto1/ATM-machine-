#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

bool pass_special(string s){
	 bool big_alphabet=false;
	 bool small_alphabet=false;
	 bool number=false;
	 bool special=false;
	 
	for(int i=0;i<s.length();i++){
		if(s[i]>='A'&&s[i]<='Z')
		big_alphabet=true;
		
		else if(s[i]>='a'&&s[i]<='z')
		small_alphabet=true;
		
		else if(s[i]>='0'&&s[i]<='9')
		number=true;
		
		else
		special=true;
	}
	
   if(small_alphabet&&big_alphabet&&number&&special)
   return 1;
   else return 0;	

}

void  user_id_update(string id){
	ifstream file;
	string name;
	
	file.open("all_user_id.txt");
    
    while(file){
	getline(file,name,'\t');  }
	
	file.close();
	
	ofstream  out;
	out.open("all_user_id.txt");
	
	out<<id<<"\n";
	out<<name;
	
	return ;
	  
}

bool all_user_id(string id){
	ifstream file;
	string name;
	
	file.open("all_user_id.txt");
    
    while(file){
	file>>name;
	if(name.compare(id)==0)
	return 1;
	}
	
	return 0;
}




//hidden pass
string hidden_password(){
	int i;
	
	char p[9];
	
	for( i=0;i<8;i++){
		p[i]=getch();
		 
		 
	cout<<"*";   
	}
	
	p[i]='\0';
	cout<<"\n";
	string pass;
	
	for(i=0;p[i]!='\0';i++){
		pass+=p[i];
		
	}
	return pass;
}



//check
bool check(string id,string pass){
	ifstream file;
	string pin;
	int amount;
	file.open(id.c_str());
	file>>amount;
	file>>pin;

	 if(pin==pass)
	 return 1;
	 else return 0;
	
}

//format pin
void format_pin(string id){
	ifstream file;
	string pin,store;
	int amount;
	
	file.open(id.c_str());
	
	file>>amount;
	file>>pin;
	while(file){
	getline(file,store,'\t');  }
	file.close();
	ofstream files;
	files.open(id.c_str());
	again:

	cout<<"Enter new password"<<endl;
    cout<<"pass word must be 8 character"<<endl;	
	string new_pass;
	cin>>new_pass;
	
	if(pass_special(new_pass)==0){
		cout<<"one must have charactor with small and big alphabet"<<endl;
		cout<<"must have number value"<<endl;
		cout<<"must have special charactor"<<endl;
		goto again;
	}
	
	files<<amount<<"\n"<<new_pass<<store;
	
}
//check balance 
void check_balance(string id){
	ifstream file;
	file.open(id.c_str());
	string value;
	file>>value;
	//balance print
	cout<<"Your account balance is  "<<value;
}

//add cash amount
void add_cash(string id){
    ifstream file;
	string value;
	int store1;
	file.open(id.c_str());
	int amout;
	file>>store1;
	cin>>amout;
	while(file){
	getline(file,value,'\t');  }
	store1+=amout;	
	file.close();
	ofstream files;
	files.open(id.c_str());
	
	files<<store1;
	files<<value;
}

//after login
void your_acc(string id){
	label:
	getch();
	system("cls");
	cout<<"0.EXIT"<<endl;
	cout<<"1.check balance"<<endl;
	cout<<"2.Add cash"<<endl;
	cout<<"3.pin format"<<endl;
	
    int value;
    cin>>value;
	switch(value){
		case 1:{
			check_balance(id);
			goto label;
			
		}
		
		case 2:{
			add_cash(id);
			
			goto label;
		}
		
		case 3:{
			format_pin(id);
			goto label;
		}
		default:
			return ;
		
	}
	
	
}

void reg(){
	string name,age,pin,mother,father,id;
	int amount;
	//name 
	cin.get();
	cout<<"Enter your name "<<endl;
	getline(cin,name,'\n');
	//age
	cout<<"Enter age"<<endl;
	cin>>age;
	
	//id
	label:
	cout<<"Enter your id"<<endl;
	cin>>id;
	if(all_user_id(id)){
		cout<<"id with name is already present plz Enter new id"<<endl;
		goto label;
	}
	
	//id update
	user_id_update(id);
	//amount
	cout<<"Enter amount"<<endl;
	cin>>amount;
	
	//pin
	again:
	cout<<"Enter pin"<<endl;
	cin>>pin;
	if(pass_special(pin)==0){
		cout<<"one must have charactor with small and big alphabet and must be 8 character"<<endl;
		cout<<"must have number value"<<endl;
		cout<<"must have special charactor"<<endl;
		goto again;
	}
	//parent name
	cin.get();
	cout<<"Enter father name then mother"<<endl;
	getline(cin,father,'\n');
	getline(cin,mother,'\n');
	string ids=id;
	//of stream
	ofstream in;
	string file=id+".txt";
	in.open(file.c_str());
	
	in<<amount<<"\n"<<pin<<"\n"<<ids<<"\n"<<name<<"\n"<<father<<"\n"<<mother<<"\n"<<age<<"\n";
}

void read(){
	ifstream in;
	string id,value;
	cin.get();
	getline(cin,id,'\n');
	id=id+".txt";
	in.open(id.c_str());
	while(in){
		getline(in,value,'\t');}
		
	cout<<value;
	return ;
}

void login(){
	//declare 
	ifstream file;
	string id,pass;
	static int i=3;
	
	up:
		
	//id input
	cin>>id;
	id=id+".txt";
	file.open(id.c_str());
	cout<<"Enter your password"<<endl;
	//five password
	pass=hidden_password();
	
	
	if(i>0){
	if(file&&check(id,pass)){
		cout<<"You login"<<endl;
		 your_acc(id);
	}
	
	else{i--;
		cout<<"You enter wrong password or id \n Try again"<<endl;

		//goto statement;
		goto up;
	}}
	else{
		cout<<"you attemp maximum chance";
	}
	
}

int main(){
    
    cout<<"*********************Welcome to the bank system*******************************\n******************************************************************************"<<endl<<endl;
    cout<<endl<<"1.Enter your id and password"<<endl;
    cout<<"2.New regestration"<<endl;
    int value;
    cin>>value;
    switch(value){
    	case 1:{
    		//login  id
    		cout<<"Enter user id"<<endl;
    		
    		login();
    		
			break;
		}
		//new registration
		case 2:{
			reg();
			system("cls");
			cout<<"you succesfully enter new account"<<endl<<"Enter one for login and Zero for exit";
			int num;
			cin>>num;
			if(num==2)
			break;
			else if(num==1)
			login();
			else
			exit(0);
		}
	}
  
  
	return 0;
}
