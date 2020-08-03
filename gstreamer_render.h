#ifndef __GSTREAMER_RENDERER_H__
#define __GSTREAMER_RENDERER_H__
#include "renderer.h"
namespace grt {
	class gstreamer_renderer : public renderer {
	public:
		~gstreamer_renderer() override;
		void render_frame(void* hwnd, frame_info frame) override;
		void render_name(void* hwnd, std::string name) override;
		void set_active(bool flag) override;
	private:
		int width_{};
		int heigh_{};
		std::string gstreamer_id_;
	};

	std::unique_ptr<renderer> get_gstreamer_renderer();
}


#endif//__GSTREAMER_RENDERER_H__