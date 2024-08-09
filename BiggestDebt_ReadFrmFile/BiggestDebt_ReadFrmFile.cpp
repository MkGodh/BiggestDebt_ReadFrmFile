#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

int main()
{
    std::string current_string;
    std::ifstream statement;
    statement.open("Vedomost.txt", std::ios::binary);

    int debt = 0;
    int maxdebt = 0;
    int totaldebt = 0;
    std::string name_part_one;
    std::string name_part_two;
    std::string biggest_state_owner;

    if (!statement.is_open())
    {
        std::cerr << "Fail to open file or mistake in a path to it" << std::endl;
        return 1;
    }

    while (std::getline(statement, current_string)) {
        std::istringstream iss(current_string);
        iss >> name_part_one >> name_part_two >> debt;

        if (debt > maxdebt) {
            biggest_state_owner = name_part_one + " " + name_part_two;
            maxdebt = debt;
        }
        totaldebt += debt;
        debt = 0;
    }

    std::cout << "Max debt owner is: " << biggest_state_owner << ", he(s/r) debt is: " << maxdebt << " Total debt is: " << totaldebt;



    return  0;
}

