#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>

using namespace std;
ofstream phone("contacts.txt" , ios::app);
string fname , lname , ph_num;
bool cont = true;
bool check;
bool checkDigits(string x){
	check = false;
	if(x.length() == 11){
		check = true;
	}
	if(check==true){
		return true;
	}
}
checkNums(string x){
	check = true;
	for(int i=0; i < x.length(); i++){
		if(!(int(x[i]) >= 48 && int(x[i]) <= 57)){
			//we got something except number, that's why false
			check = false;
			break;
		}
	}
	if(check==true){
		return true;
	}
	if(check == false){
		return false;
	}
}
void addContact(){
	here:
	cout << "Enter first name: ";
	cin >> fname;
	cout << "Enter last name: ";
	cin >> lname;
	cout << "Enter phone number: ";
	cin >> ph_num;
	if(checkDigits(ph_num) == true){
		if(checkNums(ph_num) == true){
			if(phone.is_open()){
		    phone << fname << " " << lname << " " << ph_num <<endl;
		    cout << "Contact saved succesfully" <<endl;
        	}
		}
		else{
			cout << "INVALID" <<endl;
			cout << "Number should contain digits only";
		}
	}
	else{
		cout << "INVALID" <<endl;
		cout << "Number should contain 11 digits";
	}
	cout << "\nTo add another contact, Press Y OR ";
	cout << "Press any key to exit\n";
	char k;
	cin >> k;
	if(k == 'Y' || k =='y'){
		goto here;
	}
	phone.close();
}
void searchContact(){
	system("cls");
	ifstream file("contacts.txt");
	cout << "Enter keyword to search: ";
	string keyword;
	cin >> keyword;
	while(file >> fname  >> lname >> ph_num){
	    if(keyword == fname || keyword == lname || keyword == ph_num){
	    	cout << "Contact found succesfully" << endl;
        	cout << fname << " " << lname << " " << ph_num <<endl;
		}
	}

	cout << "\nTo search another contact, Press Y OR ";
	cout << "Press any key to exit\n";
	char k;
	cin >> k;
	if(k == 'Y' || k =='y'){
		//goto there;
	}
}
void help(){
	system("cls");
	cout << setw(100);
	cout << "\nThank you for visiting\n\nSmart Home for Your Contacts.Where your Contacts Live.\n";
    cout << "Welcome to the Contact Book official website, where you can find information about all";
	cout << " features, latest versions and future releases, program versions, and special offers.\n\n";

}
void exitdo(){
	cout << "Exiting..."<<endl;
	cont = false;
	exit(1);
}
void justDoit(){
	ofstream phone("contacts.txt" , ios::app);
	short int goAround;
	system("cls");
	system("color F9");
    cout << setw(60)<<endl<< "---------";
	cout << setw(60)<<endl<< "Home Page";
	cout << setw(60)<<endl<< "---------" << endl;
	cout << " 1- Add Contact \n\n 2- Search Contact \n\n 3- Help \n\n 4- Exit \n\n"<< ">>>";
	cin >> goAround;
	switch(goAround){
		case 1:
			addContact();
			break;
		case 2:
			searchContact();
			break;
		case 3:
			help();
			break;
		case 4:
			exitdo();
			break;
		default:
			cout << "Invalid Value"<<endl<< "Press any key to continue: ";
			if(getch()== true){
				justDoit();
			}
	}
	cout << setw(60)<< "To restart press any key except" << "E\n";
	cout << setw(62)<< "To exit the program, Press E\n";
	char a;
	cin >> a;
	if(a == 'E'  || a == 'e'){
		cont= false;
	}
}
int main(){
	while(cont == true){
	  justDoit();	
    }
}

