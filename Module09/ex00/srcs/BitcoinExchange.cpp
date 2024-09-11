#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if ( this != &rhs )
	{
		this->_exchangeRates = rhs.getExchangeRates();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

const std::map<std::string, double>&   BitcoinExchange::getExchangeRates() const{
    return _exchangeRates;
}


void			BitcoinExchange::parseBitcoinExchangeRate(std::ifstream & bitcoinRatesHistory) {
	std::string line;

	std::getline(bitcoinRatesHistory, line);
	while (std::getline(bitcoinRatesHistory, line)) { 
        std::stringstream ss(line);
        std::string inputDate, exchangeRate;

        if (std::getline(ss, inputDate, ',')) {
            std::getline(ss, exchangeRate);

            removeAllWhitespace(inputDate);
            removeAllWhitespace(exchangeRate);

            if(inputDate == "" || exchangeRate == "") 
                throw std::runtime_error("ERROR! Either inputDate or exchangeRate is missing!");

            if(!isDateFormatValid(inputDate) || !isDateOnlyDigits(inputDate) || !isMonthDayValid(inputDate))
                throw std::runtime_error("ERROR! Reference database(data.csv) has error in one of its date");

            if (!isValidFloatFormat(exchangeRate) || !isFloatPositive(exchangeRate))
                throw std::runtime_error("ERROR! Reference database(data.csv) has error in one of its exchange rate");

			_exchangeRates.insert(std::make_pair(inputDate,std::atof(exchangeRate.c_str()))); //TODO: Test the std::atof 
        } else {
            throw std::runtime_error("ERROR! Delimiter(comma) not found in the line: ");
        }
    }
}

void            BitcoinExchange::parseBitcoinValue(std::ifstream & bitcoinValueHistory) {
    std::string line;
    
    std::getline(bitcoinValueHistory, line);
    while(std::getline(bitcoinValueHistory, line)) {
        std::stringstream ss(line);
        std::string targetDate, bitcoinValue;

        if (std::getline(ss, targetDate, '|')) {
            std::getline(ss, bitcoinValue);

            removeAllWhitespace(targetDate);
            removeAllWhitespace(bitcoinValue);
        
            if (targetDate == "" || bitcoinValue == "")
                std::cerr << "ERROR! Target date or bitcoin value is missing" << " => " << line << std::endl;
            else if (!isDateFormatValid(targetDate))
                std::cerr << "ERROR! Date format does not respect YYYY-MM-DD" << " => " << targetDate << std::endl;
            else if (!isDateOnlyDigits(targetDate))
                std::cerr << "ERROR! Date is not composed only composed of digit" << " => " << targetDate << std::endl;
            else if (!isMonthDayValid(targetDate))
                 std::cerr << "ERROR! Date provided does not exist" << " => " << targetDate << std::endl;
            else if (!isValidFloatFormat(bitcoinValue))
                std::cerr << "ERROR! Bitcoin value is not an integer or a float" <<  " => " << bitcoinValue << std::endl;
            else if (!isFloatPositive(bitcoinValue))
                std::cerr << "ERROR! Bitcoin value is not positive" <<  " => " << bitcoinValue << std::endl;
            else if (!isFloatWithinRange(bitcoinValue, 0, 1000))
                std::cerr << "ERROR! Bitcoin value is not within range of 0 to 1000" <<  " => " << bitcoinValue << std::endl;
            else {
                std::map<std::string, double>::iterator it = _exchangeRates.find(targetDate);
                if(it == _exchangeRates.end())
                    it = findClosestDate(targetDate);
                if(it == _exchangeRates.end()) // TODO: This is temporary fix to fix problem of date that is lower than lowest date.  
                    std::cout << "ERROR! Cannot find match because date provided is lower than lowest date in database" << std::endl;
                else
                    std::cout << it->first << " => " << bitcoinValue << " = " << (std::atof(bitcoinValue.c_str()) * it->second) << std::endl; // TODO: is std::atof OK
            } 
        } else {
            std::cerr << "ERROR! Delimiter | is missing or improperly formatted line" << std::endl;
        }
    }
}


std::map<std::string, double>::iterator BitcoinExchange::findClosestDate(std::string inputDate){

    std::map<std::string, double>::iterator it;
    unsigned int                            year, month, day;

    parseDateToInteger(inputDate, year, month, day);

    while (1) {
        std::string previousDate = generatePreviousDate(year, month, day);

        it = _exchangeRates.find(previousDate);
        if (it !=  _exchangeRates.end())
            return it;

        parseDateToInteger(previousDate, year, month, day);

        if (year < 2009) { //TODO: Test this section 
            break;
        }
    }
    return _exchangeRates.end();
}


void	BitcoinExchange::printBitcoinRates(){
	std::map<std::string, double>::iterator it;

	for(it = _exchangeRates.begin(); it != _exchangeRates.end(); ++it){
		std::cout << std::fixed << std::setprecision(2) << it->first << " | " << it->second << std::endl;
	}
}

/*
** --------------------------------- OTHER ---------------------------------
*/

std::string::iterator findFirstNonWhitespace(std::string & s){
    std::string::iterator it;

    for(it = s.begin(); it != s.end(); ++it){
        if (!std::isspace(static_cast<unsigned char>(*it)))
            return(it);
    }
    return s.end();
}

std::string::iterator findFirstTrailingWhitespace(std::string & s){
    std::string::iterator it;

    for(it = s.begin(); it != s.end(); ++it){
        if (std::isspace(static_cast<unsigned char>(*it)))
            return(it);
    }
    return s.end();
}

std::string     trimLeadingWhitespace(std::string & s){
    s.erase(s.begin(), findFirstNonWhitespace(s));
    return (s);
}

std::string     trimTrailingWhitespace(std::string & s){
    s.erase(findFirstTrailingWhitespace(s), s.end());
    return(s);
}

std::string     removeAllWhitespace(std::string & s){
    trimLeadingWhitespace(s);
    trimTrailingWhitespace(s);

    return (s);
}

bool            isDateFormatValid(std::string & s){
    if (s[4] != '-' || s[7] != '-')
        return false;
    return true;
}


bool            isDateOnlyDigits(std::string s){
    std::string str1 = s;

    str1.erase(4, 1);
    str1.erase(6, 1);
    
    for(std::size_t i = 0; i < str1.size(); ++i){
        if(!isdigit(static_cast<unsigned char>(str1[i]))){
            return false;
        }    
    }
    return true;
}

bool            isMonthDayValid(std::string s){

    unsigned int    year, month, day;

    parseDateToInteger(s, year, month, day);

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    if (month == 2){
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
            if (day > 29)
                return false;
        } else {
            if (day > 28)
                return false;
        }
    }

    return true;
}

