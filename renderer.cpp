
#include "renderer.h"
#include "dirextx_render.h"
#include "gstreamer_render.h"

namespace grt {

	std::unique_ptr<renderer>
		get_renderer() {
		return get_gstreamer_renderer();
		//return std::make_unique<directx_render>();
	}
}

