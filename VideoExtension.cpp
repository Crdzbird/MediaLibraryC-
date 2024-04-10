//
// Created by Luis Cardoza Bird on 9/4/24.
//

#include "VideoExtension.h"
#include <cstdlib>
#include <string>
extern "C" {
#include <libavformat/avformat.h>
}


double getVideoDuration(const std::string& filePath) {
    AVFormatContext* formatContext = nullptr;

    // Open video file
    if (avformat_open_input(&formatContext, filePath.data(), nullptr, nullptr) != 0) {
        avformat_close_input(&formatContext);
        return -1; // Error opening file
    }

    // Retrieve stream information
    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        avformat_close_input(&formatContext);
        return -1; // Error finding stream information
    }

    double duration = static_cast<double>(formatContext->duration) / AV_TIME_BASE;

    // Close the video file
    avformat_close_input(&formatContext);

    return duration;
}

double getVideoDuration(FILE* file) {
    AVFormatContext* formatContext = nullptr;

    // Open video file
    if (avformat_open_input(&formatContext, nullptr, nullptr, nullptr) != 0) {
        avformat_close_input(&formatContext);
        return -1; // Error opening file
    }

    // Retrieve stream information
    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        avformat_close_input(&formatContext);
        return -1; // Error finding stream information
    }

    double duration = static_cast<double>(formatContext->duration) / AV_TIME_BASE;

    // Close the video file
    avformat_close_input(&formatContext);

    return duration;
}

double getAudioDurationFromFile(FILE* file) {
    AVFormatContext* formatContext = nullptr;

    // Open audio file
    if (avformat_open_input(&formatContext, nullptr, nullptr, nullptr) != 0) {
        avformat_close_input(&formatContext);
        return -1; // Error opening file
    }

    // Retrieve stream information
    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        avformat_close_input(&formatContext);
        return -1; // Error finding stream information
    }

    double duration = 0;

    // Find the audio stream
    for (unsigned int i = 0; i < formatContext->nb_streams; ++i) {
        if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO) {
            duration = static_cast<double>(formatContext->duration) / AV_TIME_BASE;
            break;
        }
    }

    // Close the audio file
    avformat_close_input(&formatContext);

    return duration;
}

double getAudioDuration(const std::string& audioPath) {
    AVFormatContext* formatContext = nullptr;

    // Open audio file
    if (avformat_open_input(&formatContext, audioPath.data(), nullptr, nullptr) != 0) {
        avformat_close_input(&formatContext);
        return -1; // Error opening file
    }

    // Retrieve stream information
    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        avformat_close_input(&formatContext);
        return -1; // Error finding stream information
    }

    double duration = 0;

    // Find the audio stream
    for (unsigned int i = 0; i < formatContext->nb_streams; ++i) {
        if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO) {
            duration = static_cast<double>(formatContext->duration) / AV_TIME_BASE;
            break;
        }
    }

    // Close the audio file
    avformat_close_input(&formatContext);

    return duration;
}

bool isValidAudioFile(const std::string& filePath) {
    // Initialize FFmpeg's network module
    avformat_network_init();

    // Get input format context
    AVFormatContext* formatContext = avformat_alloc_context();
    if (!formatContext)
        return false;

    // Open audio file
    if (avformat_open_input(&formatContext, filePath.data(), nullptr, nullptr) != 0) {
        avformat_close_input(&formatContext);
        return false; // Error opening file
    }

    // Close the audio file
    avformat_close_input(&formatContext);

    return true;
}

bool isValidVideoFile(const std::string& filePath) {
    // Initialize FFmpeg's network module
    avformat_network_init();

    // Get input format context
    AVFormatContext* formatContext = avformat_alloc_context();
    if (!formatContext)
        return false;

    // Open video file
    if (avformat_open_input(&formatContext, filePath.data(), nullptr, nullptr) != 0) {
        avformat_close_input(&formatContext);
        return false; // Error opening file
    }

    // Close the video file
    avformat_close_input(&formatContext);

    return true;
}
