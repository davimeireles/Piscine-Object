#pragma once

#include "command.hpp"

class ThuesdayDiscountCommand : public Command {
    public:
        ThuesdayDiscountCommand(unsigned int id, const std::string& date, const std::string& client, const std::vector<unsigned int>& articles)
            : Command(id, date, client, articles) {}

        unsigned int get_total_price() const {
            unsigned int total = Command::get_total_price();
            if (get_date() == "Thuesday" || get_date() == "Tuesday") {
                return total - (total * 10 / 100);
            }
            return total;
        }
};