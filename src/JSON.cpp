#include "JSON.h"

namespace json
{
	void load()
	{
		file::read("file.json", bf);
	}

	void parse()
	{
		Json::Reader reader;
		Json::Value value;
		reader.parse((char*)&bf.front(), (char*)&bf.front() + bf.size(), value, false);
	}
}