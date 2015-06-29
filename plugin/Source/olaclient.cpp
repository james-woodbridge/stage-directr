#include <stdlib.h>
#include <unistd.h>
#include <ola/DmxBuffer.h>
#include <ola/Logging.h>
#include <ola/client/StreamingClient.h>
#include <iostream>
#include <fstream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
int main() {
	char input;
	unsigned int universe = 1; 		// universe to use for sending data
	unsigned int perFixture = 4; 	//number of channels per fixture
	unsigned int totalFixtures = 18;	//total number of fixtures
	unsigned int start = 0;			//Starting DMX channel, usually 0 or 4
	float refreshRate = 0.8;			//refresh rate in Hz
	char c[16];
	int r,g,b;
	std::fstream myFile;
	myFile.open("~/StageDirector/centroid.txt", std::fstream::in);
	myFile.getline(c, 16);
	float centroid = atof(c);
	int refreshU = 1000000/refreshRate; //refresh in useconds
	unsigned int totalChannels = perFixture * totalFixtures; //Total number of DMX channels
	// turn on OLA logging
	ola::InitLogging(ola::OLA_LOG_WARN, ola::OLA_LOG_STDERR);
	ola::DmxBuffer buffer; // A DmxBuffer to hold the data.
	buffer.Blackout(); // Set all channels to 0
	// Create a new client.
	ola::client::StreamingClient ola_client((ola::client::StreamingClient::Options()));
	// Setup the client, this connects to the server
	if (!ola_client.Setup()) {
		std::cerr << "Setup failed" << endl;
		exit(1);
	}
	while(input != 'q'){
		myFile.getline(c, 16);
		centroid = atof(c);
		r = (int)255 - ((255/3)*centroid) + 50;
		g = (int)255*(centroid-2.4);
		b = (int)255*(centroid - 2.8);
		if(r >=255) r = 255;
		if(g >=255) r = 255;
		if(b >=255) r = 255;
		if(r <0) r = 0;
		if(g <0) g = 0;
		if(b <0) b = 0;
		for (int i = start; i < totalChannels; i+=perFixture){
			buffer.SetChannel(i , 255);
			buffer.SetChannel(i+1, r);
			buffer.SetChannel(i+2, g);
			buffer.SetChannel(i+3, b);
		}
	if (!ola_client.SendDmx(universe, buffer)) {
		cout << "Send DMX failed" << endl;
		exit(2);
		}
	usleep(refreshU); // sleep for 1s between frames.
	cin >> input;
	}
	return 0;
}