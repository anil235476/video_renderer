
#include "renderer.h"
#include "dirextx_render.h"

namespace grt {

	std::unique_ptr<renderer>
		get_renderer() {
		return std::make_unique<directx_render>();
	}
}

