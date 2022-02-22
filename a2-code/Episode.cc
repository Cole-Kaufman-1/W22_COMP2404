#include "Episode.h"

Episode::Episode(const string& podcast, int number, const string& name, const string& content): podcast(podcast), number(number), name(name), content(content) {
}

void Episode::play() const{
    cout << "Episode from Podcast: " << podcast << "\n   Episode: " << name << " #" << number << "\n   Content " << content <<endl;
}

void Episode::print() const{
    cout << "Episode #" << number << " called: " << name << " from podcast: " << podcast <<endl;
}