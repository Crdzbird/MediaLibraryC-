cmake_minimum_required(VERSION 3.27)
project(healer_video_library)

set(CMAKE_CXX_STANDARD 17)

include_directories(/opt/homebrew/Cellar/ffmpeg/7.0-with-options_1/include)

link_directories(/opt/homebrew/Cellar/ffmpeg/7.0-with-options_1/lib)

add_executable(healer_video_library
        VideoExtension.cpp
        VideoExtension.h
        main.cpp
        main.cpp
)

target_link_libraries(healer_video_library avcodec avformat avutil)