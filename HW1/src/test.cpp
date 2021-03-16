#include <iostream>
#include <gtest/gtest.h>
#include <queue>
#include "TypeList.hpp"
#include "Length.hpp"
#include "Erase.hpp"

template<typename X>
std::string PrintType() {
  return "unexpected_type";
}

template<>
std::string PrintType<int>() {
  return "int";
}

template<>
std::string PrintType<std::string>() {
  return "string";
}

template<>
std::string PrintType<char>() {
  return "char";
}

template<>
std::string PrintType<TypeList<>>() {
  return "TypeList<>";
}

template<typename TypeList>
struct PrintUtil;

template<typename First, typename ... T>
struct PrintUtil<TypeList<First, T ...>> {
  static std::string PrintTypeList() {
    return PrintType<First>() + " " + PrintUtil<TypeList<T ...>>::PrintTypeList();
  }

};

template<>
struct PrintUtil<TypeList<>> {
  static std::string PrintTypeList() {
    return "";
  }
};

TEST(PrintTypeList, All) {
  EXPECT_EQ((PrintUtil<
      TypeList<int, std::string, char>
  >::PrintTypeList()), "int string char ");
}

TEST(PrintTypeList, Int) {
  EXPECT_EQ((PrintUtil<
      TypeList<int>
  >::PrintTypeList()), "int ");
}

TEST(PrintTypeList, Empty) {
  EXPECT_EQ((PrintUtil<
      TypeList<>
  >::PrintTypeList()), "");
}

TEST(Length, All) {
  EXPECT_EQ((Length<
      TypeList<int, std::string, char>
  >::value), 3);
}

TEST(Length, Char) {
  EXPECT_EQ((Length<
      TypeList<char>
  >::value), 1);
}

TEST(Length, Empty) {
  EXPECT_EQ((Length<
      TypeList<>
  >::value), 0);
}

TEST(Length, NullType) {
  EXPECT_EQ((Length<
      TypeList<>
  >::value), 0);
}

TEST(Erase, Int) {
  EXPECT_EQ((PrintUtil<
      Erase<TypeList<int, std::string, char>, int>::Result
  >::PrintTypeList()), "string char ");
}

TEST(Erase, String) {
  std::vector<Erase<TypeList<int, std::string, char>, std::string>::Result> q;
  EXPECT_EQ((PrintUtil<
      Erase<TypeList<int, std::string, char>, std::string>::Result
  >::PrintTypeList()), "int char ");
}

TEST(Erase, Char) {
  EXPECT_EQ((PrintUtil<
      Erase<TypeList<int, std::string, char>, char>::Result
  >::PrintTypeList()), "int string ");
}

TEST(Erase, IntString) {
  EXPECT_EQ((PrintUtil<
      Erase<Erase<TypeList<int, std::string, char>, int>::Result, std::string>::Result
  >::PrintTypeList()), "char ");
}

TEST(Erase, IntChar) {
  EXPECT_EQ((PrintUtil<
      Erase<Erase<TypeList<int, std::string, char>, int>::Result, char>::Result
  >::PrintTypeList()), "string ");
}

TEST(Erase, StringChar) {
  EXPECT_EQ((PrintUtil<
      Erase<Erase<TypeList<int, std::string, char>, char>::Result, std::string>::Result
  >::PrintTypeList()), "int ");
}

TEST(Erase, All) {
  EXPECT_EQ((PrintUtil<
      Erase<Erase<Erase<TypeList<int, std::string, char>, char>::Result, std::string>::Result, int>::Result
  >::PrintTypeList()), "");
}

TEST(Erase, ALotOfIntAndCharEraseChar) {
  EXPECT_EQ((PrintUtil<
      Erase<TypeList<int, char, int, char, int, char, int, char>, char>::Result
  >::PrintTypeList()), "int int char int char int char ");
}

TEST(Erase, ALotOfIntAndCharEraseInt) {
  EXPECT_EQ((PrintUtil<
      Erase<TypeList<int, char, int, char, int, char, int, char>, int>::Result
  >::PrintTypeList()), "char int char int char int char ");
}

TEST(Erase, ALotOfIntAndCharErase3Int) {
  EXPECT_EQ((PrintUtil<
      Erase<Erase<Erase<TypeList<int, char, int, char, int, char, int, char>, int>::Result, int>::Result, int>::Result
  >::PrintTypeList()), "char char char int char ");
}