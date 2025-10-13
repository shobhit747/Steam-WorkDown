#include <iostream>
#include "fetch_download.hpp"
int main(int argc, char const *argv[])
{
    fetch_download instance("2684285534");
    instance.fetch();
    instance.set_download_path("/media/shobhit/Games/Steam_Workshop_Downloader/temp_path");
    instance.download();
    return 0;
}

