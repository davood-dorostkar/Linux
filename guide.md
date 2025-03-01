# Session 2


00:13 shell
```sh
su
``` 
sudo -i //get interractive shell . what is difference from sudo -s
exit //exit ctrl+d
whoami //display current user
00:45 how shell runs command
commands:
1-internal like cd
2-external like ls
special charachters :

1:' ' space and tab natural sepeator
2:'$' replace environment value with name after dolar

1:06 01:23 break

1:28 echo and environment variables
define variable 
C=12
echo $C
export C //enable other apps access to env variables
imagin we issue this command : python test.py $HOME
what is arg[1] inside test
bash translate in before send . its become /home/user 

2:07 file path
cd // change directory
pwd // display current directory
2:21:50 absolute an relative paths
ls -a //display hidden files

2:59 3:20 break
3:23 standard input output
redirect: > write >> append
ctrl+d EOF
wc //count lines and words 
wc -l //count lines
grep
grep -i //incase sensetive
rm
sort -nr //numeric reverse
sort 
uniq -c //remove douplicates in adjacent lines. -c display with occurance number

# session 3 incompleted
00:15:
to see how much time commands need to complete:
```sh
time 
```
is result of last command inside shell:
```sh
$? 
```
connect two command run after each other if first successful:
```sh
&& 
```
run second command if first was unsuccessful:
```sh
|| 
```
redirect both stderror and std:
```sh
ls >1.txt 2>&1
```
redirect from stdin:
```sh
grep <1.txt
```
make it insensetive:
```sh
grep -i   
```
vice versa (or lines where has not foo):
```sh
grep -v foo 1.txt
```
count those line can use them with -v option also:
```sh
grep -c foo 1.txt
grep -cv foo 1.txt
```
multi file:
```sh
grep -cv foo 1.txt 2.txt
```
ping with interval:
```sh
ping -i 10 8.8.8.8 
```
globing:
```sh
ls /dev/tty*  # ttyS1 ttyS11 ...
ls /dev/ttyS? # just one char ttyS1 ttyS2
```
this search for ttyS2* ttyS3* ttyS4*:
```sh
ls /dev/ttyS[234]*
```
ls with range globbing:
```sh
ls /dev/ttyS[0-9][0-9] 
ls .dev/tty{S1,22} # world globbing
```
1:52:00 partitioning
```sh
sudo fdisk -l # list all partitions information
sudo fdisk /dev/sdb # goes into partitioning application for a disk
sudo gdisk /dev/sdb # the same with GPT feature
```
shortcuts:
- `?` show help
- `p` list partitions
- `w` save changes and exit
- `n` new partition
- `o` make GUID table
- `d` delete all partitions
- `a` make it bootable
- `t` change partition type
  - windows partition type: 0700

```sh
sudo mkfs.ntfs <partition_path> : format partition
sudo mkfs.ext4 <partition_path>
mkfs performs an all-zero format be default that takes long time 
```
- `-Q` or `--quick`  
- `-f` or `--fast` : fast format
- `-L` label : assing a label to partition

# session 4
```sh 
history
```
show command history

```sh
history -c
```
clear history loaded in ram

```sh
>.bash_history
```
clear history on disk

```sh
touch <file>
```
update modify date , if not exist create it

```sh
uname -a
```
installed kernel

```sh
uname -r
```
kernel release

```sh
apropos <word>
```
search in the manuals of apps

```sh
type <package>
```
short description of package

```sh
which <exec>
```
show path to exec file

```sh
<package> --help
```
brief help of package. package itself prints it

```sh
man <package>
```
man prints a external complete help file

```sh
unset VAR
```
remove VAR from env vars

```sh
echo \$HOME
```
escapes `$`

```sh
echo '$HOME'
```
escapes `$`

```sh
echo "$HOME"
```
not escape `$`
```sh
diff <source file> <dest file>
```
show difference. result:
```
24a25 (between line 24 and 25)
> XXX (XXX+source file = dest file)
55c56 
< YYY 
> ZZZ (source file - YYY + ZZZ = dest file)
```

## compression
```sh
gzip <file>
```
compress file and replace

```sh
gzip -d <file>
```
decompress file

```sh
zcat <file>
```
cat inside compressed file

```sh
zgrep <file>
```
search in compressed file

```sh
bzip2 <file>
```
more compression and replace

```sh
bzcat
```
```sh
bzgrep
```
```sh
/var/log/btmp
```
log of unsuccessful logins

```sh
xz <file>
```
most compression and replace

```sh
xzcat
```
```sh
xzgrep
```
to not replace original file:

```sh
gzip -c file > file.gz
```
gives output to stdout

## checksum
```sh
md5sum file
```
hash a file
```sh
shasum
```
```sh
sha256sum
```
```sh
sha512sum
```
```sh
sha256sum -c checksums
```
compare each file in current dir with checksums
checksums file syntax:
```
hash1 filename1
hash2 filename2
```
## read files
```sh
head <file>
```
10 first lines 

```sh
head -n 5 file
```
5 first lines

```sh
tail file
```
10 last lines

```sh
tail -n 5 file
```
last 5 lines

```sh
tail -f file
```
keep updating the outpu

```sh
less file
```
scrollable cat

```sh
less +G file
```
show the end of file

```sh
wc file
```
word and line count

```sh
nl <input>
```
show line number
example:
```sh
ls | nl
```

```sh
cut -d: -f2 file
```
show column '2' of file with delimiter ':'

```sh
cut -d $'\t' -f 1,2 data.txt
```
if delimiter is tab

```sh
cut -d ' ' -f 2 data.txt
```
if delimiter is space

```sh
od
```
show file in binary

```sh
od -c 
```
show characters


```sh
hexdump
```
show file in hex
same as
```sh
od -x
```

```sh
sed "s/input/output/" file
```
replace input with output

```sh
sed -n
```
no print

```sh
sed -i
```
inplace

```sh
sed -i.backup
```
inplace, get backup before it

```sh
tree
```
folder tree

```sh
mkdir -p path
```
make also parents if not exist

```sh
cp source1 source2 dest
```
multipe files

```sh
cp -p
```
preserve ownership,...

