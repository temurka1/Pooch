#include "pch.h"
#include "StringUtils.h"

std::vector<std::string_view> SAMOSBOR::core::utils::str_split(const std::string_view str, const char delim, std::uint32_t maxTokens)
{
    std::vector<std::string_view> ret;
    ret.reserve(maxTokens);

    std::string_view::size_type start = 0;
    size_t pos = str.find_first_of(delim, start);

    while (pos != std::string_view::npos)
    {
        if (pos != start)
        {
            std::string_view token = str.substr(start, pos - start);
            ret.push_back(token);
        }

        start = pos + 1;
        pos = str.find_first_of(delim, start);
    }

    if (start < str.length())
    {
        std::string_view token = str.substr(start, str.length() - start);
        ret.push_back(token);
    }

    ret.shrink_to_fit();

    return ret;
}

void SAMOSBOR::core::utils::str_split_inplace(const std::string_view str, const char delim, std::vector<std::string_view>* tokens)
{
    std::string_view::size_type start = 0;
    size_t pos = str.find_first_of(delim, start);
    size_t i = 0;

    while (pos != std::string_view::npos)
    {
        if (pos != start)
        {
            tokens->push_back(str.substr(start, pos - start));
        }

        start = pos + 1;
        pos = str.find_first_of(delim, start);
    }

    if (start < str.length())
    {
        tokens->push_back(str.substr(start, str.length() - start));
    }
}