#include <iostream>
#include "command.hpp"
#include "thuesdayDiscount.hpp"
#include "packageReductionDiscount.hpp"


int main() {
	std::vector<unsigned int> my_articles;
	my_articles.push_back(8); // 4 articles, price = 80

	Command normal_cmd(1, "Monday", "John", my_articles);
	ThuesdayDiscountCommand thuesday_cmd(2, "Thuesday", "Jane", my_articles);
	PackageReductionDiscountCommand pack_cmd(3, "Friday", "Jack", my_articles);

	std::cout << "--- OCP Discount Demonstration ---" << std::endl;
	// ! Normal Command: 160 euros
	std::cout << "Normal Command Total: " << normal_cmd.get_total_price() << " euros" << std::endl;
	
	// ! ThuesdayDiscountCommand: 10% off since it's "Thuesday" -> 160 - 16 = 144
	std::cout << "Thuesday Command Total: " << thuesday_cmd.get_total_price() << " euros" << std::endl;
	
	// ! PackageReductionDiscountCommand: 10 off if > 150 -> 160 - 10 = 150
	std::cout << "Package Reduction Command Total: " << pack_cmd.get_total_price() << " euros" << std::endl;

	return 0;
}