assume file name: `/home/davod/a.txt`

```sh
basename file
```
a.txt

```sh
dirname file
```
/home/davod

```sh
mv
```
```sh
rm -r
```
```sh
rm -i
```
interactive: asks for each file

## find
```sh
find path -type f -name filename -size filesize -mtime time -exec command
```
- `f`	regular file
- `d`	dir
- `c`	char device
- `b`	block device
- `l`	symlink

- `file.txt`		exact name
- `"file*"`		partial
- `-iname`	incase sensitive

- `12M`		exact size
- `+100M`
- `-10k`

- `-mtime -1`	modified in last 1 day
- `-mtime 1`	modified exactly 1 day ago
- `-mtime +1`	not modified in last 1 day
- `-mmin -1`	modified in last 1 minute
- `-atime -1`	accessed ~ ~
- `-ctime -1`	changed ~ ~

- `-exec ls \;`		run custom command on each match
- `-exec ls {} \;`		curly brace is that file path

- `-not`
- `-maxdepth n`		

```sh
stat file
```
file info

- `access`
- `modify`	change content
- `change`	change attributes (chmod)
- `touch` changes all

```sh
ls -R 
```
recursive into dirs

## archive
```sh
tar -czf <destination>.tar.gz <source files>
```
- `-f`	filename (must be last switch)
- `-c`	create
- `-x`	extract
- `-t`	list of contents	
- `-C`	extract to specific path
- `-v`	verbose
- `-z`	compress/decompress with gzip
- `-j`	compress/decompress with bzip2
- `-J`	compress/decompress with xz

```sh
du -h -s
```
show size of files and folders
- `-s`	show sum of folder
- `-h`	human readable

```sh
cpio
similar to tar

```sh
command1 | xargs command2
gives outputs of com1 line by line as 'argument' to com2

```sh
cat filelist.txt | xargs mkdir

```sh
command | tee result.txt
both sends result of com to stdout and result.txt
session 5
0:00 17:00 process
PID
Start Time		
Parent PID
Owner
Priority	
process status: Running Sleep sTop

ps: shows only proceess their parent is current shell
ps -ef: list all processes


00:29:59 00:35:43 alias
alias p="ping -c 4 8.8.8.8"
to see all aliases use command
alias

type p //display alias entry for p

continue process:
customize ps output 
ex :ps -eo cmd,pid,user,pcpu,s --sort pid

what is Ss Ss+ I R
Signals:
signal lists kill -L
term 15 #default kill 
send signal to process
kill -15 PID //gracefull 
kill -SIGTERM PID //gracefull 
signal 9 SIGKILL is send request to kernel to terminate app and it is most powerful signal
get pid from name
pidof processname
1:00 1:15 stop shar or break
ctrl+c send signal number 2 or INT
terminate ping command to see difference 

kill signal 9

killall ps name
kill all instances of process

kill all process from specific user
sudo pkill -u student
check load avrage with uptime command
uptime gives us 3 load avrage 1min 5min 15min
1:53 2:10 break
priority from 0 to 39 highest priority is 0
nice is from -20 to 19
only super user can do nice below 0
ex:nice -n 10 sleep 100

change priority 
renice -n 2 -p PID

02:22 dd command and swape
2:36 job control

ctlr+z 1-stop process 2-send to background
use bg  command to send continue background job
2:51 break
3:08 screen
pstree //shows process with childs inside  tree

screen -S customName
ctrl+a d detach from screen
screen -ls //list all available screens
screen -r screenname //if it is just one no need to mention screen name
screen -S train -X kill // kill screen

3:20 tmux
tmux //start tmux session
ctrl+b d //detach tmux session 
tmux a  //attach to tmux again
ctl+b c ///create new window in current tmux session
ctrl+b w //show menu to navigate ans select tmux tab
ctrl+b , //rename current tab in tmuxd
ctrl+b shift+ ' //creates new pane till 4
mtr -n 1.1.1.1 //trace rout?

3:39 vi
:syntax off
:q! exit wthout save
:x //save and exit
:w //write
:wq //write and exit
exclamation char is for override . you can edit read only file with x! or wq!
:set nu
:set nonu
change this file where vim keeps its settings

.vimrc
session 6-amin
00:00 1:30 stupid people talk about crap
01:30 1:55 permision 'user group other' just bits and numbers
each inode in ext4 is 256 bit

02:03 2:20 rwx table 
chmod [ugo][=+-][rwxst]
chown :newgroup file
chown ali:newgroup file
chgrp <group> <file or folder>

sticky bit  just work on directory. after set to delete you should be user to remove and renamefile in directory or edit content of other people
t-> we have x
T -> we dont have x
permision x for folder is mandatory. without x  and just with r u can get ls from folder . u cant even cd to it
who can run chmod : file owner and root

3:14
SUID bit highest bit
if we active sud bit file get permition of its owner and dont care who will run it
chmod +s <file>
find for all files with suid activ:
find /usr/bin/ -type f  -perm -4000

GID is a special permission bit that you can set on the groups. When you set SGID on an executable file, it enables the user to execute the file with the same permissions as the group.
sgid activate :
chmod 2777 file

permission files comes from umask
umask default is 0002
change umsak:
umask 0002
every 1  from umask becomes 0 in file permision
umask 0002 -> newdir 775
umask cant set x permistion for file u shold go explicitly give it x
		  

session 6-davood
cgroups: use to limit system resources
a better approach is: use containers

permissions
every file has an INode. it contains: UID(user/owner), GID(group), access levels
file access is 12bits: (from left to right)
type: 
- for regular files
b for block device
d for directories
3bits for user access
3bits for group access
3bits for other access
every 3bit is: [r - w - x] bits

```sh
stat file
shows file details including its inode data

you will be matched to one of (user-group-other) roles for every file. 
sequence of matching roles is user -> group -> other

```sh
ls -i
shows inode info

```sh
mkfs -I 1024 -N 100000 /dev/sdb 
-I : size of inodes
-N : num of inodes



regular file
directory
r
read content
ls 
w
modify content
modify, remove, create files in that dir, and modify directory
x
execute
no access to its files and subdirs


for [cp /a/b/c.txt /d/e] you need x for [a,b,d,e] , r for [c] and w for [e]

```sh
chmod 675 file
```sh
chmod [ugo][=+-][rwxst] file

session 7
mount points

```sh
lsblk -f 
shows existing disks and partition types

