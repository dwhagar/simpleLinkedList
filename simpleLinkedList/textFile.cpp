/*
 textFile.cpp
 David Wade Hagar
 9/28/2016
 
 CS 216
 Project 1
 textFile Class Definitions
 */

#include <string>
#include "textFile.hpp"
#include "simpleList.hpp"

using namespace std;

/*
 Default constructor for textFile class.
 */
textFile::textFile()
{
    fileName = "";
}

/*
 Constructor that accepts the file name in the object creation.
 */
textFile::textFile(string file)
{
    fileName = file;
}

/*
 Destructor function, no action required at this tiem.
 */
textFile::~textFile()
{
        // Nothing for here.
}

unsigned long textFile::textLines()
{
    return lines.size();
}

/*
 Returns a requested line form a text file.  If the file is out of bounds, it
 returns an empty string.
 */
string textFile::getLine(unsigned long lineNumber)
{
    // Check to make sure we're not going to go out of bounds.
    if (lineNumber < lines.size()) {
        lines.toHead();
        lines.forward(lineNumber);
        return lines.current()->data();
    } else {
        // If the index of lines to return is out of bounds, return an empty
        // string.
        string noData = "";
        return noData;
    }
}

/*
 Writes data into a specific line of the lines vector, replacing that data.
 
 If the lineNumber index argument is greater than is availible, the function
 will silently append the data to prevent crashing from invalid indexes.
 */
void textFile::setLine(unsigned long lineNumber, string data)
{
    if (lines.size() > lineNumber) {
        lines.toHead();
        lines.forward(lineNumber);
        lines.current()->data(data);
    } else {
        lines.toTail();
        lines.current()->data(data);
    }
}

/*
 Inserts a new line into the lines vector with data.
 */
void textFile::insertLine(unsigned long lineNumber, string data)
{
    if (lines.size() > lineNumber) {
        lines.toHead();
        lines.forward(lineNumber);
        lines.insert(data);
    } else {
        // This will add enough lines to get to lineNumber x even if there are
        // not enough lines.
        unsigned long blanks = lineNumber - lines.size();
        if (blanks > 0) {
            string blankString = "";
            for (unsigned int x; x < blanks; x++) {
                lines.append(blankString);
            }
        }
        lines.append(data);
    }
}

/*
 Removes a line from the lines vector.
 */
void textFile::removeLine(unsigned long lineNumber)
{
    lines.toHead();
    lines.forward(lineNumber);
    lines.remove();
}

/*
 Checks to see if the file is good to read/write from.
 */
bool textFile::checkFile()
{
    // Open the file as if we want to read it.
    inputHandle.open(fileName);
    // Check to see if the file access is good.
    bool result = inputHandle.good();
    // Close the file.
    inputHandle.close();
    return result;
}

/*
 Loads data from the file into the object.
 
 An important note, this will strip linebreaks which could cause formatting
 issues in an production application.
 */
void textFile::loadFile()
{
    // Make sure we start with a blank slate, no items in the vector.
    if (lines.size() > 0)
    {
        lines.clear();
    }
    
    // Open up the file for reading.
    string line;
    inputHandle.open(fileName.c_str());
    // Read every line until end of file.
    while (!inputHandle.eof()) {
        getline(inputHandle, line);
        lines.append(line);
    }
    // The last line, if empty, should not be included as it is always
    // blank, though since some editors (or the echo command) will not
    // append an extra CRLF/LF/CR character to the end, one should make
    // sure it is blank before clearing it off.
    if (line == "") {
        lines.toTail();
        lines.remove();
    }
    // Make sure to close the file again.
    inputHandle.close();
}

/*
 Saves all lines in the lines vector to the file.
 */
void textFile::saveFile()
{
    // Open the file for writing, this should erase an exiting file.
    outputHandle.open(fileName.c_str());
    // Write every line from the lines vector into the file, appending
    // a new line to the end of each.
    lines.toHead();
    while (lines.current()->next() == nullptr) {
        outputHandle << lines.current()->data().c_str() << endl;
        lines.forward(1);
    }
    // Make sure to close the file.
    outputHandle.close();
}

/*
 Sets the filename to be worked with.
 
 The object requires a filename, if the object is not created with one it must
 be set.
 */
void textFile::setFile(string file)
{
    fileName = file;
}

/*
 Returns the name of the file being worked with.
 */
string textFile::getFile()
{
    return fileName;
}
