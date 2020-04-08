
#include "renderer.h"
#include "dirextx_render.h"
#include <cassert>

namespace grt {
	
	frame_info make_frame_info(const uint8_t* y, const uint8_t* u, const uint8_t* v,
		size_t y_pitch, size_t u_pitch, size_t v_pitch, int w, int h) {
		// copy y to buffer
		int size = (w*h * 3) / 2;
		unsigned char* yuv_buf = new unsigned char[size];
		unsigned char* temp = yuv_buf;
		for (int i = 0; i < h; i++){
			memcpy(temp,  y, y_pitch);
			y += y_pitch;
			temp += y_pitch;
	}
		//copy u to buffer
		for (int i = 0; i < (h/2); i++) {
			memcpy(temp, u, u_pitch);
			u += u_pitch;
			temp += w/2;
		}

		//copy v to buffer
		for (int i = 0; i < (h / 2); i++) {
			memcpy(temp, v, v_pitch);
			v += v_pitch;
			temp += w/2;
		}
		
		frame_info frame(yuv_buf, w, h, frame_type::YUV420);
		return frame;
	}

	frame_info make_frame_info(const char* data, int w, int h, int size, frame_type type) {
		assert(type == frame_type::RGB || type == frame_type::RGBA);
		unsigned char* rgb = new unsigned char[size];
		memcpy(rgb, data, size);
		return frame_info{ rgb, w, h, type };
	}

	void clean(frame_info info) {
		delete[]info.frame_data_;
	}

	std::unique_ptr<renderer>
		get_renderer() {
		return std::make_unique<directx_render>();
	}
}

