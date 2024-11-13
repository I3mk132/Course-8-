/// ===================== ( Algorithms & Problem Solving  #04) =============================
// =========================================================================================


/// Problem #01 ( Number to Text )
// Write a program to read a number and print the text of that number
/*
#include <iostream>
#include <string>


using namespace std;

long long ReadPositiveNumber(string Message) {
	long long Num;
	do {
		cout << Message << endl;
		cin >> Num;
	} while (Num <= 0);
	return Num;
}

string NumberToText(long Number) {
	string Sentence = "";

	string OneToNineteen[] = {
		"Zero", "One", "Two", "Three", "Four",
		"Five", "Six", "Seven", "Eight", "Nine",
		"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
		"Fifteen", "Sixteen", "Seventeen", "Eihgteen", "Nineteen"
	};
	string Tens[] = {
		"", "", "Twenty", "Thirty", "Forty",
		"Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
	};

	if (Number == 0) {
		return Sentence;
	}

	if (Number >= 1 && Number <= 19) {
		return OneToNineteen[Number] + " ";
	}

	if (Number >= 20 && Number <= 99) {
		return Tens[Number / 10] + " " + NumberToText(Number % 10);
	}

	if (Number >= 100 && Number <= 199) {
		return "Hundred " + NumberToText(Number % 100);
	}

	if (Number >= 200 && Number <= 999) {
		return OneToNineteen[Number / 100] + " Hundred " + NumberToText(Number % 100);
	}

	if (Number >= 1000 && Number <= 1999) {
		return "Thousand " + NumberToText(Number % 1000);
	}

	if (Number >= 2000 && Number <= 999999) {
		return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
	}

	if (Number >= 1000000 && Number <= 1999999) {
		return "Million " + NumberToText(Number % 1000000);
	}

	if (Number >= 2000000 && Number <= 999999999) {
		return NumberToText(Number / 1000000) + "Million " + NumberToText(Number % 1000000);
	}

	if (Number >= 1000000000 && Number <= 1999999999) {
		return "Billion " + NumberToText(Number % 1000000000);
	}
	else {
		return NumberToText(Number / 1000000000) + "Billion " + NumberToText(Number % 1000000000);
	}

}

int main() {
	long long Number = ReadPositiveNumber("Enter a Number? ");
	cout << NumberToText(Number);

	system("pause > 0");
	return 0;
}
*/



/// Problem #02 ( Leap Year )
// Write a Program to check if year is a leap year or not.
/*
#include <iostream>
using namespace std;

short ReadNumber(string Message) {
	short Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

bool isLeapYear(short Year) {

	// leap year if perfectly divisible by 400
	if (Year % 100 == 0) {
		return false;
	}

	// not a leap year if divisible by 100
	// but not divisible by 400
	else if (Year % 100 == 0) {
		return true;
	}

	// leap year if not divisible y 100
	// ut divisible by 4
	else if (Year % 4 == 0) {
		return true;
	}

	// all other years are not leap years
	else {
		return false;
	}
}

int main() {
	short Year = ReadNumber("Please enter a Number : ");

	if (isLeapYear(Year)) {
		cout << "\nYes, Year [" << Year << "] is a leap year. \n";
	}
	else {
		cout << "\nNo, Year [" << Year << "] is NOT a leap year. \n";
	}
	system("pause > 0");
	return 0;
}
*/



/// Problem #03 ( Leap Year (One Line Of Code) )
// Write a program to check if year is a leap year or not.
/*
#include <iostream>
using namespace std;

bool isLeepYear(short Number) {
	return ((Number % 400 == 0) || (Number % 4 == 0 && Number % 100 != 0));
}

short ReadNumber(string Message) {
	short Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

int main() {
	short Year = ReadNumber("Enter a Number : ");
	if (isLeepYear(Year)) {
		cout << "Yes, [" << Year << "] is a leap year. " << endl;
	}
	else {
		cout << "No, [" << Year << "] is NOT a leap year. " << endl;
	}
	system("pause > 0");
	return 0;
}
*/



/// Problem 04 ( Number of Days-Hours-Minutes-Seconds In a year )
// Write a program to print Number of:
/*
#include <iostream>
using namespace std;

short ReadNumber(string Message) {
	short N;
	cout << Message << endl;
	cin >> N;
	return N;
}

bool isLeapYear(short Year) {
	return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
}

int NumberOfDaysInYear(short Year) {
	return (isLeapYear(Year)) ? 365 : 366;
}

int NumberOfHoursInYear(short Year) {
	return NumberOfDaysInYear(Year) * 24;
}

int NumberOfMinutesInYear(short Year) {
	return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondsInYear(short Year) {
	return NumberOfMinutesInYear(Year) * 60;
}

int main() {
	short Year = ReadNumber("Please enter a year to check? ");

	cout << "\nNumber of Days    in Year [" << Year << "] is " << NumberOfDaysInYear(Year);
	cout << "\nNumber of Hours   in Year [" << Year << "] is " << NumberOfHoursInYear(Year);
	cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMinutesInYear(Year);
	cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfSecondsInYear(Year);
	cout << "\n\n";

	system("pause > 0");
	return 0;
}
*/



/// Problem #05 ( Number of Days-Hours-Minutes-Seconds In a Month )
// Write a program to print Number of:
/*
#include <iostream>
using namespace std;

short ReadNumber(string Message) {
	short N;
	cout << Message;
	cin >> N;
	return N;
}

bool isLeapYear(short Year) {
	return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
}

int NumberOfDaysInMonth(short Month, short Year) {

	if (Month > 12 || Month < 1) {
		return 0;
	}

	if (Month == 2) {
		return (isLeapYear(Year) ? 29 : 28);
	}

	short arr31[7] = {1, 3, 5, 7, 8, 10, 12};
	for (short i = 0; i < 7; i++) {
		if (Month == arr31[i]) {
			return 31;
		}
	}

	return 30;
}

int NumberOfHoursInMonth(short Month, short Year) {
	return NumberOfDaysInMonth(Month, Year) * 24;
}

int NumberOfMinutesInMonth(short Month, short Year) {
	return NumberOfHoursInMonth(Month, Year) * 60;
}

int NumberOfSecondsInMonth(short Month, short Year) {
	return NumberOfMinutesInMonth(Month, Year) * 60;
}

int main() {
	short Year = ReadNumber("Please enter a year to check? ");
	cout << "\n";
	short Month = ReadNumber("Pleasee enter a Month to check? ");

	cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInMonth(Month, Year);
	cout << "\nNumber of Hours   in Month [" << Month << "] is " << NumberOfHoursInMonth(Month, Year);
	cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutesInMonth(Month, Year);
	cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSecondsInMonth(Month, Year);
	cout << endl;
	system("pause > 0");
	return 0;

}
*/



/// Problem #06 ( Number of Days In a Month Short Logic )
// Write a program to print Number of Days in a certain Month.
/*
#include <iostream>
using namespace std;

short ReadNumber(string Message) {
	short N;
	cout << Message;
	cin >> N;
	return N;
}

bool isLeapYear(short Year) {
	return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
}

int NumberOfDaysInMonth(short Month, short Year) {

	if (Month > 12 || Month < 1) {
		return 0;
	}

	short arrDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return (Month == 2 ? (isLeapYear(Year) ? 29 : 28) : arrDays[Month - 1]);
}

int NumberOfHoursInMonth(short Month, short Year) {
	return NumberOfDaysInMonth(Month, Year) * 24;
}

int NumberOfMinutesInMonth(short Month, short Year) {
	return NumberOfHoursInMonth(Month, Year) * 60;
}

int NumberOfSecondsInMonth(short Month, short Year) {
	return NumberOfMinutesInMonth(Month, Year) * 60;
}

int main() {
	short Year = ReadNumber("Please enter a year to check? ");
	cout << "\n";
	short Month = ReadNumber("Pleasee enter a Month to check? ");

	cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInMonth(Month, Year);
	cout << "\nNumber of Hours   in Month [" << Month << "] is " << NumberOfHoursInMonth(Month, Year);
	cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutesInMonth(Month, Year);
	cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSecondsInMonth(Month, Year);
	cout << endl;
	system("pause > 0");
	return 0;

}
*/




