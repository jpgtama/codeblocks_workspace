#include <iostream>

using namespace std;

enum Token_Type{
    NAME, NUMBER, END, SYMBOL, ERROR
};

// PLUS='+', MINUS='-', MUL='*', DIV='/', PRINT=';', ASSIGN='=', LP='(', RP=')'

// template<class T>
 struct Token{
    Token_Type type;
    void* value;
};

string symbolScope = "+-*/=()";
bool is_Symbol(char& ch);

string numberScope = "0123456789.";
bool is_Number(char& ch);

// TODO use regex to do this namescope
string nameScope = "abc";
bool is_Name(char& ch);

bool is_InScope(string& scope, char& ch);

Token  get_next_token();

int main()
{


    Token t = get_next_token();

    if(t.type == NUMBER){
        double* pnum = (double*)t.value;
        cout<< t.type << ", " << *pnum << endl;
    }else if(t.type == SYMBOL){
        // TODO
    } else if(t.type == NAME){
        // TODO
    }else if(t.type == END){
        // TODO
    }else if(t.type == ERROR){
        // TODO
    }




    return 0;
}

Token  get_next_token(){
    char ch = 0;
    double num;
    string name;

    cin >> ch;

    if(ch == 0){
        Token t = {END, 0};
        return t;
    }else if(is_Symbol(ch)){
        Token t = {SYMBOL, &ch};
        return t;
    }else if(is_Number(ch)){
        cin.putback(ch);
        cin >> num;
        Token  t = {NUMBER, &num};
        return t;
    }else if(is_Name(ch)){
        cin.putback(ch);
        cin >>name;
        Token  t = {NAME, &name};
        return t;
    }else{
        cerr << "invalid input ->: " << ch << endl;
        Token  t = {ERROR};
        return t;
    }

}

bool is_Symbol(char& ch){
    return is_InScope(symbolScope, ch);
    //return symbolScope.find(ch) != string::npos;
}

bool is_Number(char& ch){
    return is_InScope(numberScope, ch);
    //return numberScope.find(ch) != string::npos;
}

bool is_Name(char& ch){
    return is_InScope(nameScope, ch);
    //return nameScope.find(ch) != string::npos;
}

bool is_InScope(string& scope, char& ch){
    return scope.find(ch) != string::npos;
}