```sh
blkid /dev/sdb1
show a partition info

# /etc/fstab
location for auto mount points

fstab syntax example:

source
mount point
format
options
dump
pass
/dev/sdb1
/fs
ext4
defaults
0
0
UUID="XXXX"
/mnt
xfs
defaults
0
0


to check your fstab:
```sh
umount /fs
```sh
mount /fs
it should work

```sh
mount -a
mount all in fstab

rw or ro: rw stands for read-write, allowing both reading and writing to the file system, while ro stands for read-only, allowing only read access.

auto or noauto: auto means the file system will be automatically mounted at boot, while noauto means it won't be mounted automatically and requires manual mounting.

exec or noexec: exec allows execution of binary files on the file system, while noexec prohibits the execution of binaries.

user or nouser: user allows regular users to mount and unmount the file system, while nouser restricts this privilege to the superuser.

defaults: This option includes a set of default options, typically equivalent to rw, suid, dev, exec, auto, nouser, async.



groups

```sh
groupadd admin

# /etc/group
list of groups

syntax:
group_name:x:GUID:user1(non-primary),user2 (non-primary)
admin:x:1000:davood, ali

```sh
chown :group_name /path
change the group of file or folder

```sh
gpasswd group -a davood
add user to group

```sh
gpasswd group -d davood
delete user from group

```sh
groups davood
all groups that davood is in

# /etc/passwd
list of users

syntax:
user_name:x:UID:user_primary_group_GID::home_folder_path:default_shell
davood:x:1000:1000::/home/davood:/bin/bash

each user should have one and only one primary membership of a group, but can be member of many other groups

the only difference is that when he makes a file, his primary group will be the group of that file

if group is non primary for user, user will be in /etc/group
if group is primary for user, GID will be in /etc/passwd

```sh
useradd -m -s /bin/bash -g admin -G manager davood
-m: make home folder
-s: default shell
-g: set primary group
-G: add to group
-u: add a friendly name

# /etc/default/useradd
settings of adding users	 

# /etc/shadow
list of passwords as encrypted

syntax:
davood::other_info 
he can login without password

davood:!:other_info
no password set, cannot login

davood:HASH:other_info
set password

```sh
passwd davood
set password

```sh
chown davood /path
change owner of file or folder

```sh
chown davood: /path
also change the group to davood's primary group

other commands

```sh
usermod
```sh
userdel -r (if you want to also delete his home folder)

```sh
usermod davood -L
lock a user to login

```sh
usermod davood -U 
unlock

```sh
usermod --login new_username old_username
change user name

```sh
usermod --login new_name --move-home --home <new home> old_name
change user name and also its home folder

```sh
groupmod --new-name new_username old_username
change the name of previous user to the updated name

```sh
chsh -s /bin/bash
change default shell

```sh
chsh -s /bin/false
change to false or anything that does not exits -> user cannot login

```sh
groupmod
```sh
groupdel

```sh
gpasswd -a (add to group) -d (delete from group) user


SFTP
ssh-ftp; it is for file transfer over ssh; not confused with FTPS (ftp secure)

```sh
scp -P port source_path dest_path
the remote path syntax:
# user@ip:path
# user@ip: (path is home folder)

```sh
scp -P 443 /etc/file davood@gando.com:/etc/
```sh
scp -rP 443 /etc davood@gando.com:/etc/
transfer a folder

package management

packages are files built for us to install
install a package procedure:
copy its content on system
log files copied in a DB

how to install:
use standard repo -> sudo apt install (or yum, dnf)
add non standard repo -> sudo apt install
get package itself -> dpkg, rpm (you should also install its dependencies first)
get source code -> build (compile)

how to build:
you need a compiler (gcc)
but you cannot build big projects with gcc. you need a makefile to define the procedure
some source files are compiled together to create a object file (.o)
some files are compiled to create a library-shared object (.so)

but you also need to customize the project and build it for yourself. so you need a config file (config.sh for example). it will create your customized makefile.

```sh
apt install build-essential
most required tools for build

```sh
apt search xfs
search for something in the repo

```sh
ln -s automake-1.16 automake-1.15
sometimes it resolves making errors to create a link from what you dont have to existing files

```sh
make
build project based on makefile

```sh
make install
copy compiled file to a default location and make some symbolic links

when you install a package in this way, you need to remove all files and symbolic links manually afterwards. if you want to automate it, you can build a package from your source first.

```sh
ssh 127.0.0.1 -l davood
make a loopback ssh connection

debian package manager: apt
debian package installer: dpkg

redhad package manager: yum, dnf
redhat package installer: rpm

apt itself used dpkg to install packages.

```sh
cal
show calendar nicley

```sh
jcal
jalali cal

```sh
dpkg -l
list all installed packages

```sh
dpkg -i package
install

```sh
dpkg -P package
purge 

you want to install pack2. it requires pack1. if you install with apt, it autmatically will be installed. if using dpkg, you need to first install pack1. 
if you want to remove pack1 with dpkg, it will stop you. however, with apt, it will remove pack2 also.

# /etc/apt/sources.list
address of repos

```sh
dpkg -L package
show all files installed by a package

```sh
dpkg -I package.deb
show package info

```sh
dpkg -c package.deb
show files in a package

```sh
dpkg -S /path_to_file
show related packages to a file

# /var/cache/apt/archives/
saves deb files automatically here

```sh
apt clean
clears above folder

apt-cache rdepends --installed openjdk-8-jre
check which package installed openjdk-8-jre as a dependency

links
hard link: set a new name to existing Inode. that Inode will have two links (check it with stat). there is no new file.
limitations: cannot make hard link across partitions - cannot make hard links to directories

```sh
ln /existing_name /new_name
make hard link

soft link (symbolic link): make a new file with its own Inode. In its Inode, it has the path to another file. it does not have above limitations.

```sh
ln -s /existing_name /new_name
make soft link