/// Problem #7 ( Day Name )
// Write a proggram to read a date, and print the day name of week.
/*
#include <iostream>
using namespace std;

short ReadNumber(string Message) {
	short N;
	cout << Message;
	cin >> N;
	return N;
}

string GetDayName(int Number) {
	string arr[] = {
		"Sunday", "Monday", "tuesday",
		"wednesday", "thursday", "Friday",
		"Saturday"
	};
	return arr[Number];
}

short DayOrder(int Year, int Month, int Day) {
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + 12 * a - 2;

	int d;
	d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

int main() {
	short Year = ReadNumber("Please enter a year? ");
	cout << "\n";
	short Month = ReadNumber("Please enter a Month? ");
	cout << "\n";
	short Day = ReadNumber("Please enter a Day? ");
	cout << "\n";

	short DayNum = DayOrder(Year, Month, Day);

	cout << "Date      : " << Day << "/" << Month << "/" << Year << "\n";
	cout << "Day Order : " << DayNum << "\n";
	cout << "Day Name  : " << GetDayName(DayNum) << "\n";

	system("pause > 0");
	return 0;
}
*/



/// Problem #08 ( Month Calendar )
// Write a program to print Month Calendar.
/*
#include <iostream>
#include <iomanip>
using namespace std;

short ReadNumber(string Message) {
	short Num;
	cout << Message;
	cin >> Num;
	return Num;
}

string GetMonthShortName(int Number) {
	string arr[] = {
		"Jan", "Feb", "Mar", "Apr",
		"May", "Jun", "Jul", "Aug",
		"Sep", "Oct", "Nov", "Dec"
	};
	return arr[Number-1];
}

short DayOrder(int Year, int Month, int Day) {
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + 12 * a - 2;

	int d;
	d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

bool isLeapYear(short Year) {
	return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
}

short GetDaysInMonth(short Month, short Year) {
	if (Month > 12 || Month < 1) {
		return 0;
	}

	short arrDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (Month == 2 ? (isLeapYear(Year) ? 29 : 28) : arrDays[Month - 1]);
}

void PrintDays(short Year, short Month) {
	//short ReadDay = DayOrder(Year, Month, 1);

	//short Day = 1;
	//for (short Row = 0; Row < 5; Row++) {

	//	for (short Col = 0; Col < 7; Col++) {
	//		if (Row == 0 && Col < ReadDay) {
	//			cout << setw(5) << "";
	//		}
	//		else {
	//			if (Day > GetDaysInMonth(Month, Year)) {
	//				break;
	//			}
	//			cout << setw(5) << Day++;
	//		}
	//	}
	//	cout << endl;
	//}

	int NumberOfDays = GetDaysInMonth(Month, Year);
	int ThisMonth = DayOrder(Year, Month, 1);

	int i;
	for (i = 0; i < ThisMonth; i++) {
		cout << setw(5) << "";
	}

	for (short j = 0; j < NumberOfDays; j++) {
		cout << setw(5) << j + 1;

		if (++i == 7) {
			i = 0;
			cout << "\n";
		}
	}
}

void PrintCalender(short Year, short Month) {
	cout << "________________" << GetMonthShortName(Month) << "__________________\n\n";
	cout << setw(5) << "Sun";
	cout << setw(5) << "Mon";
	cout << setw(5) << "Tue";
	cout << setw(5) << "Wed";
	cout << setw(5) << "Thu";
	cout << setw(5) << "Fri";
	cout << setw(5) << "Sat";
	cout << "\n";

	PrintDays(Year, Month);

	cout << "\n_____________________________________\n\n";
}

int main() {
	short Year = ReadNumber("Please enter a year? ");
	cout << "\n";
	short Month = ReadNumber("Please enter a Month? ");
	cout << "\n";

	PrintCalender(Year, Month);

	system("pause > 0");
	return 0;
}
*/



/// Problem #09 ( Year Clendar )
// Write a program to print Year Calendar.
/*
#include <iostream>
#include <iomanip>
using namespace std;

short ReadNumber(string Message) {
	short Num;
	cout << Message;
	cin >> Num;
	return Num;
}

string GetMonthShortName(int Number) {
	string arr[] = {
		"Jan", "Feb", "Mar", "Apr",
		"May", "Jun", "Jul", "Aug",
		"Sep", "Oct", "Nov", "Dec"
	};
	return arr[Number - 1];
}

short DayOrder(int Year, int Month, int Day) {
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + 12 * a - 2;

	int d;
	d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

bool isLeapYear(short Year) {
	return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
}

short GetDaysInMonth(short Month, short Year) {
	if (Month > 12 || Month < 1) {
		return 0;
	}

	short arrDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (Month == 2 ? (isLeapYear(Year) ? 29 : 28) : arrDays[Month - 1]);
}

void PrintDays(short Year, short Month) {
	//short ReadDay = DayOrder(Year, Month, 1);

	//short Day = 1;
	//for (short Row = 0; Row < 5; Row++) {

	//	for (short Col = 0; Col < 7; Col++) {
	//		if (Row == 0 && Col < ReadDay) {
	//			cout << setw(5) << "";
	//		}
	//		else {
	//			if (Day > GetDaysInMonth(Month, Year)) {
	//				break;
	//			}
	//			cout << setw(5) << Day++;
	//		}
	//	}
	//	cout << endl;
	//}

	int NumberOfDays = GetDaysInMonth(Month, Year);
	int ThisMonth = DayOrder(Year, Month, 1);

	int i;
	for (i = 0; i < ThisMonth; i++) {
		cout << setw(5) << "";
	}

	for (short j = 0; j < NumberOfDays; j++) {
		cout << setw(5) << j + 1;

		if (++i == 7) {
			i = 0;
			cout << "\n";
		}
	}
}

void PrintCalender(short Year) {

	cout << "\n_____________________________________\n\n";
	cout << "           Calender - " << Year << "\n";
	cout << "_____________________________________\n\n";

	for (short i = 1; i <= 12; i++) {
		cout << "________________" << GetMonthShortName(i) << "__________________\n\n";
		cout << setw(5) << "Sun";
		cout << setw(5) << "Mon";
		cout << setw(5) << "Tue";
		cout << setw(5) << "Wed";
		cout << setw(5) << "Thu";
		cout << setw(5) << "Fri";
		cout << setw(5) << "Sat";
		cout << "\n";

		PrintDays(Year, i);

		cout << "\n_____________________________________\n\n";
	}
}

int main() {
	short Year = ReadNumber("Please enter a year? ");
	cout << "\n";

	PrintCalender(Year);

	system("pause > 0");
	return 0;
}
*/



/// Problem #10 ( Days from the beginning of year )
// Write a program to print total days from the beginning of year.
/*
#include <iostream>
#include <iomanip>
using namespace std;

short ReadNumberBetween(string Message, short From = 0, short To = 0) {
	short Num;
	do {
		cout << Message;
		cin >> Num;

	} while (!((Num <= To && Num >= From) || From == 0));
	return Num;
}

bool isLeapYear(short Year) {
	return (Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0));
}

short GetDaysCountInMonth(short Year, short Month) {
	short arr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return isLeapYear(Year) && Month == 2 ? 29 : arr[Month - 1];
}

short GetTodayCount(short Year, short Month, short Day) {
	short Counter = 0;
	for (short i = 1; i <= Month - 1; i++) {
		Counter += GetDaysCountInMonth(Year, i);
	}
	return Counter + Day;
}

int main() {
	short Day = ReadNumberBetween("\nPlease enter a day? ", 1, 31);
	short Month = ReadNumberBetween("\nPlease enter a Month? ", 1, 12);
	short Year = ReadNumberBetween("\nPlease enter a Year? ");

	cout << "\nNumber of days from the begining of the year is : ";
	cout << GetTodayCount(Year, Month, Day) << endl;

	system("pause > 0");
	return 0;
}
*/



