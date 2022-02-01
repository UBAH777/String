#pragma once
#include <cstddef>
#include <cstring>
#include <iostream>


namespace BMSTU {
    class string {
    public:

        explicit string();

        string(size_t size);

        string(const char *c_str);

        string(const BMSTU::string &other_string);

        string &operator+=(const BMSTU::string &other_string);

        friend string operator+(BMSTU::string other_string, const BMSTU::string &another_string);

        string &operator=(const BMSTU::string &other_string);

        string &operator=(const char *other_c_str);

        friend bool operator==(const BMSTU::string &lhs, const BMSTU::string &rhs);

        friend bool operator==(const BMSTU::string &lhs, const char *rhs);

        friend bool operator==(const char *lhs, const BMSTU::string &rhs);

        friend std::ostream &operator<<(std::ostream &out, const string &item);

        ~string();

        const char *c_str() const;
        char *data();
        const size_t size() const;
        friend void swap(BMSTU::string &first, BMSTU::string &second);


    private:
        char *_str_ptr;
        size_t _size_str;
        void _fill(char *str, size_t size, char value);
        static size_t _strlen(const char *str);
    };
}
