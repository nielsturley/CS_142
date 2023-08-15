//A Note regarding 'using namespace std':
// The author of this code prefers to not have the line 'using namespace std;'
// Instead, you will see 'std::' in front of string, cout, and other identifiers
// You could put 'using namespace std;' at the top of your code and not need 'std::' in front of these words,
// but many people consider it better practice to not have 'using namespace std;'


#include <iostream>
#include <string>
#include <vector>

#include "Playlist.h"


std::string GetUserString(const std::string& prompt);

void AddSongsMenuOption(vector<Song*> &library);
void ListSongsMenuOption(const vector<Song*> &library);
void AddPlaylistMenuOption(vector<Playlist> &listOfPlaylists);
void AddSongToPlaylistMenuOption(vector<Playlist> &listOfPlaylists, const vector<Song*> &library);
void ListPlaylistsMenuOption(const vector<Playlist> &listOfPlaylists);
void PlayPlaylistMenuOption(vector<Playlist> &listOfPlaylists);
void RemovePlaylistMenuOption(vector<Playlist> &listOfPlaylists);
void RemoveSongFromPlaylistMenuOption(vector<Playlist> &listOfPlaylists);
void RemoveSongFromLibraryMenuOption(vector<Playlist> &listOfPlaylists, vector<Song*> &library);
void OptionsMenuOption();
void QuitMenuOption(vector<Song*> &library);

void PrintPlaylists(const vector<Playlist> &listOfPlaylists);
void PrintSongsInLibrary(const vector<Song*> &library);

int main() {
    std::cout << "Welcome to the Firstline Player!  Enter options to see menu options." << std::endl << std::endl;

    vector<Song*> library;
    vector<Playlist> listOfPlaylists;


    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {
            AddSongsMenuOption(library);
        }
        else if (userMenuChoice == "list") {
            ListSongsMenuOption(library);
        }
        else if (userMenuChoice == "addp") {
            AddPlaylistMenuOption(listOfPlaylists);
        }
        else if (userMenuChoice == "addsp") {
            AddSongToPlaylistMenuOption(listOfPlaylists, library);
        }
        else if (userMenuChoice == "listp") {
            ListPlaylistsMenuOption(listOfPlaylists);
        }
        else if (userMenuChoice == "play") {
            PlayPlaylistMenuOption(listOfPlaylists);
        }
        else if (userMenuChoice == "remp") {
            RemovePlaylistMenuOption(listOfPlaylists);
        }
        else if (userMenuChoice == "remsp") {
            RemoveSongFromPlaylistMenuOption(listOfPlaylists);
        }
        else if (userMenuChoice == "remsl") {
            RemoveSongFromLibraryMenuOption(listOfPlaylists, library);
        }
        else if (userMenuChoice == "options") {
            OptionsMenuOption();
        }
        else if (userMenuChoice == "quit") {
            QuitMenuOption(library);
            continueMenuLoop = false;
        }
        else {
            OptionsMenuOption();
        }
    }

    return 0;
}


std::string GetUserString(const std::string& prompt) {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}
int GetUserInt(const std::string& prompt) {
    int userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}

void AddSongsMenuOption(vector<Song*> &library) {
    const std::string DONE_KEYWORD = "DONE";
    std::cout << "Enter songs' names and first lines"
    << " (type \"" << DONE_KEYWORD << "\" when done):" << std::endl;

    std::string songName = "none";
    std::string firstLine = "none";

    songName = GetUserString("Song Name: ");
    while (songName != DONE_KEYWORD) {
        firstLine = GetUserString("Song's first line: ");
        Song* newSongPointer = new Song(songName, firstLine);
        library.push_back(newSongPointer);
        songName = GetUserString("Song Name: ");
    }
}

void ListSongsMenuOption(const vector<Song*> &library) {
    for (unsigned int i = 0; i < library.size(); ++i) {
        library.at(i)->PrintSongInfo();
    }
}

