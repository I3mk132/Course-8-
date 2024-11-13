/// ________________________ Project 2 ____________________________
// Subject : ATM System

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

enum enOperations {eQWithdraw = 1, eNWithdraw = 2, eDeposit = 3, eCheck = 4, eShowInfo = 5, eLogout = 6};
enum enEdit { eName = 1, eEmail = 2, ePhone = 3, eCountry = 4, eCity = 5, eStreet = 6, eApt = 7, ePinCode = 8, eExit = 9};

struct stClientInfo {
	string Name;
	string Phone;
	string Email;
	string Country;
	string City;
	string Street;
	int Apt;
};

struct stClient {
	string AccountNumber;
	int PinCode;
	double AccountBalance;
	stClientInfo Info;
	bool MarkForDelete = false;
	bool MarkForBlocked = false;
};

string ClientFileName = "Clients.txt";
stClient CurrentUser;

string Tabs(short Tab) {
	string T;
	for (short i = 0; i < Tab; i++) {
		T += "\t";
	}
	return T;
}
short ReadNumberBetween(string Message, short From, short To) {
	short Num;
	do {
		cout << Message;
		std::cin >> Num;

	} while (Num > To || Num < From);
	return Num;
}

vector<string> SplitString(string Sentence, string Delim) {
	vector<string> vString;
	string sWord = "";
	short Pos = 0;
	while ((Pos = Sentence.find(Delim)) != string::npos) {
		sWord = Sentence.substr(0, Pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		Sentence.erase(0, Pos + Delim.length());
	}
	if (sWord != "") {
		vString.push_back(Sentence);
	}
	return vString;
}
string ConvertRecordToLine(stClient Data, string Seperator) {
	string Sentence;
	Sentence += Data.AccountNumber + Seperator;
	Sentence += to_string(Data.PinCode) + Seperator;
	Sentence += to_string(Data.AccountBalance) + Seperator;
	Sentence += Data.Info.Name + Seperator;
	Sentence += Data.Info.Phone + Seperator;
	Sentence += Data.Info.Email + Seperator;
	Sentence += Data.Info.Country + Seperator;
	Sentence += Data.Info.City + Seperator;
	Sentence += Data.Info.Street + Seperator;
	Sentence += to_string(Data.Info.Apt) + Seperator;
	Sentence += (Data.MarkForBlocked)?"Blocked":"Active";
	return Sentence;
}
stClient ConvertLineToRecord(string Line, string Seperator) {
	vector<string> vString = SplitString(Line, Seperator);
	stClient Client;

	Client.AccountNumber = vString[0];
	Client.PinCode = stoi(vString[1]);
	Client.AccountBalance = stod(vString[2]);
	Client.Info.Name = vString[3];
	Client.Info.Phone = vString[4];
	Client.Info.Email = vString[5];
	Client.Info.Country = vString[6];
	Client.Info.City = vString[7];
	Client.Info.Street = vString[8];
	Client.Info.Apt = stoi(vString[9]);
	Client.MarkForBlocked = (vString[10] == "Blocked");

	return Client;
}
vector <stClient> LoadClientsDataFromFile(string FileName) {
	fstream MyClient;
	vector <stClient> vClient;
	string Line = "";
	stClient Client;

	MyClient.open(FileName, ios::in);

	if (MyClient.is_open()) {
		while (getline(MyClient, Line)) {
			Client = ConvertLineToRecord(Line, "#//#");
			vClient.push_back(Client);
		}
		MyClient.close();
	}
	return vClient;
}
void SaveClientsDataToFile(vector<stClient> vClient, string FileName) {
	fstream File;
	string Line;
	File.open(FileName, ios::out);

	if (File.is_open()) {
		for (stClient& C : vClient) {
			Line = ConvertRecordToLine(C, "#//#");
			File << Line << endl;
		}
		File.close();
	}

}
void UpdateClientInFile() {
	vector<stClient> vClients = LoadClientsDataFromFile(ClientFileName);

	for (stClient& C : vClients) {
		if (CurrentUser.AccountNumber == C.AccountNumber) {
			C = CurrentUser;
			break;
		}
	}

	SaveClientsDataToFile(vClients, ClientFileName);
}
void ChangePinCode() {
	int PinOld1;
	int Newpin1;
	int Newpin2;
	bool isWrong = false;

	cout << "Enter the Old Pin: ";
	cin >> PinOld1;
	if (PinOld1 == CurrentUser.PinCode) {
		do {
			if (isWrong) {
				cout << "\nPin Codes NOT match. ";
			}
			cout << "\nEnter the New Pin: ";
			cin >> Newpin1;
			cout << "Enter the New Pin Again: ";
			cin >> Newpin2;

			isWrong = !(Newpin1 == Newpin2);
		} while (isWrong);
		CurrentUser.PinCode = Newpin1;
	}
	else {
		cout << "\nWRONG PIN!!" << endl;
	}
}
void BlockUser(string AccountNumber){
	vector<stClient> vClients = LoadClientsDataFromFile(ClientFileName);
	for (stClient& C : vClients) {
		if (AccountNumber == C.AccountNumber) {
			C.MarkForBlocked = true;
			break;
		}
	}
	SaveClientsDataToFile(vClients, ClientFileName);
}


bool SearchIfAccountNumberAndPinCodeInFile(string AccountNumber, int PinCode, stClient& Client) {
	vector<stClient> vClients = LoadClientsDataFromFile(ClientFileName);

	for (stClient& C : vClients) {

		if (C.AccountNumber == AccountNumber && C.PinCode == PinCode) {
			Client = C;
			return true;
		}

	}
	return false;
}
bool isUserBlocked(string AccountNumber) {
	vector<stClient> vClients = LoadClientsDataFromFile(ClientFileName);
	for (stClient C : vClients) {
		if (AccountNumber == C.AccountNumber) {
			return (C.MarkForBlocked);
		}
	}
	return false;
}
bool isMultipeOfFive(short Num) {
	return (Num % 5 == 0);
}
bool ReadPin(string AccountNumber) {
	short Counter = 3;
	int PinCode;

	if (isUserBlocked(AccountNumber)) {
		cout << "Your account is BLOCKED. " << endl;
		return false;
	}

	cout << "\nEnter PinCode (" << Counter << ")? ";
	cin >> PinCode;
	bool isWrong = !SearchIfAccountNumberAndPinCodeInFile(AccountNumber, PinCode, CurrentUser);


	while (isWrong) {
		cout << "\nWrong Pin, Enter PinCode (" << --Counter << ")? ";
		cin >> PinCode;

		isWrong = !SearchIfAccountNumberAndPinCodeInFile(AccountNumber, PinCode, CurrentUser);
		if (Counter == 1 && isWrong) {
			BlockUser(AccountNumber);
			UpdateClientInFile();
			cout << "\nUser Blocked : " << AccountNumber << endl;
			return false;
		}

	}
	return true;
}
void GoBackToMainMenu() {
	cout << "\n\n\nPress any key to go back to Main Menu...";
	system("pause > 0");
}

void PrintClinetInfo() {
	cout << "==============( Client : " << CurrentUser.AccountNumber << " )=================\n";
	cout << "================================================\n";
	cout << Tabs(1) << "[1] Name: {" << CurrentUser.Info.Name << "}\n";
	cout << Tabs(1) << "[2] Email: {" << CurrentUser.Info.Email << "}\n";
	cout << Tabs(1) << "[3] Phone: {" << CurrentUser.Info.Phone << "}\n";
	cout << Tabs(1) << "[4] Country: {" << CurrentUser.Info.Country << "}\n";
	cout << Tabs(1) << "[5] City: {" << CurrentUser.Info.City << "}\n";
	cout << Tabs(1) << "[6] Street: {" << CurrentUser.Info.Street << "}\n";
	cout << Tabs(1) << "[7] Apt: {" << CurrentUser.Info.Apt << "}\n";
	cout << Tabs(1) << "[8] PinCode: {****}\n";
	cout << Tabs(1) << "[9] Exit. \n";
	cout << "================================================\n";
}
void PrintQuickWithdrawScreen() {

	cout << "=======================================\n";
	cout << Tabs(2) << "Quick Withdraw Screen\n";
	cout << "=======================================\n";
	cout << Tabs(1) << "[1] 20       [2] 50\n";
	cout << Tabs(1) << "[3] 100      [4] 200\n";
	cout << Tabs(1) << "[5] 400      [6] 600\n";
	cout << Tabs(1) << "[7] 800      [8] 1000\n";
	cout << Tabs(1) << "[9] Exit\n";
	cout << "=======================================\n";

}
void PrintNormalWithdrawScreen() {

	cout << "=======================================\n";
	cout << Tabs(2) << "Normal Withdraw Screen\n";
	cout << "=======================================\n";

}
void PrintDepositScreen() {

	cout << "=======================================\n";
	cout << Tabs(2) << "Deposit Screen\n";
	cout << "=======================================\n";

}
void PrintCheckBalanceScreen() {

	cout << "=======================================\n";
	cout << Tabs(2) << "Check Balance\n";
	cout << "=======================================\n";

}
void PrintMainMenuScreen() {
	cout << "===========================================================\n";
	cout << Tabs(3) << "ATM Main Menu Screen\n";
	cout << "===========================================================\n";
	cout << Tabs(2) << "[1] Quick Withdraw. \n";
	cout << Tabs(2) << "[2] Normal Withdraw. \n";
	cout << Tabs(2) << "[3] Deposit. \n";
	cout << Tabs(2) << "[4] Check Balance. \n";
	cout << Tabs(2) << "[5] Show Informations. \n";
	cout << Tabs(2) << "[6] Logout. \n";
	cout << "============================================================\n";
}
void PrintLoginScreen() {
	cout << "=======================================\n";
	cout << Tabs(2) << "Login Screen\n";
	cout << "=======================================\n";
}


void QuickWithdraw() {
	PrintQuickWithdrawScreen();

	cout << "Your Balance is :" << CurrentUser.AccountBalance << endl;
	short WithdrawCount = ReadNumberBetween("Choose what to withdraw from [1] to [9]? ", 1, 9);

	if (WithdrawCount == 9) {
		return;
	}

	char Sure = 'n';
	cout << "\n\nAre you sure you want perfrom this transactions? y/n? ";
	std::cin >> Sure;

	if (tolower(Sure) == 'y') {
		short arr[] = { 20, 50, 100, 200, 400, 600, 800, 1000 };
		short Withdraw = arr[WithdrawCount - 1];

		if (Withdraw > CurrentUser.AccountBalance) {
			cout << "\nThe amount exceeds your balance, make another choice. " << endl;
			cout << "Press Anykey To Continue...";
			system("pause > 0");
		}
		else {
			::CurrentUser.AccountBalance -= Withdraw;
			cout << "\nDone Successfully. new balance is: " << CurrentUser.AccountBalance << endl;
		}
	}

	GoBackToMainMenu();
}
void NormalWithdraw() {
	char PlayAgain = 'y';
	short Num;
	while (tolower(PlayAgain) == 'y') {
		PrintNormalWithdrawScreen();
		do {
			cout << "\nEnter an amount multiple of 5's ? ";
			std::cin >> Num;

		} while (!isMultipeOfFive(Num));

		char Sure = 'n';
		cout << "\n\nAre You Sure you want perform this transaction? y/n? ";
		std::cin >> Sure;

		if (Num > CurrentUser.AccountBalance) {
			cout << "\nThe amount exceeds your balance, make another choice. " << endl;
			cout << "Press Anykey To Continue...";
			system("pause > 0");
		}
		else {
			::CurrentUser.AccountBalance -= Num;

			cout << "\n\nDone Successfully. New balance is: " << CurrentUser.AccountBalance << endl;
			PlayAgain = 'n';
		}
	}
	GoBackToMainMenu();
}
void Deposit() {
	short Num;

	PrintDepositScreen();
	cout << "\nEnter a deposit Amount? ";
	cin >> Num;

	char Sure = 'n';
	cout << "\n\nAre You Sure you want perform this transaction? y/n? ";
	std::cin >> Sure;
	if (tolower(Sure) == 'y') {
		::CurrentUser.AccountBalance += Num;

		cout << "\n\nDone Successfully. New balance is: " << CurrentUser.AccountBalance << endl;
	}
	GoBackToMainMenu();
}
void CheckBalance() {
	PrintCheckBalanceScreen();
	cout << "Your Balance is : " << CurrentUser.AccountBalance << endl;

	GoBackToMainMenu();
}
bool EditClient(enEdit Op) {
	switch (Op) {
		case enEdit::eName: {
			cout << "\nEnter a New Name: ";
			cin >> CurrentUser.Info.Name;
			break;
		}
		case enEdit::eEmail: {
			cout << "\nEnter a New Email: ";
			cin >> CurrentUser.Info.Email;
			break;
		}
		case enEdit::ePhone: {
			cout << "\nEnter a New Phone: ";
			cin >> CurrentUser.Info.Phone;
			break;
		}
		case enEdit::eCountry: {
			cout << "\nEnter a New Country: ";
			cin >> CurrentUser.Info.Country;
			break;
		}
		case enEdit::eCity: {
			cout << "\nEnter a New City: ";
			cin >> CurrentUser.Info.City;
			break;
		}
		case enEdit::eStreet: {
			cout << "\nEnter a New Street: ";
			cin >> CurrentUser.Info.Street;
			break;
		}
		case enEdit::eApt: {
			cout << "\nEnter a New Apt: ";
			cin >> CurrentUser.Info.Apt;
			break;
		}
		case enEdit::ePinCode: {
			ChangePinCode();
			break;
		}
		case enEdit::eExit: {
			return false;
		}
	}
	return true;
}
void ShowInfo() {

	while (true) {
		system("cls");
		PrintClinetInfo();

		if(!EditClient((enEdit)ReadNumberBetween("Enter Number Between [1 to 9]? ", 1, 9))) {
			break;
		}

	}

}


void MainMenuOptions() {
	char PlayAgain = 'y';
	while (tolower(PlayAgain) == 'y') {
		system("cls");
		PrintMainMenuScreen();
		enOperations Op = (enOperations)ReadNumberBetween("Enter Number Between [1 to 6]? ", 1, 6);
		switch (Op) {
			case enOperations::eQWithdraw: {
				QuickWithdraw();
				break;
			}
			case enOperations::eNWithdraw: {
				NormalWithdraw();
				break;
			}
			case enOperations::eDeposit: {
				Deposit();
				break;
			}
			case enOperations::eCheck: {
				CheckBalance();
				break;
			}
			case enOperations::eShowInfo: {
				ShowInfo();
				break;
			}
			case enOperations::eLogout: {
				PlayAgain = 'n';
				break;
			}
		}

	}
}
void Login() {

	string AccountNumber;

	while (true) {
		bool isWrong = false;


		do {
			system("cls");
			PrintLoginScreen();
			cout << "(Enter 0 to Quit)" << endl;

			if (isWrong) {
				cout << "\nInvalid AccountNumber/PinCode!!, ";
			}

			cout << "\n\nEnter Account Number? ";
			cin >> AccountNumber;

			if (AccountNumber == "0") {
				break;
			}


			isWrong = !ReadPin(AccountNumber);

		} while (isWrong);

		if (AccountNumber == "0") {
			break;
		}

		MainMenuOptions();
		UpdateClientInFile();
	}

}

int main() {
	Login();

	return 0;
}



/// ======================================= Course 8 Done ================================================
/// ==================================== 65 Problem Solved ===============================================
