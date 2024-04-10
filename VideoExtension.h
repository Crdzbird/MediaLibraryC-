//
// Created by Luis Cardoza Bird on 9/4/24.
//

#ifndef HEALER_VIDEO_LIBRARY_VIDEOEXTENSION_H
#define HEALER_VIDEO_LIBRARY_VIDEOEXTENSION_H

#include "vector"
#include "string"

double getVideoDuration(const std::string& filePath);
double getVideoDuration(FILE* file);
double getAudioDuration(const std::string& audioPath);
double getAudioDurationFromFile(FILE* file);
bool isValidAudioFile(const std::string& filePath);
bool isValidVideoFile(const std::string& filePath);

#endif //HEALER_VIDEO_LIBRARY_VIDEOEXTENSION_H
