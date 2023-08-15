//
// Created by Niels Turley on 11/23/20.
//
#include "Song.h"
#include <iostream>

using std::cout;
using std::endl;

Song::Song(string name, string firstLine) {
    songName = name;
    songFirstLine = firstLine;
    songTimesPlayed = 0;
}

void Song::SetName(string name) {
    songName = name;
}

string Song::GetName() const {
    return songName;
}

void Song::SetFirstLine(string firstLine) {
    songFirstLine = firstLine;
}

string Song::GetFirstLine() const {
    return songFirstLine;
}

int Song::GetTimesPlayed() const {
    return songTimesPlayed;
}

void Song::PrintSongInfo() const {
    cout << songName << ": \"" << songFirstLine << "\", " << songTimesPlayed << " play(s)." << endl;
}

void Song::IncrementTimesPlayed() {
    ++songTimesPlayed;
}








