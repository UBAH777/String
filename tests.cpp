#include "string.h"
#include <gtest/gtest.h>
#include <sstream>

using namespace BMSTU;


TEST(StringTests, Constructor_default) {
    BMSTU::string str;
    ASSERT_EQ(str, "");
}

TEST(StringTests, Constructor_with_length) {
    BMSTU::string str1(int(0));
    ASSERT_EQ(str1.size(), 0);

    BMSTU::string str2(7);
    ASSERT_EQ(str2.size(), 7);
}

TEST(StringTests, Constructor_c_str) {
    const char *s = "vlados";
    BMSTU::string str1(s);
    ASSERT_EQ(str1, "vlados");
}

TEST(StringTests, Constructor_other_str) {
    BMSTU::string str("zachot");
    BMSTU::string str1(str);
    ASSERT_EQ(str1, "zachot");
}

TEST(StringTests, Plus_one_term) {
    BMSTU::string str1("xochu");
    BMSTU::string str2("zachot");
    str1 += str2;
    ASSERT_EQ(str1, "xochuzachot");
}

TEST(StringTests, Concatenate_two_strings) {
    BMSTU::string str1("xochu");
    BMSTU::string str2("zachot");
    BMSTU::string str3 = str1 + str2;
    ASSERT_EQ(str3, "xochuzachot");
}

TEST(StringTests, OutputStreamTest) {
    std::string str0("vlados");
    BMSTU::string str1(str0.c_str());
    std::ostringstream oss;
    oss << str1;
    ASSERT_EQ(oss.str(), str0.c_str());
}

TEST(StringTests, ComparisonOperator) {
    const char *c_str1 = "aaa";
    const char *c_str2 = "aaa";
    BMSTU::string str1("aaa");
    BMSTU::string str2("aaa");

    ASSERT_EQ(str1, str2);
    ASSERT_EQ(c_str1, str2);
    ASSERT_EQ(str1, c_str2);

    ASSERT_FALSE(str1 + "x" == str2);
    ASSERT_FALSE(str1 + "x" == str2 + "z");
}

TEST(StringTests, FuncOfSize) {
    BMSTU::string str("aaa");
    ASSERT_EQ(str.size(), 3);
    ASSERT_EQ((str + "z").size(), 4);
    str = "";
    ASSERT_EQ(str.size(), 0);
}

TEST(StringTests, FuncOfSwap) {
    BMSTU::string s1("zzz");
    BMSTU::string s2("yyy");

    swap(s1, s2);
    ASSERT_EQ(s1, "yyy");
    ASSERT_EQ(s2, "zzz");
}
TEST(StringTests, AssignStringOperator) {
    BMSTU::string s1("zzz");
    BMSTU::string s2("");
    s2 = s1;
    ASSERT_EQ(s2, "zzz");
}

TEST(StringTests, Data_and_Ptrs) {
    BMSTU::string s1("abc");
    const char *s_ptr = s1.c_str();

    ASSERT_EQ(*s_ptr, 'a');
    ASSERT_EQ(*(s_ptr + 2), 'c');

    ASSERT_EQ(*s1.data(), 'a');
}

TEST(StringTests, Assign) {
    BMSTU::string s1 = "abc";
    BMSTU::string s2 = s1 + "abc";

    ASSERT_STREQ(s2.c_str(), "abcabc");
}

TEST(StringTests, Assign2) {
    BMSTU::string s1;
    BMSTU::string s2 = s1 + "abc";

    ASSERT_STREQ(s2.c_str(), "abc");
}

TEST(StringTests, Assign3) {
    BMSTU::string s1("abc");
    BMSTU::string s2(s1);

    ASSERT_STREQ(s2.c_str(), "abc");
}

TEST(StringTests, Size) {
    BMSTU::string s1("123456789");

    ASSERT_EQ(s1.size(), 9);
}

TEST(StringTests, AssignTest) {
    BMSTU::string s1("123456789");
    ASSERT_EQ(s1.c_str(), s1.c_str());
}