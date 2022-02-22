#include "Client.h"

Client::Client(const string& name): name(name), podArr(new PodArray()) {
}

Client::~Client() {
    delete podArr;
}

void Client::download(Network* network, const string& podcast) {
    if(podArr->isFull()){
        cout << "Podcast storage is full" << endl;
        return;
    }
    Podcast* tempPod;
    if(!network->download(name, podcast, &tempPod)){
        cout << "No such podcast was found" << endl;
        return;
    }
    podArr->addPodcast(new Podcast(*tempPod));
}

void Client::stream(Network* network, const string& podcast, int episode) const{
    Episode* tempEp;
    network->stream(name, podcast, episode, &tempEp);
    tempEp->play();
}

void Client::playLocal(const string& podcast, int episode) const {
    Podcast* tempPod;
    if (!podArr->getPodcast(podcast, &tempPod)){
        cout << "No such podcast was found" << endl;
        return;
    }
    Episode* tempEp;
    if (!tempPod->getEpisode(episode, &tempEp)){
        cout << "No such episode in podcast: " << tempPod->getTitle() << " was found" << endl; 
        return;
    }
    cout << "Playing episode locally:\n" << endl;
    tempEp->play();
}

void Client::print() const {
    cout << "Client " << name << " with " << podArr->size() << " local podcasts." <<endl;
    cout << "Local Podcasts are: ";
    podArr->print();
}