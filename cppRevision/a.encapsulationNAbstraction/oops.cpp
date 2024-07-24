#include <iostream>
#include <limits>
#include <sstream>

// Encapsulation: encapsulation is grouping the data and it's modifier functions together under a class.

// Abstraction: abstraction is hiding complex process behind a simple interface.

// Inheritance: when a class is created on top of other class, or by extending another class then the
// newly created class receives the properties and methods of the base class this is called inheritance.

// Polymorphism:
// 1. Method overloading
//    When classes have methods with same names but different parameters.
// 2. Method overriding
//    When a sub class or a child class provide a different implementation
//    of a method that is already defined in base class.

// abstract class
class AbstractEmployee
{
  virtual void askForPromotion() = 0;
};

class Employee : AbstractEmployee
{
protected:
  std::string Name;
  std::string Company;
  int Age;

public:
  void setName(std::string name)
  {
    Name = name;
  }

  std::string getName()
  {
    return Name;
  }

  void setCompany(std::string company)
  {
    Company = company;
  }

  std::string getCompany()
  {
    return Company;
  }

  void setAge(int age)
  {
    Age = age;
  }

  int getAge()
  {
    return Age;
  }

  void IntroduceYourself()
  {
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Company: " << Company << std::endl;
    std::cout << "Age: " << Age << std::endl;
  }

  Employee(std::string name, std::string company, int age)
  {
    Name = name;
    Company = company;
    Age = age;
  }

  // implementing the method of abstract class.
  void askForPromotion()
  {
    if (Age > 30)
    {
      std::cout << Name << " got promoted!" << std::endl;
    }
    else
    {
      std::cout << Name << ", Sorry! No promotion for you." << std::endl;
    }
  }

  virtual void Work()
  {
    std::cout << Name << " is checking email, task backlog, performing tasks..." << std::endl;
  }
};

// by default inheritance is private so the objects of Developer class will not have access to the properties and methods of Employee
// so we need to make the inheritance public to allow access these properties from objects of Developer class.
class Developer : public Employee
{
public:
  std::string FavProgrammingLanguage;
  Developer(std::string name, std::string company, int age, std::string favProgrammingLanguage) : Employee(name, company, age)
  {
    FavProgrammingLanguage = favProgrammingLanguage;
  }

  void FixBug()
  {
    std::cout << getName() << " is solving " << FavProgrammingLanguage << " bug." << std::endl;
  }

  void Work()
  {
    std::cout << Name << " is writing Code." << std::endl;
  }
};

class Teacher : public Employee
{
public:
  std::string Subject;
  void PrepareLesson()
  {
    std::cout << getName() << " is preparing " << Subject << " lesson." << std::endl;
  }
  Teacher(std::string name, std::string company, int age, std::string subject) : Employee(name, company, age)
  {
    Subject = subject;
  }

  void Work()
  {
    std::cout << Name << " is teaching." << std::endl;
  }
};

int get_int(std::string message)
{
  bool inputReceived = false;
  int input;
  do
  {
    std::cout << message << ": ";
    std::cin >> input;
    if (std::cin.good())
    {
      inputReceived = true;
    }
    else
    {
      std::cout << "Please provide a valid input." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while (!inputReceived);
  return input;
}

int main()
{
  // int num1 = get_int("Provide your 1st favourite number.");
  //  int num2 = get_int("Provide your 2nd favourite number.");
  //  cin >> num1 >> num2;
  //  std::cout << "1st favourite number: " << num1 << std::endl;
  //  std::cout << "2nd favourite number: " << num2 << std::endl;
  Employee employee1 = Employee("Saldina", "YT-CodeBeauty", 25);
  Employee employee2 = Employee("John", "Amazon", 35);
  employee1.askForPromotion();
  employee2.askForPromotion();
  employee1.IntroduceYourself();

  Developer dev1 = Developer("Saldina", "YT_CodeBeauty", 25, "C++");
  dev1.FixBug();
  dev1.askForPromotion();
  dev1.Work();

  Teacher t = Teacher("Jack", "Cool School", 35, "History");
  t.PrepareLesson();
  t.askForPromotion();
  t.Work();

  // the most common use of polymorphism is when a parent class reference is used to refer to a child class object.

  Employee *e1 = &dev1;
  Employee *e2 = &t;

  e1->Work();
  e2->Work();
}
