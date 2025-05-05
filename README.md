### Build Risc-V GCC toolchain

```bash
./configure --prefix=/opt/riscv --with-arch=rv32gc --with-abi=ilp32d --enable-multilib --with-multilib-generator="rv32i-ilp32--;rv32imafd-ilp32--"
```

```bash
make
```

```
(add /opt/riscv/bin to PATH)
```
