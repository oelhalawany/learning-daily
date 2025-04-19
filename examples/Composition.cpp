#include <iostream>
#include <vector>
#include <string>

// Player class
class Player {
private:
    std::string name;
    int age;
    std::string position;

public:
    Player(const std::string& name, int age, const std::string& position)
        : name(name), age(age), position(position) {}

    void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << ", Position: " << position << std::endl;
    }
};

// Team class
class Team {
private:
    std::string teamName;
    std::vector<Player> players;

public:
    Team(const std::string& teamName) : teamName(teamName) {}

    void addPlayer(const Player& player) {
        players.push_back(player);
    }

    void displayTeam() const {
        std::cout << "Team: " << teamName << std::endl;
        for (const auto& player : players) {
            player.displayInfo();
        }
    }

    // Overload the + operator to add a player to the team
    Team operator+(const Player& player) {
        Team out = *this;
        out.players.push_back(player);
        return out;
    }
};

int main() {
    // Create a team
    Team team("Dream Team");

    // Add players to the team
    team.addPlayer(Player("Alice", 25, "Forward"));
    team.addPlayer(Player("Bob", 22, "Midfielder"));
    team.addPlayer(Player("Charlie", 28, "Defender"));

    // Display team information
    team.displayTeam();

    team = team + Player("Diana", 24, "Goalkeeper");

    // Display updated team information
    team.displayTeam();
    return 0;
}