#include <cstdint>
#include <cstdio>
#include <random>
#include <type_traits>
using namespace std;

//@@@@@@@@@@@@@
//@ snippet xorshift
//@ options head
class XorShift { // {{{
private:
    static_assert(is_unsigned<uint64_t>::value);
    uint64_t x, y, z, w;
public:
    constexpr inline explicit XorShift() : x(123456789), y(362436069), z(521288629), w(88675123) {}
    constexpr inline explicit XorShift(uint64_t seed) : XorShift() { setSeed(seed); }
    constexpr inline void setSeed(uint64_t s) {
        z ^= s;
        z ^= z >> 21; z ^= z << 35; z ^= z >> 4;
        z *= 2685821657736338717LL;
    }
    inline uint64_t operator() () {
        uint64_t t=(x^(x<<11));
        x=y; y=z; z=w;
        return ( w=(w^(w>>19))^(t^(t>>8)) );
    }
    inline uint64_t operator() (uint64_t maxv) { // [0, maxv)
        return (*this)() % maxv;
    }
    inline int64_t operator() (int64_t minv, int64_t maxv) { // [minv, maxv)
        return minv + (int64_t)((*this)() % (maxv - minv));
    }
}; // }}}
//@@@@@@@

signed main()
{
    XorShift rnd;

    for (int i = 0; i < 50; ++i) {
        printf("%lu\n", rnd(5, 10));
    }
}
