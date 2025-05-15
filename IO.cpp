// LANGUAGE: required C++11 for <type_traits>, auto, range-based for loop, variable template parameters, etc.
#include <cstdio>
#include <cctype>
#include <type_traits>
#include <string>

namespace IO
{
#define UseCStdio 1
#if !UseCStdio
    class IO
    {
        static constexpr auto IN_BUFFER_SIZE = 1 << 20, OUT_BUFFER_SIZE = 1 << 20;
        std::FILE *in_stream, *out_stream;
        char in_buffer[IN_BUFFER_SIZE], *in_ptr = in_buffer, *in_end = in_buffer;
        char out_buffer[OUT_BUFFER_SIZE], *out_ptr = out_buffer;

        inline void flush_input() { in_end = in_buffer + std::fread(in_buffer, 1, IN_BUFFER_SIZE, in_stream), in_ptr = in_buffer; }
        inline void flush_output() { std::fwrite(out_buffer, 1, out_ptr - out_buffer, out_stream), out_ptr = out_buffer; }

    public:
        IO(std::FILE *in_stream = stdin, std::FILE *out_stream = stdout) : in_stream(in_stream), out_stream(out_stream) {}

        inline void bind(std::FILE *in_stream, std::FILE *out_stream) { this->in_stream = in_stream, this->out_stream = out_stream; }
        inline void bind(std::FILE *stream) { bind(stream, stream); }
        inline void bind() { bind(stdin, stdout); }
        inline void bind_input(std::FILE *stream = stdin) { this->in_stream = stream; }
        inline void bind_output(std::FILE *stream = stdout) { this->out_stream = stream; }

        inline char getchar()
        {
            if (in_ptr == in_end)
                flush_input();
            return *in_ptr++;
        }
        inline char putchar(const char &c) { return *out_ptr++ = c; }

        ~IO() { flush_output(); }
    } iomanager;
    inline char getchar() { return iomanager.getchar(); }
    inline void putchar(char c) { iomanager.putchar(c); }
#endif

    template <typename _Tint, typename = typename std::enable_if<std::is_integral<_Tint>::value>>
    inline _Tint read(_Tint &x)
    {
        char c, l;
        while (!std::isdigit(c = (char)getchar()))
            l = c;
        x = c ^ '0';
        while (std::isdigit(c = (char)getchar()))
            x = (x << 1) + (x << 3) + (c ^ '0');
        return l == '-' && (x = -x), x;
    }

    inline char read(char &x)
    {
        while (!std::isgraph(x = (char)getchar()))
            ;
        return x;
    }

    inline std::string read(std::string &x)
    {
        char c;
        while (!std::isgraph(c = (char)getchar()))
            ;
        x = c;
        while (std::isgraph(c = (char)getchar()))
            x.push_back(c);
        return x;
    }

    /**
     * @warning no check for Array-Index-Out-of-Bounds
     */
    inline void read(char *s)
    {
        while (*s = (char)getchar(), !std::isgraph(*s))
            ;
        *s = '\0';
    }

    template <typename _Tp, typename... _Args>
    inline _Tp read(_Tp &x, _Args &...args) { return read(x), read(args...); }

    template <typename _Tint, typename = typename std::enable_if<std::is_integral<_Tint>::value>>
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

    inline void write(const char *x) { while (*x) putchar(*x++); }

    inline void writeln() { putchar('\n'); }
    template <typename _Tp, typename... _Args>
    inline void write(_Tp x, _Args... args) { write(x), write(args...); }
    template <typename _Tp, typename... _Args>
    inline void writeln(_Tp x, _Args... args) { write(x), writeln(args...); }
}
