#include "decision.h"
using namespace std;

bool decision::getAge() 
{
  return age;
}

void decision::setAge(bool age) 
{
  this->age = age;
}

string decision::getCourseCat()
{
	 return courseCategory;
}

void decision::setCourseCat(string courseCategory )
{
	 this->courseCategory = courseCategory;
}

  /*
  string htmlFile((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
  file.close();
  
  return htmlFile;
}
 */

string decision::getDecision()
{
  if (!age && courseCategory == "free")
  {
    return "freeUnder18";
  }
  else if (!age && courseCategory
== "paid")
   {
     return "paidunder18";
   }
  else if (age && courseCategory=="free" )
  {
     return "freeCollegeAge";
  }
  else
  {
    return "paidCollegeAge";
  }
}


void decision::print() 
{
  cout << "You are in age group:" << age << endl;
  cout << "Course Category:" << courseCategory << endl;
}