port forwarding
```sh
ssh -L 127.0.0.1:4000:127.0.0.1:80 davood@IP_address -p port
forward port 4000 from internal device to port 80 of outside world and run ssh

access over ssh
to allow or ban access:

vim /etc/ssh/sshd_config
PasswordAuthentication no
or
PasswordAuthentication yes
service sshd restart
session 8
umask is the inverse of permission (umask 777 -> permission 000)

we can format a file as a disk. and then mount it
```sh
mkfs.ext4 <file>

here we need to define it as loop device
```sh
mount <file> /mnt -o loop 

show what files or folders are locked (open or in use by system)
```sh
lsof

```sh
lsof -u <username>

```sh
lsof -p <PID>


scheduling

cron.service is a service that is running by default by root.

# /var/spool/cron/crontabs/<user>
for every user there is a file for scheduled commands

but for safety we do not modify this file. instead we use 
```sh
crontab -e
for the first time it asks to choose your editor

when you define a cron, it is autmatic and no need to refresh its service

syntax: 
min hour day-of-month month day-of-week <command>
 * means every.
each entry can receive multiple values: 22,23,24
for day of week you can use number or 3 letters: fri, sat
*/5 means each 5 mins

```sh
crontab -l 
show cron content

there are default cron scripts in
# /etc/cron.daily (and hourly, monthly, weekly)

session 9
network interface (network card)

```sh
lspci | grep -i ethernet
show your network interface

```sh
lshw -class network
show detailed network interface data

extra: blacklist a device
sudo nano /etc/modprobe.d/blacklist.conf
blacklist <device name>
sudo update-initramfs -u
reboot


```sh
ifconfig
show network interfaces (physical and virtual. above commands: only physical)
it is in net-tools package

```sh
ifconfig -a
show also down interfaces

loopback interface: everything goes out, will come in. (usually 127.0.0.1): when we want a service that both server and client are in one machine.

```sh
ip
to config the network (ifconfig also works but ip is more important)
it is in iproute2 package

apt install iproute2

** in ip command, you can type uncomplete subcommands until they are unique
```sh
ip link show == ip li sh

```sh
ip link show
list of net interfaces; state is UP or DOWN; mac address is also provided

ip li
equal to ip li sh

```sh
ip link show dev <device name> 
show data of only one interface

```sh
ip link set up dev <name> 
turn up a physical device. the same with down


```sh
ip address show
show ip address

```sh
ip address 
equal to ip address show

```sh
ip address show dev <name>
show ip address set to this interface

```sh
ip addr add <ip> dev <name>
add an ip to the interface
you can add any number of ip to the same interface. they should be in the same range.

```sh
ip addr delete <ip> dev <name>
delete ip from interface

```sh
ip addr flush dev <name>
delete all ip from interface

-br
show data in brief. it must be used before other arguments, like: ip -br li sh

-c
colorize output. it must be used before other arguments, like: ip -br -c address sh

```sh
ping <ip> -c <repeat>
ping an ip for specific times

to use ping command:
apt-get install -y iputils-ping

```sh
ping <ip> -i <interval>

```sh
ip route show
show routing table

```sh
ip ro add <range ip> via <router ip>
tells that range ip should be accessed via specifc router
static route: a manually set route

```sh
mtr -n <dest ip> 
trace route a packet to an ip

```sh
ip ro del <ip>
```sh
ip ro del <dest ip> via <router ip>
delete from routing table

# 0.0.0.0/0 
default route. it matches every ip

every ip that matches an ip in routing table, uses that entry
if an ip matches more than one entry, it matches with smallest one
if an ip matches two same ranges with different 'next hop's, it will match the lowest metric

```sh
ip route add <range> via <router ip> metric 50
default is 100

if metrics are also the same, OS will load balance it

permanent net config (persistency)

debian (and ubuntu 18 and lower); reference
# ifupdown 
main package


```sh
ifdown enp7s0
```sh
ifup enp7s0
up and down an interface	

# /etc/network/interfaces : net config is set here

sample config:
#  auto eth0 (auto interface setup at startup)
# iface eth0 inet dhcp (to use ipv4 and dhcp)
options: dhcp/none/static
options: inet/inet6

sample static config:
# auto eth0
# iface eth0 inet static
#     address 192.0.2.7/24
#     gateway 192.0.2.254
 
redhat 6; reference

# /etc/resolv.conf
dns settings

# /etc/sysconfig/network
global interfaces config

# /etc/sysconfig/network-scripts/ifcfg-<interface-name>
a file for each interface config

sample 1:
DEVICE=eth0
BOOTPROTO=none
ONBOOT=yes
NETMASK=255.255.255.0
IPADDR=10.0.1.27
USERCTL=no

sample 2:
DEVICE=eth0
BOOTPROTO=dhcp
ONBOOT=yes


redhat 8; reference

```sh
nmcli
tool to permanent net config

```sh
nmcli connection show
```sh
nmcli connection add con-name <connection-name> ifname <device-name> type ethernet

```sh
nmtui
the same thing with a minimal gui

ubuntu 20+

# netplan
main package
in gui systems 'network manager' package takes the control

# /etc/netplan/*.yaml
network config file in yaml

```sh
netplan apply
to take effect after changing config


DNS

# /etc/resolv.conf
dns settings - it is a symlink

```sh
nslookup google.com
returns ip of web server

```sh
nslookup <site> <dns ip>
return ip from specific dns

```sh
netstat -lnpu
show active internet connections

```sh
resolvectl status
show DNS settings for each interface

# /etc/hosts
manual dns
if you want not to use dns for specific ip
if dns is not available
syntax: <ip> <alias or host url> <alias or host url> …

```sh
curl ip-api.com
show your current internet identity data

session 10
LVM

MBR issue: cannot have more than 4 primary partitions
GPT issues: 
not designed to change partition size
cannot have a partition over two disks

LVM: logical volume manager
PE: smallest unit of data in LVM (default: 4MB); all sizes must be a mutiplier of this
PV: first layer; physical volume
a disk can be partitioned as PV; a part of a disk can also be partitioned as PV

VG: second layer; volume group
think of it as virtual disks
you can add some pv to vg

LV: third layer; logical volume
think of it as virtual partitions
you can divide a vg into some lv

# lvm2
main package 

```sh
pvcreate <disk or a part of disk>
turn disk into pv