/// Problem #11 ( Daye from Day Order In a year )
// Write a program to print total days from the beginning of year,
// then Take the total days and convert them back to date.
/*
#include <iostream>
#include <iomanip>
using namespace std;

struct stDate {
	short Day;
	short Month;
	short Year;
};

short ReadNumberBetween(string Message, short From = 0, short To = 0) {
	short Num;
	do {
		cout << Message;
		cin >> Num;

	} while (!((Num <= To && Num >= From) || From == 0));
	return Num;
}

bool isLeapYear(short Year) {
	return (Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0));
}

short GetDaysCountInMonth(short Year, short Month) {
	short arr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return isLeapYear(Year) && Month == 2 ? 29 : arr[Month - 1];
}

short GetTodayCount(short Year, short Month, short Day) {
	short Counter = 0;
	for (short i = 1; i <= Month - 1; i++) {
		Counter += GetDaysCountInMonth(Year, i);
	}
	return Counter + Day;
}

stDate GetTodaysDate(short Year, short Days) {
	stDate Date;
	short DayCount;
	short ThisMonth = 1;
	while (Days >= (DayCount = GetDaysCountInMonth(Year, ThisMonth))) {
		Days -= DayCount;
		ThisMonth++;
	}
	Date.Day = Days;
	Date.Month = ThisMonth;
	Date.Year = Year;
	return Date;
}

int main() {
	short Day = ReadNumberBetween("\nPlease enter a day? ", 1, 31);
	short Month = ReadNumberBetween("\nPlease enter a Month? ", 1, 12);
	short Year = ReadNumberBetween("\nPlease enter a Year? ");

	short TodaysCount = GetTodayCount(Year, Month, Day);

	cout << "\nNumber of days from the begining of the year is : ";
	cout << TodaysCount << endl;

	stDate Date = GetTodaysDate(Year, TodaysCount);
	cout << "\nDate for [" << TodaysCount << "] is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	system("pause > 0");
	return 0;
}
*/



/// Problem #12 ( Add Days to Date )
// Write a program to read date and read how many days to add to it.
// print the results on screen
/*
#include <iostream>
#include <iomanip>
using namespace std;

struct stDate {
	short Day;
	short Month;
	short Year;
};

short ReadNumberBetween(string Message, short From = 0, short To = 0) {
	short Num;
	do {
		cout << Message;
		cin >> Num;

	} while (!((Num <= To && Num >= From) || From == 0));
	return Num;
}

stDate ReadDate() {
	stDate Date;
	Date.Day = ReadNumberBetween("\nPlease enter a day? ", 1, 31);
	Date.Month = ReadNumberBetween("\nPlease enter a Month? ", 1, 12);
	Date.Year = ReadNumberBetween("\nPlease enter a Year? ");
	return Date;
}

bool isLeapYear(short Year) {
	return (Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0));
}

short GetDaysCountInMonth(short Year, short Month) {
	short arr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return isLeapYear(Year) && Month == 2 ? 29 : arr[Month - 1];
}

short GetTodayCount(short Year, short Month, short Day) {
	short Counter = 0;
	for (short i = 1; i <= Month - 1; i++) {
		Counter += GetDaysCountInMonth(Year, i);
	}
	return Counter + Day;
}

stDate GetTodaysDate(short Year, short Days) {
	stDate Date;
	short DayCount;
	short ThisMonth = 1;
	while (Days >= (DayCount = GetDaysCountInMonth(Year, ThisMonth))) {
		Days -= DayCount;
		ThisMonth++;
		if (ThisMonth == 13) {
			Year++;
			ThisMonth = 1;
		}
	}
	Date.Day = Days;
	Date.Month = ThisMonth;
	Date.Year = Year;
	return Date;
}

int main() {
	stDate Date = ReadDate();
	short Add = ReadNumberBetween("\nHow many days to add? ");
	short TodaysCount = GetTodayCount(Date.Year, Date.Month, Date.Day) + Add;

	Date = GetTodaysDate(Date.Year, TodaysCount);
	cout << "\nDate after adding [" << Add << "] is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


	system("pause > 0");
	return 0;
}
*/


/// Problem #13 (Date1 Less than Date2)
// Write a program to read date1, date2 and check if Date1 is Less than Date2
/*
#include <iostream>
#include <iomanip>
using namespace std;

struct stDate {
	short Day;
	short Month;
	short Year;
};

short ReadNumberBetween(string Message, short From = 0, short To = 0) {
	short Num;
	do {
		cout << Message;
		cin >> Num;

	} while (!((Num <= To && Num >= From) || From == 0));
	return Num;
}

stDate ReadDate() {
	stDate Date;
	Date.Day = ReadNumberBetween("\nPlease enter a day? ", 1, 31);
	Date.Month = ReadNumberBetween("\nPlease enter a Month? ", 1, 12);
	Date.Year = ReadNumberBetween("\nPlease enter a Year? ");
	return Date;
}

bool isLeapYear(short Year) {
	return (Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0));
}

short GetDaysCountInMonth(short Year, short Month) {
	short arr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return isLeapYear(Year) && Month == 2 ? 29 : arr[Month - 1];
}

short GetTodayCount(short Year, short Month, short Day) {
	short Counter = 0;
	for (short i = 1; i <= Month - 1; i++) {
		Counter += GetDaysCountInMonth(Year, i);

	}
	return Counter + Day;
}

bool isDate1LongerThenDate2(stDate Date1, stDate Date2) {

	if (Date1.Year > Date2.Year) {
		return true;
	}
	else if (Date1.Year == Date2.Year) {

		if (Date1.Month > Date2.Month) {
			return true;
		}
		else if (Date1.Month == Date2.Year){

			if (Date1.Day > Date2.Day) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	stDate Date1, Date2;
	Date1 = ReadDate();
	cout << "\n";
	Date2 = ReadDate();

	if (isDate1LongerThenDate2(Date1, Date2)) {
		cout << "Date 1 is longer then Date 2 " << endl;
	}
	else {
		cout << "Date 1 is NOT longer then Date 2" << endl;
	}

	return 0;
}
*/



/// Problem #14 ( Date1 Equals to Date2 )
// Write a program to read date1, date2 and check if Datel Equals to Date2
/*
#include <iostream>
#include <iomanip>
using namespace std;

struct stDate {
	short Day;
	short Month;
	short Year;
};

short ReadNumberBetween(string Message, short From = 0, short To = 0) {
	short Num;
	do {
		cout << Message;
		cin >> Num;

	} while (!((Num <= To && Num >= From) || From == 0));
	return Num;
}

stDate ReadDate() {
	stDate Date;
	Date.Day = ReadNumberBetween("\nPlease enter a day? ", 1, 31);
	Date.Month = ReadNumberBetween("\nPlease enter a Month? ", 1, 12);
	Date.Year = ReadNumberBetween("\nPlease enter a Year? ");
	return Date;
}

bool isLeapYear(short Year) {
	return (Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0));
}

short GetDaysCountInMonth(short Year, short Month) {
	short arr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return isLeapYear(Year) && Month == 2 ? 29 : arr[Month - 1];
}

short GetTodayCount(short Year, short Month, short Day) {
	short Counter = 0;
	for (short i = 1; i <= Month - 1; i++) {
		Counter += GetDaysCountInMonth(Year, i);

	}
	return Counter + Day;
}

bool isDate1EqualDate2(stDate Date1, stDate Date2) {
	return Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day;
}

int main() {
	stDate Date1, Date2;
	Date1 = ReadDate();
	cout << "\n";
	Date2 = ReadDate();

	if (isDate1EqualDate2(Date1, Date2)) {
		cout << "Date 1 is Equal Date 2 " << endl;
	}
	else {
		cout << "Date 1 is NOT Equal Date 2" << endl;
	}

	return 0;
}
*/



