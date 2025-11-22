#include<iostream>
#include<array>
using namespace std;
//WARNING THIS CONTAINER TEMPLATE DOES NOT CHECK BOUNDS LIMITS OF INDEX
//Purpose to use all Functions of Array
 void arrayDeclarationAndInitialization(){
    const int size=5;
    array<int,size> T={1,2,3,4,5};
    cout<<"[";
    for(int index=0;index<T.size();index++)//This template has overloaded [] operator to access index
    {//With additional feature of .size() to get size of array
        cout << T[index] << (index < T.size() - 1 ? "," : "");
    }
    cout<<"]"<<endl;
 }
 
 int main(){
    arrayDeclarationAndInitialization();
    //Using every member function of array Template Conatiner
    array <int,10>Test={1,2,3,4,5,6,7,8,9,0};

    //at() returns a refernce to the element at specified location index with bounds checking
cout<<"Using size() and at() funttions:";
    cout<<"[";
    for(int index=0;index<Test.size();index++)//This template has overloaded [] operator to access index
    {//With additional feature of .size() to get size of array
        cout << Test.at(index) << (index < Test.size() - 1 ? "," : "");
    }
    cout<<"]"<<endl;

    //Using back and begin funtion to get reference to first and last value in the  array
     // Create an iterator for the array object.
       array<int, 10>::iterator it;
 cout<<"Using iterator even though nobody uses it:";
         array<int, 10>::const_iterator cit ;
      // Display the names.
         cout<<"[";
       for (it = Test.begin(); it != Test.end(); it++)
           cout << *it <<(it<Test.end()-1?",":"");
           cout<<"]"<<endl;
cout<<"Using constant iterator:";
           cout<<"[";
   for( cit = Test.cbegin(); cit != Test.cend(); ++cit){
    cout << *cit<<(cit<Test.cend()-1?",":"");
   }cout<<"]"<<endl;
   array<int,10>::reverse_iterator rit;
   cout<<"Using rend and rbegin to print array in reverse:";
   cout<<"[";
   for(rit=Test.rend();rit!=Test.rbegin();rit--)
   {
    cout<<*rit<<(rit<Test.crbegin()?",":"");
    
   }
   cout<<"]"<<endl;
   cout<<"Using Empty() function to check whether Test Array is empty or not.I already lmow its not empty"<<endl;
   cout<<"Test array is empty:";
   Test.empty()?cout<<"True":cout<<"False";
   cout<<Test.empty();//returns 0 not false but both are same


       return 0;

 }