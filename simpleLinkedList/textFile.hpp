/*
 textFile.hpp
 David Wade Hagar
 9/28/2016
 
 CS 216
 Project 1
 textFile Class Declarations
 */
#ifndef textFile_hpp
#define textFile_hpp

#include <string>
#include <fstream>
#include "simpleList.hpp"

namespace std {
    using namespace std;

    // Define a class to hold our text file data.
    // This class will manage our text file and operate save/load functions.
    class textFile {
    private:
        simpleList<string> lines;   // Stores all lines of the file.
        string fileName;    // The name of the file being accessed.
        ifstream inputHandle;   // File object for reading data from the file.
        ofstream outputHandle;  // File object for writing data to the file.
    public:
        textFile(); // Default Constructor
        textFile(string file);  // Constructor
        ~textFile();    // Destructor
        unsigned long textLines();  // Size of the text file in # of lines.
        string getLine(unsigned long lineNumber);   // One line of text from the file.
        void setLine(unsigned long lineNumber, string data);    // Sets a specific line to a new value.
        void insertLine(unsigned long lineNumber, string data); // Inserts a line into the file.
        void removeLine(unsigned long lineNumber);  // Removes a line from the file.
        bool checkFile();   // Checks to see if a file is good.
        void loadFile();    // Loads all the data into the object of the text file in question.
        void saveFile();    // Saves all the data in the object back to its file.
        void setFile(string file);  // Allows setting of the file name after object creation.
        string getFile();   // Returns the name of the file being worked with.
    };
}

#endif /* textFile_hpp */