bool isValidFloatFormat(std::string& s) {
    bool decimalPointSeen = false;
    bool negativeSignSeen = false;

    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];

        if (std::isdigit(c)) {
            continue;
        }

        if (c == '.') {
            if (decimalPointSeen)
                return false; 
            decimalPointSeen = true;
        } else if(c == '-'){
            if(negativeSignSeen)
                return false;
            negativeSignSeen = true;
        } else {
            return false;
        }
    }
    return true;
}

bool isFloatPositive(std::string& s){

    float rate = stringToFloat(s);

    if (rate < 0)
        return false;
    return true;
}

bool isFloatWithinRange(std::string& s, int min, int max){
    float value = stringToFloat(s);

    if (value < min || value > max)
        return false;
    return true;
}

float stringToFloat(const std::string& s) {
    std::stringstream ss(s);
    float result;

    ss >> result;
    return result;
}

void parseDateToInteger(const std::string& inputDate, unsigned int& year, unsigned int& month, unsigned int& day) {
    
    std::string yearString = inputDate.substr(0, 4);
    std::string monthString = inputDate.substr(5, 2);
    std::string dayString = inputDate.substr(8, 2);

    year = std::atoi(yearString.c_str());
    month = std::atoi(monthString.c_str());
    day = std::atoi(dayString.c_str());
}

std::string generatePreviousDate(unsigned int year, unsigned int month, unsigned int day) {
     if (day > 1) {
        day -= 1;
    } else if (day == 1 && month != 1) {
        month -= 1;

        if (month == 2) {
      
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                day = 29;
            } else {
                day = 28;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            day = 30; 
        } else {
            day = 31;
        }
    } else if (day == 1 && month == 1) {
        year -= 1;
        month = 12;
        day = 31;
    }

    std::stringstream newFullDate;
    newFullDate << year << "-";
    newFullDate << std::setw(2) << std::setfill('0') << month << "-";
    newFullDate << std::setw(2) << std::setfill('0') << day;

    return newFullDate.str();
}