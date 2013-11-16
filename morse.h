#pragma once

#include <map>
#include <stdexcept>
#include <string>

namespace morse
{
	std::string operator "" _m(const char text[], long unsigned int len)
	{
		std::string s;
		static std::map<const char*, const char*> dot =
		{
			{ "", "e" },
			{ "e", "i" },
			{ "i", "s" },
			{ "s", "h" },
			{ "h", "5" },
			{ "t", "n" },
			{ "n", "d" },
			{ "d", "b" },
			{ "b", "6" },
			{ "a", "r" },
			{ "r", "l" },
			{ "m", "g" },
			{ "g", "z" },
			{ "o", "ö" },
			{ "ö", "8" },
			{ "8", ":" },
			{ "z", "7" },
			{ "u", "f" },
			{ "f", "é" },
			{ "r", "l" },
			{ "w", "p" },
			{ "p", "Þ" },
			{ "k", "c" },
			{ "c", "ç" },
			{ "v", "ŝ" },
			{ "ü", "đ" },
			{ "đ", "?" },
			{ "é", "\"" },
			{ "ä", "+" },
			{ "à", "@" },
			{ "j", "ĵ" },
			{ "1", "'" },
			{ "x", "/" },
			{ "y", "ĥ" },
			{ "q", "ĝ" },
			{ "ch", "9" }
		};
		static std::map<const char*, const char*> dash =
		{
			{ "", "t" },
			{ "e", "a" },
			{ "t", "m" },
			{ "i", "u" },
			{ "a", "w" },
			{ "n", "k" },
			{ "m", "o" },
			{ "s", "v" },
			{ "u", "ü" },
			{ "r", "ä" },
			{ "w", "j" },
			{ "d", "x" },
			{ "k", "y" },
			{ "g", "q" },
			{ "o", "ch" },
			{ "h", "4" },
			{ "v", "3" },
			{ "ü", "2" },
			{ "đ", "_" },
			{ "l", "è" },
			{ "+", "." },
			{ "p", "à" },
			{ "j", "1" },
			{ "6", "-" },
			{ "b", "=" },
			{ "q", "ñ" },
			{ "ch", "0" }
		};

		std::string currM;
		const char *current = "";
		for (const char *c = text; *c; ++c)
		{
			switch (*c)
			{
			case ' ':
				s += current;
				currM = "";
				current = "";
				break;
			case '.':
			{
						auto it(dot.find(current));
						if (it != dot.end())
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
						if (it != dash.end())
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
}