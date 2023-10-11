#include <iostream>
#include <vector>
#include <string>

bool isValidIP(const std::string &ip) {
    std::vector<std::string> segments;
    size_t start = 0;
    size_t end = ip.find('.');
    
    while (end != std::string::npos) {
        std::string segment = ip.substr(start, end - start);
        segments.push_back(segment);
        start = end + 1;
        end = ip.find('.', start);
    }
    // 处理最后一个段
    std::string segment = ip.substr(start);
    segments.push_back(segment);

    // IP地址必须有四个段
    if (segments.size() != 4) {
        return false;
    }

    // ... 后续的验证逻辑 ...
    for (const std::string &seg : segments) {
        if (seg.empty() || seg.size() > 3) {
            return false;
        }
        for (char c : seg) {
            if (!std::isdigit(c)) {
                return false;
            }
        }
        int num = std::stoi(seg);
        if (num < 0 || num > 255) {
            return false;
        }
        if (seg.size() > 1 && seg[0] == '0') {
            return false;
        }
    }
    
    return true;
}

int main() {
    std::string ip;
    std::cout << "Enter an IP address: ";
    std::getline(std::cin, ip);

    if (isValidIP(ip)) {
        std::cout << ip << " is a valid IP address." << std::endl;
    } else {
        std::cout << ip << " is not a valid IP address." << std::endl;
    }

    return 0;
}
