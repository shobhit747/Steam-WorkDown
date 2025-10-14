#pragma once
#include <nlohmann/json_fwd.hpp>

class fetch_download{
    private:
    std::string workshop_item_id;
    std::string consumer_app_id;
    std::string description;
    std::string file_size;
    std::string title;
    std::string preview_url;

    std::string user_define_download_path;

    void set_fetched_data(
        std::string title,
        std::string description,
        std::string file_size,
        std::string consumer_app_id,
        std::string preview_url
    );

    void display_data();

    public:
    fetch_download(std::string item_id);
    ~fetch_download();

    void fetch();

    void set_download_path(std::string path);
    void download();
};
