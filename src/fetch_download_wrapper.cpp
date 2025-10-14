#include "fetch_download_wrapper.hpp"
#include "fetch_download.hpp"
#ifdef __cplusplus
extern "C" {
#endif
    fetch_download* fetch_download_c(char* item_id){ return new fetch_download(item_id); }
    void fetch_download_c_fetch(fetch_download* object){ object->fetch(); }
    void fetch_download_c_set_download_path(fetch_download* object,const char *path)
        { object->set_download_path(std::string(path)); }
    void fetch_download_c_download(fetch_download* object){ object->download(); }
    void fetch_download_c_delete(fetch_download* object){ delete object; }
#ifdef __cplusplus
}
#endif