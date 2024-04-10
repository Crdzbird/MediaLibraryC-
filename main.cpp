//
// Created by Luis Cardoza Bird on 10/4/24.
//

#include <iostream>
#include "VideoExtension.h"
#include <libavformat/avformat.h>

int main() {
std::string filename = "/Users/crdzbird/Desktop/peruano.mp4";

// Check if the file extension is valid
std::string extension = filename.substr(filename.find_last_of(".") + 1);

// Get the duration of the video file
int duration = getVideoDuration(filename);
if (duration == -1) {
std::cerr << "Error: Failed to get video duration.\n";
return 1;
}

// Display the duration
std::cout << "Duration of " << filename << ": " << duration << " seconds\n";

return 0;
}
