#pragma once

#include "oxygine-framework.h"
#include "json/json.h"
#include "core/file.h" 

using namespace oxygine;

namespace json
{
	file::buffer bf;

	void load();
	void parse();
}