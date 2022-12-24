/*
 * class_name: https://github.com/MurakamiShun/class_name
 * Copyright (c) 2022 MurakamiShun
 *
 * Released under the MIT License.
 */
#pragma once
#include <string_view>

template<typename D>
class class_name {
private:
    static constexpr auto impl(){
        #ifdef _MSC_VER
        constexpr auto str_ptr = __FUNCTION__;
        constexpr auto base_class_len = std::char_traits<char>::length("class_name<");
        constexpr auto head_len = base_class_len + std::char_traits<char>::length(str_ptr[base_class_len] == 's' ? "struct " : "class ");
        constexpr auto tail_len = std::char_traits<char>::length(">::impl");
        #elif defined(__clang__)
        constexpr auto str_ptr = __PRETTY_FUNCTION__;
        constexpr auto head_len = std::char_traits<char>::find(str_ptr, std::char_traits<char>::length(str_ptr), '[') - str_ptr + std::char_traits<char>::length("[D = ");
        constexpr auto tail_len = std::char_traits<char>::length("]");
        #elif defined(__GNUC__)
        constexpr auto str_ptr = __PRETTY_FUNCTION__;
        constexpr auto head_len = std::char_traits<char>::find(str_ptr, std::char_traits<char>::length(str_ptr), '[') - str_ptr + std::char_traits<char>::length("[with D = ");
        constexpr auto tail_len = std::char_traits<char>::length("]");
        #endif
        constexpr auto len = std::char_traits<char>::length(str_ptr);
        return std::string_view(&str_ptr[head_len], len - head_len - tail_len);
    }
public:
    static constexpr auto value = impl();
};