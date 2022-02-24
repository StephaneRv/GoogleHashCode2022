#define UNUSED __attribute__((unused))

#include <fstream>
#include <sstream>
#include <iostream>
#include <DataStructs.hpp>
#include "Parser.hpp"

int main(UNUSED int ac, UNUSED char *av[])
{
    std::ifstream inFile;
    std::string line;

    inFile.open("datasets/a_an_example.in.txt");
    std::getline(inFile, line);

    std::vector<std::string> skills;
    auto splittedLine = Parser::getArgs(line);
    std::vector<User> users(std::stoi(splittedLine[0]));
    std::vector<Project> projects(std::stoi(splittedLine[1]));

    for (std::size_t i = 0; i < users.size(); i++)
    {
        std::getline(inFile, line);
        splittedLine = Parser::getArgs(line);
        users[i].name = splittedLine[0];
        for (int j = 0; j < std::stoi(splittedLine[1]); j++)
        {
            std::getline(inFile, line);
            auto skillArgs = Parser::getArgs(line);
            skills.push_back(skillArgs[0]);
            users[i].skills.insert({skillArgs[0], std::stoi(skillArgs[1])});
        }
        // std::cout << "name is: " << users[i].name << std::endl;
        // for (const auto &it : users[i].skills) {
        //     std::cout << "skill is: " << it.first << " level is: " << it.second << std::endl;
        // }
        // std::cout << std::endl;
    }
    // std::cout << std::endl;
    // std::cout << std::endl;
    for (std::size_t i = 0; i < projects.size(); i++)
    {
        std::getline(inFile, line);
        splittedLine = Parser::getArgs(line);
        projects[i].name = splittedLine[0];
        projects[i].duration = std::stoi(splittedLine[1]);
        projects[i].score = std::stoi(splittedLine[2]);
        projects[i].bestBefore = std::stoi(splittedLine[3]);
        for (int j = 0; j < std::stoi(splittedLine[4]); j++)
        {
            std::getline(inFile, line);
            auto skillArgs = Parser::getArgs(line);
            skills.push_back(skillArgs[0]);
            projects[i].requiredSkills.insert({skillArgs[0], std::stoi(skillArgs[1])});
        }
        // std::cout << "name is: " << projects[i].name << std::endl;
        // std::cout << "duration is: " << projects[i].duration << std::endl;
        // std::cout << "score is: " << projects[i].score << std::endl;
        // std::cout << "bestBefore is: " << projects[i].bestBefore << std::endl;
        // for (const auto &it : projects[i].requiredSkills) {
        //     std::cout << "skill is: " << it.first << " level is: " << it.second << std::endl;
        // }
        // std::cout << std::endl;
    }

    return 0;
}