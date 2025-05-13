# Competitive-Progamming-Input-Output

适用于信息学竞赛的快速输入输出

见 [洛谷](https://www.luogu.com.cn/article/hzpq6znb)

希望有大佬能帮忙捉个虫或者拓展一下 Orz

请点击 [code](https://github.com/WangYiBen0/Competitive-Progamming-Input-Output) 旁边的 [issue](https://github.com/WangYiBen0/Competitive-Progamming-Input-Output/issues) 反馈，或者提个 [PR](https://github.com/WangYiBen0/Competitive-Progamming-Input-Output/pulls)

## 用法 / 接口

`IO::read(A)` 读入 `A`  
`IO::read(A, B, ...)` 依次读入 `A`、`B`、……  
`IO::write(A)` 输出 `A`
`IO::write(A, B, ...)` 依次、不间隔地输出 `A`、`B`、……，可使用 `IO::write(A, ' ', B, ' ', C, ...)` 以用空格隔开

可选择是否使用 `<cstdio>` 提供的 `(std::)getchar` 、 `(std::)putchar`，将 `UseCStdio` 宏改成 `0` / `false` 使用 `fread` / `fwrite` 手动管理缓冲区
