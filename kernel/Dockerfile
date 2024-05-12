FROM ubuntu:focal
RUN apt-get update && apt-get install -y build-essential libncurses-dev bison flex libssl-dev libelf-dev bc cpio
RUN mkdir /home/kernel
COPY linux-5.4.275 /home/kernel
WORKDIR /home/kernel/
RUN make clean
# RUN make menuconfig
RUN make -j$(nproc)