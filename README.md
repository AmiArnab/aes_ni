# AES NI
Fast AES on Software using AES NI ISA.

Compile using the following command.

```bash
g++ main.cpp -msse2 -msse -march=native -maes -o aes_ni
```
