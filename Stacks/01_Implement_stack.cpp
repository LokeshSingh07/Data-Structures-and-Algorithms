// Implementation of Stack
#include<iostream>
using namespace std;

#define MAX 100

class Stack{
  private: 
    int arr[MAX];
    int top;


  public:
    Stack():top(-1){}


    void push(int val){
        if(top == MAX-1){
            cout<<"\nStack overflow";
            return;
        }

        arr[++top] = val;
    }


    int pop(){
        if(top == -1){
            cout<<"\nStack is empty";
            return -1;
        }


        int temp = arr[top];
        top--;
        return temp;
    }

    int peek(){
        if(top == -1) {
            cout<<"\nStack is empty";
            return -1;
        }

        return arr[top];
    }

    bool empty(){
        return top == -1;
    }

    bool full(){
        return top == MAX-1;
    }

    int size(){
        return top+1;
    }

};



int main(){
    Stack st;

    st.push(2);
    cout<<"\nSize: "<<st.size();
    cout<<"\nPeek : "<<st.peek();
    
    st.pop();
    st.pop();
    cout<<"\nisEmpty : "<<st.empty();

    st.push(3);
    cout<<"\nPeek : "<<st.peek();
    
    st.push(4);
    cout<<"\nPeek : "<<st.peek();
    
    st.push(5);
    cout<<"\nPeek : "<<st.peek();

    
    st.push(6);
    cout<<"\nPeek : "<<st.peek();
    
    st.push(7);
    cout<<"\nPeek : "<<st.peek();
    cout<<"\nSize : "<<st.size();




return 0;
}









// GFG -> Implement stack using array
class MyStack {
  public:
    #define MAX 100
    
    int arr[MAX];
    int top =-1;
    
    void push(int x) {
        if(top == MAX-1) return;
        
        top++;
        arr[top] = x;
    }

    int pop() {
        if(top == -1) return -1;
        
        int temp = arr[top];
        arr[top] = -1;
        top--;
        return temp;
    }
};