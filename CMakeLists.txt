cmake_minimum_required(VERSION 3.7)

add_definitions(/ZI)

add_library(video_render
	renderer.h
	renderer.cpp
	dirextx_render.h
	dirextx_render.cpp
	)

target_include_directories(video_render PUBLIC 
	 $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	#$<BUILD_INTERFACE:${ABSL_PATH}>
	)
target_link_libraries(video_render 
 PUBLIC
 utility
 )