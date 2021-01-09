//Ahmed Wadood 19I-1858 B OOP Project
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class FileHandle {

public:

	fstream read_From_File;
	string customer_First_Name;
	long balance;
	double Account_Id;
	double Account_Pin;

public:

	void read() {

		read_From_File.open("customer.txt", ios::in | ios::app);

		get_Name();
		get_Balance();
		getID();
		get_Pin();
	}

	long getID() {

		read_From_File >> Account_Id;
		cout << endl;

		return Account_Id;
	}

	string get_Name() {

		read_From_File >> customer_First_Name;
		cout << endl;

		return customer_First_Name;
	}

	long get_Pin() {

		read_From_File >> Account_Pin;
		cout << endl;

		return Account_Pin;

	}

	double get_Balance() {

		read_From_File >> balance;
		cout << endl;

		return balance;
	}

};

class Transaction {

public:

	string name;
	double balane;
	long accountnumber;
	long accountid;
	FileHandle obj;
public:

	void read() {

		fstream read_From_File;
		read_From_File.open("customer.txt", ios::in | ios::app);

		read_From_File >> name;
		read_From_File >> balane;
		read_From_File >> accountnumber;
		read_From_File >> accountid;

	}

	void write()
	{
		fstream read_From_File;
		read_From_File.open("customer.txt", ios::in | ios::app);

		read_From_File << name << " ";
		read_From_File << balane << " ";
		read_From_File << accountnumber << " ";
		read_From_File << accountid << " ";

		exit;


	}

};

class Deposit :public Transaction {

	string field_type;

public:

	double amount_deposit() {

		read();

		double deposit;
		cout << "Enter the amount to deposit :";
		cin >> deposit;

		balane = deposit + balane;
		cout << "Deposited Amount: " << deposit<<endl;
		write();

		return balane;

	}

};

class withDraw :public Transaction {

	string field_type;

public:

	double amount_Withdraw() {

		read();

		cout << " choose a withdrawal option(1-6): ";
		int option;
		cin >> option;

		if (option == 1) {
			if (balane < 20)
			{
				cout << "You dont have enough amount"<<endl;

			}
			else {
				balane = balane - 20.0;
				cout << "You have withdrawn 20$ " << endl;
				cout << "Please Take your withdraw amount: " << endl;
			}
			write();

			return balane;

		}

		else if (option == 2) {

			if (balane < 40.0) {

				cout << "Your balance is less : plz re_Enter amount " << endl;
			}

			else

				balane = balane - 40.0;
			cout << "You have withdrawn 40$"<<endl;
			cout << "Plz Take your withdraw amountL " << endl;

			write();

			return balane;

		}

		else if (option == 3) {

			if (balane < 60.0) {

				cout << "Your balance is less : plz re_Enter amount " << endl;
			}

			else

				balane = balane - 60.0;
			cout << "You have withdrawn 60$" << endl;
			cout << "Plz Take your withdraw amount: " << endl;

			write();

			return balane;
		}

		else if (option == 4) {

			if (balane < 100.0) {

				cout << "Your balance is less : plz re_Enter amount " << endl;
			}

			else

				balane = balane - 100.0;
			cout << "You have withdrawn 100$" << endl;
			cout << "Plz Take your withdraw amount: " << endl;

			write();

			return balane;

		}

		else if (option == 5) {

			if (balane < 200.0) {

				cout << "Your balance is less : plz re_Enter amount " << endl;
			}

			else

				balane = balane - 200.0;
			cout << "You have withdrawn 200$" << endl;
			cout << "Plz Take your withdraw amount: " << endl;

			write();

			return balane;

		}

		else if (option == 6) {

			cout << "Your Transaction is going to cancel: " << endl;

		}
	}
};

class Manu {

public:

	string name;
	double balance;
	long V_Account_Id;
	long V_Account_Pin;
	long get_AccNo;
	long get_AccPin;
	withDraw obj;
	Deposit obj2;
	FileHandle obj3;

public:

	void Welcome() {


		cout << "****************WELCOME !***************** " << endl;
	}

	void input_Account_del() {

		cout << "Enter Your 8-digits Account Number: ";
		cin >> get_AccNo;

		cout << endl;

		cout << "Enter Your 5-digits Account Pin: ";
		cin >> get_AccPin;

	}

	void Choice_Selection() {

		cout << " Main Menu: " << endl;
		cout << "  1-  View My Balance: " << endl;
		cout << "  2-  Withdraw Cash: " << endl;
		cout << "  3-  Deposit Funds: " << endl;
		cout << "  4-  Exit: " << endl;

		Transaction_Pass();
	}

	void Transaction_Pass() {

		int choice;
		cout << endl;

		cout << "Enter Your Choice: ";
		cin >> choice;

		if (choice == 1) {

			fstream read_amount;
			read_amount.open("customer.txt", ios::in | ios::app);

			while (!read_amount.eof()) {

				read_amount >> name;
				read_amount >> balance;
				read_amount >> V_Account_Id;
				read_amount >> V_Account_Pin;

				if ((V_Account_Id == get_AccNo) && (V_Account_Pin == get_AccPin)) {

					cout << "Your remaining balance :" << balance << endl;

					cout << "Thanku For using our ATM \n" << endl;

					Choice_Selection();
				}
			}
		}

		else if (choice == 2) {

			cout << " Withdrawal options: " << endl;
			cout << "    1-    $20        " << "      4-     $100 " << endl;
			cout << "    2-    $40        " << "      5-     $200 " << endl;
			cout << "    3-    $60        " << "      6-     Cancel Transaction" << endl;

			obj.amount_Withdraw();
			Choice_Selection();
		}

		else if (choice == 3) {

			obj2.amount_deposit();
			Choice_Selection();
		}

		else if (choice == 4) {

			cout << "***Thank You***" << endl;

		}

		else if ((choice == 5) && (choice < 10)) {

			cout << "You select an invalid option:" << endl;

			Choice_Selection();
		}
	}

};

class Account {

public:

	string customer_First_Name;
	string customer_Last_Name;
	double balance;
	long Account_Id;
	long Account_Pin;
	Manu obj;
	long verify_ID;
	long verify_Pin;

public:

	Account() {

		customer_First_Name = "";
		customer_Last_Name = "";
		balance = 00000;
		Account_Id = 0000000;
		Account_Pin = 0000;
		obj.get_AccNo = 0000;
		obj.get_AccPin = 000;
		verify_ID = 700;
		verify_Pin = 800;
	}


	void Get_Acc_detail() {

		obj.input_Account_del();

		verify_ID = obj.get_AccNo;
		verify_Pin = obj.get_AccPin;

	}

	void show() {

		obj.Choice_Selection();

	}
};

class Verification {

	string name;
	double balance;
	long V_Account_Id;
	long V_Account_Pin;
	long accid;
	long accpin;
	Account obj;

public:

	void check_validation() {

		fstream verify;
		verify.open("customer.txt", ios::in | ios::app);

		obj.Get_Acc_detail();

		do {

			verify >> name;
			verify >> balance;
			verify >> V_Account_Id;
			verify >> V_Account_Pin;

			if ((obj.verify_ID == V_Account_Id) && (obj.verify_Pin == V_Account_Pin)) {

				cout << "\nplease wait: Your request is being proceed:" << endl;

				obj.show();

				break;
			}

		} while (!verify.eof());

		cout << "\n *** Invalid account number or Pin\n" << endl;
	}
};




int main() {


	Manu menu;
	menu.Welcome();

	Verification ver;
	ver.check_validation();

}