/// Problem #15 ( Last Day, Last Month )
// Write a program to read date and check:
// - if it is last Day in Month
// - if it is last Month in year
/*
#include <iostream>
#include <iomanip>
using namespace std;

struct stDate {
	short Day;
	short Month;
	short Year;
};

short ReadNumberBetween(string Message, short From = -32000, short To = 32000) {
	short Num;
	do {
		cout << Message;
		cin >> Num;

	} while (!((Num <= To && Num >= From)));

	return Num;
}

stDate ReadDate() {
	stDate Date;
	Date.Day = ReadNumberBetween("\nPlease enter a day? ", 1, 31);
	Date.Month = ReadNumberBetween("\nPlease enter a Month? ", 1, 12);
	Date.Year = ReadNumberBetween("\nPlease enter a Year? ");
	return Date;
}

bool isLeapYear(short Year) {
	return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
}

short GetMonthDayCount(short Year, short Month) {
	short arr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (isLeapYear(Year) && Month == 2) ? 29 : arr[Month - 1];
}

bool isLastDayInMonth(short Year, short Month, short Day) {
	return (GetMonthDayCount(Year, Month) == Day);
}

bool isLastMonthInYear(short Month) {
	return Month == 12;
}

int main() {
	stDate Date = ReadDate();

	(isLastDayInMonth(Date.Year, Date.Month, Date.Day)) ? cout << "\nYes, Day is Last Day in Month. " : cout << "\nNo, Day is Not Last Day in Month";
	cout << endl;
	(isLastMonthInYear(Date.Month)) ? cout << "Yes, Month is Last Month in Year. " : cout << "No, Month is Not Last Month in Year. ";
	cout << endl;
	return 0;
}
*/

/// Problem #16 ( Increase Date by One day )
// Write a program to read a date and make a function to incresae date by one
/*
#include <iostream>
#include <iomanip>
using namespace std;

struct stDate {
	short Day;
	short Month;
	short Year;
};

short ReadNumberBetween(string Message, short From = -32000, short To = 32000) {
	short Num;
	do {
		cout << Message;
		cin >> Num;

	} while (!((Num <= To && Num >= From)));

	return Num;
}

stDate ReadDate() {
	stDate Date;
	Date.Day = ReadNumberBetween("\nPlease enter a day? ", 1, 31);
	Date.Month = ReadNumberBetween("\nPlease enter a Month? ", 1, 12);
	Date.Year = ReadNumberBetween("\nPlease enter a Year? ");
	return Date;
}

bool isLeapYear(short Year) {
	return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
}

short GetMonthDayCount(short Year, short Month) {
	short arr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (isLeapYear(Year) && Month == 2) ? 29 : arr[Month - 1];
}

bool isLastDayInMonth(short Year, short Month, short Day) {
	return (GetMonthDayCount(Year, Month) == Day);
}

bool isLastMonthInYear(short Month) {
	return Month == 12;
}

void IncreaseDateByOne(stDate& Date) {
	if (isLastDayInMonth(Date.Year, Date.Month, Date.Day)) {
		if (isLastMonthInYear(Date.Month)) {
			Date.Year++;
			Date.Month = 1;
		}
		else {
			Date.Month++;
		}
		Date.Day = 1;
	}
	else {
		Date.Day++;
	}

}

// short GetTodayCount(short Year, short Month, short Day) {
// 	short Counter = 0;
// 	for (short i = 1; i <= Month - 1; i++) {
// 		Counter += GetMonthDayCount(Year, i);
//
// 	}
// 	return Counter + Day;
// }
//
// stDate GetTodayDate(short Year, short TodayCount) {
// 	stDate Date;
// 	Date.Month = 1;
// 	short DaysCount;
// 	while (TodayCount > (DaysCount =  GetMonthDayCount(Year, Date.Month))) {
// 		TodayCount -= DaysCount;
// 		Date.Month++;
// 		if (Date.Month > 12) {
// 			Year++;
// 			Date.Month = 1;
// 		}
// 	}
// 	Date.Year = Year;
// 	Date.Day = TodayCount;
//
// 	return Date;
// }

int main() {
	stDate Date = ReadDate();
	IncreaseDateByOne(Date);
	//Date = GetTodayDate(Date.Year, GetTodayCount(Date.Year, Date.Month, Date.Day)+1);

	cout << "\nDate after adding one day : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	return 0;
}
*/



/// Problem #17 ( Diff in Days )
// Write a program to read a Date1, Date2 and make a function to calculate the difference in days.
// Note: Date 1 should be less then Date2
/*
#include <iostream>
#include <iomanip>
using namespace std;

struct stDate {
	short Day;
	short Month;
	short Year;
};

short ReadNumberBetween(string Message, short From = -32000, short To = 32000) {
	short Num;
	do {
		cout << Message;
		cin >> Num;

	} while (!((Num <= To && Num >= From)));

	return Num;
}

stDate ReadDate() {
	stDate Date;
	Date.Day = ReadNumberBetween("\nPlease enter a day? ", 1, 31);
	Date.Month = ReadNumberBetween("\nPlease enter a Month? ", 1, 12);
	Date.Year = ReadNumberBetween("\nPlease enter a Year? ");
	return Date;
}

bool isLeapYear(short Year) {
	return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
}

short GetMonthDayCount(short Year, short Month) {
	short arr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (isLeapYear(Year) && Month == 2) ? 29 : arr[Month - 1];
}

bool isLastDayInMonth(short Year, short Month, short Day){
	return GetMonthDayCount(Year, Month) == Day;
}

bool isLastMonthInYear(short Month){
	return Month == 12;
}

bool isDate1EqualDate2(stDate Date1, stDate Date2) {
	return Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day;
}

void IncreaseDayByOne(stDate& Date){
	if (isLastDayInMonth(Date.Year, Date.Month, Date.Day)){
		if (isLastMonthInYear(Date.Month)){
			Date.Year++;
			Date.Month = 1;
		}
		else {
			Date.Month++;
		}
		Date.Day = 1;
	}
	else {
		Date.Day++;
	}
}

short GetDifferenceCount(stDate Date1, stDate Date2, bool IncludeEndDay = false){
	short Counter = 0;
	while (!isDate1EqualDate2(Date1, Date2)){
		Counter++;
		IncreaseDayByOne(Date1);
	}
	return (IncludeEndDay) ? ++Counter : Counter;
}

int main() {
	stDate Date1 = ReadDate();
	cout << "\n";
	stDate Date2 = ReadDate();

	cout << "\nDifferance is: "
		<< GetDifferenceCount(Date1, Date2) << " Day(s)." << endl;

	cout << "Differance (Including End Day) is: "
		<< GetDifferenceCount(Date1, Date2, true) << " Day(s). " << endl;

	return 0;
}
*/



