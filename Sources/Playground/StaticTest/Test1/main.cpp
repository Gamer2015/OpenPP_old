#include <exception>
#include <string>
#include <iostream>
#include <sstream>

class MyException : public std::exception
{
    public:
        MyException(char* file, int line)
        {
            sprintf(mBuffer,"%d", line);
            mWhat.append("Exception occured!\nFile \"").append(file).append("\" Line ").append(mBuffer).append(" error");
        }

        const char* what() const noexcept
        {
            return mWhat.c_str();
        }
    private:
        std::string mWhat;
        char mBuffer[8];
};

int main(void)
{
    try
    {
        throw MyException(__FILE__, __LINE__);
    }
    catch(MyException &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
