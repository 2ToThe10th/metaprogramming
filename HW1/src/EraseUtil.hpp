#pragma once
#include "TypeList.hpp"

template<typename ToErase, typename Current, typename ... Data>
struct EraseUtil;

// Если данные закончились, то возвращаем то что уже есть
template<typename ToErase, typename Current>
struct EraseUtil<ToErase, Current> {
  using Result = Current;
};

// Если первый элемент в данных совпадает с ToErase, то возвращаем TypeList без него
template<typename ToErase, typename ... T, typename ... Other>
struct EraseUtil<ToErase, TypeList<T ...>, ToErase, Other ...> {
  using Result = TypeList<T ..., Other ...>;
};

// Иначе переходим к следующему элементу
template<typename ToErase, typename ... T, typename First, typename ... Other>
struct EraseUtil<ToErase, TypeList<T ...>, First, Other ...> {
  using Result = typename EraseUtil<ToErase, TypeList<T ..., First>, Other ...>::Result;
};
