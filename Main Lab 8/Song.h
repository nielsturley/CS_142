//
// Created by Niels Turley on 11/23/20.
//

#ifndef MAIN_LAB_8_SONG_H
#define MAIN_LAB_8_SONG_H

#include <string>

using std::string;

class Song {
public:
    Song(string name = "NoName", string firstLine = "NoLyrics");
    void SetName(string name);
    string GetName() const;
    void SetFirstLine(string firstLine);
    string GetFirstLine() const;
    int GetTimesPlayed() const;
    void PrintSongInfo() const;
    void IncrementTimesPlayed();




private:
    string songName;
    string songFirstLine;
    int songTimesPlayed;
};

#endif //MAIN_LAB_8_SONG_H