```sh
pvdisplay
show pv's

before/after creating a pv, it is better to change that partition type into LVM (8e) with fdisk

```sh
vgcreate <vg name> <path to pv to add>
create a vg

```sh
vgdisplay
show vg's

```sh
vgextend <vg name> <path to new pv>
add new pv to a vg

```sh
vgreduce <vg> <pv>
remove pv from vg

```sh
lvcreate --name <lv name> <size> (ex: L1G) <source vg>
create a lv on a vg



lv partitions are added as /dev/dm-0 and  …

```sh
ls -l /dev/mapper/
see symlinks to lv partitions(there is a symlink with <lv name> to partition files mentioned above)

# /dev/<vg name>/<lv name>
another symlink to the same thing. it is more readable

after making LV you can format it like a normal partition with mkfs

```sh
lvdisplay
show all lv in detail

```sh
lvdisplay <path to lv>
show a lv detail

note: system cannot boot from a LVM partition. so linux makes a mbr or GPT partition to boot.





RAID


we also have software raid in linux

```sh
mdadm

extend a partition:
unmount
```sh
umount <mount point>
extend partition
```sh
lvextend -L+512M <partition>
check disk integrity
```sh
e2fsck -f <partition>
extend its file system
```sh
resize2fs <partition>



shrink a partition:
unmount
```sh
umount <mount point>
check disk integrity
```sh
e2fsck -f <partition>
shrink file system
```sh
resize2fs <partition> <new size>
shrink partition
```sh
lvreduce <new size> <partition>


```sh
vgchange -an
deactivate all vg

```sh
vgscan 
finds all connected vg

```sh
vgchange -ay 
activate all existing vg

dd

```sh
dd if=<source> of=<dest> status=progress bs=1024 count=1
also show progress
bs: size to read each iteration
count: # of bs to read

```sh
dd if=.. status=progress | gzip -c > <dest.gz>
make image and compress at the same time

```sh
gzip -dc <source.gz> | dd of=<dest disk>
extract image and copy to disk

```sh
ssh user@ip command
to run a command on another machine without entering a shell

```sh
gzip -dc <image> | ssh user@other-machine-ip dd of=<partition>
extract an image and write to a partition on another machine over ssh



example: 

```sh
cat w.txt | ssh student@185.83.115.40 -p 10008 "cat > /home/student/rcv.txt"

shell

login shell runs all these 4 files. non-login shell runs only bashrc's. 

```sh
sudo -i
get root login shell

```sh
sudo -s 
get root non-login shell

interactive shell is when your keyboard is connected to console. non-interactive shell is when you run a script in a shell.

```sh
bash -i
get an interactive shell


session 11

partition type of linux LVM in MBR: 8e, in GPT: 8e00 (always adds 00 hex for next byte)

regex
it matches only once per segment
. any char
[^ ] not
^ start of string
```sh
end of string
{3} number of chars
{2,6} {2,} number of chars range
* means {0,} , affects previous token
+ means {1,}, affects previous token
? means {0,1} , affects previous token
\d means [0-9]
\D means [^above]
\w means [a-zA-Z0-9_]
\W means[^above]
\. means . literally etc.

regex is greedy by default (it matches with longest match). 
to turn it off use: *?, *? instead of *,+ : it gives shortest match

grouping with ():
make subpattern with (    |     )
use groups with their number like: \1

grep with regex:
grep -E = egrep
fgrep : no regex support

sed -E  's/regex/result' input.txt

in vi : :%s/regex/replace_with/g - for search and replace
in vi you have to escape the parantheses for grouping : \(regex\)

in python: 
import re
re.findall(r"regex", input)


linux boot
firmware runs sector 0 of disk. inside it there is bootloader code. it finds and runs kernel and knows file systems.
it has 446Byte limit.
kernel is not responsible for the rest of os. it runs /sbin/init. this file runs other processes.
/sbin/init is symbolic link to systemd for new distros

lilo was old linux boot loader.
grub is the new one. grub has stage1 (446byte) which runs stage2 (/boot/grub). it does not have limit. it has many features.

hit esc to see grub menu
use `e` to edit booting settings
parameter `linux` : root= the path to kernel device, ro : readonly, the kernel is readonly until boot finish
initrd: a copy of required services for booting

password recovery:
change ro -> rw , and add init=/bin/bash, then change password

change grub settings: /etc/default/grub then hit: update-grub

session 12
system init
/sbin/init has PID=1 and is the parent of all other processes

sysVinit (old linux init type):

runlevel 1: only root is enabled. is used for maintenance.

```sh
runlevel
shows previous and current runlevel state

```sh
sudo init 3
change runlevel

/etc/rc.local
old way to make custom init

systemd (new linux init)
it has a lot more responsibilities than sysVinit

```sh
systemctl 
show all processes run by systemd

```sh
systemctl --type service
show only services

```sh
systemclt status myservice

every service has a unit file (the address is shown in status), which tells what should be done when starting, stopping, …

```sh
systemctl disable/enable myservice
enable means will be run on boot
when enabling, a symlink will be created inside /etc/systemd/system/multi-user.target.wants/

```sh
systemctl is-enabled myservice

```sh
systemctl start/stop myservice

```sh
systemctl get-default
view current default target

```sh
systemctl --type=target
view all targets
or
```sh
systemctl --type=target --all

```sh
systemctl set-default multi-user.target
set default target
available:
poweroff.target – This is the target in which the system shuts down. For obvious reasons it is unlikely you would want this as your default target.
rescue.target – Causes the system to start up in a single user mode under which only the root user can log in. In this mode the system does not start any networking, graphical user interface or multi-user services. This run level is ideal for system administrators to perform system maintenance or repair activities.
multi-user.target – Boots the system into a multi-user mode with text based console login capability.
graphical.target – Boots the system into a networked, multi-user state with graphical desktop environment 
reboot.target

make a service:
create a file in /etc/systemd/system/myservice.service with unit file standard
it should point to a script file somewhere

then
```sh
systemctl daemon-reload
reloads all services, used when created new service

second way: 

