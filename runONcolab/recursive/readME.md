#INSTRUCTION
the folder runONcolab is contains all the source code and result file after simulate on google colab. If you want to check out this project, just download the runONcolab folder and run it.
#REQUIRE TOOL:
the Makefile is built to run on some specific tools, you need to download it to watch the result and operation with the available makefile. If you are professional, you know what to do, if you don't, copy the below script.
# =========================
# Install Verilator 5.026
# =========================

# 1. Install dependencies
apt-get update
apt-get install -y \
    git make autoconf g++ flex bison help2man

# 2. Download Verilator source
cd /content
git clone https://github.com/verilator/verilator.git
cd verilator
git checkout v5.050

# 3. Configure
autoconf
./configure

# 4. Build (use -j2 for Colab stability)
make -j2

# 5. Install
make install

# 6. Refresh shell cache
hash -r

# 7. Verify installation
which verilator
verilator --version


# Install Icarus
sudo apt update
sudo apt install iverilog gtkwave

# Install Risc_v toolchain
wget -q https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/releases/download/v14.2.0-3/xpack-riscv-none-elf-gcc-14.2.0-3-linux-x64.tar.gz

tar -xzf xpack-riscv-none-elf-gcc-14.2.0-3-linux-x64.tar.gz


export PATH=/content/xpack-riscv-none-elf-gcc-14.2.0-3/bin:$PATH

riscv-none-elf-gcc --version

# Để PATH có hiệu lực lâu dài trong phiên làm việc hiện tại, bạn cũng có thể dùng:
echo 'export PATH=/content/xpack-riscv-none-elf-gcc-14.2.0-3/bin:$PATH' >> ~/.bashrc
source ~/.bashrc

# HOW TO USE:
after installing all the tools, use this flow: make hex -> make run, maybe you should make clean first to clear the available result and watch the operation of the flow from the begining 
