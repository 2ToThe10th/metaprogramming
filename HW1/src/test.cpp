#include <iostream>
#include <gtest/gtest.h>
#include <queue>
#include "TypeList.hpp"
#include "Length.hpp"
#include "Erase.hpp"
#include "IArmyFactory.hpp"

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

TEST(TypeListLength, All) {
  EXPECT_EQ((Length<
      TypeList<int, std::string, char>
  >::value), 3);
}

TEST(TypeListLength, Char) {
  EXPECT_EQ((Length<
      TypeList<char>
  >::value), 1);
}

TEST(TypeListLength, Empty) {
  EXPECT_EQ((Length<
      TypeList<>
  >::value), 0);
}

TEST(TypeListLength, NullType) {
  EXPECT_EQ((Length<
      TypeList<>
  >::value), 0);
}

TEST(TypeListErase, Int) {
  EXPECT_EQ((PrintUtil<
      Erase<TypeList<int, std::string, char>, int>::Result
  >::PrintTypeList()), "string char ");
}

TEST(TypeListErase, String) {
  std::vector<Erase<TypeList<int, std::string, char>, std::string>::Result> q;
  EXPECT_EQ((PrintUtil<
      Erase<TypeList<int, std::string, char>, std::string>::Result
  >::PrintTypeList()), "int char ");
}

TEST(TypeListErase, Char) {
  EXPECT_EQ((PrintUtil<
      Erase<TypeList<int, std::string, char>, char>::Result
  >::PrintTypeList()), "int string ");
}

TEST(TypeListErase, IntString) {
  EXPECT_EQ((PrintUtil<
      Erase<Erase<TypeList<int, std::string, char>, int>::Result, std::string>::Result
  >::PrintTypeList()), "char ");
}

TEST(TypeListErase, IntChar) {
  EXPECT_EQ((PrintUtil<
      Erase<Erase<TypeList<int, std::string, char>, int>::Result, char>::Result
  >::PrintTypeList()), "string ");
}

TEST(TypeListErase, StringChar) {
  EXPECT_EQ((PrintUtil<
      Erase<Erase<TypeList<int, std::string, char>, char>::Result, std::string>::Result
  >::PrintTypeList()), "int ");
}

TEST(TypeListErase, All) {
  EXPECT_EQ((PrintUtil<
      Erase<Erase<Erase<TypeList<int, std::string, char>, char>::Result, std::string>::Result, int>::Result
  >::PrintTypeList()), "");
}

TEST(TypeListErase, ALotOfIntAndCharEraseChar) {
  EXPECT_EQ((PrintUtil<
      Erase<TypeList<int, char, int, char, int, char, int, char>, char>::Result
  >::PrintTypeList()), "int int char int char int char ");
}

TEST(TypeListErase, ALotOfIntAndCharEraseInt) {
  EXPECT_EQ((PrintUtil<
      Erase<TypeList<int, char, int, char, int, char, int, char>, int>::Result
  >::PrintTypeList()), "char int char int char int char ");
}

TEST(TypeListErase, ALotOfIntAndCharErase3Int) {
  EXPECT_EQ((PrintUtil<
      Erase<Erase<Erase<TypeList<int, char, int, char, int, char, int, char>, int>::Result, int>::Result, int>::Result
  >::PrintTypeList()), "char char char int char ");
}

TEST(TypeListErase, Empty) {
  EXPECT_EQ((PrintUtil<
      Erase<Erase<Erase<TypeList<>, int>::Result, int>::Result, int>::Result
  >::PrintTypeList()), "");
}

TEST(TypeListErase, ListDoesntContainType) {
  EXPECT_EQ((PrintUtil<
      Erase<Erase<TypeList<int, std::string, char>, float>::Result, double>::Result
  >::PrintTypeList()), "int string char ");
}

TEST(Factory, CheckOutputTypeInfantry) {
  IArmyFactory factory;
  auto infantry = std::make_shared<Infantry>();
  EXPECT_EQ(typeid(factory.Create<Infantry>()), typeid(infantry));
}

TEST(Factory, CheckOutputTypeArcher) {
  IArmyFactory factory;
  auto archer = std::make_shared<Archer>();
  EXPECT_EQ(typeid(factory.Create<Archer>()), typeid(archer));
}

TEST(Factory, CheckOutputTypeCavalry) {
  IArmyFactory factory;
  auto cavalry = std::make_shared<Cavalry>();
  EXPECT_EQ(typeid(factory.Create<Cavalry>()), typeid(cavalry));
}