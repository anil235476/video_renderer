#ifndef __RENDERER__
#define __RENDERER__
#include <memory>
#include <string>
#include <frame_info.h>
namespace grt {

	class renderer {
	public:
		virtual void render_frame(void* hwnd, frame_info frame)=0;
		virtual void render_name(void* hwnd, std::string name) = 0;
		virtual void set_active(bool flag) = 0;
	};

	std::unique_ptr<renderer>
		get_renderer();
}

#endif // !__RENDERER__

