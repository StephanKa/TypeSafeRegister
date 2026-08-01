#include <TypeSafeRegister.hpp>

struct AmalgamationFieldOwner
{
};

using AmalgamationField = BitField<AmalgamationFieldOwner, 0, 1, "READY">;
using AmalgamationRegister = Register<std::uint32_t, 0, 0, READWRITE, "STATUS", AmalgamationField>;

int main()
{
    AmalgamationRegister reg;
    reg |= AmalgamationField{};
    return reg() == 1U ? 0 : 1;
}