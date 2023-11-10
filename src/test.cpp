#include <cpr/cpr.h>
#include <iostream>

int main(int argc, char** argv) {
    cpr::Response r = cpr::Get(cpr::Url{"https://codeforces.com/api/user.status?handle=tourist&from=1&count=10"});
    std::cout << r.status_code << '\n';                  // 200
    std::cout << r.header["content-type"] << '\n';       // application/json; charset=utf-8
    std::cout << r.text << '\n';                         // JSON text string
    return 0;
}
