#pragma once

#include <string>
#include <vector>

/**
 * * The price of each article will be 20euros.
 * * @_articles will be used to count the number of articles.
 */

class Command {
	
	private:
		unsigned int _id;
		std::string _date;
		std::vector<unsigned int> _articles;
		std::string _client;

	public:
		Command(unsigned int id, const std::string& date, const std::string& client, const std::vector<unsigned int>& articles)
			: _id(id), _date(date), _articles(articles), _client(client) {}

		virtual ~Command() {}

		virtual unsigned int get_total_price() const {
			unsigned int total = 0;
			for (size_t i = 0; i < _articles.size(); ++i) {
				total += (_articles[i] * 20);
			}
			return total;
		}

		unsigned int get_id() const { return _id; }
		const std::string& get_date() const { return _date; }
		const std::string& get_client() const { return _client; }
		const std::vector<unsigned int>& get_articles() const { return _articles; }
};