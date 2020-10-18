//stackTemp.h
//Header file for stack template

#include <iostream>  //pre-processor directive
#include <fstream>    //file IO
using namespace std;

template <class T>
class GenStack {
  public:
    //Constructors
    //Default
    GenStack();
    //Overload
    GenStack(int maxSize);
    //methods
    T push(T data);
    T pop();
    T peek();
    //Misc methods
    bool isFull();
    bool isEmpty();
    int getSize();

  //main elements
    int top;
    int mSize;
    T *myArray;
};

template<class T>
GenStack<T>::GenStack(){
  mSize = 128;
  top = -1; //Set to negative one, so with pre-increment on push it will go to 0
  myArray = new T[mSize];
}
template<class T>
GenStack<T>::GenStack(int maxSize){
  mSize = maxSize;
  top = -1;
  myArray = new T[maxSize];
}


//Method Implementation
//Main methods
//Push
template <class T>
T GenStack<T>::push(T data){
  //Check if Full before proceeding
  //cout << "pushing: " << data << endl;
  if (this->isFull()){
    //make Bigger
    int oldMax = mSize;
    mSize *= 2;
    //creating larger array
    T *newArray = new T[mSize];
    //copy over
    for (int i = 0; i < oldMax; ++i){
      newArray[i] = myArray[i];
    }
    //Reassign new array to main array
    myArray = newArray;

    //Finish the push
    myArray[++top] = data;
  } else {
    //cout << "not full" << endl;
    myArray[++top] = data;
    //cout << top << endl;
  }
}
//Pop method
template <class T>
T GenStack<T>::pop(){
  //Check if empty
  if(this->isEmpty()){
    cout << "empty" << endl;
  } else {
    return myArray[top--];
  }
}
template <class T>
T GenStack<T>::peek(){
  //Check if Empty
  if(this->isEmpty()){
    cout << "empty" << endl;
  } else {
    //cout << "is not empty" << endl;
    return myArray[top];
  }
}
//MISC METHODs
//Check if full
template <class T>
bool GenStack<T>::isFull(){
  return (top == mSize-1);
}
//Check if empty
template <class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}
//Return the current size of the array
template <class T>
int GenStack<T>::getSize(){
  return int(top+1);
}
