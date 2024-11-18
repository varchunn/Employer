#include <iostream>
#include <windows.h>
using namespace std;

class Employer
{
protected:
    char* name;

public:
    Employer(const char* Name) {
        name = new char[strlen(Name) + 1];
        strcpy_s(name, strlen(Name) + 1, Name);
    }

    virtual void Print() const = 0;

    virtual ~Employer()
    {
        if (name != nullptr)
        {
            delete[] name;
        }
    }
};
class President : public Employer
{
    char* country;

public:
    President(const char* Name, const char* Country) : Employer(Name)
    {
        country = new char[strlen(Country) + 1];
        strcpy_s(country, strlen(Country) + 1, Country);
    }

    void Print() const
    {
        cout << "Pr Name: " << name << endl;
        cout << "Pr Country: " << country << endl;
    }

    ~President()
    {
        if (country != nullptr)
        {
            delete[] country;
        }
    }
};

class Manager : public Employer
{
    char* department;

public:
    Manager(const char* Name, const char* Dept) : Employer(Name)
    {
        department = new char[strlen(Dept) + 1];
        strcpy_s(department, strlen(Dept) + 1, Dept);
    }

    void Print() const
    {
       
        cout << "Mn Name: " << name << endl;
        cout << "Mn Department: " << department << endl;
    }

    ~Manager()
    {
        if (department != nullptr)
        {
            delete[] department;
        }
    }
};

class Worker : public Employer
{
    char* job;

public:
    Worker(const char* Name, const char* Job) : Employer(Name)
    {
        job = new char[strlen(Job) + 1];
        strcpy_s(job, strlen(Job) + 1, Job);
    }

    void Print() const
    {
        cout << "Wk Name: " << name << endl;
        cout << "Wk job: " << job << endl;
    }

    ~Worker()
    {
        if (job != nullptr)
        {
            delete[] job;
        }
    }
};

int main()
{
   
    Employer* employees[3] =
    {
        new President("Garry", "Germany"),
        new Manager("Kate", "Team work"),
        new Worker("Bob", "Sales")
    };

    for (int i = 0; i < 3; ++i)
    {
        employees[i]->Print();
        cout << endl;
    }

    for (int i = 0; i < 3; ++i)
    {
        delete employees[i];
    }

    system("pause");
    return 0;
}
