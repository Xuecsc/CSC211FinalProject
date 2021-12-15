#include <iostream>
#include <vector>
using namespace std;

#include "resource.h"
#include "httplib.h"
#include "decision.h"
#include "resourcePageCreator.h"
#include <string>
#include <fstream>

std::string readFile(std::string fp)
{
  auto file = std::fstream(fp);
  return string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

int main()
{
  httplib::Server svr;
  auto ret = svr.set_mount_point("/", "./");
  svr.Get("/option", [](const auto &req, auto &res) {
  
  bool over18 = req.has_param("age");
  bool free = req.has_param("freeOrPaid");
  decision a;
  a.setAge(over18);
  a.setCourseCat(free?"free":"paid");
  rescourcePageCreator page;
  page.print();

  res.set_content(page.getWebpage(a), "text/html");
  

  });

  std::cout << "start server..." << std::endl;
  svr.listen("0.0.0.0", 8080);
}



  
