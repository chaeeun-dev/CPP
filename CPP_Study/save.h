#pragma once
#include <string_view>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

void save(std::string_view); // const ���� �ʿ䰡 ����, string_view�� ���� ���� �����ϱ�!!! ���͸� ��α� �� �����ϱ�


void save(std::string_view fileName)
{
    // file�� �б������ ���� 
    std::ifstream in{ fileName.data() }; // ���� �ڷ���, �ڿ��� ������ �ϱ� ���� �̸� // RALL
    if (!in) { // ��ǲ ������ �߸� �Ǿ�����
        std::cout << fileName << "���� ����" << std::endl;
        exit(0);
    }

    // ������ ������ ���ٿ� ���� ���� ����.
    std::ofstream out{ "45��_���� ������ ����� ����.txt", std::ios::app }; // app�� append
     
    //std::cout << sizeof out << std::endl;

    // ���� ������ ������ �о� �� ���Ͽ� �� ���δ�.
    // STL �ڷ� ������ �˰����� �̿��Ͽ� ����Ѵ�(���� �� �ƴϴ�).
    std::vector<char> v{ std::istreambuf_iterator<char>{ in}, {} };

    auto now = std::chrono::system_clock::now();
    auto utc = std::chrono::system_clock::to_time_t(now);
#pragma warning(disable: 4996)
    auto It = localtime(&utc);
#pragma warning(default: 4996)

    // �ѱ� �������� ����Ѵ�(��� ��Ʈ���� ������ ��ȯ)
    auto old = out.imbue(std::locale("ko_KR"));

    out << std::endl << std::endl;
    out << "==========================================================================" << std::endl;
    out << "fileName :" << std::put_time(It, ":, %x %A %X") << std::endl;
    out << "==========================================================================" << std::endl;
    out << std::endl << std::endl;

    out.imbue(old);

    std::copy(v.begin(), v.end(), std::ostreambuf_iterator<char>{ out });
}