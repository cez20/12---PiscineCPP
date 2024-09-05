#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{

}

// BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
// {

// }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{

}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/

void			BitcoinExchange::mapBitcoinDatabase(std::ifstream & btc_database) {
	std::string line;

	std::getline(btc_database, line);
	while (std::getline(btc_database, line)) { 
        std::stringstream ss(line);
        std::string file_date, file_exchange_rate;

        // Get the first part (before the comma)
        if (std::getline(ss, file_date, ',')) {
            std::getline(ss, file_exchange_rate);
			bitcoin_map.insert(std::make_pair(file_date, std::stod(file_exchange_rate))); //TODO: validate std::stod can be used
        } else {
            std::cerr << "Delimiter(comma) not found in the line: " << line << std::endl;
        }
    }
}

void            BitcoinExchange::findBitcoinData(std::ifstream & second_database) {
    std::string line;
    
    while(std::getline(second_database, line)) {
        size_t delimiter_pos = line.find('|');

        if (delimiter_pos != std::string::npos){
            std::string date_to_find = line.substr(0, delimiter_pos);
            std::string nbr_of_bitcoins = line.substr(delimiter_pos + 1);

            trim_right_spaces(date_to_find);
            trim_left_spaces(nbr_of_bitcoins);

            // Check if the date exists in the map
            std::map<std::string, double>::iterator it = bitcoin_map.find(date_to_find);
            if (it != bitcoin_map.end()) {
                std::cout << it->first << " => " << nbr_of_bitcoins << " = "
                        << (std::stod(nbr_of_bitcoins) * it->second) << std::endl;
            } else {
                std::cerr << "ERROR! Cannot find the date in file" << std::endl;
            }
        } else {
            std::cerr << "ERROR! Delimiter missing or improperly formatted line" << std::endl;
        }
    }
}


void	BitcoinExchange::printMap(){
	std::map<std::string, double>::iterator it;

	for(it = bitcoin_map.begin(); it != bitcoin_map.end(); ++it){
		std::cout << std::fixed << std::setprecision(2) << it->first << " | " << it->second << std::endl;
	}
}

/*
** --------------------------------- OTHER ---------------------------------
*/

std::string::iterator find_first_letter(std::string & s){
    std::string::iterator it;

    for(it = s.begin(); it != s.end(); ++it){
        if (!std::isspace(static_cast<unsigned char>(*it)))
            return(it);
    }
    return s.end();
}

std::string::iterator find_first_space(std::string & s){
    std::string::iterator it;

    for(it = s.begin(); it != s.end(); ++it){
        if (std::isspace(static_cast<unsigned char>(*it)))
            return(it);
    }
    return s.end();
}

std::string trim_left_spaces(std::string & s){
    s.erase(s.begin(), find_first_letter(s));
    return (s);
}

std::string trim_right_spaces(std::string & s){
    s.erase(find_first_space(s), s.end());
    return(s);
}


/* ************************************************************************** */