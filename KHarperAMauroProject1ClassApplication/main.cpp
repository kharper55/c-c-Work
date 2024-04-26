// 04/20 12:21 AM - Resubmission to phase out inappropriate use of a function
//                  found on the internet.

/* ============================================================================
 * main.cpp                                                 
 * Author: Anthony Mauro and Kevin Harper
 * Date: 04/13/2023
 * Description: This is a program that makes use of a custom C++ class named
 *              bbTicket that stores information about the purchaser of a
 *              ticket to a hypothetical basketball game(s). At the beginning of
 *              execution, the file "input.txt" is read in and its' lines, which
 *              contain comma-separated data members of the bbTicket class, are
 *              used as inputs to a custom class constructor. All of the 
 *              bbTicket objects created from the read-in of "input.txt" are 
 *              appended to a vector. The user is intended to interect with a 
 *              console menu thereafter where they can add to this vector,
 *              search for tickets matching a user-input date in "MM/DD/YY"
 *              format, print out all the bbTickets currently stored in the vector,
 *              or quit. By default, upon quitting, the entries of the vector are 
 *              automatically written to output.txt in the same comma-separated 
 *              format that they were read-in.
 *
 *              It is important that the user-input date strings are formatted 
 *              as MM/DD/YY, since leading zeroes or a year written out fully 
 *              (such as 2023) will cause issues with the bbTicket method 
 *              isDate().
 *
 * Written in C/C++, Ansi-style.
 * ========================================================================= */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "bbTicket.hpp"

#define INFILE_NAME "data3.txt"
#define OUTFILE_NAME "output2.txt"

using namespace std;

bbTicket readFileLine(ifstream &inputFile);

/* ============================================================================
 * main()
 * Return: int, 0 for succesful execution of main()
 * Description: Home block for all function calls, interactive console menu, and
 *              print statements.
 * Parameters: N/A 
 * Locals:
 * ========================================================================= */
