# manager-createstructure
[![GitHub license](https://img.shields.io/badge/license-GNU-green?style=flat)](https://github.com/createstructure/manager-createstructure/blob/main/docs/LICENSE)
![Author](https://img.shields.io/badge/author-Castellani%20Davide-green?style=flat)
![sys.platform supported](https://img.shields.io/badge/OS%20platform%20supported-all-blue?style=flat) 

##  Description 
Repo for managing the creation of the repos
![createstructure/manager-createstructure](https://opengraph.githubassets.com/df75cb80a35dc3c06c2259ad1b64f4d508e3ddabdecd47e27731572eac1cc005/createstructure/manager-createstructure)
##  Directory structure 

```
../repo
├── Makefile
├── bin # source code
│   ├── global-libraries
│   │   ├── bin # source code
│   │   │   ├── cryptation.hpp
│   │   │   ├── emoji.hpp
│   │   │   ├── inputs.hpp
│   │   │   ├── json.hpp
│   │   │   ├── positive.hpp
│   │   │   ├── rest.hpp
│   │   │   └── sleep.hpp
│   │   └── docs # documentation
│   │       ├── CHANGELOG.md
│   │       ├── LICENSE
│   │       └── README.md
│   ├── local-libreries
│   │   ├── help.hpp
│   │   ├── login.hpp
│   │   ├── memory.hpp
│   │   └── version.hpp
│   ├── manager.cpp
│   └── manager.yml
├── debian # debian control code
│   ├── changelog
│   ├── compat
│   ├── control
│   ├── copyright
│   ├── manager.dirs
│   ├── postinst
│   ├── postrm
│   ├── preinst
│   ├── rules
│   └── source
│       └── format
├── docs # documentation
│   ├── LICENSE
│   └── README.md
├── manager.1
└── requirements.in

8 directories, 31 files
```
manager (10.01.02) focal; urgency=medium

  * [beta => latest](https://github.com/createstructure/manager-createstructure/issues/9)

 -- Castellani Davide <help@castellanidavide.it>  Sat, 11 Dec 2021 23:15:00 +1000

manager (10.01.01) focal; urgency=medium

  * [Create a Docker management system](https://github.com/createstructure/manager-createstructure/issues/3)
  * [Create service for the new REST API](https://github.com/createstructure/manager-createstructure/issues/4)
  * [Create a routine to automate the Docker container management](https://github.com/createstructure/manager-createstructure/issues/5)
  * [Include install.sh in the manager-createstructure debian package](https://github.com/createstructure/manager-createstructure/issues/1)
  * [Convert functions into classes in all libraries](https://github.com/createstructure/manager-createstructure/issues/6)
  * [Improve documentation](https://github.com/createstructure/manager-createstructure/issues/7)

 -- Castellani Davide <help@castellanidavide.it>  Fri, 10 Dec 2021 22:00:00 +1000

manager (09.01.20) focal; urgency=medium

  * Try to change reboot waiting-time (3h => 6h)

 -- Castellani Davide <help@castellanidavide.it>  Tue, 07 Sep 2021 08:05:00 +1000

manager (09.01.19) focal; urgency=medium

  * Change reboot waiting-time (12h => 3h)

 -- Castellani Davide <help@castellanidavide.it>  Mon, 13 Aug 2021 16:00:00 +1000

manager (09.01.18) focal; urgency=medium

  * Added help management

 -- Castellani Davide <help@castellanidavide.it>  Mon, 19 Jul 2021 10:45:00 +1000

manager (09.01.17) focal; urgency=medium

  * Updated librerias
  * Optimized importations
  * Formatted source

 -- Castellani Davide <help@castellanidavide.it>  Sun, 18 Jul 2021 14:30:00 +1000

manager (09.01.16) focal; urgency=medium

  * auto-reboot now "stable"
  * removed file "files"

 -- Castellani Davide <help@castellanidavide.it>  Sat, 17 Jul 2021 14:15:00 +1000

manager (09.01.15) focal; urgency=medium

  * Test auto-reboot #2

 -- Castellani Davide <help@castellanidavide.it>  Sat, 17 Jul 2021 13:15:00 +1000

manager (09.01.14) focal; urgency=medium

  * Test auto-reboot

 -- Castellani Davide <help@castellanidavide.it>  Thu, 15 Jul 2021 15:15:00 +1000

manager (09.01.13) focal; urgency=medium

  * Fixed a bug

 -- Castellani Davide <help@castellanidavide.it>  Tue, 13 Jul 2021 21:15:00 +1000

manager (09.01.12) focal; urgency=medium

  * Fixed a bug

 -- Castellani Davide <help@castellanidavide.it>  Sun, 11 Jul 2021 10:15:00 +1000

manager (09.01.11) focal; urgency=medium

  * Added auto-reboot every 12h

 -- Castellani Davide <help@castellanidavide.it>  Sat, 10 Jul 2021 20:30:00 +1000

manager (09.01.10) focal; urgency=medium

  * Fixed a bug

 -- Castellani Davide <help@castellanidavide.it>  Fri, 07 Jul 2021 15:00:00 +1000

manager (09.01.09) focal; urgency=medium

  * Optimized some librerias

 -- Castellani Davide <help@castellanidavide.it>  Fri, 07 Jul 2021 14:45:00 +1000

manager (09.01.08) focal; urgency=medium

  * Changed librerias management

 -- Castellani Davide <help@castellanidavide.it>  Fri, 25 Jun 2021 9:15:00 +1000

manager (09.01.07) focal; urgency=medium

  * Changed docker

 -- Castellani Davide <help@castellanidavide.it>  Tue, 22 Jun 2021 21:10:00 +1000

manager (09.01.06) focal; urgency=medium

  * Added ARM availability

 -- Castellani Davide <help@castellanidavide.it>  Mon, 21 Jun 2021 17:55:00 +1000

manager (09.01.05) focal; urgency=medium

  * fixed a bug
  * Added install.sh in the repo

 -- Castellani Davide <help@castellanidavide.it>  Sun, 20 Jun 2021 10:00:00 +1000

manager (09.01.04) focal; urgency=medium

  * Enabled debug to find the error

 -- Castellani Davide <help@castellanidavide.it>  Sun, 20 Jun 2021 8:30:00 +1000

manager (09.01.03) focal; urgency=medium

  * Fixed a bug

 -- Castellani Davide <help@castellanidavide.it>  Sat, 19 Jun 2021 22:00:00 +1000

manager (09.01.02) focal; urgency=medium

  * Fixed a bug w/ Docker container

 -- Castellani Davide <help@castellanidavide.it>  Sat, 19 Jun 2021 21:00:00 +1000

manager (09.01.01) focal; urgency=medium

  * Initial version

 -- Castellani Davide <help@castellanidavide.it>  Sat, 19 Jun 2021 16:00:00 +1000
##  Rebuild the manager-createstructure locally 
Install the manager-create locally permits you to do some debug and try new configurations.

### Steps:
- [ Rebuild the manager-createstructure locally ](#octocat-rebuild-the-manager-createstructure-locally-octocat)
  - [Steps:](#steps)
  - [1. Install VirtualBox on the PC](#1-install-virtualbox-on-the-pc)
  - [2. Install Ubuntu](#2-install-ubuntu)
  - [3. Install dependencies](#3-install-dependencies)
  - [4. Compile](#4-compile)

### 1. Install VirtualBox on the PC
For installation we suggest VirtualBox, a tool that allows you to create one or more virtual machines :computer:.
If any of these crashes, in any case, your PC will not lose data, at most you will have to restart it :smile:.

To install VirtualBox on your PC you need to:
- Get in into the UEFI
- Enable the function which name is like "Virtualization" (for each UEFI this step is different but similar)
- Save the configuration and restart the PC
- Go to the [VirtualBox website](https://www.virtualbox.org/)
- Press "Download"
- Run the downloaded file
- Follow the installation steps

### 2. Install Ubuntu
As the OS we suggest to use Ubuntu, because it is lightweight (for RAM and CPU) and it's free.

To install Ubuntu on VirtualBox you need to:
- Download the last LTS version of Ubuntu by the following link: [https://ubuntu.com/download/desktop](https://ubuntu.com/download/desktop)
> Now you can continue with the other steps during the download
- Open VirtualBox
- Press "New"
- Compile the form
    - As name put "rest-createstructure"
    - As Type: "Linux"
    - As version: "Ubuntu (64-bit)" or "Ubuntu (32-bit)"
    - Press "Next >"
- Set the RAM to use for the VirtualMachine, at most half of local RAM and press "Next >"
- Leave "Create a virtual hard disk now" and press "Create"
- Leave "VDI ..." and press "Next >"
- Leave "Dynamically allocated" and press "Next >"
- Change the hard disk memory, we suggest 16GB and press "Create"
> Make sure that Ubuntu download is finished before to continue
- On the VirtualBox console, selecting the created VM, press "Start"
- Select as start-up disk Ubuntu, already downloaded
    - Press the folder icon
    - Press "Add", in the top menu
    - Select the Ubuntu iso, the file will have a structure like "ubuntu-version-other_info.iso"
    - Press "Choose" and "Start"
- Follow the install steps (the installation needs some minutes)

### 3. Install dependencies
Now you have to install building dependencies.
To install Dependes on the Virtual Machine you need to:
- On the VM (Virtual Machine) open the terminal (`Ctrl + Alt + T`)
- On the terminal paste `sudo apt update; sudo add-apt-repository ppa:jyrki-pulliainen/dh-virtualenv -y; sudo apt-get install git build-essential debhelper devscripts equivs dh-virtualenv python3.8 gnupg gnupg2 libcurl4-openssl-dev libssl-dev -y; git clone https://github.com/createstructure/manager-createstructure; cd manager-createstructure; echo "3.0 (native)" > ./debian/source/format` and insert password

### 4. Compile
To compile type: `dpkg-buildpackage -us -uc`
Now the .deb file is in the .. folder, you can install it with apt.

---
Made w/ :heart: by Castellani Davide

If you want to contribute you can start with:
- [Discussion](https://github.com/createstructure/manager-createstructure/discussions)
- [Issue](https://github.com/createstructure/manager-createstructure/issues/new)
