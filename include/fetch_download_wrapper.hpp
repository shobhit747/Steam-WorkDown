#pragma once

#ifdef __cplusplus
extern "C" {
#endif
    typedef struct fetch_download fetch_download;
    fetch_download* fetch_download_c(char* item_id);
    void fetch_download_c_fetch(fetch_download* object);
    void fetch_download_c_download(fetch_download* object);
    void fetch_download_c_delete(fetch_download* object);
#ifdef __cplusplus
}
#endif
