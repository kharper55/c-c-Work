/* ============================================================================
 * bbTicket.cpp                                                 
 * Author: Kevin Harper
 * Date: 04/09/2023
 * Description: This is the cpp file associated with the bbTicket model class.
 *              It contains the descriptions and definitions of the methods 
 *              available to the user for the bbTicket class.
 *
 * Written in C/C++, Ansi-style.
 * See bbTicket.hpp for further explanation of data members.
 * ========================================================================= */
#include <string>
#include "bbTicket.hpp"
#include <sstream> //for std::stringstream

/* ============================================================================
 * bbTicket()  
 * Return: N/A
 * Description: Custom constructor for model class.
 *              Initializes bbTicket object with customer name, age, price paid,
 *              their status as a fan or not, and the date of purchase.
 * ========================================================================= */
bbTicket::bbTicket(std::string initName, int initAge, float initPrice, 
                   bool initFan, std::string initDate) {
  customerName = initName;
  customerAge = initAge;
  ticketPrice = initPrice;
  fanStatus = initFan;
  purchaseDate = initDate;
}

/* ============================================================================
 * isDate()
 * Return: boolean
 * Description: Determines whether or not the date of a certain bbTicket object
 *              matches the date provided as an argument. 
 * Parameters: string date - a date string formatted as "MM/DD/YY"
 * Locals: bool dateMatch - boolean, declared as false and changed to true if
 *                          a match of the two dates occurs
 * NOTE: Caution should be taken to ensure that the input date format matches 
 *       the expected format described in bbTicket.hpp.
 * ========================================================================= */
bool bbTicket::isDate(std::string date) { 
  bool dateMatch = false;
  if (date == purchaseDate) dateMatch = true;
  
  return dateMatch;
}

/* ============================================================================
 * toString()
 * Return: string
 * Description: Declares necessary string literals and formats a return string
 *              for console printing, containing the private members of an 
 *              instance of the bbTicket class. 
 * Parameters: N/A
 * Locals: std::string info0,info1,info2 - simple static string literals used to
 *                                    construct a human-readable sentence.
 *         std::string isFan - set with an if-else pair to properly convey
 *                       the member tickets' associated individual as a fan
 * ========================================================================= */
std::string bbTicket::toString() {
  std::string info0 = " is ";
  std::string info1 = " and paid $";
  std::string info2 = " for tickets on ";
  std::string isFan;
  if (fanStatus == 0) isFan = " They are not a fan.";
  else isFan = " They are a fan!";

  //Adopted from https://www.geeksforgeeks.org/convert-float-to-string-in-cpp/
  //Stringstream workaround for imprecise floating point monetary values.
  //Ideally, we would use a fixed point type from the get go.
  std::stringstream s;
  s << ticketPrice;
  std::string result = s.str();
  
  return customerName + info0 + std::to_string(customerAge) + info1 
                      + result + info2 
                      + purchaseDate + "." + isFan; 
}

/* ============================================================================
 * toFile()
 * Return: string
 * Description: Returns a subjectively formatted, CSV string containing the 
 *              private members of a bbTicket instance for placement on a txt 
 *              file line.
 * Parameters: N/A
 * Locals: N/A
 * ========================================================================= */
std::string bbTicket::toFile() {
  //Adopted from https://www.geeksforgeeks.org/convert-float-to-string-in-cpp/
  //Stringstream workaround for imprecise floating point monetary values.
  std::stringstream s;
  s << ticketPrice;
  std::string result = s.str();
  
  return customerName + "," + std::to_string(customerAge) 
                      + "," + result
                      + "," + std::to_string(fanStatus)
                      + "," + purchaseDate;
}

/* ============================================================================
 * updateFanStatus()
 * Return: N/A
 * Description: Update fan status to true according to the total number of visits
 *              they claim to have made to various basketball games for the venue
 *              or team of interest.
 * Parameters: N/A
 * Locals: N/A
 * ========================================================================= */
void bbTicket::updateFanStatus(int numVisits) {
  // Update fan status to true if they've been 3 or more times
  if (numVisits >= 3) fanStatus = true;
  
}

/* ============================================================================
 * print()
 * Return: N/A
 * Description: Prints the return string of toString() immediately.
 * Parameters: N/A
 * Locals: N/A
 * ========================================================================= */
void bbTicket::print() {
  std::string printTicket = bbTicket::toString();
  std::cout << printTicket << std::endl;
}

/* ============================================================================
 *                           ////END FILE////
 * ========================================================================= */