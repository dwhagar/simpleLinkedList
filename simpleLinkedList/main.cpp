/*
 Simple Linked List Implementation
 by David Wade Hagar
 September 30th, 2016
 
 This work and all associated files is coverde by the Creative Commons 3.0
 Attribution (BY) license.  Full license text can be found in the LICENSE file
 which should accompany this work.  It can also be located at:
 https://creativecommons.org/licenses/by/3.0/us/
 
 This project is kept on GitHub at the URL:
 https://github.com/dwhagar/simpleLinkedList
 
 Read the README.md file for more information.
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include "textFile.hpp"

using namespace std;

void displayHelp();
bool isInteger(const string &s);
bool askSave();

int main(int argc, const char * argv[]) {
    int resultCode = 0;
    
    // Convert to a vector.
    vector<string> args(argv, argv + argc);
    
    // Process arguments, must be 1 argument, otherwise exit with code 1.
    if (args.size() < 2) {
        cout << "Missing command line argument!" << endl;
        cout << "Usage: ./myEditor <input text filename>" << endl;
        resultCode = 1;
    } else {
        string fileName = args[1];
        textFile dataFile(fileName);
        
        // Check if the file is ok to use, if it is, lets go.
        if (!dataFile.checkFile()) {
            resultCode = 2;
        } else {
            // We can now assume the file is good, so we can work with it.
            dataFile.loadFile();
            
            // Display some text to help the user.
            displayHelp();
            
            // Now get user input.
            bool done = false;
            string userInput = "";
            
            while (!done) {
                cout << "> ";
                getline(cin, userInput);
                
                char cmd = tolower(userInput.c_str()[0]);
                char cmd2 = ' ';
                if (userInput.size() > 1) {
                    cmd2 = userInput.c_str()[1];
                }
                
                // This check makes sure the command format is correct
                // so that commands don't fire off by mistake.
                if (strncmp(&cmd, " ", 1) != 0 && strncmp(&cmd2, " ", 1) == 0) {
                    switch(cmd) {
                        case 'q': {
                            done = true;
                            break;
                        }
                        case 'i': {
                            unsigned long lineIndex = dataFile.textLines() + 1;
                            string newLine;
                            if (userInput.size() > 1) {
                                string cmdArg = userInput.substr(2);
                                lineIndex = stol(cmdArg);
                            }
                            cout << to_string(lineIndex) << "> ";
                            getline(cin, newLine);
                            dataFile.insertLine(lineIndex - 1, newLine);
                            break;
                        }
                        case 'd': {
                            if (userInput.size() > 1) {
                                unsigned long lineIndex;
                                string cmdArg = userInput.substr(2);
                                lineIndex = stol(cmdArg);
                                dataFile.removeLine(lineIndex - 1);
                            }
                            break;
                        }
                        case 'l': {
                            for (int x = 0; x < dataFile.textLines(); x++) {
                                cout << to_string(x + 1) << "> " << dataFile.getLine(x) << endl;
                            }
                            break;
                        }
                        case 'h': {
                            displayHelp();
                            break;
                        }
                        case 's': {
                            dataFile.saveFile();
                            break;
                        }
                    }
                }
            }
            
            // Ask about saving the file before exiting.
            bool save = askSave();
            if (save) {
                dataFile.saveFile();
            }
            cout << "Thank you for using myEditor." << endl;
        }
    }
    
    return resultCode;
}

/*
 Asks the user if they'd like to save or not, returns true if they do.  Anything
 other than "y" or "Y" will be interpreted as a negative answer.
 */
bool askSave()
{
    bool result = false;
    string userInput = "";
    cout << "Do you wan to save the change? (Y - yes; N - no) ";
    getline(cin, userInput);
    userInput = tolower(*userInput.c_str());
    if (strncmp(userInput.c_str(), "y", 1) == 0) {
        result = true;
    }
    return result;
}

/*
 Displays help text.
 */
void displayHelp()
{
    cout << "Welcome to my text editor." << endl;
    cout << "\tTo insert text at the end of the file, type 'I'" << endl;
    cout << "followed by the text." << endl;
    cout << "\tTo insert text at a certain line number, type 'I'" << endl;
    cout << "followed by a space and the desired line number." << endl;
    cout << "\tTo delete a line, type 'D' followed by a space and the" << endl;
    cout << "line number." << endl;
    cout << "\tTo print all the lines, type 'L' and press enter." << endl;
    cout << "\tTo save the current content, type 'S' and press enter." << endl;
    cout << "\tTo display this introduction, type 'H' and press" << endl;
    cout << "enter." << endl;
    cout << "\tTo quit, type 'Q' and press enter." << endl;
}

/*
 Checks to see if a stirng is an integer, returns true if the string is an
 integer, returns false it it is not.
 */
bool isInteger(const string &s)
{
    char *p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}
