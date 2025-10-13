#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "fetch_download.hpp"
#include <nlohmann/json.hpp>
#include <httplib.h>
#include <filesystem>
#define RED "\033[31m" 
#define RESET "\033[0m"

namespace fs = std::filesystem;

fetch_download::fetch_download(std::string item_id)
    : workshop_item_id(item_id) {}

void fetch_download::set_fetched_data(
    std::string title, std::string description, std::string file_size,
    std::string consumer_app_id, std::string preview_url
){
    std::string temp;
    if(description.size() > 100){
        for(int i = 0; i < 50; i++){
            temp += description[i];
        }
    }
    description = temp + "...";
    this->title = title;
    this->description = description;
    this->file_size = file_size;
    this->preview_url = preview_url;
    this->consumer_app_id = consumer_app_id;
}

void fetch_download::display_data(){
    std::cout << "====== Workshop Item Details ======\n" ;
    std::cout << "Workshop ID : " << workshop_item_id << std::endl;
    std::cout << "Title : " << title << std::endl;
    std::cout << "Description : " << description << std::endl;
    std::cout << "Size : " << file_size << std::endl;
    std::cout << "Image preview : " << preview_url << std::endl;
    std::cout << "Consumer App ID : " << consumer_app_id << std::endl;
    std::cout << "====================================" << std::endl;

}

void fetch_download::fetch(){
    std::string workshop_api_url = "https://api.steampowered.com";
    std::string workshop_api_endpoint = "/ISteamRemoteStorage/GetPublishedFileDetails/v1/";
    
    httplib::Client client(workshop_api_url);


    httplib::Params parameters;
    std::pair<std::string, std::string> itemcount(
        "itemcount",
        "1"
    );
    std::pair<std::string, std::string> publishedfileids(
        "publishedfileids[0]",
        workshop_item_id
    );
    parameters.insert(itemcount);
    parameters.insert(publishedfileids);
    
    httplib::Result response = client.Post(workshop_api_endpoint,parameters);

    if(response){
        nlohmann::json json;
        nlohmann::json workshop_item_data;
        workshop_item_data = json.parse(response->body);
        workshop_item_data = workshop_item_data["response"];
        workshop_item_data = workshop_item_data["publishedfiledetails"][0];

        std::string consumer_app_id = std::to_string(workshop_item_data["consumer_app_id"].get<int>());

        set_fetched_data(
            workshop_item_data["title"],
            workshop_item_data["description"],
            workshop_item_data["file_size"],
            consumer_app_id,
            workshop_item_data["preview_url"]
        );

    }else{
        std::cout << RED << httplib::to_string(response.error() ) << std::endl;
    }
}

void fetch_download::set_download_path(std::string path){
    user_define_download_path = path;
}

void fetch_download::download(){

    std::string steamcmd_download_command = 
        "./SteamCMD/steamcmd.sh +force_install_dir "
        + fs::current_path().string() + " "
        + "+login anonymous +workshop_download_item "
        + consumer_app_id + " " + workshop_item_id + " +quit";
    
    display_data();
    std::cout << "Downloading.. " << title << "(" << workshop_item_id << ")\n"; 

    FILE* pipe = popen(steamcmd_download_command.c_str(), "r");
    if (!pipe) {
        std::cerr << RED <<"Failed to run steamcmd_download_command\n";
        return;
    }
    std::array<char,126> buffer;
    std::string err_log = "ERROR : ";
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        err_log += buffer.data();
    }

    pclose(pipe);

    fs::path item_current_download_path = fs::absolute("steamapps/workshop/content/"+consumer_app_id+"/"+workshop_item_id);
    if(fs::exists(item_current_download_path)){
        std::cout << "Workshop Item : "+ title +"(" + workshop_item_id + ") ";
        std::cout << "successfully downloaded." << std::endl; 
        
        //move to user defined path
        if(!user_define_download_path.empty()){
            if(fs::exists(user_define_download_path)){
                fs::rename(item_current_download_path,user_define_download_path);
                // fs::remove_all(item_current_download_path);
                std::cout << "Download location : " << user_define_download_path << std::endl;
            }else{
                std::cout << RED << "path : " + user_define_download_path + " does not exists" << RESET << std::endl;
            }
        }
        std::cout << "Download location : " << item_current_download_path << std::endl;

    }else{
        std::cout << RED << err_log << std::endl;
    }
}

fetch_download::~fetch_download(){}