void AddPlaylistMenuOption(vector<Playlist> &listOfPlaylists) {
    std::string playlistName = GetUserString("Playlist name: ");
    Playlist newPlaylist(playlistName);
    listOfPlaylists.push_back(newPlaylist);
}

void AddSongToPlaylistMenuOption(vector<Playlist> &listOfPlaylists, const vector<Song*> &library) {
    PrintPlaylists(listOfPlaylists);
    int playlistChoice = GetUserInt("Pick a playlist index number: ");
    PrintSongsInLibrary(library);
    int songChoice = GetUserInt("Pick a song index number: ");
    listOfPlaylists.at(playlistChoice).AddSong(library.at(songChoice));

}

void ListPlaylistsMenuOption(const vector<Playlist> &listOfPlaylists) {
    PrintPlaylists(listOfPlaylists);
}

void PlayPlaylistMenuOption(vector<Playlist> &listOfPlaylists) {
    PrintPlaylists(listOfPlaylists);
    int playlistChoice = GetUserInt("Pick a playlist index number: ");
    std::cout << std::endl;
    std::cout << "Playing songs from playlist: " << listOfPlaylists.at(playlistChoice).GetName() << std::endl;
    listOfPlaylists.at(playlistChoice).PlaySongs();
}

void RemovePlaylistMenuOption(vector<Playlist> &listOfPlaylists) {
    PrintPlaylists(listOfPlaylists);
    int playlistChoice = GetUserInt("Pick a playlist index number to remove: ");
    listOfPlaylists.erase(listOfPlaylists.begin() + playlistChoice);
}

void RemoveSongFromPlaylistMenuOption(vector<Playlist> &listOfPlaylists) {
    PrintPlaylists(listOfPlaylists);
    int playlistChoice = GetUserInt("Pick a playlist index number: ");
    listOfPlaylists.at(playlistChoice).PrintSongNames();
    int songChoice = GetUserInt("Pick a song index number to remove: ");
    listOfPlaylists.at(playlistChoice).RemoveSong(songChoice);
}

void RemoveSongFromLibraryMenuOption(vector<Playlist> &listOfPlaylists, vector<Song*> &library) {
    PrintSongsInLibrary(library);
    int songChoice = GetUserInt("Pick a song index number to remove: ");
    for (unsigned int i = 0; i < listOfPlaylists.size(); ++i) {
        listOfPlaylists.at(i).RemoveSong(library.at(songChoice));
    }
    delete library.at(songChoice);//DELETING POINTER HERE
    library.erase(library.begin() + songChoice);
}

void OptionsMenuOption() {
    std::cout << "add      Adds a list of songs to the library" << std::endl
    << "list     Lists all the songs in the library" << std::endl
    << "addp     Adds a new playlist" << std::endl
    << "addsp    Adds a song to a playlist" << std::endl
    << "listp    Lists all the playlists" << std::endl
    << "play     Plays a playlist" << std::endl
    << "remp     Removes a playlist" << std::endl
    << "remsp    Removes a song from a playlist" << std::endl
    << "remsl    Removes a song from the library (and all playlists)" << std::endl
    << "options  Prints this options menu" << std::endl
    << "quit     Quits the program" << std::endl << std::endl;
}

void QuitMenuOption(vector<Song*> &library) {
    std::cout << "Goodbye!" << std::endl;
    if (library.size() != 0) {
        for (unsigned int i = (library.size() - 1); i > 0; --i) {
            delete library.at(i);//DELETING ALL POINTERS HERE
            library.erase(library.begin() + i);
        }
    }
}

void PrintPlaylists(const vector<Playlist> &listOfPlaylists) {
    for (unsigned int i = 0; i < listOfPlaylists.size(); ++i) {
        std::cout << "  " << i << ": " << listOfPlaylists.at(i).GetName() << std::endl;
    }
}

void PrintSongsInLibrary(const vector<Song*> &library) {
    for (unsigned int i = 0; i < library.size(); ++i) {
        std::cout << "  " << i << ": " << library.at(i)->GetName() << std::endl;
    }
}