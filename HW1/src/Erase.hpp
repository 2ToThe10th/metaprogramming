#pragma once
#include "TypeList.hpp"
#include "EraseUtil.hpp"

template<typename List, typename ToErase>
struct Erase;

template<typename ... T, typename ToErase>
struct Erase<TypeList<T ...>, ToErase> {
  using Result = typename EraseUtil<ToErase, TypeList<>, T ...>::Result;
};