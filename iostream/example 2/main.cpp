#include <iostream>
#include <fstream>
#include <iomanip>

void print_header()
{
    std::cout << std::setw(20) << std::left << "Student" << std::setw(20) << std::right << "Grade" << std::endl;

    // seting empty spaces
    std::cout << std::setfill('-');

    std::cout << std::setw(40) << std::left << "--" << std::endl;
}

void print_fotter()
{
    std::cout << std::setfill('-');
    std::cout << std::setw(40) << std::left << "--" << std::endl;
}

int process(std::string responce, std::string key)
{
    int score = 0;
    for (int i = 0; i < key.size(); i++)
    {
        if (responce[i] == key[i])
        {
            score = score + 1;
        }
    }
    return score;
}
int main()
{
    std::fstream in_file;
    std::string key{};
    std::string name{};
    std::string responce{};
    int running_sum = 0;
    int total_students = 0;
    double avr_score = 0.0;
    in_file.open("responces.txt");
    if (!in_file)
    {
        std::cout << "Error: Cannot open \n";
        return 1;
    }
    // otput portion

    // std::getline(in_file, key);
    in_file >> key;
    // printing header
    print_header();

    // content to show
    while (in_file >> name >> responce)
    {
        ++total_students;
        int score = process(responce, key);
        std::cout << std::setfill(' ');
        std::cout << std::setw(20) << std::left << name << std::setw(20) << std::right << score << std::endl;
        running_sum += score;
    }

    // fotter
    print_fotter();

    if (total_students != 0)
    {
        avr_score = static_cast<double>(running_sum) / total_students;
        std::cout << std::setfill(' ');
        std::cout << std::setw(20) << std::left << "avrage" << std::setw(20) << std::right << avr_score << std::endl;
    }

    in_file.close();
    return 0;
}