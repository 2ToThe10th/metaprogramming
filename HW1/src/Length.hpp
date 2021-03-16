#pragma once

template<typename TypeList>
struct Length;

template<typename First, typename ... T>
struct Length<TypeList<First, T ...>> {
  static constexpr size_t value = Length<TypeList<T ...>>::value + 1;
};

template<>
struct Length<TypeList<>> {
  static constexpr size_t value = 0;
};