#include <iostream>

//操作符重载，operator == 是一个整体， operator是关键字

class Student
{
    private:
        int age;
    public:
        Student(int age)
        {
            this->age = age;
        }

        inline bool operator == (const Student &right) const;
};

inline bool Student::operator == (const Student &right) const
{
    /*
    if (this == right)
        return true;
    */

    if (this->age == right.age)
        return true;

    return false;
}

int main()
{
    Student s1(10);

    if (s1 == s1)
        std::cout<<"Equal"<<std::endl;

    Student s2(20);
    
    if (s1 == s2)
        std::cout<<"Equal Again"<<std::endl;
    else
        std::cout<<"No Equal"<<std::endl;

    return 0;
}
