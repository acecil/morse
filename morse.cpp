#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
 
std::string operator "" _m(const char text[], long unsigned int len)
{
  std::string s;
  static auto dot([](){
      std::map<const char*, const char*> d;
      d[""] = "e";
      d["e"] = "i";
      d["i"] = "s";
      d["s"] = "h";
      d["h"] = "5";
      d["t"] = "n";
      d["n"] = "d";
      d["d"] = "b";
      d["b"] = "6";
      d["a"] = "r";
      d["r"] = "l";
      d["m"] = "g";
      d["g"] = "z";
      d["o"] = "ö";
      d["ö"] = "8";
      d["8"] = ":";
      d["z"] = "7";
      d["u"] = "f";
      d["f"] = "é";
      d["r"] = "l";
      d["w"] = "p";
      d["p"] = "Þ";
      d["k"] = "c";
      d["c"] = "ç";
      d["v"] = "ŝ";
      d["ü"] = "đ";
      d["đ"] = "?";
      d["é"] = "\"";
      d["ä"] = "+";
      d["à"] = "@";
      d["j"] = "ĵ";
      d["1"] = "'";
      d["x"] = "/";
      d["y"] = "ĥ";
      d["q"] = "ĝ";
      d["ch"] = "9";
      return d;
    }());
  static auto dash([](){
      std::map<const char*, const char*> d;
      d[""] = "t";
      d["e"] = "a";
      d["t"] = "m";
      d["i"] = "u";
      d["a"] = "w";
      d["n"] = "k";
      d["m"] = "o";
      d["s"] = "v";
      d["u"] = "ü";
      d["r"] = "ä";
      d["w"] = "j";
      d["d"] = "x";
      d["k"] = "y";
      d["g"] = "q";
      d["o"] = "ch";
      d["h"] = "4";
      d["v"] = "3";
      d["ü"] = "2";
      d["đ"] = "_";
      d["l"] = "è";
      d["+"] = ".";
      d["p"] = "à";
      d["j"] = "1";
      d["6"] = "-";
      d["b"] = "=";
      d["q"] = "ñ";
      d["ch"] = "0";
      return d;
    }());

  std::string currM;
  const char *current = "";
  for(const char *c = text; *c; ++c)
  {
    switch(*c)
    {
    case ' ':
      s += current;
      currM = "";
			current = "";
      break;
    case '.':
      {
        auto it(dot.find(current));
        if( it != dot.end() )
        {
          current = it->second;
          currM += *c;
        }
        else
        {
          throw new std::invalid_argument(currM);
        }
      }
      break;
    case '-':
      {
        auto it(dash.find(current));
        if( it != dash.end() )
        {
          current = it->second;
          currM += *c;
        }
        else
        {
          throw new std::invalid_argument(currM);
        }
      }
      break;
    default:
      throw new std::invalid_argument(std::string("bad morse code character"));
    }
  }
	
	s += current;

  return s;
}


int main()
{
  auto m0 = ".- -... -.-."_m;
	auto m1 = ".... . .-.. .-.. --- .-- --- .-. .-.. -.."_m;

  std::cout << m0 << std::endl;
  std::cout << m1 << std::endl;
  
	return 0;
}
