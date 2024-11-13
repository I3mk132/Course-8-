 /// _______________________ Project 1 ___________________________
  // Subject : Bank ( Extenstion 2)

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include "MyDateLib.h"

using namespace std;
const string ClientsFileName = "Clients.txt";
const string UsersFileName = "Users.txt";

enum enOperation { eList = 1, eNew = 2, eDelete = 3, eUpdate = 4, eFind = 5, eTransactions = 6, eManageUsers = 7, eLogout = 8 };
enum enTransactionOperation { eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eMainMenu = 4 };
enum enUserManageOperation { euList = 1, euNew = 2, euDelete = 3, euUpdate = 4, euFind = 5, euMainMenu = 6 };
enum enUserPermissions { eAll = -1, pList = 1, pAdd = 2, pDelete = 4, pUpdate = 8, pFind = 16, pTransactions = 32, pManageUsers = 64};

struct stClients {
	string AccountNumber;
	int PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

struct stUsers {
	string Username;
	int Password;
	int Permissions;
	bool MarkForDelete = false;
};

stUsers CurrentUser;

string ReadString(string Message) {
	string Sentence;
	cout << Message;
	getline(cin >> ws, Sentence);
	return Sentence;
}

char ReadChar(string Message) {
	char Character;
	cout << Message;
	cin >> Character;
	cin.ignore(0, '\n');
	return Character;
}

short ReadNumberBetween(string Message, short From, short To) {
	short Num = 0;
	do {
		cout << Message;
		cin >> Num;
	} while (Num < From || Num > To);
	cin.ignore(0, '\n');

	return Num;
}

string Tabs(short Num) {
	string tabs = "";
	for (short i = 0; i < Num; i++) {
		tabs += "\t";
	}
	return tabs;
}

void PrintClientCard(stClients C) {
	cout << "\n----------------------------------";
	cout << "\nAccount Number  : " << C.AccountNumber;
	cout << "\nPin Code        : " << C.PinCode;
	cout << "\nName            : " << C.Name;
	cout << "\nPhone           : " << C.Phone;
	cout << "\nAccount Balance : " << C.AccountBalance;
	cout << "\n----------------------------------" << endl;
}

void PrintUserCard(stUsers U) {
	cout << "\n----------------------------------";
	cout << "\nUsername    : " << U.Username;
	cout << "\nPassword    : " << U.Password;
	cout << "\nPermissions : " << U.Permissions;
	cout << "\n----------------------------------" << endl;
}

bool SearchIfAccountNumberInFile(vector<stClients>& vClients, string AccountNumber, stClients& Client, bool Delete = false) {
	for (stClients& C : vClients) {
		if (C.AccountNumber == AccountNumber) {

			Client = C;

			if (Delete) {
				C.MarkForDelete = true;
			}

			return true;

		}
	}
	return false;
}

bool SearchIfUsernameInFile(vector<stUsers>& vUsers, string Username, stUsers& User, bool Delete = false) {
	for (stUsers& U : vUsers) {

		if (U.Username == Username) {
			User = U;
			if (Delete) {
				U.MarkForDelete = true;
			}

			return true;
		}

	}
	return false;
}

bool SearchIfUsernameAndPasswordInFile(vector<stUsers> vUsers, string Username, int Password, stUsers& User) {
	for (stUsers& U : vUsers) {
		if (U.Username == Username && U.Password == Password) {
			User = U;
			return true;
		}
	}
	return false;
}

bool CheckAccessPermission(enUserPermissions Permission) {
	return ((CurrentUser.Permissions & Permission) == Permission || CurrentUser.Permissions == enUserPermissions::eAll);
}

stClients ReadClientInformations(vector<stClients>& vClient, bool WithAccountNumber = true) {
	stClients Client;

	if (WithAccountNumber) {
		cout << "Enter Account Number? ";
		cin >> Client.AccountNumber;

		while (SearchIfAccountNumberInFile(vClient, Client.AccountNumber, Client)) {
			cout << "Client with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
			cin >> Client.AccountNumber;
		};
	}

	cout << "Enter Pin Code? ";
	cin >> Client.PinCode;

	cout << "Enter Name? ";
	getline(cin >> ws, Client.Name);

	cout << "Enter Phone? ";
	cin >> Client.Phone;

	cout << "Enter Account Balance? ";
	cin >> Client.AccountBalance;

	return Client;
}

short GetPermissions();

void PrintAccessDeclined();

stUsers ReadNewUser(vector<stUsers>& vUsers, bool WithUsername = true) {
	stUsers User;

	if (WithUsername) {
		cout << "\nEnter Username? ";
		cin >> User.Username;
		while (SearchIfUsernameInFile(vUsers, User.Username, User)) {
			cout << "\nUser with [" << User.Username << "] already exists, Enter Another Username? ";
			cin >> User.Username;
		}
	}

	cout << "\nEnterPassword? ";
	cin >> User.Password;

	User.Permissions = GetPermissions();

	return User;
}

vector<string> SplitString(string Line, string Delim) {
	short pos;
	vector<string> vString;
	string sWord = "";

	while ((pos = Line.find(Delim)) != std::string::npos) {
		sWord = Line.substr(0, pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		Line.erase(0, pos + Delim.length());
	}
	if (Line != "") {
		vString.push_back(Line);
	}
	return vString;
}

stClients ConvertLineToRecord(string Line, string Seperator) {
	stClients Client;
	vector<string> vString = SplitString(Line, Seperator);

	Client.AccountNumber = vString[0];
	Client.PinCode = stoi(vString[1]);
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stod(vString[4]);

	return Client;
}

stUsers ConvertLineToUsersRecord(string Line, string Seperator) {
	stUsers User;
	vector<string> vString = SplitString(Line, Seperator);

	User.Username = vString[0];
	User.Password = stoi(vString[1]);
	User.Permissions = stoi(vString[2]);

	return User;
}

string ConvertRecordToLine(stClients Client, string Seperator) {
	string Line = "";

	Line += Client.AccountNumber + Seperator;
	Line += to_string(Client.PinCode) + Seperator;
	Line += Client.Name + Seperator;
	Line += Client.Phone + Seperator;
	Line += to_string(Client.AccountBalance);

	return Line;
}

string ConvertRecordToLine(stUsers User, string Seperator) {
	string sWord = "";
	sWord += User.Username + Seperator;
	sWord += to_string(User.Password) + Seperator;
	sWord += to_string(User.Permissions);
	return sWord;
}

void SaveClientDataToFile(vector<stClients>& vClient, string FileName) {
	fstream MyFile;
	string Line = "";
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open()) {

		for (stClients& C : vClient) {

			if (!C.MarkForDelete) {
				Line = ConvertRecordToLine(C, "#//#");
				MyFile << Line << endl;
			}

		}
		MyFile.close();
	}
}

void SaveUsersDataToFile(vector<stUsers>& vUser, string FileName) {
	fstream File;
	string Line;
	File.open(FileName, ios::out);

	if (File.is_open()) {

		for (stUsers& U : vUser) {

			if (!U.MarkForDelete) {
				Line = ConvertRecordToLine(U, "#//#");
				File << Line << endl;
			}

		}
		File.close();
	}
}

vector<stClients> LoadClientDataFromFile(string FileName) {
	vector<stClients> vClients;
	fstream MyFile;
	string Line = "";
	stClients Client;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {
		while (getline(MyFile, Line)) {
			Client = ConvertLineToRecord(Line, "#//#");
			vClients.push_back(Client);
		}
		MyFile.close();
	}

	return vClients;
}

vector<stUsers> LoadUsersDataFromFile(string FileName) {
	vector<stUsers> vUsers;
	fstream MyFile;
	string Line = "";
	stUsers User;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {
		while (getline(MyFile, Line)) {
			User = ConvertLineToUsersRecord(Line, "#//#");
			vUsers.push_back(User);
		}
		MyFile.close();
	}

	return vUsers;
}

short GetPermissions() {
	short Permissions = 0;

	char Access = 'n';
	cout << "\n\nDo you want to give full access? Y/n? ";
	cin >> Access;
	if (tolower(Access) == 'y') {
		return enUserPermissions::eAll;
	}

	cout << "Do You want to give access to: ";
	char ShowClient = 'n';
	cout << "\n\nShow Client List? y/n? ";
	cin >> ShowClient;
	if (tolower(ShowClient) == 'y') {
		Permissions += enUserPermissions::pList;
	}

	char NewClient = 'n';
	cout << "\n\nAdd New Client? y/n? ";
	cin >> NewClient;
	if (tolower(NewClient) == 'y') {
		Permissions += enUserPermissions::pAdd;
	}

	char DeleteClient = 'n';
	cout << "\n\nDelete Client? y/n? ";
	cin >> DeleteClient;
	if (tolower(DeleteClient) == 'y') {
		Permissions += enUserPermissions::pDelete;
	}

	char UpdateClient = 'n';
	cout << "\n\nUpdate Client? y/n? ";
	cin >> DeleteClient;
	if (tolower(UpdateClient) == 'y') {
		Permissions += enUserPermissions::pUpdate;
	}

	char FindClient = 'n';
	cout << "\n\nFind Client? y/n? ";
	cin >> FindClient;
	if (tolower(FindClient) == 'y') {
		Permissions += enUserPermissions::pFind;
	}

	char Transactions = 'n';
	cout << "\n\nTransactions? y/n? ";
	cin >> Transactions;
	if (tolower(Transactions) == 'y') {
		Permissions += enUserPermissions::pTransactions;
	}

	char ManageUsers = 'n';
	cout << "\n\nManage Users? y/n? ";
	cin >> ManageUsers;
	if (tolower(ManageUsers) == 'y') {
		Permissions += enUserPermissions::pManageUsers;
	}

	return Permissions;
}

void DeleteClientByAccountNumber(vector<stClients> vClient) {
	stClients Client;
	char isSure = 'n';

	string AccountNumber = "";
	cout << "\n\nPlease enter Account Number? " << endl;
	cin >> AccountNumber;

	while (!SearchIfAccountNumberInFile(vClient, AccountNumber, Client, true)) {
		cout << "Account Number [" << AccountNumber << "] is Not exists, Please Enter another Number? ";
		cin >> AccountNumber;
	}
	cout << "\nThe following are the client details: ";
	PrintClientCard(Client);

	cout << "\n\n\nAre You sure you want to delete this client? y/n ?";
	cin >> isSure;
	if (tolower(isSure) == 'y') {
		SaveClientDataToFile(vClient, ClientsFileName);

		cout << "\n\n\nClient Deleted Successfully!  " << endl;
	}
}

void NewTransaction(vector<stClients>& vClients, string AccountNumber, int Deposit) {
	for (stClients& Client : vClients) {
		if (AccountNumber == Client.AccountNumber) {
			Client.AccountBalance += Deposit;
		}
	}
}

void AddClient(string FileName, stClients AddClient) {
	fstream MyFile;
	string Line = "";

	MyFile.open(FileName, ios::in | ios::app);

	if (MyFile.is_open()) {
		Line = ConvertRecordToLine(AddClient, "#//#");
		MyFile << Line << endl;

		MyFile.close();
	}
}

void AddClients() {
	char PlayAgain = 'y';
	stClients Client;
	vector<stClients> vClients = LoadClientDataFromFile(ClientsFileName);

	cout << "Adding New Clients: \n\n";

	while (tolower(PlayAgain) == 'y') {
		Client = ReadClientInformations(vClients);
		AddClient(ClientsFileName, Client);

		cout << "\n\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> PlayAgain;
	}
}

void UpdateClient(vector<stClients> vClients) {
	char Char = 'n';
	string AccountNumber = "";


	cout << "\nPlease Enter Account Number? ";
	cin >> AccountNumber;

	for (stClients& C : vClients) {
		if (AccountNumber == C.AccountNumber) {

			cout << "The following are the client details: \n";
			PrintClientCard(C);

			cout << "\n\n\nAre you sure you want update this client? y/n ? ";
			cin >> Char;
			if (tolower(Char) == 'y') {
				cout << "\n\n\n";
				C = ReadClientInformations(vClients, false);
				C.AccountNumber = AccountNumber;
				cout << "\n\nClient Updated Successfully. " << endl;
				break;
			}
		}
	}

	SaveClientDataToFile(vClients, ClientsFileName);

}

void FindClient(vector<stClients> vClients) {
	string AccountNumber = "";
	stClients Client;

	cout << "\nPlease Enter Account Number? ";
	cin >> AccountNumber;

	while (!SearchIfAccountNumberInFile(vClients, AccountNumber, Client)) {
		cout << "Account Number [" << AccountNumber << "] is Not exists, Please Enter another Number? ";
		cin >> AccountNumber;
	}

	cout << "The following are the client details: \n";
	PrintClientCard(Client);
}

void AddDeposit(vector<stClients> vClients) {

	string AccountNumber = "";
	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;

	stClients Client;
	while (!SearchIfAccountNumberInFile(vClients, AccountNumber, Client)) {
		cout << "Client with [" << AccountNumber << "] does not exist." << endl;

		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
	}

	cout << "\nThe following are the client details: ";
	PrintClientCard(Client);

	int Deposit;
	cout << "\nPlease enter deposit amount? ";
	cin >> Deposit;

	char isSure = 'n';
	cout << "\nAre you sure you want perform this transaction? y/n? ";
	cin >> isSure;
	if (tolower(isSure) == 'y') {
		NewTransaction(vClients, AccountNumber, Deposit);
		cout << "\nDone Successfully. New balance is: " << Deposit + Client.AccountBalance;

		SaveClientDataToFile(vClients, ClientsFileName);
	}


}

void WithdrawDeposit(vector<stClients> vClients) {

	string AccountNumber;
	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;

	stClients Client;
	while (!SearchIfAccountNumberInFile(vClients, AccountNumber, Client)) {
		cout << "Client with [" << AccountNumber << "] does not exist." << endl;

		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
	}

	cout << "\nThe following are the client details: ";
	PrintClientCard(Client);

	int Withdraw;
	cout << "\nPlease enter withdraw amount? ";
	cin >> Withdraw;
	while (Withdraw > Client.AccountBalance) {
		cout << "Amount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
		cout << "\nPlease enter another amount? ";
		cin >> Withdraw;
	}


	char isSure = 'n';
	cout << "\n\nAre you sure you want perform this transaction? y/n? ";
	cin >> isSure;

	if (tolower(isSure) == 'y') {
		Withdraw *= -1;
		NewTransaction(vClients, AccountNumber, Withdraw);
	}

	SaveClientDataToFile(vClients, ClientsFileName);
}

void AddUser(stUsers User, string FileName) {
	fstream File;
	string Line;

	File.open(FileName, ios::in | ios::app);

	if (File.is_open()) {
		Line = ConvertRecordToLine(User, "#//#");
		File << Line << endl;

		File.close();
	}
}

void AddUsers(vector<stUsers> vUsers) {
	char PlayAgain = 'y';
	stUsers User;

	while (tolower(PlayAgain) == 'y') {
		cout << "Adding New User : " << endl;
		User = ReadNewUser(vUsers);
		AddUser(User, UsersFileName);

		cout << "User Added Successfully, do you want to add more Users? Y/N? ";
		cin >> PlayAgain;
	}
}

void DeleteUserByUsername(vector<stUsers> vUsers) {
	stUsers User;
	bool isSure = false;

	cout << "Please Enter Username? : ";
	cin >> User.Username;
	if (!SearchIfUsernameInFile(vUsers, User.Username, User, true)) {
		cout << "User with Username (" << User.Username << ") is NOT Found! " << endl;
		return;
	}
	cout << "The following are the User details: ";
	PrintUserCard(User);

	cout << "\n\n\nAre you sure you want delete this User? y/n? ";
	cin >> isSure;
	if (isSure) {
		SaveUsersDataToFile(vUsers, UsersFileName);
		cout << "\n\n Client Deleted Successfully. " << endl;
	}

}

void UpdateUsers(vector<stUsers> vUsers) {
	stUsers User;
	char isSure = 'n';

	cout << "Please Enter Username? : ";
	cin >> User.Username;

	if (!SearchIfUsernameInFile(vUsers, User.Username, User)) {
		cout << "Username With Username (" << User.Username << ") is NOT Found. " << endl;
		return;
	}

	for (stUsers& U : vUsers) {
		if (User.Username == U.Username) {

			cout << "The following are the User details: \n";
			PrintUserCard(U);

			cout << "\n\n\nAre you sure you want update this User? y/n ? ";
			cin >> isSure;
			if (tolower(isSure) == 'y') {
				cout << "\n\n\n";
				U = ReadNewUser(vUsers, false);
				U.Username = User.Username;
				break;
			}
		}
	}
	SaveUsersDataToFile(vUsers, UsersFileName);
	cout << "\n\nUser Updated Successfully. " << endl;

}

void FindUser(vector<stUsers> vUsers) {
	stUsers User;
	string Username;
	cout << "Please Enter Username? ";
	cin >> Username;
	while (!SearchIfUsernameInFile(vUsers, Username, User)) {
		cout << "Username not found (" << Username << ") Please enter another one : " << endl;
		cin >> Username;
	}
	cout << "The following are the User details: \n";
	PrintUserCard(User);
}

void GoBackToMainMenu() {
	cout << "\n\n\nPress any key to go back to Main Menu...";
	system("pause > 0");
}

void GoBackToTransactionMenu() {
	cout << "\n\n\nPress any key to go back to Transaction Menu...";
	system("pause > 0");
}

void GoBackToUserManageMenu() {
	cout << "\n\n\nPress any key to go back to User Manage Menu...";
	system("pause > 0");
}

void PrintMainMenuScreen() {
	cout << "==============================================\n";
	cout << Tabs(2) << "Main Menu Screen\n";
	cout << "==============================================\n";
	cout << Tabs(1) << "[1] Show Client List. \n";
	cout << Tabs(1) << "[2] Add New Client. \n";
	cout << Tabs(1) << "[3] Delete Client. \n";
	cout << Tabs(1) << "[4] Update Client Info. \n";
	cout << Tabs(1) << "[5] Find Client. \n";
	cout << Tabs(1) << "[6] Transactions. \n";
	cout << Tabs(1) << "[7] Manage Users. \n";
	cout << Tabs(1) << "[8] Logout. \n";
	cout << "==============================================" << endl;
}

void PrintClientList(vector<stClients> vClients) {
	for (stClients& Client : vClients) {
		cout << "|=| " << setw(17) << left << Client.AccountNumber;
		cout << "|=| " << setw(15) << left << Client.PinCode;
		cout << "|=| " << setw(26) << left << Client.Name;
		cout << "|=| " << setw(17) << left << Client.Phone;
		cout << "|=| " << setw(10) << left << Client.AccountBalance;
		cout << endl;
	}
}

void PrintListScreen() {
	if (!CheckAccessPermission(enUserPermissions::pList)) {
		PrintAccessDeclined();
		return;
	}
	system("cls");
	vector<stClients> vClients = LoadClientDataFromFile(ClientsFileName);

	cout << Tabs(4) << "Client List (" << vClients.size() << ") Clients(s).\n";
	cout << "________________________________________________________________________________________________________\n\n";
	cout << "|=| " << setw(17) << left << "Account Number";
	cout << "|=| " << setw(15) << left << "Pin Code";
	cout << "|=| " << setw(26) << left << "Client Name";
	cout << "|=| " << setw(17) << left << "Phone";
	cout << "|=| " << setw(10) << left << "Balance";
	cout << "\n________________________________________________________________________________________________________\n\n";
	PrintClientList(vClients);
	cout << endl;
	cout << "_________________________________________________________________________________________________________\n";
	GoBackToMainMenu();
}

void PrintNewClientScreen() {
	if (!CheckAccessPermission(enUserPermissions::pAdd)) {
		PrintAccessDeclined();
		return;
	}
	system("cls");

	cout << "=========================================\n";
	cout << Tabs(2) << "Add New Clients Screen\n";
	cout << "=========================================\n";
	AddClients();

	GoBackToMainMenu();
}

void PrintDeleteClientScreen() {
	if (!CheckAccessPermission(enUserPermissions::pDelete)) {
		PrintAccessDeclined();
		return;
	}

	vector<stClients> vClients = LoadClientDataFromFile(ClientsFileName);
	system("cls");
	cout << "==============================================\n";
	cout << Tabs(2) << "Delete Client Screen\n";
	cout << "==============================================\n";
	DeleteClientByAccountNumber(vClients);

	GoBackToMainMenu();
}

void PrintUpdateClientScreen() {
	if (!CheckAccessPermission(enUserPermissions::pUpdate)) {
		PrintAccessDeclined();
	}
	vector<stClients> vClients = LoadClientDataFromFile(ClientsFileName);
	system("cls");
	cout << "==============================================\n";
	cout << Tabs(2) << "Update Client Screen\n";
	cout << "==============================================\n";
	UpdateClient(vClients);


	GoBackToMainMenu();
}

void PrintFindClientScreen() {
	if (!CheckAccessPermission(enUserPermissions::pFind)) {
		PrintAccessDeclined();
	}

	system("cls");
	vector<stClients> vClients = LoadClientDataFromFile(ClientsFileName);
	cout << "==============================================\n";
	cout << Tabs(2) << "Find Client Screen\n";
	cout << "==============================================\n";
	FindClient(vClients);

	GoBackToMainMenu();
}

void PrintTransactionsMenuScreen() {
	cout << "==============================================\n";
	cout << Tabs(1) << "  Transactions Menu Screen\n";
	cout << "==============================================\n";
	cout << Tabs(1) << "[1] Deposit. \n";
	cout << Tabs(1) << "[2] Withdraw. \n";
	cout << Tabs(1) << "[3] Total Balances. \n";
	cout << Tabs(1) << "[4] Main Menu. \n";
	cout << "==============================================" << endl;
}

void PrintDepositScreen() {
	system("cls");
	vector<stClients> vClients = LoadClientDataFromFile(ClientsFileName);
	cout << "==============================================\n";
	cout << Tabs(2) << "Find Client Screen\n";
	cout << "==============================================\n";
	AddDeposit(vClients);

	GoBackToTransactionMenu();
}

void PrintWithdrawScreen() {
	system("cls");
	vector<stClients> vClients = LoadClientDataFromFile(ClientsFileName);

	cout << "==============================================\n";
	cout << Tabs(2) << "Find Client Screen\n";
	cout << "==============================================\n";
	WithdrawDeposit(vClients);

	GoBackToTransactionMenu();
}

void PrintTotalBalancesScreen() {
	system("cls");
	vector<stClients> vClients = LoadClientDataFromFile(ClientsFileName);

	cout << Tabs(4) << "Client List (" << vClients.size() << ") Clients(s).\n";
	cout << "________________________________________________________________________________________________________\n\n";
	cout << "|=| " << setw(17) << left << "Account Number";
	cout << "|=| " << setw(40) << left << "Client Name";
	cout << "|=| " << setw(30) << left << "Balance";
	cout << "\n________________________________________________________________________________________________________\n\n";

	int TotalBalances = 0;

	if (vClients.size() == 0) {
		cout << Tabs(4) << "No Clients Available In the System!";
	}
	else {

		for (stClients& Client : vClients) {

			cout << "|=| " << setw(17) << left << Client.AccountNumber;
			cout << "|=| " << setw(40) << left << Client.Name;
			cout << "|=| " << setw(30) << left << Client.AccountBalance;
			cout << endl;
			TotalBalances += Client.AccountBalance;
		}
		cout << "\n";

	}
	cout << "_________________________________________________________________________________________________________\n\n\n";
	cout << Tabs(4) << "Total Balances = " << TotalBalances;
	GoBackToTransactionMenu();
}

void PrintManageUsersMenuScreen() {
	cout << "==============================================\n";
	cout << Tabs(1) << "  Manage Users Menu Screen\n";
	cout << "==============================================\n";
	cout << Tabs(1) << "[1] List Users. \n";
	cout << Tabs(1) << "[2] Add New User. \n";
	cout << Tabs(1) << "[3] Delete User. \n";
	cout << Tabs(1) << "[4] Update User. \n";
	cout << Tabs(1) << "[5] Find User. \n";
	cout << Tabs(1) << "[6] Main Menu. \n";
	cout << "==============================================" << endl;
}

void PrintUsersList(vector<stUsers> vUsers) {
	for (stUsers& U : vUsers) {
		cout << "|=| " << setw(17) << left << U.Username;
		cout << "|=| " << setw(15) << left << U.Password;
		cout << "|=| " << setw(26) << left << U.Permissions;
		cout << endl;
	}
}

void PrintUsersListScreen() {
	system("cls");
	vector<stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);
	cout << Tabs(4) << "Client List (" << vUsers.size() << ") Clients(s).\n";
	cout << "________________________________________________________________________________________________________\n\n";
	cout << "|=| " << setw(17) << left << "Username";
	cout << "|=| " << setw(15) << left << "Password";
	cout << "|=| " << setw(26) << left << "Permissions";
	cout << "\n________________________________________________________________________________________________________\n\n";
	PrintUsersList(vUsers);
	cout << endl;
	cout << "_________________________________________________________________________________________________________\n";
	GoBackToUserManageMenu();

}

