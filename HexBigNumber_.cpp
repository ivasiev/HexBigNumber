// HexBigNumber.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <sstream>
// Бібліотека написана на С++. Основна ідея використання 1 байту для відображення двох 16 ткових цифр (Здалось що це найоптимальніший варіант)
// Побітові реалізовані деякі побітові операції
// Арифметичні операції не реалізовані (Потребують більше часу)

using namespace std;
class BigNumber {

    string get_char_represent(unsigned int decimalNumber);
    int get_number_represent(char s);
    std::vector <unsigned char> number;// array of hex digit 
    void print_vector();
public:
    void setHex(string hex_number_string);
    string getHex();
    //  INV
    void XOR(const BigNumber& b);
    //  OR
    void AND(const BigNumber& b);
    void OR(const BigNumber& b);
    
    //  shiftR
    //  shiftL
    //  ADD(додавання)
    //  SUB(віднімання)
    //  MOD(взяття за модулем)
    friend BigNumber XOR(const BigNumber& a, const BigNumber& b);
};

string BigNumber::get_char_represent(unsigned int decimalNumber) {
    if (decimalNumber == 0) {
        return "00";
    }
    std::string hexNumber = "";
    while (decimalNumber > 0) {
        int remainder = decimalNumber % 16;
        char hexDigit;

        if (remainder < 10) {
            hexDigit = '0' + remainder;
        }
        else {
            hexDigit = 'a' + remainder - 10;
        }

        hexNumber = hexDigit + hexNumber;
        decimalNumber /= 16;
    }
    if (hexNumber.length() == 1) hexNumber = "0" + hexNumber;
    return hexNumber;

};
int BigNumber::get_number_represent(char s) {
    if (s == '1') return 1;
    if (s == '2') return 2;
    if (s == '3') return 3;
    if (s == '4') return 4;
    if (s == '5') return 5;
    if (s == '6') return 6;
    if (s == '7') return 7;
    if (s == '8') return 8;
    if (s == '9') return 9;
    if (s == '0') return 0;
    if (s == 'A' or s == 'a') return 10;
    if (s == 'B' or s == 'b') return 11;
    if (s == 'C' or s == 'c') return 12;
    if (s == 'D' or s == 'd') return 13;
    if (s == 'E' or s == 'e') return 14;
    if (s == 'F' or s == 'f') return 15;
    return 0;// на обробку неправильних вхідних не хватило часу
};

void BigNumber::print_vector() {
    for (int i = 0; i < number.size(); i++) {
        cout << unsigned int(number[i]) << " ";
    }
}
 void BigNumber::setHex(string hex_number_string) {
        if (hex_number_string.length() % 2 != 0)hex_number_string = "0" + hex_number_string;
        for (int i = hex_number_string.length() - 1; i > 0; i = i - 2) {
            number.push_back(
                static_cast<int>(get_number_represent(hex_number_string[i - 1]) * 16 + get_number_represent(hex_number_string[i]))
            );
        };

    };
    string BigNumber::getHex() {
        string s = "";
        for (int i = 0; i < number.size(); i++)
            s = get_char_represent(number[i]) + s;
        return s;
    };
    //  INV
    void BigNumber::XOR(const BigNumber& b) {
        for (int i = 0; i < number.size(); i++) {
            //if (i!= number.size()-1 and number[i]=='0')
            number[i] = number[i] ^ b.number[i % b.number.size()];

        };

    };
    //  OR
    void BigNumber::AND(const BigNumber& b) {
        for (int i = 0; i < number.size(); i++) {
            //if (i!= number.size()-1 and number[i]=='0')
            number[i] = number[i] & b.number[i % b.number.size()];

        };
    }
    void BigNumber::OR(const BigNumber& b) {
        for (int i = 0; i < number.size(); i++) {
            //if (i!= number.size()-1 and number[i]=='0')
            number[i] = number[i] | b.number[i % b.number.size()];

        };
    }
    BigNumber XOR(const BigNumber &a, const BigNumber &b) {
        BigNumber c;
        for (int i = 0; i < a.number.size(); i++) {
            //if (i!= number.size()-1 and number[i]=='0')
            c.number.push_back(a.number[i] ^ b.number[i % b.number.size()]);

        };

       
        return c;
    }
int main()
{
    string s1,s2;
    cout << "Enter Hex1 ";
    cin >> s1;
    cout << "Enter Hex2 ";
    cin >> s2;
    BigNumber a,b,c;
    a.setHex(s1);
    b.setHex(s2);
    cout << endl;
    cout << endl<<" XOR ";
    c=XOR(a,b);
    cout << c.getHex();
   
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
