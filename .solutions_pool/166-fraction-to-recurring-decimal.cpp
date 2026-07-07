#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    string result;
    
    if (denominator == 0){ return result; }
    if (numerator == 0) { return "0"; }

    
    long long n = numerator;
    long long d = denominator;

    
    bool sign = ((float)numerator/denominator >= 0);
    if ( n < 0 ){ n = -n; }
    if ( d < 0 ){ d = -d; }
    if (sign == false){
        result.push_back('-');
    }

    long long remainder = n % d;
    long long division = n / d;
    ostringstream oss;
    oss << division;
    result += oss.str();
    if (remainder == 0){
        return result;
    }
    
    result.push_back('.');

    
    
    
    
    map<long long, int> rec;

    for (int pos=result.size(); remainder!=0; pos++, remainder=(remainder*10)%d ) {
        if (rec.find(remainder) != rec.end()) {
            result.insert(result.begin()+rec[remainder], '(');
            result.push_back(')');
            return result;
        }
        rec[remainder] = pos;
        result.push_back((remainder*10)/d + '0');
    }

    return result;
}

void test(int num, int deno)
{
    cout << "numerator: " << num << "\tdenominator: " << deno << "\tresult: " << fractionToDecimal(num, deno) << endl;
}

int main(int argc, char** argv)
{
    test(1, 2);
    test(10, 2);
    test(100, 2);
    test(1, 3);
    test(100, 3);
    test(1, 6);
    test(100, 6);
    test(-1, 4);
    test(1, -3);
    test(-1, -6);
    test(25, 99);
    test(1, 7);
    test(10, 7);
    test(100, 7);
    test(1, 17);
    test(1, 1024);
    test( -2147483648, -1999);
    test(-1, -2147483648);

    if (argc > 2) {
        int num = atoi(argv[1]);
        int deno = atoi(argv[2]);
        test(num, deno);
    }
    return 0;
}