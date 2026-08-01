#pragma once

#include <cstddef>
#include <Register.h>

/**
 * @brief Represents an SVD register array with compile-time checked indices.
 *
 * @tparam Count Number of registers in the array.
 * @tparam Increment Address distance between adjacent elements.
 * @tparam RegisterWidth Unsigned storage type of one array element.
 * @tparam BaseAddress Address of element zero.
 * @tparam ResetValue SVD reset value used by host simulation.
 * @tparam RegisterType SVD access permission type.
 * @tparam Name Generated register name.
 * @tparam Fields Generated field descriptor types.
 */
template<typename RegisterWidth, std::uintptr_t BaseAddress, RegisterWidth ResetValue, typename RegisterType, details::FixedString Name,
         std::size_t Count, std::uintptr_t Increment, typename... Fields>
class RegisterArray
{
  public:
    template<std::size_t Index>
        requires (Index < Count)
    /**
     * @brief Return the register at compile-time index @p Index.
     * @tparam Index Zero-based array index, constrained to `Index < Count`.
     * @return Reference to the selected register instance.
     */
    [[nodiscard]] static Register<RegisterWidth, BaseAddress + Index * Increment, ResetValue, RegisterType, Name, Fields...> &at()
    {
        static Register<RegisterWidth, BaseAddress + Index * Increment, ResetValue, RegisterType, Name, Fields...> instance;
        return instance;
    }

    /**
     * @brief Return the number of registers represented by this array.
     * @return Number of generated array elements.
     */
    [[nodiscard]] static consteval std::size_t size()
    {
        return Count;
    }
};