int main() {
  
  bool fan;
  string name, age, price, date, pdate, print, stringFan, choice;
  int sum = 0, nameCheck = 0, ageCheck = 0, priceCheck = 0;
  int fanCheck = 0, dateCheck = 0, count = 0;
  ofstream outputFile;
  
  vector <bbTicket> ticketVec;

  ifstream inputFile; 
  inputFile.open(INFILE_NAME);    //Open the input file for reading

  // If the specified input file exists, properly opens, and is not empty,
  // then take the lines of the file and construct new bbTicket class members
  // with them and append them to the ticket vector. peek() method is used
  // so that the character checked is still available to the filestream in the
  // chance that the file is not empty.
  if (inputFile.is_open() && inputFile.peek() != EOF) {
    for (int i = 0; !inputFile.eof(); ++i) {
      ticketVec.push_back(readFileLine(inputFile));
    }
    inputFile.close();
  }
    
  else {
    cout << "Input file failed to open, does not exist, or is empty..." << endl;
  }
  
  cout << "\nWelcome to Basketball Ticket manager "
       << "by Anthony Mauro and Kevin Harper! " << endl;
  cout << "\nUse the menu below to manage tickets: " << endl;

  do {
    cout << endl;
    cout << "Ticket Management System Choices " << endl;
    cout << "1)Add New Ticket " << endl;
    cout << "2)Search tickets wth date " <<endl;
    cout << "3)Print out all tickets " << endl;
    cout << "4)Quit" << endl;
    cout << "Enter 1, 2, 3, or 4" <<endl;
  
    getline(cin, choice);
 
    //////////////////////////MENU OPTION 1 //////////////////////////
    // Add new user input ticket
    if(choice == "1") {
      
      while (nameCheck == 0) {
        
        cout << "Please Enter First Name (exclude symbols): " << endl;
  			getline(cin, name);
        
        for (int i = 0; i < name.size(); i++) {
          if (!((name[i] >= 65 && name[i] <= 90) 
              || (name[i] >= 97 && name[i] <= 122))) {        
            count += 1; 
          }
        }
        
        if (count == 0) nameCheck = 1;
        else {
          cout << "Try again...\n";
          count = 0;
        }
      }
      nameCheck = 0;

      while(ageCheck == 0) {
        
        cout << "Please Enter Age: " << endl;
        getline(cin, age);

        for(int i = 0; i < age.size(); i++){
          if(!(age[i] >= 48 && age[i] <= 57)){
            count += 1;
          }
        }
        
        if (count == 0) ageCheck = 1;
        else {
          cout << "Try again...\n";
          count = 0;
        }
      }
      ageCheck = 0;
      
      while(priceCheck == 0) {
        
        cout << "Please Enter Ticket Price: " << endl << "$";
        getline(cin, price);

        for(int i = 0; i < price.size(); i++){
          if(!((price[i] >= 48 && price[i] <= 57) || price[i] == 46)) {
            count += 1;
          }
        }
        
        if (count == 0) priceCheck = 1;
          else {
            cout << "Try again...\n";
            count = 0;
          }
        }
        priceCheck = 0;

      while(fanCheck == 0){
        
        cout << "Please enter 1 for true or 0"
             << " for false if individual attended more than 3 games: " << endl; 
        getline(cin, stringFan);
          
        for(int i = 0; i < stringFan.size(); i++) {
          if(!(stringFan[i] >= 48 && stringFan[i] <= 49)) {
            count += 1;
          }
        }
        
        if (count == 0) {
          if (stoi(stringFan) == 1) fan = true;
          else fan = false; 
          fanCheck = 1;
        }
        else {
          cout << "Try again...\n";
          count = 0;
        }
      }
      fanCheck = 0;

      while(dateCheck == 0) {
        
        cout << "Please Enter Purchase Date: " << endl;
        getline(cin, date);
       
        for(int i = 0; i < date.size(); i++) {
          // Add one to count if any of the chars are not a digit or '/'
          if(!((date[i] >= 48 && date[i] <= 57) || date[i] == 47)) {
            count += 1;
          }
        }
        
        // This will only execute if any of the user input chars are not ints
        // or '/'
        // We know already that it only contains ints, which is good, but we now
        // check to see if these ints make sense
        if (count == 0) {
          // Split the date at each delimiter '/'
          // Store month, day, and year into each of their own vars (type int)
          // Then use an if statement to check if these new variables' values make
          // logical sense
          int delimPos1 = date.find_first_of(',');
          int delimPos2 = date.find_last_of(',');
          int month = stoi(date.substr(0,delimPos1));
          int day = stoi(date.substr(delimPos1 + 1, delimPos2 - (delimPos1 + 1)));
          int year = stoi(date.substr(delimPos2 + 1, date.size()));

          // Restrict days to 0 --> 31
          // Restrict months to 0 --> 12
          // Restrict years to '00 --> '25
          if (!(year >= 0 && year <= 31) || !(month >= 0 && month <= 12)
              || !(year >= 00 && year <= 25)) {
            count += 1;
          }
        }

        // If count is still equal to zero, we have good data!
        if (count == 0) dateCheck = 1;
        else {
          cout << "Try again...\n";
          count = 0;
        }
      }
      dateCheck = 0;
      
      ticketVec.push_back(bbTicket(name, stof(age), stof(price), fan, date));
    }
    ////////////////////////// END OPTION 1 //////////////////////////

    ////////////////////////// MENU OPTION 2 //////////////////////////
    // Search for tickets with same date as user input date
    if(choice == "2") {
      
      while (dateCheck == 0) {
        cout << "Please enter the date of the tickets you want to see: " << endl;
        getline(cin,date);
        
        for(int i = 0; i < date.size(); i++) {
          // Add one to count if any of the chars are not a digit or '/'
          if(!((date[i] >= 48 && date[i] <= 57) || date[i] == 47)) {
            count += 1;
          }
        }
      // This will only execute if any of the user input chars are not ints
      // or '/'
      // We know already that it only contains ints, which is good, but we now
      // check to see if these ints make sense
        if (count == 0) {
          int delimPos1 = date.find_first_of(',');
          int delimPos2 = date.find_last_of(',');
          int month = stoi(date.substr(0, delimPos1));
          int day = stoi(date.substr(delimPos1 + 1, delimPos2 - (delimPos1 + 1)));
          int year = stoi(date.substr(delimPos2 + 1, date.size()));
  
          // Restrict days to 0 --> 31
          // Restrict months to 0 --> 12
          // Restrict years to '00 --> '25 
          if (!(year >= 0 && year <= 31) || !(month >= 0 && month <= 12)
              || !(year >= 00 && year <= 25)) {
            count += 1;
          }
        }
        if (count == 0) dateCheck = 1;
        else {
          cout << "Try again...\n";
          count = 0;
        }
      }
      // Reset for subsequent executions
      dateCheck = 0;

      // Don't let execution get to this point until we verify the user input date
      // is valid...
      for(int i = 0; i < ticketVec.size(); i++) {
        bool dateCheckX = ticketVec[i].isDate(date);
        
        // Print the vector entry in the case of a match
        if(dateCheckX == true) {
          cout << ticketVec[i].toString() << endl;
          sum += 1;
        }
      }
    
      if(sum == 0) {
        cout << "The date you have entered doesn't match any tickets." << endl;
      }
      //Reset sum for subsequent runs
      sum = 0;
    }
    ////////////////////////// END OPTION 2 //////////////////////////
    
    ////////////////////////// MENU OPTION 3 //////////////////////////
    //Print out all entries in the vector to the console
    if(choice == "3") {
      
      for(int i = 0; i < ticketVec.size(); i++) {
        cout<<ticketVec[i].toString()<<endl;
      }
    }
    ////////////////////////// END OPTION 3 //////////////////////////
    
  } while(choice != "4");

  // Automatically write the vector contents to our output file at the end
  outputFile.open(OUTFILE_NAME);
  
  if(choice == "4") {
    for(int i = 0; i < ticketVec.size(); i++) {
      print = ticketVec[i].toFile();
      outputFile<<ticketVec[i].toFile()<<endl;
    } 
    outputFile.close();
  }
  cout << "\nRemember to brush your teeth!" << endl;

  return 0 ;
}

