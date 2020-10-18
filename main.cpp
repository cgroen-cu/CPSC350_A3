//main file for a3

#include "delimChecker.h"
//#include "stackTemp.cpp"

int main(int argc, char** argv){
  delimChecker <char> ds1;
  char answer = 'Y';
  string file = "test.txt";
  while (toupper(answer) == 'Y'){
    cout <<"Enter file path: ";
    cin >> file;
    cout << ds1.fileChecker(file) << endl;
    cout << "Do you want to enter another file? (Y/N): ";
    cin >> answer;
  }

}
