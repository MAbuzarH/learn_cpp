// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song
{
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;

public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const
    {
        return name;
    }
    std::string get_artist() const
    {
        return artist;
    }
    int get_rating() const
    {
        return rating;
    }

    bool operator<(const Song &rhs) const
    {
        return this->name < rhs.name;
    }

    bool operator==(const Song &rhs) const
    {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s)
{
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
    return os;
}

void display_menu()
{
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song)
{
    // This function should display
    // Playing: followed by the song that is playing

    std::cout << "You implement this function" << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song)
{
    // This function should display the current playlist
    // and then the current song playing.

    std::cout << "You implement this function" << std::endl;
}

void display_list(const std::list<Song> &playlist)
{
    for (auto &list : playlist)
    {
        std::cout << list << std::endl;
    }
}

int main()
{

    std::list<Song> playlist{
        {"God's Plan", "Drake", 5},
        {"Never Be The Same", "Camila Cabello", 5},
        {"Pray For Me", "The Weekend and K. Lamar", 4},
        {"The Middle", "Zedd, Maren Morris & Grey", 5},
        {"Wait", "Maroone 5", 4},
        {"Whatever It Takes", "Imagine Dragons", 3}};

    std::list<Song>::iterator current_song = playlist.begin();

    std::cout << "To be implemented" << std::endl;
    char input = '\0';
    std::string name;
    std::string artist;
    int rating;

    // display menue and take input;
    do
    {
        display_menu();
        // std::cout << "playing" << std::endl;
        // std::cout << *current_song << std::endl;
        std::cin >> input;

        if (input == 'A' || input == 'a')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // take input for new song
            std::cout << "Entre name of new song: ";
            getline(std::cin, name);
            // std::cin >> name;

            std::cout << "Entre artist of new song: ";
            getline(std::cin, artist);
            // std::cin >> artist;

            std::cout << "Entre reating of new song: ";
            std::cin >> rating;

            playlist.insert(current_song, Song(name, artist, rating));
        }

        // play first song in play list
        if (input == 'F' || input == 'f')
        {
            current_song = playlist.begin();
            std::cout << "Playing First song" << std::endl;
            std::cout << *current_song << std::endl;
        }

        // play next song in play list
        if (input == 'N' || input == 'n')
        {
            current_song++;
            std::cout << "Playing Next song" << std::endl;
            std::cout << *current_song << std::endl;
            if (current_song == playlist.end())
            {
                current_song = playlist.begin();
            }
        }
        if (input == 'P' || input == 'p')
        {
            if (current_song == playlist.begin())
            {
                current_song = playlist.end();
            }
            current_song--;
            std::cout << "Playing previous song" << std::endl;
            std::cout << *current_song << std::endl;
        }
        if (input == 'L' || input == 'l')
        {
            display_list(playlist);
        }

    } while (input != 'Q' && input != 'q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}