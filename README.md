# 适用于信息学竞赛的快速输入输出

见 [洛谷](https://www.luogu.com.cn/article/hzpq6znb)

希望有大佬能帮忙捉个虫或者拓展一下 Orz

请去 Issues 反馈，或者提个 Pull requests

拓展性：在 `IO` 命名空间中写一个 `void read(_Tp)` / `void write(_Tp)` 重载即可，使用 `getchar(void)` / `putchar(char|int)` 函数（若设置不使用自定义单字符输入输出则会自动退回至 `<cstdio>`）

## 用法 / 接口

clone 到本地，将 `IO.cpp` 的内容复制到你的程序中，即可使用。  
记得写 `namespace`

- `IO::read(A)` 读入 `A`
- `IO::read(A, B, ...)` 依次读入 `A`、`B`、……
- `IO::write(A)` 输出 `A`
- `IO::write(A, B, ...)` 依次、不间隔地输出 `A`、`B`、……，可使用 `IO::write(A, ' ', B, ' ', C, ...)` 以用空格隔开

可选择是否使用 `<cstdio>` 提供的 `std::getchar` 、 `std::putchar`，将 `UseCStdio` 宏改成 `0` / `false` 使用 `fread` / `fwrite` 手动管理缓冲区

目前已实现的重载：

- `int` 系列（整型）：`short, int, long, long long, __int128(GCC)`
- `char` 字符
- `std::string` 字符串（不用为了 `std::string` 而用 `std::cin` 了）
- `char *` C 风格字符串

> [!Warning]
> `char *` 的输入输出可能不安全，请自行注意（开大点）
