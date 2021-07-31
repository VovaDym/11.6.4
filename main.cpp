#include <iostream>
#include <string>
bool nCorrect(std::string n){
    bool minus = n.length() > 0 && n[0] == '-';
    bool dot = false;
    int dotPosition = 0;
    for (int i = 0; !dot && i < n.length(); ++i){
        if (n[i] == '.'){
            dot = true;
            dotPosition = i;
        }
    }
    bool good = true;

    int nStart = minus ? 1 : 0;
    int nEnd = (dot ? dotPosition : (int)n.length());

    for (int i = nStart; i < nEnd; ++i){
        if (n[i] < '0' || n[i] > '9'){
            good = false;
        }
    }

    int dotStart = dot ? dotPosition + 1 : n.length();

    for (int i = dotStart; i < n.length(); ++i){
        if (n[i] < '0' || n[i] > '9'){
            good = false;
        }
    }

    if ((nEnd - nStart) + (n.length() - dotStart) == 0){
        good = false;
    }
    return (good ? 1 : 0);
}
int d(std::string part)
{
    int number = 0;
    for(int i = 0;i < part.length() ;++i)
    {
        if(part[0] == '-')
        {
            i = 1;
            int digit = part[i] -'0';
            number = (number * 10 + digit) * -1;
        }
        else
        {
            int digit = part[i] -'0';
            number = number * 10 + digit;
        }
    }
    return  number;
}


int main() {
    std::string numb1,numb2;
    std::cout << "Enter a number one: \n";
    std::cin >> numb1;
    std::cout << "Enter a number two: \n";
    std::cin >> numb2;
    if(!nCorrect(numb1) || !nCorrect(numb2))
    {
        std::cout << "The numbers is incorrect";
    }
    else {
        std::string numb1part1, numb1part2, numb2part1, numb2part2;
        for (int i = 0; i < numb1.length() && numb1[i] != '.'; ++i) {
            numb1part1 += numb1[i];
        }
        std::cout << numb1part1 <<d(numb1part1) << "\n";
        for (int i = 0; i < numb2.length() && numb2[i] != '.'; ++i) {
            numb2part1 += numb2[i];
        }
        std::cout << numb2part1 << d(numb2part1) << "\n";
        if (d(numb1part1) < d(numb2part1)) {
            std::cout << "Less\n";
        }
        else if (d(numb1part1) > d(numb2part1))
        {
            std::cout << "More\n";
        }
        else
        {
            std::cout << "Equal\n";
        }
    }
}
