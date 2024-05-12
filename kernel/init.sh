#!/bin/bash

set -e

apt-get update -q
apt-get install -yq git docker.io docker-buildx docker-compose
CONDITIONS_MET=true

if ! groups | grep -q '\bdocker\b'; then
    usermod -aG docker $USER
    CONDITIONS_MET=false
fi

if [ "$(stat -c '%U:%G' /var/run/docker.sock)" != "root:docker" ]; then
    chown root:docker /var/run/docker.sock
    CONDITIONS_MET=false
fi

if [ "$(stat -c '%a' /var/run/docker.sock)" != "660" ]; then
    chmod 660 /var/run/docker.sock
    CONDITIONS_MET=false
fi

if [ "$CONDITIONS_MET" = false ]; then
    echo "At least one condition is not met. Configuring ..."
    systemctl restart docker
    echo "GUI is now available in docker containers. Please Logout and login again to take effect."
else
    echo "All conditions were met. GUI is available in docker containers."
fi

echo "--------IMPORTANT: ----------"
echo "Please use docker commands: docker, docker-compose, ... WITHOUT sudo from now on."
echo "If you are using GUI apps over ssh, use with -X switch, like: ssh -X user@remote_pc."


wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.4.275.tar.xz
tar xvJf linux-5.4.275.tar.xz
rm -rf linux-5.4.275.tar.xz