```sh
crontab -e 
@reboot script/path

shutdown
```sh
halt
```sh
init 0
```sh
shutdown 
shutdown +15 : shutdown after 15 minutes
```sh
shutdown -r 10:30 : reboot at 10:30
shutdown +10 "Save your work! This system will shut down in 10 min!" : with a message
```sh
shutdown -c
cancel shutdown
shutdown --show  : show scheduled status 
```sh
poweroff

logs

logging settings is in the /etc/rsyslog.conf
it includes also the config files in /etc/rsyslog.d/

session 13
systemd-continued
as you kinow /etc/fstab is used for mouning disks. systemd controls every kind of initialization, to name some: mounig points, services, …
in newer linuxes systemd also reads fstab by default and automatically makes unit files to mount them and so the recommended approach is using fstab to define mount points.

containers start an application directly without using an init system like systemd

```sh
tune2fs
change parameters of existing fs (inodes, journaling, …)

system time

```sh
date
show current date and time

timezone data are stored in the tzdata package

```sh
date -u
show utc

```sh
date -I
format it in iso 
(there are a lot of options for formatting)

```sh
date +"%Y"
manually formatting the output of date

```sh
date -–date='@some_number'
time and date for when some_number seconds had past the epoch
epoch=the beginning of time (1 jan 1970)

```sh
hwclock
time which has been read from HW clock (it is not the HW clock directly)

```sh
hwclock -v
verbose mode

```sh
hwclock –systohc (or -w)
set hw clock from system time

```sh
hwclock –hctosys (or -s)
set system time from hw clock

```sh
timedatectl
show data about time and timezone

```sh
timedatectl set-time '2023-08-22 10:00:00'
set current time

```sh
timedatectl list-timezones

# /etc/localtime
this is a symbolic link to the current TZ binary file

# /usr/share/zoneinfo/
the location of all TZ files

```sh
ln -s /usr/share/zoneinfo/Asi/Tokyo /etc/localtime
change the TZ 

```sh
datetimectl set-timezone Asia/Tehran
the same


NTP

```sh
apt install systemd-timesyncd
install ntp client service

```sh
systemctl status systemd-timesyncd

sync your time:
```sh
systemctl restart systemd-timesyncd
```sh
timedatectl timesync-status


```sh
systemctl status ntpd
another ntp client (and server) - not much used

```sh
ntpdate pool.ntp.org
one time fix date and time

pool.ntp.org is a project consisting of a cluseter of servers for ntp

```sh
chrony
recommended as ntp service

sudo apt update
sudo apt install chrony

(it will replace systemd-timesyncd service)

sudo systemctl start chronyd
sudo systemctl enable chronyd



```sh
chronyc tracking
detailed info about ntp

```sh
chronyc sources
show sources of ntp

```sh
chronyc makestep
same as ntpdate

```sh
dpkg -l package
show package status

```sh
apt purge package
remove package & its configs

language and charset

LANG

```sh
od
show file in binary

```sh
hexdump
show file in hex
same as
```sh
od -x

every character is 1 byte = 128 case for ASCII and 128 for other chars (farsi). you need code page to encode the character (cp1256 for arabic)

unicode.org made a code for every character
UTF-8 is a variable encoding:
for 0-127 = 1 byte
for others 2, 3, 4 byte depend on char

```sh
iconv -f ISO-8859-1 -t UTF-8 input.txt -o output.txt
convert encoding from -> to

```sh
iconv --list
list of all encodings

LC_something
env  variables for language and charset

```sh
locale
show current LC settings

privilege

```sh
su user
this does not run profile

```sh
su -l user
gives login shell and run profile
you will be in user home folder

```sh
su user -c "command"
command is run with user privilege

sudo is a service that is running with root privilege 
its config is in 
/etc/sudoers

in this file you can define users with custom access

all users in sudo group can run sudo (run with root privilege) with their pass

```sh
groups user
show all groups of user

```sh
sudo su user
switch user without password 

if you run a command with sudo and then redirect output to a file, actions after redirect are done with current shell and it does not have root access!
sudo ls > /var/log/1.txt
to fix this:
echo hi | sudo tee /var/log/kern2.log 1>/dev/null

shell scripting
1. 
```sh
bash file.sh

2.
```sh
bash < file.sh

3. 
add 
#! /bin/bash (or anything)
then 
chmod +x file
then 
./file

only when you run a text file, #! (shibang) is important and shell decided what to use
previous ways make a new shell and run in it -> env vars will be a issue. the child shell does not have access to parent env vars, unless you have exported them

```sh
source file
not make a new shell. it runs all lines of file in current shell

```sh
. file
same as source

```sh
env
show all env vars

```sh
env VAR=100 ./script
run script with VAR without defining it (or you want to run it with modified VAR)

```sh
env VAR=100 command
the same

```sh
command $1
inside a bash script, $1 means first argument. you can pass arguments. $0 is the script path

```sh
echo -e "123"
do not interpret backslash escape

```sh
echo -n "123\n"
do not add automatic new line, remove any ending newline

```sh
mkdir `date`
backtick lets you run a command inside another command

/lib/modules/
path of kernel modules

```sh
ls /bin/modules/`uname -r`/kernel

```sh
ls /bin/modules/$(uname -r)/kernel
the same

```sh
expr $A + $B
do arithmetic

```sh
echo $((A + B))
the same

```sh
command1 && command2
run com2 only if com1 successful with return 0

```sh
command1 || command2
run com2 if com1 not successful

```sh
-eq
check 	numeric equality

```sh
= , ==
check string equality


session 14

GUI
xserver: a component that provides graphical user interface
xclient: any software that works with gui
gui works on network in linux
window manger: manages multiple xclients in the system


widgets: provide standard components to xclients

at boot systemd runs graphical login. it connects to xserver. after login it runs window manger and still keeps running. 

desktop environment: a prepared package including a xserver+a graphical login+ a window manager+ … : gnome, kde, …

xserver forwarding
```sh
ssh -l <user> 127.0.0.1 -X firefox
run a gui app over ssh in localhost

```sh
ssh user@ip -X firefox
run a gui app over ssh

