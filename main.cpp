//#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "Game.h"
//#include "httplib.h"

int main(int argc, char *argv[])
{
    /*httplib::Client cli("https://127.0.0.1:7059");

    std::string data = "{\n"
                       "    \"Name\": \"from cpp\",\n"
                       "    \"Score\": 99,\n"
                       "    \"TimeSurvived\": 20\n"
                       "}";
    auto res = cli.Post(std::string("/api/highscores/add-new"), data, std::string("application/json"));

    std::cout << res << std::endl;*/
    //std::cout << res->status << std::endl;
    //std::cout << res->body << std::endl;

    Game g;
    g.run();

    return 0;
}
