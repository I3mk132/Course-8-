#pragma once;

#include <iostream>
#include <iomanip>



namespace DateLib {

    struct stDate {
        short Year = 0;
        short Month = 0;
        short Day = 0;
    };

    short ReadYear() {
        short Num;
        std::cout << "Please enter a Year? ";
        std::cin >> Num;
        return Num;
    }

    short ReadMonth() {
        short Num;

        do {
            std::cout << "Please enter a Month? ";
            std::cin >> Num;
        } while (!(Num > 0 && Num < 13));

        return Num;
    }

    short ReadDay() {
        short Num;
        do {
            std::cout << "Please enter a day? ";
            std::cin >> Num;
        } while (Num < 1 || Num > 31);

        return Num;
    }

    stDate ReadDate() {
        stDate D;
        D.Day = ReadDay();
        D.Month = ReadMonth();
        D.Year = ReadYear();
        return D;
    }

    bool isLeapYear(short Year) {
        return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
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

    int GetDayCountInMonth(short Month, short Year) {

        if (Month > 12 || Month < 1) {
            return 0;
        }

        short arrDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (Month == 2 ? (isLeapYear(Year) ? 29 : 28) : arrDays[Month - 1]);
    }

    std::string GetDayName(int Number) {
        std::string arr[] = {
            "Sunday", "Monday", "tuesday",
            "wednesday", "thursday", "Friday",
            "Saturday"
        };
        return arr[Number];
    }

    std::string GetDayShortName(int Number) {
        std::string arr[] = {
            "Sun", "Mon", "Tue",
            "Wed", "Thu", "Fri",
            "Sat"
        };
        return arr[Number];
    }

    short DayOfWeekOrder(int Year, int Month, int Day) {
        int a = (14 - Month) / 12;
        int y = Year - a;
        int m = Month + 12 * a - 2;

        int d;
        d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

        return d;
    }

    std::string GetMonthShortName(int Number) {
        std::string arr[] = {
            "Jan", "Feb", "Mar", "Apr",
            "May", "Jun", "Jul", "Aug",
            "Sep", "Oct", "Nov", "Dec"
        };
        return arr[Number-1];
    }

    void PrintDays(short Year, short Month) {

        int NumberOfDays = GetDayCountInMonth(Month, Year);
        int ThisMonth = DayOfWeekOrder(Year, Month, 1);

        int i;
        for (i = 0; i < ThisMonth; i++) {
            std::cout << std::setw(5) << "";
        }

        for (short j = 0; j < NumberOfDays; j++) {
            std::cout << std::setw(5) << j + 1;

            if (++i == 7) {
                i = 0;
                std::cout << "\n";
            }
        }
    }

    void PrintCalender(short Year) {

        std::cout << "\n_____________________________________\n\n";
        std::cout << "           Calender - " << Year << "\n";
        std::cout << "_____________________________________\n\n";

        for (short i = 1; i <= 12; i++) {
            std::cout << "________________" << GetMonthShortName(i) << "__________________\n\n";
            std::cout << std::setw(5) << "Sun";
            std::cout << std::setw(5) << "Mon";
            std::cout << std::setw(5) << "Tue";
            std::cout << std::setw(5) << "Wed";
            std::cout << std::setw(5) << "Thu";
            std::cout << std::setw(5) << "Fri";
            std::cout << std::setw(5) << "Sat";
            std::cout << "\n";

            PrintDays(Year, i);

            std::cout << "\n_____________________________________\n\n";
        }
    }

    short GetTodayCountInYear(short Year, short Month, short Day) {
        short Counter = 0;
        for (short i = 1; i <= Month - 1; i++) {
            Counter += GetDayCountInMonth(Year, i);
        }
        return Counter + Day;
    }

    short GetTodayCount(short Year, short Month, short Day) {
        short Counter = 0;
        for (short i = 1; i <= Month - 1; i++) {
            Counter += GetDayCountInMonth(Year, i);
        }
        return Counter + Day;
    }

    stDate GetTodaysDate(short Year, short Days) {
        stDate Date;
        short DayCount;
        short ThisMonth = 1;
        while (Days >= (DayCount = GetDayCountInMonth(ThisMonth, Year))) {
            Days -= DayCount;
            ThisMonth++;
        }
        Date.Day = Days;
        Date.Month = ThisMonth;
        Date.Year = Year;
        return Date;
    }

    bool isDate1LongerThenDate2(stDate Date1, stDate Date2) {

        if (Date1.Year > Date2.Year) {
            return true;
        }
        else if (Date1.Year == Date2.Year) {

            if (Date1.Month > Date2.Month) {
                return true;
            }
            else if (Date1.Month == Date2.Month){

                if (Date1.Day > Date2.Day) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isDate1EqualDate2(stDate Date1, stDate Date2) {
        return Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day;
    }

    bool isLastDayInMonth(short Year, short Month, short Day) {
        return (GetDayCountInMonth(Month, Year) == Day);
    }

    bool isLastMonthInYear(short Month) {
        return Month == 12;
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

    bool isDate1BeforeDate2(stDate Date1, stDate Date2) {
        return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

    std::string PrintDate(stDate D) {
        return std::to_string(D.Day) + "/" + std::to_string(D.Month) + "/" + std::to_string(D.Year);
    }

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
}


