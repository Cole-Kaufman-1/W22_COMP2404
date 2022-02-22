#include "Podcast.h"
#include "defs.h"

Podcast::Podcast(string title, string host): title(title), host(host), numEps(0) {
    episodes = new Episode*[MAX_EPS];
}


Podcast::Podcast(const Podcast& pod): title(pod.title), host(pod.host), numEps(pod.numEps){
    Episode** eps = new Episode*[MAX_EPS];
    for (int i = 0; i < pod.numEps; ++i){
        Episode *newEp = pod.episodes[i];
        eps[i] = new Episode(*newEp);
    }
    episodes = eps;
}

Podcast::~Podcast(){
    for (int i = 0; i < numEps; ++i) {
        delete episodes[i];
    }
    delete [] episodes;
}

const string& Podcast::getTitle() const {
    return title;
}

const string& Podcast::getHost() const {
    return host;
}

int Podcast::getNumEpisodes() const {
    return numEps;
}

bool Podcast::addEpisode(const string& epTitle, const string& content){
    if (numEps >= MAX_EPS) return false;
    episodes[numEps++] = new Episode(this->title, numEps, epTitle, content);
    return true;
}

bool Podcast::getEpisode(int i, Episode** ep){
    if (i >= numEps || i < 0) {
        *ep = NULL;
        return false;
    }
    *ep = episodes[i];
    return true;
}

bool Podcast::lessThan(Podcast& pod) const {
    return this->title < pod.title;
}

void Podcast::print() const {
    cout << "Podcast: " << title << " hosted by: " << host << " with " << numEps << " episodes.\n" << endl;

    for (int i = 0; i < numEps; ++i) {
        episodes[i]->print();
    }
}