#include <string>
#include <unordered_map>
#include <vector>

typedef struct {
    std::string name;
    std::unordered_map<std::string, int> skills;
} User;

typedef struct {
    std::string name;
    std::unordered_map<std::string, int> requiredSkills;
    int duration;
    int score;
    int bestBefore;
} Project;