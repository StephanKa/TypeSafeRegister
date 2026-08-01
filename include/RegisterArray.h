#pragma once

#include <cstddef>
#include <Register.h>

template<typename RegisterWidth, std::uintptr_t BaseAddress, RegisterWidth ResetValue, typename RegisterType, details::FixedString Name,
         std::size_t Count, std::uintptr_t Increment, typename... Fields>
class RegisterArray
{
  public:
    template<std::size_t Index>
        requires (Index < Count)
    [[nodiscard]] static Register<RegisterWidth, BaseAddress + Index * Increment, ResetValue, RegisterType, Name, Fields...> &at()
    {
        static Register<RegisterWidth, BaseAddress + Index * Increment, ResetValue, RegisterType, Name, Fields...> instance;
        return instance;
    }

    [[nodiscard]] static consteval std::size_t size()
    {
        return Count;
    }
};