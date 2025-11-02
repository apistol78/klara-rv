### Build Risc-V GCC toolchain

```bash

git clone https://github.com/riscv/riscv-gnu-toolchain

#./configure --prefix=/opt/riscv --with-arch=rv32gc --with-abi=ilp32d --enable-multilib --with-multilib-generator="rv32i-ilp32--;#rv32imafd-ilp32--"

./configure --prefix=/opt/riscv --with-arch=rv32im_zfinx_zicsr --with-abi=ilp32 --enable-multilib --with-multilib-generator="rv32im_zfinx_zicsr-ilp32--"

sudo make -j4

```

```
(add /opt/riscv/bin to PATH)
```