/// Problem #18 ( Your Age In Days )
// Write a program calculate you age in days.
/*
#include <iostream>
using namespace std;

struct stDate {
	short Day;
	short Month;
	short Year;
};

short ReadNumberBetween(string Message, short From = -32000, short To = 32000) {
	short Num;
	do {
		cout << Message;
		cin >> Num;

	} while (!((Num <= To && Num >= From)));

	return Num;
}

stDate ReadDate() {
	stDate Date;
	Date.Day = ReadNumberBetween("\nPlease enter a day? ", 1, 31);
	Date.Month = ReadNumberBetween("\nPlease enter a Month? ", 1, 12);
	Date.Year = ReadNumberBetween("\nPlease enter a Year? ");
	return Date;
}

bool isLeapYear(short Year) {
	return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
}

short GetMonthDayCount(short Year, short Month) {
	short arr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (isLeapYear(Year) && Month == 2) ? 29 : arr[Month - 1];
}

bool isLastDayInMonth(short Year, short Month, short Day){
	return GetMonthDayCount(Year, Month) == Day;
}

bool isLastMonthInYear(short Month){
	return Month == 12;
}

void IncreaseDayByOne(stDate& Date){
	if (isLastDayInMonth(Date.Year, Date.Month, Date.Day)){
		if (isLastMonthInYear(Date.Month)){
			Date.Year++;
			Date.Month = 1;
		}
		else {
			Date.Month++;
		}
		Date.Day = 1;
	}
	else {
		Date.Day++;
	}
}

bool isDate1EqualDate2(stDate Date1, stDate Date2) {
	return Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day;
}

stDate GetSystemDate(){
	stDate Date;

	time_t t = time(0);
	tm* now = localtime(&t);

	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;

	return Date;
}

int GetUserAge(stDate Date){
	stDate Date2 = GetSystemDate();
	int Day = 0;

	while (!isDate1EqualDate2(Date, Date2)){
		IncreaseDayByOne(Date);
		Day++;
	}
	return Day;
}

int main(){

	cout << "Please Enter Your Date of Birth: \n\n";
	stDate Date = ReadDate();
	cout << "\n\nYour Age is : " << GetUserAge(Date) << " Day(s). " << endl;

	return 0;
}
 */



 /// Problem #19 ( Diff In Days ( Negative Days ) )
 // Write a program to read a Date1, Date2 and make a function to calculate the difference in days.
 // Note: if date2 is less than date1 print the results in Minutes
 /*
 #include <iostream>
 #include <iomanip>
 using namespace std;

 struct stDate {
	 short Day;
	 short Month;
	 short Year;
 };

 short ReadNumberBetween(string Message, short From = -32000, short To = 32000) {
	 short Num;
	 do {
		 cout << Message;
		 cin >> Num;

	 } while (!((Num <= To && Num >= From)));

	 return Num;
 }

 stDate ReadDate() {
	 stDate Date;
	 Date.Day = ReadNumberBetween("\nPlease enter a day? ", 1, 31);
	 Date.Month = ReadNumberBetween("\nPlease enter a Month? ", 1, 12);
	 Date.Year = ReadNumberBetween("\nPlease enter a Year? ");
	 return Date;
 }

 bool isLeapYear(short Year) {
	 return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
 }

 short GetMonthDayCount(short Year, short Month) {
	 short arr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	 return (isLeapYear(Year) && Month == 2) ? 29 : arr[Month - 1];
 }

 bool isLastDayInMonth(short Year, short Month, short Day){
	 return GetMonthDayCount(Year, Month) == Day;
 }

 bool isLastMonthInYear(short Month){
	 return Month == 12;
 }

 bool isDate1EqualDate2(stDate Date1, stDate Date2) {
	 return Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day;
 }

 bool isDate1LongerThenDate2(stDate Date1, stDate Date2){
	 return (Date1.Year > Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month > Date2.Month ? true : (Date1.Month == Date2.Month) ? (Date1.Day > Date2.Day) : false) : false;
 }

 void IncreaseDayByOne(stDate& Date){
	 if (isLastDayInMonth(Date.Year, Date.Month, Date.Day)){
		 if (isLastMonthInYear(Date.Month)){
			 Date.Year++;
			 Date.Month = 1;
		 }
		 else {
			 Date.Month++;
		 }
		 Date.Day = 1;
	 }
	 else {
		 Date.Day++;
	 }
 }

 void SwapDates(stDate& Date1, stDate& Date2){
	 stDate TempDate;

	 TempDate.Year = Date1.Year;
	 TempDate.Month = Date1.Month;
	 TempDate.Day = Date1.Day;

	 Date1.Year = Date2.Year;
	 Date1.Month = Date2.Month;
	 Date1.Day = Date2.Day;

	 Date2.Year = TempDate.Year;
	 Date2.Month = TempDate.Month;
	 Date2.Day = TempDate.Day;
 }

 short GetDifferenceCount(stDate Date1, stDate Date2, bool IncludeEndDay = false){
	 short Counter = 0;
	 int SwapFlagValue = 1;

	 if (isDate1LongerThenDate2(Date1, Date2)){
		 SwapDates(Date1, Date2);
		 SwapFlagValue = -1;
	 }
	 while (!isDate1EqualDate2(Date1, Date2)){
		 Counter++;
		 IncreaseDayByOne(Date1);
	 }
	 return (SwapFlagValue) * ((IncludeEndDay) ? ++Counter : Counter);
 }

 int main() {
	 stDate Date1 = ReadDate();
	 cout << "\n";
	 stDate Date2 = ReadDate();

	 cout << "\nDifferance is: "
		  << GetDifferenceCount(Date1, Date2) << " Day(s)." << endl;

	 cout << "Differance (Including End Day) is: "
		  << GetDifferenceCount(Date1, Date2, true) << " Day(s). " << endl;

	 return 0;
 }
  */



  /// Problem #20 - #32 ( Increase Date Problems )
  // Write a program to read a date and make a function to increase date as follows :
  /*
  #include <iostream>
  #include <iomanip>
  #include "MyDateLib.h";

  using namespace std;
  using namespace DateLib;

  void IncreaseDateByXDays(stDate& D, short Add) {

	  for (short i = 1; i <= Add; i++) {
		  IncreaseDayByOne(D);
	  }

  }

  void IncreaseDateByOneWeek(stDate& D) {

	  for (short i = 1; i <= 7; i++) {
		  IncreaseDayByOne(D);
	  }

  }

  void IncreaseDateByXWeeks(stDate& D, short Weeks) {

	  for (short i = 1; i <= Weeks; i++) {
		  IncreaseDateByOneWeek(D);
	  }

  }

  void IncreaseDateByOneMonth(stDate& D) {

	  if (D.Month == 12) {
		  D.Year++;
		  D.Month = 1;
	  }
	  else {
		  D.Month++;
	  }

	  short DaysInCurrectMonth = GetDayCountInMonth(D.Month, D.Year);
	  if (D.Day > DaysInCurrectMonth) {
		  D.Day = DaysInCurrectMonth;
	  }

  }

  void IncreaseDateByXMonths(stDate& D, short Months) {
	  for (short i = 1; i <= Months; i++) {
		  IncreaseDateByOneMonth(D);
	  }
  }

  void IncreaseDateByOneYear(stDate& D) {
	  D.Year++;
  }

  void IncreaseDateByXYears(stDate& D, short Year) {
	  for (short i = 1; i <= Year; i++) {
		  IncreaseDateByOneYear(D);
	  }
  }

  void IncreaseDateByXYearsFaster(stDate& D, short Year) {
	  D.Year += Year;
  }

  void IncreaseDateByOneDecade(stDate& D) {
	  D.Year += 10;
  }

  void IncreaseDateByXDecades(stDate& D, short Decade) {
	  for (short i = 1; i <= Decade*10; i++) {
		  IncreaseDateByOneYear(D);
	  }
  }

  void IncreaseDateByXDecadesFaster(stDate& D, short Decade) {
	  D.Year += 10 * Decade;
  }

  void IncreaseDateByOneCentury(stDate& D) {
	  D.Year += 100;
  }

  void IncreaseDateByOneMillennium(stDate& D) {
	  D.Year += 1000;
  }

  string PrintDate(stDate D) {
	  return to_string(D.Day) + "/" + to_string(D.Month) + "/" + to_string(D.Year);
  }

  int main() {
	  stDate Date = ReadDate();

	  cout << "Date is : ";
	  cout << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n\n";

	  cout << "Date after : \n\n";


	  IncreaseDayByOne(Date);
	  cout << "01-Adding one day is: " << PrintDate(Date) << endl;

	  // ============================================================

	  IncreaseDateByXDays(Date, 10);
	  cout << "02-Adding 10 days is: " << PrintDate(Date) << endl;

	  // ============================================================

	  IncreaseDateByOneWeek(Date);
	  cout << "03-Adding One week is: " << PrintDate(Date) << endl;

	  // ============================================================

	  IncreaseDateByXWeeks(Date, 10);
	  cout << "04-Adding 10 weeks is: " << PrintDate(Date) << endl;

	  // ============================================================

	  IncreaseDateByOneMonth(Date);
	  cout << "05-Adding one Month is: " << PrintDate(Date) << endl;

	  // ============================================================

	  IncreaseDateByXMonths(Date, 5);
	  cout << "06-Adding one months is: " << PrintDate(Date) << endl;

	  // ============================================================

	  IncreaseDateByOneYear(Date);
	  cout << "07-Adding one year is: " << PrintDate(Date) << endl;

	  // ============================================================

	  IncreaseDateByXYears(Date, 10);
	  cout << "08-Adding 10 Years is: " << PrintDate(Date) << endl;

	  // ============================================================

	  IncreaseDateByXYearsFaster(Date, 10);
	  cout << "09-Adding 10 Years (faster) is: " << PrintDate(Date) << endl;

	  // ============================================================

	  IncreaseDateByOneDecade(Date);
	  cout << "10-Adding one Decade is: " << PrintDate(Date) << endl;

	  // ============================================================

	  IncreaseDateByXDecades(Date, 10);
	  cout << "11-Adding 10 Decades is: " << PrintDate(Date) << endl;

	  // ============================================================

	  IncreaseDateByXDecadesFaster(Date, 10);
	  cout << "12-Adding 10 Decade (faster) is: " << PrintDate(Date) << endl;

	  // ============================================================

	  IncreaseDateByOneCentury(Date);
	  cout << "13-Adding one Century is: " << PrintDate(Date) << endl;

	  // ============================================================

	  IncreaseDateByOneMillennium(Date);
	  cout << "14-Adding one Millennium is: " << PrintDate(Date) << endl;

	  return 0;
  }
  */



  /// Problem #33 - #46 ( Decrease Date Problems )
  // Write a program to read a date and make a function to Decrease date as follows:
  /*
  #include <iostream>
  #include <iomanip>
  #include "MyDateLib.h";

  using namespace std;
  using namespace DateLib;



  void DecreaseDateByOneDay(stDate& Date) {
	  if (Date.Day == 1) {
		  if (Date.Month == 1) {
			  Date.Year--;
			  Date.Month = 12;
		  }
		  else {
			  Date.Month--;
		  }
		  Date.Day = GetDayCountInMonth(Date.Month, Date.Year);
	  }
	  else {
		  Date.Day--;
	  }
  }

  void DecreaseDateByXDays(stDate& Date, short Day) {
	  for (short i = 0; i < Day; i++) {
		  DecreaseDateByOneDay(Date);
	  }
  }

  void DecreaseDateByOneWeek(stDate& Date) {
	  for (short i = 0; i < 7; i++) {
		  DecreaseDateByOneDay(Date);
	  }
  }

  void DecreaseDateByXWeeks(stDate& Date, short Week) {
	  for (short i = 0; i < Week; i++) {
		  DecreaseDateByOneWeek(Date);
	  }
  }

  void DecreaseDateByOneMonth(stDate& Date) {
	  if (Date.Month == 1) {
		  Date.Year--;
		  Date.Month = 12;
	  }
	  else {
		  Date.Month--;
	  }

	  short Max = GetDayCountInMonth(Date.Month, Date.Year);
	  if (Date.Day > Max) {
		  Date.Day = Max;
	  }
  }

  void DecreaseDateByXMonths(stDate& Date, short Month) {
	  for (short i = 0; i < Month; i++) {
		  DecreaseDateByOneMonth(Date);
	  }
  }

  void DecreaseDateByOneYear(stDate& Date) {
	  Date.Year--;
  }

  void DecreaseDateByXYears(stDate& Date, short Year) {
	  for (short i = 0; i < Year; i++) {
		  DecreaseDateByOneYear(Date);
	  }
  }

  void DecreaseDateByXYearsFaster(stDate& Date, short Year) {
	  Date.Year -= Year;
  }

  void DecreaseDateByOneDecades(stDate& Date) {
	  Date.Year -= 10;
  }

  void DecreaseDateByXDecades(stDate& Date, short Decade) {
	   for (short i = 0; i < Decade * 10; i++) {
		   DecreaseDateByOneYear(Date);
	   }
  }

  void DecreaseDateByXDecadesFaster(stDate& Date, short Decade) {
	  Date.Year -= Decade * 10;
  }

  void DecreaseDateByOneCentury(stDate& Date) {
	  Date.Year -= 100;
  }

  void DecreaseDateByOneMillennium(stDate& Date) {
	  Date.Year -= 1000;
  }

  int main() {
	  stDate Date = ReadDate();
	  cout << "Print Date : " << PrintDate(Date);
	  cout << "\n\nDate After: \n\n";
	  short i = 1;

	  DecreaseDateByOneDay(Date);
	  cout << setw(3) << left << i++ << "- Subtracting one day is: " << PrintDate(Date) << endl;

	  // ======================================================================

	  DecreaseDateByXDays(Date, 10);
	  cout << setw(3) << left << i++ << "- Subtracting 10 day is: " << PrintDate(Date) << endl;

	  // ======================================================================

	  DecreaseDateByOneWeek(Date);
	  cout << setw(3) << left << i++ << "- Subtracting one week is: " << PrintDate(Date) << endl;

	  // =======================================================================

	  DecreaseDateByXWeeks(Date, 10);
	  cout << setw(3) << left << i++ << "- Subtracting 10 weeks is: " << PrintDate(Date) << endl;

	  // =======================================================================

	  DecreaseDateByOneMonth(Date);
	  cout << setw(3) << left << i++ << "- Subtracting one month is: " << PrintDate(Date) << endl;

	  // =======================================================================

	  DecreaseDateByXMonths(Date, 5);
	  cout << setw(3) << left << i++ << "- Subtracting 5 months is: " << PrintDate(Date) << endl;

	  // =======================================================================

	  DecreaseDateByOneYear(Date);
	  cout << setw(3) << left << i++ << "- Subtracting one year is: " << PrintDate(Date) << endl;

	  // =======================================================================

	  DecreaseDateByXYears(Date, 10);
	  cout << setw(3) << left << i++ << "- Subtracting 10 years is: " << PrintDate(Date) << endl;

	  // =======================================================================

	  DecreaseDateByXYearsFaster(Date, 10);
	  cout << setw(3) << left << i++ << "- Subtracting 10 years (faster) is: " << PrintDate(Date) << endl;

	  // ========================================================================

	  DecreaseDateByOneDecades(Date);
	  cout << setw(3) << left << i++ << "- Subtracting one Decade is: " << PrintDate(Date) << endl;

	  // ========================================================================

	  DecreaseDateByXDecades(Date, 10);
	  cout << setw(3) << left << i++ << "- Subtracting 10 Decades is: " << PrintDate(Date) << endl;

	  // ========================================================================

	  DecreaseDateByXDecadesFaster(Date, 10);
	  cout << setw(3) << left << i++ << "- Subtracting 10 Decades (faster) is: " << PrintDate(Date) << endl;

	  // ========================================================================

	  DecreaseDateByOneCentury(Date);
	  cout << setw(3) << left << i++ << "- Subtracting One Century is: " << PrintDate(Date) << endl;

	  // ========================================================================

	  DecreaseDateByOneMillennium(Date);
	  cout << setw(3) << left << i++ << "- Subtracting One Millennium is: " << PrintDate(Date) << endl;

	  return 0;
  }
  */



  /// Problem #47 - #53 ( More Date Problems )
  // Write a program to read a date and make a function as follows:
  /*
  #pragma warning(disable : 4996)
  #include <iostream>
  #include <iomanip>
  #include "MyDateLib.h";

  using namespace std;
  using namespace DateLib;

  short DayOfWeekOrder(stDate Date) {
	  int a = (14 - Date.Month) / 12;
	  int y = Date.Year - a;
	  int m = Date.Month + 12 * a - 2;

	  int d;
	  d = (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	  return d;
  }

  bool isEndOfWeek(stDate Date) {
	  short TodayCount = DayOfWeekOrder(Date);
	  return (TodayCount == 0);
  }

  bool isWeekEnd(stDate Date) {
	  short TodayCount = DayOfWeekOrder(Date);
	  return (TodayCount == 0 || TodayCount == 6);
  }

  bool isWorkDay(stDate Date) {
	  return !isWeekEnd(Date);
  }

  short DaysUntilTheEndOfWeek(stDate Date) {
	  short TodayCount = DayOfWeekOrder(Date);
	  return 7 - TodayCount;
  }

  short DaysUntilTheEndOfMonth(stDate Date) {
	  // stDate End;
	  // End.Day = GetDayCountInMonth(Date.Month, Date.Year);
	  // End.Month = Date.Month;
	  // End.Year = Date.Year;
	  //
	  // return GetDifferenceCount(Date, End, true);
	  return GetDayCountInMonth(Date.Month, Date.Year) - Date.Day;
  }

  short DaysUntilTheEndOfYear(stDate Date) {
	  stDate EndYear;
	  EndYear.Day = 31;
	  EndYear.Month = 12;
	  EndYear.Year = Date.Year;

	  short Counter = 0;
	  while (isDate1LongerThenDate2(EndYear, Date)) {
		  IncreaseDayByOne(Date);
		  Counter++;
	  }
	  return Counter;
  }

  int main() {
	  stDate Date = GetSystemDate();

	  cout << "Today is " << GetDayShortName(Date.Day - 1) << " , " << PrintDate(Date) << endl;

	  cout << "\nIs it End of Week? ";
	  if (isEndOfWeek(Date)) {
		  cout << "\nYes it is the end of the week. ";
	  } else {
		  cout << "\nNo it is NOT the end of the week. ";
	  }

	  cout << "\n\nIs it Weekend? ";
	  if (isWorkDay(Date)) {
		  cout << "\nYes it is a weekend. ";
	  } else {
		  cout << "\nNo it is NOT a weekend. ";
	  }

	  cout << "\n\nIs it Business Day? ";
	  if (isWorkDay(Date)) {
		  cout << "\nYes it is a Business Day. ";
	  } else {
		  cout << "\nNo it is NOT a business day. ";
	  }

	  cout << "\n";
	  cout << "\nDays until end of week  : " << DaysUntilTheEndOfWeek(Date) << " Day(s). ";
	  cout << "\nDays until end of Month : " << DaysUntilTheEndOfMonth(Date) << " Days(s). ";
	  cout << "\nDays until end of year  : " << DaysUntilTheEndOfYear(Date) << " Day(s). ";

	  return 0;
  }
  */



  /// Problem #54 ( Calculate Vacation Days )
  // Write a program to read Vacation Period DateFrom and
  // DateTo and make a function to calculate the actual vacatoin days.
  /*
  #include <iostream>
  #include "MyDateLib.h"

  using namespace std;
  using namespace DateLib;

  short ActualVacationDays(stDate From, stDate To) {
	  short Counter = 0;
	  while (isDate1BeforeDate2(From, To)) {
		  if (isWorkDay(From)) {
			  Counter++;
		  }
		  IncreaseDayByOne(From);
	  }
	  return Counter;
  }

  int main() {
	  cout << "\nVacation Starts: " << endl;
	  stDate DateFrom = ReadDate();

	  cout << "\nVacation Ends: " << endl;
	  stDate DateTo = ReadDate();


	  cout << "\nVacation From: " << GetDayShortName(DayOfWeekOrder(DateFrom));
	  cout << " , " << PrintDate(DateFrom);

	  cout << "\nVacation To: " << GetDayShortName(DayOfWeekOrder(DateTo));
	  cout << " , " << PrintDate(DateTo) << endl;

	  cout << "\nActual Vacation Days is: " << ActualVacationDays(DateFrom, DateTo) << endl;

	  return 0;
  }

  */



