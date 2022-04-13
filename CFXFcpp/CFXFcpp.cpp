#include <iostream>
#include "cpr/cpr.h"

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
	return str;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: " << argv[0] << " [CFX Url]";
		Sleep(3000);
		exit(0);
	}

	cpr::Response response = cpr::Get(cpr::Url{ argv[1] },
		cpr::Header{ 
			{"user-agent", "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.2; .NET CLR 1.0.3705;)"} 
		}
	);

	std::string ip = response.header["x-citizenfx-url"];
	std::string ipWhttp = ReplaceAll(ip, std::string("http://"), std::string(""));
	std::string ipWslash = ReplaceAll(ipWhttp, std::string("/"), std::string(""));

	std::cout << "IP: " << ipWslash;
}