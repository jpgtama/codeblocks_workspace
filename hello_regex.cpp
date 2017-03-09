#include <iostream>
#include <regex>


using namespace std;

int main()
{
    regex pattern("\\w");


    cout << "regex match: " << regex_search('+', pattern) << endl;

    return 0;
}
