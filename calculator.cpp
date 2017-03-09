#include <iostream>
#include <string>
#include <regex>

using namespace std;

enum Token_Type{
    NAME, NUMBER, SYMBOL, END,  ERROR
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
regex nameRegex("\\w+");

bool is_Name(char& ch);

bool is_InScope(string& scope, char& ch);

Token  get_next_token();

bool isLoweercase(char& ch){
    return (ch >= 'a' && ch <= 'z');
}


bool isUppercase(char& ch){
    return (ch >= 'A' && ch <= 'Z');
}

int main()
{

//    char ch[] = {'a', 0};
//
//    cout << ch << endl;


    char ch;
    while(cin){
        cin >> ch;

        if(ch == '0'){
            break;
        }else{
//            cout << "is lower case: " << isLoweercase(ch) << endl;
//            cout << "is upper case: " << isUppercase(ch) << endl;
              cout << "is name: " << is_Name(ch) << endl;
        }
    }






//
//    Token t = get_next_token();
//
//    if(t.type == NUMBER){
//        double* pnum = (double*)t.value;
//        cout<< t.type << ", " << *pnum << endl;
//    }else if(t.type == SYMBOL){
//        // TODO
//    } else if(t.type == NAME){
//        // TODO
//    }else if(t.type == END){
//        // TODO
//    }else if(t.type == ERROR){
//        // TODO
//    }




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
    char str[] = {ch, 0};
    return regex_match(str, nameRegex);
//    return nameScope.find(ch) != string::npos;
}

bool is_InScope(string& scope, char& ch){
    return scope.find(ch) != string::npos;
}