/// Problem #55 ( Calculate Vacation Return Date )
// Write a program to read Vacation Start DateFrom and VacationDays, then
// make a function to calculate the vacation return Date.
/*
  #include <iostream>
  using namespace std;
  #include "MyDateLib.h";
  using namespace DateLib;

  stDate ReturnDate(stDate From, short VacationDates) {

	  // in case the data is weekend keep adding one day until you reach business
	  // we get rid of all weekends before the first business day
	  while (isWeekEnd(From)) {
		  IncreaseDayByOne(From);
	  }

	  //here we increase the vacation dates to add all weekends to it.
	  short WeekEndCounter = 0;
	  for (short i = 1; i <= VacationDates + WeekEndCounter; i++) {

		  if (isWeekEnd(From)) {
			  WeekEndCounter++;
		  }

		  IncreaseDayByOne(From);
	  }

	  //in case the return date is week end keep adding one day until you reach business day
	  while (isWeekEnd(From)) {
		  IncreaseDayByOne(From);
	  }

	  return From;
  }

  int main() {
	  cout << "Vacation Starts: " << endl;
	  stDate DateFrom = ReadDate();

	  short VacationDays;
	  cout << "\nPlease enter vacation days? ";
	  cin >> VacationDays;

	  stDate Return = ReturnDate(DateFrom, VacationDays);

	  cout << "\n\nReturn Date: " << GetDayShortName(DayOfWeekOrder(Return));
	  cout << " , " << PrintDate(Return) << endl;

	  return 0;
  }
  */



  /// Problem #56 ( Is Date1 After Date2 )
  // Write a program to read Date1 & Date2, and check if Date1 is after Date2 or not.
  /*
  #include <iostream>
  using namespace std;

  #include "MyDateLib.h"
  using namespace DateLib;

  int main() {
	  cout << "Enter Date1: \n";
	  stDate Date1 = ReadDate();

	  cout << "\nEnter Date2: \n";
	  stDate Date2 = ReadDate();

	  if (isDate1AfterThenDate2(Date1, Date2)) {
		  cout << "Yes, Date1 is After Date2. " << endl;
	  } else {
		  cout << "No, Date1 is NOT After Date2" << endl;
	  }
  }
  */



  /// Problem #57 ( Compare Date Function )
  // Write a Program to read Date1, Date2 and write a function to compare dates, it should return:
  /*
  #include <iostream>
  using namespace std;

  #include "MyDateLib.h"
  using namespace DateLib;

  enum enDateCompare{Before = -1, Equal = 0, After = 1};

  enDateCompare CompareDates(stDate Date1, stDate Date2) {
	  if (isDate1BeforeDate2(Date1, Date2)) {
		  return enDateCompare::Before;
	  }
	  if (isDate1EqualDate2(Date1, Date2)) {
		  return enDateCompare::Equal;
	  }
	  return enDateCompare::After;

  }

  int main() {

	  cout << "Enter Date1: " << endl;
	  stDate Date1 = ReadDate();
	  cout << "\nEnter Date2: " << endl;
	  stDate Date2 = ReadDate();

	  cout << "\nCompare Result = " << CompareDates(Date1, Date2) << endl;
	  return 0;
  }
  */



  /// Problem #58 ( Is Overlap Periods )
  // Write a  program to read Two Periods and check if they overlap or not?
  /*
  #include <iostream>
  using namespace std;

  #include "MyDateLib.h";
  using namespace DateLib;

  bool isDatesOverlap(stPeriod Period1, stPeriod Period2) {
	  if (
		  CompareDates(Period1.EndDate, Period2.StartDate) == enDateCompare::Before
		  ||
		  CompareDates(Period1.StartDate, Period2.EndDate) == enDateCompare::After
		  ) {
		  return false;
	  }
	  else {
		  return true;
	  }
  }

  int main() {
	  cout << "Enter Period1: \n\n";
	  stPeriod Period1 = ReadPeriod();

	  cout << "\n\nEnter Period2: \n\n";
	  stPeriod Period2 = ReadPeriod();

	  if (isDatesOverlap(Period1, Period2)) {
		  cout <<"Yes, Periods Overlap" << endl;
	  } else {
		  cout << "No, Periods NOT Overlap" << endl;
	  }

	  return 0;
  }
  */



  /// Problem #59 ( Period Length In Days )
  // Write a program to read a period and calculate period length in days?
  /*
  #include <iostream>
  using namespace std;

  #include "MyDateLib.h";
  using namespace DateLib;

  short GetPeriodLength(stPeriod Period, bool IncludingEndDay = false) {
	  return GetDifferenceCount(Period.StartDate, Period.EndDate, IncludingEndDay);
  }

  int main() {
	  cout << "Enter Period 1: \n";
	  stPeriod Period = ReadPeriod();

	  cout << "\nPeriod Length is: " << GetPeriodLength(Period) << endl;
	  cout << "Period Length (Including End Date) is: " << GetPeriodLength(Period, true) << endl;

	  return 0;
  }
  */



  /// Problem #60 ( Is Date Within Period )
  // Write a program to read a Period and DAte, then check if date is within this period or not?
  /*
  #include <iostream>
  using namespace std;

  #include "MyDateLib.h";
  using namespace DateLib;

  bool isDateWithinPeriod(stPeriod Period, stDate Date) {
	  return (
		  CompareDates(Period.StartDate, Date) == enDateCompare::Before
		  &&
		  CompareDates(Period.EndDate, Date) == enDateCompare::After
		  );
  }

  int main() {
	  cout << "Enter Period: " << endl;
	  stPeriod Period = ReadPeriod();

	  cout << "\nEnter Date to check: " << endl;
	  stDate Date = ReadDate();

	  if (isDateWithinPeriod(Period, Date)) {
		  cout << "\nYes, Date is within period. " << endl;
	  } else {
		  cout << "\nNo, Date is NOT within period. " << endl;
	  }
	  return 0;
  }
  */



  /// Problem #61 ( Count Overlap Days )
  // Write a program to read two periods then count overlap days
  /*
  #include <iostream>
  using namespace std;

  #include "MyDateLib.h";
  using namespace DateLib;

  short GetOverlapDaysCount(stPeriod Period1, stPeriod Period2) {
	  short Period1Length = GetPeriodLength(Period1, true);
	  short Period2Length = GetPeriodLength(Period2, true);

	  if (!isOverlapPeriods(Period1, Period2)) {
		  return 0;
	  }

	  short OverlapCount = 0;
	  if (Period1Length < Period2Length) {
		  while (isDate1BeforeDate2(Period1.StartDate, Period1.EndDate)) {
			  if (isDateWithinPeriod(Period2, Period1.StartDate)) {
				  OverlapCount++;
			  }
			  IncreaseDayByOne(Period1.StartDate);
		  }

	  }
	  else {
		  while (isDate1BeforeDate2(Period2.StartDate, Period2.EndDate)) {
			  if (isDateWithinPeriod(Period1, Period2.StartDate)) {
				  OverlapCount++;
			  }
			  IncreaseDayByOne(Period2.StartDate);
		  }

	  }

	  return OverlapCount;
  }

  int main() {
	  cout << "Enter Period1 : " << endl;
	  stPeriod Period1 = ReadPeriod();
	  cout << "\nEnter Period2 : " << endl;
	  stPeriod Period2 = ReadPeriod();

	  cout << "\n\nOverlap Days Count is: " << GetOverlapDaysCount(Period1, Period2) << endl;

	  return 0;
  }
  */



  /// Problem #62 ( Validate Date )
  // Write a program to read Date and write a function to validate this date
  /*
  #include <iostream>
  using namespace std;

  #include "MyDateLib.h"
  using namespace DateLib;

  bool isValidDate(stDate Date) {
	  if (Date.Day > GetDayCountInMonth(Date.Month, Date.Year) || Date.Day < 1) {
		  return false;
	  }

	  if (Date.Month > 12 || Date.Month < 1) {
		  return false;
	  }

	  if (Date.Year < 1) {
		  return false;
	  }

	  return true;
  }

  int main() {
	  stDate Date = ReadDate();
	  if (isValidDate(Date)) {
		  cout << "\nYes, Date is a valid date. " << endl;
	  } else {
		  cout << "\nNo, Date is NOT a valid date. " << endl;
	  }

	  return 0;
  }
  */



  /// Problem #63 & #64 ( Read/Print Date String )
  // Write a program to
  // * StringToDate.
  // * DateToString.
  /*
  #include <iostream>
  #include "MyStringLib.h"
  #include <vector>
  #include "MyDateLib.h"
  #include <string>


  using namespace std;
  using namespace DateLib;

  stDate StringToDate(string sDate) {
	  vector<string> vString = StringLib::SplitString(sDate, "/");

	  stDate Date;

	  Date.Day = stoi(vString[0]);
	  Date.Month = stoi(vString[1]);
	  Date.Year = stoi(vString[2]);

	  return Date;
  }

  string DateToString(stDate Date) {
	  string sDate;
	  sDate += to_string(Date.Day) + "/";
	  sDate += to_string(Date.Month) + "/";
	  sDate += to_string(Date.Year);
	  return sDate;
  }

  string ReadStringDate() {
	  string sDate;
	  cout << "Please Enter Date dd/mm/yyyy? ";
	  getline(cin >> ws, sDate);
	  return sDate;
  }

  int main() {

	  string sDate = ReadStringDate();

	  stDate Date = StringToDate(sDate);
	  cout << "\nDay:" << Date.Day;
	  cout << "\nMonth:" << Date.Month;
	  cout << "\nYear:" << Date.Year;

	  cout << "\n\nYou Entered: " << DateToString(Date) << endl;

	  system("pause > 0");
	  return 0;
  }
  */



  /// Problem #65 ( FormatDate )
  // Write a program to read Date and write a function to format that date.
  
  #include <iostream>
  #include "MyDateLib.h"
  #include "MyStringLib.h"
  using namespace std;
  using namespace DateLib;


  string FormatDate(stDate Date, string FormatedDate = "dd/mm/yyyy") {

	  FormatedDate = StringLib::ReplaceWordInStringUsingBuiltInFunction(FormatedDate, "dd", to_string(Date.Day));
	  FormatedDate = StringLib::ReplaceWordInStringUsingBuiltInFunction(FormatedDate, "mm", to_string(Date.Month));
	  FormatedDate = StringLib::ReplaceWordInStringUsingBuiltInFunction(FormatedDate, "yyyy", to_string(Date.Year));

	  return FormatedDate;
  }

  int main() {
	  string sDate = ReadStringDate();
	  stDate Date = StringToDate(sDate);

	  cout << "\n\n" << FormatDate(Date) << "\n\n";
	  cout << FormatDate(Date, "yyyy/dd/mm") << "\n\n";
	  cout << FormatDate(Date, "mm/dd/yyyy") << "\n\n";
	  cout << FormatDate(Date, "mm-dd-yyyy") << "\n\n";
	  cout << FormatDate(Date, "dd-mm-yyyy") << "\n\n";
	  cout << FormatDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n\n";

	  return 0;
  }
  
