//
// Created by Niels Turley on 11/23/20.
//

#ifndef MAIN_LAB_8_PLAYLIST_H
#define MAIN_LAB_8_PLAYLIST_H

#include "Song.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Playlist {
public:
    Playlist(string name = "NoName");
    string GetName() const;
    void AddSong(Song* songToAdd);
    void RemoveSong(Song* songToRemove);
    void RemoveSong(int songToRemove);
    void PrintSongNames() const;
    void PlaySongs();



private:
    vector<Song*> songList;
    string playlistName;
};

#endif //MAIN_LAB_8_PLAYLIST_H
