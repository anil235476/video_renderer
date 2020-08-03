#include "gstreamer_render.h"
#include <cassert>
#include "gstreamer_interface.h"
namespace grt {


	void gstreamer_renderer::render_frame(void* hwnd, frame_info frame) {
		if (frame.width_ != width_ || frame.height_ != heigh_) {
			assert(gstreamer_id_.empty());//todo: when it is false need to handle by reseting source
			gstreamer_id_ = gst::allocate_source(frame);
			assert(!gstreamer_id_.empty());
			width_ = frame.width_;
			heigh_ = frame.height_;
		}

		assert(!gstreamer_id_.empty());//id should be valid
		gst::on_frame(frame, gstreamer_id_);

	}
	
	void gstreamer_renderer::render_name(void* hwnd, std::string name) {
		//todo: handle this 
	}

	void gstreamer_renderer::set_active(bool flag) {
		//todo: handle this
	}

	std::unique_ptr<renderer> get_gstreamer_renderer() {
		return std::make_unique< gstreamer_renderer>();
	}

}