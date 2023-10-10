# AES NI
Fast AES on Software using AES NI ISA.

Compile using the following command.

```bash
g++ main.cpp -O3 -msse2 -msse -march=native -maes -o aes_ni
```

__Remember! `-O3` is important!__