void PrintAddUserScreen() {
	system("cls");
	vector<stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);
	cout << "==============================================\n";
	cout << Tabs(2) << "Add User Screen\n";
	cout << "==============================================\n";
	AddUsers(vUsers);
	GoBackToUserManageMenu();
}

void PrintDeleteUserScreen() {
	system("cls");
	vector<stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);
	cout << "==============================================\n";
	cout << Tabs(2) << "Delete User Screen\n";
	cout << "==============================================\n";
	DeleteUserByUsername(vUsers);
	GoBackToUserManageMenu();
}

void PrintUpdateUserScreen() {
	system("cls");
	vector<stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);
	cout << "==============================================\n";
	cout << Tabs(2) << "Update User Screen\n";
	cout << "==============================================\n";
	UpdateUsers(vUsers);
	GoBackToUserManageMenu();
}

void PrintFindUserScreen() {
	system("cls");
	vector<stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);
	cout << "==============================================\n";
	cout << Tabs(2) << "Find User Screen\n";
	cout << "==============================================\n";
	FindUser(vUsers);
	GoBackToUserManageMenu();
}

void PrintProgramEnd() {
	cout << "\n-----------------------------------\n";
	cout << "\tProgram Ends :-)";
	cout << "\n-----------------------------------\n";
}

