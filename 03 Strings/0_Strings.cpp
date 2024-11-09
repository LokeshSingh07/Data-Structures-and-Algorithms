#include<iostream>
using namespace std;


int main(){
/*
    string name;
    // cin>>name;
    getline(cin, name);

    cout<<"Prinitng name : "<<name<<endl;  

    // cout<<"Printing first character : "<<name[0]<<endl;
    int i = 0;
    while(name[i] != '\0'){
        cout<<"index : "<<i<<" character : "<<name[i]<<endl;
        i++;
    }

    cout<<"Printing the index 5 : "<<name[5]<<endl;
    int value = (int)name[5];
    cout<<"Printing the ASCII value of character at index 5 : "<<value<<endl;
*/


    string str;
    cout<<"Input : ";
    getline(cin, str);

    cout<<"\nLength of string : "<<str.length();
    cout<<"\nLength of string : "<<str.size();
    cout<<"\nString is empty or not : "<<str.empty();
    
    cout<<"\n\nAccess element using at() : "<<str.at(2);
    cout<<"\nFront element : "<<str.front();
    cout<<"\nBack element : "<<str.back();



    // Append
    string s1 = "lokesh ";
    string s2 = "singh";
    cout<<"\n\nBefore appending : "<<s1<<" , "<<s2;

    s1.append(s2);
    cout<<"\nAfter appending : "<<s1<<" , "<<s2;


    // erase(index, len)
    string s3 = "love youu babe";
    s3.erase(5, 3);
    cout<<"\nAfter erase() : "<<s3;


    // Insert(index,  str)
    string s4 = "love you";
    s4.insert(5, "babe");
    cout<<"\nAfter insert() : "<<s4;


    // push_back() & pop_back()
    string s5 = "love";
    s5.push_back('y');
    cout<<"\nAfter push_back() : "<<s5;
    s5.pop_back();
    cout<<"\nAfter pop_back() : "<<s5;


    // Find() 
    string s6 = "aar tera super star desi kalakaar";
    if(s6.find("super") !=  string::npos){
        cout<<"\n'Found.";
    }
    else{
        cout<<"\n'Not found.";
    }


    // compare()     0, -1, 1
    string s7 = "love you";
    string s8 = "love youu";
    if(s7.compare(s8) == 0){
        cout<<"\nBoth strings are equal.";
    }
    else if(s7.compare(s8) == -1){
        cout<<"\nString s7 is smaller.";
    }
    else{
        cout<<"\nString s8 is smaller.";
    }
    

    // substr(start, len)
    string s9 = "love you";
    string s10 = s9.substr(5, 3);
    cout<<"\nAfter substr() : "<<s10;





return 0;
}