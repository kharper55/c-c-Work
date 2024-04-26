/* ============================================================================
 * bbTicket.hpp                                                 
 * Author: Kevin Harper
 * Date: 04/09/2023
 * Description: This is the hpp file associated with the bbTicket model class.
 *              It describes the private data members of the bbTicket class
 *              and provides prototypes for the class methods outlined in 
 *              bbTicket.cpp
 *
 * Written in C/C++, Ansi-style.
 * See bbTicket.cpp for further explanation of class methods.
 * ========================================================================= */
#pragma once
#include <iostream>
#include <string>

/* ============================================================================
 * class bbTicket                                               
 * Description: Custom class representing some common factors associated with 
 *              the purchase of a ticket for a basketball game.
 * Members: std::string customerName - the name of the owner of a bbTicket object
 *          int customerAge - the age of the owner of a bbTicket object
 *          float ticketPrice - the price of a bbTicket object
 *          bool fanStatus - the fan status of the owner of the bbTicket object
 *                           (determined by bbTicket constructor OR updated
 *                            by calls to the method updateFanStatus())
 *          std::string purchaseDate - the date of purchase of the bbTicket object,
 *                                formatted as "MM/DD/YY"
 * Constructors: default - default class constuctor initializes each member of the
 *                         object with the appropriate default value per type
 *               custom - initializes a bbTicket object with user defined member
 *                        values of the appropriate type
 * Methods: bool isDate()
 *          std::string toString() 
 *          std::string toFile()
 *          void updateFanStatus(int numVisits)
 *          void print()
 * ========================================================================= */
class bbTicket {

private:
  // Class members
  std::string customerName;
  int customerAge;
  float ticketPrice; 
  bool fanStatus;
  std::string purchaseDate;

public:
  // Default class constructor (empty object)
  bbTicket() = default;  
  // Custom class constructor
  bbTicket(std::string initName, int initAge, float initPrice,
           bool initFan, std::string initDate);

  // Class methods
  bool isDate(std::string date);
  std::string toString();
  std::string toFile();
  void updateFanStatus(int numVisits);
  void print();  
};

/* ============================================================================
 *                           ////END FILE////
 * ========================================================================= */