settings to config for xserver forwarding (need to be checked):
in the /etc/ssh/sshd_config : X11Forwarding yes
sudo systemctl restart ssh
sudo apt install x11-xserver-utils
xhost local:root
or
xhost + local:
or
xhost +

$apt -y install x11-apps
some basic apps to test x11 (like xeyes)

```sh
sudo apt install ubuntu-desktop
install ubuntu desktop env

```sh
sudo apt install lxde

tty
tty are the consoles that you can connect to the machine (it can be a bash shell, gui ,...)
shortcut: ctrl+alt+(F1, F2, …)


Misc
will be in the exam:
how to redirect both stdout and stderr? 
ls / >out.txt 2>&1

how many files and folders in the current dir? find

find . -mtime +1: modified since begining to 1 day ago
find . -mtime -1: modified in 1 day ago until now

bash -norc

** memorize all package management options for exam

notes:
vi:
first you are in command mode
i : insert mode
esc: command mode
:wq : save and quit
:w : save
:q! : quit without save
/ : search in file, n : next search match, N : prev search match
:%s/word/newword : find and replace

time ls : execution time of ls

status code: 0 -> successfully run
? : env var for last status code

sleep 5 ; ls : execute in order
sleep 5 && ls : execute if first one has satus code 0
sleep 5 ||  ls : execute if first one does not has satus code 0

> : redirect stdout 
1> : redirect stdout 
2> : redirect stderr

home folder of users: /home/davood
home forlder of root: /root

history: show previous command history
.bash_history file
history -c : clear loaded history until logout

grep -v text file: lines without text
grep -c text file: number of lines with text
grep -n text file: show line number

cpu info: /proc/cpuinfo

touch: change file timestamp (modified time)

to make a empty file: 1. touch file ,2.  >file

uname -a: kernel data
uname -r: kenel release data

man : full desc
type: short desc
apropos: search in desc

use / to search in man

scape special chars:
use \
use " ": does not escape some chars like $
use ' '

gzip file
gzip -d file.gz
gzip -c file > file.gz
gzip -dc file.gz > file
zcat: read a compressed file
zgrep

bzip2 file
bzip2 -d file.bz2
bzip2 -c file > file.bz2
bzip2 -dc file.bz2 > file
bzcat
bzgrep

xz file
xz -d file.xz
xz -c file > file.xz
xz -dc file.xz > file
xzcat
xzgrep

md5sum text
shasum text
sha256sum
sha512sum

echo -n salam: does not append newline at the end

cp file1 file2 file3 .
copies 3 files to here. the last argument is the destination

everything is file. types of file: regular file, directory,...

stat file
modify -> content
change -> attributes

tar -cf myfile.tar *
f must be at the end, becuase myfile.tar is the input for f

assignment:
linux everything is a file 
sed tutorial
du -hs folder/
fgrep, egrep
set, unset


rsync
transfer files more efficient than cp. it can work over network. it reduces transfer with a diff mechanism. link

