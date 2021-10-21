#include <iostream>
#include <fstream>
#include <windows.h>

// MUHAMMET MEHMET KIR 1904010013

/*Named railway reservation system project in C++, this program will have features in two modes,
password protection and some basic file handling operations to add and display train inquiry and reservation records.*/

using namespace std;

class Login{
	
	private:
			
		string user_id;
		
		string user_password;
				
	public:
// 			set - get method
//-----------------------------------------------------
		void set_id(string nickname){
			
			user_id = nickname;	
					
		}
		void set_password(string password){
			
			user_password = password;
			
		}
		string get_id(){
			
			return user_id;
			
		}
		string get_password(){
			
			return user_password;
			
		}
//-----------------------------------------------------
		void print_info(){
			
			cout<<user_id<<" "<<user_password<<endl;
			
		}
		
};

class Reservation{
	
	public:
		
		string name;
		
		string surname;
		
		int age;
		
		string f_station;
		
		string l_station;
		
		string time;
		
		string train_name;
		
		void print_info(){
			
			cout<<f_station<<"\t"<<l_station<<"\t"<<time<<"\t"<<train_name<<endl;
			
		}
		
};
// 		function print train information.. train table
void train_info(){	

	cout<<"| First Station | Last Station | Departure Time | Train Name |\n";	
	cout<<"----------------------------------------------------------------\n";
	cout<<"|   MANISA	|   IZMIR      |      09.15     |   TCDD-01  |\n";
	cout<<"----------------------------------------------------------------\n";
	cout<<"|   MANISA	|   BALIKESIR  |      11.30     |   TCDD-02  |\n";
	cout<<"----------------------------------------------------------------\n";
	cout<<"|   MANISA	|   AYDIN      |      13.45     |   TCDD-03  |\n";
	cout<<"----------------------------------------------------------------\n";
	cout<<"|   MANISA	|   CANAKKALE  |      15.00     |   TCDD-04  |\n";
	cout<<"----------------------------------------------------------------\n\n";
	
}


int main(){
	
	Login user;				// login object
	user.set_id("deneme");        // username
	user.set_password("1234");   // password
	
	Reservation r1;		   // reservation object
		
	string id;
	string password;
	
	int selection;	

// 				Login process --> password protection
//--------------------------------------------------------------------------
	cout<<"\n";
	cout<<"\t\tLOGIN SCREEN\n"<<endl;
	while(1){
			
		cout<<"Please enter username: ";
		cin>>id;
		
		cout<<"Please enter user password: ";
		cin>>password;
		
		cout<<"\n";
		
		if(user.get_id() == id && user.get_password() != password){
			
			Sleep(500);
			
			cout<<"Your password is incorrect\n"<<endl;
						
		}			
		else if(user.get_id() != id && user.get_password() == password){
			
			Sleep(500);
			
			cout<<"Your username is incorrect\n"<<endl;
			
		}
		else if(user.get_id() != id && user.get_password() != password){
			
			Sleep(500);
			
			cout<<"Your username and password are incorrect\n"<<endl;
			
		}
		else{
			
			Sleep(500);
			
			cout<<"Login is successful...\n"<<endl;
			
			break;
			
		}				
	}
//--------------------------------------------------------------------------*/
	
	cout<<"1.TRAIN INQUIRY\n2.ADD RESERVATION\n3.VIEW RESERVATION\n4.EXIT\n\n";
		
	while(1){
		
		cout<<"Please select your action: ";
				
		cin>>selection;
		
		cout<<"------------------------------\n";
		
		cout<<"\n";	
			
		if(selection == 1){
			
			train_info();
			
		}
		if(selection == 2){			
			
			cout<<"Please enter the information in order:\n\n";
			
			cout<<"Name: ";
			cin>>r1.name;
			cout<<"\n";
			
			cout<<"Surname: ";
			cin>>r1.surname;
			cout<<"\n";
			
			cout<<"Age: ";
			cin>>r1.age;
			cout<<"\n";
			
			cout<<"First Station: ";
			cin>>r1.f_station;
			cout<<"\n";
			
			cout<<"Last Station: ";
			cin>>r1.l_station;
			cout<<"\n";
			
			cout<<"Departure Time: ";
			cin>>r1.time;
			cout<<"\n";
			
			cout<<"Train Name: ";
			cin>>r1.train_name;
			cout<<"\n";
			
			cout<<"\n";
			
			ofstream file_print("information.txt",std::ios_base::app);
			
			file_print<<"Name: "<<r1.name<<"\n"<<"Surname: "<<r1.surname<<"\n"<<"Age: "<<r1.age<<"\n"<<"First Station: "<<r1.f_station<<"\n"<<"Last Station: "<<r1.l_station<<"\n"<<"Departure Time: "<<r1.time<<"\n"<<"Train Name: "<<r1.train_name<<"\n"<<endl;
						
		}
		if(selection == 3){
			
			ifstream file_read("information.txt");
			
			string line = "";
			
			if(file_read.is_open()){
				
				while(getline(file_read,line)){
					
					cout<<line<<endl;
					
				}
				
				file_read.close();
				
			}
		}
		
		if(selection == 4){
			
			cout<<"Logging out...\n\n";
			
			Sleep(1000);
			
			cout<<"Logout is done..."<<endl;
			
			break;
			
		}
				
	}	
	
	return 0;
}