void PrintAccessDeclined() {
	system("cls");
	cout << "==============================================\n";
	cout << Tabs(2) << "Access Declined,\n";
	cout << Tabs(2) << "You Dont Have Permissions To do this, \n";
	cout << Tabs(2) << "Please Contact your admin. \n";
	cout << "==============================================\n";
	GoBackToMainMenu();
}

void PrintLoginMenu() {
	cout << "==============================================\n";
	cout << Tabs(2) << "Login Screen\n";
	cout << "==============================================\n";
}

void ManageUsersMenuScreen() {
	bool PlayAgain = true;

	if (!CheckAccessPermission(enUserPermissions::pManageUsers)) {
		PrintAccessDeclined();
		return;
	}


	while (PlayAgain) {
		system("cls");
		PrintManageUsersMenuScreen();
		enUserManageOperation UOpType;
		UOpType = (enUserManageOperation)ReadNumberBetween("Choose what do you want to do? [1 to 6]? ", 1, 6);

		switch (UOpType) {

		case enUserManageOperation::euList: {
			PrintUsersListScreen();
			break;
		}

		case enUserManageOperation::euNew: {
			PrintAddUserScreen();
			break;
		}

		case enUserManageOperation::euDelete: {
			PrintDeleteUserScreen();
			break;
		}

		case enUserManageOperation::euUpdate: {
			PrintUpdateUserScreen();
			break;
		}

		case enUserManageOperation::euFind: {
			PrintFindUserScreen();
			break;
		}

		case enUserManageOperation::euMainMenu: {
			PlayAgain = false;
			break;
		}

		default: {
			PlayAgain = false;
		}

		}
	}
}

