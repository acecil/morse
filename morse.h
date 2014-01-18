#pragma once

#include <cstring>
#include <map>
#include <stdexcept>
#include <string>
#include "utf8.h"

class morse
{
public:
	morse() : m_text() {}
	morse(const char text[]) : m_text(encode(text)) {}
	morse(const std::string& text) : m_text(encode(text)) {}
	morse(const morse& other) : m_text(other.m_text) {}
	morse(morse&& other) : m_text(std::move(other.m_text)) {}
	
	morse& operator=(const char text[]) { m_text = encode(text); return *this; }
	morse& operator=(const std::string& text) { m_text = encode(text); return *this; }
	morse& operator=(const morse& other) { m_text = other.m_text; return *this; }
	morse& operator=(morse&& other) { m_text = std::move(other.m_text); return *this; }
	
	morse& assign(const char text[]) { m_text = encode(text); return *this; }
	morse& assign(const std::string& text) { m_text = encode(text); return *this; }
	morse& assign(const morse& other) { m_text = other.m_text; return *this; }
	morse& assign(morse&& other) { m_text = std::move(other.m_text); return *this; }
	
	operator const char*() const { return m_text.c_str(); }
	operator std::string() { return m_text; }
	operator const std::string() const { return m_text; }
	operator const std::string&() const { return m_text; }
	
	morse& set_morse(const char text[]) { m_text = text; return *this; }
	morse& set_morse(const std::string& text) { m_text = text; return *this; }
	morse& set_morse(std::string&& text) { m_text = std::move(text); return *this; }
	
	bool operator==(const morse& other) { return m_text == other.m_text; }
	
	std::string decode() const
	{
		static const std::map<const char*, const char*> dot =
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
		static const std::map<const char*, const char*> dash =
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

		std::string s;
		std::string currM;
		const char *current = "";
		for (const char c : m_text)
		{
			switch (c)
			{
			case ' ':
				if( current[0] == '\0' )
				{
					s += " ";
				}
				else
				{
					s += current;
				}
				currM = "";
				current = "";
				break;
			case '.':
				{
					auto it(dot.find(current));
					if (it != dot.cend())
					{
						current = it->second;
						currM += c;
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
					if (it != dash.cend())
					{
						current = it->second;
						currM += c;
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
	
private:
	std::string m_text; // Morse code string.
	
	static std::string encode(const std::string& text)
	{
		static const std::map<std::string, std::string> tab =
		{
			{ " ", " " },
			{ "a", ".-" },
			{ "b", "-..." },
			{ "c", "-.-." },
			{ "d", "-.." },
			{ "e", "." },
			{ "f", "..-." },
			{ "g", "--." },
			{ "h", "...." },
			{ "i", ".." },
			{ "j", ".---" },
			{ "k", "-.-" },
			{ "l", ".-.." },
			{ "m", "--" },
			{ "n", "-." },
			{ "o", "---" },
			{ "p", ".--." },
			{ "q", "--.-" },
			{ "r", ".-." },
			{ "s", "..." },
			{ "t", "-" },
			{ "u", "..-" },
			{ "v", "...-" },
			{ "w", ".--" },
			{ "x", "-..-" },
			{ "y", "-.--" },
			{ "z", "--.." },
			{ "0", "-----" },
			{ "1", ".----" },
			{ "2", "..---" },
			{ "3", "...--" },
			{ "4", "....-" },
			{ "5", "....." },
			{ "6", "-...." },
			{ "7", "--..." },
			{ "8", "---.." },
			{ "9", "----." },
			{ ".", ".-.-.-" },
			{ ",", "--..--" },
			{ "?", "..--.." },
			{ "'", ".----." },
			{ "!", "-.-.--" },
			{ "/", "-..-." },
			{ "(", "-.--." },
			{ ")", "-.--.-" },
			{ "&", ".-..." },
			{ ":", "---..." },
			{ ";", "-.-.-." },
			{ "=", "-...-" },
			{ "+", ".-.-." },
			{ "-", "-....-" },
			{ "_", "..--.-" },
			{ "\"", ".-..-." },
			{ "$", "...-..-" },
			{ "@", ".--.-." },
			{ "ä", ".-.-" },
			{ "æ", ".-.-" },
			{ "ą", ".-.-" },
			{ "à", ".--.-" },
			{ "å", ".--.-" },
			{ "ç", "-.-.." },
			{ "ĉ", "-.-.." },
			{ "ć", "-.-.." },
			{ "š", "----" },
			{ "ð", "..--." },
			{ "ś", "...-..." },
			{ "è", ".-..-" },
			{ "ł", ".-..-" },
			{ "é", "..-.." },
			{ "đ", "..-.." },
			{ "ę", "..-.." },
			{ "ĝ", "--.-." },
			{ "ĥ", "-.--." },
			{ "ĵ", ".---." },
			{ "ź", "--..-." },
			{ "ñ", "--.--" },
			{ "ń", "--.--" },
			{ "ö", "---." },
			{ "ø", "---." },
			{ "ó", "---." },
			{ "ŝ", "...-." },
			{ "þ", ".--.." },
			{ "ü", "..--" },
			{ "ŭ", "..--" },
			{ "ż", "--..-" }
		};

		std::string enc;
		auto begin = utf8::iterator<std::string::const_iterator>(text.cbegin(), text.cbegin(), text.cend());
		auto end = utf8::iterator<std::string::const_iterator>(text.cend(), text.cbegin(), text.cend());
		for(auto it = begin; it != end; ++it)
		{
			auto cit = it;
			std::string::const_iterator bit = it.base();
			std::string::const_iterator eit = (++it).base();
			std::string ch(bit, eit);
			it = cit;
			auto itt(tab.find(ch));
			if( itt == tab.cend() )
			{
				throw new std::invalid_argument(ch);
			}
			if( !enc.empty() && (itt->second != " ") )
			{
				enc += " ";
			}
			enc += itt->second;
		}
		
		return enc;
	}
};

std::ostream& operator<<(std::ostream& os, const morse& obj)
{
	return os << static_cast<const std::string&>(obj);
}
std::istream& operator>>(std::istream& is, morse& obj)
{
	std::string text;
	is >> text;
	obj = text;
	return is;
}

std::string to_string(const morse& m)
{
	return m.decode();
}

morse operator "" _m(const char text[], long unsigned int len)
{
	morse m;
	return m.set_morse(text);
}
