#include <iostream>

bool check(const std::string& text)
{
    std::string brackets("");
    std::string Brackets("([{)]}");
    size_t position;

    for(std::string::const_iterator iter = text.begin(); *iter != 0; ++iter)
    {
        position = Brackets.find_first_of(*iter);

        if(position != std::string::npos)
        {
            if(position < 3)
                brackets += *iter;
            else
            {
                if(Brackets[position - 3] == brackets.back())
                    brackets.pop_back();
                else
                    return false;
            }
        }
    }
    return brackets.size() == 0;
}
void Test(const std::string& text, bool success)
{
    std::cout << "check(\""<<text<<"\"): ";
    std::cout << (check(text)==success?"success":"failed") << std::endl;
}

int main(void)
{
    Test("(A)", true);
    Test("}{", false);
    Test("(A])", false);
    Test("()[{}](A)", true);
    Test("(A", false);
    return 0;
}
