#pragma once

#include "command.hpp"

class PackageReductionDiscountCommand : public Command {
    public:
        PackageReductionDiscountCommand(unsigned int id, const std::string& date, const std::string& client, const std::vector<unsigned int>& articles)
            : Command(id, date, client, articles) {}

        unsigned int get_total_price() const {
            unsigned int total = Command::get_total_price();
            if (total > 150) {
                return total - 10;
            }
            return total;
        }
};