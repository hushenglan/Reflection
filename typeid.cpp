#include <iostream>
#include <typeinfo>
#include <string>
#include <utility>

class person
{
  public:

   person(const std::string& n) : _name(n) {}
   virtual const std::string& name() const{ return _name; }

  private:

    std::string _name;
};

class employee : public person
{
   public:

     employee(const std::string& n, const std::string& p) :
         person(n), _profession(p) {}

     const std::string& profession() const { return _profession; }

   private:

     std::string _profession;
};

void somefunc(const person& p)
{
   if(typeid(employee) == typeid(p))
   {
      std::cout << p.name() << " is an employee ";
      const employee& emp = dynamic_cast<const employee&>(p);
      std::cout << "who works in " << emp.profession() << '\n';
   }
}

int main()
{
   employee paul("Paul","Economics");
   somefunc(paul);
}