#ifndef PODCAST_H
#define PODCAST_H

#include "Episode.h"

class Podcast{
    public:
        Podcast(string title, string host);
        Podcast(const Podcast& pod);
        ~Podcast();

        const string& getTitle() const;
        const string& getHost() const;
        int getNumEpisodes() const;
        bool addEpisode(const string& title, const string& content);
        bool getEpisode(int index, Episode** ep) const;
        bool lessThan(Podcast& pod) const;
        void print() const;
        
    private:
        const string title, host;
        Episode** episodes;
        int numEps;

};

#endif