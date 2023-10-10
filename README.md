# AES NI
Fast AES on Software using AES NI ISA. Mostly borrowed from [here](https://gist.github.com/acapola/d5b940da024080dfaf5f).

Compile using the following command.

```bash
g++ main.cpp -O3 -msse2 -msse -march=native -maes -o aes_ni
```

__Remember! `-O3` is important!__


