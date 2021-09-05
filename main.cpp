#include <iostream>
#include <string>
std::string result (std::string numb1, std::string numb2)
{
    int i = 0;
    std::string result;
    if(numb1[0] == '-' && numb2[0] == '-')
    {
        while (i < numb2.length() && numb1[i] == numb2[i] )
        {
            ++i;
        }
        if(numb1[i] > numb2[i])
        {
            result = "Less";
        }
        else if (numb1[i] < numb2[i])
        {
            result = "More";
        }
        else
        {
            result = "Equal";
        }
    }
    else
    {
        while (i < numb2.length() && numb1[i] == numb2[i] )
        {
            ++i;
        }
        if(numb1[i] < numb2[i])
        {
            result = "Less";
        }
        else if (numb1[i] > numb2[i])
        {
            result = "More";
        }
        else
        {
            result = "Equal";
        }
    }

    return result;
}

int dotCounter (std::string str)
{
    int dot = 0;
    for(int i = 0; i < str.length();++i)
    {
        if(str[i] == '.')
        {
            ++dot;
        }
    }
    return dot;
}

bool nCorrect(std::string numb)
{
    bool nCorrect = true;
    bool minus = false;
    int dotCounter = 0;
    int dotPosition = 0;
    if(numb.length() == 1)
    {
        numb += '.';
    }
    if (numb.length() > 0 && numb[0] == '-')
    {
        minus = true;
    }
    for (int i = 0; i < numb.length(); ++i)
    {
        if (numb[i] == '.')
        {
            ++dotCounter;
            dotPosition = i;
        }
    }
    if (dotCounter > 1)
    {
        nCorrect = false;

    }
    else
    {
        int iStart = 0;
        int iEnd = (int)numb.length();
        if (minus) ++iStart;
        if (dotCounter == 1) iEnd = dotPosition;
        if ((iStart == dotPosition) && dotPosition + 1 == (int)numb.length()) nCorrect = false;
        for (int i = iStart; i < iEnd; ++i)
        {
            if (numb[i] < '0' || numb[i] > '9')
            {
                nCorrect = false;
            }
        }
        if(nCorrect && dotCounter == 1)
        {
            for (int i = dotPosition + 1; i < numb.length(); ++i)
            {
                if (numb[i] < '0' || numb[i] > '9')
                {
                    nCorrect = false;
                }
            }
        }
    }
    return nCorrect;
}

std::string numb_not_noll (std::string numb)
{
    std::string buf;
    int i = 0;
    while (i < numb.length() && numb[i] == '0')
    {
        ++i;
    }
    for (;i < numb.length();++i)
    {
        buf += numb[i];
    }
    numb = buf;
    return numb;
}

int main() {

    char dot = '.';
    char null = '0';
    std::string numb1;
    std::string numb2;
    int differenceStr;

    std::cout << "Enter a number one: \n";
    std::cin >> numb1;
    while (!nCorrect(numb1))
    {
        std::cout << "ERROR!Enter a number one: \n";
        std::cin >> numb1;
    }
    if (numb1[0] == '0')
    {
        numb1 = numb_not_noll(numb1);
    }
    if(dotCounter(numb1) == 0)
    {
        numb1 += dot;
    }

    std::cout << "Enter a number two: \n";
    std::cin >> numb2;
    while (!nCorrect(numb2))
    {
        std::cout << "ERROR!Enter a number two: \n";
        std::cin >> numb2;
    }
    if (numb2[0] == '0')
    {
        numb2 = numb_not_noll(numb2);
    }
    if(dotCounter(numb2) == 0)
    {
        numb2 += dot;
    }

    if(numb1.length() < numb2.length())
    {
        differenceStr = numb2.length() - numb1.length();
        for(int i = 0;i < differenceStr; i++)
        {
            numb1 += null;
        }
    }
    else if(numb1.length() > numb2.length())
    {
        differenceStr = numb1.length() - numb2.length();
        for(int i = 0;i < differenceStr; i++)
        {
            numb2 += null;
        }
    }
    std::cout << result(numb1,numb2);
}
