#ifndef NETWORK_H
#define NETWORK_H

#include "Subscriber.h"
#include "Podcast.h"
#include "PodArray.h"

class Network{
    public:
        Network(const string&);
        ~Network();

        //get elems from collections
        bool getPodcast(const string&, Podcast**) const;

        //add and remove
        bool addPodcast(const string&, const string&);
        bool removePodcast(const string&);
        bool addEpisode(const string&, const string&, const string&);
        bool addSubscriber(const string&, const string&);

        //client services
        bool download(const string&, const string&, Podcast**) const;
        bool stream(const string&, const string&, int, Episode**) const;
        bool hasSubscriber(const string&) const;

        //other
        void print() const;

    private:
        string name;
        PodArray* podArr;
        Subscriber* subs[MAX_SUBS];
        int numSubs;
};

#endif