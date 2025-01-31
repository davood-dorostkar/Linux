#!/bin/bash

sudo ip link set eno1 up
sudo ip addr add 192.168.1.110/24 dev eno1
sudo ip ro add default via 192.168.1.1
sudo echo 'nameserver 8.8.8.8' >> /etc/resolv.conf
sudo echo 'nameserver 8.8.4.4' >> /etc/resolv.conf
ping google.com
