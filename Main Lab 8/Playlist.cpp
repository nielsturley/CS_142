//
// Created by Niels Turley on 11/23/20.
//
#include "Playlist.h"

Playlist::Playlist(string name) {
    playlistName = name;
    vector<Song*> songList;

}

void Playlist::AddSong(Song* songToAdd) {
    songList.push_back(songToAdd);
}

string Playlist::GetName() const {
    return playlistName;
}

void Playlist::RemoveSong(Song* songToRemove) {
    for (unsigned int i = 0; i < songList.size(); ++i) {
        if (songToRemove == songList.at(i)) {
            songList.erase(songList.begin() + i);
        }
    }
}

void Playlist::PrintSongNames() const {
    for (unsigned int i = 0; i < songList.size(); ++i) {
        cout << "  " << i << ": " << songList.at(i)->GetName() << endl;
    }
}

void Playlist::PlaySongs() {
    for (unsigned int i = 0; i < songList.size(); ++i) {
        cout << songList.at(i)->GetFirstLine() << endl;
        songList.at(i)->IncrementTimesPlayed();
    }
}

void Playlist::RemoveSong(int songToRemove) {
    songList.erase(songList.begin() + songToRemove);
}

