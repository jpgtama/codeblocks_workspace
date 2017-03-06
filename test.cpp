#include <iostream>

using namespace std;

enum Token_Type{
    NAME, NUMBER, END, SYMBOL, ERROR
};

// PLUS='+', MINUS='-', MUL='*', DIV='/', PRINT=';', ASSIGN='=', LP='(', RP=')'


template<class T> struct Token{
    Token_Type type;
    T value;
};



int main()
{


    Token<double> t = {NUMBER, 2323.234};

    cout<< t.type << ", " << t.value << endl;

    string symbol = "+-*/";

    bool found = symbol.find('+') != string::npos;

    cout << "find: " << found << endl;

    return 0;
}

Token  get_next_token(){
    char ch = 0;
    double num;
    string name;

    cin >> ch;

    if(ch == 0){
        return Token<int> t = {END, 0};
    }else if(is_Symbol(ch)){
        return Token<char>t = {SYMBOL, ch};
    }else if(is_Number(ch)){
        cin.putback(ch);
        cin >> num;
        return Token<double> t = {NUMBER, num};
    }else if(is_Name(ch)){
        cin.putback(ch);
        cin >>name;
        return Token<string> t = {NAME, name};
    }else{
        cerr << "invalid input ->: " << ch << endl;
        return Token<void> t = {ERROR};
    }

}