rsync source destination (copies source into destination)
rsync source/ destination (copies source's contents into destination)
--progress or -P show progess for each file
The --info=progress2 gives a overall percentage
perform a trial run with no changes made using --dry-run
--remove-source-files deletes source files, like a move
-a copying files recursively
-v verbose
-h human readable
-z compress (usefull when transferring over network)
--ignore-existing ignore if file exists in destination

rsync -a is equal to rsync --archive and is a convenience command. According to the man page, it equals rsync -rlptgoD :
-r or --recurse: recursively copy data
-l or --links: copy symlinks as symlinks
-p or --perms: preserve permissions
-t or --times: preserve modifications times
-g or --group: preserve the group
-o or --owner: preserve owner
-D is the same as --devices --specials:
--devices: preserve device files
--specials: preserve special files
rsync -a --info=progress2 --no-i-r src dst
--no-i-r is short for --no-inc-recursive and disables incremental recursion, forcing rsync to do a complete scan of of all directories before starting the file transfer. This is needed to get an accurate progress report, otherwise rsync doesn’t know how much work is left.

rsync -avz /usbdisk/ calomel@somemachine:/backups/ : use over ssh
rsync -avz --del src dest : delete any file on dest that is no longer in src
rsync -avz user@machine:/backups/ local/ : pull instead of push
rsync -avz src/{file1,file2,file3} dest : multiple files
or 
rsync -avz src/file1 src/file2 dest

rsync -avR user@machine:'`find /data/video -name "*.[avi]"`' /download/ : use shell command
rsync --backup --backup-dir=`date +%Y.%m.%d` -a src/ /BACKUP/ : incremental backup into named folder

typical command:
rsync -avhz --no-i-r --preallocate --info=progress2 src dest/
or ommit 'v' option for better visual

automatic DHCP 

#### Step 1: Check for Conflicting Configurations
1. **Check if `eno1` is marked as unmanaged in NetworkManager's device settings**:
   Sometimes, specific devices are marked as unmanaged in separate config files. Run:
   ```bash
   sudo grep -r 'eno1' /etc/NetworkManager/
   ```
   Look for any configuration that explicitly marks `eno1` as unmanaged and remove it if found.

2. **Check `/etc/network/interfaces`**:
   Since NetworkManager can be influenced by the traditional network configuration system (`/etc/network/interfaces`), check that `eno1` is not configured there.
   ```bash
   sudo nano /etc/network/interfaces
   ```
   If you find a configuration for `eno1`, either remove it or comment it out by placing a `#` at the beginning of each line related to `eno1`.

3. **Verify any `udev` rules**:
   Sometimes, devices are managed through `udev` rules. Run the following to check if `eno1` has any `udev` rules associated:
   ```bash
   sudo grep -r 'eno1' /etc/udev/
   ```
   If there are rules that mark the device as unmanaged, you may need to modify or remove them.

#### Step 2: Explicitly Tell NetworkManager to Manage the Device
1. **Add a specific unmanaged devices rule** to handle this in the NetworkManager configuration:
   Edit the NetworkManager configuration:
   ```bash
   sudo nano /etc/NetworkManager/NetworkManager.conf
   ```

2. **Explicitly allow NetworkManager to manage all devices except bridges** (since you have many bridges, this can help):
   Add or modify this section:
   ```ini
   [keyfile]
   unmanaged-devices=type:bridge
   ```

3. **Clear any unmanaged state for `eno1`**:
   If you made changes, force NetworkManager to forget any unmanaged state for the `eno1` device by deleting the state:
   ```bash
   sudo nmcli general reload
   sudo nmcli device reapply eno1
   ```

#### Step 3: Restart NetworkManager and Bring Up the Device
After making these changes, restart the relevant services:

1. **Restart NetworkManager**:
   ```bash
   sudo systemctl restart NetworkManager
   ```

2. **Bring the device up again**:
   ```bash
   sudo nmcli device set eno1 managed yes
   sudo nmcli device connect eno1
   ```

3. **Check the status of `eno1`**:
   ```bash
   nmcli device status
   ```

### Step 4: Reboot the System
If all else fails, a system reboot may be necessary to apply all the configuration changes:
```bash
sudo reboot
```

After rebooting, check whether the `eno1` interface is now managed and properly configured. If this still does not resolve the issue, we can investigate further, but these steps should ensure that NetworkManager is correctly managing the `eno1` interface. Let me know how it goes!




fix issues with ubuntu gui (e.g. missing sys tray)

Uninstalling Python on Ubuntu can cause a lot of problems because many core components of the system, such as the GUI and network management tools, depend on Python scripts. Even after reinstalling Python, some dependencies and packages may still be broken or missing, leading to issues like missing tray icons.

Here's how you can troubleshoot and potentially resolve the problem:

### 1. **Reinstall Essential Ubuntu Packages**
Since system packages may have been broken during the uninstallation of Python, it's important to reinstall some key components of the desktop environment. Run the following commands to reinstall the core components:

```bash
sudo apt update
sudo apt install --reinstall ubuntu-desktop gnome-shell gnome-shell-extensions gnome-tweaks indicator-application
```

This ensures that core desktop packages and the GNOME shell (or other desktop environment you're using) are properly set up.

### 2. **Check for Missing Dependencies**
Verify if any packages are missing or if there are broken dependencies that need to be fixed:

```bash
sudo apt --fix-broken install
sudo apt autoremove
```

The first command fixes broken dependencies, while the second removes unnecessary packages that might have been orphaned after uninstalling Python.

### 3. **Reinstall Python Dependencies**
Some Ubuntu-specific tools, such as network managers and GUI applications, might still require specific Python modules. Reinstall the `python3` and its related packages:

```bash
sudo apt install --reinstall python3 python3-venv python3-pip python3-gi
```

The `python3-gi` package is essential for the GNOME interface, as it provides Python bindings for GTK.

### 4. **Check for Missing System Tray Icons**
The issue with tray icons could be related to `gnome-shell-extension-appindicator` or a similar extension that provides tray icon support. To reinstall it, run:

```bash
sudo apt install --reinstall gnome-shell-extension-appindicator
```

After reinstalling, restart GNOME or the entire system for changes to take effect:

```bash
gnome-shell --replace &
```

Alternatively, reboot the system:

```bash
sudo reboot
```

prevent auto start an application
To prevent RustDesk from starting automatically at startup, even though it doesn't appear in the "Startup Applications" list in Ubuntu, you can try the following steps to stop it from launching on boot.

### 1. **Check for Systemd Services**
RustDesk might be registered as a service with `systemd`, which would cause it to start automatically. To check if there's a service for RustDesk, follow these steps:

- Open a terminal and run:

```bash
systemctl list-unit-files | grep rustdesk
```

If a RustDesk service exists, you'll see an entry for it.

- If you find a service, disable it using:

```bash
sudo systemctl disable rustdesk
```

This will prevent it from starting automatically on boot.

- To stop it immediately without rebooting:

```bash
sudo systemctl stop rustdesk
```

### 2. **Check for Autostart Desktop Entry**
Sometimes applications create autostart entries in the user’s home directory under the `.config/autostart/` folder.

- Check if there's a RustDesk autostart entry by running:

```bash
ls ~/.config/autostart/
```

- If you see a `rustdesk.desktop` file, delete it to stop RustDesk from starting automatically:

```bash
rm ~/.config/autostart/rustdesk.desktop
```

### 3. **Check for Crontab Entry**
Sometimes, applications might be configured to start via `cron`. Check your crontab to ensure RustDesk isn't being triggered through it.

- Open your user crontab with:

```bash
crontab -e
```

- If you see any entry related to RustDesk, remove it.

### 4. **Check Global Autostart (For All Users)**
RustDesk might have created a system-wide autostart entry. To check for this, look in `/etc/xdg/autostart/`:

- Run:

```bash
ls /etc/xdg/autostart/
```

- If `rustdesk.desktop` is listed, you can either delete it or move it elsewhere:

```bash
sudo mv /etc/xdg/autostart/rustdesk.desktop /etc/xdg/autostart/rustdesk.desktop.bak
```

This will effectively disable the autostart entry.

---

By following these steps, you should be able to prevent RustDesk from running at startup. Let me know if it worked, or if you need further assistance!


disable automatic update check

sudo systemctl disable unattended-upgrades

or 

sudo apt remove unattended-upgrades


see all services
systemctl list-unit-files

create swap
- add swap
```sh
sudo fallocate -l 2G /swapfile
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
echo '/swapfile none swap sw 0 0' >> /etc/fstab
```
- reboot the system

run command periodically
```sh
watch <command>
```
the default interval is 2 sec

options:
```sh
-n 10 # run each 10 sec
-t # hide header
-c # Interprets ANSI color sequences.
-d # highlights the changes in the command output
```

set ssh key
eval "$(ssh-agent -s)" && ssh-add ~/.ssh/davood

sshuttle
sudo apt-get install sshuttle
sshuttle --dns -vNHr root@49.13.228.90 -x 49.13.228.90:22 0/0

telnet
telnet smtp.gmail.com 587


email client with cli
sudo apt install msmtp

nano ~/.msmtprc

account default
host smtp.gmail.com
port 587
auth on
user dado2hacker@gmail.com
password APP_PASSWORD
from  dado2hacker@gmail.com
tls on

echo "Hello, this is a test" | msmtp dado2hacker@gmail.com