/* ============================================================================
 * readFileLine()
 * Author: Kevin Harper
 * Return: N/A
 * Description: Creates a bbTicket object from an inputted file line 
 *              (string) with individual members comma delimited as the following:
 *              customerName,customerAge,purchasePrice,fanStatus,purchaseDate
 * Parameters: ifstream &inputFile - location of predeclared input file stream    
 * Locals: string buffer, name, age, date, fan, price - C++ strings acting as
 *         space to read in the comma delimited file line
 * NOTE: All bbTicket members are determined from a master comma-delimited string.
 *       This function splits the master string at the delimiters and stores the 
 *       contents between each delimiter (the bbTicket class members) as a substring,
 *       which is then converted in the return statement to the necessary type using
 *       stof() and stoi() from the string library, as needed. fanStatus is converted
 *       from a string value to a true boolean using an if-else pair.
 * SUBNOTE: The bbTicket class member function toFile() returns a string formatted
 *          precisely as is meant to be read in by this main function. Use a combo
 *          of the two to write to and read from text files in the controller
 *          portion during program execution.
 * ========================================================================= */
bbTicket readFileLine(ifstream &inputFile) {
  string buffer, name, age, date, price;
  bool fan;
  
  getline(inputFile, buffer);
  //Find index of comma delimiters
  int delimPos1 = buffer.find_first_of(',');
  // "+1" ensures the delimiter itself is excluded from the substring
  int delimPos2 = buffer.find_first_of(',', delimPos1+1);
  int delimPos3 = buffer.find_first_of(',', delimPos2+1);
  int delimPos4 = buffer.find_first_of(',', delimPos3+1);

  name = buffer.substr(0, delimPos1);
  age = buffer.substr(delimPos1 + 1, delimPos2 - (delimPos1 + 1));
  price = buffer.substr(delimPos2 + 1, delimPos3 - (delimPos2 + 1));
  fan = stoi(buffer.substr(delimPos3 + 1, delimPos4 - (delimPos3 + 1)));
  date = buffer.substr(buffer.find_last_of(',') + 1, buffer.size());
  
  return bbTicket(name, stoi(age), stof(price), fan, date);
}

/* ============================================================================
 *                           ////END FILE////
 * ========================================================================= */