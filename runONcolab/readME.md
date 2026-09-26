# Instructions

The `runONcolab` directory contains all source code and simulation results generated on Google Colab. To explore this project, download or clone the `runONcolab` folder and follow the setup instructions below.

---

## Prerequisites & Installation

The provided `Makefile` depends on specific HDL tools and the RISC-V toolchain. If you are running this environment on Google Colab or an Ubuntu/Debian system, execute the script below to install all dependencies.

```bash
# ==========================================
# 1. Install Verilator (v5.026)
# ==========================================

# Install build dependencies
sudo apt-get update
sudo apt-get install -y git make autoconf g++ flex bison help2man

# Clone and build Verilator
cd /content
git clone [https://github.com/verilator/verilator.git](https://github.com/verilator/verilator.git)
cd verilator
git checkout v5.026

autoconf
./configure

# Build (using -j2 for Colab stability) and install
make -j2
sudo make install

# Refresh shell cache and verify
hash -r
which verilator
verilator --version


# ==========================================
# 2. Install Icarus Verilog & GTKWave
# ==========================================

sudo apt update
sudo apt install -y iverilog gtkwave


# ==========================================
# 3. Install RISC-V GNU Toolchain
# ==========================================

cd /content
wget -q [https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/releases/download/v14.2.0-3/xpack-riscv-none-elf-gcc-14.2.0-3-linux-x64.tar.gz](https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/releases/download/v14.2.0-3/xpack-riscv-none-elf-gcc-14.2.0-3-linux-x64.tar.gz)

tar -xzf xpack-riscv-none-elf-gcc-14.2.0-3-linux-x64.tar.gz

# Add toolchain to PATH
export PATH=/content/xpack-riscv-none-elf-gcc-14.2.0-3/bin:$PATH
echo 'export PATH=/content/xpack-riscv-none-elf-gcc-14.2.0-3/bin:$PATH' >> ~/.bashrc
source ~/.bashrc

# Verify installation
riscv-none-elf-gcc --version

# How to Run
Once all prerequisites are installed, run the commands in the following order:

Bash
# (Optional) Clean previous simulation outputs
make clean

# Generate hex files from source code
make hex

# Execute simulation
make run
