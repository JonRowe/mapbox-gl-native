#include <mbgl/util/uv.hpp>

#include <uv.h>

namespace uv {

std::string cwd() {
#if UV_VERSION_MAJOR == 0 && UV_VERSION_MINOR <= 10
    char dir[512];
    uv_cwd(dir, 512);
    return dir;
#else
    size_t max = 0;
    std::string dir;
    do {
        max += 256;
        dir.resize(max);
        uv_cwd(const_cast<char *>(dir.data()), &max);
    } while (max == dir.size());
    dir.resize(max - 1);
    return dir;
#endif
}

}