void TransactionsMenuScreen() {
	bool PlayAgain = true;

	if (!CheckAccessPermission(enUserPermissions::pTransactions)) {
		PrintAccessDeclined();
		return;
	}


	while (PlayAgain) {
		system("cls");
		PrintTransactionsMenuScreen();
		enTransactionOperation TrOpType;
		TrOpType = (enTransactionOperation)ReadNumberBetween("Choose what do you want to do? [1 to 4]? ", 1, 4);

		switch (TrOpType) {

		case enTransactionOperation::eDeposit: {
			PrintDepositScreen();
			break;
		}

		case enTransactionOperation::eWithdraw: {
			PrintWithdrawScreen();
			break;
		}

		case enTransactionOperation::eTotalBalances: {
			PrintTotalBalancesScreen();
			break;
		}

		case enTransactionOperation::eMainMenu: {
			PlayAgain = false;
			break;
		}

		default: {
			PlayAgain = false;
		}

		}
	}
}

void MainScreen() {
	bool PlayAgain = true;

	while (PlayAgain) {
		system("cls");
		PrintMainMenuScreen();
		enOperation OpType = (enOperation)ReadNumberBetween("Choose what do you want to do? [1 to 8]? ", 1, 8);
		switch (OpType) {

		case enOperation::eList: {
			PrintListScreen();
			break;
		}

		case enOperation::eNew: {
			PrintNewClientScreen();

			break;
		}

		case enOperation::eDelete: {
			PrintDeleteClientScreen();

			break;
		}

		case enOperation::eUpdate: {
			PrintUpdateClientScreen();

			break;
		}

		case enOperation::eFind: {
			PrintFindClientScreen();

			break;
		}

		case enOperation::eTransactions: {
			TransactionsMenuScreen();

			break;
		}

		case enOperation::eManageUsers: {
			ManageUsersMenuScreen();
			break;
		}

		case enOperation::eLogout: {
			PlayAgain = false;
			break;
		}

		default: {
			PlayAgain = false;
		}

		}
	}
}

void LoginScreen() {
	char PlayAgain = 'y';
	string Username;
	int Password;
	stUsers User;
	 bool isNotFound = false;
	vector<stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);
	while (tolower(PlayAgain) == 'y') {
		do {
			system("cls");
			PrintLoginMenu();

			if (isNotFound) {
				cout << "\nInvalid Username or Password!!" << endl;
			}

			cout << "\nEnter Username? ";
			cin >> Username;
			cout << "\nEnter Password? ";
			cin >> Password;

			isNotFound = SearchIfUsernameAndPasswordInFile(vUsers, Username, Password, CurrentUser);
		} while (!isNotFound);


		MainScreen();
	}
}

int main() {

	LoginScreen();


		return 0;
}
