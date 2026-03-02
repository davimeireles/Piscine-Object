#pragma once

#include <cstdint>
#include <string>
#include <map>

class Command {
	
	private:
		std::map<std::string, uint32_t>command;
		uint32_t _id;
		uint32_t _date;
		std::string _client;
		std::string _articles;

	public:
		uint32_t getTotalPrice();
};