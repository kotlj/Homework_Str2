
#include <iostream>

using namespace std;

class MyString
{
private:
    char* str;
    int length;

    static int numOfStr;
public:
    MyString()
    {
        length = 80;
        str = new char[length + 1];
        str[length] = '\0';
        numOfStr++;
    }
    MyString(int _length)
    {
        length = _length;
        str = new char[length + 1];
        str[length] = '\0';
        numOfStr++;
    }
    MyString(char* _str)
    {
        length = 0;
        for (int phase = 0; phase < 2; phase++)
        {
            for (int i = 0; _str[i] != '\0'; i++)
            {
                if (phase == 0)
                {
                    length++;
                }
                else
                {
                    str[i] = _str[i];
                }
            }
            if (phase == 0)
            {
                str = new char[length + 1];
            }
        }
        str[length] = '\0';
        numOfStr++;
    }
    MyString(const char _str[])
    {
        length = 0;
        for (int phase = 0; phase < 2; phase++)
        {
            for (int i = 0; _str[i] != '\0'; i++)
            {
                if (phase == 0)
                {
                    length++;
                }
                else
                {
                    str[i] = _str[i];
                }
            }
            if (phase == 0)
            {
                str = new char[length + 1];
            }
        }
        str[length] = '\0';
        numOfStr++;
    }
    MyString(MyString& obj)
    {
        this->length = obj.length;
        this->str = new char[length + 1];
        for (int i = 0; obj.str[i] != '\0'; i++)
        {
            this->str[i] = obj.str[i];
        }
        this->str[length] = '\0';
    }

    void inputStr()
    {
        gets_s(str, length);
    }

    void showStr()
    {
        cout << str << '\n';
    }

    void MyStrCopy(MyString& obj)
    {
        this->length = obj.length;
        delete[] this->str;
        this->str = new char[length + 1];
        for (int i = 0; obj.str[i] != '\0'; i++)
        {
            this->str[i] = obj.str[i];
        }
        this->str[length] = '\0';
    }

    void static showCount()
    {
        cout << numOfStr << '\n';
    }

    bool MyStrStr(const char* _toFind)
    {
        bool find = false;
        for (int i = 0; str[i] != '\0'; i++)
        {
            for (int j = 0; _toFind[j] != '\0'; j++)
            {
                if (str[i + j] != '\0' && str[i + j] == _toFind[j])
                {
                    find = true;
                }
                else
                {
                    find = false;
                    break;
                }
            }
            if (find)
            {
                return find;
            }
        }
        return find;
    }

    int MyChr(char c)
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == c)
            {
                return i;
            }
        }
        return -1;
    }

    int MyStrLen()
    {
        return length;
    }

    void MyStrCat(MyString& obj)
    {
        char* tample = new char[this->length + obj.length + 1];
        for (int i = 0; i < this->length; i++)
        {
            tample[i] = this->str[i];
        }
        for (int i = 0; i < obj.length; i++)
        {
            tample[this->length + i] = obj.str[i];
        }
        this->length += obj.length;
        delete[] this->str;
        this->str = tample;
        this->str[length] = '\0';
    }

    void MyChrDel(char c)
    {
        char* tample = new char[length];
        int indx = this->MyChr(c);
        for (int i = 0; i < length; i++)
        {
            if (i < indx)
            {
                tample[i] = this->str[i];
            }
            else if (i == indx)
            {
                continue;
            }
            else
            {
                tample[i - 1] = this->str[i];
            }
        }
        this->length--;
        delete[] this->str;
        this->str = tample;
        this->str[this->length] = '\0';
    }

    int MyStrCmp(MyString& obj)
    {
        return (this->length == obj.length ? 0 : (this->length > obj.length ? 1 : -1));
    }

    ~MyString()
    {
        delete[] str;
    }
};

int MyString::numOfStr = 0;


int main()
{
    MyString a("hello");
    MyString b(" world");
    a.MyStrCat(b);
    a.MyChrDel('l');
    if (a.MyStrStr("helo"))
    {
        a.MyStrCopy(b);
        a.showStr();
    }
}