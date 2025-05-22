// LANGUAGE: required C++11 for <type_traits>, auto, range-based for loop, variable template parameters, etc.
#ifdef _WIN32 || WIN32
#include <io.h>
#elif __linux__
#include <unistd.h>
#endif
#include <cstdio>
#include <cctype>
#include <type_traits>
#include <string>

namespace IO
{
#define UseCStdio 1
#if !UseCStdio
    namespace
    {
        static constexpr auto IN_BUFFER_SIZE = 1 << 20, OUT_BUFFER_SIZE = 1 << 20;
        std::FILE *in_stream = stdin, *out_stream = stdout;
        char in_buffer[IN_BUFFER_SIZE], *in_ptr = in_buffer, *in_end = in_buffer;
        char out_buffer[OUT_BUFFER_SIZE], *out_ptr = out_buffer;

        inline void flush_input() { in_end = in_buffer + std::fread(in_buffer, 1, IN_BUFFER_SIZE, in_stream) - 1, in_ptr = in_buffer; }
        inline void flush_output() { std::fwrite(out_buffer, 1, out_ptr - out_buffer, out_stream), out_ptr = out_buffer; }

        inline void bind_input(std::FILE *stream = stdin) { in_stream = stream; }
        inline void bind_output(std::FILE *stream = stdout) { out_stream = stream; }

        class __FLUSHER__
        {
        public:
            ~__FLUSHER__() { flush_output(); }
        } __OUTPUT_FLUSHER__;
    }

    inline int getchar()
    {
        if (in_ptr == in_end)
            flush_input();
        return *in_ptr++;
    }
    inline int putchar(const char &c) { return *out_ptr++ = c; }

#else

    inline int getchar() { return std::getchar(); }
    inline int putchar(char c) { return std::putchar(c); }

#endif

    template <typename _Tint, typename = typename std::enable_if<std::is_integral<_Tint>::value>::type>
    inline void read(_Tint &x)
    {
        char c = 0, l = 0;
        while (!std::isdigit(c = (char)getchar()))
            l = c;
        x = c ^ '0';
        while (std::isdigit(c = (char)getchar()))
            x = (x << 1) + (x << 3) + (c ^ '0');
        if (l == '-')
            x = -x;
    }

    inline void read(char &x)
    {
        while (!std::isgraph(x = (char)getchar()))
            ;
    }

    inline void read(std::string &x)
    {
        char c;
        while (!std::isgraph(c = (char)getchar()))
            ;
        x = c;
        while (std::isgraph(c = (char)getchar()))
            x.push_back(c);
    }

    inline void read(char *s)
    {
        while (*s = (char)getchar(), !std::isgraph(*s))
            ++s;
        *++s = '\0';
    }

    template <typename _Tp, typename... _Args>
    inline void read(_Tp &x, _Args &...args) { read(x), read(args...); }

    template <typename _Tint, typename = typename std::enable_if<std::is_integral<_Tint>::value>::type>
    inline void write(_Tint x)
    {
        if (x == 0)
            return putchar('0'), void();
        if (x < 0)
            putchar('-'), x = -x;
        char buf[128];
        int ptr = 0;
        while (x)
            buf[ptr++] = char(x % 10 + '0'), x /= 10;
        while (ptr)
            putchar(buf[--ptr]);
    }

    inline void write(char x) { putchar(x); }

    inline void write(const std::string &x)
    {
        for (const char &c : x)
            putchar(c);
    }

    inline void write(const char *x)
    {
        while (*x)
            putchar(*x++);
    }

    template <typename _Tp, typename... _Args>
    inline void write(_Tp x, _Args... args) { write(x), write(args...); }
}
