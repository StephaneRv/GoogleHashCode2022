#include <string>
#include <unordered_map>
#include <vector>

// std::vector<std::string> Skills;

typedef struct {
    std::string name;
    std::unordered_map<std::string, int> skills;
} User;

typedef struct {
    std::string name;
    int duration;
    int score;
    int bestBefore;
} Project;