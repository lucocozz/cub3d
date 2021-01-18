#!/bin/zsh

sudo apt-get install gcc make xorg libxext-dev libbsd-dev
cd ~
git clone https://github.com/42Paris/minilibx-linux
cd minilibx-linux
./configure
sudo mv libmlx.a /usr/local/lib
sudo mv mlx.h /usr/local/include
cd /usr/local/man/
sudo mkdir man3
cd ~/minilibx-linux/man/man3
sudo mlx*.1 /usr/local/man/man3