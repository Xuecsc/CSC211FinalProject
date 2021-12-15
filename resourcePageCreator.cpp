#include "resourcePageCreator.h"

string& replaceChar(string &str, char origin, char replacement)
{
  for(int i = 0; i < str.size(); i++)
  {
    if(str[i] == origin)
      str[i] = replacement;
  }
  return str;
}
rescourcePageCreator::rescourcePageCreator()
{ 
  ifstream inputFile;
// free under 18
inputFile.open("freeUnder18.txt");

if (inputFile.is_open()) {
  string name, website;
  while (inputFile >> name >> website) {
    replaceChar(name,'_', ' ');
    freeUnder18.push_back(Resource(name, website, "Free Under 18"));
  }
}
inputFile.close();

// paid under 18
inputFile.open("paidUnder18.txt");

if (inputFile.is_open()) {
  string name, website;
  while (inputFile >> name >> website) {
    replaceChar(name,'_', ' ');
    freeUnder18.push_back(Resource(name, website, "Paid Under 18"));
  }
}
inputFile.close();

// free college age
inputFile.open("freeCollegeAge.txt");

if (inputFile.is_open()) {
  string name, website;
  while (inputFile >> name >> website) {
    replaceChar(name,'_', ' ');
    freeCollegeAge.push_back(Resource(name, website, "Free College Age"));
  }
}
inputFile.close();

//paid college age
inputFile.open("paidCollegeAge.txt");

if (inputFile.is_open()) {
  string name, website;
  while (inputFile >> name >> website) {
    replaceChar(name,'_', ' ');
    paidCollegeAge.push_back(Resource(name, website, "Paid College Age"));
  }
}
inputFile.close();
}

string rescourcePageCreator::getWebpage(decision a)
{
   string result;
   string decision = a.getDecision();

    if (decision == "freeUnder18")
      {
        for (int i=0; i <freeUnder18.size();i++ )
        {
          result = result + freeUnder18[i].getHtml();
        }
      }

     else if (decision == "paidUnder18")
      {
        for (int i=0; i <paidUnder18.size();i++ )
        {
          result = result + paidUnder18[i].getHtml();
        }
      }

      else if (decision == "freeCollegeAge")
      {
        for (int i=0; i <freeCollegeAge.size();i++ ){
  
          result = result + freeCollegeAge[i].getHtml();
        }
      }

      else 
      {
        for (int i=0; i <paidCollegeAge.size();i++ ){
  
          result = result + paidCollegeAge[i].getHtml();
        }
      }

   return string("<html>"
   "<link rel=\"stylesheet\" href=\"style.css\">"
   "<body>\n"
"<table>\n"
  "<tr>\n"
    "<th>Name</th>\n"
  "</tr>")+result + "</table>\n</body></html>";
}

void rescourcePageCreator::print()
{

   for (int i=0; i <freeUnder18.size();i++ )
      {
        cout <<  "Free Under 18 Rescources:" << freeUnder18[i].getHtml() << endl;
      }
 
    for (int i=0; i <paidUnder18.size();i++ )
      {
        cout <<  "Paid Under 18 Rescources:" << paidUnder18[i].getHtml() << endl;
      }
 
     for (int i=0; i <freeCollegeAge.size();i++ )
      {
        cout <<  "Free College Age Rescources:" << freeCollegeAge[i].getHtml() << endl;
      }

    for (int i=0; i <paidCollegeAge.size();i++ )
      {
        cout <<  "Paid College Age Rescources:" << paidCollegeAge[i].getHtml() << endl;
      }

}

