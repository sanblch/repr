#pragma once
#include <type_traits>

template<typename T, typename _ = void>
struct is_stackish : std::false_type {};

template<typename... Ts>
struct is_stackish_helper {};

template<typename T>
struct is_stackish<
        T,
        std::conditional_t<
            false,
            is_stackish_helper<
                typename T::value_type,
                typename T::size_type,
                decltype(std::declval<T>().size()),
                decltype(std::declval<T>().pop()),
                decltype(std::declval<T>().top())
                >,
            void
            >
        > : public std::true_type {};