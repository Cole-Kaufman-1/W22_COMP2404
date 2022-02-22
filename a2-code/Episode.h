#ifndef EPISODE_H
#define EPISODE_H

#include <string>
#include <iostream>

using namespace std;

class Episode {
    public:
        Episode(const string& podcast, int number, const string& name, const string& content);
        void play() const;
        void print() const;

    private:
        const string name, content, podcast; 
        const int number;
};

#endif