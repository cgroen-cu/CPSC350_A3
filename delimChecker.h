//delimChecker.h
//Header file for the main class that checks the deliminators

#include "stackTemp.h"
using namespace std;

template <class T>
class delimChecker{
  public:
    //Constructos
    delimChecker(); //Default
  //  delimChecker(string filename);  //Overload for file input
    //Stacks
    GenStack <char> symbolStack;  //Stack for holding the symbols (in chars)
    GenStack <int> locationStack;  //stack for holding the symbol locations (in ints)
    GenStack <int> lineStack; //stack for holding line number
    GenStack <char> backStack; //stack for holding all deliminators not just open


    //Methods
    string fileChecker(string file);

  private:
    string file;
    int lineNum;
    string line = "";

};

//Constructors
//Default
template <class T>
delimChecker<T>::delimChecker(){
  file = "test.txt";
  lineNum = 0;
}
// //Overload
// template <class T>
// delimChecker<T>::delimChecker(string filename){
//   file = "test.txt";
//   lineNum = 0;
// }
template <class T>
string delimChecker<T>::fileChecker(string file){
  //string for output
  string output = "All deliminators are correct";
  //Openfile
  ifstream myfile;
  myfile.open (file);
  cout << "Opening file: " << file << endl;
  cout << "check deloiminators..." << endl;

  //Iterate through the lines of the fle
  while (getline (myfile,line)){
    ++lineNum;

    //iterate through each line
    for (int i = 0; i < line.size()-1; ++i){
      //Check to see if it is a comment
      if(line[i-1] == '/' && line[i] == '/'){
        //cout << "ggI-1: " << line[i-1] << "and i: " << line[i] << endl;
        i = line.size();
      } else {
        //cout << "I-1: " << line[i-1] << "and i: " << line[i] << endl;
        //If the charcter is an open bracket
        //Then add it to the stack, and its location
          if (line[i] == '{' || line[i] == '(' || line[i] == '['){
            //cout << "found deliminator: '"<< line[i] << "' at: " << i << endl;
            symbolStack.push(line[i]); //push the symbol onto the symbol stack
            locationStack.push(i); //push the symbol's location onto the location stack
            lineStack.push(lineNum);  //push the line number of symbol to line stack
            backStack.push(i); //push symbol on backup stack
          }
      //But if the character is a closed bracket
      //Then check its location and see if it is an error or can be popped
      //Chceks each symbol 1 by 1
      //They are all the same, however
          else if (line[i] == '}'){
            //cout << "found deliminator: '"<< line[i] << "' at: " << i << endl;
            //cout << locationStack.peek() << endl;
      //Needs to check to see if previous symbol is the correct opening
            if (symbolStack.peek() == '{'){
      //Then checks if they are on the same line
              if (lineNum == lineStack.peek()){
                //cout << "same line" << endl;
                symbolStack.pop();
                locationStack.pop();
                lineStack.pop();
              }
      //Then checks to make sure it is at correct index - Correct one
              else if (locationStack.peek() == i+2){
                //cout << "I: " << i <<  " n previous: " << locationStack.peek() << endl;
                //cout << "found correct symbol" << endl;
                symbolStack.pop();
                locationStack.pop();
                lineStack.pop();
              }
      //Then checks to see if it is place farther ahead
              else if (locationStack.peek() > i+2){
                //cout << "I: " << i <<  " n previous: " << locationStack.peek() << endl;
                cout << "\nERROR at line " << lineNum << ", index: " << i << ": '" << line[i] << "'\n";
                cout << "Could not find closing symbol for " << symbolStack.pop() << "' in line: " << lineStack.pop() << ", at index: " << locationStack.pop() << endl;
                return "";
              }
      //Then if itstill isnt correct
              else {
                //cout << "I: " << i <<  " n previous: " << locationStack.peek() << endl;
                cout << "\nERROR at line " << lineNum << ", index: " << i << ": '" << line[i] << "'\n";
                cout << "Could not find opening symbol" << endl;
                return "";
              }

            }
      //If it is not the correct opening symbol type for it
            else {
              cout << "Could not find closing symbol for " << symbolStack.pop() << "' in line: " << lineStack.pop() << ", at index: " << locationStack.pop() << endl;
              return "";
            }
            backStack.push(i); //push symbol on backup stack
          }
          else if (line[i] == ')'){
            //cout << "found deliminator: '"<< line[i] << "' at: " << i << endl;
            //cout << locationStack.peek() << endl;
      //Needs to check to see if previous symbol is the correct opening
            if (symbolStack.peek() == '('){
      //Then checks if they are on the same line
              if (lineNum == lineStack.peek()){
                //cout << "same line" << endl;
                symbolStack.pop();
                locationStack.pop();
                lineStack.pop();
              }
      //Then checks to make sure it is at correct index - Correct one
              else if (locationStack.peek() == i+2){
                //cout << "I: " << i <<  " n previous: " << locationStack.peek() << endl;
                //cout << "found correct symbol" << endl;
                symbolStack.pop();
                locationStack.pop();
                lineStack.pop();
              }
      //Then checks to see if it is place farther ahead
              else if (locationStack.peek() > i+2){
                //cout << "I: " << i <<  " n previous: " << locationStack.peek() << endl;
                cout << "\nERROR at line " << lineNum << ", index: " << i << ": '" << line[i] << "'\n";
                cout << "Could not find closing symbol for " << symbolStack.pop() << "' in line: " << lineStack.pop() << ", at index: " << locationStack.pop() << endl;
                return "";
              }
      //Then if itstill isnt correct
              else {
                //cout << "I: " << i <<  " n previous: " << locationStack.peek() << endl;
                cout << "\nERROR at line " << lineNum << ", index: " << i << ": '" << line[i] << "'\n";
                cout << "Could not find opening symbol" << endl;
                return "";
              }

            }
      //If it is not the correct opening symbol type for it
            else {
              cout << "Could not find closing symbol for " << symbolStack.pop() << "' in line: " << lineStack.pop() << ", at index: " << locationStack.pop() << endl;
              return "";
            }
            backStack.push(i); //push symbol on backup stack
          }
          else if (line[i] == ']'){
            //cout << "found deliminator: '"<< line[i] << "' at: " << i << endl;
            //cout << locationStack.peek() << endl;
      //Needs to check to see if previous symbol is the correct opening
            if (symbolStack.peek() == '['){
      //Then checks if they are on the same line
              if (lineNum == lineStack.peek()){
                //cout << "same line" << endl;
                symbolStack.pop();
                locationStack.pop();
                lineStack.pop();
              }
      //Then checks to make sure it is at correct index - Correct one
              else if (locationStack.peek() == i+2){
                //cout << "I: " << i <<  " n previous: " << locationStack.peek() << endl;
                //cout << "found correct symbol" << endl;
                symbolStack.pop();
                locationStack.pop();
                lineStack.pop();
              }
      //Then checks to see if it is place farther ahead
              else if (locationStack.peek() > i+2){
                //cout << "I: " << i <<  " n previous: " << locationStack.peek() << endl;
                cout << "\nERROR at line " << lineNum << ", index: " << i << ": '" << line[i] << "'\n";
                cout << "Could not find closing symbol for " << symbolStack.pop() << "' in line: " << lineStack.pop() << ", at index: " << locationStack.pop() << endl;
                return "";
              }
      //Then if itstill isnt correct
              else {
                //cout << "I: " << i <<  " n previous: " << locationStack.peek() << endl;
                cout << "\nERROR at line " << lineNum << ", index: " << i << ": '" << line[i] << "'\n";
                cout << "Could not find opening symbol" << endl;
                return "";
              }

            }
      //If it is not the correct opening symbol type for it
            else {
              cout << "Could not find closing symbol for " << symbolStack.pop() << "' in line: " << lineStack.pop() << ", at index: " << locationStack.pop() << endl;
              return "";
            }
            backStack.push(i); //push symbol on backup stack
          }
      }

    }

  }
  //Close File
  myfile.close();
  if (symbolStack.isEmpty()){
    return output;
  } else {
    cout << "\nERROR \nCould not find closing symbol for '" << symbolStack.pop() << "' in line: " << lineStack.pop() << ", at index: " << locationStack.pop() << endl;
    return "";
  }

}
