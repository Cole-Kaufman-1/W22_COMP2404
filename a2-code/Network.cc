#include "Network.h"

Network::Network(const string& name): name(name), numSubs(0), podArr(new PodArray()) {
}

Network::~Network() {
    for (int i = 0; i < numSubs; ++i){
        delete subs[i];
    }
    delete podArr;
}

bool Network::getPodcast(const string& podcast, Podcast** pod) const {
    return podArr->getPodcast(podcast, pod);
}

bool Network::addPodcast(const string& podcast, const string & host) {
    if(podArr->isFull()) return false;
    Podcast* tempPod = new Podcast(podcast, host);
    return podArr->addPodcast(tempPod);
    
}

bool Network::removePodcast(const string& podcast) {
    Podcast* tempPod;
    bool retVal = podArr->removePodcast(podcast, &tempPod);
    delete tempPod;
    return retVal;
}

bool Network::addEpisode(const string& podcast, const string& title, const string& content) {
    Podcast* tempPod;
    if(getPodcast(podcast, &tempPod)){
       return tempPod->addEpisode(title, content);
    }
    return false;
}

bool Network::addSubscriber(const string& name, const string& creditCard) {
    if (numSubs >= MAX_SUBS) return false;
    subs[numSubs] = new Subscriber(name, creditCard);
    ++numSubs;
    return true;
}

bool Network::download(const string& subscriber, const string& podcast, Podcast** pod) const{
    if (!getPodcast(podcast, pod)){
        cout << "No such podcast" << endl;
        *pod = NULL;
        return false;
    }
    if (!hasSubscriber(subscriber)){
        cout << "No such subscriber" << endl;
        *pod = NULL;
        return false;
    }
    return true;
}

bool Network::stream(const string& subscriber, const string& podcast, int episode, Episode** ep) const{
    Podcast* tempPod;
    if(!download(subscriber, podcast, &tempPod)){
        return false;
    }
    if (!tempPod->getEpisode(episode, ep)){
        cout << "No such episode" << endl;
        *ep = NULL;
        return false;
    }
    return true;
}

bool Network::hasSubscriber(const string& name) const {
    for (int i = 0; i < numSubs; ++i){
        if (subs[i]->matches(name)) return true;
    }
    return false;
}

void Network::print() const {
    cout << "Network: " << name << " with " << podArr->size() << " podcasts and " << numSubs << " subscribers." << endl;
    cout << "Podcasts in " << name << ": ";
    podArr->print();
    cout << "Subscribers in " << name << ": ";
    for (int i = 0; i < numSubs; ++i) {
        subs[i]->print();
    }
}