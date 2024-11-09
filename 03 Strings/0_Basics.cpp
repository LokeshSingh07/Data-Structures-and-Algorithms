#include<iostream>
#include<string.h>
using namespace std;


int findLength(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }

    return i;
}

void reverse(char str[], int length){
    int s=0;
    int e=length-1;

    while(s<e){
        swap(str[s], str[e]);
        s++;
        e--;
    }
}

void convertToUppercase(char str[]){
    int i = 0;
    while(str[i] !='\0'){
        char ch = str[i];
        if(ch>='a' && ch<='z'){
            str[i] = ch - 'a' + 'A';    // LC -> UC
        }
        i++;
    }
}

void replacewithSpace(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        char ch = str[i];
        if(ch == '@') str[i] = ' ';
        i++;
    }
}

bool isPalindrome(char str[]){
    int length = findLength(str);
    int s=0;
    int e=length-1;

    while(s<e){
        if(str[s] != str[e]) return false;
        s++;
        e--;
    }
    return true;
}



int main(){
/*
    char ch[10];
    cout<<"Enter the str : ";
    cin>>ch;
    cout<<"Printing the value of ch : "<<ch<<endl;

    for(int i=0; i<10; i++) cout<<"At index : "<<i<<" "<<ch[i]<<endl;

    // Wanna print the NULL char
    char temp = ch[6];
    int value = (int)temp;
    cout<<"Printing (ASCII) integer value : "<<value<<endl;

    
    // taking input that contains spaces, tab       --  Delimeter
    char sent[100];
    cin.getline(sent, 100);
    cout<<"Printing the value of sent : "<<sent<<endl;
*/


    // Length of String
    char str[100];
    // cin>>str;
    cin.getline(str, 100);
    int len = findLength(str);
    cout<<"Length of the string is : "<<len<<endl;
    cout<<"Length of the string is : "<<strlen(str)<<endl;      // inbuit
    

    // reverse of a string
    char str2[] = "singh";
    reverse(str2, len);
    cout<<"String  after reversing : "<<str<<endl;


    // convert to uppercase
    char  str3[] = "My name is Singh";
    convertToUppercase(str3);
    cout<<"String after converting to uppercase : "<<str3<<endl;


    // replace @ with space
    char str4[] = "My@name@is@Singh";
    replacewithSpace(str4);
    cout<<"String after replacing @ with space : "<<str4<<endl;


    // check palindrome
    char str5[] = "racecar";
    cout<<"Is string a palindrome : "<<isPalindrome(str5)<<endl;




 

return 0;
}