// #include <iostream>

// using namespace std;

// class Team
// {
// private:
//     int Score;
//     int Wickets;

// public:
//     Team(int score = 0, int wickets = 0) : Score(score), Wickets(wickets)
//     {
//     }

//     void setScore(int score) { Score = score; }
//     void setWickets(int wickets) { Wickets = wickets; }

//     int getScore() { return Score; }
//     int getWickets() { return Wickets; }
// };

// int main()
// {
//     int score, wickets;
//     Team *T = new Team[4];

//     for (int i = 0; i < 2; i++)
//     {
//         cout << "** enter data for :" << i + 1 << endl;
//         cout << "enter score for Team " << i + 1 << " : ";
//         cin >> score;

//         cout << "enter wickets for Team " << i + 1 << " : ";
//         cin >> wickets;

//         // Team T1;
//         T[i].setScore(score);
//         T[i].setWickets(wickets);
//         cout << "Team " << i + 1 << " has scores: " << T[i].getScore() << " and wickets: " << T[i].getWickets() << endl;
//     }

//     cout << "** Team 3 created (default):" << endl;
//     cout << "Team 3 has scores: " << T[2].getScore() << " and wickets" << T[2].getWickets() << endl;

//     cout << "** Team 4 created (parametrized):" << endl;
//     new (&T[3]) Team(190, 6);
//     cout << "Team 3 has scores: " << T[3].getScore() << " and wickets" << T[3].getWickets() << endl;

//     int index;
//     int maxscore = T[0].getScore();
//     for (int i = 0; i < 3; i++)
//     {
//         if (T[i].getWickets() >= 6)
//         {
//             cout << "Team " << i + 1 << " Has 6 wickets" << endl;
//         }
//         if (maxscore <= T[i].getScore())
//         {
//             maxscore = T[i].getScore();
//             index = i;
//         }
//     }

//     cout << "The max scoure for Team: " << index + 1 << " has " << T[index].getScore() << endl;

//     delete[] T;
//     return 0;
// }

// optimized soluthion
#include <iostream>
#include <vector>

using namespace std;

class Team
{
private:
    int Score;
    int Wickets;

public:
    // Constructor with default values
    Team(int score = 0, int wickets = 0) : Score(score), Wickets(wickets) {}

    void setScore(int score) { Score = score; }
    void setWickets(int wickets) { Wickets = wickets; }

    int getScore() const { return Score; }
    int getWickets() const { return Wickets; }
};

int main()
{
    int score, wickets;
    vector<Team> teams(4); // Vector to manage teams

    // Input for the first two teams
    for (int i = 0; i < 2; i++)
    {
        cout << "** Enter data for Team " << i + 1 << " **" << endl;
        cout << "Enter score: ";
        cin >> score;
        cout << "Enter wickets: ";
        cin >> wickets;

        teams[i] = Team(score, wickets);

        cout << "Team " << i + 1 << " has score: " << teams[i].getScore() << " and wickets: " << teams[i].getWickets() << endl;
    }

    // Default and parameterized team creations
    cout << "** Team 3 created (default):" << endl;
    cout << "Team 3 has score: " << teams[2].getScore() << " and wickets: " << teams[2].getWickets() << endl;

    cout << "** Team 4 created (parameterized):" << endl;
    teams[3] = Team(190, 6);
    cout << "Team 4 has score: " << teams[3].getScore() << " and wickets: " << teams[3].getWickets() << endl;

    // Finding the maximum score and checking for wickets >= 6
    int maxIndex = 0;
    for (int i = 0; i < 4; i++)
    {
        if (teams[i].getWickets() >= 6)
        {
            cout << "Team " << i + 1 << " has 6 or more wickets." << endl;
        }

        if (teams[i].getScore() > teams[maxIndex].getScore())
        {
            maxIndex = i;
        }
    }

    cout << "The highest score is by Team " << maxIndex + 1 << " with " << teams[maxIndex].getScore() << " runs." << endl;

    return 0;
}
