
#ifndef PODARRAY_H
#define PODARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Podcast.h"
#include "defs.h"

using namespace std;

class PodArray {
		
	public:
		//constructor
		PodArray();
		//copy constructor
		PodArray(PodArray&);
		
		//destructor
		~PodArray();
		
		//other
		/*
		* addPodcast(Podcast*): 
		* 
		* Creating an object outside of the class and 
		* adding the pointer, then deleting that object in the destructor
		* is a little unusual.
		* But this helps us when we "download" a Podcast to the Client. It
		* allows us to first make a deep copy of the Podcast, then add it 
		* to the Client's PodArray.
		*/
		bool addPodcast(Podcast*);
		bool getPodcast(const string& title, Podcast**) const;
		bool removePodcast(const string& title, Podcast**);
		int size() const;
		bool isFull() const;
		void print() const;
	
	private:
		int numPods;
		Podcast** podcasts;
};
#endif
