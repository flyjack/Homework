#include <iostream>
#include <ext/hash_map>
#include <string>

using namespace __gnu_cxx;

int main()
{
  hash_map<int, std::string> hmap;
  int i = 0;       

  for (; i<10; i++)
	  hmap[i] = "abc";

  std::cout<<hmap[2]<<std::endl;
  
  return 0;
}
